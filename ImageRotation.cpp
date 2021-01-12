#include<opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat rotate(Mat src, double angle)
{
	Mat dst;
	Point2f pt(src.cols / 2., src.rows / 2.);
	Mat r = getRotationMatrix2D(pt, angle, 1.0);
	warpAffine(src, dst, r, Size(src.cols, src.rows));
	return dst;
}

int main()
{
	int angle;
	Mat src = imread("C:/Users/Diksha/Downloads/download.jpg");

	Mat dst;
	cout << "Enter angle to rotate:";
	cin >> angle;
	dst = rotate(src, angle);
	string srcname = "Source Image";
	namedWindow(srcname);
	string windowname = "Rotated Image";
	namedWindow(windowname);
	imshow(srcname, src);
	imshow(windowname, dst);
	waitKey(0);
	destroyAllWindows();
	return 0;
}