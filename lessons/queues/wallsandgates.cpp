/*
	program: wallsandgates.cpp
	leetcode: https://leetcode.com/problems/walls-and-gates/
	Runtime: 27 ms, faster than 93.03% of C++ online submissions for Walls and Gates
	Memory Usage: 14.4 MB, less than 67.71% of C++ online submissions for Walls and Gates 

*/


#include <iostream>
#include <deque>
#include <vector>
#include <utility>	//for the pair data structure
#include <climits>	//for INT_MAX

using namespace std;


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
    
        int m = rooms.size();
        if (m == 0) return;
        int n = rooms[0].size();

        deque<pair<int,int>> q;				//double ended queue used to implement the queue for BFS

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (rooms[row][col] == 0) {             //Gate = 0
                    pair<int, int> temppair;
                    temppair.first = row;
                    temppair.second = col;
                    q.push_back(temppair);
                }
            }
        }
        while (!q.empty()) {
                pair<int,int> point = q.front();
                int row = point.first;
                int col = point.second;
                q.pop_front();
                for (int i=0;i<4;++i) {
                    int r = row + direction[i].first;
                    int c = col + direction[i].second;
                    if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] != INT_MAX){
                        continue;
                    }
                    rooms[r][c] = rooms[row][col] + 1;
                    pair<int,int> temp;
                    temp.first = r;
                    temp.second = c;
                    q.push_back(temp);
                }
        }
        
    }
    private:
        vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
};


int main(){

	//this input is taken from the leetcode question
	//INT_MAX represents an empty room
	//-1 represents a wall
	//0 represents a gate
	vector<vector<int>> rooms = {{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};

	Solution s;
	s.wallsAndGates(rooms);

	for(int i=0;i<rooms.size();++i){
		for(auto it = rooms[i].begin();it!=rooms[i].end();++it){
			cout << *it << " "; 
		}
		cout << endl;
	}
	

	return 0;
}
