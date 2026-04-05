#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_ERROR);

	VideoCapture cap(0);
	Mat img;

	CascadeClassifier faceCascade;
	faceCascade.load("resources/haarcascade_frontalface_default.xml");
	if (faceCascade.empty()) { 
		std::cout << "XML file not loaded" << std::endl; 
	}

	while (true) {
		cap.read(img);
		std::vector<Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
		}
		imshow("image", img);
		waitKey(1);
	}
	return 0;
}
