#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Mat imgHSV, mask;
int hmin = 20, smin = 20, vmin = 150;
int hmax = 200, smax = 255, vmax = 255;

int main()
{
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_ERROR);

	std::string path = "resources/lambo.png";
	Mat img = imread(path);

	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	Scalar lower(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
	inRange(imgHSV, lower, upper, mask);

	imshow("image", img);
	imshow("image HSV", imgHSV);
	imshow("image Mask", mask);
	waitKey(0);
	return 0;
}

