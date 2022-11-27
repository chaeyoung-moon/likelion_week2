#include "gis.h"

int getGIS(char* filename, struct coordinate* a, struct coordinate* b) {
	printf("%s/n", filename);//
	FILE* fp = fopen(filename, "r");
	int cur = 0;
	while (!feof(fp)) {
		fscanf(fp, "(%d%c, %d%c) (%d%c, %d%c) \n",
			&a[cur].longitude.dms, &a[cur].longitude.direction,
			&a[cur].latitude.dms, &a[cur].latitude.direction,
			&b[cur].longitude.dms, &b[cur].longitude.direction,
			&b[cur].latitude.dms, &b[cur].latitude.direction);
		cur++;
	}
	fclose(fp);
	return cur;
}
