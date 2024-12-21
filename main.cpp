#include <iostream>
#include <random>
using namespace std;

template <typename T>
void fill_arr (T arr[], int size) {
	random_device rd;
	mt19937 gen(rd());

	if (typeid(T) == typeid(float))
		uniform_real_distribution<float> dis(0, 100);
	else if (typeid(T) == typeid(double))
		uniform_real_distribution<double> dis(1.0, 100.0);
	else
		uniform_int_distribution<int> dis(0, 100);
	
	for (int i = 0; i < size; i++) {
		arr[i] = dis(gen);
	}
}

template <typename T>
int

int main() {

	return 0;
}