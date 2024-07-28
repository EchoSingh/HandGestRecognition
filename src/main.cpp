#include "include/HandGestureRecognition.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cam(0);
    if (!cam.isOpened()) {
        cout << "ERROR: Camera not opened" << endl;
        return -1;
    }

    HandGestureRecognition recognizer;

    Mat img;
    Mat img_threshold;
    Mat img_gray;
    Mat img_roi;
    namedWindow("Original_image", WINDOW_AUTOSIZE);
    namedWindow("Gray_image", WINDOW_AUTOSIZE);
    namedWindow("Thresholded_image", WINDOW_AUTOSIZE);
    namedWindow("ROI", WINDOW_AUTOSIZE);
    char a[40];
    int count = 0;

    while (true) {
        bool b = cam.read(img);
        if (!b) {
            cout << "ERROR: Cannot read frame" << endl;
            return -1;
        }

        Rect roi(340, 100, 270, 270);
        img_roi = img(roi);
        recognizer.processFrame(img_roi);

        int fingerCount = recognizer.getFingerCount();
        if (fingerCount == 1)
            strcpy_s(a, "Hello :D ");
        else if (fingerCount == 2)
            strcpy_s(a, "Peace :) ");
        else if (fingerCount == 3)
            strcpy_s(a, "3 it is !!");
        else if (fingerCount == 4)
            strcpy_s(a, "0100");
        else if (fingerCount == 5)
            strcpy_s(a, "FIVE");
        else
            strcpy_s(a, "Welcome !!");

        putText(img, a, Point(70, 70), FONT_HERSHEY_SIMPLEX, 3, Scalar(255, 0, 0), 2, 8, false);

        imshow("Original_image", img);
        imshow("Gray_image", img_roi);
        imshow("Thresholded_image", img_roi);
        imshow("ROI", img_roi);

        if (waitKey(30) == 27) {
            break;
        }
    }

    return 0;
}
