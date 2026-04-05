#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Mat imgHSV, mask;
int hmin = 10, smin = 45, vmin = 156;
int hmax = 70, smax = 255, vmax = 255;

int main()
{
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_ERROR);

	std::string path = "resources/lambo.png";
	Mat img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);

	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("HSat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("image", img);
		imshow("image HSV", imgHSV);
		imshow("image Mask", mask);
		waitKey(1);
	}
	return 0;
}

