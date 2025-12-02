#ifndef SORTING_H
#define SORTING_H
#include <chrono>
#include <iostream>
#include <fstream>

extern std::string filePath = "YOUR_PATH";

//bubble sort
template<typename T>
void bubbleSort(T* arr, size_t size, bool inspect = false) {
	if (size < 2) return;

	unsigned long comps = 0;
	unsigned long swaps = 0;
	std::chrono::high_resolution_clock::time_point t0 = std::chrono::high_resolution_clock::now();
	std::string path = filePath + "/bubbleSort.csv";

	for (size_t j = 0; j + 1 < size; j++) {
		for (size_t i = 1; i + 1 < size - j; i++) {
			if (arr[i - 1] > arr[i]) {
				T temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				if (inspect) {
					comps++;
					swaps++;
				}
			}
			else {
				if (inspect) comps++;
			}
		}
	}

	if (inspect) {
		auto elapsed = std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t0).count();
		std::cout << "\n---bubbleSort---\n";
		std::cout << "arr size = " << size << "\n";
		std::cout << "Comaparisons = " << comps << "\n";
		std::cout << "Swaps = " << swaps << "\n";
		std::cout << "Executuion time = " << elapsed << " ms\n";

		std::ofstream log;
		log.open(path,std::ios::app);

		if (log.is_open()) {
			log << size << "," << comps << "," << swaps << "," << elapsed << "\n";
			std::cout << "Saved " << path << "\n";
		}
		log.close();

	}

}

template<typename T>
void insertionSort(T* arr, size_t size, bool inspect = false) {
	if (size < 2) return;

	unsigned long long swaps = 0;
	unsigned long long comps = 0;

	auto t0 = std::chrono::high_resolution_clock::now();
	std::string path = filePath + "/insertionSort.csv";

	for (size_t i = 1; i < size; ++i) {
		T key = arr[i];
		size_t j = i;

		while (j > 0) {
			if (inspect) comps++;               

			if (arr[j - 1] > key) {
				arr[j] = arr[j - 1];            
				if (inspect) swaps++;
				--j;
			}
			else {
				break;
			}
		}

		arr[j] = key;                           
		if (inspect) swaps++;
	}

	if (inspect) {
		double elapsed = std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t0).count();

		std::cout << "\n---insertionSort---\n";
		std::cout << "arr size = " << size << "\n";
		std::cout << "Comparisons = " << comps << "\n";
		std::cout << "Swaps/assignments = " << swaps << "\n";
		std::cout << "Execution time = " << elapsed << " ms\n";

		std::ofstream log(path, std::ios::app);
		if (log.is_open()) {
			log << size << "," << comps << "," << swaps << "," << elapsed << "\n";
			std::cout << "Saved " << path << "\n";
		}
	}
}


template<typename T>
void selectionSort(T* arr, size_t size,bool inspect = false) {
	if (size < 2) return;

	unsigned long swaps = 0;
	unsigned long comps = 0;
	std::chrono::high_resolution_clock::time_point t0 = std::chrono::high_resolution_clock::now();

	std::string path = filePath + "/selectionSort.csv";

	for (size_t j = 0; j < size - 1; j++) {
		T min = arr[j];
		size_t idx = j;
		for (size_t i = j + 1; i < size; i++) {
			if (arr[i] < min) {
				if (inspect) comps++;
				min = arr[i];
				idx = i;
			}
			else {
				if (inspect) comps++;
			}
		}

		if (idx != j) {
			arr[idx] = arr[j];
			arr[j] = min;
			if (inspect) swaps++;
		}
		
	}

	if (inspect) {
		auto elapsed = std::chrono::duration<double,std::milli>(std::chrono::high_resolution_clock::now() - t0).count();
		std::cout << "\n---selectionSort---\n";
		std::cout << "arr size = " << size << "\n";
		std::cout << "Comaparisons = " << comps << "\n";
		std::cout << "Swaps = " << swaps << "\n";
		std::cout << "Executuion time = " << elapsed << " ms\n";

		std::ofstream log(path, std::ios::app);
		if (log.is_open()) {
			log << size << "," << comps << "," << swaps << "," << elapsed << "\n";
			std::cout << "Saved " << path << "\n";
		}
		log.close();

	}
}



template<typename T>
void combSort(T* arr, size_t size,bool inspect = false) {
	if (size < 2) return;

	unsigned long comps = 0;
	unsigned long swaps = 0;
	std::chrono::high_resolution_clock::time_point t0 = std::chrono::high_resolution_clock::now();
	std::string path = filePath + "/combSort.csv";

	bool swapped = true;

	size_t gap = size;
	while (gap != 1 || swapped == true) {

		gap = (gap * 10) / 13;
		if (gap < 1) gap = 1;

		swapped = false;
		for (size_t i = 0; i < size - gap; i++) {
			if (arr[i] > arr[i + gap]) {
				if (inspect) {
					comps++;
					swaps++;
				}

				T tmp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = tmp;
				swapped = true;
			}
			else {
				if (inspect) comps++;
			}
		}
	}

	if (inspect) {
		auto elapsed = std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t0).count();
		std::cout << "\n---combSort---\n";
		std::cout << "arr size = " << size << "\n";
		std::cout << "Comaparisons = " << comps << "\n";
		std::cout << "Swaps = " << swaps << "\n";
		std::cout << "Executuion time = " << elapsed << " ms\n";

		std::ofstream log(path, std::ios::app);
		if (log.is_open()) {
			log << size << "," << comps << "," << swaps << "," << elapsed << "\n";
			std::cout << "Saved " << path << "\n";
		}
		log.close();

	}
}


template<typename T>
void shellSort(T* arr, size_t size, bool inspect = false) {
	if (size < 2) return;

	unsigned long long comps = 0;
	unsigned long long swaps = 0;

	auto t0 = std::chrono::high_resolution_clock::now();
	std::string path = filePath + "/shellSort.csv";

	for (size_t gap = size / 2; gap > 0; gap /= 2) {
		for (size_t i = gap; i < size; ++i) {
			T temp = arr[i];
			size_t j = i;
			while (j >= gap) {
				if (inspect) comps++;             

				if (arr[j - gap] > temp) {
					arr[j] = arr[j - gap];          
					if (inspect) swaps++;
					j -= gap;
				}
				else {
					break;
				}
			}
			arr[j] = temp;                          
			if (inspect) swaps++;
		}
	}

	if (inspect) {
		double elapsed = std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t0).count();

		std::cout << "\n---shellSort---\n";
		std::cout << "arr size = " << size << "\n";
		std::cout << "Comparisons = " << comps << "\n";
		std::cout << "Swaps/assignments = " << swaps << "\n";
		std::cout << "Execution time = " << elapsed << " ms\n";

		std::ofstream log(path, std::ios::app);
		if (log.is_open()) {
			log << size << "," << comps << "," << swaps << "," << elapsed << "\n";
			std::cout << "Saved " << path << "\n";
		}
	}
}




//printing
template<typename T>
void printArr(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}


void clearLogs() {
	std::string path = filePath + "/bubbleSort.csv";
	std::ofstream log(path);
	log.close();
	path = filePath + "/insertionSort.csv";
	log.open(path);
	log.close();
	path = filePath + "/selectionSort.csv";
	log.open(path);
	log.close();
	path = filePath + "/combSort.csv";
	log.open(path);
	log.close();
	path = filePath+ "/shellSort.csv";
	log.open(path);
	log.close();
}

#endif  
