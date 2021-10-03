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
	
	Mat img1 = imread("cat.bmp");
	
	Mat img2 = img1(Rect(220, 140, 340, 220));
	Mat img3 = img1(Rect(220, 140, 340, 220)).clone();



	// 부분 추출
	//img2 = ~img2; // image 반전
	imshow("img1", img1);
	//imshow("img2", img2);
	// shallow copy 때문에 원본 데이터도 반전이 발생함.

	img3 = ~img3; // 반전
	imshow("img3", img3);
	
	Mat img4 = img1(Range(0, 302), Range(10, 130)).clone();

	imshow("img4", img4);

	waitKey();
	destroyAllWindows();

	return 0;
}


