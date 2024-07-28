#include "include/Utils.hpp"


namespace Utils {
    void preprocessFrame(const cv::Mat& frame, cv::Mat& output) {
        cv::Mat gray, blurred, thresholded;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        cv::GaussianBlur(gray, blurred, cv::Size(19, 19), 0);
        cv::threshold(blurred, thresholded, 0, 255, cv::THRESH_BINARY_INV + cv::THRESH_OTSU);

        // Morphological operations to reduce noise and fill gaps
        cv::morphologyEx(thresholded, output, cv::MORPH_CLOSE, cv::Mat::ones(5, 5, CV_8U));
        cv::morphologyEx(output, output, cv::MORPH_OPEN, cv::Mat::ones(5, 5, CV_8U));
    }
}
