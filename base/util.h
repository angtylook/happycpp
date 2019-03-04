#ifndef UTIL_H_
#define UTIL_H_
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    out << "[";
    std::ostream_iterator<T> out_iter(out, ", ");
    std::copy(v.begin(), v.end(), out_iter);
    out << "]";
    return out;
}

#endif  // UTIL_H_
