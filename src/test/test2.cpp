#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


#include "constants.h"

using namespace std;

int main(int argc,char** argv){

    cv::Mat image = cv::imread(IMAGE_BOLDT);
    cv::Mat logo = cv::imread(IMAGE_LOGO);
    cv::Mat imageROI(image,cv::Rect(image.cols-logo.cols,image.rows-logo.rows,logo.cols,logo.rows));
    logo.copyTo(imageROI,logo);
    cv::namedWindow("ShowImage");
    cv::imshow("ShowImage",image);
    cv::waitKey(3*1000);
    cv::imwrite("./result.jpg",image);

    return 0;
}