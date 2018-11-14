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
  ofstream outfile;
  string inFileName;
  int element;
  int time;
  int count = 0;

  cout << "enter file: ";
  cin >> inFileName;
  
  int t1[10];
  int t2[100];
  int t3[500];
  int t4[1000];
  int t5[10000];
  int t6[20000];
  int t7[100000];
  int t8[200000];
  
  inFile.open(inFileName.c_str());
  
  for(int i = 0; i < 10; i++)
    {
      inFile >> element;
      t1[i] = element;
    }
  
  inFile.close();
  
  Sorting* s1 = new Sorting(t1);
  
  high_resolution_clock::time_point a = high_resolution_clock::now();
  count = s1->SelectionSort(10);
  high_resolution_clock::time_point b = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(b-a).count();
  cout << ":::: " << duration << endl;

  inFile.open(inFileName.c_str());
}
