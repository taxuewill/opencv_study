#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "constants.h"

using namespace std;

cv::Mat getImageOfHistogram(const cv::Mat &hist, int zoom)
{
    // Get min and max bin values
    double maxVal = 0;
    double minVal = 0;
    cv::minMaxLoc(hist, &minVal, &maxVal, 0, 0);
    // get histogram size
    int histSize = hist.rows;
    // Square image on which to display histogram
    cv::Mat histImg(histSize * zoom, histSize * zoom, CV_8U, cv::Scalar(255));
    // set highest point at 90% of nbins (i.e. image height)
    int hpt = static_cast<int>(0.9 * histSize);
    // Draw vertical line for each bin
    for (int h = 0; h < histSize; h++)
    {
        float binVal = hist.at<float>(h);
        if (binVal > 0)
        {
            int intensity = static_cast<int>(binVal * hpt / maxVal);
            cv::line(histImg, cv::Point(h * zoom, histSize * zoom),
                     cv::Point(h * zoom, (histSize - intensity) * zoom), cv::Scalar(0), zoom);
        }
    }
    return histImg;
}



int main(int argc, char **argv)
{
    int histSize[3];        // number of bins in histogram
    float hranges[2];       // range of values
    const float *ranges[3]; // pointer to the different value ranges
    int channels[3];        // channel number to be examined
    histSize[0] = histSize[1] = histSize[2] = 8;      // 8 bins
    hranges[0] = 0.0;       // from 0 (inclusive)
    hranges[1] = 256.0;     // to 256 (exclusive)
    ranges[0] = ranges[1]= ranges[2]=hranges;
    channels[0] = 0; // we look at channel 0
    channels[1] = 1; // we look at channel 0
    channels[2] = 2; // we look at channel 0

    cv::Mat image = cv::imread(IMAGE_BOLDT);
    cv::Mat color = image(cv::Rect(0, 0, 100, 45));
    cv::Mat hist;
    cv::calcHist(&color,1,channels,cv::Mat(),hist,3,histSize,ranges);
    //cv::calcHist(&image,1,channels,cv::Mat(),hist,1,histSize,ranges);
    // cv::Mat histImage = getImageOfHistogram(hist,1);
    cv::normalize(hist,hist,1.0);
    cv::Mat result;
    cv::calcBackProject(&image,1,channels,hist,result,ranges,255.0);
    cv::namedWindow("ShowImage");
    cv::threshold(result,result,25.5,255,cv::THRESH_BINARY);
    cout<<result.cols<<"x"<<result.rows<<endl;
    cv::imshow("ShowImage", result);
    // cv::imwrite("./output_wave.jpg",result);
    cv::waitKey(10 * 1000);

    return 0;
}