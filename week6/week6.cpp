﻿// week6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\27318\\Desktop\\大二下网络课程\\数字图像\\第六周\\lena.jpg");
	cv::Mat dstMat,dstMat1,dx,dy;

	int threshold = 20;
	Sobel(srcMat, dx, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
	Sobel(srcMat, dy, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT);
	Canny(dx, dy, dstMat, threshold, threshold*3);
	imshow("lena1", dstMat);

	Canny(srcMat, dstMat1, threshold, threshold * 3);
	imshow("lena2", dstMat1);

	waitKey(0);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
