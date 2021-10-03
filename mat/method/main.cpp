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
	
	

	Mat img1 = imread("lenna.bmp");

	cout << "Width: " << img1.cols << endl;
	cout << "Height: " << img1.rows << endl;
	cout << img1.total() << endl;

	if (img1.type() == CV_8UC1)
		cout << "gray scale!" << endl;
	else if (img1.type() == CV_8UC3)
		cout << "img1 is true color!" << endl;
	
	float data[] = { 2.2f, 3.3f, 1.1f, 222.1f };
	Mat mat2(2, 2, CV_32FC1, data);
	cout << mat2 << endl;

	waitKey();
	destroyAllWindows();

	return 0;
}


