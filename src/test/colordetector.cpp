#include "test/colordetector.h"

cv::Mat ColorDetector::process(const cv::Mat &image){
    result.create(image.size(),CV_8U);
    cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
    cv::Mat_<uchar>::iterator itout = result.begin<uchar>();
    for(;it!=itend;it++,itout++){
        if(getDistanceToTargetColor(*it)<maxDist){
            *itout=255;
        }else{
            *itout=0;
        }
    }
    return result;
}

cv::Mat ColorDetector::operator()(const cv::Mat &image){
    cv::Mat output;
    // compute absolute difference with target color
    cv::absdiff(image,cv::Scalar(target),output);
    // split the channels into 3 images
    std::vector<cv::Mat> images;
    cv::split(output,images);
    // add the 3 channels (saturation might occurs here)
    output= images[0]+images[1]+images[2];
    // apply threshold
    cv::threshold(output,
            output,
            maxDist,
            25,
            cv::THRESH_TOZERO);

    return output;
}