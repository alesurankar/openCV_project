#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void main()
{
	std::string path = "resources/gal2.png";
	cv::Mat img = cv::imread(path);
	cv::imshow("image", img);
	cv::waitKey(0);
}

