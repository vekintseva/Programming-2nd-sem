//
// Created by Виктория on 24.02.2022.
//

#include "integer.h"
using namespace std;

CSet::CSet() {
    for (int i = 0; i < 10; i++) {
        Set[i] = false;
    }
}

CSet::CSet(int i) {
    Set[i] = true;
}

bool operator==(const CSet &set1, const CSet &set2) {
    for (int i = 0; i < 10; i++) {
        if (set1[i] != set2[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const CSet &set1, const CSet &set2) {
    return !(set1 == set2);
}

bool CSet::operator[](int index) const {
    return Set[index];
}

bool& CSet::operator[](int index) {
    return Set[index];
}

CSet operator+( CSet set1, CSet set2) {
   for (int i=0;i<10;i++){
       if ((set1[i])&& (!set2[i])) {
           set2[i]=set1[i];
       }
   }
    return set2;
}

void operator+=(CSet & set, int x) {
    if (!set.Set[x]) {
        set.Set[x] = true; //если его нет, то мы его можем добавить, иначе нет, тк тогда будет 2 элемента
    }
}

void operator-=(CSet & set, int x) {
    if (set.Set[x]) {
        set.Set[x] = false; //если этот элемент есть, то мы его убираем, тк его быть не должно
    }
}

ostream &operator<<(std::ostream &out, const CSet & set) {
    out << "{ ";
    for (int i = 0; i < 10; i++) {
        if (set.Set[i]) {
            out << i << " ";
        }
    }
    out << "}" << endl;
    return out;
}


