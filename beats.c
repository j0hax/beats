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

  time_t timestamp = time(NULL);

  while ((c = getopt(argc, argv, "afhint:")) != -1) {
    switch (c) {
    case 'a':
      print_at = false;
      break;
    case 'f':
      full_mode = true;
      break;
    case '?':
    case 'h':
      printf("Usage: beats [-ahn] [-f | -i] [-t timestamp]\n");
      printf("Displays the Swatch Internet Time.\n\n");
      printf("-a\tomit leading @-sign\n");
      printf("-f\tprint full floating-point value\n");
      printf("-h\tdisplay this help and exit\n");
      printf("-i\tinteger mode (omit decimals)\n");
      printf("-n\tomit newline (\\n)\n");
      printf("-t\tparse UNIX timestamp\n");
      exit(EXIT_SUCCESS);
    case 'i':
      int_mode = true;
      break;
    case 'n':
      print_newline = false;
      break;

    case 't':
      if (!sscanf(optarg, "%ld", &timestamp)) {
        fprintf(stderr, "Error: could not parse timestamp\n");
        exit(EXIT_FAILURE);
      }
      break;
    }
  }

  // Make sure float and and int was specified at the same time
  if (int_mode && full_mode) {
    fprintf(stderr, "Error: cannot use integer and float modes\n");
    exit(EXIT_FAILURE);
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
