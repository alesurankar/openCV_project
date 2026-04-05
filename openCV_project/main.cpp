#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_ERROR);

	cv::VideoCapture cap(0);
	cv::Mat img;

	while (true) {
		cap.read(img);

		cv::imshow("image", img);
		cv::waitKey(1);
	}
	return 0;
}

