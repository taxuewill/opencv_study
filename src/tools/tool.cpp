#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

static const int ANGLE_POINT_SIZE = 5;
static const int LINE_SIZE = 100;

using namespace std;
using namespace cv;

void drawImage(Mat & image);

void drawBlackLine(Mat & image,int lineNum);
void drawWhiteLine(Mat & image,int lineNum);

int main(int argc,char** argv){

    cout<<"Hello,OpenCv"<<endl;
    int imageSize = (ANGLE_POINT_SIZE+1)*LINE_SIZE;
    Mat image(imageSize,imageSize,CV_8U,256);
    drawImage(image);
    namedWindow("ShowImage");
    imshow("ShowImage",image);
    waitKey(2*1000);
    imwrite("./output.png",image);
    return 0;
}


void drawImage(Mat & image){
    int cols = image.cols;
    int rows = image.rows;
    int channels = image.channels();
    cout<<"rows is "<<rows <<",cols is "<<cols<<",channels is "<<channels<<endl;
    for(int i = 0 ;i < rows;i++){
        int lineNum = i/LINE_SIZE;
        if(lineNum%2 == 0){
            // cout<<"black"<<endl;
            drawBlackLine(image,i);
        }else{
            // cout<<"white"<<endl;
            drawWhiteLine(image,i);
        }
    }
}

void drawBlackLine(Mat & image,int lineNum){
    int cols = image.cols;
    uchar* start = image.ptr<uchar>(lineNum);
    //cout<<"lineNum "<<lineNum<<endl;
    int blackWhiteFlag = -1;
    for(int i = 0;i< cols;i++){
        if(blackWhiteFlag<0){
            start[i] = 0;
        }else{
            start[i] = 255;
        }
        if(i>0 &&i%LINE_SIZE == 0){
           // cout<<"blackWhiteFlag "<<blackWhiteFlag<<endl;
            blackWhiteFlag = -blackWhiteFlag;
        }
    }
}
void drawWhiteLine(Mat & image,int lineNum){
    int cols = image.cols;
    uchar* start = image.ptr<uchar>(lineNum);
    int blackWhiteFlag = 1;
    for(int i = 0;i< cols;i++){
        if(blackWhiteFlag<0){
            start[i] = 0;
        }else{
            start[i] = 255;
        }
        if(i>0 &&i%LINE_SIZE == 0){
           // cout<<"blackWhiteFlag "<<blackWhiteFlag<<endl;
            blackWhiteFlag = -blackWhiteFlag;
        }
    }
}