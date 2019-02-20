//
// Created by ZaberKo on 2019-02-11.
//

#ifndef DATASTRUCTURE_BINARYSEARCH_H
#define DATASTRUCTURE_BINARYSEARCH_H

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        //may cause overflow
        //int mid = (l + r) / 2;

        int mid=l+(r-l)/2;
        if (arr[mid] == target)
            return mid;

        if (target < arr[mid])
            r=mid-1;

        else //target < arr[mid]
            l=mid+1;
    }
    return -1;
}

#endif //DATASTRUCTURE_BINARYSEARCH_H
