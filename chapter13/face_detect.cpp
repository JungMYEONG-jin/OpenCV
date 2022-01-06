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


void detect_face();
void detect_eyes();


int main()
{
	detect_face();
	detect_eyes();
	return 0;
}




void detect_face()
{
	Mat src = imread("aaa.jpg");

	if (src.empty())
	{
		cerr << "IMAGE LOAD FAILED" << endl;
		return;
	}

	CascadeClassifier classifier("haarcascade_frontalface_default.xml");

	if (classifier.empty())
	{
		cerr << "XML LOAD FAILED" << endl;
		return;
	}

	vector<Rect> faces;
	classifier.detectMultiScale(src, faces);

	for (Rect face : faces)
	{
		rectangle(src, face, Scalar(255, 0, 255), 2);
	}

	imshow("src", src);

	waitKey();
	destroyAllWindows();
}

void detect_eyes()
{
	Mat src = imread("kids.png");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	CascadeClassifier face_classifier("haarcascade_frontalface_default.xml");
	CascadeClassifier eye_classifier("haarcascade_eye.xml");

	if (face_classifier.empty() || eye_classifier.empty()) {
		cerr << "XML load failed!" << endl;
		return;
	}

	vector<Rect> faces;
	face_classifier.detectMultiScale(src, faces);

	for (Rect face : faces)
	{
		rectangle(src, face, Scalar(255, 0, 255), 2);

		Mat faceROI = src(face);

		vector<Rect> eyes;
		eye_classifier.detectMultiScale(faceROI, eyes);

		for (Rect eye : eyes)
		{
			Point center(eye.x + eye.width / 2, eye.y + eye.height / 2);
			circle(faceROI, center, eye.width / 2, Scalar(255, 0, 0), 2, LINE_AA);
		}
	}

	imshow("src", src);

	waitKey();
	destroyAllWindows();

}
