/*
	program: subsets.cpp
	leetcode: https://leetcode.com/problems/subsets/
	Runtime: 4 ms, faster than 57.80% of C++ online submissions for Subsets.
	Memory Usage: 7.5 MB, less than 44.06% of C++ online submissions for Subsets.

*/


#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        vector<string> bitmask;

        for(int i=0; i<pow(2,nums.size());++i){
              bitmask.push_back(bitset<10>(i).to_string());
              vector<int> temp;
              int ptr = bitmask.back().length()-1;
              int ptr2 = 0;
              for(int j=ptr; j>static_cast<int>(ptr-nums.size());--j){
                  int x =0;
                  if(bitmask.back()[j] == '1'){
                   temp.push_back(nums[ptr2]);  
                  }
                  ptr2++; 
                  
              }
              result.push_back(temp);
        }
        return result;
    }   
};

int main(int argc, char * argv[]){

	//test case from leetcode
	vector<int> nums = {1,2,3};

	vector<vector<int>> result;

	Solution s;
	result = s.subsets(nums);

	for(auto i = 0; i<result.size(); ++i){
		for(auto it = result[i].begin(); it!= result[i].end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}

	return 0;
}
