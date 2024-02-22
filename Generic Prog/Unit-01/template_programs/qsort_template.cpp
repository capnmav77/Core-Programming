#include <iostream>
using namespace std;

template <typename T>
void swap(T* a, T* b)
{
	T t = *a;
	*a = *b;
	*b = t;
}

template <typename T>
int partition(T arr[], int const low, int const high)
{
	T pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
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
	int arr[] = { 13, 1, 8, 3, 5, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	quicksort(arr, 0, n - 1);
	cout << "After sorting\n";
	for (int k = 0; k < n; k ++)
		cout << arr[k] << " ";
	return 0;

}