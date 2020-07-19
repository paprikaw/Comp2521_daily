#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NOT_HEIGHT_BALANCED -99

// Note that the type of "BSTree" is a "struct BSTNode *"
// In other words, BSTree is a pointer to the structure BSTNode.
typedef struct BSTNode *BSTree;
typedef struct BSTNode BSTNode;

struct BSTNode {
	int value;
	BSTree left;		// Note this is a pointer, read above.
	BSTree right;
};


// Tutorial Exercises
int printHeightDiff(BSTree tree);
int isHeightBalanced(BSTree tree);
// Extra Questions
void prefix(BSTree tree);
void infix(BSTree tree);
void destroyTree(BSTree tree);

// Tree Creation
BSTree createTree(int *numbers, int size);
BSTNode *createNode(int number);
void appendNode(BSTree root, BSTNode *node);

int main(void) {
	//  V Change this to 0 for the other tree
	#if 1
	// Balance Tree
	int size = 4;
	int numbers[4] = {3, 2, 7, 13};
	#else
	// Another Unbalanced tree - Draw it out
	int size = 8;
	int numbers[8] = {4, 2, 10, 8, 6, 5, 9, 13}; 
	#endif

	// Creating the tree based on the arrays above.
	// Insertion goes left to right.
	BSTree root = createTree(numbers, size);

	//=====================
	// Older Tute Questions
	//======================
	printf("Printing height at every node:\n");
	int height = printHeightDiff(root);
	printf("The height of the tree overall: %d\n\n", height);

	int result = isHeightBalanced(root);
	if (result == NOT_HEIGHT_BALANCED) puts("Not height balanced!");
	else printf("Tree is height balanced and has height: %d\n", result);
	

	// =============
	// Extra content
	// =============
	prefix(root);
	puts(""); 
	infix(root);
	puts(""); 
	// Since we won't put a '\n' in infix and prefix code. There is a neater method ...

	// Good idea to free memory
	destroyTree(root);
	return 0;
}

// =========================
// Week 4 Tutorial Question
// =========================
int printHeightDiff(BSTree tree) {
	//BASE CASE
	if (tree == NULL) return -1;
 
	//Recursive Step
	int left = printHeightDiff(tree->left);
	int right = printHeightDiff(tree->right);
	printf("data: %d, diff: %d", tree->value, left-right);
	int max = (left > right) ? left + 1 : right + 1;
	return -1;
}

// Return the height of the tree if it is 'height balance' 
// Otherwise, if the tree is unbalanced return NOT_HEIGHT_BALANCED
int isHeightBalanced(BSTree tree) {
	// Todo
	return -1;
}

// ================
// Extra Questions
// ================
// Print the nodes in prefix order
void prefix(BSTree tree) {
	// Todo
	return;
}

// Print the nodes in infix order
void infix(BSTree tree) {
	if (tree == NULL) return;

	// Recuresive step
	infix(tree->left);
	printf("%d", tree->value);
	infix(tree->right);
	
	return;
}

// Free all the memory in the tree
void destroyTree(BSTree tree) {
	// Todo
	return;
}


// =============
// Tree Creation
// =============
BSTree createTree(int *numbers, int size) {
	assert(numbers != NULL);
	assert(size > 0);
	BSTree root = createNode(numbers[0]);

	for (int i = 1; i < size; i++) {
		BSTNode *node = createNode(numbers[i]);
		appendNode(root, node);
	}
	return root;
}

BSTNode *createNode(int number) {
	BSTree node = malloc(sizeof(*node));
	if (node == NULL) exit(1);
	node->value = number;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void appendNode(BSTree root, BSTNode *node) {
	assert(root != NULL);
	assert(node != NULL);
	// Insert to the left
	if (node->value < root->value) {
		// If there is no left child then insert node
		if (root->left == NULL) {
			root->left = node;
			// We want to exit since we have inserted
			return;
		}
		// Otherwise there is a left child node,
		// Do a recursive step
		appendNode(root->left, node);
	}
	// Insert to the right - Duplicates are add to the right
	else if (node->value >= root->value) {
		// If there is no right child then insert node
		if (root->right == NULL) {
			root->right = node;
			// We want to exit since we have inserted
			return;
		}
		// Otherwise there is a right child node,
		// Do a recursive step
		appendNode(root->right, node);
	}
}

