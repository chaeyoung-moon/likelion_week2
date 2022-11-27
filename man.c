#include "gis.h"

void displayDis(struct coordinate* a, struct coordinate* b, int len) {
	for (int i = 0; i < len; i++) {
		int distanceSec = abs(a[i].latitude.totalSec - b[i].latitude.totalSec) + abs(a[i].longitude.totalSec - b[i].longitude.totalSec);
		printf("(%02dd %02dm %02ds %c, %02dd %02dm %02ds %c) ", a[i].longitude.degree, a[i].longitude.minute, a[i].longitude.second, a[i].longitude.direction, a[i].latitude.degree, a[i].latitude.minute, a[i].latitude.second, a[i].latitude.direction);
		printf("(%02dd %02dm %02ds %c, %02dd %02dm %02ds %c) ", b[i].longitude.degree, b[i].longitude.minute, b[i].longitude.second, b[i].longitude.direction, b[i].latitude.degree, b[i].latitude.minute, b[i].latitude.second, b[i].latitude.direction);
		printf("%06d %04dd %02dm %02ds \n", distanceSec, distanceSec / 3600, distanceSec / 60, distanceSec % 60);
	}
}
