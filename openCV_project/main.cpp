#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_ERROR);

	std::string path = "resources/gal2.png";
	Mat img = imread(path);
	Mat imgResize1;
	Mat imgResize2;

	//std::cout << img.size << "/n";
	resize(img, imgResize1, Size(640, 640));
	resize(img, imgResize2, Size(), 0.4, 0.4);

	imshow("image", img);
	imshow("image Resize1", imgResize1);
	imshow("image Resize2", imgResize2);
	waitKey(0);
	return 0;
}

