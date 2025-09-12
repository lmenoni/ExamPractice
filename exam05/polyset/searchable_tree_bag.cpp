#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(): tree_bag() {}

searchable_tree_bag::~searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other ) : tree_bag(other) {}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other ) {
    this->clear();
    this->tree = copy_searchable_node(other.tree);
    return *this;
}

bool searchable_tree_bag::has(int val) const {
    node **n = (node **)&(this->tree);
    while (*n)
    {
        if (val == (*n)->value)
            return (true);
        if (val < (*n)->value)
            n = &(*n)->l;
        else if (val >= (*n)->value)
            n = &(*n)->r;
    }
    return (false);
}

tree_bag::node *searchable_tree_bag::copy_searchable_node(tree_bag::node *n) {
    if (!n)
        return 0;
    return new node((node){copy_searchable_node(n->l), copy_searchable_node(n->r), n->value});
}

