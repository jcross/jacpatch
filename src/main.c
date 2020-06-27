#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "hardInput.h"

#define MAGIC "JACPATCH"
#define MAGIC_SIZE sizeof(MAGIC)
#define MAX_FN_LEN 256
#define MAX_ASCII_SIZE 10

// Exit codes.
#define SUCCESS 0
#define TOO_SHORT 1
#define NO_MAGIC 2
#define EARLY_END 3

struct header {
  char fileName[MAX_FN_LEN];
  unsigned fileSize;
};

struct header loadHeader(struct header, unsigned char *,
			 unsigned, unsigned);

unsigned long int skipComments(unsigned char *, unsigned,
			       unsigned);
void checkEnd(unsigned, unsigned);

int main()
{
  struct header head = {.fileName = "", .fileSize = 0};
  head = loadHeader(head, hardInput, hardInput_len, 0);
  printf("Filename: %s\n", head.fileName);
  printf("File Size: %u\n", head.fileSize);
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

  return head;
}

unsigned long int skipComments(unsigned char *input,
			       unsigned inputSize,
			       unsigned offset)
{
  bool onCommentLine = input[offset] == ';';
  while(onCommentLine) {
    for(; input[offset] != '\n' && offset < inputSize; ++offset);
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
   
