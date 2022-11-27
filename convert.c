#include "gis.h"

void convertDMS(struct coordinate* a, struct coordinate* b, int len) {
    for (int i = 0; i < len; i++) {
        a[i].longitude.degree = a[i].longitude.dms / 10000;
        a[i].longitude.minute = a[i].longitude.dms % 10000 / 100;
        a[i].longitude.second = a[i].longitude.dms % 10000 % 100;
        a[i].longitude.totalSec = a[i].longitude.degree * 3600 + a[i].longitude.minute * 60 + a[i].longitude.second;
        if (a[i].longitude.direction == 'W') a[i].longitude.totalSec = -a[i].longitude.totalSec;

        a[i].latitude.degree = a[i].latitude.dms / 10000;
        a[i].latitude.minute = a[i].latitude.dms % 10000 / 100;
        a[i].latitude.second = a[i].latitude.dms % 10000 % 100;
        a[i].latitude.totalSec = a[i].latitude.degree * 3600 + a[i].latitude.minute * 60 + a[i].latitude.second;
        if (a[i].latitude.direction == 'S') a[i].latitude.totalSec = -a[i].latitude.totalSec;

        b[i].longitude.degree = b[i].longitude.dms / 10000;
        b[i].longitude.minute = b[i].longitude.dms % 10000 / 100;
        b[i].longitude.second = b[i].longitude.dms % 10000 % 100;
        b[i].longitude.totalSec = b[i].longitude.degree * 3600 + b[i].longitude.minute * 60 + b[i].longitude.second;
        if (b[i].longitude.direction == 'W') b[i].longitude.totalSec = -b[i].longitude.totalSec;

        b[i].latitude.degree = b[i].latitude.dms / 10000;
        b[i].latitude.minute = b[i].latitude.dms % 10000 / 100;
        b[i].latitude.second = b[i].latitude.dms % 10000 % 100;
        b[i].latitude.totalSec = b[i].latitude.degree * 3600 + b[i].latitude.minute * 60 + b[i].latitude.second;
        if (b[i].latitude.direction == 'S') b[i].latitude.totalSec = -b[i].latitude.totalSec;
    }
}
