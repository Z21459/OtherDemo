#include "allhead.h"
const string path5 = "2.jpg";

/*
操作图像中的像素
设置感兴趣区域ROI
进行图像混合
分离颜色通道
进行多通道图像混合
调整图像对比度和亮度
图像傅里叶变换


1.图像矩阵的大小取决于所用的颜色模型 取决于通道数  多通道-多个子列
LUT函数 Look up table操作 operationOnArrays:LUT()<lut>
计时函数 getTickCount()--CPU事件自启动来时  getTickFrequency()--CPU 一秒钟走的周期数
两者相减
*/

void colorReduce(Mat &img, int div)
{
	imshow("原始", img);
	Mat detImg;
	detImg.create(img.rows, img.cols, img.type());
	double time0 = static_cast<double>(getTickCount());

	/* 操作 减少*/
	detImg = img.clone();
	int row = detImg.rows;
	int col = detImg.cols*detImg.channels();//列数乘以通道数

	for (int i = 0; i < row; i++)
	{
		uchar *data = detImg.ptr<uchar>(i);//得到任意行首地址
		for (int j = 0; j < col; j++)
		{
			data[j] = data[j] / div * div + div / 2;//处理每个像素
		}
	}

	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	std::cout << time0 << endl;
	imshow("效果", detImg);
	waitKey(0);

}

//感兴趣区域值ROI 例子可参照three
/*
1.使用表示矩形区域Rect
2.指定行列范围 Range
*/

//分离颜色通道和多通道图
/*
split 将一个多通道分离成几个单通道
merge 将多个单通道合并成一个多通道
*/

//图像对比和亮度调整  --算子的概念 
/*
点操作：根据输入像素值，来计算相应的输出像素值，这类算子有
亮度  对比度 颜色 变换
*/
int g_ConValue = 0;
int g_BrightValue = 0;
Mat img, desImgf;
static void onConBright(int, void *)
{
	namedWindow("Xiao", 1);//窗口名字定义要一样  否则没办法显示滚动
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				desImgf.at<Vec3b>(i, j)[k] =
					saturate_cast<uchar>((g_ConValue*0.01)*(img.at<Vec3b>(i, j)[k]) + g_BrightValue);
			}
		}
	}
	imshow("Xiao", img);
	imshow("yuan", desImgf);
	while (char(waitKey(1)) != 'q'){};
}
static void onConstra(Mat &img)
{
	if (!img.data) return;
	desImgf = Mat::zeros(img.size(), img.type());

	g_ConValue = 80;
	g_BrightValue = 80;
	namedWindow("Xiao", 1);
	createTrackbar("Con", "Xiao",&g_ConValue, 300, onConBright);
	createTrackbar("Bright", "Xiao", &g_BrightValue, 200, onConBright);
	onConBright(g_ConValue,0);
	onConBright(g_BrightValue,0);
}

//傅里叶变换 dft

int main5()
{
	img = imread(path5);
	//colorReduce(img, 32);
	onConstra(img);

	system("pause");
	return 0;
}