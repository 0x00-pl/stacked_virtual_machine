#include<vector>
using namespace std;

class vm_stack{
public:
	vm_stack(){}
	void push(int val){stk.push_back(val);}
	void pop(){stk.pop_back();}
	int back(){return stk.back();}
	vector<int> stk;
};