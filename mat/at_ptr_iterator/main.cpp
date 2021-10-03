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
	
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i)++;
		}
	}

	cout << mat1 << endl;
	// ptr 특정행의 첫번째 주소 반환
	// at이나 ptr은 자료형 지정해줘야함
	for (int j = 0; j < mat1.rows; j++)
	{
		uchar* p = mat1.ptr<uchar>(j);
		for (int i = 0; i < mat1.cols; i++)
		{
			p[i]++;
		}
	}
	cout << mat1 << endl;
	
	// ptr이 at보다 빠르긴함


	//iterator 사용
	for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); it++)
	{
		(*it)++; // iterator에 해당하는 값 증가
	}
	cout << mat1 << endl;
	// iterator가 안전하긴 하나 ptr보다 느리고 at처럼 자유자재로 접근 가능한게 아님


	
	


	waitKey();
	destroyAllWindows();

	return 0;
}


