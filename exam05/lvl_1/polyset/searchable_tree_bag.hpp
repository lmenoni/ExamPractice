#ifndef SEARCHABLE_TREE_BAG_H
#define SEARCHABLE_TREE_BAG_H

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag: virtual public tree_bag, public searchable_bag {
public:

    searchable_tree_bag();
    ~searchable_tree_bag();
    searchable_tree_bag(const searchable_tree_bag& other );
    searchable_tree_bag& operator=(const searchable_tree_bag& other );

    bool has (int val) const;
    static void traverse_and_insert(const node* n, void (*f)(int, void*), void* param);
    node *get_tree( void ) const;
    tree_bag::node *copy_searchable_node(tree_bag:: node *n);

};

#endif