#include<stdio.h>

int stack[100], top=-1, total_elements=0;

int isEmpty(){

	if(top == -1){
		printf("\n Stack is Empty \n");
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(){

	if(top >= total_elements -1 ){
		printf("Stack is Full!!!");
		return 1;
	}
	else{
		return 0;
	}	
}

int pop(){
	int data = -1;
	if(!isEmpty()){
		data = stack[top];
		top--;
	}
	return data;
}

void push(int data_to_push){

	if(!isFull()){
		top++;
		stack[top] = data_to_push;
	}
}

void display(){

	if(!isEmpty()){
		printf("\nYour Stack Is : \n");
		for(int i=0; i<=top; i++){
			printf("%d,", stack[i]);
		}
	}
}

int main(){
	int choice, data;

	printf("Please Enter Total Number of Elements");
	scanf("%d", &total_elements);

	do{
		printf("\nSelect Option from Menu : \n 1. Push\n 2. Pop\n 3. Display\n 4. Exit \n Choice = ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				if(!isFull()){
					printf("\nPlease Enter Data : ");
					scanf("%d", &data);
					push(data);
				}
				break;
			case 2:
				data = pop();
				printf("\n Data = %d", data);
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
				break;
			default:
				printf("\nPlease Enter valid Option");
				break;
		}
	}while(1);
	return 0;
}