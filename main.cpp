#include <iostream>
#include <random>
using namespace std;

template <typename T>
T midle_arithmetic(T* arr, int size) {
	T sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum / size;
}

void fill_arr(int* arr, int size) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10);
	for (int i = 0; i < size; i++) {
		arr[i] = dis(gen);
	}
}

int main() {
	const int size = 5;
	int* arr = new int[size];
	fill_arr(arr, size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << midle_arithmetic(arr, size) << endl;
	delete[] arr;
	return 0;
}
