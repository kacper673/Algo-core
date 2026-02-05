#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue {
private:
	int* tab;
	int* time_quant;
	int capacity;
	int front;
	int back;

	//for Round Robin
	struct ValWithTime {
		int x;
		int t;
		ValWithTime() = default;
		ValWithTime(int x_, int t_) : x(x_), t(t_) {};
	};

public:
	Queue(int capacity_): capacity(capacity_) {
		tab = new int[capacity];
		time_quant = new int[capacity];
		front = -1;
		back = -1;
	}

	~Queue() {
		delete[] tab;
		delete[] time_quant;
	}

	bool isFull() {
		if (back == capacity - 1) return true;
		return false;
	}
	bool isEmpty() {
		if (front == -1) return true;
		return false;
	}
	void add(int x) {
		if (isFull()) return;

		if (isEmpty()) {
			back++;
			front = 0;
			tab[front] = x;	
		}
		else {
			back++;
			tab[back] = x;
		}
		
	}

	int remove() {
		if (isEmpty()) return NULL;

		int temp = tab[front];
		if (front == back) {
			front = back = -1;
			return temp;
		}
		front++;
		return temp;
	}

	void printQueue() {
		if (isEmpty()) {
			std::cout << "Queue is empty";
			return;
		}
		for (int i = front; i <= back; i++) {
			std::cout << tab[i] << " ";
		}
	}

	//neccessary to simulate RoundRobin - adding value and time count assigned to value;
	void addWithTime(int x,int t) {
		if (isFull()) return;

		if (isEmpty()) {
			back++;
			front = 0;
			tab[front] = x;
			time_quant[front] = t;
		}
		else {
			back++;
			tab[back] = x;
			time_quant[back] = t;
		}
	}

	ValWithTime removeWithTime() {
		if (isEmpty()) std::abort();

		ValWithTime temp(tab[front], time_quant[front]);
		if (front == back) {
			front = -1;
			back = -1;
			return temp;
		}
		front++;
		return temp;
	}

	void moveToBack() {
		if (isEmpty() || isFull()) return;
		back++;
		tab[back] = tab[front];
		time_quant[back] = time_quant[front];
		front++;
	}

	void RoundRobinSimulation(int T) {
		std::cout << "\n\n---Round Robin simulation---\n\n";
		std::cout << "Time threshold = " << T << "\n\n";
		std::cout << "Processe's queue : "; printQueue(); std::cout << "\n\n";
		std::cout << "-----------------------------\n\n";
		
		while (!isEmpty()) {
			for (int i = 0; i <= T; i++) {
				std::cout << "Process id " << tab[front] << "\n"; //tab[front] is a running proccess id
				std::cout << "Proces time quant " << time_quant[front] << "\n"; //remaining time quant for that process
				std::cout << "Remaining time aveilable " << T - i<<"\n";
				if (time_quant[front] == 0) {
					removeWithTime();
					std::cout << "Procesed (id: "<<tab[front]<< " ) finalized\n";
					std::cout << "Remaining processes "; printQueue(); std::cout << "\n\n";
					break;
				}
				time_quant[front] -= 1;
			}
			moveToBack();
			std::cout << "Proces " << tab[front] << " exeeded available time. Moved to back of the queue\n";
			std::cout << "Current Queue state: "; printQueue(); std::cout << "\n\n";
		}
	}

	void sortAsc() {
		if (isEmpty()) return;
		for (int i = front; i < back; ++i) {
			for (int j = front; j < back - (i - front); ++j) {
				if (tab[j] > tab[j + 1]) {
					int tmp = tab[j]; tab[j] = tab[j + 1]; tab[j + 1] = tmp;
				}
			}
		}
	}

	void sortDesc() {
		if (isEmpty()) return;
		for (int i = front; i < back; ++i) {
			for (int j = front; j < back - (i - front); ++j) {
				if (tab[j] < tab[j + 1]) {
					int tmp = tab[j]; tab[j] = tab[j + 1]; tab[j + 1] = tmp;
				}
			}
		}
	}

};

struct PriorityValue {
	int val;
	int prio;
	bool priority;
	PriorityValue() = default;
	PriorityValue(int val_,int  prio_) : val(val_), prio(prio_), priority(true) {};
	PriorityValue(int val_) : val(val_),priority(false) {};
};

class PriorityQueue {
private:
	PriorityValue* tab;
	int capacity;
	int front;
	int back;
public:
	PriorityQueue(int capacity_) : capacity(capacity_) {
		tab = new PriorityValue[capacity];
		front = -1;
		back = -1;
	}

	~PriorityQueue() {
		delete[] tab;
	}

	bool isFull() {
		if (back == capacity - 1) return true;
		return false;
	}
	bool isEmpty() {
		if (front == -1) return true;
		return false;
	}
	void add(PriorityValue pr_val) {
		if (isFull()) return;

		if (isEmpty()) {
			back++;
			front = 0;
			back = 0;
			tab[front] = pr_val;
			sortByPriority();
		}
		else {
			back++;
			tab[back] = pr_val;
			sortByPriority();
		}

	}

	void sortByPriority() {
		for (int i = front; i < back; i++) {
			for (int j = front; j < back - (i - front); j++) {
				const bool aNo = !tab[j].priority;
				const bool bNo = !tab[j + 1].priority;
				if ((aNo && !bNo) || (!aNo && !bNo && tab[j].prio > tab[j + 1].prio)) {
					PriorityValue temp = tab[j];
					tab[j] = tab[j + 1];
					tab[j + 1] = temp;
				}
			}
		}
	}

	int remove() {
		if (isEmpty()) std::abort();

		int temp = tab[front].val;
		if (front == back) {
			front = back = -1;
			return temp;
		}
		else {
			front++;
		}
		return temp;
	}

	int removeFromBack() {
		if (isEmpty()) std::abort();
		
		int temp = tab[back].val;

		if (front == back) {
			front = back = -1;
			return temp;
		}
		else {
			back--;
		}
		return temp;
	}

	void printQueue() {
		if (isEmpty()) {
			std::cout << "Queue is empty";
			return;
		}
		for (int i = front; i <= back; i++) {
			std::cout << "Value " << tab[i].val;
			if (tab[i].priority) {
				std::cout << " Priority " << tab[i].prio << "\n";
			}
			else {
				std::cout << "\n";
			}
		}

	}

};

#endif 

