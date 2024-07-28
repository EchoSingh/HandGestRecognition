#ifndef UTILS_HPP
#define UTILS_HPP

#include <opencv2/opencv.hpp>

namespace Utils {
    void preprocessFrame(const cv::Mat& frame, cv::Mat& output);
}

#endif // UTILS_HPP
