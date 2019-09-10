#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


#include "constants.h"

using namespace std;

int main(int argc,char** argv){

    // cv::Mat image = cv::imread(IMAGE_BOLDT);
    // cv::Mat hsv;
    // cv::cvtColor(image,hsv,CV_BGR2HSV);
    // std::vector<cv::Mat> channels;
    // cv::split(hsv,channels);
    int i=0;
    // if(argc >1){
        i = atoi(argv[1]);
        cout<<"intput i is "<<i<<endl;
    // }
    // if(i<0||i>2){
    //     i=0;
    // }
    // cout<<"param is "<<i<<endl;
    cv::Mat hs(128,360,CV_8UC3);
    for(int h = 0;h<360;h++){
        for(int s = 0;s <128;s++){
            hs.at<cv::Vec3b>(s,h)[0]=h/2;
            hs.at<cv::Vec3b>(s,h)[1]=255-s*2;
            hs.at<cv::Vec3b>(s,h)[2]=i;
        }
    }
    cv::namedWindow("ShowImage");//0 is seidiao,1 is baohedu,2 is liangdu
    cv::imshow("ShowImage",hs);
    cv::waitKey(10*1000);
    //cv::imwrite("./result.jpg",image);

    return 0;
}