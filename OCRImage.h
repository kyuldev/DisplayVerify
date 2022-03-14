#pragma once
#include <string>
#include <opencv2/imgcodecs.hpp>
#include <baseapi.h>
#include <allheaders.h>

using namespace cv;

class OCRImage
{
public:
	OCRImage(String file);

	std::string getPB1Col1();
	std::string getPB1Col2();
	std::string getPB2Col1();
	std::string getPB2Col2();
	std::string getPB3Col1();
	std::string getPB3Col2();
	std::string getPB4Col1();
	std::string getPB4Col2();
	std::string getPB5Col1();
	std::string getPB5Col2();
	std::string getPB6Row1();
	std::string getPB6Row2();
	std::string getPB7Row1();
	std::string getPB7Row2();
	std::string getPB8Row1();
	std::string getPB8Row2();
	std::string getPB9Row1();
	std::string getPB9Row2();
	std::string getPB10Row1();
	std::string getPB10Row2();
	std::string getPB11Col1();
	std::string getPB11Col2();
	std::string getPB12Col1();
	std::string getPB12Col2();
	std::string getPB13Col1();
	std::string getPB13Col2();
	std::string getPB14Col1();
	std::string getPB14Col2();
	std::string getPB15Col1();
	std::string getPB15Col2();
	std::string getPB16Row1();
	std::string getPB16Row2();
	std::string getPB17Row1();
	std::string getPB17Row2();
	std::string getPB18Row1();
	std::string getPB18Row2();
	std::string getPB19Row1();
	std::string getPB19Row2();
	std::string getPB20Row1();
	std::string getPB20Row2();

	// Returns a string containing a word with no spaces in the x, y, width, height region.
	std::string getTextWord(int x, int y, int w, int h);

	// Returns true if a rectangle is detected in the provided area. Assumes that the provided
	// region is just slightly larger than the rectangle to be detected
	bool hasRectangle(int x, int y, int w, int h);

	// Returns true is image represented in templatePath is found in the provided region
	// Assumes provided image template is of same size and orientation as main image
	// The thresh value is a value between 1.0 and 0 that represents the probability of match.
	// When the template is on top of other text (like an X over a label), the probabilty is as low
	// as 0.57. When the template is matched without other obstruction, the probability is 1.0.
	bool templateMatch(std::string templatePath, double thresh, int x, int y, int w, int h);

	// Call to pop up a window to view the current state of the image
	void viewImage();
	void viewDebugImage();

	// Call to draw a rectangle on the image. Useful for debugging.
	// x,y = coordinates of upper left corner of rectangle
	// w = width of rectangle
	// h = height of rectangle
	void drawRect(int x, int y, int w, int h);
	void drawRectDebug(int x, int y, int w, int h);

	// Call to save the image to file.
	void saveImage(String file);
	void saveDebugImage(String file);

private:
	Mat image, debugImage, imageInv;
	tesseract::TessBaseAPI* api;

	std::string getText(int x, int y, int w, int h);
	std::string getTextVert(int x, int y, int w, int h);
	std::string cleanString(std::string str);

	Mat cropImage(Mat img, int x, int y, int w, int h);

	// When set true, a rectangle is drawn around the areas where text is extracted and 
	// can be viewed through viewDebugImage().
	const bool DEBUG = false;

	// Resolution of images.
	const int IMAGE_RESOLUTION = 144;

	// Constants used for getting text of pushbuttons
	// X-positions of upper left corner of pushbutton areas. Assume each pushbutton has two areas.
	const int LEFT_PB_MARGIN_COL1 = 10;
	const int LEFT_PB_MARGIN_COL2 = 40;
	const int RIGHT_PB_MARGIN_COL1 = 670;
	const int RIGHT_PB_MARGIN_COL2 = 640;

	// Y-positions of upper left corner of pushbutton areas. Assume each pushbutton has two areas.
	const int TOP_PB_MARGIN_ROW1 = 15;
	const int TOP_PB_MARGIN_ROW2 = 40;
	const int BOTTOM_PB_MARGIN_ROW1 = 680;
	const int BOTTOM_PB_MARGIN_ROW2 = 655;

	// Pushbutton area width and height (single string of text)
	const int VERT_PB_WIDTH = 30;
	const int VERT_PB_HEIGHT = 118;
	const int HORIZ_PB_WIDTH = 80;
	const int HORIZ_PB_HEIGHT = 25;

	// Y-position of upper left corner of pushbutton area
	const int PB1 = 541;
	const int PB2 = 423;
	const int PB3 = 305;
	const int PB4 = 187;
	const int PB5 = 69;
	const int PB11 = 69;
	const int PB12 = 187;
	const int PB13 = 305;
	const int PB14 = 423;
	const int PB15 = 541;

	// X-position of upper left corner of pushbutton area
	const int PB6 = 90;
	const int PB7 = 200;
	const int PB8 = 310;
	const int PB9 = 420;
	const int PB10 = 535;
	const int PB16 = 545;
	const int PB17 = 440;
	const int PB18 = 320;
	const int PB19 = 210;
	const int PB20 = 90;

	// Constants for identifying individual characters when vertically stacked
	const int MIN_CHAR_WIDTH = 5;
	const int MIN_CHAR_HEIGHT = 16;
	const int MAX_CHAR_HEIGHT = 22;
};