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
		if (arr[j] < pivot) // can be fixed by changing the condition to *arr[j] < *pivot
		{
			i++;
            cout<<"i = "<<arr[i]<<" j = "<<arr[j]<<endl;
			swap(&arr[i], &arr[j]);
            cout<<"i = "<<arr[i]<<" j = "<<arr[j]<<endl;
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
    char chararr[] = {'a','b','c','d','e','f','g'};
    int charn = sizeof(chararr) / sizeof(chararr[0]);
    double doublearr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int doublen = sizeof(doublearr) / sizeof(doublearr[0]);

    const char *a3 = "ghi";
    const char *a5 = "ano";
    const char *a1 = "abc";
    const char *a2 = "def";
    const char *a4 = "jkl";
    

    const char *s_arr [] = {a1, a2, a3, a4, a5};
    int s_n = sizeof(s_arr) / sizeof(s_arr[0]);
	
	// quicksort(arr, 0, n - 1);
	// cout << "After sorting\n";
	// for (int k = 0; k < n; k ++)
	// 	cout << arr[k] << " ";
    // cout << endl;
    // quicksort(chararr, 0, charn - 1);
    // cout << "chararray\n";
    // for (int k = 0; k < charn; k ++)
    //     cout << chararr[k] << " ";
    // cout << endl;
    // cout<<"Double array"<<endl;
    // quicksort(doublearr, 0, doublen - 1);
    // for(int i=0 ; i<doublen ; i++)
    //     cout<<doublearr[i]<<" ";
    // cout<<endl;
    cout<<"String array"<<endl;
    quicksort(s_arr, 0, s_n - 1);
    for(int i=0 ; i<s_n ; i++)
        cout<<s_arr[i]<<" ";    // it is therfore clear that the template is sorting the array of pointers based on the address of the pointers and not the value of the pointers.
    cout<<endl;
	return 0;

}