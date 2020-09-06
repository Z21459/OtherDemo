#include<iostream>
using namespace std;
#define N 10

int main () {
	int buf[N+1] ,tmp[N],i,j;
	for (i = 0; i <= N; i++)
	{
		cin >> buf[i];
		tmp[buf[i]]++;
	}
	for (j = 0; j < N; j++)
	{
		if (tmp[j] > 1){
			cout << j << endl;
}
	}
	return 0;
}

