#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int b[100];  
void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= mid) {
        b[k++] = a[i++];
    }

    while (j <= high) {
        b[k++] = a[j++];
    }


    for (int k = low; k <= high; k++) {
        a[k] = b[k];
    }
}


void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[100], n;
    clock_t s, e;

    cout << "Enter N: ";
    cin >> n;

 
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1100;
    }

    cout << "\nThe array before sorting is: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    s = clock();
    mergesort(a, 0, n - 1); 
    e = clock();

    cout << "\nThe array after sorting is: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "The time taken is: " << (double)(e - s) / CLOCKS_PER_SEC << " seconds" << endl;
   return 0;
}

