#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "constants.h"

int main()
{
    cv::Mat image = cv::imread(IMAGE_BOLDT,0);
    if (!image.data)
        return 0;
    // Display the image
    cv::namedWindow("Image");
    cv::imshow("Image", image);

    cv::Mat result;
    cv::morphologyEx(image, result, cv::MORPH_GRADIENT, cv::Mat());

    cv::namedWindow("Edge Image");
    cv::imshow("Edge Image",255- result);
    // cv::Mat eroded;
    // cv::erode(image,eroded,cv::Mat());

    // cv::namedWindow("Erode Image");
    // cv::imshow("Erode Image", eroded);

    cv::waitKey();
    return 0;
}