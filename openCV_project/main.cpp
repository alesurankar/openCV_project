#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
float w = 150;
float h = 350;

Mat matrix, imgWarp;

int main()
{
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_ERROR);

	std::string path = "resources/gal2.png";
	Mat img = imread(path);

	Point2f src[4] = { {529,142}, {771,190}, {405,395}, {674,457} };
	Point2f dst[4] = { {0.0f,0.0f}, {w,0.0f}, {0.0f,h}, {w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("image", img);
	imshow("image Warp", imgWarp);
	waitKey(0);
	return 0;
}

