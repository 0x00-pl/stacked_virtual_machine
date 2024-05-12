#include<iostream>
using namespace std;
#include"vm_stack.h"

inline void inc(vm_stack& a){
	//beg:
	++a.stk.back();
}
typedef void pmfunc(vm_stack&);

void loop(vm_stack& stk, vector<pmfunc*>& vcmd){
	for(auto i=vcmd.begin(); i!=vcmd.end(); ++i){
		(*i)(stk);
	}
}


void main(){
	vm_stack a;
	vector<pmfunc*> cmds;
	cmds.push_back(&inc);
	cmds.push_back(&inc);
	cmds.push_back(&inc);
	cmds.push_back(&inc);
	a.push(0);
	loop(a,cmds);
	inc(a);
	system("pause");
}