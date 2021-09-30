#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	cout << "HELLO CV " << CV_VERSION << endl;

	Point pt1;
	cout <<"pt1: "<< pt1 << endl;
	// assign
	pt1.x = 5;
	pt1.y = 10;
	Point pt2(10, 30);
	cout << "pt1: " << pt1 << endl;
	cout << "pt2: " << pt2 << endl;

	int d = pt1.dot(pt2);
	cout << "내적: " << d << endl;
	auto same = [](Point& e, Point& k) {return e == k; };
	if (same(pt1, pt2))
		cout << "같은 평면입니다" << endl;
	else
		cout << "다른 평면입니다" << endl;

	pt1.x += 5;
	pt1.y += 20;
	cout << "pt1: " << pt1 << endl;
	cout << "pt2: " << pt2 << endl;
	if (same(pt1, pt2))
		cout << "같은 평면입니다" << endl;
	else
		cout << "다른 평면입니다" << endl;


	return 0;
}