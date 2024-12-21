#include <iostream>
#include <random>
using namespace std;

template <typename T>
int fill_arr(T* arr, int size) {
    random_device rd;
    mt19937 gen(rd());

    if (typeid(T) == typeid(bool)) {
        uniform_int_distribution<int> bool_dist(0, 1);
        for (int i = 0; i < size; i++) {
            arr[i] = bool_dist(gen);
        }
    }
    else {
        uniform_int_distribution<int> dist(1, 50);
        for (int i = 0; i < size; i++) {
            arr[i] = dist(gen);
        }
    }
    return 0;
}

template<typename T>
void sort_arr_up(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void sort_arr_down(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void sorting(T* arr, int size, bool choice) {
    if (choice) {
        sort_arr_down(arr, size);
    }
    else {
        sort_arr_up(arr, size);
    }
}

int main() {
    int size = 10;
    int* arr = new int[size];
    fill_arr(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "True or False: ";
    bool choice;
    cin >> choice;

    sorting(arr, size, choice);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}