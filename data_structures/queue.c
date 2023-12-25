//queue
#include <stdio.h>
#include <stdlib.h>

struct queue_t {
	int value;
	struct queue_t *front;
	struct queue_t *back;
};

struct queue_t* enque(int value, struct queue_t *next) {
	struct queue_t* this = (struct queue_t*)malloc(sizeof(*this));

	this->value = value;

	if (next != NULL) {
		next->front = this;
		this->back = next;
	} else {
		this->front = NULL;
		this->back = NULL;
	}

	return this;
}

struct queue_t* deque(struct queue_t* this) {
	struct queue_t* return_value = NULL;

	if (this->back) {
		this->back->front = NULL;
		return_value = this->back;
	}

	free(this);
	return return_value;
}

int main() {
	struct queue_t* my_queue = enque(5, enque(6, enque(7, NULL)));

	struct queue_t* temp = my_queue;
	while(temp != NULL) {
		printf("%d\n", temp->value);
		temp = deque(temp);
	}

	return 0;
}
