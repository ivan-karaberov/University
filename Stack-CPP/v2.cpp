#include <iostream>

class Stack {
	private:
		typedef struct Obj{
			int data;
			Obj* next;
		} obj;

		obj* top = NULL;

	public:
		bool empty();
		void push(int data);
		int pop();
		void invert();
};

int main(){
	Stack c;
	c.push(1);
	c.push(2);
	c.push(-3);
	c.invert();

	while(!c.empty()){
		std::cout << "Deleted > " << c.pop() << std::endl;
	}

	return 0;
}


bool Stack::empty(){
	return top ? false : true;
}

void Stack::push(int data){
	obj* stk = new obj;
	stk -> data = data;
	stk -> next = top;
	top = stk;
}

int Stack::pop(){
	if (empty()) return 0;
	int tmp;
	obj* stk = top;
	tmp = stk -> data;
	top = stk -> next;
	delete stk;
	return tmp;
} 

void Stack::invert(){
	obj* stk = top;

	while(stk){
	stk->data = -(stk->data);
	stk = stk->next;
	}
}