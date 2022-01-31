/*
	program: minstack.cpp
	leetcode: https://leetcode.com/problems/min-stack/
	Runtime: 40 ms, faster than 31.15% of C++ online submissions for Min Stack.
	Memory Usage: 16.3 MB, less than 67.32% of C++ online submissions for Min Stack.

*/


#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        
        if(data.empty()){
            data.push_back({val,val});
            return;
        }
        
        pair<int,int> temp = data.back();
        int temp2 = temp.second;
        pair<int,int> newval;
        newval.first = val;
        if(val<temp2)
            newval.second = val;
        else
            newval.second = temp2;
        data.push_back(newval);
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        return data.back().first;
    }
    
    int getMin() {
        return data.back().second;
    }
private:
    vector<pair<int,int>> data;
};

int main(int argc, char* argv[]){

	//input from leetcode
	
	  MinStack minStack;
	  minStack.push(-2);
	  minStack.push(0);
	  minStack.push(-3);
	  cout << "current min value is: " <<  minStack.getMin() << endl; // return -3
	  minStack.pop();
	  minStack.top();    // return 0
	  cout << "current min value is: " <<  minStack.getMin() << endl; // return -2	

	

	  return 0;
}
