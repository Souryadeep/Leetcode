#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int* y){

	int temp = *x;
	*x = *y;
	*y = temp;

}

void insertionsort(vector<int>& vec){

	for (int i=1;i<vec.size();++i){
		
		for(int j=i-1;j>=0;--j){
			if(vec[j+1] < vec[j]){
				swap(&vec[j+1],&vec[j]);
			}	  	
			else
				break;
		}
	}

}


int main(int argc, char* argv[]){

	vector<int> vec = {29,10,14,27,13,5};	//test case taken from visualalgo.net
	insertionsort(vec);

	for (auto it=vec.begin();it!=vec.end();++it){
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
