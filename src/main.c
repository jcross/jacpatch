#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bool.h" // Bool is C99+
#include "hardInput.h"

#define MAGIC "JACPATCH"
#define MAGIC_SIZE sizeof(MAGIC)
#define MAX_FN_LEN 256
#define MAX_ASCII_SIZE 10

// Exit codes.
#define SUCCESS 0
#define TOO_SHORT 1
#define NO_MAGIC 2

struct header {
  unsigned char fileName[MAX_FN_LEN];
  unsigned int fileSize;
  bool valid;
};

struct header loadHeader(struct header, unsigned char *,
			 unsigned int, unsigned int);

int main()
{
  struct header head = {};
  head = loadHeader(head, hardInput, hardInput_len, 0);
  printf("Filename: %s\n", head.fileName);
  printf("File Size: %d\n", head.fileSize);
  printf("Header Valid: %d\n", head.valid);
  return SUCCESS;
}

struct header loadHeader(struct header head, unsigned char *input,
			 unsigned int inputSize, unsigned int offset)
{
  if(inputSize - offset < MAGIC_SIZE - 1) {
    printf("Header too short! Is this really a jacpatch?\n");
    exit(TOO_SHORT);
  }
  if(strncmp(&input[offset], MAGIC, MAGIC_SIZE - 1)) {
    printf("Insufficient magic! Is this really a jacpatch?\n");
    exit(NO_MAGIC);
  }

  // TODO: Need something to eat comments!
  // TODO: Need to handle running out of input.
  
  // Print the message describing the patch.
  // input[offset-1] is used because we want to gobble the newline.
  for(offset = offset + MAGIC_SIZE;
      offset < inputSize && input[offset-1] != '\n';
      offset = offset + 1) {
    putc(input[offset], stdout);
  }

  // Get the filename.
  // We don't want to gobble the '\n' here.
  memset(head.fileName, '\0', sizeof(MAX_FN_LEN)); // Zero out filename.
  for(unsigned int i = 0;
      offset + i < inputSize &&
	offset + i < offset + MAX_FN_LEN &&
	input[offset + i] != '\n';
      ++i) head.fileName[i] = input[offset + i];

  offset = offset + strlen(head.fileName);

  unsigned char asciiSize[MAX_ASCII_SIZE];
  memset(asciiSize, '\0', MAX_ASCII_SIZE);
  // TODO: Read file size.

  head.valid = TRUE; // This probably isn't needed if exits are in place.
  return head;
}


