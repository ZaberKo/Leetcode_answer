#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include "sortHelper.h"
#include "sort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "BST.h"
#include "AVLTree.h"



using namespace sortHelper;





//int main() {
//    int n = 10000;
//    int *arr1 = generateRandomAraay(n, 0, n);
////    int *arr1 = generateNearlyOrderedArray(n, 10);
//    int *arr = copyArr(arr1, n);
//    int *arr2 = copyArr(arr1, n);
//    int *arr3 = copyArr(arr1, n);
//    int *arr4 = copyArr(arr1, n);
//    int *arr5 = copyArr(arr1, n);
//
////    testSort(arr1, n, selectionSort);
////    testSort(arr2, n, insertionSort);
////    testSort(arr3, n, insertionSort3);
////    testSort(arr4, n, bubbleSort2);
////    testSort(arr5, n, mergeSort);
//    testSort(arr, n, quickSort3Ways);
//
////    printArr(arr, n);
////    insertionSort(arr,0,n-1);
////    mergeSortBU(arr, n);
////    bubbleSort2(arr, n);
////    quicksort2(arr,n);
////    printArr(arr, n);
//
//}
template <typename T>
void printVec(const vector<T> &vec);

void testR(BST<int,int> &bst,int t){
    vector<int> vec;
    bst.LevelOrder(vec);
    printVec(vec);
    bst.Remove(t);
    vec.clear();
}

int main(){
    array<int,5> arr={3,1,5,2,4};
    BST<int,int> bst;
    for(auto i:arr){
        bst.Insert(i,i);
    }


    cout<<"size: "<<bst.Size()<<endl;
    cout<<bst.Contain(10)<<endl;
    cout<<bst.Contain(2)<<endl;
    int* max=bst.GetMax();
    int* min=bst.GetMin();
    cout<<"max: "<<(max?*max:-1)<<endl;
    cout<<"min: "<<(min?*min:-1)<<endl;

//    vector<int> vec1,vec2,vec3;
//    bst.PreOrder(vec1);
//    bst.InOrder(vec2);
//    bst.PostOrder(vec3);
//
//    cout<<"pre: ";
//    for(int i :vec1)
//        cout<<i<<" ";
//    cout<<endl;
//
//    cout<<"in: ";
//    for(int i :vec2)
//        cout<<i<<" ";
//    cout<<endl;
//
//    cout<<"post: ";
//    for(int i :vec3)
//        cout<<i<<" ";
//    cout<<endl;
    testR(bst,5);
    testR(bst,3);
}

template <typename T>
void printVec(const vector<T> &vec){
    cout<<"vec: ";
    for(int i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
}






