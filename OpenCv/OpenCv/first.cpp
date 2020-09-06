#pragma once
#include"allhead.h"

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

/*
����������Ĳ���  ������opencv�Ļ���
�Ծ��������һЩ����
*/

const string path = "F:\\GraduatedFile\\1.png";
const string vPath = "./111.mp4";


//��ʾͼ��
void onShowImg(Mat &img)
{
	// ����һ��ͼƬ��poyanghu��Сͼ��    
	//Mat img = imread(path);
	// ����һ����Ϊ "ͼƬ"����    
	namedWindow("ͼƬ");
	// �ڴ�������ʾͼƬ   
	imshow("ͼƬ", img);
	// �ȴ�6000 ms�󴰿��Զ��ر�    
	waitKey(6000);
}
//��ʴ  ��ͼ�а�ɫ���� ��ʴ��ͼ���и�������
void onImgFuShi(Mat &img)
{
	/*Mat img = imread(path);
	imshow("ԭͼ", img);*/
	//��ʴ
	Mat ele = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImg;
	erode(img, dstImg, ele);
	img = dstImg;
}
//ģ�� ���о�ֵ�˲�
void onImgMoHu(Mat &img)
{
	Mat dstImg;
	blur(img, dstImg, Size(15, 15));
	img = dstImg;
}
//canny��Ե���  ����ת���ɻҶ�ͼ ����blur����ģ���ͽ��� Ȼ����canny
//���б�Ե���
void onImgBianYuan(Mat &img)
{
	Mat dstImg, edgeImg, grayImg;
	//������С�ľ���
	dstImg.create(img.size(), img.type());
	//ת���ɻҶ�
	cvtColor(img, grayImg, COLOR_BGR2GRAY);
	//���� ʹ��3*3�ں˽���
	blur(grayImg, edgeImg, Size(3, 3));
	//Canny����
	Canny(edgeImg, edgeImg, 3, 9, 3);

	img = edgeImg;
}


//������������ VideoCapture

void onReadVideo(const string path)
{
	VideoCapture cap(path);
	//ѭ����ʾÿһ֡
	while (1)
	{
		Mat frame;
		cap >> frame;
		imshow("������ȡ", frame);
		waitKey(300);
	}
}
//��������ͷ�ɼ�ͼ��
void onVideoXiangJi(const string path)
{
	VideoCapture cap(0);
	while (1)
	{
		Mat frm;
		cap >> frm;
		imshow("��ǰ֡", frm);
		waitKey(30);//��ʱ30ms
	}
}
//��������ͷ ��Ե���
void onVideoCanny(const string path)
{
	VideoCapture cap(0);
	Mat edgImg;
	while (1)
	{
		Mat frm;
		cap >> frm;
		imshow("��ǰ֡", frm);
		///�Ҷ�ͼ
		cvtColor(frm, edgImg, CV_BGR2GRAY);
		//����
		blur(edgImg, edgImg, Size(3, 3));
		//�߼�
		Canny(edgImg, edgImg, 0, 30, 3);
		imshow("canny ֮������", edgImg);
		if (waitKey(30) >= 0) break;//��ʱ30ms		
	}
}


int mainf()
{
	//////////////////////////////////first//////////////////
	//Mat img = imread(path);
	//imshow("ԭͼ", img);
	//onShowImg(img);
	//onImgFuShi(img);
	//onImgMoHu(img);
	//onImgBianYuan(img);
	//imshow("Ч��ͼͼƬ", img);
	//waitKey(0);
	//��Ƶ����
	//onReadVideo(vPath);
	//onVideoXiangJi(vPath);
	//onVideoCanny(vPath);

	system("pause");
	return 0;
}