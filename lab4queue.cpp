#include <iostream>
#include "D:\source\repos\algorithms_and_data_structures\stackLab3\STACK.h"
 //#include <cstdlib>
using namespace std;

// define default capacity of the queue
#define SIZE 10

// Class for queue
class queue
{
	int* arr;   	// array to store queue elements
	int capacity;   // maximum capacity of the queue
	int front;  	// front points to front element in the queue (if any)
	int rear;   	// rear points to last element in the queue
	int count;  	// current size of the queue

public:
	queue(int size = SIZE);	 // constructor
	~queue();				   // destructor

	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
	void swap_top_and_bottom();
	void reverse_gueue();
	void deleteAll();
	bool belongs(int val);
	void print();
};

// Constructor to initialize queue
queue::queue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
	delete[] arr;
}

// Utility function to remove front element from the queue
void queue::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << arr[front] << '\n';
	front = (front + 1) % capacity;
	count--;
}

// Utility function to add an item to the queue
void queue::enqueue(int item)
{
	// check for queue overflow
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

// Utility function to return front element in the queue
int queue::peek()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[front];
}

// Utility function to return the size of the queue
int queue::size()
{
	return count;
}

// Utility function to check if the queue is empty or not
bool queue::isEmpty()
{
	return (size() == 0);
}

// Utility function to check if the queue is full or not
bool queue::isFull()
{
	return (size() == capacity);
}
void queue::swap_top_and_bottom() {
	if (!isEmpty()) {
		int temp = arr[front];
		arr[front] = arr[rear];
		arr[rear] = temp;
	}
	else { cout << "Queue is empty" << endl; }
}
void queue::reverse_gueue() {
	STACK<int> Stack;
	while (!isEmpty()) {
		Stack.push(peek());
		dequeue();
	}
	while (!isEmpty()) {
		enqueue(Stack.top_int());
		Stack.pop();
	}
	
}
void queue::deleteAll() {
	for (int i = front; i <= size(); i++) {
		dequeue();
	}
}
bool queue::belongs(int val) 
{
	for (int i = front; i <= size(); i++) {
		if (arr[i] == val) {
			return true;
		}
	}
	return false;
}
void queue::print() {
	if (!isEmpty()) {
		for (int i = front; i <= size(); i++) {
			cout << arr[i] << endl;

		}
	}
	else cout << "empty" << endl;
}

int main()
{
	
	queue theQueue(50);

	int ch=0, val;
	while (ch != 11) {
		cout << "choose the action" << endl;
		cout << "1 - remove from queue" << endl;
		cout << "2 - put to the queue" << endl;
		cout << "3 - get size" << endl;
		cout << "4 - check if empty" << endl;
		cout << "5 - check if full" << endl;
		cout << "6 - swap top and bottom" << endl;
		cout << "7 - reverse" << endl;
		cout << "8 - clear" << endl;
		cout << "9 - check if element belongs" << endl;
		cout << "10 - print" << endl;
		cout << "11 - exit the menu" << endl;
		cin >> ch;
		switch (ch) {
		case 1:
			theQueue.dequeue();
			break;
		case 2:
			cout << "enter element" << endl;
			cin >> val;
			theQueue.enqueue(val);
			break;
		case 3:
			cout << theQueue.size() << endl;
			break;
		case 4:
			cout << theQueue.isEmpty() << endl;
			break;
		case 5:
			cout << theQueue.isFull() << endl;
			break;
		case 6:
			theQueue.swap_top_and_bottom();
			break;
		case 7:
			theQueue.reverse_gueue();
			break;
		case 8:
			theQueue.deleteAll();
			break;
		case 9:
			cout << "enter element" << endl;
			cin >> val;
			theQueue.belongs(val);
			break;
		case 10:
			theQueue.print();
			break;
		}
	}
	return 0;
}