#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_ERROR);

	Mat img(512, 512, CV_8UC3, Scalar(250,250,250));

	circle(img, Point(256,256), 155, Scalar(0, 69, 255), 10);

	imshow("image", img);
	waitKey(0);
	return 0;
}

