#include "set.hpp"

set::set() : ab_(), tb_(), is_array_(true) {}

set::set(const searchable_bag &b) : ab_(), tb_() {
    // per fare la copia dobbiamo sapere che tipo di searchable bag è
    // usiamo quindi il dynamic cast (ritorna NULL se fallisce il cast)
    // l'oggetto poi viene copiato tramite operator=
    // da notare che questo costruttore potrebbe non essere l'unico necessario
    // controllare le traces (es set sa(a); prend un puntatore)
    const searchable_array_bag *pab = dynamic_cast<const searchable_array_bag*>(&b);
    if (pab) {
        ab_ = *pab;
        is_array_ = true;
    }
    else {
        const searchable_tree_bag *ptb = dynamic_cast<const searchable_tree_bag*>(&b);
        if (ptb) {
            tb_ = *ptb;
            is_array_ = false;
        }
        else //se non è nessuno dei 2 tipi lasciamo entrambi gli oggetti vuoti e diciamo che è un array_bag
            is_array_ = true;
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

void set::insert(int v) {
    if (is_array_) 
        ab_.insert(v);
    else
        tb_.insert(v);
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
