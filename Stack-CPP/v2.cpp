#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


class LinkedList{
private:
    int size;
    Node* head;
public:
    
    LinkedList(){
        size = 0;
        head = NULL;
    }

    ~LinkedList(){
        size = 0;
        while(head != NULL) pop();
    }

    int getSize(){
        return size;
    }

    int empty(){
        return getSize() == 0;
    }

    void push(int data){
        Node* ptr = new Node(data);
        ptr->next = head;
        head = ptr;
        
        size++;
    }

    void pop(){
        if (head == NULL) return;

        Node* ptr = head;
        head = ptr->next;
        delete ptr;

        size--;
    }

    Node* getByIndex(int index){
        Node* ptr = head;
        int n = 0;

        while(n != index){
            if(ptr == NULL) return ptr;
            ptr = ptr->next;
            n++;
        }

        return ptr;
    }

    
	Node* operator [] (int index) {
		return  getByIndex(index);
	}

    void invert(){
        for(Node* ptr = head; ptr != NULL; ptr = ptr->next){
            ptr->data *= -1;
        }
    }

    void swap(int index1, int index2){
        Node* ptr_index1 = getByIndex(index1);
        Node* ptr_index2 = getByIndex(index2);
        if(ptr_index1 == NULL || ptr_index2 == NULL) return;
        int tmp = ptr_index1->data;
        ptr_index1->data = ptr_index2->data;
        ptr_index2->data = tmp;
    }

    Node* top(){
        return head;
    }

};


int main(){
    LinkedList lst;
    lst.push(1);
    lst.push(2);
    lst.push(3);

    std::cout << ">> " << lst[1]->data  << std::endl;
    std::cout << ">> " << lst[2]->data;
    lst.swap(0, 2);
    lst.invert();
    lst.pop();

    std::cout << std::endl;
    return 0;
}
