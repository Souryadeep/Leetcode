/*
	program: pow.coo
	leetcode: https://leetcode.com/explore/learn/card/recursion-i/256/complexity-analysis/2380/
	Algorithm: fast power recurse algo used
	For x^y, it is the same as doing x^(y/2) * x^(y/2). So the recursion depth can be reduced to half
	This is much better in terms of space and time complexity
	For an odd number, x^(y/2) * x^(y/2), multiply this by x one more time before returning
*/

#include <iostream>

using namespace std;

class Solution {
public:

    double fastPow(double x, long long n){

        if(n==0)
            return 1.0;
        double half = fastPow(x,n/2);

        if(n%2 == 0)
            return half*half;
        else
            return half*half*x;


    }

    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            x = 1/x;
            N = -N;
        }
        return fastPow(x,N);
    }
};

int main(int argc, char* argv[]){

	Solution s;
	cout << s.myPow(2.0,10) << endl;
	

}
