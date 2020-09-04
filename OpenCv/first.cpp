#pragma once
#include"allhead.h"

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

/*
矩阵和向量的操作  是运用opencv的基础
对矩阵操作的一些方法
*/

const string path = "F:\\GraduatedFile\\1.png";
const string vPath = "./111.mp4";


//显示图像
void onShowImg(Mat &img)
{
	// 读入一张图片（poyanghu缩小图）    
	//Mat img = imread(path);
	// 创建一个名为 "图片"窗口    
	namedWindow("图片");
	// 在窗口中显示图片   
	imshow("图片", img);
	// 等待6000 ms后窗口自动关闭    
	waitKey(6000);
}
//腐蚀  用图中暗色部分 腐蚀掉图像中高亮部分
void onImgFuShi(Mat &img)
{
	/*Mat img = imread(path);
	imshow("原图", img);*/
	//腐蚀
	Mat ele = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImg;
	erode(img, dstImg, ele);
	img = dstImg;
}
//模糊 进行均值滤波
void onImgMoHu(Mat &img)
{
	Mat dstImg;
	blur(img, dstImg, Size(15, 15));
	img = dstImg;
}
//canny边缘检测  将其转换成灰度图 再用blur进行模糊和降噪 然后用canny
//进行边缘检测
void onImgBianYuan(Mat &img)
{
	Mat dstImg, edgeImg, grayImg;
	//创建大小的矩阵
	dstImg.create(img.size(), img.type());
	//转换成灰度
	cvtColor(img, grayImg, COLOR_BGR2GRAY);
	//降噪 使用3*3内核降噪
	blur(grayImg, edgeImg, Size(3, 3));
	//Canny算子
	Canny(edgeImg, edgeImg, 3, 9, 3);

	img = edgeImg;
}


//视屏基础操作 VideoCapture

void onReadVideo(const string path)
{
	VideoCapture cap(path);
	//循环显示每一帧
	while (1)
	{
		Mat frame;
		cap >> frame;
		imshow("视屏读取", frame);
		waitKey(300);
	}
}
//调用摄像头采集图像
void onVideoXiangJi(const string path)
{
	VideoCapture cap(0);
	while (1)
	{
		Mat frm;
		cap >> frm;
		imshow("当前帧", frm);
		waitKey(30);//延时30ms
	}
}
//调用摄像头 边缘检测
void onVideoCanny(const string path)
{
	VideoCapture cap(0);
	Mat edgImg;
	while (1)
	{
		Mat frm;
		cap >> frm;
		imshow("当前帧", frm);
		///灰度图
		cvtColor(frm, edgImg, CV_BGR2GRAY);
		//降噪
		blur(edgImg, edgImg, Size(3, 3));
		//边检
		Canny(edgImg, edgImg, 0, 30, 3);
		imshow("canny 之后视屏", edgImg);
		if (waitKey(30) >= 0) break;//延时30ms		
	}
}


int mainf()
{
	//////////////////////////////////first//////////////////
	//Mat img = imread(path);
	//imshow("原图", img);
	//onShowImg(img);
	//onImgFuShi(img);
	//onImgMoHu(img);
	//onImgBianYuan(img);
	//imshow("效果图图片", img);
	//waitKey(0);
	//视频操作
	//onReadVideo(vPath);
	//onVideoXiangJi(vPath);
	//onVideoCanny(vPath);

	system("pause");
	return 0;
}