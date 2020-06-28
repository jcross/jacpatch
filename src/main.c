#include "main.h"

int main()
{
  printf(BANNER, VERSION);
  printf("Press any key to continue.\n");
  pause();
  long offset = 0;
  struct header head = {.fileName = "", .fileSize = 0, .end = 0};
  while(offset < hardInput_len) {
    head = loadHeader(head, hardInput, hardInput_len, offset);
    printf("Filename: %s\n", head.fileName);
    printf("File Size: %lu\n", head.fileSize);
    printf("Header end: %lu\n", head.end);

    FILE *file = openFile(head);
    offset = applyTriplets(file, head, hardInput,
			   hardInput_len, head.end + 1);
    fclose(file);
  }
  printf("Binar[y|ies] successfully patched! Enjoy!\n");
  return SUCCESS;
}

struct header loadHeader(struct header head, unsigned char *input,
			 long inputSize, long offset)
{
  void lskipComments() { offset = skipComments(input, inputSize, offset); }
  lskipComments();
  void lcheckEnd() { checkEnd(inputSize, offset); }
  lcheckEnd();
  if(inputSize - offset < MAGIC_SIZE - 1) {
    printf("Header too short! Is this really a JACPatch?\n");
    exit(TOO_SHORT);
  }
  if(memcmp(&input[offset], MAGIC, MAGIC_SIZE - 1)) {
    printf("Insufficient magic! Is this really a JACPatch?\n");
    exit(NO_MAGIC);
  }

  lskipComments();
  lcheckEnd();
  // Print the message describing the patch.
  // input[offset-1] is used because we want to gobble the newline.
  for(offset = offset + MAGIC_SIZE;
      offset < inputSize && input[offset-1] != '\n';
      ++offset) {
    putchar(input[offset]);
  }

  lskipComments();
  lcheckEnd();
  // Get the filename.
  // We don't want to gobble the '\n' here.
  memset(head.fileName, '\0', MAX_FN_LEN); // Zero out filename.
  for(long i = 0;
      offset < inputSize &&
	i <  MAX_FN_LEN - 2 &&
	input[offset] != '\n';) head.fileName[i++] = input[offset++];
  ++offset; // Skip the newline.

  lskipComments();
  lcheckEnd();
  char asciiSize[MAX_ASCII_SIZE] = "";
  memset(asciiSize, '\0', MAX_ASCII_SIZE); // Zero out filename.
  for(long i = 0;
      offset < inputSize &&
	i < MAX_ASCII_SIZE - 2 &&
	input[offset] != '\n'; ++i) {
    if(isdigit(input[offset])) asciiSize[i] = input[offset];
    ++offset;
  }
  head.fileSize = strtoul(asciiSize, NULL, 10);
  head.end = offset;

  return head;
}

long applyTriplets(FILE *file, struct header head,
		   unsigned char *input,
		   long inputSize,
		   long offset)
{
  while(offset < inputSize && input[offset] != MAGIC[0]) {
    offset = applyTriplet(file, head, input, inputSize, offset);
    printf("Char at offset: %c\n", input[offset]);
  }
  return offset;
}

long applyTriplet(FILE *file, struct header head,
		  unsigned char *input,
		  long inputSize,
		  long offset)
		       
{
  void lskipComments() { offset = skipComments(input, inputSize, offset); }
  lskipComments();
  void lcheckEnd() { checkEnd(inputSize, offset); }
  lcheckEnd();

  char tripletAsciiOffset[MAX_ASCII_SIZE] = "";
  memset(tripletAsciiOffset, '\0', MAX_ASCII_SIZE); // Zero out string.
  for(long i = 0;
      offset < inputSize &&
	i < MAX_ASCII_SIZE - 2 &&
	input[offset] != '\n'; ++offset) {
    if(isxdigit(input[offset])) {
      tripletAsciiOffset[i] = input[offset];
      ++i;
    }
  }
  long tripletOffset = strtol(tripletAsciiOffset, NULL, 16);
  printf("Found triplet pointing to %s!\n", tripletAsciiOffset);

  if(tripletOffset > head.fileSize) {
    printf("Triplet offset would be beyond end of file!");
    exit(OFFSET_OOR);
  }

  lskipComments();
  lcheckEnd();
  fseekAbs(file, tripletOffset);

  char aHB[] = "\0\0"; // ASCII representation of a hex byte.
  unsigned char expectedByte = 0;
  unsigned char foundByte = 0;
  for(++offset;
      offset < inputSize &&
	input[offset] != '\n'; ++offset) {
    if(!aHB[0] && isxdigit(input[offset])) { // No nibbles yet.
      aHB[0] = input[offset];
    } else if(aHB[0] && isxdigit(input[offset])) {
      aHB[1] = input[offset];
      expectedByte = strtoul(aHB, NULL, 16);
      foundByte = fgetc(file);
      if(foundByte != expectedByte) {
	printf("Found %x instead of %x at %lx!\n", foundByte,
	       expectedByte, ftell(file) - 1);
	printf("Binary is wrong or already patched!\n");
	exit(UNEXPECTED_BYTE);
      } else memset(aHB, '\0', 3);
    }
  }
  printf("Existing bytes look correct. Proceeding to patch... ");

  lskipComments();
  lcheckEnd();
  fseekAbs(file, tripletOffset);
  memset(aHB, '\0', 3);
  unsigned char newByte = 0;
  for(++offset;
      offset < inputSize &&
	input[offset] != '\n'; ++offset) {
    if(!aHB[0] && isxdigit(input[offset])) { // No nibbles yet.
      aHB[0] = input[offset];
    } else if(aHB[0] && isxdigit(input[offset])) {
      aHB[1]  = input[offset];
      newByte = strtoul(aHB, NULL, 16);
      fputc(newByte, file);
      memset(aHB, '\0', 3);
    }
  }
  printf("Done!\n");

  ++offset;
  lskipComments();
  return offset;
}

long skipComments(unsigned char *input,
		  long inputSize,
		  long offset)
{
  bool onCommentLine = input[offset] == ';';
  while(onCommentLine) {
    for(; input[offset] != '\n' && offset < inputSize; ++offset)
      putchar(input[offset]);
    if(PRINT_COMMENTS) putchar('\n');
    ++offset;
    onCommentLine = (offset == inputSize || input[offset] == ';');
  }
  return offset;
}

void checkEnd(long inputSize, long offset)
{
  if(offset >= inputSize) {
    printf("Unexpected end of patch!\n");
    exit(EARLY_END);
  }
}
   
FILE * openFile(struct header head) {
  FILE *file = fopen(head.fileName, "r+b");

  if(file == NULL) {
    fclose(file);
    printf("Unable to open expected file: %s\n", head.fileName);
    exit(NOT_FOUND);
  }

  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  if(fileSize != head.fileSize) {
    fclose(file);
    printf("File size mismatch: %ld!\n", fileSize);
    exit(WRONG_SIZE);
  }

  return file;
}

void fseekAbs(FILE *file, long offset) {
  // fseek and tell seem completely fucking broken in ia-16 DOS.
  fseek(file, offset, SEEK_SET);
  return;
}
