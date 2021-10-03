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
	
	Mat img1(480, 640, CV_8UC1); // grayscale 가로 640 세로 480 1 channel
	Mat img2(480, 640, CV_8UC3); // true color 가로 640 세로 480 3 channel
	Mat img3(Size(480, 640), CV_8UC3); // Size type
	// 행렬의 크기와 타입을 지정하여 저장하면 쓰레기값으로 채워짐 ex vector에서 init시 0으로 채워지는것
	Mat img4(480, 640, CV_8UC1, Scalar(128)); // all pixel value filled with 128 
	Mat img5(480, 640, CV_8UC3, Scalar(0, 0, 255));; // Scalar사용시 컬러는 B G R 순이다.
	vector<Mat> imgs;
	imgs.push_back(img1);
	imgs.push_back(img2);
	imgs.push_back(img3);
	imgs.push_back(img4);
	imgs.push_back(img5);
	for (auto& it : imgs)
		cout << it.channels() << endl;
	Mat mat1 = Mat::zeros(3, 3, CV_32SC1); // 0 matrix channel 1
	Mat mat2 = Mat::ones(3, 3, CV_32FC1);
	Mat mat3 = Mat::eye(3, 3, CV_32FC1); // 단위 행렬
	vector<Mat> matrix;
	matrix.push_back(mat1);
	matrix.push_back(mat2);
	matrix.push_back(mat3);
	for (auto& it : matrix)
		cout << it << endl;
	

	// matrix 지정시 외부데이터에 할당하는게 가능함. 이를 이용시 동적으로 메모리 공간 할당을 하지 않아 빠름
	// size 지정해줘야함. auto_step으로 지정시 패딩바이트 고려하지 않고 하기 때문
	float data[] = { 1,2,3,4,5,6 };
	Mat mat4(2, 3, CV_32FC1, data);
	// 하지만 이렇게 외부데이터 공유시 mat 변경 또는 외부데이터 변경시 함께 변경되므로 주의 필요
	cout << mat4 << endl;
	data[4] = 16;
	cout << mat4 << endl;

	Mat_<float> mat5_(2, 3); // 2 by 3 
	mat5_ << 1, 2, 3, 4, 5, 6;
	Mat mat5 = mat5_;
	cout << mat5_ << endl;
	cout << mat5 << endl;
	// 한번에 init
	Mat mat6 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	cout << mat6 << endl;
	
	cout << mat6 + mat4 << endl;
	Mat mat7 = Mat_<float>({ 2, 3 }, { 1,2,3,4,5,6 });
	cout << mat7 << endl;

	// create 사용
	mat4.create(256, 256, CV_8UC3);
	mat5.create(4, 4, CV_32FC1);
	
	mat4 = Scalar(255, 0, 0);
	mat5.setTo(1.f);
	

	return 0;
}


