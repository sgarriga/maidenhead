// Convert latitude and longitude to Maidenhead grid locators.
//
// adapted from Ossi Väänänen's code https://ham.stackexchange.com/questions/221/how-can-one-convert-from-lat-long-to-grid-square
// test cases lifted from https://gist.github.com/laemmy/maidenhead.py
// 
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
    int o1, o2, o3;
    int a1, a2, a3;
    double dec_lat, dec_lon;

    if (argc != 3) {
        printf("Usage: %s <lat> <lon>\n", argv[0]);
        printf("lat is decimal > -90 and <= 90\n");
        printf("lon is decimal > -180 and <= 180\n");
        exit(EXIT_SUCCESS);
    }

    dec_lat = atof(argv[1]);
    if (dec_lat <= -90 || dec_lat > 90) {
        printf("latitude must be -90<=lat<90, given %f\n", dec_lat);
        exit(EXIT_FAILURE); // can't handle north pole
    }

    dec_lon = atof(argv[2]);
    if (dec_lon <= -180.0 || dec_lon > 180.0) {
        printf("longitude must be -180<=lon<180, given %f\n", dec_lon);
        exit(EXIT_FAILURE);
    }

    // longitude
    dec_lon += 180.0;
    o1 = (int)(dec_lon / 20.0);
    dec_lon -= (double)o1 * 20.0;
    o2 = (int)(dec_lon / 2.0);
    dec_lon -= 2.0 * (double)o2;
    o3 = (int)(12.0 * dec_lon);

    // latitude
    dec_lat += 90.0;
    a1 = (int)(dec_lat / 10.0);
    dec_lat -= (double)a1 * 10.0;
    a2 = (int)(dec_lat);
    dec_lat -= (double)a2;
    a3 = (int)(24.0 * dec_lat);

    putchar(o1 + 'A');
    putchar(a1 + 'A');
    putchar(o2 + '0');
    putchar(a2 + '0');
    putchar(o3 + 'a');
    putchar(a3 + 'a');
    putchar('\n');

    exit(EXIT_SUCCESS);
}

