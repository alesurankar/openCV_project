#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_ERROR);

	std::string path = "resources/gal2.png";
	cv::Mat img = cv::imread(path);
	cv::imshow("image", img);
	cv::waitKey(0);

	return 0;
}

