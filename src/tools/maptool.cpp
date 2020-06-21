#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

void drawMap(cv::Mat mat);

int main(int argc,char** argv){

    cv::Mat map(480,640,CV_8UC3,cv::Scalar(255,255,255));
    drawMap(map);
    cv::namedWindow("showMap");
    cv::imshow("showMap",map);
    cv::waitKey(-1);
    return 0;
}

void drawMap(cv::Mat mat){
    cout<<"mat is continous "<<mat.isContinuous()<<endl; 
    int cols = mat.cols;
    int rows = mat.rows;
    int scope = 25;
    for(int i = 0;i< rows;i++){
        if(i%scope==0){
            for(int j = 0;j<cols;j++){
                mat.at<cv::Vec3b>(i,j) = 0;
            }
        }
    }

    for(int j=0;j< cols;j++){
        if(j%scope == 0){
            for(int i=0;i<rows;i++){
                mat.at<cv::Vec3b>(i,j) = 0;
            }
        }
    }
    int centerR = rows/2;
    int centerC = cols/2;
    for(int i = -1;i<2;i++){
        for(int j = -1;j<2;j++){
            mat.at<cv::Vec3b>(rows/2+i,cols/2+j)= cv::Vec3b(0,0,255);
        }
    }
    
    // mat.at<cv::Vec3b>(rows/2,cols/2)= cv::Vec3b(0,0,255);
    // mat.at<cv::Vec3b>(rows/2+1,cols/2)= cv::Vec3b(0,0,255);
}

// void drawMap(cv::Mat mat){
    
//     cv::Mat_<cv::Vec3b>::iterator it = mat.begin<cv::Vec3b>();
//     cv::Mat_<cv::Vec3b>::iterator end = mat.end<cv::Vec3b>();
//     while(it!=end){
//         //do something
//         *it = 0;
//         it++;
//     }
// }