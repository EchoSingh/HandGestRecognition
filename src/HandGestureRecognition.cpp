#include "include/HandGestureRecognition.hpp"
#include "include/Utils.hpp"
#include <algorithm>

HandGestureRecognition::HandGestureRecognition() : fingerCount(0) {}

void HandGestureRecognition::processFrame(cv::Mat& frame) {
    cv::Mat preprocessed;
    preprocessFrame(frame, preprocessed);
    findContours(preprocessed);
    findConvexHull();
    detectFingers();
}

int HandGestureRecognition::getFingerCount() const {
    return fingerCount;
}

void HandGestureRecognition::preprocessFrame(const cv::Mat& frame, cv::Mat& output) {
    Utils::preprocessFrame(frame, output);
}

void HandGestureRecognition::findContours(const cv::Mat& frame) {
    contours.clear();
    cv::findContours(frame, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    if (!contours.empty()) {
        largestContour = *std::max_element(contours.begin(), contours.end(),
            [](const std::vector<cv::Point>& c1, const std::vector<cv::Point>& c2) {
                return cv::contourArea(c1) < cv::contourArea(c2);
            });
    }
}

void HandGestureRecognition::findConvexHull() {
    hullIndices.clear();
    defects.clear();
    if (!largestContour.empty()) {
        cv::convexHull(largestContour, hullIndices, false);
        cv::convexityDefects(largestContour, hullIndices, defects);
    }
}

void HandGestureRecognition::detectFingers() {
    fingerCount = 0;
    std::vector<cv::Point> hullPoints;
    for (int idx : hullIndices) {
        hullPoints.push_back(largestContour[idx]);
    }

    for (const auto& defect : defects) {
        cv::Point start = largestContour[defect[0]];
        cv::Point end = largestContour[defect[1]];
        cv::Point far = largestContour[defect[2]];
        float depth = defect[3] / 256.0;

        if (depth > 20 && cv::norm(start - far) > 20 && cv::norm(end - far) > 20) {
            fingerCount++;
        }
    }

    if (!hullPoints.empty()) {
        fingerCount++;
    }
}
