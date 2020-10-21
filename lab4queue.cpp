#include <iostream>
#include "D:\source\repos\algorithms_and_data_structures\stackLab3\STACK.h"
using namespace std;
struct QNode {
	int data;
	QNode* next;
	QNode(int d)
	{
		data = d;
		next = NULL;
	}
	QNode() 
	{
		data = 0;
		next = NULL;
	}
	/*QNode& operator =(const QNode& a)
	{
		data = a.data;
		next = a.next;
		return *this;
	}*/
	bool operator==(const QNode& p) {
		if (this->data == p.data) { return true; }
		else return false;
	}
	friend ostream& operator<< (ostream& out, const QNode& point);
	//friend istream& operator>> (istream& out, QNode& point);
};
ostream& operator<< (ostream& out, const QNode& point)
{
	out << point.data;
	return out;
}
class queue {
private:
	QNode *front, * rear;
public: 
	queue()
	{
		front = rear = NULL;
	}

	void enqueue(int x)
	{

		QNode* temp = new QNode(x);
		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}

	void dequeue()
	{
		if (front == NULL)
			return;
		QNode* temp = front;
		front = front->next;

		if (front == NULL)
			rear = NULL;

		delete (temp);
	}
	bool isEmpty()
	{
		return (size() <=0);
	}
	QNode* peek()
	{
		if (isEmpty())
		{
			return NULL;
		}
		return front;
	}
	int size()
	{
		int count = 0;
		QNode* temp = front;
		while (temp != NULL) {
			temp = temp->next;
			++count;
		}
		return count;
	}
	void swap_top_and_bottom() 
	{
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return;
		}
		QNode* temp = front;
		rear->next = front->next;
		front->next = NULL;
		front = rear;
		QNode* node = front;
		while (node != NULL) {
			if (node->next == front) { node->next = temp; }
			node = node->next;
		}
	}
	void reverse_gueue() {
		STACK<int> Stack;
		while (!isEmpty()) {
			Stack.push(peek()->data);
			dequeue();
		}
		while (!Stack.is_empty()) {
			enqueue(Stack.top_int());
			Stack.pop();
		}
	}
	void deleteAll() {
		int s = size();
		if (s < 0) {
			return;
		}
		for (int i = 0; i < s; i++) {
			dequeue();
		}
	}
	bool belongs(QNode val)
	{
		QNode* temp = front;
		while (temp != NULL) 
		{
			if (*temp == val) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	void print() {
		if (isEmpty()) 
		{
			cout << "empty" << endl;
			return;
		}
		QNode* temp = front;
		while (temp != NULL)
		{
			cout << *temp << endl;
			temp = temp->next;
		}		
	}
};
int main()
{
	
	queue theQueue;// = new queue;

	int ch=0, val;
	while (ch != 10) {
		cout << "choose the action" << endl;
		cout << "1 - remove from queue" << endl;
		cout << "2 - put to the queue" << endl;
		cout << "3 - get size" << endl;
		cout << "4 - check if empty" << endl;
		cout << "5 - swap top and bottom" << endl;
		cout << "6 - reverse" << endl;
		cout << "7 - clear" << endl;
		cout << "8 - check if element belongs" << endl;
		cout << "9 - print" << endl;
		cout << "10 - exit the menu" << endl;
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
			theQueue.swap_top_and_bottom();
			break;
		case 6:
			theQueue.reverse_gueue();
			break;
		case 7:
			theQueue.deleteAll();
			break;
		case 8:
			cout << "enter element" << endl;
			cin >> val;
			cout << theQueue.belongs(val) << endl;
			break;
		case 9:
			theQueue.print();
			break;
		}
	}
	return 0;
}