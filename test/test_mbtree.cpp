#include <gtest/gtest.h>
#include "test_api.h"
#include <mBinaryTree.h>
#include <cassert>

#define TEST_MAX_VALUE 10000

int preorders[100];
int idx = 0;
void printBTree(BTreeNode *root) {
	if (root) {
		fprintf(stderr, "node:%d->", root->value);
		preorders[idx++] = root->value;
		printBTree(root->left);
		printBTree(root->right);
		fprintf(stderr, "\n");
	}
}
TEST(BTree, construct) {
	/*****************************
	             1
			    / \
			   2   3
			  / \   \
			 4   5   6
	 
	******************************/
	int preorder[] = {1,2,4,5,3,6};
	int inorder[]  = {4,2,5,1,3,6};
	const int length = 6;
	BTreeNode* root = construct(preorder, inorder, 6);
	idx = 0;
	printBTree(root);
	ASSERT_EQ(0, memcmp(preorder, preorders, length * sizeof(int)));
}
