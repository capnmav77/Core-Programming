// #include<bits/stdc++.h>

// using namespace std;

// // class Quicksort{

// //     public:
// //         // Quicksort(); 
// //         // ~Quicksort();
// //         void quicksort(int *arr, int low, int high){
// //             if(low < high){
// //                 int pi = partition(arr, low, high);
// //                 quicksort(arr, low, pi-1);
// //                 quicksort(arr, pi+1, high);
// //             }
// //         }
// //         void swap(int *arr, int i, int j){
// //             int temp = arr[i];
// //             arr[i] = arr[j];
// //             arr[j] = temp;
// //         }
// //         int  partition(int *arr, int low, int high){
// //             int pivot = arr[high];
// //             int i = low-1;
// //             for(int j=low; j<high; j++){
// //                 if(arr[j] < pivot){
// //                     i++;
// //                     swap(arr, i, j);
// //                 }
// //             }
// //             swap(arr, i+1, high);
// //             return i+1;
// //         }
// //         void printArray(int *arr, int size){
// //             for(int i=0; i<size; i++){
// //                 cout << arr[i] << " ";
// //             }
// //             cout << endl;
// //         }
// // };


// class Quicksort{
//     public: 
//     // void swap(void *ptr1, void *ptr2){
//     //     auto temp = *ptr1;
//     //     *ptr1 = *ptr2;
//     //     *ptr2 = temp;
//     // }

//     int pivotvar(void *arr, int min, int max){
//         return min+(max-min)/2;
    
//     }

// void swap(void *ptr1, void *ptr2){
//    auto temp = *static_cast<int*>(ptr1);
//    *static_cast<int*>(ptr1) = *static_cast<int*>(ptr2);
//    *static_cast<int*>(ptr2) = temp;
// }

// void quicksort(void * arr , int max , int min){
//    int pivot = pivotvar(arr, min, max);
//    int *arrInt = static_cast<int*>(arr);
//    int i = min;
//    int j = max;  

//    while(i<=j){
//        while(arrInt[i]<arrInt[pivot]){
//            i++;
//        }
//        while(arrInt[j]>arrInt[pivot]){
//            j--;
//        }
//        if(i<=j){
//            swap(&arrInt[i], &arrInt[j]);
//            i++;
//            j--;
//        }
//    }

//    if(min<j){
//        quicksort(arr, min, j);
//    }
//    if(max>i){
//        quicksort(arr, i, max);
//    }
// }

        

//     void printArray(void *arr , int size){
//         static_cast<int*>(arr);
//         for(int i=0; i<size; i++){
//             cout << arr[i] << " ";
//         }
//     }
// };



// int main()
// {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     Quicksort q;

//     q.quicksort(arr, 0, n-1);
//     q.printArray(arr, n);
    
//     return 0;
// }



#include <iostream>
using namespace std;

using swap_fn = void(*)(void*, int const, int const);
using compare_fn = bool(*)(void*, int const, int const);

int partition(void* arr, int const low, int const high,
		compare_fn fcomp, swap_fn fswap)
{
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (fcomp(arr, j, high))
		{
			i++;
			fswap(arr, i, j);
		}
	}
	fswap(arr, i + 1, high);
	return i + 1;
}

void quicksort(void* arr, int const low, int const high,
			compare_fn fcomp, swap_fn fswap)
{
	if (low < high)
	{
		int const pi = partition(arr, low, high, fcomp, fswap);
		quicksort(arr, low, pi - 1, fcomp, fswap);
		quicksort(arr, pi + 1, high, fcomp, fswap);
	}
}

void swap_int(void* arr, int const i, int const j)
{
	int* iarr = (int*)arr;
	int t = iarr[i];
	iarr[i] = iarr[j];
	iarr[j] = t;
}

bool less_int(void* arr, int const i, int const j)
{
	int* iarr = (int*)arr;
	return iarr[i] <= iarr[j];
}

int main()
{
	int arr[] = { 13, 1, 8, 3, 5, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	char c_arr[] = { 'm', 'a', 'd', 'b', 'p', 'i', 'c', 'k', 'l', 'q' };
	int c_n = sizeof(c_arr) / sizeof(c_arr[0]);
	float f_a [] = {3.4, 2.5, 1.1, 4.4, 5.5, 1.57};
	// double f_a [] = {3.4, 2.5, 1.1, 4.4, 5.5, 1.57};
	int f_n = sizeof(f_a) / sizeof(f_a[0]);
	short s_a [] = {3, 2, 1, 4, 5, 1};
	// short l_a [] = {3, 2, 1, 4, 5, 1};
	int s_n = sizeof(s_a) / sizeof(s_a[0]);
	
	cout << "Quick sort an int array\n";
	quicksort(arr, 0, n - 1, less_int, swap_int);
	for (int k = 0; k < n; k ++)
		cout << arr [k] << " " ;

    cout << "\nQuick sort a char array\n";
    quicksort(c_arr, 0, c_n - 1, less_int, swap_int);
    for (int k = 0; k < c_n; k ++)
        cout << c_arr [k] << " " ;

	cout << "\nQuick sort a float array of size: " << f_n << "\n";
	quicksort(f_a, 0, f_n - 1, less_int, swap_int);
	for (int m = 0; m < f_n; m ++)
		cout << f_a [m] << " " ;

	cout << "\nQuick sort a short array of size: " << s_n << "\n";
	quicksort(s_a, 0, s_n - 1, less_int, swap_int);
	for (int m = 0; m < s_n; m ++)
		cout << s_a [m] << " " ;

}