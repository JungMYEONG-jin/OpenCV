#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	cout << "HELLO CV " << CV_VERSION << endl;
	RotatedRect r1(Point2f(40, 30), Size2f(50, 20), 30.f);
	cout << "r1 center: " << r1.center <<"	r1 size: "<<r1.size<<"	r1 angle: "<<r1.angle<< endl;
	Point2f pts[4];
	r1.points(pts);

	for (int i = 0; i < 4; i++)
		cout << pts[i] << endl;

	// 객체를 감싸는 최소 크기 사각형 구하기
	Rect br = r1.boundingRect();
	cout << "br: " << br << endl;



	Range r(0, 10);
	cout << r << endl;
	//start end임 end는 포함 x


	// cv::String이 존재하였으나 4.0 이상부터 std::string과 동일해짐
	String str1 = "Hello";
	String str2 = "OPENCV";
	cout << str1 << " " << str2 << endl;
	String str3 = str1 + " " + str2;
	cout << str3 << endl;





	return 0;
}


