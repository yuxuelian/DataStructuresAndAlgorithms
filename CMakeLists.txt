cmake_minimum_required(VERSION 3.8)
project(C_TestProject)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c tree/Tree.c tree/Tree.h sort/QuickSort.c sort/QuickSort.h
        sort/InsertionSort.c sort/InsertionSort.h TestSortHealper.c TestSortHealper.h
        BinarySearch.h sort/MergeSort.c sort/MergeSort.h sort/IterMergeSort.c sort/IterMergeSort.h
        sort/SelectionSort.c sort/SelectionSort.h sort/QuickSort3Ways.c sort/QuickSort3Ways.h
        heap/HeapSort.c heap/HeapSort.h heap/MaxHeap.c heap/MaxHeap.h heap/IndexHeap.c heap/IndexHeap.h
        tree/Tree2.cpp tree/Tree2.h sort/RadixSort.c sort/RadixSort.h
        sort/BubbleSort.c sort/BubbleSort.h link/LinkedList.c link/LinkedList.h)
add_executable(C_TestProject ${SOURCE_FILES})