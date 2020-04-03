// week6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("C:\\Users\\27318\\Desktop\\大二下网络课程\\数字图像\\第六周\\lena_rot.jpg", 1);
	cv::Mat grayMat;
	cv::Mat dstMat;
	cvtColor(srcMat, grayMat, CV_BGR2GRAY);
	if (srcMat.empty()) return -1;

	int height = grayMat.rows;
	int width = grayMat.cols;
	int srcX_1,srcY_1, srcX_2, srcY_2, srcX_3, srcY_3, srcX_4, srcY_4 = 0;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			if (j == 0 && grayMat.at<uchar>(j, i) < 250) {
				srcX_1 = j;
				srcY_1 = i;
			}
			if (i == width - 1 && grayMat.at<uchar>(j, i) < 250) {
				srcX_2 = j;
				srcY_2 = i;
			}
			if (i == 0 && grayMat.at<uchar>(j, i) < 250) {
				srcX_3 = j;
				srcY_3 = i;
			}
			if (i == 0 && grayMat.at<uchar>(j, i) < 250) {
				srcX_3 = j;
				srcY_3 = i;
			}
			if (j == height - 1 && grayMat.at<uchar>(j, i) < 250) {
				srcX_4 = j;
				srcY_4 = i;
			}
		}
	}
	cout << srcX_1 << " , " << srcY_1 << endl;
	cout << srcX_2 << " , " << srcY_2 << endl;
	cout << srcX_3 << " , " << srcY_3 << endl;
	cout << srcX_4 << " , " << srcY_4 << endl;
	cout << height << " , " << width << endl;
	//变换前的四点坐标
	cv::Point2f pts1[] = {
		cv::Point2f(srcY_1,srcX_1),
		cv::Point2f(srcY_2,srcX_2),
		cv::Point2f(srcY_3,srcX_3),
		cv::Point2f(srcY_4,srcX_4)
	};
	//变换后的四点坐标
	cv::Point2f pts2[] = {
		cv::Point2f(0,0),
		cv::Point2f(width - 1,0),
		cv::Point2f(0,height - 1),
		cv::Point2f(width - 1,height - 1)
	};
	//计算仿射矩阵
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);

	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());
	cv::imshow("srcMat", srcMat);
	cv::imshow("dstMat", dstMat);
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
