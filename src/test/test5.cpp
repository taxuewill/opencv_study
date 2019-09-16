#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


#include "constants.h"

using namespace std;

int main(int argc,char** argv){

    cv::Mat image = cv::imread(IMAGE_GROUP,0);
    cv::Mat result;
    cv::equalizeHist(image,result);
    
    cv::namedWindow("ShowImage");
    cv::imshow("ShowImage",result);
    cv::waitKey(10*1000);

    return 0;
}