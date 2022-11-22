#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED
class Array {
public:
    Array();
    ~Array();
    Array(int);
    void InsertionSort();
    void BubbleSort();
    void SelectionSort();
    void Merge(int, int, int);
    void MergeSort(int, int);
    void swapNums(int, int);
    void max_heapify(int n, int i);
    void ascendingHeapSort();
    void buildMaxHeap();
    void insert_value_maxHeap(int val);
    void CS(int);
    void RCS(int, int);
    void RS(int);
    void HeapSort();
    void Display();
private:
    int* a;
};
#endif // SORTS_H_INCLUDED