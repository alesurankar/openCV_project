#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;


int main()
{
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_ERROR);

	std::string path = "resources/face.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { std::cout << "XML file not loaded" << std::endl; }

	std::vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}

	imshow("image", img);
	waitKey(0);
	return 0;
}

