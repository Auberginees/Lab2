#include "Heap.h"
#include <iostream>


int Parent(int i)
{
    if (i == 1) return 0;
    return i / 2;
}

int Left(int i)
{
    return 2 * i;
}

int Right(int i)
{
    return 2 * i + 1;
}

void MaxHeapify(vector<int>& A, int i, int heap_size)
{
    int l = Left(i);
    int r = Right(i);
    int largest;

    if (l <= heap_size && A[l - 1] > A[i - 1])
    {
        largest = l;
    }
    else
        largest = i;

    if (r <= heap_size && A[r - 1] > A[largest - 1])
        largest = r;
    if (largest != i)
    {
        swap(A[i - 1], A[largest - 1]);
        MaxHeapify(A, largest, heap_size);
    }
}

void BuildMaxHeap(vector<int>& A, int heap_size)
{
    for (int i = (heap_size / 2); i >= 1; i--)
        MaxHeapify(A, i, heap_size);
}

void MinHeapify(vector <int>& A, int i, int& heap_size)
{
    int l = Left(i);
    int r = Right(i);
    int smallest;
    if (l <= heap_size && A[l - 1] < A[i - 1])
    {
        smallest = l;
    }
    else
    {
        smallest = i;
    }

    if (r <= heap_size && A[r - 1] < A[smallest - 1])
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap(A[i - 1], A[smallest - 1]);
        MinHeapify(A, smallest, heap_size);
    }
}

void BuildMinHeap(vector <int>& A, int heap_size)
{
    for (int i = heap_size / 2; i >= 1; i--)
    {
        MinHeapify(A, i, heap_size);
    }
}

void HeapSort(vector<int>& A, int heap_size)
{
    setlocale(LC_CTYPE, "ukr");
    int choise;
    cout << "Choose one of the sorting options:" << endl;
    cout << "1- Сортування за зростанням (MaxHeap)" << endl;
    cout << "2- Сортування за спаданням (MinHeap)" << endl;
    cin >> choise;
    switch (choise)
    {
    case 1:
    {
        BuildMaxHeap(A, heap_size);
        for (int i = heap_size - 1; i >= 1; i--)
        {
            swap(A[0], A[i]); // тут
            heap_size--;
            MaxHeapify(A, 1, heap_size);
        }
    }break;
    case 2:
    {
        BuildMinHeap(A, heap_size);
        for (int i = heap_size - 1; i >= 1; i--)
        {
            swap(A[0], A[i]); // тут
            heap_size--;
            MinHeapify(A, 1, heap_size);
        }
    }break;

    }
}

int HeapMax(vector<int> A)
{
    return A[0];
}

int HeapExtractMax(vector<int>& A, int& heap_size)
{
    if (heap_size < 1)
    {
        cout << "Queue is empty." << endl;
        return 0;
    }
    int max = A[0];
    A[0] = A[heap_size - 1];
    heap_size--;
    MaxHeapify(A, 1, heap_size);
    return max;
}

void HeapIncreaseKey(vector<int>& A, int i, int key)
{
    if (key < A[i])
    {
        cout << "The new key is smaller than the current key." << endl;
        return;
    }
    A[i] = key;
    while (i > 0 && A[Parent(i)] < A[i])
    {

        swap(A[i], A[Parent(i)]);

        i = Parent(i);
    }
}

void MaxHeapInsert(vector<int>& A, int key, int& heap_size)
{
    heap_size++;
    A.push_back(INT_MIN);
    HeapIncreaseKey(A, heap_size - 1, key);
}


void ShowArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}