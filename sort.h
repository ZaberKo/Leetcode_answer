//
// Created by ZaberKo on 2019-02-07.
//

#ifndef DATASTRUCTURE_SORT_H
#define DATASTRUCTURE_SORT_H

#include <iostream>



using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;

        }
        swap(arr[i], arr[minIdx]);
    }
}

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

//use assignment rather than swap(3*assignment)
//better
template<typename T>
void insertionSort2(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T t = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > t; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = t;
    }
}





template<typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


template<typename T>
void bubbleSort2(T arr[], int n) {
    int flagIdx = n - 2;
    int tmp;
    while (flagIdx > 0) {
        tmp = 0;
        for (int i = 0; i <= flagIdx; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                tmp = i;
            }
        }
        flagIdx = tmp;
    }
}

#endif





