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
    cv::Mat element5(5,5,CV_8U,cv::Scalar(1));
	cv::Mat closed;
    cv::morphologyEx(image,closed,cv::MORPH_CLOSE,element5);//先膨胀，后腐蚀。去除图像中小的暗点
    // Display the closed image
	cv::namedWindow("Closed Image");
	cv::imshow("Closed Image",closed);

    // Open the image
	cv::Mat opened;
	cv::morphologyEx(image,opened,cv::MORPH_OPEN,element5);//先腐蚀，后膨胀。去除图像中小的亮点

    // Display the opened image
	cv::namedWindow("Opened Image");
	cv::imshow("Opened Image",opened);

    

    cv::waitKey();
    return 0;
}