#pragma once
#include "ArrayBag.hpp"
#include "SearchableBag.hpp"

class SearchableArrayBag : public ArrayBag, public SearchableBag {
public:
    SearchableArrayBag() : ArrayBag() {}
    SearchableArrayBag(const SearchableArrayBag& other) : ArrayBag(other) {}
    ~SearchableArrayBag() {}
    SearchableArrayBag& operator=(const SearchableArrayBag& other) {
        if (this != &other) ArrayBag::operator=(other);
        return *this;
    }
    virtual bool has(int value) const {
        for (int i = 0; i < _size; ++i)
            if (_data[i] == value) return true;
        return false;
    }
};
