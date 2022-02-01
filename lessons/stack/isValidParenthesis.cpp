#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> charstack;
        
        for(auto it=s.begin();it!=s.end();++it){
            
            if(*it=='(' || *it=='[' || *it=='{')
                charstack.push_back(*it);
            else if(*it == ')'){
                
                if(charstack.empty())
                    return false;
                else if(charstack.back()=='(')
                    charstack.pop_back();
                else if (charstack.back()=='[' || charstack.back()=='{')
                    break;
                else
                    charstack.push_back(*it);
            }
            else if(*it == ']'){
                if(charstack.empty())
                    return false;
                else if(charstack.back()=='[')
                    charstack.pop_back();
                else if (charstack.back()=='{' || charstack.back()=='(')
                    break;
                else
                    charstack.push_back(*it);
            }
            else if(*it == '}'){
                if(charstack.empty())
                    return false;
                else if(charstack.back()=='{')
                    charstack.pop_back();
                else if (charstack.back()=='(' || charstack.back()=='[')
                    break;
                else
                    charstack.push_back(*it);
            }
        }
        
        if(charstack.empty())
            return true;
        else
            return false;
    }
};

int main(int argc, char* argv[]){

	//input from leetcode
	
	string str = "(({[]}))";
	Solution s;
	bool valid = s.isValid(str);

	if(valid)
		cout << "Valid string" << endl;
	else
		cout << "Invalid string" << endl;

	return 0;
}
