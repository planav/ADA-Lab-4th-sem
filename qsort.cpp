#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define max 500

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;

  
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] < pivot) {
            count++;
        }
    }

   
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex) {
       
        while (arr[i] < pivot) {
            i++;
        }

       
        while (arr[j] > pivot) {
            j--;
        }

        
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void qsort(int arr[], int s, int e) {
    if (s >= e) {
        return;
    }

    int p = partition(arr, s, e);
    qsort(arr, s, p - 1);
    qsort(arr, p + 1, e);
}

int main() {
    int a[max], n;
    clock_t s, e;

    cout << "Enter the Value of N: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    cout << "\nThe array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    s = clock();
    qsort(a, 0, n - 1);
    e = clock();

    cout << "\nElements of array after sorting are: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << "\nTime taken: " << double(e - s) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}
















