#include "allHead.h"

/*
������ݹ�--�ֶ��ֶ���֮��ԭ��   ��ٷ� ��һ����Χ���г����п��ܵ�ֵ���ҵ�����Ҫ���
1.�ݹ���ŵ��
2.�����̶����⣬���Ӵ�
3.������������
4.������
5.�ǹȲ���
6.�ķ����� ��������Ȼ��������ĸ�����ƽ���ͱ�ʾ   --��ٱ�ʾ1 2 3 4
7.�ݹ�Ѱ����Сֵ
8.���ػ���
9.ʹ�õݹ� ���ֲ���
10.ѡ������ ����Խ�� ����Խ�� �������ճ���˳���������Σ�����ͬ����ѡ��




*/
//���ݹ�
inline int onFibo(int n) {
	if (n == 2 || n == 1) {
		return 1;
	}
	else {
		return onFibo(n - 1) + onFibo(n - 2);
	}
}
//�ݹ���ŵ�� ͨ���ƶ� ��Ĳ�����С������  ʹ���е� ��b��
void onHanTaKe(int n = 4,int a = 1, int b = 3, int c = 2)
{
	if (n == 1)//һ������
	{
		cout << a << " -> " << b << endl;
		return;
	}
	if (n == 2)
	{
		cout << a << " -> " << c << endl;
		cout << a << " -> " << b << endl;
		cout << c << " -> " << b << endl;
		return;
	}
	else
	{
		onHanTaKe(n - 1, a, b, c);
		cout << a << " -> " << b << endl;
		onHanTaKe(n - 1, c, b, a);
	}
		

}
//�����̶�����
void onSqeNum(int a)
{
	int i = 0;
	bool flag = false;
	for (i = 0; i < a; i++)
	{
		int sum = 0;
		for (int k = i; k < a; k++)
		{
			sum = sum + k;
			if (sum == a)
			{
				for (int j = i; j <= k; j++)
				{
					if (j != k)
						cout << j << "+";
					else
						cout << j << "=" << a;
				}
				cout << endl;
				flag = true;
				break;
			}
			if (sum > a)
			{
				break;
			}
		}
	}
	if (!flag)
	{
		cout << "������\n";
	}
}
//������������
void onSumInt(int a)
{
	if (a <= 0) return;
	int i = 0, j = 0;
	bool flag = false;
	for (i = 1; i < a; i++)
	{
		for (j = 1; j < a; j++)
		{
			if (pow(j, 2) + pow(i, 2) == a)
			{
				cout << i << "^" << 2 <<"+"<<j 
					<< "^" << 2 << "=" << a << endl;
				flag = true;
				break;
			}
		}
	}
	if (!flag)
		cout << "������\n";
}
//������
void onSpecial()
{
	int abcd = 1000;
	for (abcd = 1000; abcd <= 9999; abcd++)
	{
		int r_abcd = abcd;
		vector<int>a_vec;
		while (abcd)
		{
			a_vec.push_back(abcd % 10);//1234  4321
			abcd = abcd / 10;
		}
		int i = 0;
		int ab = 0, cd = 0;
		for (i = a_vec.size() - 1; i >= 0; i--)
		{
			if (i >= a_vec.size() / 2)
			{
				ab = ab * 10 + a_vec[i];
			}
			else
			{
				cd = cd * 10 + a_vec[i];
			}
		}
		int temp = ab + cd;
		int res = pow(temp, 2);
		if (r_abcd == pow(temp, 2))
			cout << r_abcd << endl;
		abcd = r_abcd;//���¸�ֵ
	}
}
//�ǹȲ���
void onJiaoGu(int a)
{
	//ż��/2   ����*3  һֱ�ݹ���ȥ  ���Ϊ��
	int count = 1;
	if ( a < 1)return;
	if (a == 1)
	{
		cout << "true" << endl;
		return;
	}
	while (a!=1 &&count <= 1000)
	{
		if (a % 2 == 0)
		{
			cout << a <<" /2 =" << a/2<< endl;
			a = a / 2;
		}
		else
		{
			cout << a << " * 3 + 1 =" << a * 3 + 1 << endl;
			a = a * 3 +1;
		}
		count++;
	}
	if (count < 1000 && a == 1)
	{
		cout << "true \n";
	}

}
//�ݹ���Сֵ
int onSmallValue(int arr[],int n)//
{
	/*int arr[9] = { 1,5,2,3,4,6,2,5,7 };
	int n = 9;*/
	int v1, v2, v3;
	if (n == 1) return arr[0];
	if (n % 2 == 0)
	{
		v1 = onSmallValue(arr, n / 2);
		v2 = onSmallValue(arr + n / 2, n / 2);
		if (v1 < v2) return v1;
		else return v2;
	}
	if (n % 2 != 0)
	{
		v1 = onSmallValue(arr, n / 2);
		v2 = onSmallValue(arr + n / 2+1, n / 2);
		v3 = arr[n / 2];
		if (v1 < v2)
		{
			if (v1 < v3) return v1;
			else return v3;
		}
		else
		{
			if (v2 < v3) return v2;
			else return v3;
		}
	}
}
//ͬ����
void onSameSum()
{
	int sum = 0;
	int count = 0;
	vector<int> res;
	for (int i = 1; i < 1000; i++)
	{
		sum = (i * i);
		//cout << sum << " ";
		if (i < 10)
		{
			if (i == (sum % 10)) cout << i << endl;
		}
		else if (i >= 10 && i < 100)//��λ��
		{
			res.clear();
			count = 2;
			while(count > 0)
			{
				res.push_back(sum % 10);
				sum = sum / 10;
				count--;
			}
			int t = 0;
			for (int j = res.size()-1; j >= 0; j--)
			{
				t = t * 10 + res[j];
			}
			if (t == i)
			{
				cout << i << endl;
			}
		}
		else//��λ��
		{
			res.clear();
			count = 3;
			while (count > 0)
			{
				res.push_back(sum % 10);
				sum = sum / 10;
				count--;
			}
			for (int j = res.size() - 1; j >= 0; j--)
			{
				count = count * 10 + res[j];
			}
			if (count == i)
			{
				cout << i << endl;
			}
		}
	}
}
void onSameSum1(int i)
{
	int j;
	for (j = 10; j < 1000; j = j * 10)
	{
		if ((i / j) == 0) break;
	}
	if ((i*i) % j == i) cout << i;
}
//���ػ���
bool onIsHuiWen(vector<long> vec)
{
	bool flag = true;
	int len = vec.size();
	for (int i = 0; i < len / 2; i++)
	{
		if (vec[i] != vec[len - i - 1]) flag = false;
	}
	return flag;
}
void onSanHuiWen()
{
	for (int i = 11; i < 1000; i++)
	{
		long temp = i;
		long two = i * i;
		long three = i * i*i;
		vector<long>vec1;
		vector<long>vec2;
		vector<long>vec3;
		while (temp)
		{
			vec1.push_back(temp % 10);
			temp = temp / 10;
		}
		while (two)
		{
			vec2.push_back(two % 10);
			two = two / 10;
		}
		while (three)
		{
			vec3.push_back(three % 10);
			three = three / 10;
		}
		if (onIsHuiWen(vec1) && onIsHuiWen(vec2) && onIsHuiWen(vec3))
		{
			cout << i << endl;
		}
	}
}
//�ݹ���ֲ��� Ѱ�Ҽٱ�
void onDiGuiStart(int a[], int low, int high)
{
	//������ż���ֿ�����
	if (high - low < 2) return;
	if (high - low == 2)
	{
		if (a[low] > a[high - 1]) cout << a[high - 1];
		else cout << a[low];
		return;
	}
	
	int mid = (low + high) / 2;
	int i = 0;
	int sum1 = 0, sum2 = 0;
	for (i = 0; i < mid; i++)
	{
		sum1 += a[i];
	}
	for (i = mid; i < high; i++)
	{
		sum2 += a[i];
	}
	if (sum1 > sum2)//����
	{
		low = mid;
		onDiGuiStart(a, low, high);
	}
	else if(sum1 < sum2)//ǰ���
	{
		high = mid;
		onDiGuiStart(a, low, high);
	}
	else//ǰ����ͬ
	{

	}
}
void onDiGuiErFen()
{
	int a[8] = { 2,2,2,1,2,2,2,2 };
	int low = 0, high = 8;
	onDiGuiStart(a, low, high);
}
//ѡ������
//����ṹ�� �����ŵ÷� ����
struct Player
{
	int id;
	int score;
	int rank;
};
//�������򣬷���(Խ��-���ȼ�Խ��) �ȼ� ���(�������)
void onSortScore(Player player[], int n)
{
	Player temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (player[j].score > player[j + 1].score)
			{
				temp = player[j];
				player[j] = player[j + 1];
				player[j + 1] = temp;
			}
		}
	}
}
//���շ�������� ��λ����
void onSetRand(Player player[], int n)
{
	int i, j = 2;
	player[0].rank = 1;
	for (i = 1; i < n; i++)
	{
		if (player[i].score != player[i - 1].score)
		{
			player[i].rank = j;
			j++;
		}
		else
			player[i].rank = player[i - 1].rank;
	}
}
//�ڰ����������
void onSordId(Player player[],int n)
{
	Player temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (player[j].id > player[j + 1].id)
			{
				temp = player[j];
				player[j] = player[j + 1];
				player[j + 1] = temp;
			}
		}
	}
}
void onChooseBeauty()
{
	Player player[7] = {
		{1,5,0},{2,3,0},{3,4,0},
		{4,7,0},{5,3,0},{6,5,0},
		{7,6,0}
	};
	int n = 7;
	onSortScore(player,  n);
	onSetRand(player,  n);
	onSordId(player, n);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "id" << " score" << " rank" << endl;
		cout << player[i].id << "    " << player[i].score << "   " << 
			player[i].rank << endl;
	}
}





int main2()
{

	//cout << onFibo(3);
	//onHanTaKe(4, 1, 3, 2);

	//onSqeNum(27);
	//onSumInt(3);
	//onSpecial();
	//onJiaoGu(5);

	//int arr[9] = { 1,5,2,3,4,6,2,5,7 };
	//int n = 9;
	//int t = onSmallValue(arr,9);
	//cout << t << endl;

	//onSameSum();
	//onSanHuiWen();
	//onDiGuiErFen();

	//onChooseBeauty();


	system("pause");
	return 0;
}