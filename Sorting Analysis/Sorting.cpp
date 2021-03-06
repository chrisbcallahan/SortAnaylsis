/*Sorting.cpp
 Author: Chris Callahan and Johnathan Kulovitz
 Submission  Date:  4/23/2017
Purpose:  This provides the implementation of different sorting algorthims.
References are located in the project report.
Statement  of Academic  Honesty:The  following  code  represents  my  own  work.  I  have  neitherreceived  nor  given  inappropriate assistance. I have not copiedor  modified code from any source other than the course webpageor the course textbook. I recognize that any unauthorizedassistance or plagiarism will be handled in accordance  withthe  University  of  Georgia's  Academic  Honesty  Policy  and  thepolicies  of  this course.  I  recognize  that  my  work  is  basedon  an  assignment  created  by  the  Department  of ComputerScience at the University of Georgia. Any publishingor posting of source code for this project  is strictlyprohibited  unless  you  have written consent  from  the  Departmentof Computer Science  at the  University  of  Georgia.*/
#include "Sorting.h"
#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;

Sorting::Sorting(int* data)
{
  this->data = data;
}

long Sorting::SelectionSort(int size)
{
  int min;
  long count = 0;
  for(int i = 0; i < size-1; i++)
  {
    min = i;
    //loop through array to find the min
    for(int j = i+1; j < size; j++)
    {
      count++;
      if(data[j] < data[min])
      {
	  //new min location
	  min = j;
      }
    }
    // swap
    swap(data[i], data[min]);
  }
  return count;
}

long Sorting::BubbleSort(int size)
{
  int already = 0;
  long count = 1;
  bool b = false;
  for(int i = size-1; i > 0 && !b; i--)
  {
    b = true;
    int j;
    for(j = size-1; j > already; j--)
    {
      count++;
      if(data[j] < data[j-1])
      {
	b = false;
	int temp = data[j-1];
	data[j-1] = data[j];
	data[j] = temp;
      }
    }
    already++;
  }
  return count;
}

long Sorting::InsertionSort(int size)
{
  long count = 1;
  int i, key, j;
  for(i = 1; i < size; i++)
  {
    key = data[i];
    j = i-1;
    
    /* Move elemnts of data[0...i-1], that 
       are greater than key to one position 
       ahead of their current position */
    count++;
    while(j >= 0 && data[j] > key)
    {
      count++;
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = key;
  }
  return count;
}

void merge(int * data, int low, int high, int mid, long & count);

void Sorting::MergeSort(int low, int high, long & count)
{
  int mid;
  if(low < high)
  {
    mid = (low+high)/2;
    MergeSort(low, mid, count);
    MergeSort(mid+1, high, count);
    merge(data, low, high, mid, count);
  }
}

void merge(int * data, int low, int high, int mid, long & count)
{
  int i, j, k, c[200000];
  i = low;
  k = low;
  j = mid+1;
  
  while(i <= mid && j <= high)
  {
    if(data[i] < data[j])
    {
      c[k] = data[i];
      k++;
      i++;
      count++;
    }
    else 
    {
      c[k] = data[j];
      k++;
      j++;
      count++;
    }
  }
  while(i <= mid)
  {
    c[k] = data[i];
    k++;
    i++;
  }
  while(j <= high)
  {
    c[k] = data[j];
    k++;
    j++;
  }
  for(i = low; i < k; i++)
  {
    data[i] = c[i];
  }
}

void Sorting::QuickSort(int left, int right, long & count)
{
  int i = left;
  int j = right;
  int temp;
  int pivot = data[(left+right) / 2];

  /*partition*/
  while(i <= j)
  {
    count++;
    while(data[i] < pivot)
    {
      i++;
      count++;
    }
    count++;
    while(data[j] > pivot)
    {  
      j--;
      count++;
    }
    if(i <= j)
    {
      temp = data[i];
      data[i] = data[j];
      data[j] = temp;
      i++;
      j--;
    }
  }
  
  if(left < j)
    QuickSort(left, j, count);
  if(i < right)
    QuickSort(i, right, count);
}

void heapify(int * data, int n, int i, long & count);

void Sorting::HeapSort(int n, long & count)
{
  // Build heap (rearrange array)
  for(int i = n / 2 - 1; i >=0; i--)
    heapify(data, n, i, count);

  // extract elements one by one from array
  for(int i = n-1; i>=0; i--)
  {
    // move current root to end
    swap(data[0], data[i]);

    // call max heapify on the reduced heap
    heapify(data, i, 0, count);
  }
}

void heapify(int * data, int n, int i, long & count)
{
  int largest = i; //largest is the root
  int l = 2*i + 1; //left
  int r = 2*i + 2; //right

  // if left child is larger than root
  if(l < n)
  {
    count++;
    if(data[l] > data[largest])
       largest = l;
  }
  // if right child is larger than largest so far
  if(r < n)
  { 
    count++;
    if(data[r] > data[largest])
      largest = r;
  }
  // if largest is not root
  if(largest != i)
  {
    swap(data[i], data[largest]);

    // recursively heapify the affected sub-tree
    heapify(data, n, largest, count);
  }
}

void Sorting::printData(int size)
{
  for(int i = 0; i < size; i++)
    cout << data[i] << endl;
} 
