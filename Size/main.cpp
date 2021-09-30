#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	cout << "HELLO CV " << CV_VERSION << endl;

	Size sz1, sz2(10, 30);
	if (sz1 == sz2)
		cout << "같은 객체입니다" << endl;
	else
		cout << "다른 객체입니다" << endl;
	cout << "sz1: " << sz1 << endl;
	cout << "sz2: " << sz2 << endl;

	cout << "sz1 area: " << sz1.area() << endl;
	cout << "sz2 area: " << sz2.area() << endl;

	

	sz1.width = 10;
	sz1.height = 30;

	if (sz1 == sz2)
		cout << "같은 객체입니다" << endl;
	else
		cout << "다른 객체입니다" << endl;

	cout << "sz1: " << sz1 << endl;
	cout << "sz2: " << sz2 << endl;

	cout << "sz1 area: " << sz1.area() << endl;
	cout << "sz2 area: " << sz2.area() << endl;



	return 0;
}


