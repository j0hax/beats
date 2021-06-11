#include <time.h>
#include "libbeat.h"

double to_beats(time_t normal) {
	
	// calculate Biel Mean Time
	time_t bmt = normal + 3600;
	
	// calculate the elapsed seconds of the day
	int elapsed = bmt % 86400;
	
	// get the .beat count for the day
    return elapsed / 86.4;
}
