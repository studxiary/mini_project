#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

///////////////////// Resize and Crop //////////////////////////

int main(int ac, char** av) {
    string  path = "Resources/test.png";
    Mat img = imread(path);
    Mat imgResize, imgCrop;
    resize(img, imgResize, Size(), 0.5, 0.5);
    
    Rect roi(200,100,300,300);
    imgCrop = img(roi);

    imshow("Image Img", img);
    imshow("Image ImgResize", imgResize);
    imshow("Image ImgCrop", imgCrop);


    waitKey(0);


    return 0;
}

