//
// Created by ZaberKo on 2019-02-04.
//

#ifndef DATASTRUCTURE_SORTHELPER_H
#define DATASTRUCTURE_SORTHELPER_H

#include <iostream>
#include <cassert>
#include <algorithm>


using namespace std;

namespace sortHelper {

    int *generateRandomAraay(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);

        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    int *generateNearlyOrderedArray(int n, int swapTime) {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int j = 0; j < swapTime; ++j) {
            int x1 = rand() % n;
            int x2 = rand() % n;
            swap(arr[x1], arr[x2]);
        }
        return arr;
    }

    void printArray(int *arr, int size) {
        for_each(arr, arr + 100,
                 [](int a) {
                     cout << a << endl;
                 });

    }

    template<typename T>
    void printArr(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1])
                return false;

        }
        return true;
    }

    template<typename T>
    void testSort(T arr[], int n, void(*sort)(T[], int)) {
        clock_t start = clock();
        sort(arr, n);
        clock_t end = clock();
        assert(isSorted(arr, n));
        cout << "it take " << double(end - start) / CLOCKS_PER_SEC << " s." << endl;
    }

    template<typename T>
    T *copyArr(T arr[], int n) {
        int *arr_new = new int[n];
        copy(arr, arr + n, arr_new);
        return arr_new;
    }


}

#endif //DATASTRUCTURE_SORTHELPER_H
