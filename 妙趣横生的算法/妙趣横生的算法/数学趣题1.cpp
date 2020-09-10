#include "allHead.h"
/*
1.舍罕王失算 1 2 4 8 16
2.求两个数最大公约和最小公倍数
3.近似证明
4.三色球
5.白钱买百鸡
6.回文
7.填数字
8.新郎 新娘
9.兔子产仔  斐波那契序列
10.魔幻方阵
11.甲乙丙 三个人说谎   使用穷举法进行判断
*/
//失算
void onSumAll(int n)
{
	int sum = 0;
	if (n <= 0) return;
	for (int i = 1; i <= n; i++)
	{
		sum = sum + int(pow(2, i - 1));
	}
	cout << sum << endl;
	return;
}
//公约和最小公倍数
void onGongYue(int a, int b)
{
	//最大公
	if (a <= 0 || b <= 0) return;
	int yue = 0;
	int bei = 0;
	if (a > b)
	{
		yue = b;
		bei = a;
	}
	else
	{
		yue = a;
		bei = b;
	}
	while (yue)
	{
		if (a%yue == 0 && b%yue == 0)
		{
			cout << yue;
			break;
		}
		yue--;
	}
	//公倍
	while (bei)
	{
		if (bei%a == 0 && bei%b == 0)
		{
			cout << bei;
			break;
		}
		bei++;
	}
}
//近似
void onJinShi(int left, int right)
{
	bool flag = false;
	if (left <= 2) return;
	for (int i = left; i <= right; i++)
	{
		if (i % 2 == 0)//求出每个偶数
		{
			int k = 1;
			while (k <= i)
			{
				if (k % 2 != 0 && (i - k) % 2 != 0)
				{
					flag = true;
					return;
				}
				k++;
			}
			if (flag)
				cout << "true \n";
			else
				cout << "false";
		}
	}
}
//三色球 3 3 6 摸出8个球 搭配  穷举法
void onSanSe(int a, int b, int c)
{
	// 0 1 2 3；0 1 2 3；2 3 4 5 6
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			for (int k = 2; k <= c; k++)
			{
				if ((i + j + k) == 8)
					cout << i << " " << j << " " << k << endl;
			}
		}
	}
}
//百鸡买
void onBuyJi()
{
	int father = 5;
	int mouther = 3;
	int sou = 1/3;
	int sum = 100;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			for (int k = 0; k < 101; k++)
			{
				if (((i + j + k) == 100) && (5 * i + 3 * j + k / 3) == 100  && k%3 == 0)
					cout << i << " " << j << " " << k << endl;

			}
		}
	}
}
//回文
void onRev(const char *str)
{
	int len = strlen(str);
	bool flag = true;
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
			flag = false;
	}
	if (flag)
		cout << "是回文\n";
	else
		cout << "不是回文\n";
	return;
}
//填数字 穷举法 //判断
int onRe(int a)
{
	int sum = 0;
	while (a)
	{
		int yu = a % 10;
		sum = sum*10 + yu;
		a = a / 10;
	}
	return sum;
}
int onFunc(int i, int j)
{
	//判断五个数是否相同
	vector<int> a_vec;
	while (i)
	{
		int yu = i % 10;
		a_vec.push_back(yu);
		i = i / 10;
	}
	if (a_vec[0] == a_vec[1]) return 0;
	if (a_vec[0] == a_vec[2]) return 0;
	if (a_vec[0] == a_vec[3]) return 0;
	if (a_vec[0] == j) return 0;
	if (a_vec[1] == a_vec[2]) return 0;
	if (a_vec[1] == a_vec[3]) return 0;
	if (a_vec[1] == j) return 0;
	if (a_vec[2] == a_vec[3]) return 0;
	if (a_vec[2] == j) return 0;
	if (a_vec[3] == j) return 0;
	return 1;

}
void onTianShu()
{
	for (int i = 1000; i < 10000; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (i*j == onRe(i) && onFunc(i, j))//满足
			{
				cout << i << " * " << j << " = " << (i*j);
			}
		}
	}
}
//新郎 新娘  穷举法
int onMatch(int i, int j, int k, char wife[])
{
	if (wife[i] == 'X') return 0;
	if (wife[j] == 'X') return 0;
	if (wife[k] == 'Z') return 0;
	return 1;
}
void onFindWife()
{
	char husband[3] = { 'A','B','C' }, wife[3] = { 'X','Y','Z' };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (i != j && i != k && j != k)
				{
					if (onMatch(i, j, k, wife))
					{
						cout << "得到一组";
					}
					
				}
			}
		}
	}
}
//水鲜花数
void onFindFlo()
{
	for (int i = 100; i < 1000; i++)
	{
		int temp = i;
		int sum = 0;
		while (i)
		{
			sum = sum + (i % 10)*(i % 10)*(i % 10);
			i = i / 10;
		}
		if (sum == temp)
		{
			cout << temp << endl;
		}
		i = temp;//i已经被修改  需要重新赋值
	}
	return;
}
//魔幻方阵  行列 对角线值相同  穷举法
void onMoHuanMatri()
{
	//三层循环 输出满足的值 1-9 3*3的方阵
}
//全排列
void onAllSort1()
{
	int arr[3] = { 1,2,3 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[i] != arr[j] & arr[i] != arr[k] && arr[j] != arr[k])
					cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
			}
		}
	}
}
void onPrem(int a[], int n, int s, int r[], int m)
{
	//a 1 2 3
 	int i=0, j=0, k=0, flag = 0;
	int b[3];
	for (i = 0; i < n; i++)
	{
		flag = 1;
		r[s] = a[i];
		j = 0;
		for (k = 0; k < n; k++)
		{
			if (i != k)
			{
				b[j] = a[k];
				j++;
			}
		}
		onPrem(b, n - 1, s + 1, r, m);
	}
	if (flag == 0)
	{
		//cout << endl;
		for (k = 0; k < m; k++)
			cout << r[k] << " ";
		cout << endl;
	}
}
void onAllSort2()
{
	const int max = 200;
	int a[3] = {1,2,3}, r[3];
	int len = sizeof(a) / sizeof(a[0]);
	onPrem(a, 3, 0, r, 3);
}
//亲密数
void onLoveNum()
{
	//求a中的每一个数 然后去b中找 ，并且分解b中的所有因子数
	
	int i, j, x[3001];
	for (i = 1; i <= 3000; i++)
	{
		int sum = 0;
		for (j=1 ; j < i; j++)
		{
			if (i%j == 0)
				sum += j;
		}
		x[i] = sum;//存放所有的数的 质数和
	}
	for (i = 1; i <= 3000; i++)
	{
		if (x[i] != -1)
		{
			for (j = i + 1; j <= 3000; j++)
			{
				if (x[i] == j && x[j] == i)
				{
					cout << i << " " << j << endl;
					x[j] = -1;//找到了
				}
			}
		}
	}
}
//数字翻译器


const char *data0[19] = 
{
	"one", "two", "three" , "four", "five", "six" , "seven",
	"eight" , "nine" , "ten", "eleven", "twelve", "thirteen" , "fourteen",
	"fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen"
};
const char *data1[10] =
{
	"twenty","thrity","forty","fifty" ,"sixty" ,"seventy","eighty","ninty",
	"hundred" ,"thousand"
};
//enum NumToEnglish
//{
//	one = 1, two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7,
//	eight = 8, nine = 9, ten = 10, eleven = 11, twelve = 12, thirteen = 13, fourteen = 14,
//	fifteen = 15, sixteen = 16, seventeen = 17, eighteen = 18, nineteen = 19, twenty = 20,
//	hundred = 21,thousand =22,thrity=23,forty=24,fifty=25,sixty=26,seventy=27,eighty=28,
//	ninty=29
//};
int onQian(int a)
{
	int temp = a - (a / 1000) * 1000;
	cout << data0[(a / 1000)-1] << " " << "thousand" << " ";
	return temp;
}
int onBai(int a)
{
	int temp = a - (a / 100) * 100;
	cout << data0[(a / 100) - 1] << " " << "hundred" << " ";
	return temp;
}
void onShi(int a)
{
	if (a % 10 != 0)//有余数 带各位
	{
		int temp = a % 10;
		cout << data1[(a / 10) - 2] << " " << data0[temp - 1];
	}
	else//没有余数
	{
		cout << data1[(a / 10)-2];
	}
}
void onFanyi()
{
	int a = 120;
	//先计算千位  如果不存在- 计算百位  百位不存在计算十位和各位
	if (a / 1000 != 0)//存在千位
	{
		int temp = onQian(a);
		int shi = onBai(temp);
		onShi(shi);
	}
	else//不存在千位
	{
		if (a / 100 != 0)//存在百位
		{
			int shi = onBai(a);
			onShi(shi);
		}
		else//只有两位  十位和各位
		{
			onShi(a);
		}
	}
}





int main1()
{

	//onSanSe(3, 3, 6);
	//onBuyJi();

	//onFindFlo();

	//onAllSort1();
	//onAllSort2();

	//onLoveNum();
	//onFanyi();


	system("pause");
	return 0;
}