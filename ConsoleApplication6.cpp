#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void findTextContours(const Mat& inputImage, Mat& outputImage) 
{
    Mat gray, blurred, edges;
    cvtColor(inputImage, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, blurred, Size(5, 5), 0);
    Canny(blurred, edges, 30, 150);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(edges.clone(), contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
    for (int i = 0; i < contours.size(); i++) 
    {
        Scalar color(0, 255, 0);
        drawContours(outputImage, contours, i, color, 2, LINE_8, hierarchy, 0);
    }
}
int main()
{
    Mat image = imread("image2.jpg");
    Mat contour_image = Mat::zeros(image.size(), CV_8UC3);
    findTextContours(image, contour_image);
    imshow("Text Contours", contour_image);
    waitKey(0);
    return 0;
}
