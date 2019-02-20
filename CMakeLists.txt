cmake_minimum_required(VERSION 3.13)
project(DataStructure)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructure main.cpp Test.cpp Test.h sortHelper.h sort.h mergesort.h quicksort.h binarysearch.h BST.cpp BST.h union_find.h AVLTree.cpp AVLTree.h)