#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int val;
	struct node *next;
} node_t;

node_t *head = NULL;

void push_tail(int n){
	if (head == NULL){
		head = malloc(sizeof(node_t));
		head->val = n;
		head->next = NULL;
	}
	else {
		node_t *current = head;
		while(current->next != NULL){
			current = current->next;
		}
		
		node_t *tmp = malloc(sizeof(node_t));
		tmp->val = n;
		tmp->next = NULL;
		current->next = tmp;
	}
}

void push_head(int n){
	if (head == NULL) {
		head = malloc(sizeof(node_t));
		head->val = n;
		head->next = NULL;
	}
	else {
		node_t *curr_head = head;
		node_t *new_node = malloc(sizeof(node_t));
		new_node->val = n;
		new_node->next = curr_head;
		head = new_node;
	}
}

int pop_head();
int pop_tail();

int deletenode(int n){
	if (head == NULL) return -1;
	
	node_t *prev = malloc(sizeof(node_t));
	node_t *current = head;

	while(current!= NULL){
		if (current->val == n)
			break;
		
		prev = current;
		current= current->next;
		if (current == NULL) return -1;
	}

	prev = current->next;

	return 1;
}

int length(){
	node_t *current = head;
	int count = 0;
	while (current != NULL){
		count++;
		current = current->next;
	}

	return count;
}

void printList(){
	node_t *current = head;
	while (current != NULL){
		printf("[%d]->", current->val);
		current= current->next;
	}
	printf("\n");
}

int main(){
	int i;

	for(i = 0; i < 10; i++){
		push_head(i);		
	}


	printf("%d\n", length());
	printf("%d\n", head);
	printList();
	free(head);

	return 0;
}
