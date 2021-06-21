#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

double to_beats(time_t normal) {
  // Calculate Biel Mean Time
  time_t bmt = normal + 3600;

  // Calculate the elapsed seconds of the day
  int elapsed = bmt % 86400;

  // Get the .beat count for the day
  return elapsed / 86.4;
}

int main(int argc, char **argv) {

  char c;

  // Default formatting
  bool int_mode = false;
  bool full_mode = false;
  bool print_at = true;
  bool print_newline = true;

  while ((c = getopt(argc, argv, "afhin")) != -1) {
    switch (c) {
    case 'a':
      print_at = false;
      break;
    case 'f':
      full_mode = true;
      break;
    case 'h':
      printf("beats - outputs current Swatch Internet Time\n\n");
      printf("OPTIONS:\n");
      printf("-a\tomit leading @-sign\n");
      printf("-f\tprint full float\n");
      printf("-h\tprint this help screen\n");
      printf("-i\tomit decimal places\n");
      printf("-n\tomit newline\n");
      printf("Parse a timestamp by piping it into this program.\n");
      exit(EXIT_SUCCESS);
    case 'i':
      int_mode = true;
      break;
    case 'n':
      print_newline = false;
      break;
    }
  }

  // Make sure float and and int was specified at the same time
  if (int_mode && full_mode) {
    errno = EINVAL;
    perror("Float and integer modes");
    exit(EXIT_FAILURE);
  }

  time_t timestamp;

  // Check if input is being piped in
  if (isatty(fileno(stdin))) {
    timestamp = time(NULL);
  } else {
    if (!scanf("%ld", &timestamp)) {
      perror("Parsing timestamp");
      exit(EXIT_FAILURE);
    }
  }

  // Get our beats for the time of day
  double beats = to_beats(timestamp);

  if (print_at) {
    printf("@");
  }

  if (int_mode) {
    printf("%03i", (int)beats);
  } else if (full_mode) {
    printf("%lf", beats);
  } else {
    printf("%03.*f", 2, beats);
  }

  if (print_newline) {
    printf("\n");
  }
}
