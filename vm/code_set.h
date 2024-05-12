

typedef void vmfunc(int*& stk, vmfunc*& vf);

void run_code(int* stk, vmfunc* vcmd){
	while(vcmd){
		(*vcmd)(stk,vcmd);
	}
}

void pop(int*& stk, vmfunc*& vf){
	++vf;
	--stk;
}
void push_const(int*& stk, vmfunc*& vf){
	++vf;
	stk[0]=static_cast<int>(*vf);
	++vf;
	++stk;
}

void pop_mem(int*& stk, vmfunc*& vf){
	++vf;
	--stk;
	*static_cast<int*>(*vf)= stk[0];
	++vf
}
void push_mem(int*& stk, vmfunc*& vf){
	++vf;
	stk[0]= *static_cast<int*>(*vf);
	++vf
	++stk;
}

void add(int*& stk, vmfunc*& vf){
	++vf;
	stk[-2]+= stk[-1];
	--stk;
}
void sub(int*& stk, vmfunc*& vf){
	++vf;
	stk[-2]-= stk[-1];
	--stk;
}
void mul(int*& stk, vmfunc*& vf){
	++vf;
	stk[-2]*= stk[-1];
	--stk;
}
void div(int*& stk, vmfunc*& vf){
	++vf;
	stk[-2]/= stk[-1];
	--stk;
}
void fadd(int*& stk, vmfunc*& vf){
	++vf;
	static_cast<float>(stk)[-2]+= static_cast<float>(stk)[-1];
	--stk;
}
void fsub(int*& stk, vmfunc*& vf){
	++vf;
	static_cast<float>(stk)[-2]-= static_cast<float>(stk)[-1];
	--stk;
}
void fmul(int*& stk, vmfunc*& vf){
	++vf;
	static_cast<float>(stk)[-2]*= static_cast<float>(stk)[-1];
	--stk;
}
void fdiv(int*& stk, vmfunc*& vf){
	++vf;
	static_cast<float>(stk)[-2]/= static_cast<float>(stk)[-1];
	--stk;
}