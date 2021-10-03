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


// mat class 는 여러 채널을 갖는다. 각 채널은 자료형을 지정할수 있음. but 하나의 채널에는 통일된 자료형을 사용해야함!
// gray scale 1 channel
// true color 3 channel

using namespace std;
using namespace cv;


int main()
{
	cout << "HELLO CV " << CV_VERSION << endl;
	
	Mat img1 = imread("dog.bmp");
	Mat img2 = img1; // shallow copy 데이터를 고융하게됨
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
	// shallow copy로 인해 img1 변경시 img2 img3 다 영향 받음
	// deep copy img4 img5는 그대로




	waitKey();
	destroyAllWindows();

	return 0;
}


