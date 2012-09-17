/********************************************************************
 * FILE: imgStruct.c
 * -----------------
 *  The implementation for the incomplete methods described in 
 *  imgStruct.h
 */

#include <stdlib.h>
#include "imgStruct.h"

struct colorpixel {
  int R;
  int G;
  int B;
};

struct binarypixel {
  int value;
};

struct bwpixel {
  int value;
};

struct hsvpixel {
  int H;
  int S;
  int V;
};

// Here, we create the ColorPixel image, later this will point to an
// array of ColorPixels that comprise of the image, but we need the 
// exact dimensions of the image before we can create the array. This
// technique in all of the image structs
struct colorimage {
  ColorPixel *image;
  int height;          
  int width;
};

struct binaryimage {
  BinaryPixel *image;
  int height;
  int width;
};

struct bwimage {
  BWPixel *image;
  int height;
  int width;
};

struct hsvimage {
  HSVPixel *image;
  int height;
  int width;
};
