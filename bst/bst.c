#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct node *createRoot(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void printTree(struct node *root) {
  if (root != NULL) {
    printTree(root->left);
    printf("%d  ", root->key);
    printTree(root->right);
  }
}


struct node *insert(struct node *node, int key) {
  if (node == NULL) return createRoot(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}


