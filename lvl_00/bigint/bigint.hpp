#pragma once
#include <string>
#include <algorithm>
#include <iostream>

struct bigint {
    std::string _val;

    bigint() : _val("0") {}
    bigint(unsigned int i) { _val = ""; if (!i) _val = "0"; else while (i) _val = char('0' + i % 10) + _val, i /= 10; }
    bigint(const std::string& s) : _val(s.empty() ? "0" : s) {}
    bigint(const bigint& o) : _val(o._val) {}
    bigint& operator=(const bigint& o) { _val = o._val; return *this; }

    bigint operator+(const bigint& o) const {
        std::string a = _val, b = o._val, res = "";
        std::reverse(a.begin(), a.end()); std::reverse(b.begin(), b.end());
        int carry = 0, i = 0;
        while (i < (int)a.size() || i < (int)b.size() || carry) {
            int sum = carry + (i < (int)a.size() ? a[i] - '0' : 0) + (i < (int)b.size() ? b[i] - '0' : 0);
            res = char('0' + sum % 10) + res; carry = sum / 10; i++;
        }
        return bigint(res);
    }

    bigint& operator+=(const bigint& o) { *this = *this + o; return *this; }

    bool operator<(const bigint& o) const {
        if (_val.size() != o._val.size()) return _val.size() < o._val.size();
        return _val < o._val;
    }

    bigint operator<<(unsigned int n) const {
        bigint res(*this);
        for (unsigned int i = 0; i < n; i++) {
            int carry = 0;
            for (int j = res._val.size() - 1; j >= 0; j--) {
                int val = (res._val[j] - '0') * 2 + carry;
                res._val[j] = '0' + val % 10; carry = val / 10;
            }
            if (carry) res._val = '1' + res._val;
        }
        return res;
    }

    void print() const { std::cout << _val << std::endl; }
};
