/*Sorting.cpp
   Author: Chris Callahan and Johnathan Kulovitz
   Submission  Date:  4/23/2017
  Purpose:  This is the tester for sorting algorithms
  References are located in the project report.
  Statement  of Academic  Honesty:The  following  code  represents  my  own  w\
   ork.  I  have  neitherreceived  nor  given  inappropriate assistance. I have\
    not copiedor  modified code from any source other than the course webpageor\
    the course textbook. I recognize that any unauthorizedassistance or plagiar\
   ism will be handled in accordance  withthe  University  of  Georgia's  Acade\
   mic  Honesty  Policy  and  thepolicies  of  this course.  I  recognize  that\
     my  work  is  basedon  an  assignment  created  by  the  Department  of Co\
   mputerScience at the University of Georgia. Any publishingor posting of sour\
   ce code for this project  is strictlyprohibited  unless  you  have written c\
   onsent  from  the  Departmentof Computer Science  at the  University  of  Ge\
   orgia.*/

#include "Sorting.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
  ifstream inFile;
  ofstream outFile;
  string inFileName;
  //string outFileName;
  string sortType;
  int numElements;
  int element;
  long count = 0; // number of comparisons
  
  /* Gather user input */
  cout << "Enter a file for input & press return: ";
  cin >> inFileName;
  inFile.open(inFileName.c_str());

  //inFile.open("random.dat");
  
  //cout << "Enter a file to store results & press return: ";
  //outFile.open(outFileName.c_str());
  //outFile >> outFileName;
  

  cout << "Enter the number of elements you wish to sort & press return: ";
  cin >> numElements;

  cout << "Enter your desired sorting algorithm & press return.";
  cout << "Options: " << endl;
  cout << "1) Selection\n2) Bubble\n3) Insertion\n4) Merge\n5) Quick\n6) Heap\n";
  cout << ": ";
  cin >> sortType;
  
  /* crate array from file elements */
  int * data = new int [numElements];
  
  for(int i = 0; i < numElements; i++)
  {
    inFile >> element;
    data[i] = element;
  }
  
  Sorting* sortData = new Sorting(data);

  if(sortType == "Selection")
  {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    count = sortData->SelectionSort(numElements);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2-t1).count();
    cout << "Sorted data: " << endl;
    sortData->printData(numElements);
    cout << "Compare count: " << count << endl;
    cout << "Time: " << duration << " microseconds" << endl;
  }
  else if(sortType == "Bubble")
  {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    count = sortData->BubbleSort(numElements);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2-t1).count();
    cout << "Sorted data: " << endl;
    sortData->printData(numElements);
    cout << "Compare count: " << count << endl;
    cout << "Time: " << duration << " microseconds" << endl;
  }
  else if(sortType == "Insertion")
  {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    count = sortData->InsertionSort(numElements);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2-t1).count();
    cout << "Sorted data: " << endl;
    sortData->printData(numElements);
    cout << "Compare count: " << count << endl;
    cout << "Time: " << duration << " microseconds" << endl;
  }
  else if(sortType == "Merge")
  {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    sortData->MergeSort(0, numElements-1, count);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2-t1).count();
    cout << "Sorted data: " << endl;
    sortData->printData(numElements);
    cout << "Compare count: " << count << endl;
    cout << "Time: " << duration << " microseconds" << endl;
  }
  else if(sortType == "Quick")
  {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    sortData->QuickSort(0, numElements-1, count);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2-t1).count();
    cout << "Sorted data: " << endl;
    sortData->printData(numElements);
    cout << "Compare count: " << count << endl;
    cout << "Time: " << duration << " microseconds" << endl;
  }
  else if(sortType == "Heap")
  {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    sortData->HeapSort(numElements, count);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2-t1).count();
    cout << "Sorted data: " << endl;
    sortData->printData(numElements);
    cout << "Compare count: " << count << endl;
    cout << "Time: " << duration << " microseconds" << endl;
  }
  else 
  {
    cout << "Error: You entered an invalid sorting algorithm.";
  }
   
}
