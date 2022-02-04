/*
	program: numOfIslands.cpp using dfs
	leetcode: https://leetcode.com/problems/number-of-islands/
	Runtime: 41 ms, faster than 59.11% of C++ online submissions for Number of Islands.
	Memory Usage: 12.3 MB, less than 84.30% of C++ online submissions for Number of Islands
*/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;


class Solution {
public:
    
	void dfs(vector<vector<char>>& grid,int row,int col){

        if(grid[row][col] == '0')
                  return;

        if(row+1<grid.size() && grid[row+1][col]=='1'){
                  grid[row][col]='0';
                  dfs(grid,row+1,col);
        }
        if(row-1>=0 && grid[row-1][col]=='1'){
                  grid[row][col]='0';
                  dfs(grid,row-1,col);
        }
        if(col+1<grid[0].size() && grid[row][col+1]=='1'){
                  grid[row][col]='0';
                  dfs(grid,row,col+1);
        }
        if(col-1>=0 && grid[row][col-1]=='1'){
                  grid[row][col]='0';
                  dfs(grid,row,col-1);
        }
        
        grid[row][col] = '0';

        }

	int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        int num_islands = 0;
        for (int row = 0; row < m; row++) {
                  for (int col = 0; col < n; col++) {
                        if (grid[row][col] == '1') {
                                num_islands++;
                                dfs(grid,row,col);
                                //grid[row][col] = '0';
                        }
                  }
        }
        return num_islands;

    }  

};

int main(int argc, char* argv[]){


	//input is taken from leetcode
	//1 represents land, 0 represents the water

	vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

	Solution s;

	cout << "Number of islands: " << s.numIslands(grid) << endl;

	return 0;
}




