/*
	This is a working implementation of the problem, but times out. Has O(n^2) time complexity.
	Hence I have not written the I/O and main for this program.
	Please use the montonic stack to solve this problem in O(n)

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        for(auto it = temperatures.begin(); it!=temperatures.end(); ++it){
            auto jt=it+1;
            for(; jt!=temperatures.end(); ++jt){
                if(*jt>*it){
                     *it = jt - it;
                     break;
                }
            }
            if(jt==temperatures.end())
                *it = 0;
        }
        return temperatures;
    }

};
