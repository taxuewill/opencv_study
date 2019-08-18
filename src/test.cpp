#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


#include "constants.h"

using namespace std;

int main(int argc,char** argv){

    cv::Mat image;
    image = cv::imread(IMAGE_BOLDT,cv::IMREAD_COLOR);
    if(image.empty()){
        cout<<"not find image"<<endl;
        return -1;
    }
    cv::namedWindow("ShowImage");
    cv::imshow("ShowImage",image);
    cv::waitKey(0);


    return 0;
}