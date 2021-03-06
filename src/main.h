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
#define MAGIC_SIZE (long)sizeof(MAGIC)
#define MAX_FN_LEN 256
#define MAX_ASCII_SIZE 256

// Exit codes.
#define SUCCESS 0
#define TOO_SHORT 1
#define NO_MAGIC 2
#define EARLY_END 3
#define NOT_FOUND 4
#define WRONG_SIZE 5
#define OFFSET_OOR 6
#define UNEXPECTED_BYTE 7

struct header {
  char fileName[MAX_FN_LEN];
  long fileSize;
  long end;
};

// Pre-define functions.
struct header loadHeader(struct header, unsigned char *,
			 long, long);
long skipComments(unsigned char *, long,
		      long);
void checkEnd(long, long);

long applyTriplets(FILE *, struct header,
		   unsigned char *, long, long);

long applyTriplet(FILE *, struct header,
		  unsigned char *, long, long);

FILE * openFile(struct header);

void fseekAbs(FILE *, long);
