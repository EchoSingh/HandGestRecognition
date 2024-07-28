#ifndef HANDGESTURERECOGNITION_HPP
#define HANDGESTURERECOGNITION_HPP

#include <opencv2/opencv.hpp>
#include <vector>

class HandGestureRecognition {
public:
    HandGestureRecognition();
    void processFrame(cv::Mat& frame);
    int getFingerCount() const;

private:
    void preprocessFrame(const cv::Mat& frame, cv::Mat& output);
    void findContours(const cv::Mat& frame);
    void findConvexHull();
    void detectFingers();

    int fingerCount;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> defects;
    std::vector<int> hullIndices;
    std::vector<cv::Point> largestContour;
};

#endif // HANDGESTURERECOGNITION_HPP
