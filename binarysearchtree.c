#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *left, *right;
} node_bt;

node_bt *root = NULL;

node_bt* insert_node(node_bt nd, int n);

void insert(int n){
   if (root == NULL){
      root = malloc(sizeof(node_bt));
      root->data = n;
   }
   else {
      node_bt *top = root;
      insert_node(*top, n);
   }
}

node_bt* insert_node(node_bt nd, int n){
   if (nd == NULL){
      node_bt *new_node = malloc(size(node_bt));
      *new_node->data = n;
      return new_node;
   }
   if (n <= nd->data){
      nd->left = insert_node(nd->left, data);
   }
   else {
      nd->right = insert_node(nd->right, data);
   }
}

int main(){

   return 0;
}
