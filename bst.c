#include "bst.h" // Header file that defines the structure and function prototypes.
#include <stdlib.h>
#include <string.h>

struct node* createNode(int data, char* question, char* guess) { // Method to create a new node and initialize its values.
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data; // Set the 'data' field of the new node.
    newNode->question = strdup(question);
    newNode->guess = strdup(guess);
    newNode->left = NULL; // Initialize the left child pointer to NULL.
    newNode->right = NULL;
    return newNode; // Return the newly created node.
}

struct node* insert(struct node* root, int data, char* question, char* guess) { // Method to insert a new node into the binary tree.
    if (root == NULL) {
        return createNode(data, question, guess); // If the tree is empty, create a new node and return it as the root.
    }

    if (data < root->data) {
        root->left = insert(root->left, data, question, guess); // If 'data' is less than the current node's 'data', insert the new node in the left subtree.
    } else if (data > root->data) {
        root->right = insert(root->right, data, question, guess);
    }
    return root; // Return the root of the subtree after insertion.
}
