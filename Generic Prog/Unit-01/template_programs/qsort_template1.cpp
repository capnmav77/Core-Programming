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
	char c_arr[] = {'z', 'b', 'e', 'f', 'n'};
	int c_n = sizeof(c_arr) / sizeof(c_arr[0]);
	double d_arr[] = {1.234, 2.314, 1.117, 2.112, 3.456};
	int d_n = sizeof(d_arr) / sizeof(d_arr[0]);
	const char *s_arr [] = {"abc", "bac", "acc", "bbc"};
	int s_n = 4;

	quicksort(arr, 0, n - 1);
	cout << "After sorting\n";
	for (int k = 0; k < n; k ++)
		cout << arr[k] << " ";

	cout << "\n";
	cout << "After char arr sorting\n";
	quicksort(c_arr, 0, c_n - 1);
	for (int k = 0; k < c_n; k ++)
		cout << c_arr[k] << " ";

	cout << "\n";
	cout << "After double arr sorting\n";
	quicksort(d_arr, 0, d_n - 1);
	for (int k = 0; k < d_n; k ++)
		cout << d_arr[k] << " ";

	cout << "\n";
	cout << "After string arr sorting\n";
	quicksort(s_arr, 0, 4 - 1);
	for (int k = 0; k < 4; k ++)
		cout << s_arr[k] << " ";

}


