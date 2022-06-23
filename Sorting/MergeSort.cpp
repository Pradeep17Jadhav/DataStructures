#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end) {
    int i, j;
    vector<int> arrNew;
    i = start;
    j = mid+1;

    //traverse both parts and keep adding smaller element in new array
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            arrNew.push_back(arr[i++]);
        }
        else {
            arrNew.push_back(arr[j++]);
        }
    }

    //once one of the part is exhausted, we will have to add remaining elements of other part to the array
    while(i <= mid) {
        arrNew.push_back(arr[i++]);
    }

    while(j <= end) {
        arrNew.push_back(arr[j++]);
    }

    //copy back the sorted array to original array
    for(i = start; i <= end; i++)
        arr[i] = arrNew[i - start];
}

void mergeSort(vector<int> &arr, int start, int end) {
    if(start >= end)
        return;
    
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    for(int &i: arr)
        cout << i << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size()-1);

    for(int &i: arr)
        cout << i << " ";

    return 0;
}