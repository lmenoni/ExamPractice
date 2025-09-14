#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(): tree_bag() {}

searchable_tree_bag::~searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other ) : tree_bag(other) {}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other) {
    if (this != &other) {
        tree_bag::operator=(other); // chiama l’operatore della base
    }
    return *this;
}

bool searchable_tree_bag::has(int val) const {
    const node* n = tree;
    while (n) {
        if (val == n->value)
            return true;
        if (val < n->value)
            n = n->l;
        else
            n = n->r;
    }
    return false;
}

void searchable_tree_bag::for_each(void (*f)(int, void*), void* param) const {
    traverse(tree, f, param);
}

void searchable_tree_bag::traverse(const node* n, void (*f)(int, void*), void* param) {
    if (!n)
        return;
    f(n->value, param);
    traverse(n->l, f, param);
    traverse(n->r, f, param);
}

tree_bag::node *searchable_tree_bag::copy_searchable_node(tree_bag::node *n) {
    if (!n)
        return 0;
    return new node((node){copy_searchable_node(n->l), copy_searchable_node(n->r), n->value});
}


