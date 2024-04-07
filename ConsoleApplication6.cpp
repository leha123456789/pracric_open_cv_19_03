#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() 
{
    Mat image = imread("image2.jpg");
    Mat gray, blurred, edges;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, blurred, Size(5, 5), 0);
    Canny(blurred, edges, 30, 150);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(edges.clone(), contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    Mat contour_image = Mat::zeros(image.size(), CV_8UC3);
    for (size_t i = 0; i < contours.size(); i++) 
    {
        drawContours(contour_image, contours, static_cast<int>(i), Scalar(0, 255, 0), 1);
    }
    imshow("Text Contours", contour_image);
    waitKey(0);
    return 0;
}
