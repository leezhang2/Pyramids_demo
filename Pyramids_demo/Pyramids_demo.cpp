// Pyramids_demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<math.h>

using namespace cv;
using namespace std;

Mat src, dst, tmp;
const char* window_name = "Pyramids Demo";

int main()
{
	printf("\n Zoom In-Out demo \n");
	printf("--------------------\n");
	printf("*[u]->Zoom in \n");
	printf("*[d]->Zoom out \n");
	printf("[ESC]->Close program \n \n");

	src = imread("H:\\opencv\\sources\\samples\\data\\chicky_512.png");
	if (!src.data)
	{
		printf("No data!---Exiting the program \n");
		return -1;
	}
	tmp = src;
	dst = tmp;

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	imshow(window_name, dst);
	
	while (1)
	{
		
		char c = (char)waitKey(10);
		if ((char)c == 27)
		{
			break;
		}
		if ((char)c == 'u')
		{
			pyrUp(tmp, dst, Size(tmp.cols * 2, tmp.rows * 2));
			printf("**Zoom In:Image * 2\n");
		}
		else if((char)c == 'd')
		{
			pyrDown(tmp, dst, Size(tmp.cols / 2, tmp.rows / 2));
			printf("**Zoom Out:Image/2 \n");
		}
		imshow(window_name, dst);
		tmp = dst;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
