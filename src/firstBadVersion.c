/*
	program: firstBadVersion.c
	leetcode: https://leetcode.com/problems/first-bad-version/
	Runtime: 3 ms, faster than 20.59% of C online submissions for First Bad Version.
	Memory Usage: 5.4 MB, less than 75.29% of C online submissions for First Bad Version.	

	NOTE: this solution cannot be executed as API isBadVersion is a black box

*/

#include <stdio.h>
#include <stdlib.h>

//other headers or macros go here

int firstBadVersion(int n) {
    
    int left = 1;
    int right = n;
    
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(isBadVersion(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}


int main(int argc, char *argv[]){


	if(argc==1){
		fprintf(stderr,"%s\n","usage: ./test num1 num2");
		exit(1);
	}

	int versions;
	int firstbad;

	versions = atoi(argv[1]);
	first bad = atoi(argv[2]);

	int res = firstBadVersion(versions)

	return 0;
}

