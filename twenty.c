#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Function to create a game tree with predefined questions and guesses.
struct node* CreateGameTree() {
    struct node* gameTree = NULL; // Initialize a pointer to the root of the game tree.

    // Insert predefined questions and guesses into the game tree.
    gameTree = insert(gameTree, 100, "Does it grow underground?", "");
    insert(gameTree, 50, "Is it long in shape?", "");
    insert(gameTree, 25, "Is it orange in color?", "");
    insert(gameTree, 15, "", "It's a carrot!");
    insert(gameTree, 35, "", "It's a parsnip!");
    insert(gameTree, 75, "Is it red in color?", "");
    insert(gameTree, 65, "", "It's a radish!");
    insert(gameTree, 85, "", "It's a potato!");
    insert(gameTree, 150, "Does it grow on a tree?", "");
    insert(gameTree, 125, "Is it red in color?", "");
    insert(gameTree, 115, "", "It's an apple!");
    insert(gameTree, 135, "", "It's a peach!");
    insert(gameTree, 175, "Is it red in color?", "");
    insert(gameTree, 165, "", "It's a tomato!");
    insert(gameTree, 185, "", "It's a pea!");

    return gameTree; // Return the pointer to the root of the created game tree.
}

// Function to play the game recursively.
void PlayGame(struct node* root) {
    if (root == NULL) {
        printf("I don't know what it is!\n"); // If the root is NULL, it means the game tree doesn't have an answer.
        return;
    }

    if (*root->question) { // If the node contains a question (not a guess), ask the question.
        printf("%s\ny/n: ", root->question);
        char input;
        scanf(" %c", &input);
        if (input == 'y') {
            PlayGame(root->left); // If the user answers 'yes', continue with the left child.
        } else if (input == 'n') {
            PlayGame(root->right); // If the user answers 'no', continue with the right child.
        }
    } else { // If the node contains a guess, ask if it's correct.
        printf("%s\ny/n: ", root->guess);
        char input;
        scanf(" %c", &input);
        if (input == 'y') {
            printf("I win!\n"); // If the user answers 'yes', the computer wins.
        } else {
            printf("You win!\n"); // If the user answers 'no', the user wins.
        }
    }
}

int main() {
    struct node* gameTree = CreateGameTree(); // Create the game tree with predefined questions and guesses.
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    char character = 0; // Initialize a character variable for user input.

    while (1) { // While loop for playing the game until the user decides to quit.
        scanf(" %c", &character); // Take a character input from the user.
        if (character == 'q') break;
        printf("You think of a fruit or vegetable, and I will try to guess it!\n");
        PlayGame(gameTree); // Start playing the game using the created game tree.
        printf("Press 'q' to quit or any other key to continue:\n");
    }
    printf("Bye Bye!\n"); // Display a goodbye message when the user quits the game.
    return 0;
}
