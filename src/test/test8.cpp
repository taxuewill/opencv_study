#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "constants.h"

int main()
{
    cv::Mat image = cv::imread(IMAGE_BOOK,0);
    // display original image
	cv::namedWindow("Original Image");
    cv::transpose(image,image);
    cv::flip(image, image, 0);

    // using a fixed threshold 
	// cv::Mat binaryFixed;
	// cv::Mat binaryAdaptive;
    // cv::threshold(image,binaryFixed,70,255,cv::THRESH_BINARY);
    // using as adaptive threshold
	int blockSize= 21; // size of the neighborhood
	int threshold=10;  // pixel will be compared to (mean-threshold)
    cv::Mat iimage;
    cv::integral(image,iimage,CV_32S);

    int halfSize = blockSize/2;

    for(int j = halfSize; j<image.rows - halfSize - 1; j++){
        uchar* data = image.ptr<uchar>(j);
		int* idata1 = iimage.ptr<int>(j - halfSize);
		int* idata2 = iimage.ptr<int>(j + halfSize + 1);

		// for pixel of a line
		for (int i = halfSize; i<image.cols - halfSize - 1; i++) {

			// compute sum
			int sum = (idata2[i + halfSize + 1] - idata2[i - halfSize] -
				idata1[i + halfSize + 1] + idata1[i - halfSize]) / (blockSize*blockSize);

			// apply adaptive threshold
			if (data[i]<(sum - threshold))
				data[i] = 0;
			else
				data[i] = 255;
		}
    }

	cv::imshow("Original Image",image);
    // cv::imwrite("./book_1.jpg",image);

    cv::waitKey(10 * 1000);
    return 0;
}