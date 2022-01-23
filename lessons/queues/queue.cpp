/*
	this is a user defined implementation of circular queue
	in genereal, when using queues, stick to the standard library queue, queue<int> q
	API:	
		- q.push(x)	- add value to the queue
		- q.pop()	- pop the first element from the queue (FIFO)
		- q.size()
		- q.front()	- first element of the queue
		- q.back()	- last element of the queue

*/


#include <iostream>
#include <vector>


using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        p_start=-1;
        p_end=-1;
        size = k;
        data.resize(k);
    }
    
    bool enQueue(int value) {
       if(isFull())
           return false;
        if(isEmpty())
            p_start = 0;
        
        p_end = (p_end + 1) % size;
        data[p_end] = value;
        return true;
    }
    
    bool deQueue() {
        
        if (isEmpty()) {
            return false;
        }
        if (p_start == p_end) {
            p_start = -1;
            p_end = -1;
            return true;
        }
        p_start = (p_start + 1) % size;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        else
            return data[p_start];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        else
            return data[p_end];
    }
    
    bool isEmpty() {
         return p_start == -1;           
    }
    
    bool isFull() {
        return ((p_end + 1) % size) == p_start;   
    }
private:
    vector<int> data;
    int p_start;
    int p_end;
    int size;
};


int main(int argc, char* argv[]){

	  MyCircularQueue myCircularQueue(3);
	  cout << myCircularQueue.enQueue(1) << endl; // return True
	  cout << myCircularQueue.enQueue(2) << endl; // return True
	  cout << myCircularQueue.enQueue(3) << endl; // return True
	  cout << myCircularQueue.enQueue(4) << endl; // return False
	  cout << myCircularQueue.Rear() << endl;     // return 3
	  cout << myCircularQueue.isFull() << endl;   // return True
	  cout << myCircularQueue.deQueue() << endl;  // return True
	  cout << myCircularQueue.enQueue(4) << endl; // return True
	  cout << myCircularQueue.Rear() << endl;     // return 4

	
	  return 0;
}
