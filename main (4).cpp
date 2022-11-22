#include <iostream>
#include"Sorts.h.h"
#define MAXSIZE 10
using namespace std;

int main()
{
Array Insert;
Array Selection;
Array Bubble;
Array M;
Array Heap;
Array C;
Array R;
Insert.InsertionSort();
Insert.Display();

Selection.SelectionSort();
Selection.Display();

Bubble.BubbleSort();
Bubble.Display();

M.MergeSort(0,MAXSIZE-1);
M.Display();

Heap.buildMaxHeap();
Heap.ascendingHeapSort();
Heap.Display();

C.CS(MAXSIZE);
C.Display();

R.RS(MAXSIZE);
R.Display();

    return 0;
}
