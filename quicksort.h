//
// Created by ZaberKo on 2019-02-11.
//

#ifndef DATASTRUCTURE_QUICKSORT_H
#define DATASTRUCTURE_QUICKSORT_H




//worst case: => O(n^2)
//1. ordered array
//2. many repeated number


//use random index to solve worst case




//for arr[l...r]
//let arr[l...p-1]<arr[p] & arr[p+1...r]>arr[p]
template<typename T>
int __partition(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);

    T t = arr[l];

    // arr[l+1...j] < v ; arr[j+1...i) > v
    int j = l;
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] < t) {
//            swap(arr[j+1],arr[i]);
//            j++;
            swap(arr[++j], arr[i]);

        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
void __quicksort(T arr[], int l, int r) {
    if (l >= r)
        return;

    int p = __partition(arr, l, r);
    __quicksort(arr, l, p - 1);
    __quicksort(arr, p + 1, r);
}


template<typename T>
void quicksort(T arr[], int n) {
    srand(time(NULL));
    __quicksort(arr, 0, n - 1);
}



//2-way quick sort
template<typename T>
int __partition2(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);

    T t = arr[l];

    // arr[l+1...j] <= v ; arr[j+1...i) >= v
    int i = l + 1, j = r;
    while (true) {
        while (i <= r && arr[i] < t) i++; // now arr[i]>=t
        while (j >= l + 1 && arr[j] > t) j--;

        if (i >= j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;

    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
void __quicksort2(T arr[], int l, int r) {
    if (l >= r)
        return;

    int p = __partition2(arr, l, r);
    __quicksort2(arr, l, p - 1);
    __quicksort2(arr, p + 1, r);
}


template<typename T>
void quicksort2(T arr[], int n) {
    srand(time(NULL));
    __quicksort2(arr, 0, n - 1);
}


//3-ways quick sort

//     <v     =v      un    >v
// -|------|-------|------|-------|
// l     lt         i      gt     r

template <typename T>
void __quickSort3Ways(T arr[], int l, int r){

    // 对于小规模数组, 使用插入排序进行优化
    if( r - l <= 15 ){
        insertionSort(arr,l,r);
        return;
    }



    // ------partition part------
    // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
    swap( arr[l], arr[rand()%(r-l+1)+l ] );

    T v = arr[l];

    int lt = l;     // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v
    int i = l+1;    // arr[lt+1...i) == v
    while( i < gt ){
        if( arr[i] < v ){
            swap( arr[i], arr[lt+1]);
            i ++;
            lt ++;
        }
        else if( arr[i] > v ){
            swap( arr[i], arr[gt-1]);
            //i does not need +1
            gt --;
        }
        else{ // arr[i] == v
            i ++;
        }
    }
    //---------------------------

    //put pivot at the the first place of [=V] range
    swap( arr[l] , arr[lt] );

    __quickSort3Ways(arr, l, lt-1);
    __quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n){

    srand(time(NULL));
    __quickSort3Ways( arr, 0, n-1);
}

#endif //DATASTRUCTURE_QUICKSORT_H
