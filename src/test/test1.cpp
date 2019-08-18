#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


#include "constants.h"

using namespace std;

int main(int argc,char** argv){

    cv::Mat image(240,320,CV_8U,256);
    cv::namedWindow("ShowImage");
    cv::imshow("ShowImage",image);
    cv::waitKey(3*1000);

    return 0;
}