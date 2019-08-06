#include "mBinaryTree.h"
#include <exception>
#include <cstdio>
#include <string>
class mException: public std::exception {
public:
    mException(const char* info) {
        fprintf(stderr,"%s\d", info);
    }
};
static cfBTreeNode* construct_internal(
    int* startPreOrder, int* endPreOrder,
    int* startInOrder, int* endInOrder
) {
    int rootValue = startPreOrder[0];
    cfBTreeNode* root = new cfBTreeNode(rootValue);
    //
    if(startPreOrder == endPreOrder) {
        if(startInOrder == endInOrder && *startPreOrder == *startInOrder){
            return root;
        } else {
            throw mException("Invalid input");
        }
    }
    int* rootInOrder = startInOrder;
    while(rootInOrder <= endInOrder && *rootInOrder != rootValue)
        ++rootInOrder;
    //
    if(rootInOrder == endInOrder && *rootInOrder != rootValue)
        throw mException("Invalid input");
    int leftLength = rootInOrder - startInOrder;
    int* leftPreorderEnd = startPreOrder+leftLength;
    if(leftLength > 0) {
        root->left = construct_internal(startPreOrder+1, leftPreorderEnd,
                        startInOrder, rootInOrder-1);
    }
    if(leftLength < endPreOrder - startPreOrder) {
        root->right = construct_internal(leftPreorderEnd+1, endPreOrder, 
                        rootInOrder+1, endInOrder);
    }
    return root;
}

cfBTreeNode* construct(int* preorder, int* inorder, int length) {
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    return construct_internal(preorder, preorder+length-1,inorder,inorder+length-1);
}


cfBTreeNode* getNext(cfBTreeNode* pNode){
    return nullptr;
}