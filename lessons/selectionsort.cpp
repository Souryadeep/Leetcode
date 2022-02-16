#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int* y){

	int temp = *x;
	*x = *y;
	*y = temp;

}

void sort(vector<int>& vec){

	for (int i=0;i<vec.size();i++){		//size gives the number of elements in the vector
		int min_pos = i;
		for(int j=i+1;j<vec.size();++j){
			if(vec[j]<vec[min_pos])
				  min_pos = j;
		}
		swap(&vec[i],&vec[min_pos]);
	}

}

int main(int argc, char* argv[]){

	vector<int> vec = {64,25,12,22,11};	//test case taken from geeks for geeks
	sort(vec);

	for (auto it=vec.begin();it!=vec.end();++it){
		cout << *it << " ";
	}
	cout << endl;

	return 0;

}
