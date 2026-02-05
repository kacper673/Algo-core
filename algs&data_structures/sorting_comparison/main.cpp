#include "sorting.h"
#include <iostream>
#include <random>

template<typename T>
T randomNum(T min, T max) {
	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<T> dist(min, max);
	return dist(rng);
}


template<typename T>
void createRandArr(T* arr, size_t size,T min, T max) {
	for (size_t i = 0; i < size; i++) {
		arr[i] =  randomNum(min, max);
	}

}

int main() {

	clearLogs();

	int vsmall = 5000;
	int small = 10000;
	int medium = 50000;
	int big = 100000;
	int vbig = 150000;

	int* ar = new int[vsmall];
	createRandArr(ar, vsmall, -1000, 1000);

	int* arr = new int[small];
	createRandArr(arr, small, -1000, 1000);

	int* arrr = new int[medium];
	createRandArr(arrr, medium, -1000, 1000);
	

	int* arrrr = new int[big];
	createRandArr(arrrr, big, -1000, 1000);

	int* arrrrr = new int[vbig];
	createRandArr(arrrrr, vbig, -1000, 1000);

	bubbleSort(ar, vsmall, true);
	bubbleSort(arr, small,true);
	bubbleSort(arrr, medium, true);
	bubbleSort(arrrr, big, true);
	bubbleSort(arrrrr, vbig, true);

	std::cout << "\n\n";

	createRandArr(ar, vsmall, -1000, 1000);
	createRandArr(arr, small, -1000, 1000);
	createRandArr(arrr, medium, -1000, 1000);
	createRandArr(arrrr, big, -1000, 1000);
	createRandArr(arrrrr, vbig, -1000, 1000);

	insertionSort(ar, vsmall, true);
	insertionSort(arr, small,true);
	insertionSort(arrr,medium , true);
	insertionSort(arrrr,big, true);
	insertionSort(arrrrr, vbig, true);


	std::cout << "\n\n";
	
	createRandArr(ar, vsmall, -1000, 1000);
	createRandArr(arr, small, -1000, 1000);
	createRandArr(arrr, medium, -1000, 1000);
	createRandArr(arrrr, big, -1000, 1000);
	createRandArr(arrrrr, vbig, -1000, 1000);

	selectionSort(ar, vsmall, true);
	selectionSort(arr, small,true);
	selectionSort(arrr, medium, true);
	selectionSort(arrrr, big, true);
	selectionSort(arrrrr, vbig, true);


	std::cout << "\n\n";
	
	createRandArr(ar, vsmall, -1000, 1000);
	createRandArr(arr, small, -1000, 1000);
	createRandArr(arrr, medium, -1000, 1000);
	createRandArr(arrrr, big, -1000, 1000);
	createRandArr(arrrrr, vbig, -1000, 1000);

	combSort(ar, vsmall, true);
	combSort(arr, small,true);
	combSort(arrr, medium, true);
	combSort(arrrr, big, true);
	combSort(arrrrr, vbig, true);

	
	std::cout << "\n\n";

	createRandArr(ar, vsmall, -1000, 1000);
	createRandArr(arr, small, -1000, 1000);
	createRandArr(arrr, medium, -1000, 1000);
	createRandArr(arrrr, big, -1000, 1000);
	createRandArr(arrrrr, vbig, -1000, 1000);

	shellSort(ar, vsmall, true);
	shellSort(arr, small,true);
	shellSort(arrr, medium, true);
	shellSort(arrrr, big, true);
	shellSort(arrrrr, vbig, true);


	delete[] ar;
	delete[] arr;
	delete[] arrr;
	delete[] arrrr;
	delete[] arrrrr;
		

	return 0;
}

