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
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 4);

	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		std::cout << area << std::endl;

		std::vector<std::vector<Point>> conPoly(contours.size());
		std::vector<Rect> boundRect(contours.size());

		if (area > 1000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02*peri,true);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			std::cout << conPoly[i].size() << std::endl;
			boundRect[i] = boundingRect(conPoly[i]);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 255, 255), 5);
		}
	}
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

