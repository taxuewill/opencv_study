#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


#include "constants.h"

using namespace std;


void colorReduce(cv::Mat image, int div=64) {

      int nl= image.rows; // number of lines
      int nc= image.cols * image.channels(); // total number of elements per line

      for (int j=0; j<nl; j++) {

          // get the address of row j
          uchar* data= image.ptr<uchar>(j);

          for (int i=0; i<nc; i++) {

            // process each pixel ---------------------

            data[i]= data[i]/div*div + div/2;

            // end of pixel processing ----------------

          } // end of line
      }
}

int main(int argc,char** argv){

    cv::Mat image;
    // image = cv::imread(IMAGE_BOLDT,cv::IMREAD_COLOR);    //CV_8UC3
    // image = cv::imread(IMAGE_BOLDT,cv::IMREAD_GRAYSCALE);
    image = cv::imread(IMAGE_BOLDT,-1);
    
    if(image.empty()){
        cout<<"not find image"<<endl;
        return -1;
    }
    cout<<"channels "<<image.channels()<<endl;
    colorReduce(image,128);
    cv::namedWindow("ShowImage");
    cv::imshow("ShowImage",image);
    //cv::waitKey(3*1000);
    cv::waitKey(-1);

    return 0;
}
