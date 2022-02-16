/*
	adapted from K&R
*/

#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int* y){

	int temp = *x;
	*x = *y;
	*y = temp;

}


void qsort(vector<int>& vec, int left, int right){

	if(left>right)
		  return;

	//find pivot element and swap to left most position
	swap(&vec[left],&vec[(left+right)/2]);

	int last = left;
	for(int i=left+1;i<=right;++i){
		if(vec[i]<vec[left])
			  swap(&vec[++last],&vec[i]);
	}
	swap(&vec[left],&vec[last]);
	qsort(vec,left,last-1);
	qsort(vec,left+1,right);		

}


int main(int argc, char* argv[]){
	
	vector<int> vec = {25,18,17,11,13,12,4,22,11,25,13,26,49,43,28,46,49};	//test case taken from visualalgo.net

	qsort(vec,0,vec.size()-1);
	for (auto it=vec.begin();it!=vec.end();++it){
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
