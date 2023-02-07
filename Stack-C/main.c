/*
	15. Создать стек, поместив в него числа. Изменить знаки чисел в стеке 
	(положительные сделать отрицательными и наоборот)
*/


#include <stdio.h>
#include <malloc.h>


void push(int);
void show();
void invert();
int empty();
int pop();


typedef struct Obj{
	int data;
	struct Obj *next;
}obj;


obj* top = NULL;


int main(){
	push(1);
	push(2);
	push(3);
	
	printf("Original: \n");
	show();
	invert();
	printf("Inverted:\n");
	show();

	while(!empty()){
		printf("Deleted > %d\n", pop());
	}

	return 0;
}

int empty(){
	return NULL == top ? 1 : 0;
}


void push(int data){
	obj* stk = (obj*)malloc(sizeof(obj));
	stk->data = data;
	stk->next = top;
	top = stk;
}


int pop(){
	/* Удаляет элемент из стека и возвращает его значение*/
	int tmp;
	
	if(empty()) return 0;
	
	obj* stk = top;
	tmp = stk->data;
	top = stk->next;
	free(stk);
	
	return tmp;
}


void show(){
	obj* stk = top;
	
	while(stk){
	    printf("> %d\n", stk->data);
		stk = stk->next;	
	}
}


void invert(){
	obj* stk = top;
	
	while(stk){
		stk->data = -(stk->data);
		stk = stk->next;
	}
}