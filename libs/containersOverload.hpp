#pragma once

#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        os << *it << ", ";
    }
    if (!v.empty()) {
        os << "\b\b";
    }
    os << "]";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        os << *it << ", ";
    }
    if (!v.empty()) {
        os << "\b\b";
    }
    os << "]";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        os << *it << ", ";
    }
    if (!v.empty()) {
        os << "\b\b";
    }
    os << "]";
    return os;
}

