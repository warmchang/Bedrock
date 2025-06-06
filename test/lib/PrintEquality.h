#pragma once

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <list>
#include <optional>

using namespace std;

template<typename T>
ostream& operator<<(ostream& output, const list<T>& val)
{
    return output << "[" << SComposeList(val) << "]";
}

template<typename T>
ostream& operator<<(ostream& output, const set<T>& val)
{
    return output << "[" << SComposeList(val) << "]";
}

template<typename T, typename U>
ostream& operator<<(ostream& output, const map<T, U>& val)
{
    output << "[Map] {" << endl;
    for (const auto& [k, v] : val) {
        output << k << ": " << v << endl;
    }
    return output << "}";
}

template<typename T>
ostream& operator<<(ostream& output, const std::optional<T>& val)
{
    if (val.has_value()) {
        return output << val.value();
    }

    return output << "(nullopt)";
}

class PrintEquality {
    public:
        template <typename U, typename V>
        PrintEquality(const U& a, const V& b, bool isEqual) {
            cout << a << " " << (isEqual ? "=" : "!") << "= " << b << "\n";
        }
};
