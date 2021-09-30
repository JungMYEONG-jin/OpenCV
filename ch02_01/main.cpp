#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	cout << "HELLO CV " << CV_VERSION << endl;

	cv::Mat img;
	//img = cv::imread("lenna.bmp");
	// 흑백으로 저장하기
	img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	


	if (img.empty())
	{
		cerr << "Failed to open file" << endl;
		return -1;
	}

	vector<int> params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(96);
	// jpeg 압축률 96%
	// 흑백으로 저장하자
	imwrite("lenna.jpg", img, params);


	cv::namedWindow("image"); 
	cv::imshow("image", img);

	cv::waitKey(); // key 입력 대기
	return 0;
}