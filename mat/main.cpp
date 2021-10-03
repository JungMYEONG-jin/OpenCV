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
	
	Mat img1(480, 640, CV_8UC1); // grayscale ���� 640 ���� 480 1 channel
	Mat img2(480, 640, CV_8UC3); // true color ���� 640 ���� 480 3 channel
	Mat img3(Size(480, 640), CV_8UC3); // Size type
	// ����� ũ��� Ÿ���� �����Ͽ� �����ϸ� �����Ⱚ���� ä���� ex vector���� init�� 0���� ä�����°�
	Mat img4(480, 640, CV_8UC1, Scalar(128)); // all pixel value filled with 128 
	Mat img5(480, 640, CV_8UC3, Scalar(0, 0, 255));; // Scalar���� �÷��� B G R ���̴�.
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
	Mat mat3 = Mat::eye(3, 3, CV_32FC1); // ���� ���
	vector<Mat> matrix;
	matrix.push_back(mat1);
	matrix.push_back(mat2);
	matrix.push_back(mat3);
	for (auto& it : matrix)
		cout << it << endl;
	

	// matrix ������ �ܺε����Ϳ� �Ҵ��ϴ°� ������. �̸� �̿�� �������� �޸� ���� �Ҵ��� ���� �ʾ� ����
	// size �����������. auto_step���� ������ �е�����Ʈ ������� �ʰ� �ϱ� ����
	float data[] = { 1,2,3,4,5,6 };
	Mat mat4(2, 3, CV_32FC1, data);
	// ������ �̷��� �ܺε����� ������ mat ���� �Ǵ� �ܺε����� ����� �Բ� ����ǹǷ� ���� �ʿ�
	cout << mat4 << endl;
	data[4] = 16;
	cout << mat4 << endl;

	Mat_<float> mat5_(2, 3); // 2 by 3 
	mat5_ << 1, 2, 3, 4, 5, 6;
	Mat mat5 = mat5_;
	cout << mat5_ << endl;
	cout << mat5 << endl;
	// �ѹ��� init
	Mat mat6 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	cout << mat6 << endl;
	
	cout << mat6 + mat4 << endl;
	Mat mat7 = Mat_<float>({ 2, 3 }, { 1,2,3,4,5,6 });
	cout << mat7 << endl;

	// create ���
	mat4.create(256, 256, CV_8UC3);
	mat5.create(4, 4, CV_32FC1);
	
	mat4 = Scalar(255, 0, 0);
	mat5.setTo(1.f);
	

	return 0;
}


