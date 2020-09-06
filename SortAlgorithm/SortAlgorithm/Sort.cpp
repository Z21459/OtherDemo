#include <iostream>
#include <vector>
using namespace std;

//常用两个函数，获得最大值和交换
int getMaxValue(const vector<int> &arr) {
	int max = 0;
	for (auto val : arr) {
		if (val > max) {
			max = val;
		}
	}
	return max;
}

void Swap(int &pa, int &pb) {
	int temp = pa;
	pa = pb;
	pb = temp;
}

//冒泡排序依次比较相邻两元素，若前一元素大于后一元素则交换之，直至最后一个元素即为最大；
//然后重新从首元素开始重复同样的操作，直至倒数第二个元素即为次大元素   O(N2) 稳定
void bubbleSort(vector<int>&arr, int bgn, int end) {
	/*isLoop用于指示依次遍历中是否发生元素交换，若没有，则已是有序数列，退出即可*/
	bool isLoop = true;
	for (int i = end; true == isLoop && i > bgn; --i) {
		isLoop = false;
		for (int j = bgn + 1; j < i; ++j) {
			if (arr[j] < arr[j - 1]) {
				Swap(arr[j], arr[j - 1]);
				isLoop = true;
			}
		}
	}
}

//选择排序 首先初始化最小元素索引值为首元素，依次遍历待排序数列，若遇到小于该最小索引位置处的元素则刷新最小索引为该较小元素的位置，直至遇到尾元素，结束一次遍历
//并将最小索引处元素与首元素交换；然后，初始化最小索引值为第二个待排序数列元素位置，同样的操作，可得到数列第二个元素即为次小元素；O(N2) 不稳定
void selectSort(vector<int>&arr, int bgn, int end) {
	for (int i = 0; i < bgn; ++i) {
		int minIndex = 0;
		for (int j = i + 1; j < end; ++j) {
			if (arr[j] < arr[j + 1]){
				minIndex = j;
            }
		}
		if (minIndex != i) {
			Swap(arr[i], arr[minIndex]);
		}
	}
}

//快速排序 （类似于选择排序的定位思想）选一基准元素，依次将剩余元素中小于该基准元素的值放置其左侧，大于等于该基准元素的值放置其右侧；
//然后，取基准元素的前半部分和后半部分分别进行同样的处理；以此类推，直至各子序列剩余一个元素时，即排序完成（类比二叉树的思想，from up to down）O(NlogN) 不稳定
void quickSort(vector<int>&arr, int bgn, int end) {
	if (bgn >= end - 1) {
		return;
	}
	int lindex = bgn;
	int rindex = end - 1;
	int std = arr[lindex];
	while (lindex < rindex) {
		while (lindex < rindex) {
			if (arr[rindex] < std) {
				arr[lindex++] = arr[rindex];
				break;
			}
			--rindex;
		}
		while (lindex < rindex)
		{
			if (arr[lindex] >= std)
			{
				arr[rindex--] = arr[lindex];
				break;
			}
			++lindex;
		}
	}
	arr[lindex] = std;
	quickSort(arr, bgn, lindex);
	quickSort(arr, rindex + 1, end);
}
//插入排序  数列前面部分看为有序，依次将后面的无序数列元素插入到前面的有序数列中，初始状态有序数列仅有一个元素，即首元素。
//在将无序数列元素插入有序数列的过程中，采用了逆序遍历有序数列，相较于顺序遍历会稍显繁琐，但当数列本身已近排序状态效率会更高。  O(N2) 稳定
void insertSort(vector<int>&arr, int bgn, int end) {
	for (int i = bgn + 1; i < end; i++) {
		/*
* 分为1,2两部分处理，可以囊括j = beg - 1时的情况
* 即需要将arr[i]插入到首元素前的位置，若使用一个for
* 包括这两部分，则会在发生这种情况时退出
  */
    /*1*/
		int j = i - 1;
		for (; j > bgn; --j) {
			if (arr[j] <= arr[i])
				break;
		}
		/*2*/
		if (j != i - 1) {
			int temp = arr[i];
			for (int k = i; k > j + 1; --k) {
				arr[k] = arr[k - 1];
			}
			arr[j + 1] = temp;
		}
	 }
}
//希尔排序 - 插入排序的改进版。为了减少数据的移动次数，在初始序列较大时取较大的步长，通常取序列长度的一半，此时只有两个元素比较，交换一次；
//之后步长依次减半直至步长为1，即为插入排序，由于此时序列已接近有序，故插入元素时数据移动的次数会相对较少，效率得到了提高。O(N3/2) 不稳定
/*希尔排序*/
void shellSort(vector<int> &arr, int bgn, int end)
{
	for (int step = (end - bgn) / 2; step > 0; step /= 2)
	{
		for (int i = bgn; i < step; ++i)
		{
			/*
			* 以下，insertSort的变异
			*/
			for (int j = i + step; j < end; j += step)
			{
				int k = j - step;
				for (; k >= i; k -= step)
					if (arr[k] <= arr[j])
						break;
				if (k != j - step)
				{
					int tmp = arr[j];
					for (int m = j; m > k + step; m -= step)
						arr[m] = arr[m - step];
					arr[k + step] = tmp;
				}
			}
		}
	}
}
//桶排序 - 实现线性排序，但当元素间值得大小有较大差距时会带来内存空间的较大浪费。首先，找出待排序列中得最大元素max，申请内存大小为max + 1的桶（数组）并初始化为0；
//然后，遍历排序数列，并依次将每个元素作为下标的桶元素值自增1；
//最后，遍历桶元素，并依次将值非0的元素下标值载入排序数列（桶元素 > 1表明有值大小相等的元素，此时依次将他们载入排序数列），遍历完成，排序数列便为有序数列。O(x*N) 稳定

void bucketSort(vector<int> &arr)
{
	int max = getMaxValue(arr);
	int *pBuf = new int[max + 1];

	memset(pBuf, 0, (max + 1) * sizeof(int));
	for (auto const i : arr)
		++pBuf[i];

	for (int i = 0, j = 0; i <= max; ++i)
	{
		while (pBuf[i]--)
			arr[j++] = i;
	}
	delete[]pBuf;
}
//基数排序 - 桶排序的改进版，桶的大小固定为10，减少了内存空间的开销。首先，找出待排序列中得最大元素max，并依次按max的低位到高位对所有元素排序；
//桶元素10个元素的大小即为待排序数列元素对应数值为相等元素的个数，即每次遍历待排序数列，桶将其按对应数值位大小分为了10个层级，
//桶内元素值得和为待排序数列元素个数。O(x*N)  稳定
//1. 计数排序，按整形数值单位进行排序
void countSort(vector<int> &arr, int exp)
{
	int bucket[10] = { 0 };
	int arrSize = arr.size();
	int *pTemp = new int[arrSize];
	memset(pTemp, 0, arrSize * sizeof(int));//将申请的空间清空

	//统计单位exp各数值计数值
	for (auto const val : arr)
		++bucket[(val / exp) % 10];

	//计数分层
	for (int i = 1; i < 10; ++i)
		bucket[i] += bucket[i - 1];

	//按exp位大小用数组arr元素填充pTemp
	for (int i = arrSize - 1; i >= 0; --i)
		pTemp[--bucket[(arr[i] / exp) % 10]] = arr[i];
	/*bugs*/
#if 0
	//bug1: bucket各层次的计数值没遍历一次相应自减1
	for (auto const val : arr)
		pTemp[bucket[(val / exp) % 10] - 1] = val;
	//bug2: arr数组元素每次排序时，下标应从大到小遍历，否则无法实现排序
	for (auto const val : arr)
		pTemp[--bucket[(val / exp) % 10]] = val;
#endif

	//pTemp -> arr
	for (int i = 0; i < arrSize; ++i)
		arr[i] = pTemp[i];
	delete[]pTemp;
}
//2. 合并各单位计数排序结果
void radixSort(vector<int> &arr)
{
	int max = getMaxValue(arr);
	for (int exp = 1; max / exp != 0; exp *= 10)
		countSort(arr, exp);
}
//归并排序 - 采用了分治和递归的思想，递归 & 分治 - 排序整个数列如同排序两个有序数列，依次执行这个过程直至排序末端的两个元素，
//再依次向上层输送排序好的两个子列进行排序直至整个数列有序（类比二叉树的思想，from down to up）。O(NlogN) 稳定
/*归并排序*/
//排序两个有序数列
void mergeSortInOrder(vector<int> &arr, int bgn, int mid, int end)
{
	int *pBuf = new int[end - bgn];
	int *pTemp = pBuf;
	int lindex = bgn;
	int rindex = mid;

	while ((lindex < mid) && (rindex < end))
		*(pTemp++) = (arr[lindex] < arr[rindex]) ? arr[lindex++] : arr[rindex++];

	while (lindex < mid)
		*pTemp++ = arr[lindex++];
	while (rindex < end)
		*pTemp++ = arr[rindex++];

	//pTemp -> arr
	pTemp = pBuf;
	for (int i = bgn; i < end; i++)
		arr[i] = *pTemp++;

	delete[]pBuf;
}
//UpToDown To DownToUp
void mergeSort(vector<int> &arr, int bgn, int end)
{
	//数组arr空or仅有一个元素则退出
	if (bgn >= end - 1)
		return;

	int mid = (bgn + end) / 2;
	mergeSort(arr, bgn, mid);
	mergeSort(arr, mid, end);
	mergeSortInOrder(arr, bgn, mid, end);
}
//堆排序 - 堆排序的思想借助于二叉堆中的最大堆得以实现。首先，将待排序数列抽象为二叉树，并构造出最大堆；
//然后，依次将最大元素（即根节点元素）与待排序数列的最后一个元素交换（即二叉树最深层最右边的叶子结点元素）；
//每次遍历，刷新最后一个元素的位置（自减1），直至其与首元素相交，即完成排序。 O(NlogN) 不稳定
/*堆排序*/
//根节点元素自顶向下移动到合适的位置以构成最大堆
void downToMaxHeap(vector<int> &arr, int bgn, int end)
{
	int child;
	int parent = bgn;

	/*假根节点向下移动至合适的位置 --整个堆排序的核心代码块*/
	while ((child = parent * 2 + 1) < end)
	{
		if ((child < end - 1) && (arr[child] < arr[child + 1]))
			++child;    //右孩子节点
		if (arr[child] > arr[parent])
			Swap(arr[child], arr[parent]);
		else
			break;
		parent = child;
	}
}
//将数组构造为最大堆
void buildMaxHeap(vector<int> &arr, int bgn, int end)
{
	if (bgn >= end - 1)
		return;

	int parent = end / 2 - 1;
	while (parent >= 0)
	{
		downToMaxHeap(arr, parent, end);
		--parent;
	}
}
//堆排序
void heapSort(vector<int> &arr, int bgn, int end)
{
	/*for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}*/
	//构造最大堆
	buildMaxHeap(arr, bgn, end);

	while (end > 1)
	{
		Swap(arr[0], arr[--end]);
		downToMaxHeap(arr, 0, end);
	}
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}
}



int main() {
    //-https://www.cnblogs.com/Glory-D/p/7884525.html
	vector<int>a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(2);
	a.push_back(8);
	a.push_back(1);
	a.push_back(3);
	a.push_back(5);
	a.push_back(2);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	cout << "\n";
	//cout << "***" <<sizeof(long) << sizeof(int) << sizeof(double) << sizeof(float) <<sizeof(long long) << sizeof(char*);
	insertSort(a, 0, a.size());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	system("pause");
	return 0;
}