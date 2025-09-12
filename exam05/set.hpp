#ifndef SET_H
#define SET_H

#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class set {
private:

    searchable_bag *_bag;

public:

    set();
    set(const set& other);
    set(searchable_bag& bag);
    ~set();
    set& operator=(const set& other);
    void insert(int val);
    void insert(int *a, int s);
    bool has(int val) const;
    void print(void);
    void clear(void);
    searchable_bag& get_bag(void);

};
#endif