//graphs
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
	int data;
	struct node_t *left;
	struct node_t *right;
};

struct node_t* create_node(int data, struct node_t* left, struct node_t* right) {
	struct node_t* temp = (struct node_t*)malloc(sizeof(*temp));
	temp->data = data;
	temp->left = left;
	temp->right = right;

	return temp;
}

void node_traverse(struct node_t* node) {
	printf("%d\n", node->data);

	if (node->left)
		node_traverse(node->left);

	if (node->right)
		node_traverse(node->right);
}

void node_free(struct node_t* node) {
	if (node->left)
		node_free(node->left);

	if (node->right)
		node_free(node->right);

	printf("freeing -> %d\n", node->data);
	free(node);
}

int main() {
	struct node_t* a = create_node(1, create_node(2, NULL, create_node(4, NULL, NULL)), create_node(3, NULL, NULL));
	node_traverse(a);
	node_free(a);
	return 0;
}