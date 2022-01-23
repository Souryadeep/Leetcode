/*
	program: movingabg.cpp
	leetcode: https://leetcode.com/explore/learn/card/queue-stack/228/first-in-first-out-data-structure/1368/

	- This problem is solved by using a deque (pronounced deck) data structure
	- Deque is a double ended queue, which means it is a O(1) operation to insert and delete from start and end of the queue
	- please refer to https://en.cppreference.com/w/cpp/container/deque for more details and std library functions to use with deque
*/

#include <iostream>
#include <deque>

using namespace std;

class MovingAverage {
public:
    MovingAverage(int size) {
        window = size;
    }
    
    double next(int val) {
        if(data.size()==window) {
            windowSum-=data.front();
            data.pop_front();
        }       
        data.push_back(val);
        windowSum+=val;
        
        return ((double)windowSum/data.size());
        
    }
private:
    int window;
    deque<int> data;
    int windowSum = 0;
};

int main(int argc, char*argv[]){
	
	MovingAverage ma(3);
	cout << ma.next(1) << endl; // return 1.0 = 1 / 1
	cout << ma.next(10) << endl; // return 5.5 = (1 + 10) / 2
	cout << ma.next(3) << endl; // return 4.66667 = (1 + 10 + 3) / 3
	cout << ma.next(5) <<endl; // return 6.0 = (10 + 3 + 5) / 3
	return 0;
}
