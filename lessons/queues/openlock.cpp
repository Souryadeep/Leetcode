/*
	program: openlock.cpp
	leetcode: https://leetcode.com/problems/open-the-lock/
	Runtime: 1088 ms, faster than 6.19% of C++ online submissions for Open the Lock.
	Memory Usage: 19.1 MB, less than 94.10% of C++ online submissions for Open the Lock.
*/


#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
                
        for(auto& x:deadends)
		{
			if(x=="0000") return -1;
		}
        
        for(int i=0;i<8;i++){
            if(i%2==0)
                incdec.push_back(1);
            else{
                incdec.push_back(-1);
            }
        }            
        
        vector<bool> been_there(10000, false);
        vector<int> distance(10000, -1);

        deque<string> q;
        int depth = 0;
        
        q.push_back("0000");
        distance[0] = 0;
        
        while (!q.empty()) {
            string lock_val = q.front();
            q.pop_front();
            int n = stoi(lock_val);
            been_there[n] = true;
            
            if(lock_val == target)
                return distance[stoi(lock_val)];

            
            int j=0;
            for (int i=0;i<8;++i){
                
                string s1 = lock_val;
                // cout << incdec[i] << endl;
                if(incdec[i] == 1 && s1[j] == '9')
                    s1[j] = '0';
                else if (incdec[i] == -1 && s1[j] == '0')
                    s1[j] = '9';
                else
                    s1[j] = s1[j] + incdec[i];
                
                
                
                if(!been_there[stoi(s1)] && find(deadends.begin(),deadends.end(),s1)==deadends.end()){
                     q.push_back(s1);
                     been_there[stoi(s1)] = true;
                     distance[stoi(s1)] = distance[stoi(lock_val)] + 1;
                }
                if(i%2!=0)
                    j++;
                                       
            }   
        }
        return -1;
    }
private:
    vector<int> incdec;
};


int main(int argc, char** argv){
	
	//input is taken from leetcode

	vector<string> deadends = {"0201","0101","0102","1212","2002"};
	string target("0202");

	Solution s;

	cout << "Number of steps to unlock: " << s.openLock(deadends,target) << endl;

	return 0;

}
