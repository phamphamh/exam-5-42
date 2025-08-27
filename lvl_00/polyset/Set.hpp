#pragma once
#include "SearchableBag.hpp"

class Set {
private:
    SearchableBag* bag;
public:
    Set(SearchableBag* bag) : bag(bag) {}
    Set(const Set& other) : bag(other.bag) {}
    virtual ~Set() {}
    Set& operator=(const Set& other) {
        if (this != &other) bag = other.bag;
        return *this;
    }
    void insert(int value) { if (!bag->has(value)) bag->insert(value); }
    void insert(int* values, int size) {
        if (!values || size <= 0) return;
        for (int i = 0; i < size; i++)
            if (!bag->has(values[i])) bag->insert(values[i]);
    }
    bool has(int value) const { return bag->has(value); }
    void print() const { bag->print(); }
    void clear() { bag->clear(); }
};
