#include "ocrimage.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

OCRImage::OCRImage(String file) {
	image = imread(file);

	// Process the image using OpenCV before passing to Tesseract OCR
	// Tesseract prefers black text on white background

	// Change to grayscale
	cvtColor(image, image, COLOR_BGR2GRAY);

	// Apply thresholding to better isolate characters from background
	threshold(image, image, 150, 255, THRESH_BINARY_INV + THRESH_OTSU);

	// Make an inverted copy of image for contour operations (they prefer black background)
	bitwise_not(image, imageInv);

	if (DEBUG) {
		debugImage = image.clone();
	}

	// Intialize Tesseract in English
	api = new tesseract::TessBaseAPI();
	api->Init("C:\\Program Files\\Tesseract-OCR\\tessdata", "eng");

}

std::string OCRImage::getPB1Col1()
{
	return getTextVert(LEFT_PB_MARGIN_COL1, PB1, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB1Col2()
{
	return getTextVert(LEFT_PB_MARGIN_COL2, PB1, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB2Col1()
{
	return getTextVert(LEFT_PB_MARGIN_COL1, PB2, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB2Col2()
{
	return getTextVert(LEFT_PB_MARGIN_COL2, PB2, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB3Col1()
{
	return getTextVert(LEFT_PB_MARGIN_COL1, PB3, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB3Col2()
{
	return getTextVert(LEFT_PB_MARGIN_COL2, PB3, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB4Col1()
{
	return getTextVert(LEFT_PB_MARGIN_COL1, PB4, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB4Col2()
{
	return getTextVert(LEFT_PB_MARGIN_COL2, PB4, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB5Col1()
{
	return getTextVert(LEFT_PB_MARGIN_COL1, PB5, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB5Col2()
{
	return getTextVert(LEFT_PB_MARGIN_COL2, PB5, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB6Row1()
{
	return getText(PB6, TOP_PB_MARGIN_ROW1, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB6Row2()
{
	return getText(PB6, TOP_PB_MARGIN_ROW2, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB7Row1()
{
	return getText(PB7, TOP_PB_MARGIN_ROW1, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB7Row2()
{
	return getText(PB7, TOP_PB_MARGIN_ROW2, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB8Row1()
{
	return getText(PB8, TOP_PB_MARGIN_ROW1, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB8Row2()
{
	return getText(PB8, TOP_PB_MARGIN_ROW2, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB9Row1()
{
	return getText(PB9, TOP_PB_MARGIN_ROW1, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB9Row2()
{
	return getText(PB9, TOP_PB_MARGIN_ROW2, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB10Row1()
{
	return getText(PB10, TOP_PB_MARGIN_ROW1, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB10Row2()
{
	return getText(PB10, TOP_PB_MARGIN_ROW2, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB11Col1()
{
	return getTextVert(RIGHT_PB_MARGIN_COL1, PB11, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB11Col2()
{
	return getTextVert(RIGHT_PB_MARGIN_COL2, PB11, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB12Col1()
{
	return getTextVert(RIGHT_PB_MARGIN_COL1, PB12, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB12Col2()
{
	return getTextVert(RIGHT_PB_MARGIN_COL2, PB12, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB13Col1()
{
	return getTextVert(RIGHT_PB_MARGIN_COL1, PB13, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB13Col2()
{
	return getTextVert(RIGHT_PB_MARGIN_COL2, PB13, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB14Col1()
{
	return getTextVert(RIGHT_PB_MARGIN_COL1, PB14, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB14Col2()
{
	return getTextVert(RIGHT_PB_MARGIN_COL2, PB14, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB15Col1()
{
	return getTextVert(RIGHT_PB_MARGIN_COL1, PB15, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB15Col2()
{
	return getTextVert(RIGHT_PB_MARGIN_COL2, PB15, VERT_PB_WIDTH, VERT_PB_HEIGHT);
}

std::string OCRImage::getPB16Row1()
{
	return getText(PB16, BOTTOM_PB_MARGIN_ROW1, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB16Row2()
{
	return getText(PB16, BOTTOM_PB_MARGIN_ROW2, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB17Row1()
{
	return getText(PB17, BOTTOM_PB_MARGIN_ROW1, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB17Row2()
{
	return getText(PB17, BOTTOM_PB_MARGIN_ROW2, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB18Row1()
{
	return getText(PB18, BOTTOM_PB_MARGIN_ROW1, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB18Row2()
{
	return getText(PB18, BOTTOM_PB_MARGIN_ROW2, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB19Row1()
{
	return getText(PB19, BOTTOM_PB_MARGIN_ROW1, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB19Row2()
{
	return getText(PB19, BOTTOM_PB_MARGIN_ROW2, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB20Row1()
{
	return getText(PB20, BOTTOM_PB_MARGIN_ROW1, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getPB20Row2()
{
	return getText(PB20, BOTTOM_PB_MARGIN_ROW2, HORIZ_PB_WIDTH, HORIZ_PB_HEIGHT);
}

std::string OCRImage::getTextWord(int x, int y, int w, int h)
{
	if (DEBUG) {
		drawRectDebug(x, y, w, h);
	}

	Mat croppedImage = cropImage(image, x, y, w, h);
	api->SetPageSegMode(tesseract::PSM_SINGLE_WORD);

	// Tell Tesseract to use the provided image
	api->SetImage(croppedImage.data, croppedImage.cols, croppedImage.rows, croppedImage.channels(), croppedImage.step);

	// This doesn't seem necessary, but removes a warning.
	api->SetSourceResolution(IMAGE_RESOLUTION);

	// Get the text
	char* t = api->GetUTF8Text();
	std::string s = cleanString(std::string(t));

	// Free per GetUTF8Text() docs
	delete[] t;

	return s;
}

bool OCRImage::hasRectangle(int x, int y, int w, int h)
{
	// Calculate total area of the region for filtering purposes
	int totalArea = w * h;

	// Crop region before feeding to OpenCV
	Mat croppedImage = cropImage(imageInv, x, y, w, h);

	// Find shapes using findContours
	std::vector<std::vector<cv::Point> > contours;

	// RETR_EXTERNAL is good for this case as it will only detect parent contours, which means
	// that it will easily detect an outer rectangle and ignore anything inside the rectangle
	// https://learnopencv.com/contour-detection-using-opencv-python-c/
	findContours(croppedImage, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	int s = contours.size();
	std::vector<Point> approx;
	for (size_t i = 0; i < s; i++) {
		Rect r = boundingRect(contours[i]);

		// Calculate area of the contour for filtering
		int area = r.width * r.height;

		// If area of rectangle is at least 60% of region and not the same as the region, proceed
		if (area > totalArea*0.6 && area != totalArea) {
			double epsilon = 0.05 * arcLength(contours[i], true);
			std::vector<std::vector<cv::Point> > curves;
			approxPolyDP(contours[i], approx, epsilon, true);

			// If contour has 4 edges and is convex, it's most likely a rectangle
			if (approx.size() == 4 && isContourConvex(approx)) {
				return true;
			}
		}
	}

	return false;
}

bool OCRImage::templateMatch(std::string tPath, double thresh, int x, int y, int w, int h)
{
	// Load template image
	Mat tImg = imread(tPath);

	// Change to grayscale
	cvtColor(tImg, tImg, COLOR_BGR2GRAY);
	threshold(tImg, tImg, 150, 255, THRESH_BINARY_INV + THRESH_OTSU);

	// Crop region before performing template matching
	Mat croppedImage;
	Mat ROI(image, Rect(x, y, w, h));
	ROI.copyTo(croppedImage);

	int rows = croppedImage.rows - tImg.rows + 1;
	int cols = croppedImage.cols - tImg.cols + 1;

	// Detect if template is smaller than the region
	if (rows < 0 || cols < 0) {
		return false;
	}

	// Detect edges
	Mat tImgCanny;
	Canny(tImg, tImgCanny, 50, 200);
	Mat cICanny;
	Canny(croppedImage, cICanny, 50, 200);

	// Initialize result based upon inputs
	Mat resultImg(rows, cols, CV_32FC1);

	// Perform match operation
	matchTemplate(cICanny, tImgCanny, resultImg, TM_CCORR_NORMED);

	// Sift through the data and find the best match. Because we're using TM_CCORR_NORMED, the max values
	// are what we will be using.
	double minVal, maxVal;
	Point minLoc(-1, -1), maxLoc(-1, -1);
	minMaxLoc(resultImg, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	if (maxVal >= thresh) {
		return true;
	}

	return false;
}

void OCRImage::viewImage()
{
	namedWindow("OCR Image", WINDOW_AUTOSIZE);
	imshow("OCR Image", image);
	moveWindow("OCR Image", 0, 45);
	waitKey(0);
	destroyAllWindows();
}

void OCRImage::viewDebugImage()
{
	namedWindow("OCR Debug Image", WINDOW_AUTOSIZE);
	imshow("OCR Debug Image", debugImage);
	moveWindow("OCR Debug Image", 0, 45);
	waitKey(0);
	destroyAllWindows();
}

void OCRImage::drawRect(int x, int y, int w, int h)
{
	rectangle(image, Rect(x, y, w, h), Scalar(0, 255, 0), 2);
}

void OCRImage::drawRectDebug(int x, int y, int w, int h)
{
	rectangle(debugImage, Rect(x, y, w, h), Scalar(0, 255, 0), 2);
}

void OCRImage::saveImage(String file)
{
	imwrite(file, image);
}

void OCRImage::saveDebugImage(String file)
{
	imwrite(file, debugImage);
}

std::string OCRImage::getText(int x, int y, int w, int h)
{
	if (DEBUG) {
		drawRectDebug(x, y, w, h);
	}

	// Crop text region before feeding to Tesseract
	Mat croppedImage = cropImage(image, x, y, w, h);

	api->SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);

	// Tell Tesseract to use the provided image
	api->SetImage(croppedImage.data, croppedImage.cols, croppedImage.rows, croppedImage.channels(), croppedImage.step);
	
	// This doesn't seem necessary, but removes a warning.
	api->SetSourceResolution(IMAGE_RESOLUTION);

	// Use this to write out a file to verify you're passing the correct image info to Tesseract
	//Pix *d = api->GetThresholdedImage();
	//pixWrite("C:\\Users\\kyle\\Pictures\\pix.jpg", d, IFF_JFIF_JPEG);

	// Get the text
	char* t = api->GetUTF8Text();
	std::string s = cleanString(std::string(t));

	// Free per GetUTF8Text() docs
	delete[] t;

	return s;
}

// Tesseract doesn't seem to be able to read strings where the letters are stacked horizontally
// This method isolates the characters and uses Tesseract to decode them one by one
std::string OCRImage::getTextVert(int x, int y, int w, int h)
{
	if (DEBUG) {
		drawRectDebug(x, y, w, h);
	}

	// Crop text region before feeding to Tesseract
	Mat croppedImage = cropImage(image, x, y, w, h);

	// Isolate characters using contours
	std::vector<std::vector<cv::Point> > contours;
	findContours(croppedImage, contours, RETR_LIST, CHAIN_APPROX_NONE);

	// New string to return
	std::string txt;
	int s = contours.size();
	//printf("NUM OF CONTOURS: [%i]", s);
	for (size_t i = 0; i < s; i++) {
		Rect r = boundingRect(contours[i]);

		// Filter out false positives by using results that fit within a typical character size
		if (r.width < w and r.width > MIN_CHAR_WIDTH and r.height > MIN_CHAR_HEIGHT and r.height < MAX_CHAR_HEIGHT) {
			
			// Isolate character
			Mat croppedChar = cropImage(croppedImage, r.x, r.y, r.width, r.height);

			api->SetPageSegMode(tesseract::PSM_SINGLE_CHAR);

			// Tell Tesseract to use the provided image
			api->SetImage(croppedChar.data, croppedChar.cols, croppedChar.rows, croppedChar.channels(), croppedChar.step);

			// This doesn't seem necessary, but removes a warning.
			api->SetSourceResolution(IMAGE_RESOLUTION);

			// Use this to write out a file toverify you're passing the correct image info to Tesseract
			//Pix *d = api->GetThresholdedImage();
			//pixWrite("C:\\Users\\kyle\\Pictures\\pix.jpg", d, IFF_JFIF_JPEG);

			// Get the text and add to the string
			char* t = api->GetUTF8Text();
			std::string s = cleanString(std::string(t));

			// Free per GetUTF8Text() docs
			delete[] t;

			txt.append(s);
		}
	}

	// Reverse the characters in the string as they were processed backwards
	std::reverse(txt.begin(), txt.end());
	return txt;
}

std::string OCRImage::cleanString(std::string str)
{
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

	return str;
}

Mat OCRImage::cropImage(Mat img, int x, int y, int w, int h)
{
	Mat croppedImg;
	Mat ROI(img, Rect(x, y, w, h));
	ROI.copyTo(croppedImg);
	return croppedImg;
}
