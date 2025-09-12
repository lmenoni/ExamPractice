#ifndef SET_H
#define SET_H

#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class set {
private:

// sono oggetti e non puntatori per non dare errore con delete.
// non sono searchable bag 
// non essendo puntatori non possono essere messi a NULL,
// abbiamo quindi un booleano per distinguere su quale oggetto chiamare la relativa funzione
// ATTENZIONE gestiamo 2 soli tipi di bag, se il tester prova con nuovi tipi di bag andra' trovato un modo per gestirli
    searchable_array_bag ab_;
    searchable_tree_bag  tb_;
    bool    is_array_;

public:

    set();
    set(const set& other);
    set(const searchable_bag &b);
    ~set();
    set& operator=(const set& other);
    // chiamano l'omonima funzione sull'oggetto
    void insert(int val);
    void insert(int *a, int n);
    bool has(int val) const;
    void print(void) const;
    void clear(void);
    searchable_bag& get_bag(void);

};
#endif
