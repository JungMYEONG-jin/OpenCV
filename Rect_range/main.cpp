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

	// ��ü�� ���δ� �ּ� ũ�� �簢�� ���ϱ�
	Rect br = r1.boundingRect();
	cout << "br: " << br << endl;



	Range r(0, 10);
	cout << r << endl;
	//start end�� end�� ���� x


	// cv::String�� �����Ͽ����� 4.0 �̻���� std::string�� ��������
	String str1 = "Hello";
	String str2 = "OPENCV";
	cout << str1 << " " << str2 << endl;
	String str3 = str1 + " " + str2;
	cout << str3 << endl;





	return 0;
}


