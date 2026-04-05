#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_ERROR);
    cv::Mat img = cv::imread("images/gal2.png");

    if (img.empty()) {
        std::cout << "Image not found!\n";
        return -1;
    }

    cv::imshow("My Image", img);
    cv::waitKey(0);
    return 0;
}