#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <map>

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "]";
    return out;
}

template<typename T>
ostream& operator<< (ostream& out, const map<T, T>& m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        out << "[";
        out << it->first << ": " << it->second;
            out << "]";
            if(it != prev(m.end()))
                out << "\n";
    }
    return out;
}