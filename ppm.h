/********************************************************************
 * FILE: ppm.h
 * -----------
 *  This is a library that aims to make importing images in the PPM
 *  and PGM formats easy to import and parse into appropriate data
 *  structures. This library depends on the "imgStruct.h" header.
 *
 *  AUTHOR: David N. Robinson
 *  DATE: 09/17/2012
 *  LICENSE: GPLv3
 */

#ifndef UTILS_PPM
#define UTILS_PPM

/********************************************************************
 * FUNCTION: importPPM(char* path, ColorImage image)
 * -------------------------------------------------
 *  This function imports a PPM image file and parses it into a 
 *  ColorImage struct. Once parsed, the image will be able to be 
 *  manipulated by other functions.
 *  
 *  Here is an example, inputImg is a ColorImage, path is a char*
 *
 *      importPPM(path, inputImg);
 */
void importPPM(char* path, ColorImage image);

/********************************************************************
 * FUNCTION: importPGM(char* path, ColorImage image)
 * -------------------------------------------------
 *  This function imports a PGM image file and parses it into a
 *  BWImage struct. Once parsed, the image will be able to be 
 *  manipulated by other functions.
 *
 *  Here is an example, inputImg is a ColorImage, path is a char*
 *
 *      importPGM(path, inputImg);
 */
void importPGM(char* path, BWImage);

/********************************************************************
 * FUCNTION: exportRGBPPM(char* path, ColorImage image)
 * ----------------------------------------------------
 *  This function exports a PPM image file from the data contained
 *  within a ColorImage struct. Outputs to the path passed through
 *  the parameter. NB: THIS FUNCTION ONLY WORKS WITH AN RGB COLOR
 *  SPACE.
 *
 *  Here is an example, outputImg is a ColorImage and path is a char*
 *
 *      exportRGBPPM(path, outputImg);
 */
void exportRGBPPM(char* path, ColorImage image);

/********************************************************************
 * FUNCTION: exportBinaryPGM(char* path, BinaryImage image)
 * --------------------------------------------------------
 *  This function exports a PGM image file from the data contained
 *  within a BinaryImage struct. Outputs to the path passed through
 *  the parameter. This function only works with binary images.
 *
 *  Here is an example, outputImg is a BinaryImage, path is a char*
 *
 *      exportBinaryPGM(path, outputImg);
 */
void exportBinaryPGM(char* path, BinaryImage image);

/********************************************************************
 * FUNCTION: exportBWPGM(char* path, BWImage image)
 * ------------------------------------------------
 *  This function exports a PGM image file from the data contained
 *  within a BWImage struct. Outputs to the path passed through the
 *  parameter. This function only works with the bw images
 *
 *  Here is an example, outputImg is a BWImage, path is a char*
 *
 *      exportBWPGM(path, outputImg);
 */
void exportBWPGM(char* path, BWImage image);

#endif
