#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dlfcn.h>
#include <string.h>

struct geoinfo {
	int degree;
	int minute;
	int second;
	int totalSec;
	int dms;
	char direction;
};

struct coordinate {
	struct geoinfo longitude;
	struct geoinfo latitude;
};
