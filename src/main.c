#include "main.h"

int main()
{
  printf(BANNER, VERSION);
  printf("Press any key to continue.\n");
  pause();
  unsigned offset = 0;
  struct header head = {.fileName = "", .fileSize = 0, .end = 0};
  while(offset <= hardInput_len) {
    head = loadHeader(head, hardInput, hardInput_len, offset);
    printf("Filename: %s\n", head.fileName);
    printf("File Size: %u\n", head.fileSize);
    printf("Header end: %u\n", head.end);

    FILE *file = openFile(head);
    offset = applyTriplets(file, hardInput, hardInput_len, head.end + 1);
    fclose(file);
  }
  return SUCCESS;
}

struct header loadHeader(struct header head, unsigned char *input,
			 unsigned inputSize, unsigned offset)
{
  void lskipComments() { offset = skipComments(input, inputSize, offset); }
  lskipComments();
  void lcheckEnd() { checkEnd(inputSize, offset); }
  lcheckEnd();
  if(inputSize - offset < MAGIC_SIZE - 1) {
    printf("Header too short! Is this really a jacpatch?\n");
    exit(TOO_SHORT);
  }
  if(memcmp(&input[offset], MAGIC, MAGIC_SIZE - 1)) {
    printf("Insufficient magic! Is this really a jacpatch?\n");
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
  for(unsigned i = 0;
      offset < inputSize &&
	i <  MAX_FN_LEN - 2 &&
	input[offset] != '\n';) head.fileName[i++] = input[offset++];
  ++offset; // Skip the newline.

  lskipComments();
  lcheckEnd();
  char asciiSize[MAX_ASCII_SIZE] = "";
  memset(asciiSize, '\0', MAX_ASCII_SIZE); // Zero out filename.
  for(unsigned  i = 0;
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

unsigned applyTriplets(FILE *file,
		       unsigned char *input,
		       unsigned inputSize,
		       unsigned offset)
		       
{
  void lskipComments() { offset = skipComments(input, inputSize, offset); }
  lskipComments();
  void lcheckEnd() { checkEnd(inputSize, offset); }
  lcheckEnd();
  return inputSize;
}

unsigned skipComments(unsigned char *input,
		      unsigned inputSize,
		      unsigned offset)
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

void checkEnd(unsigned inputSize, unsigned offset)
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
  fseek(file, 0, SEEK_END); // Cross-platform trick to find file size.
  int fileSize = ftell(file);
  if(fileSize != head.fileSize) {
    fclose(file);
    printf("File size mismatch: %d!\n", fileSize);
    exit(WRONG_SIZE);
  }
  rewind(file);
  return file;
}
