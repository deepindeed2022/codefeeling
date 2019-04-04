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

struct rb_node_base {
    typedef rb_node_base *base_ptr;
    base_ptr l_child;
    base_ptr r_child;
    base_ptr parent;
    ColorType type;
    
    static base_ptr minimum(base_ptr x) {
        // 一直往左走，就能找到红黑树的最小值节点
        while (x->l_child != 0)
            x = x->l_child;
        return x;
    }
    static base_ptr maximum(base_ptr x) {
        // 一直往右走，就能找到红黑树的最大值节点
        while (x->r_child != 0) x = x->r_child;
        return x;
    }
};

template <typename K=int, typename V=int>
struct rb_tree_node: public rb_node_base {
    typedef rb_tree_node<K, V>* link_type;
    K key;
    V value;
};

errcode_t rb_tree_add_node(rb_tree_node<int, int> *root, int k, int v);
errcode_t rb_tree_del_node(rb_tree_node<int, int> *root, int k);
errcode_t dump_rb_tree(rb_tree_node<int, int> *root);
#endif