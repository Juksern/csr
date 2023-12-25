//stack
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

struct sitem_t {
	int value;
};

struct sitem_t* create_item(int value) {
	struct sitem_t* temp = (struct sitem_t*) malloc(sizeof(*temp));
	temp->value = value;
	return temp;
}

struct stack_t {
	int top;
	struct sitem_t* items[STACK_SIZE];
};

struct stack_t create_stack() {
	struct stack_t temp = {0, {0}};
	return temp;	
}

void push(struct stack_t* this, struct sitem_t* item) {
	if (this->top + 1 > STACK_SIZE) {
		printf("stack overflow!!\n");
		return;
	}

	this->top = this->top + 1;
	this->items[this->top] = item;
}

struct sitem_t* pop(struct stack_t* this) {
	if (this->top - 1 == -1) {
		return NULL;
	}

	struct sitem_t* temp = this->items[this->top];
	this->top--;

	return temp; 
}

int main() {
	struct stack_t stack = create_stack();
	push(&stack, create_item(5));
	push(&stack, create_item(10));
	push(&stack, create_item(10));
	push(&stack, create_item(10));
	push(&stack, create_item(10));
	push(&stack, create_item(10)); //overflow

	struct sitem_t* temp = pop(&stack);
	while (temp != NULL) {
		printf("%d\n", temp->value);
		temp = pop(&stack);
	}
	
	return 0;
}
