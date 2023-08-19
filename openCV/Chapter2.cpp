#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

///////////////////// Basic Functions //////////////////////////

int main(int ac, char** av) {
    string  path = "Resources/test.png";
    Mat img = imread(path);
    Mat imgGray, imgBlur,imgCanny, imgDil, imgErode;
    
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlur, Size(7,7),5,0);
    Canny(imgBlur, imgCanny, 25,75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(9, 9));
    dilate(imgCanny, imgDil, kernel);
    erode(imgDil, imgErode, kernel);

    imshow("Image Canny", imgCanny);
    imshow("Image Dilation", imgDil);
    imshow("Image Erode", imgErode);

    waitKey(0);

    return 0;
} 

 