/*
	program: reversepolish.cpp
	leetcode: https://leetcode.com/problems/evaluate-reverse-polish-notation/
	Runtime: 18 ms, faster than 32.12% of C++ online submissions for Evaluate Reverse Polish Notation.
	Memory Usage: 12.5 MB, less than 11.66% of C++ online submissions for Evaluate Reverse Polish Notation.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        vector<string> stack;

        for (auto it=tokens.begin();it!=tokens.end();++it){
            if(*it == "+"){
                int temp2 = stoi(stack.back());
                stack.pop_back();
                int temp1 = stoi(stack.back());
                result = temp1+temp2;
                stack.pop_back();
                stack.push_back(to_string(result));

            }
            else if(*it == "-"){
                int temp2 = stoi(stack.back());
                stack.pop_back();
                int temp1 = stoi(stack.back());
                result = (temp1-temp2);
                stack.pop_back();
                stack.push_back(to_string(result));

            }
            else if(*it == "*"){
                int temp2 = stoi(stack.back());
                stack.pop_back();
                int temp1 = stoi(stack.back());
                result = (temp1*temp2);

                stack.pop_back();
                stack.push_back(to_string(result));

            }
            else if(*it == "/"){
               int temp2 = stoi(stack.back());
                stack.pop_back();
                int temp1 = stoi(stack.back());
                result =  (temp1/temp2);

                stack.pop_back();
                stack.push_back(to_string(result));

            }
            else{
                stack.push_back(*it);
            }
        }
        return stoi(stack.back());
    }
};

int main(int argc, char* argv[]){
	
	//input taken from leetcode testcase
	vector<string> input = {"2","1","+","3","*"};
	Solution s;
	int result = s.evalRPN(input);

	cout << "The calculation result is: " << result << endl;

}
