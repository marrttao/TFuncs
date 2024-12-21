#include <iostream>
#include <random>
using namespace std;


template <typename T>
void fill_array(T* arr, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-20, 20);
    for (int i = 0; i < size; i++) {
        arr[i] = dist(gen);
    }
}


template <typename T>
void find_negative_positions(T* arr, int size, int& left_index, int& right_index) {
    left_index = -1;
    right_index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            if (left_index == -1) {
                left_index = i;
            }
            right_index = i;
        }
    }
}

template <typename T>
void sort_arr(T* arr, int left_index, int right_index) {
	for (int i = left_index; i < right_index; i++) {
		for (int j = i + 1; j <= right_index; j++) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}

int main() {
    const int size = 20;
    int arr[size];

    fill_array(arr, size);

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int left_index, right_index;
    find_negative_positions(arr, size, left_index, right_index);
    cout << "left negative index: " << left_index << endl;
    cout << "right negative index: " << right_index << endl;

    sort_arr(arr, left_index, right_index);

    cout << "sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
