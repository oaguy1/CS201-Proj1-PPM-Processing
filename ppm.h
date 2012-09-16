/********************************************************************
 * FILE: ppm.h
 * -----------
 *  PPM is an image format that is extremely easy to open and 
 *  manipulate using basic programming. This library seeks to make
 *  such image processing easier by abstracing out some data types
 *  and functions for use with opening and working with PPM image
 *  files.
 *
 *  AUTHOR: David N. Robinson
 *  DATE: 09/16/2012
 *  VERSION: 0.1a
 *  LICENSE: BSD 3-clause
 *******************************************************************/

#ifndef UTILS_PPM
#define UTILS_PPM

/********************************************************************
 * TYPE: ColorPixel
 * -----------
 *  Definition of type pixel to store the color value for a single
 *  pixel. Each color value is stored as an in 0 < i < 255 for 3
 *  discrete color channels. By default the three channels will 
 *  represent a RGB value. For other color-spaces, such as HSV, there
 *  will be another pixel struct
 */
struct colorpixel;
typedef struct colorpixel *ColorPixel;

/********************************************************************
 * TYPE: BinaryPixel
 * -----------
 *  Definition of type pixel to store the either a black or a white
 *  color value in a single pixel. 0 is black (unselected) and 0 is
 *  white (selected).
 */
struct binarypixel;
typedef struct binarypixel *BinaryPixel;

/********************************************************************
 * TYPE: ColorPixel
 * -----------
 *  Definition of type pixel to store the grey value for a single 
 *  pixel. all grey values will be 0 < i < 255.
 */
struct bwpixel;
typedef struct bwpixel *BWPixel;

/********************************************************************
 * TYPE: ColorPixel
 * -----------
 *  Definition of type pixel to store the color value of each pixel.
 *  Each color value is stored as an in 0 < i < 255 for 3 discrete
 *  color channels (hue, saturation, luminosity). Those seeking an
 *  RGB color-space should seek out the ColorPixel typedef.
 */
struct hsvpixel;
typedef struct hsvpixel *HSVPixel;

/********************************************************************
 * FUNCTION: createColorPixel(int R, int G, int B)
 * -----------------------------------------------
 *  Function to properly allocate memory for a new ColorPixel data 
 *  type
 *
 *  Here is an example usage, i[][] is a 2D array of ColorPixels:
 *
 *      i[0][0] = createColorPixel(255, 255, 255);
 */
ColorPixel createColorPixel(int R, int G, int B);
