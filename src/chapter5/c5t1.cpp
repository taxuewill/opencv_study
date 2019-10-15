#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "constants.h"

int main()
{
    cv::Mat image = cv::imread(IMAGE_BINARY);
    if (!image.data)
        return 0;
    // Display the image
    cv::namedWindow("Image");
    cv::imshow("Image", image);
    cv::Mat eroded;
    cv::erode(image,eroded,cv::Mat());
        // Display the eroded image
	cv::namedWindow("Eroded Image");
	cv::imshow("Eroded Image",eroded);

    cv::Mat dilated;
    cv::dilate(image,dilated,cv::Mat());

        // Display the dilated image
	cv::namedWindow("Dilated Image");
	cv::imshow("Dilated Image",dilated);

    cv::Mat temp = dilated -eroded;

    cv::namedWindow("Temp Image");
	cv::imshow("Temp Image",temp);

    cv::waitKey();
    return 0;
}