#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/types_c.h>

#include "constants.h"

int main()
{
    cv::Mat image = cv::imread(IMAGE_BINARY,0);
    //cvtColor(image,image,CV_RGB2GRAY);
    if (!image.data)
        return 0;
    // Display the image
    cv::namedWindow("Image");
    cv::imshow("Image", image);
    cv::Mat fg;
    
    cv::erode(image,fg,cv::Mat(),cv::Point(-1,-1),4);
        // Display the eroded image
	cv::namedWindow("Eroded Image");
	cv::imshow("Eroded Image",fg);

    cv::Mat bg;
    cv::dilate(image,bg,cv::Mat(),cv::Point(-1,-1),4);
    cv::Mat threadHoldBg;
    cv::threshold(bg,threadHoldBg,1,128,cv::THRESH_BINARY_INV);
   
    cv::namedWindow("Dilate Image");
	cv::imshow("Dilate Image",bg);

    cv::namedWindow("threadHold Image");
    cv::imshow("threadHold Image",threadHoldBg);
    cv::Mat markers(image.size(),CV_8U,cv::Scalar(0));
    markers = fg+threadHoldBg;

    cv::namedWindow("markers Image");
    cv::imshow("markers Image",markers);

    cv::Mat sMarkers;
    markers.convertTo(sMarkers,CV_32S);

    cv::cvtColor(image,image,CV_RGB2GRAY);

    cv::watershed(image,sMarkers);

    cv::Mat waterMarkers;
    sMarkers.convertTo(waterMarkers,CV_8U,255,255);

    cv::namedWindow("water markers Image");
    cv::imshow("water markers Image",waterMarkers);


    cv::waitKey();
    return 0;
}