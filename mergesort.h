//
// Created by ZaberKo on 2019-02-10.
//

#ifndef DATASTRUCTURE_MERGESORT_H
#define DATASTRUCTURE_MERGESORT_H

template <typename T>
void insertionSort(T arr[],int l ,int r)
{
    for (int i = l+1; i <=r ; ++i) {
        T t=arr[i];
        int j;
        for (j = i; j >0&&arr[j-1]>t ; --j) {
            arr[j]=arr[j-1];
        }
        arr[j]=t;
    }
}

template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T aux[r - l + 1];

    for (int i = l; i <= r; ++i)
        aux[i - l] = arr[i];

    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }


}

//sort arr[l...r]
template<typename T>
void __mergeSort(T arr[], int l, int r) {

//    if (l >= r)
//        return;

    if(l-r+1<=15){
        insertionSort(arr,l,r);
        return;
    }


    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);

//    __merge(arr, l, mid, r);
    if(arr[mid]>arr[mid+1])
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {

    __mergeSort(arr, 0, n - 1);
}



//button-to-up version
template <typename T>
void mergeSortBU(T arr[],int n){
    for (int sz = 1; sz <=n ; sz<<=1) {

        for (int i = 0; i+sz < n; i+=sz<<1) {
            __merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));
        }
    }
}


#endif //DATASTRUCTURE_MERGESORT_H
