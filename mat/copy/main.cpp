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
	
	Mat img1 = imread("dog.bmp");
	Mat img2 = img1; // shallow copy �����͸� �����ϰԵ�
	if (img1.empty())
		cerr << "Load Failed" << endl;
	if (img2.empty())
		cerr << "Load Failed" << endl;
	Mat img3;
	img3 = img1; // shallow copy
	Mat img4 = img1.clone();
	Mat img5;
	img1.copyTo(img5); // deep copy

	img1.setTo(Scalar(0, 255, 255)); // yellow

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);
	// shallow copy�� ���� img1 ����� img2 img3 �� ���� ����
	// deep copy img4 img5�� �״��




	waitKey();
	destroyAllWindows();

	return 0;
}


