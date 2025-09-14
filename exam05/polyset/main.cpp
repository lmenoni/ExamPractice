#include "searchable_tree_bag.hpp"
#include "searchable_array_bag.hpp"
#include <cstdlib>
#include <iostream>
#include "set.hpp"

// le stampe di debug non ci sono nel main originale
int main(int ac, char **av)
{
    if (ac == 1)
        return 1;
    std::cout << "CREO" << std::endl;
    searchable_bag *t = new searchable_tree_bag;
    searchable_bag *a = new searchable_array_bag;
    std::cout << "INSERISCO" << std::endl;
    for (int i = 1; i < ac; i++)
    {
        t->insert(atoi(av[i]));
        a->insert(atoi(av[i]));
    }
    std::cout << "STAMPO" << std::endl;
    t->print();
    a->print();
    std::cout << "CERCO" << std::endl;
    for (int i = 1; i < ac; i++)
    {
        std::cout << t->has(atoi(av[i])) << std::endl;
        std::cout << a->has(atoi(av[i])) << std::endl;
        std::cout << t->has(atoi(av[i]) - 1) << std::endl;
        std::cout << a->has(atoi(av[i]) - 1) << std::endl;
    }
    std::cout << "DISTRUGGO" << std::endl;
    t->clear();
    a->clear();
    std::cout << "DUPLICO" << std::endl;
    const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
    tmp.print();
    tmp.has(1);
    std::cout << "CREO SET" << std::endl;
    set sa(*a);
    set st(*t);
    for (int i = 1; i < ac; i++)
    {
        st.insert(atoi(av[i]));
        sa.insert(atoi(av[i]));
    }
    std::cout << "CERCO" << std::endl;
    sa.has (atoi(av[1]));
    std::cout << "STAMPO" << std::endl;
    sa.print();
    std::cout << "STAMPO DALLA BAG" << std::endl;
    sa.get_bag().print();
    std::cout << "STAMPO ST" << std::endl;
    st.print();
    sa.clear();
    std::cout << "INSERISCO ARRAY" << std::endl;
    int arr[]{1, 2, 3, 4,};
    sa.insert(arr, 4);
}