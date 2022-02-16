#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int* y){

	int temp = *x;
	*x = *y;
	*y = temp;

}

void bubblesort(vector<int>& vec){

	for (int i=0;i<vec.size()-1;++i){
		bool flag = false;
		for (int j=0;j<vec.size()-i-1;++j){
			if(vec[j] > vec[j+1]){
				  swap(&vec[j],&vec[j+1]);
				  flag = true;
			}
		}
			if (!flag)
				  break;
	}
}

int main(int argc, char* argv[]){

	vector<int> vec = {5,1,4,2,8};		//test case taken from geeksforgeeks
	bubblesort(vec);

	for (auto it=vec.begin();it!=vec.end();++it){
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
