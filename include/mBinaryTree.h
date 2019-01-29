#ifndef M_BINARY_TREE_H_
#define M_BINARY_TREE_H_
typedef struct BTreeNode {
    int value;
    BTreeNode* left;
    BTreeNode* right;
    BTreeNode(int _value)
    :value(_value), left(nullptr), right(nullptr)
    { }
} BTreeNode;
BTreeNode* construct(int* preorder, int*inorder, int length);
BTreeNode* getNext(BTreeNode* pNode);
#endif