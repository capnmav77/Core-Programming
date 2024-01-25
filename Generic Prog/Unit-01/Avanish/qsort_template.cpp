#include <iostream>
using namespace std;

template <typename T>
void swap(T* a, T* b)
{
	cout<<"Swap between "<<*a<<" "<<*b<<endl;
	T t = *a;
	*a = *b;
	*b = t;
}

template <typename T>
int partition(T arr[], int const low, int const high)
{
	T pivot = arr[high];
	cout<<"Pivot = "<<pivot<<endl;
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (*arr[j] < *pivot)
		{
			i++;
			cout<<"Here swap is called "<<arr[j]<<" "<<pivot<<endl;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

template <typename T>
void quicksort(T arr[], int const low, int const high)
{
	if (low < high)
	{
		int const pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

int main()
{

	char *s1 = "abc\0";
	char *s2 = "bbc\0";
	char *s3 = "bac\0";
	char *s4 = "acc\0";

	char* sr[]={s1,s3,s4,s2};


	quicksort(sr,0,3);
	cout<<endl;
	for(int i=0;i<4;++i)
	printf("%s ",sr[i]);

	return 0;

}