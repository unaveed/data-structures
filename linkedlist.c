#include "stdio.h"
#include "stdlib.h"


typedef struct Node {
	int val;
	struct Node *next;
} Node;

void insertNode(Node* root, int n){
	if (root == NULL){
		root = (Node*)malloc(sizeof(Node));
		root->val = n;
	}
	else {
		while(root->next != NULL){
//			printf("Node: %d\n", root->val);
			root = root->next;
		}

		Node *tmp = (Node*)malloc(sizeof(Node));
		tmp->val = n;
		*root->next = tmp;
	}
}

int deletenode(Node* root, int n){
	if (root == NULL) return 0;
	
	Node *prev = (Node*)malloc(sizeof(Node));
	while(root != NULL){
		if (root->val == n)
			break;
		
		prev = root;
		root = root->next;
	}

	prev = root->next;

	return 0;
}

int length(Node* node){
	struct Node* current = node;
	int count = 0;
	while (current != NULL){
		count++;
		current = current->next;
	}

	return count;
}

void printList(Node* root){
	while (root != NULL){
		printf("[%d]->", root->val);
		root = root->next;
	}
	printf("\n");
}

int main(){
	Node *node = (Node*)malloc(sizeof(Node));
	node->val = 3;
	int i;

	for(i = 0; i < 10; i++){
		insertNode(node, i);		
	}

	//printf("Delete: %d\n", deleteNode(node, 3));

	printf("%d", length(node));
	printf("\n\n\n%d", node->val);
	//printList(node);
	free(node);

	return 0;
}
