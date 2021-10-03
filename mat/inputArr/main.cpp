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
	
	Vec<uchar, 3> p1, p2(0, 0, 255);
	// also
	Vec3b p11, p22(0, 0, 255);
	p1.val[0] = 100;
	p11[0] = 233;
	cout << p1 << endl;
	cout << p11 << endl;
	// scalar
	// blue green red 투명도

	Scalar gray = 128;
	cout << gray << endl;
	Scalar yellow(0, 0, 0);
	yellow[0] = 0;
	cout << "Yellow: " << yellow << endl;
	Mat img(256, 256, CV_8UC3, yellow);
	for (int i = 0; i < 4; i++)
		cout << yellow[i] << endl;

	auto printMat = [](InputArray _mat) {
		Mat mat = _mat.getMat();
		cout << mat << endl;
	};


	auto inputArrOp = [&printMat]() {
		uchar data1[] = { 1,2,3,4,5,6 };
		Mat mat1(2, 3, CV_8U, data1);
		printMat(mat1);

		vector<float> mat2 = { 1.24f, 3.1f,2.1f };
		printMat(mat2);

		; };

	inputArrOp();
	
	imshow("img1", img);





	waitKey();
	destroyAllWindows();


	return 0;
}


