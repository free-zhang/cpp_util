//
// Created by jackffzhang on 2019/10/1.
//

#ifndef CLION_TEST_MAP_UTIL_H
#define CLION_TEST_MAP_UTIL_H

#include <map>

using  namespace std;

template <typename T1, typename T2>
inline bool inMap(const T1& key, const map<T1, T2>& m){
    return m.find(key) != m.cend();
}

#endif //CLION_TEST_MAP_UTIL_H

