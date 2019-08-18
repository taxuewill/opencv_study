#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


#include "constants.h"

using namespace std;

int main(int argc,char** argv){

    cv::Mat image;
    // image = cv::imread(IMAGE_BOLDT,cv::IMREAD_COLOR);    //CV_8UC3
    // image = cv::imread(IMAGE_BOLDT,cv::IMREAD_GRAYSCALE);
    image = cv::imread(IMAGE_BOLDT,-1);
    
    if(image.empty()){
        cout<<"not find image"<<endl;
        return -1;
    }
    cout<<"channels "<<image.channels()<<endl;
    cv::namedWindow("ShowImage");
    cv::imshow("ShowImage",image);
    cv::waitKey(3*1000);


    return 0;
}