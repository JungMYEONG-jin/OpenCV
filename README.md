# OpenCV
1. opencv 학습
2. 주의점! imshow(), waitkey() 같이 호출해야 동작한다.

```c++
cv::imshow("image", img);
cv::imshow("image2", img2);
//imshow와 waitkey는 연속호출
cv::waitKey(); // key 입력 대기
```