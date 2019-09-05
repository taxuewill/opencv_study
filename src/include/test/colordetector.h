#ifndef COLORDETECT
#define COLORDETECT

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class ColorDetector {

private:
    // minimum acceptable distance
	int maxDist; 

    cv::Vec3b target;

    cv::Mat converted;

    cv::Mat result;
public:
    ColorDetector() : maxDist(100), target(0,0,0){}

    int getColorDistance(const cv::Vec3b& color1,const cv::Vec3b& color2) const{
        return abs(color1[0]-color2[0])+abs(color1[1]-color2[1])+abs(color1[2]-color2[2]);
    }
    int getDistanceToTargetColor(const cv::Vec3b& color) const {
		  return getColorDistance(color, target);
	}

    // Sets the color to be detected
	  void setTargetColor(cv::Vec3b color) {

		  target= color;
	  }

	  // Gets the color to be detected
	  cv::Vec3b getTargetColor() const {

		  return target;
	  }

      // Gets the color distance threshold
	  int getColorDistanceThreshold() const {

		  return maxDist;
	  }

      cv::Mat process(const cv::Mat &image);
	  cv::Mat operator()(const cv::Mat &image);

};

#endif