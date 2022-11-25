#include "Heap.h"
using namespace std;


int main()
{
    setlocale(LC_CTYPE, "ukr");
    vector<int> A;
    int el, e, y, choose;
    cout << "����i�� �-��� �������i�: " << endl;
    cin >> e;
    cout << "����i�� �������� �������i�: " << endl; // 16 10 14 8 7 9 3 2 4 1 maxheap
    for (int a = 0; a < e; a++)
    {
        cout << a + 1 << ": ";
        cin >> el;
        A.push_back(el);
    }
    int heap_size = A.size();
    int n = heap_size;
    int* B = new int[heap_size];
    for (int i = 0; i < heap_size; i++)
        B[i] = A[i];


    ShowArray(A);
    cout << endl;
    while (1)
    {
        printf("**********************************************\n");
        cout << "1 - ���������� �i���i��" << endl;
        cout << "2 - �i���i������ ����������" << endl;
        cout << "3 - �������� ������������ �������" << endl;
        cout << "4 - ��i���� �������� ��������" << endl;
        cout << "5 - ������ �������" << endl;
        cout << "6 - �������� �����" << endl;
        printf("**********************************************\n");

        cout << "��� ���i�: ";
        cin >> y;

        switch (y) {
        case 1:
            cout << "����i��: " << endl;
            cout << "1 - BuildMaxHeap (����������� �i���i��)" << endl;
            cout << "2 - BuildMinHeap (�������� �i���i��)" << endl;
            cin >> choose;
            switch (choose)
            {
            case 1:
                BuildMaxHeap(A, heap_size);
                break;
            case 2:
                BuildMinHeap(A, heap_size);
                break;
            }
            ShowArray(A);
            break;
        case 2:
            HeapSort(A, heap_size);
            ShowArray(A);
            break;
        case 3:
            B[A.size() - 1] = HeapExtractMax(A, heap_size);
            A.erase(A.end() - 1);
            for (int i = 0; i < A.size(); i++)
                B[i] = A[i];
            for (int i = 0; i < A.size(); i++)
                cout << A[i] << " ";
            cout << endl;
            break;
        case 4:
            cout << "����i�� ����� ��������, ���� �� ������ ��i����: " << endl;
            int i;
            cin >> i;
            cout << "����i�� ���� ��������: " << endl;
            int key;
            cin >> key;
            HeapIncreaseKey(A, i, key);
            ShowArray(A);
            break;
        case 5:
            cout << "����i�� ��������, ��� �� ������ ��������: " << endl;
            cin >> key;

            MaxHeapInsert(A, key, heap_size);
            ShowArray(A);
            break;
        case 6:
            ShowArray(A);
            break;
        }
    }
}