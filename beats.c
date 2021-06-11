#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "libbeat.h"

int main(int argc, char **argv) {

  double beats = to_beats(time(NULL));

  char c;

  while ((c = getopt(argc, argv, "ifh")) != -1)
    switch (c) {
    case 'i':
      printf("%d\n", (int)beats);
      exit(0);
    case 'f':
      printf("%f\n", beats);
      exit(0);
    default:
      exit(1);
    }
  printf("@%03.*f", 2, beats);
}
