#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

using namespace cv;

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

void GetContours(Mat imgDil, Mat img)
{
	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img, contours, -1, Scalar(255, 0, 255), 4);
}

int main()
{
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_ERROR);

	std::string path = "resources/lambo.png";
	Mat img = imread(path);

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	GetContours(imgDil, img);

	imshow("image", img);
	//imshow("image Gray", imgGray);
	//imshow("image Blur", imgBlur );
	//imshow("image Canny", imgCanny);
	//imshow("image Dil", imgDil);
	waitKey(0);
	return 0;
}

