#include <iostream>
#include <random>
using namespace std;

template <typename T>
void fill_arr(T* arr, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 50);

    for (int i = 0; i < size; i++) {
        arr[i] = dist(gen);
    }
}

template <typename T>
void insertionSort(T* arr, int size) {
    for (int i = 1; i < size / 2; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    for (int i = size / 2; i < size; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= size / 2 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int size = 10;
    int* arr = new int[size];
    fill_arr(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
