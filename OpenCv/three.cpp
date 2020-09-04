#include"allhead.h"

/*
HighGUI图形用户界面初步
图像的载入 显示 输出到文件
滑动条Trackbar的创建和使用
OpenCv鼠标操作
Mat类作为数据结构进行图像存取  保存图像和其他矩阵的数据结构

imread()-读  imshow()-显示  nameWindow()-创建窗口 imwrite()-输出图像到文件

*/
//生成一个图片
const string Apath = "1.jpg";
const string Bpath = "2.jpg";
//创建
void createImg(Mat &img)
{
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			Vec4b &rgb = img.at < Vec4b> (i, j);
			rgb[0] = UCHAR_MAX;
			rgb[1] = saturate_cast<uchar>((float(img.cols - 1)) /
				((float)img.cols)*UCHAR_MAX);
			rgb[2] = saturate_cast<uchar>((float(img.rows - 1)) /
				((float)img.rows)*UCHAR_MAX);
			rgb[3] = saturate_cast<uchar>(0.5*(rgb[1]+rgb[2]));
		}
	}
}
//融合
void onMerge(const string Apath, const string Bpath)
{
	Mat logo = imread("1.jpg",199);//38 50
	Mat img2 = imread("2.jpg");//333 500
	
	//融合
	Mat imgROI;
	imgROI = img2(Rect(20, 20, logo.cols, logo.rows));//注意坐标设置  不要超过原图大小  不然报错
	//添加到原图
	addWeighted(imgROI, 0.5, logo, 0.3, 0., imgROI);
	namedWindow("合成");
	imshow("合成", img2);
	waitKey();
}

//添加滑动条 createTrackbar()函数
#define WINDOW_NAME "线形混合"
const int g_nMaxValue = 100;
int g_nValueSlider = 0;//对应变量
double g_AlphaValue = 0.0;
double g_BetaValue = 0.0;
Mat img1;
Mat img2;
Mat desImg;
void onTrackBar(int, void*)
{
	g_AlphaValue = (double)g_nValueSlider / g_nMaxValue;
	g_BetaValue = (1.0 - g_AlphaValue);
	//混合
	addWeighted(img1, g_AlphaValue, img2, g_BetaValue, 0.0, desImg);

	imshow(WINDOW_NAME, desImg);
}
void onMerger1()
{
	//连个图的大小尺寸要一样
	img1 = imread("2.jpg");//38 50
	img2 = imread("2.jpg");//333 500
	g_nValueSlider = 70;
	namedWindow(WINDOW_NAME, 1);
	char TrackbarName[50];
	std::cout << TrackbarName << "Alpha" << g_nMaxValue;
	createTrackbar(TrackbarName, WINDOW_NAME, &g_nValueSlider,
		g_nMaxValue, onTrackBar);
	onTrackBar(g_nValueSlider, 0);
	waitKey(0);
}

//鼠标操作
void onDrawRect(Mat &img, Rect box);
void onMouseHandle(int event, int x, int y, int glags, void*param);
#define WINDOW_MOUSE "鼠标操作"
Rect rect;
bool is_draw = false;//是否绘制
RNG rng(12345);
void onMouseHandle(int event,int x,int y,int glags,void*param)
{
	Mat &img = *(Mat*)param;
	switch (event)
	{
	case EVENT_MOUSEMOVE:
	{
		if (is_draw)
		{
			rect.width = x - rect.x;
			rect.height = y - rect.y;
		}
	}
		break;
	case EVENT_LBUTTONDOWN:
	{
		is_draw = true;
		rect = Rect(x, y, 0, 0);
	}
		break;
	case EVENT_LBUTTONUP:
	{
		is_draw = false;
		if (rect.width < 0)
		{
			rect.x += rect.width;
			rect.width *= -1;
		}
		if (rect.height < 0)
		{
			rect.y += rect.height;
			rect.height *= -1;
		}
		onDrawRect(img, rect);
	}
		break;
	default:
		break;
	}
}
void onDrawRect(Mat &img, Rect box)
{
	rectangle(img, box.tl(), box.br(), Scalar(rng.uniform(0, 255),
		rng.uniform(0, 255), rng.uniform(0, 255)));//随机
}
void onShowHelpText()
{

}
//主函数
void onStartDraw()
{
	rect = Rect(-1, -1, 0, 0);
	Mat img(600, 800, CV_8UC3), tmpImg;
	img.copyTo(tmpImg);
	rect = Rect(-1, -1, 0, 0);
	img = Scalar::all(0);

	//鼠标回调
	namedWindow(WINDOW_MOUSE);
	setMouseCallback(WINDOW_MOUSE, onMouseHandle, (void*)&img);

	while (1)
	{
		img.copyTo(tmpImg);
		if (is_draw) onDrawRect(tmpImg, rect);//
		imshow(WINDOW_MOUSE,tmpImg);
		if (waitKey(10) == 27) break;//ESC退出
	}
}

int main3()
{
	//Mat img(480, 640, CV_8UC4);
	//createImg(img);
	//vector<int>par_vec;
	//par_vec.push_back(IMWRITE_PNG_COMPRESSION);
	//par_vec.push_back(9);
	//try
	//{
	//	imwrite("alpha.png", img, par_vec);
	//	imshow("生成图片",img);
	//	waitKey(0);
	//}
	//catch(runtime_error)
	//{
	//	std::cout << "error\n";
	//	return 1;
	//}

	//onMerge(Apath,Bpath);
	//onMerger1();
	onStartDraw();
	system("pause");
	return 0;
}