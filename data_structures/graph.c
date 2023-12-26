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

void graph_traverse(struct node_t* node) {
	printf("%d", node->data);

	if (node->left)
		graph_traverse(node->left);

	if (node->right)
		graph_traverse(node->right);
}

int main() {
	struct node_t* a = create_node(1, create_node(2, NULL, create_node(4, NULL, NULL)), create_node(3, NULL, NULL));

	graph_traverse(a);
	return 0;
}