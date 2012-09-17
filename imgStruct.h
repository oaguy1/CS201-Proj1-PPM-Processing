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
 *  LICENSE: GPLv3
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
 * TYPE: BWPixel
 * -----------
 *  Definition of type pixel to store the grey value for a single 
 *  pixel. all grey values will be 0 < i < 255.
 */
struct bwpixel;
typedef struct bwpixel *BWPixel;

/********************************************************************
 * TYPE: HSVPixel
 * -----------
 *  Definition of type pixel to store the color value of each pixel.
 *  Each color value is stored as an in 0 < i < 255 for 3 discrete
 *  color channels (hue, saturation, luminosity). Those seeking an
 *  RGB color-space should seek out the ColorPixel typedef.
 */
struct hsvpixel;
typedef struct hsvpixel *HSVPixel;

/********************************************************************
 * TYPE: ColorImage
 * -----------
 *  Definition of a struct consisting of a 2D array of ColorPixels.
 *  The combination of all the pixels creates a full image. This 
 *  particular struct uses ColorPixels, but others will use different
 *  pixel types. Also, each ColorImage struct stores the height
 *  and width value of the full image for easy retreaval
 */
struct colorimage;
typedef struct colorimage *ColorImage;

/********************************************************************
 * TYPE: BinaryImage
 * -----------
 *  Definition of a struct consisting of a 2D array of BinaryPixels.
 *  The combination of all the pixels creates a full image. This 
 *  particular struct uses BinaryPixels, but others will use different
 *  pixel types. Also, each BinaryImage struct stores the height
 *  and width value of the full image for easy retreaval
 */
struct binaryimage;
typedef struct binaryimage *BinaryImage;


/********************************************************************
 * TYPE: BWImage
 * -----------
 *  Definition of a struct consisting of a 2D array of BWPixels.
 *  The combination of all the pixels creates a full image. This 
 *  particular struct uses BWPixels, but others will use different
 *  pixel types. Also, each BWImage struct stores the height
 *  and width value of the full image for easy retreaval
 */
struct bwimage;
typedef struct bwimage *BWImage;

/********************************************************************
 * TYPE: HSVImage
 * -----------
 *  Definition of a struct consisting of a 2D array of HSVPixels.
 *  The combination of all the pixels creates a full image. This 
 *  particular struct uses HSVPixels, but others will use different
 *  pixel types. Also, each HSVImage struct stores the height
 *  and width value of the full image for easy retreaval
 */
struct hsvimage;
typedef struct hsvimage *HSVImage;

/********************************************************************
 * FUNCTION: createColorPixel(int R, int G, int B)
 * -----------------------------------------------
 *  Function to properly allocate memory for a new ColorPixel data 
 *  type and return the pixel to the calling function.
 *
 *  Here is an example usage, i[][] is a 2D array of ColorPixels:
 *
 *      i[0][0] = createColorPixel(255, 255, 255);
 */
ColorPixel createColorPixel(int red, int green, int blue);

/********************************************************************
 * FUNCTION: deleteColorPixel(ColorPixel pixel)
 * --------------------------------------------
 *  Function to properly de-allocate the memory of a specific
 *  ColorPixel struct passed through the parameter
 *
 *  Here is an example usage, p is a ColorPixel:
 *
 *      deleteColorPixel(p);
 */
void deleteColorPixel(ColorPixel pixel);

/********************************************************************
 * FUNCTION: createBinaryPixel(int value)
 * --------------------------------------
 *  Function to properly allocate memory for a new BinaryPixel data
 *  type and return the pixel to the calling function.
 *
 *  Here is an example usage, i[][] is a 2D array of BinaryPixels
 *
 *      i[0][0] = createBinaryPixel(0);
 */
BinaryPixel createBinaryPixel(int value);

/********************************************************************
 * FUNCTION: deleteBinaryPixel(BinaryPixel pixel)
 * ----------------------------------------------
 *  Function to properly de-allocate memory of a specific 
 *  BinaryPixel struct passed through the parameter.
 *
 *  Here is an example usage, b is a binary pixel:
 *
 *      deleteBinaryPixel(b);
 */
void deleteBinaryPixel(BinaryPixel pixel);

/********************************************************************
 * FUNCTION: createBWPixel(int value)
 * ----------------------------------
 *  Function to properly allocate memory for a new BWPixel data type
 *  and return the pixel to the calling function.
 *
 *  Here is an example usage; i[][] is a 2D array of BWPixels
 *
 *      i[0][0] = createBWPixel(114);
 */
BWPixel createBWPixel(int value);

/********************************************************************
 * FUNCTION: deleteBWPixel(BWPixel pixel)
 * --------------------------------------
 *  This function properly de-allocates memory for a specific 
 *  BWPixel struct passed through the parameter.
 *
 *  Here is an example usage, b is a BWPixel:
 *
 *      deleteBWPixel(b);
 */
void deleteBWPixel(BWPixel pixel);

/********************************************************************
 * FUNCTION: createHSVPixel(int H, int S, int V)
 * ----------------------------------
 *  Function to properly allocate memory for a new HSVPixel data type
 *  and return the pixel to the calling function.
 *
 *  Here is an example usage; i[][] is a 2D array of HSVPixels
 *
 *      i[0][0] = createHSVPixel(114);
 */
HSVPixel createHSVPixel(int hue, int sat, int value);

/********************************************************************
 * FUNCTION: deleteHSVPixel(HSVPixel pixel)
 * ----------------------------------------
 *  This function properly de-allocates memory for a specific 
 *  BWPixel struct passed through the parameter.
 *
 *  Here is an example usage, b is a BWPixel:
 *
 *      deleteBWPixel(b);
 */
void deleteHSVPixel(HSVPixel pixel);

/********************************************************************
 * FUNCTION: createColorImage()
 * ----------------------------
 *  Function to properly allocate memory for a ColorImage struct and 
 *  pass the ColorImage back to the calling function.
 *
 *  Here is an example usage, input is a ColorImage struct:
 *
 *      input = createColorImage();
 */
ColorImage createColorImage(int height, int width);

/********************************************************************
 * FUNCTION: deleteColorImage(ColorImage image)
 * --------------------------------------------
 *  Function to properly de-allocate memory for a specific ColorImage
 *  struct passed through the parameter.
 *
 *  Here is an example usage, image is a ColorImage:
 *
 *      deleteColorImage(image);
 */
void deleteColorImage(ColorImage image);

/********************************************************************
 * FUNCTION: createBinaryImage()
 * ----------------------------
 *  Function to properly allocate memory for a BinaryImage struct and 
 *  pass the BinaryImage back to the calling function.
 *
 *  Here is an example usage, input is a BinaryImage struct:
 *
 *      input = createBinaryImage();
 */
BinaryImage createBinaryImage(int height, int width);

/********************************************************************
 * FUNCTION: deleteBinaryImage(ColorImage image)
 * --------------------------------------------
 *  Function to properly de-allocate memory for a specific BinaryImage
 *  struct passed through the parameter.
 *
 *  Here is an example usage, image is a BinaryImage:
 *
 *      deleteBinaryImage(image);
 */
void deleteBinaryImage(BinaryImage image);

/********************************************************************
 * FUNCTION: createBWImage()
 * ----------------------------
 *  Function to properly allocate memory for a BWImage struct and 
 *  pass the BWImage back to the calling function.
 *
 *  Here is an example usage, input is a BWImage struct:
 *
 *      input = createBWImage();
 */
BWImage createBWImage(int height, int width);

/********************************************************************
 * FUNCTION: deleteBWImage(BWImage image)
 * --------------------------------------------
 *  Function to properly de-allocate memory for a specific BWImage
 *  struct passed through the parameter.
 *
 *  Here is an example usage, image is a BWImage:
 *
 *      deleteBWImage(image);
 */
void deleteBWImage(BWImage image);

/********************************************************************
 * FUNCTION: createHSVImage()
 * ----------------------------
 *  Function to properly allocate memory for a HSVImage struct and 
 *  pass the HSVImage back to the calling function.
 *
 *  Here is an example usage, input is a HSVImage struct:
 *
 *      input = createHSVImage();
 */
HSVImage createHSVImage(int height, int width);

/********************************************************************
 * FUNCTION: deleteHSVImage(HSVImage image)
 * --------------------------------------------
 *  Function to properly de-allocate memory for a specific HSVImage
 *  struct passed through the parameter.
 *
 *  Here is an example usage, image is a ColorHSV:
 *
 *      deleteHSVImage(image);
 */
void deleteHSVImage(HSVImage image);

#endif
