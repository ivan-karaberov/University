/* Разработать классы для  решения заданий лабораторной работы №4. */

#include <iostream>
#include <vector>

class Stack{
	private:
		int topOfStack = 0;
		std::vector<int> elements;

	public:
		int size(){
			return topOfStack;
		}

		bool empty(){
			return size() ? false : true;
		}

		void push(int element){
			topOfStack++;
			elements.push_back(element);
		}

		int pop(){
			if(empty()){
				std::cout << "Stack empty: ";
				return 0;
			} 

			int element = elements.at(--topOfStack);
			elements.pop_back();
			return element;
		}

		int top(){
			if(empty()){
				std::cout << "Stack empty: ";
				return 0;
			} 
			return elements.at(size() - 1);
		}

		void invert(){
			for(int i = 0; i < topOfStack; i++){
				elements[i] *= -1; 
			}
		}
};


int main(){
	Stack c;

	c.push(1);
	c.push(2);
	c.push(3);

	c.invert();

	while(!c.empty()){
		std::cout << "Deleted from stack > " << c.pop() << std::endl;
	}

	return 0;
}

