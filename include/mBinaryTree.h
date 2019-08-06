#ifndef M_BINARY_TREE_H_
#define M_BINARY_TREE_H_
typedef struct cfBTreeNode {
    int value;
    cfBTreeNode* left;
    cfBTreeNode* right;
    cfBTreeNode(int _value)
    :value(_value), left(nullptr), right(nullptr)
    { }
} cfBTreeNode;
cfBTreeNode* construct(int* preorder, int*inorder, int length);
cfBTreeNode* getNext(cfBTreeNode* pNode);
#endif