#include "Heap.h"
using namespace std;


int main()
{
    setlocale(LC_CTYPE, "ukr");
    vector<int> A;
    int el, e, y, choose;
    cout << "Введiть к-сть елементiв: " << endl;
    cin >> e;
    cout << "Введiть значення елементiв: " << endl; // 16 10 14 8 7 9 3 2 4 1 maxheap
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
        cout << "1 - Побудувати пiрамiду" << endl;
        cout << "2 - Пiрамiдальне сортування" << endl;
        cout << "3 - Видалити максимальний елемент" << endl;
        cout << "4 - Змiнити значення елементу" << endl;
        cout << "5 - Додати елемент" << endl;
        cout << "6 - Показати масив" << endl;
        printf("**********************************************\n");

        cout << "Ваш вибiр: ";
        cin >> y;

        switch (y) {
        case 1:
            cout << "Оберiть: " << endl;
            cout << "1 - BuildMaxHeap (незростаюча пiрамiда)" << endl;
            cout << "2 - BuildMinHeap (неспадна пiрамiда)" << endl;
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
            cout << "Введiть номер елемента, який ви хочете змiнити: " << endl;
            int i;
            cin >> i;
            cout << "Введiть нове значення: " << endl;
            int key;
            cin >> key;
            HeapIncreaseKey(A, i, key);
            ShowArray(A);
            break;
        case 5:
            cout << "Введiть значення, яке ви хочете вставити: " << endl;
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