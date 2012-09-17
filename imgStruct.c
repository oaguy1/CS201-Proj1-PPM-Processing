/********************************************************************
 * FILE: imgStruct.c
 * -----------------
 *  The implementation for the incomplete methods described in 
 *  imgStruct.h
 */

#include <stdio.h>
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

ColorPixel createColorPixel(int red, int green, int blue) {

  ColorPixel pixel = (ColorPixel) malloc(sizeof(struct colorpixel));

  if (pixel == NULL) {
    printf("Out of memory!\n");
    exit(1);
  }

  pixel->R = red;
  pixel->G = green;
  pixel->B = blue;

  return pixel;

}

void deleteColorPixel(ColorPixel pixel) {
  
  free(pixel);

}

BinaryPixel createBinaryPixel(int value) {

  BinaryPixel pixel = (BinaryPixel) malloc(sizeof(struct binarypixel));

  if (pixel == NULL) {
    printf("Out of memory!\n");
    exit(1);
  }

  pixel->value = value;

  return pixel;

}

void deleteBinaryPixel(BinaryPixel pixel) {
  
  free(pixel);

}

BWPixel createBWPixel(int value) {

  BWPixel pixel = (BWPixel) malloc(sizeof(struct bwpixel));

  if (pixel == NULL) {
    printf("Out of memory!\n");
    exit(1);
  }

  pixel->value = value;

  return pixel;

}

void deleteBWPixel(BWPixel pixel) {
  
  free(pixel);

}

HSVPixel createHSVPixel(int hue, int sat, int value) {

  HSVPixel pixel = (HSVPixel) malloc(sizeof(struct hsvpixel));

  if (pixel == NULL) {
    printf("Out of memory!\n");
    exit(1);
  }

  pixel->H = hue;
  pixel->S = sat;
  pixel->V = value;

  return pixel;

}

void deleteHSVPixel(HSVPixel pixel) {
  
  free(pixel);

}

ColorImage createColorImage(int height, int width) {

 ColorImage image = (ColorImage) malloc(sizeof(struct colorimage));

 if (image == NULL) {
   printf("Out of memory!\n");
   exit(1);
 }

 // Rather than create the array, I am allocating the place in memory
 // for the image array, which will be populated during the parsing
 // process
 image->image = (ColorPixel*) malloc(height*width*sizeof(struct colorpixel));
 image->height = height;
 image->width = width;

}
