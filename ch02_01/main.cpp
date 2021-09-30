#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	cout << "HELLO CV " << CV_VERSION << endl;

	cv::Mat img;
	//img = cv::imread("lenna.bmp");
	// ������� �����ϱ�
	img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	


	if (img.empty())
	{
		cerr << "Failed to open file" << endl;
		return -1;
	}

	vector<int> params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(96);
	// jpeg ����� 96%
	// ������� ��������
	imwrite("lenna.jpg", img, params);


	cv::namedWindow("image"); 
	cv::imshow("image", img);

	cv::waitKey(); // key �Է� ���
	return 0;
}