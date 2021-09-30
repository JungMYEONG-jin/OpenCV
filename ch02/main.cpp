#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	cout << "HELLO CV " << CV_VERSION << endl;

	cv::Mat img;
	img = cv::imread("lenna.bmp");

	if (img.empty())
	{
		cerr << "Failed to open file" << endl;
		return -1;
	}

	cv::namedWindow("image"); 
	cv::imshow("image", img);

	cv::waitKey(); // key 입력 대기
	return 0;
}