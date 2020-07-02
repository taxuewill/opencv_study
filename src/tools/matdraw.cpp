//https://docs.opencv.org/3.4/d6/d6e/group__imgproc__draw.html

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

void drawCircle(Mat mat);
void drawText(Mat mat);
void drawLine(Mat mat);
void drawRecangle(Mat mat);

int main(int argc,char** argv){

    cv::Mat map(600,800,CV_8UC3,cv::Scalar(255,255,255));


    drawCircle(map);
    drawText(map);
    drawLine(map);
    drawRecangle(map);

    cv::namedWindow("showMap");
    cv::imshow("showMap",map);
    cv::waitKey(-1);

    return 0;
}


void drawCircle(Mat mat){
    int centerX = mat.cols/2;
    int centerY = mat.rows/2;
    cout<<"center["<<centerX<<","<<centerY<<"]"<<endl;
    cv::circle(mat,
        cv::Point(centerX,centerY),
        50,
        cv::Scalar(255,255,0),
        1);
}

void drawText(Mat mat){
    cv::putText(mat,
        "This is test!",
        cv::Point(20,30),
        cv::FONT_HERSHEY_SIMPLEX,
        1.0,
        Scalar(10,50,0),
        2);
}

void drawLine(Mat mat){
    cv::line(mat,
        cv::Point(50,50),
        cv::Point(100,100),
        cv::Scalar(0,100,100),
        2,
        CV_AA);
}

void drawRecangle(Mat mat){
    cv::rectangle(mat,
    cv::Rect(100,100,50,50),
    Scalar(100,0,255),
    1);
}

