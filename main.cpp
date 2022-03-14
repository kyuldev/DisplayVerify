#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "OCRImage.h"

// Don't do this. It somehow messes with Tesseract.
//namespace std;

int main()
{
    OCRImage theImage("C:/dev/sample_x2.jpg");

    std::cout << "PB1, Col 1: [" << theImage.getPB1Col1() << "]\n";

    std::cout << "PB1, Col 2: [" << theImage.getPB1Col2() << "]\n";

    std::cout << "PB2, Col 1: [" << theImage.getPB2Col1() << "]\n";

    std::cout << "PB2, Col 2: [" << theImage.getPB2Col2() << "]\n";

    std::cout << "PB3, Col 1: [" << theImage.getPB3Col1() << "]\n";

    std::cout << "PB3, Col 2: [" << theImage.getPB3Col2() << "]\n";

    std::cout << "PB4, Col 1: [" << theImage.getPB4Col1() << "]\n";

    std::cout << "PB4, Col 2: [" << theImage.getPB4Col2() << "]\n";

    std::cout << "PB5, Col 1: [" << theImage.getPB5Col1() << "]\n";

    std::cout << "PB5, Col 2: [" << theImage.getPB5Col2() << "]\n";

    std::cout << "PB6, Row 1: [" << theImage.getPB6Row1() << "]\n";

    std::cout << "PB6, Row 2: [" << theImage.getPB6Row2() << "]\n";

    std::cout << "PB7, Row 1: [" << theImage.getPB7Row1() << "]\n";

    std::cout << "PB7, Row 2: [" << theImage.getPB7Row2() << "]\n";

    std::cout << "PB8, Row 1: [" << theImage.getPB8Row1() << "]\n";

    std::cout << "PB8, Row 2: [" << theImage.getPB8Row2() << "]\n";

    std::cout << "PB9, Row 1: [" << theImage.getPB9Row1() << "]\n";

    std::cout << "PB9, Row 2: [" << theImage.getPB9Row2() << "]\n";

    std::cout << "PB10, Row 1: [" << theImage.getPB10Row1() << "]\n";

    std::cout << "PB10, Row 2: [" << theImage.getPB10Row2() << "]\n";

    std::cout << "PB11, Col 1: [" << theImage.getPB11Col1() << "]\n";

    std::cout << "PB11, Col 2: [" << theImage.getPB11Col2() << "]\n";

    std::cout << "PB12, Col 1: [" << theImage.getPB12Col1() << "]\n";

    std::cout << "PB12, Col 2: [" << theImage.getPB12Col2() << "]\n";

    std::cout << "PB13, Col 1: [" << theImage.getPB13Col1() << "]\n";

    std::cout << "PB13, Col 2: [" << theImage.getPB13Col2() << "]\n";

    std::cout << "PB14, Col 1: [" << theImage.getPB14Col1() << "]\n";

    std::cout << "PB14, Col 2: [" << theImage.getPB14Col2() << "]\n";

    std::cout << "PB15, Col 1: [" << theImage.getPB15Col1() << "]\n";

    std::cout << "PB15, Col 2: [" << theImage.getPB15Col2() << "]\n";

    std::cout << "PB16, Row 1: [" << theImage.getPB16Row1() << "]\n";

    std::cout << "PB16, Row 2: [" << theImage.getPB16Row2() << "]\n";

    std::cout << "PB17, Row 1: [" << theImage.getPB17Row1() << "]\n";

    std::cout << "PB17, Row 2: [" << theImage.getPB17Row2() << "]\n";

    std::cout << "PB18, Row 1: [" << theImage.getPB18Row1() << "]\n";

    std::cout << "PB18, Row 2: [" << theImage.getPB18Row2() << "]\n";

    std::cout << "PB19, Row 1: [" << theImage.getPB19Row1() << "]\n";

    std::cout << "PB19, Row 2: [" << theImage.getPB19Row2() << "]\n";

    std::cout << "PB20, Row 1: [" << theImage.getPB20Row1() << "]\n";

    std::cout << "PB20, Row 2: [" << theImage.getPB20Row2() << "]\n";

    std::cout << "TAC: [" << theImage.getTextWord(323, 630, 67, 32) << "]\n";

    std::cout << "Rectangle? [" << theImage.hasRectangle(310, 610, 95, 70) << "]\n";

    std::cout << "Perfect Match? [" << theImage.templateMatch("C:/dev/x.jpg", 1.0, 345, 320, 30, 90) << "]\n";

    std::cout << "Template Over Text Match? [" << theImage.templateMatch("C:/dev/x.jpg", 0.55, 13, 545, 30, 90) << "]\n";

    //theImage.viewDebugImage();

    return 0;
}