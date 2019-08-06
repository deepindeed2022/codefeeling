#include <gtest/gtest.h>
#include "test_api.h"
#include <mBinaryTree.h>
#include <cassert>

#define TEST_MAX_VALUE 10000

int preorders[100];
int idx = 0;
void print_preorder_btree(cfBTreeNode *root) {
	if (root) {
		fprintf(stderr, "node:%d->", root->value);
		preorders[idx++] = root->value;
		print_preorder_btree(root->left);
		print_preorder_btree(root->right);
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
	cfBTreeNode* root = construct(preorder, inorder, 6);
	idx = 0;
	print_preorder_btree(root);
	ASSERT_EQ(0, memcmp(preorder, preorders, length * sizeof(int)));
}
