#ifndef INCLUDE_TREE_RB_TREE_H_
#define INCLUDE_TREE_RB_TREE_H_
#include <util.h>
// 红黑树是一种特殊的二叉树，且必须要满足以下几个特性：
// 1. 每个节点或是黑色或是红色 
// 2. 根节点是黑色 
// 3. 每个叶节点是黑色（叶节点为空节点） 
// 4. 如果一个节点是红色，则它的子节点必须是黑色 
// 5. 从一个节点到该节点的所有叶节点的路径包含相同数目的黑色节点

enum ColorType {
    BLACK,
    RED,
};

template <typename K, typename V>
struct RB_Node {
    K key;      // 键值，用于索引，可比较类型或是有相应的比较器
    V value;    // 存储的数据
    RB_Node* l_child, *r_child, *parent;
    ColorType type;
};

errcode_t rb_tree_add_node(RB_Node<int, int>* root, int k, int v);
errcode_t rb_tree_del_node(RB_Node<int, int>* root, int k);
errcode_t dump_rb_tree(RB_Node<int, int>* root);
#endif