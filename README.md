# OpenCV
1. opencv 학습
2. 주의점! imshow(), waitkey() 같이 호출해야 동작한다.

```c++
cv::imshow("image", img);
cv::imshow("image2", img2);
//imshow와 waitkey는 연속호출
cv::waitKey(); // key 입력 대기
```



# OpenCV 의 클래스

1. Point_ class : 2차원 평면좌표를 나타내는 class

```c++

template<typename _Tp> class Point_
{
public:
	Point_();
	Point_(_Tp x, _Tp y);
	Point_(const Point_& pt);

	Point_& operator = (const Point_& pt);

	_Tp dot(const Point_& pt) const; // 두 점 사이의 내적
	double ddot(const Point_& pt) const; // 내적을 double형 return
	double cross(const Point_& pt) const; // 외적
	bool inside(const Rect_<_Tp>& r) const; // 두점이 사각형 r 영역에 있는지 확인 함수

	_Tp x, y;


};

typedef Point_<int> Point2i;
typedef Point_<long> Point2l;
typedef Point_<float> Point2f;
typedef Point_<double> Point2d;
typedef Point2i	Point;

```

2. Size_ : width * height를 나타내는 class
```c++
template<typename _Tp> class Size_
{
public:
	Size_();
	Size_(_Tp x, _Tp y);
	Size_(const Size_& sz);

	Size_& operator = (const Size_& sz);

	_Tp area() const; // 넓이 반환
	bool empty() const; // 유효하지 않은 크기면 true return

	_Tp width, height;
};

typedef Size_<int> Size2i;
typedef Size_<long> Size2l;
typedef Size_<float> Size2f;
typedef Size_<double> Size2d;
typedef Size2i Size;

```