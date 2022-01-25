/*
	program: majorityElem.cpp
	leetcode: https://leetcode.com/problems/majority-element/
	Runtime: 44 ms, faster than 8.45% of C++ online submissions for Majority Element.
	Memory Usage: 19.6 MB, less than 50.23% of C++ online submissions for Majority Element

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    Solution(vector<int> vec){
	nums = vec;
    }

    int majorityElement() {
        
        if(nums.size()==1)
            return nums[0];
        
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
private:
	vector<int> nums;
};


int main(int argc, char* argv[]){

	vector<int> vec;
	cout << "Enter the length of the array of elements: ";

	int len;
	cin >> len;

	
	cout << "Enter the array of elements: ";
	for (int i=0;i<len;i++){
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	

	Solution s(vec);

	int res = s.majorityElement();	

	cout << "Majority element is: " << res << endl;

	return 0;
}
