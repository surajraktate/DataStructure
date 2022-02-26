// Stack Implimentation using class
#include <iostream>
#include <stdexcept>
#include <string.h>

using namespace std;

class Stack{
private:
	int total_length, top=-1;
	char stack_data[100];
	int isFull(){
		if(top >= total_length - 1){
			return 1;
		}
		else{
			return 0;
		}
	} 
	int isEmpty(){
		if(top == -1){
			return 1;
		}
		else{
			return 0;
		}	
	}
public:
	Stack(){
		total_length = 100;
	}
	Stack(int total_number_of_elements){
		total_length = total_number_of_elements;
	}
	char pop(){
		char data=NULL;
		if(!isEmpty()){
			data = stack_data[top];
			top--;
		}else{
			throw std::length_error("Stack is Empty!!");
		}
		return data;
	}

	void push(char data){
		if(!isFull()){
			top++;
			stack_data[top] = data;
		}else{
			throw std::length_error("Stack is Full!!");
		}
	}

	int length(){
		return top + 1;
	}
};

int main(){
	Stack s(5);
	int choice;
	char data;

	do{
		cout << "\nSelect Option from Menu : \n 1. Push\n 2. Pop\n 3. Length\n 4. Exit \n Choice = ";
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				try{
					cout << "\nPlease Enter Data : ";
					scanf("%s", &data);
					s.push(data);
				}catch(const std::length_error& e){
					cout << e.what() << endl;;
				}
				break;

			case 2:
				try{
					data = s.pop();
					cout << "\n Data = " << data;
				}catch(const std::length_error& e){
					cout << e.what() << endl;;
				}
				break;
			case 3:
				cout << s.length();
				break;
			case 4:
				return 0;
				break;
			default:
				cout << "\nPlease Enter valid Option";
				break;
		}
		
	}while(1);

	return 0;
}