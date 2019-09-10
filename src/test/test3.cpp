#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


#include "constants.h"
#include "test/colordetector.h"

using namespace std;

int main(int argc,char** argv){

    cv::Mat image = cv::imread(IMAGE_BOLDT);
    ColorDetector cdetector;
    cv::Vec3b target(230,190,130);
    cdetector.setTargetColor(target);

    // cv::Mat result = cdetector.process(image);
    // cv::Mat result = cdetector(image);
    // cout<<"result type "<<result.type()<<endl;
    cv::Mat result;
    cv::floodFill(image,
        cv::Point(100,50),
        cv::Scalar(255,255,255),
        (cv::Rect *)0,
        cv::Scalar(35,35,35),
        cv::Scalar(35,35,35),
        cv::FLOODFILL_FIXED_RANGE
        );
    
    
    cv::namedWindow("ShowImage");
    cv::imshow("ShowImage",image);
    cv::waitKey(10*1000);
    cv::imwrite("./result.jpg",image);

    return 0;
}