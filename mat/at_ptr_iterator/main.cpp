#include "opencv2/opencv.hpp"
#include <iostream>


#define CV_8U 0
#define CV_8S 1
#define CV_16U 2
#define CV_16S 3
#define CV_32S 4	//int
#define CV_32F 5	//float 
#define CV_64F 6	// double
#define CV_16F 7	//float16_t


// mat class �� ���� ä���� ���´�. �� ä���� �ڷ����� �����Ҽ� ����. but �ϳ��� ä�ο��� ���ϵ� �ڷ����� ����ؾ���!
// gray scale 1 channel
// true color 3 channel

using namespace std;
using namespace cv;


int main()
{
	cout << "HELLO CV " << CV_VERSION << endl;
	
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i)++;
		}
	}

	cout << mat1 << endl;
	// ptr Ư������ ù��° �ּ� ��ȯ
	// at�̳� ptr�� �ڷ��� �����������
	for (int j = 0; j < mat1.rows; j++)
	{
		uchar* p = mat1.ptr<uchar>(j);
		for (int i = 0; i < mat1.cols; i++)
		{
			p[i]++;
		}
	}
	cout << mat1 << endl;
	
	// ptr�� at���� ��������


	//iterator ���
	for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); it++)
	{
		(*it)++; // iterator�� �ش��ϴ� �� ����
	}
	cout << mat1 << endl;
	// iterator�� �����ϱ� �ϳ� ptr���� ������ ató�� ��������� ���� �����Ѱ� �ƴ�


	
	


	waitKey();
	destroyAllWindows();

	return 0;
}


