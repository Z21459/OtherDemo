#include <stdio.h>

#define MAX 10
typedef char ElementType;
typedef ElementType ARR[MAX];
//ARR arr1;//ElementType arr1[MAX];
int len = sizeof(ARR)/sizeof(ElementType);

void swap(ElementType arr[],int i,int j)
{
	ElementType temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void print(ARR arr)
{
	int i;
	for(i = 0;i < len;i++)
	{
		printf("%3d",arr[i]);
	}
	printf("\n");
}

void bubble1(ARR arr);
void bubble2(ARR arr);
void select(ARR arr);
void insert(ARR arr);
void shell(ARR arr);
void heapadjust(ARR arr,int n,int m);
void heap(ARR arr);
void mergesort(ARR arr,int left,int right);
void merge(ARR arr,int left,int mid,int right);
void quicksort(ARR arr,int low,int high);
int pivotkey1(ARR arr,int low,int high);
void quicksort(ARR arr,int low,int high);
ElementType getpivot(ARR arr,int low,int high);
void Qsort(ARR arr,int low,int high);

int main()
{
	ARR arr1 = {10,9,8,7,6,5,4,3,2,1};
	ARR arr2 = {10,1,2,3,4,5,6,7,8,9};
	ARR arr3 = {10,9,8,7,6,5,4,3,2,1};
	ARR arr4 = {1,2,3,4,5,6,7,8,10,9};
	ARR arr5 = {6,9,1,3,5,8,2,4,7,10};
	ARR arr6 = {6,4,2,5,10,7,1,8,3,9};
	ARR arr7 = {6,4,2,5,10,7,1,8,3,9};
	ARR arr8 = {1,2,3,4,5,6,7,8,10,9};

	//printf("bubble1 : \n");
	//bubble1(arr1);

	//printf("bubble2 : \n");
	//bubble2(arr2);

	//printf("select : \n");
	//select(arr3);
	
	//printf("insert : \n");
	//insert(arr4);
	
	//printf("shell : \n");
	//shell(arr5);
	//printf("heap : \n");
	//heap(arr6);
	
	//print(arr7);
	//printf("merge : \n");
	//mergesort(arr7,0,len-1);
	
	//print(arr8);
	//printf("quicksort : \n");
	////quicksort(arr8,0,len-1);

	//Qsort(arr8,0,len-1);

    return 0;
}
//冒泡排序
void bubble1(ARR arr)
{
	int i,j;
	for(i = 0;i < len-1;i++)
	{
		for(j = 0;j < len-i-1;j++)
		{
			if(arr[j] > arr[j+1])
				swap(arr,j,j+1);
		}
		print(arr);
	}
}
//改进冒泡排序
void bubble2(ARR arr)
{
	int i,j;
	int flag = 1;
	for(i = 0;i < len-1 && flag;i++)
	{
		flag = 0;
		for(j = 0;j < len-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				flag = 1;
				swap(arr,j,j+1);
			}
		}
		//if(0 == flag)
		//	break;
		print(arr);
	}
}

void select(ARR arr)
{
	int i,j;
	int min;
	for(i = 0;i < len-1;i++)
	{
		min = i;
		for(j = i+1;j < len;j++)
		{
			if(arr[j] < arr[min])
				min = j;
		}
		if(min != i)
			swap(arr,min,i);
		print(arr);
	}
}
//插入排序
void insert(ARR arr)
{
	int i,j;
	ElementType temp;
	for(i = 1;i < len;i++)
	{
		temp = arr[i];
		if(arr[i-1] > arr[i])
		{
			for(j = i-1;j >= 0;j--)
			{
				if(arr[j] > temp)
					arr[j+1] = arr[j];
				else
					break;
			}
			arr[j+1] = temp;
			print(arr);
		}
	}
}

void shell(ARR arr)
{
	int a[] = {1,3,5};
	int k = 2;
	int step = a[k];
	int i,j;
	ElementType temp;

	while(k >= 0)
	{
		for(i = step;i < len;i++)
		{
			if(arr[i-step] > arr[i])
			{
				temp = arr[i];
				for(j = i-step;j >= 0;j -= step)
				{
					if(arr[j] > temp)
						arr[j+step] = arr[j];
					else
						break;
				}
				arr[j+step] = temp;
			}
		}
		step = a[--k];
		print(arr);
	}	
}
//对数组arr[n..m]调整成大顶堆
void heapadjust(ARR arr,int n,int m)
{
	int i;
	ElementType temp = arr[n];
    for(i=2*n+1;i <= m;i = 2*i+1)
    {
    	if(i < m && arr[i] < arr[i+1])
    		i++;
    	if(arr[i] < temp)
    		break;
    	arr[n] = arr[i];
    	n = i;
    }
    arr[n] = temp;
}

void heap(ARR arr)
{
	int i;
	for(i = (len-2)/2;i>=0;i--)
	{
		heapadjust(arr,i,len-1);
	}
	for(i = len-1;i >= 0;i--)
	{
		swap(arr,0,i);
		heapadjust(arr,0,i-1);
		print(arr);
	}
}
//对两个有序序列arr[left,mid]和 arr[mid+1,right]进行归并
void merge(ARR arr, int left, int mid, int right)
{
	//int i = left;
	//int j = mid+1;
	//int len = right - left +1;
	//ElementType temp[len];//数组的值要为常量
	//int k = 0;
	//while(i <= mid && j <= right)
	//{
	//	if(arr[i] > arr[j])
	//		temp[k++] = arr[j++];
	//	else
	//		temp[k++] = arr[i++];
	//}
	//while(i <= mid)
	//	temp[k++] = arr[i++];
	//while(j <= right)
	//	temp[k++] = arr[j++];
	//for(i = 0;i < len;i++)
	//	arr[i+left] = temp[i];
	//print(arr);
}

void mergesort(ARR arr,int left,int right)
{
	if(left == right)
		return;
	int mid = (left+right) / 2;
	mergesort(arr,left,mid);
	mergesort(arr,mid+1,right);
	merge(arr,left,mid,right);
}
// 非递归的归并排序

//返回枢轴的位置
int pivotkey1(ARR arr,int low,int high)
{//把数组的第一个元素作为枢轴
	//ElementType pivot = arr[low];
	ElementType pivot = getpivot(arr,low,high);
	while(low < high)
	{
		while(low<high && arr[high]>=pivot)
			high--;
		arr[low] = arr[high];
		//swap(arr,low,high);
		while(low<high && arr[low] <= pivot)
			low++;
		arr[high] = arr[low];
		//swap(arr,low,high);
	}
	arr[low] = pivot;
	print(arr);
	return low;
}

int pivotkey2(ARR arr,int low,int high)
{
	ElementType pivot = arr[low];
	//ElementType pivot = getpivot(arr,low,high);
	int i;
	int tail = low+1;
	for(i = low+1;i <= high;i++)
	{
		if(arr[i] <= pivot)
			swap(arr,i,tail++);
	}
	swap(arr,low,tail-1);
	print(arr);
	return tail-1;
}

void quicksort(ARR arr,int low,int high)
{
	if(low < high)
	{
		//pivotkey为枢轴的位置
		int pivotkey = pivotkey1(arr,low,high);
		quicksort(arr,low,pivotkey-1);//对底子表进行快速排序
		quicksort(arr,pivotkey+1,high);	//对高子表进行快速排序
	}
}

//快速排序的改进算法
ElementType getpivot(ARR arr,int low,int high)
{//三值取中法获得枢轴的值
	int mid = (low+high)/2;
	if(arr[low] > arr[high])
		swap(arr,low,high);
	if(arr[mid] > arr[high])
		swap(arr,mid,high);
	if(arr[mid] > arr[low])
		swap(arr,low,mid);
	return arr[low];
}

void Qsort(ARR arr,int low,int high)
{
	while(low < high)
	{
		int pivotkey = pivotkey1(arr,low,high);
		quicksort(arr,low,pivotkey-1);
		low = pivotkey+1;
	}
}
