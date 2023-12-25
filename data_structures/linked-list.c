//linked list
#include <stdio.h>
#include <stdlib.h>

struct litem_t {
	int value;
	struct litem_t* next;
};

struct litem_t* create_item(int value, struct litem_t* next) {
	struct litem_t* temp = (struct litem_t*) malloc(sizeof(*temp));
	temp->value = value;
	temp->next = next;

	return temp;
}

int main() {
	struct litem_t* first = create_item(1, create_item(2, NULL));
	struct litem_t* cur = first;

	while(cur != NULL) {
		struct litem_t* prev = cur;
		printf("value: %d\n", cur->value);
		cur = cur->next;
		free(prev);
	}
	
	return 0;
}

