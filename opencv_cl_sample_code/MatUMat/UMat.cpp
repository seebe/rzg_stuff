#include <time.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/core/ocl.hpp>
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    if (!cv::ocl::haveOpenCL())
    {
        cout << "OpenCL is not available..." << endl;
        //return;
    }

    UMat img, gray;
    imread("image.jpg", IMREAD_COLOR).copyTo(img);

    clock_t begin = clock();
    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray,Size(7, 7), 1.5);
    Canny(gray, gray, 0, 50);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << time_spent << endl;

    imshow("edges", gray);
    waitKey();
    return 0;
}
