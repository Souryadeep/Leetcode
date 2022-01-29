/*
	program: numOfIslands.cpp
	leetcode: https://leetcode.com/problems/number-of-islands/
	Runtime: 68 ms, faster than 24.63% of C++ online submissions for Number of Islands.
	Memory Usage: 13.1 MB, less than 35.41% of C++ online submissions for Number of Islands. 

*/

#include <iostream>
#include <deque>
#include <utility>
#include <vector>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        deque<pair<int,int>> q;
        int num_islands = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1') {
                    num_islands++;
                    grid[row][col] = '0';
                    pair<int, int> temppair;
                    temppair.first = row;
                    temppair.second = col;
                    q.push_back(temppair);
                    while (!q.empty()) {
                        pair<int,int> point = q.front();
                        int row = point.first;
                        int col = point.second;
                        q.pop_front();
                        for (int i=0;i<4;++i) {
                            int r = row + direction[i].first;
                            int c = col + direction[i].second;
                            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != '1'){
                                continue;
                            }
                            grid[r][c] = '0';
                            pair<int,int> temp;
                            temp.first = r;
                            temp.second = c;
                            q.push_back(temp);
                        }   
                    }
                }
            }
        }
        return num_islands;
    }
    private:
        vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
};


int main(int argc, char* argv[]){


	//input is taken from leetcode
	//1 represents land, 0 represents the water

	vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

	Solution s;

	cout << "Number of islands: " << s.numIslands(grid) << endl;

	return 0;
}
