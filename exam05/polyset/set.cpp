#include "set.hpp"

set::set() : ab_(), tb_(), is_array_(true) {}

set::set(const searchable_bag &b) : ab_(), tb_() {
    // per fare la copia dobbiamo sapere che tipo di searchable bag è
    // usiamo quindi il dynamic cast (ritorna NULL se fallisce il cast)
    // l'oggetto poi viene copiato tramite operator=
    // da notare che questo costruttore potrebbe non essere l'unico necessario
    // controllare le traces (es set sa(a); prend un puntatore)
    if (auto pab = dynamic_cast<const searchable_array_bag*>(&b)) {
        is_array_ = true;
        for (int i = 0; i < pab->get_size(); ++i) {
            insert(pab->get_data()[i]); // usa insert → niente duplicati
        }
    }
    else if (const searchable_tree_bag *ptb = dynamic_cast<const searchable_tree_bag*>(&b)) {
        is_array_ = false;
        ptb->for_each(insert_callback, this); // importante!! per accedere a node abbiamo bisogno che sia searchable_tree_bag a eseguire l'insert
    }
    else {
        is_array_ = true; // fallback vuoto
    }
}

set::set(const set &other) : ab_(other.ab_), tb_(other.tb_), is_array_(other.is_array_) {}

set &set::operator=(const set &other) {
    if (this != &other) {
        ab_ = other.ab_;
        tb_ = other.tb_;
        is_array_ = other.is_array_;
    }
    return *this;
}

set::~set() {}
// prende il puntatore al set come argomento e ci lancia insert
void set::insert_callback(int v, void* param) {
    set* s = static_cast<set*>(param);
    s->insert(v);
}

void set::insert(int v) {
    if (is_array_) {
        if (!ab_.has(v))
            ab_.insert(v);
    }
    else {
        if (!tb_.has(v))
            tb_.insert(v);
    }
}

void set::insert(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        insert(arr[i]);
    }
}

bool set::has(int v) const {
    return is_array_ ? ab_.has(v) : tb_.has(v);
}

void set::print() const {
    if (is_array_)
        ab_.print();
    else
        tb_.print();
}

void set::clear() {
    if (is_array_)
        ab_.clear();
    else
        tb_.clear();
}

searchable_bag &set::get_bag() {
    if (is_array_)
        return static_cast<searchable_bag&>(ab_);
    else
        return static_cast<searchable_bag&>(tb_);
}

