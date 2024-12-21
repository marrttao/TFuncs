#include <iostream>
#include <random>
using namespace std;

template <typename T>
void countElements (T arr[], int size, int& negativeCount, int& zeroCount) {
    negativeCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            negativeCount++;
        }
        else if (arr[i] == 0) {
            zeroCount++;
        }
    }
}

void fill_arr(int* arr, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-5, 0);
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
}

int main() {
    const int size = 10;
    int* arr = new int[size];
    int negativeCount, zeroCount;
    fill_arr(arr, size);
    countElements(arr, size, negativeCount, zeroCount);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

    cout << "Negative elements: " << negativeCount << endl;
    cout << "Zero elements: " << zeroCount << endl;

    delete[] arr;
    return 0;
}
