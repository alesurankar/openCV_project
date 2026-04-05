#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_ERROR);

	std::string path = "resources/video.mp4";
	cv::VideoCapture cap(path);
	cv::Mat img;

	while (true) {
		cap.read(img);

		cv::imshow("image", img);
		cv::waitKey(10);
	}
	return 0;
}

