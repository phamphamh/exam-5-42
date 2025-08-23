#include "bigint.hpp"
#include <limits>

static size_t parseShiftCount(const std::string& revDigits) {
    size_t value = 0;
    for (size_t i = revDigits.size(); i-- > 0; ) {
        int d = revDigits[i] - '0';
        if (value > std::numeric_limits<size_t>::max() / 10)
            return std::numeric_limits<size_t>::max();
        value = value * 10 + static_cast<size_t>(d);
    }
    return value;
}

bigint::bigint() : _val("0"){}


bigint::bigint(unsigned int i){
    std::ostringstream oss;
    oss << i;
    _val = oss.str();
    std::reverse(_val.begin(), _val.end());
}

bigint::bigint(const std::string& val){
    bool isDigi = true;
    for(std::string::const_iterator it = val.begin(); it < val.end(); ++it)
        if (!::isdigit(*it))
            isDigi = false;
    if (val.empty() || isDigi == false)
        _val = "0";
    else {
    _val = val;
    std::reverse(_val.begin(), _val.end());
    removeZero();
    }
}
bigint::bigint(const bigint& other) : _val(other._val){}
bigint& bigint::operator=(const bigint& rhs){
    if (this != &rhs){
        _val = rhs._val;
    }
    return *this;
}
bigint::~bigint(){}


void bigint::removeZero(){
    while(_val.size() && _val[_val.size() - 1] == '0')
        _val.erase(_val.size() - 1);
    if (_val.empty())
        _val = "0";
}

std::string bigint::addStrings(const std::string s1, const std::string s2){
    std::string final;
    size_t result = 0, rest = 0, len = 0;
    len = (s1.size() > s2.size()) ? s1.size() : s2.size();
    for (size_t i = 0; i < len ; i++){
        int s1_r = (i < s1.size()) ? s1[i] - '0' : 0;
        int s2_r = (i < s2.size()) ? s2[i] - '0' : 0;
        result = s1_r + s2_r + rest;
        final.push_back((result % 10) + '0');
        rest = result / 10;
    }
    if (rest) final.push_back(rest + '0');
    return final;
}

bigint bigint::operator+(const bigint& bi){
    bigint res(addStrings(_val, bi._val));
    return res;
}

bigint& bigint::operator+=(const bigint& bi){
    _val = addStrings(_val, bi._val);
    return *this;
}

bigint bigint::operator++(int){
    bigint res(*this);
    _val = addStrings(_val, "1");
    return res;
}

bigint& bigint::operator++(){
    _val = addStrings(_val, "1");
    return *this;
}

bool bigint::operator==(const bigint& bi) const{
    return this->_val == bi._val;
}
bool bigint::operator!=(const bigint& bi) const{
    return !(*this == bi);
}
bool bigint::operator<(const bigint& bi) const{
    if (_val.size() != bi._val.size())
        return _val.size() < bi._val.size();
    for (size_t i = _val.size(); i-- > 0; ){
        if (_val[i] < bi._val[i])
            return true;
        if (_val[i] > bi._val[i])
            return false;
    }
    return false;
}

bool bigint::operator>(const bigint& bi) const{
    return bi < *this;
}
bool bigint::operator>=(const bigint& bi) const{
    return !(*this < bi);
}
bool bigint::operator<=(const bigint& bi) const{
    return !(*this > bi);
}

bigint bigint::operator<<(unsigned int y) const{
    bigint r(*this);
    if (y > 0)
        r._val.insert(r._val.begin(), y, '0');
    return r;
}

bigint bigint::operator>>(unsigned int y) const{
    bigint r(*this);
    if (y >= r._val.size()) {
        r._val = "0";
        return r;
    }
    if (y > 0)
        r._val.erase(r._val.begin(), r._val.begin() + y);
    return r;
}

bigint bigint::operator<<(const bigint& bi) const{
    size_t count = parseShiftCount(bi._val);
    return (*this) << static_cast<unsigned int>(count);
}

bigint bigint::operator>>(const bigint& bi) const{
    size_t count = parseShiftCount(bi._val);
    return (*this) >> static_cast<unsigned int>(count);
}

bigint& bigint::operator<<=(unsigned int y){
    *this = *this << y;
    return *this;
}
bigint& bigint::operator>>=(unsigned int y){
    *this = *this >> y;
    return *this;
}

bigint& bigint::operator<<=(const bigint& bi){
    *this = *this << bi;
    return *this;
}
bigint& bigint::operator>>=(const bigint& bi){
    *this = *this >> bi;
    return *this;
}


void bigint::print(std::ostream& os) const{
    for (size_t i = _val.size(); i-- > 0; )
        os << _val[i];
    os << '\n';
}

std::ostream& operator<<(std::ostream& os, const bigint& bi){
    bi.print(os);
    return os;
}
