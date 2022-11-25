#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Parent(int i);
int Left(int i);
int Right(int i);
void MaxHeapify(vector<int>& A, int i, int heap_size); //
void BuildMaxHeap(vector<int>& A, int heap_size); //
void MinHeapify(vector <int>& A, int i, int& heap_size); //
void BuildMinHeap(vector <int>& A, int heap_size); //
void HeapSort(vector<int>& A, int heap_size); //
int HeapMax(vector<int> A); //
int HeapExtractMax(vector<int>& A, int& heap_size); //
void HeapIncreaseKey(vector<int>& A, int i, int key);
void MaxHeapInsert(vector<int>& A, int key, int& heap_size);
void ShowArray(vector<int> A);

