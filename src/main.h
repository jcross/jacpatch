#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "hardInput.h"
#include "version.h"
#include "pause.h"

#define PRINT_COMMENTS true

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
  unsigned end;
};

// Pre-define functions.
struct header loadHeader(struct header, unsigned char *,
			 unsigned, unsigned);
unsigned skipComments(unsigned char *, unsigned,
		      unsigned);
void checkEnd(unsigned, unsigned);

unsigned applyTriplets(unsigned char *, unsigned, unsigned);
