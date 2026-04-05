#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_ERROR);

	std::string path = "resources/gal2.png";
	Mat img = imread(path);
	Mat imgGray;
	Mat imgBlur;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(7,7), 5, 0);

	imshow("image", img);
	imshow("image Gray", imgGray);
	imshow("image Blur", imgBlur);
	waitKey(0);
	return 0;
}

