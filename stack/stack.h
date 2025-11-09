#ifndef STACK_H
#define STACK_H
#include <iostream>
constexpr int MAX = 100;

class Stack {
public:
	
	explicit Stack(size_t capacity)
		: base_(nullptr), top_(nullptr), end_(nullptr)
	{
		if (capacity == 0) { std::cout << ("capacity=0\n"); return; }
		base_ = new int[capacity];
		top_ = base_;	
		end_ = base_ + capacity;
	}

	Stack(const Stack& rhs) :
		base_(new int[rhs.capacity()]),
		top_(base_ + rhs.size()),
		end_(base_ + rhs.capacity())

	{
		for (size_t i = 0; i < rhs.size(); ++i) base_[i] = rhs.base_[i];
	};

	Stack& operator=(Stack& rhs) {
		if (this == &rhs) return *this;
		if (capacity() != rhs.capacity()) {
			delete[] base_;
			base_ = new int[rhs.capacity()];
			end_ = base_ + rhs.capacity();
		}
		for (size_t i = 0; i < rhs.size(); ++i) base_[i] = rhs.base_[i];
		top_ = base_ + rhs.size();
		return *this;

	}

	~Stack() {
		delete[] base_;
		base_ = top_ = end_ = nullptr;
	}

	bool empty() const { return top_ == base_; };
	bool full() const { return top_ == end_; };
	size_t size() const { return static_cast<size_t>(top_ - base_); }
	size_t capacity() const { return static_cast<size_t>(end_ - base_); }


	void push(int i) {
		if (full()) {
			std::cout << "Stack overflow\n";
			return;
		}
		*top_++ = i;
	}

	int pop() {
		if (empty()) {
			std::cerr << "Stack is empty\n";
			return NULL;
		}
		return *--top_;
	}

	int top() {
		if (empty()) {
			std::cerr << "Stack is empty\n";
			return NULL;
		}
		return *(top_ -1);
	}

	void printStack() {
		if (empty()) return;
		for (int i = 0; i < size(); i++) {
			std::cout << base_[i] << " ";
		}
	}



private:
	int* base_;
	int* top_;
	int* end_;

	
};


#endif 