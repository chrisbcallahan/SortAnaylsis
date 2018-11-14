#ifndef SORTING_H
#define SORTING_H

class Sorting
{
 private:
  int* data;

 public:
  Sorting(int* data); //constructor
  long SelectionSort(int size);
  long BubbleSort(int size);
  long InsertionSort(int size);
  void MergeSort(int low, int high, long & count);
  void QuickSort(int left, int right, long & count);
  void HeapSort(int n, long& count);
  void printData(int size);

};

#endif
