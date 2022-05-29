#include "algo.h"
#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main() {
    vector<int> a{1, 2, 3, 4};
    vector<int> b{1, 2, 3, 4, 2};
    vector<int> c{4, 3, 2, 1, 0};
    vector<int> e{1, 2, 3, 4, 3, 2, 1};
    vector<int> f{1, 2, 3, 4, 3, 2, 3};
    vector<int> e1{1, 2, 3, 3, 2, 1};
    vector<int> f1{1, 2, 3, 4, 2, 1};
    vector<pair<int, int>> h{{1, 2},
                             {2, 3},
                             {3, 4}};

    vector<int> g{1};
    set<int> s{1, 2, 3};

cout<<"ANYOF:"<<endl;
    cout<<((anyOf(a.begin(), a.end(), [](int x) { return x == 3; }))? "TRUE" : "FALSE")<<endl;
    cout<<((anyOf(a.begin(), a.end(), [](int x) { return x == 5; }))? "TRUE" : "FALSE")<<endl;
    cout<<"\n";

    cout<<"NoneOf"<<endl;
   cout<<((noneOf(a.begin(), a.end(), [](int x) { return x > 5; }))? "TRUE" : "FALSE")<<endl;
   cout<<((!noneOf(a.begin(), a.end(), [](int x) { return x >= 3; }))? "TRUE" : "FALSE")<<endl;
    cout<<"\n";

cout<<"isSorted:"<<endl;
    cout<<((isSorted(a.begin(), a.end(), [](int x, int y) { return x < y; }))? "TRUE" : "FALSE")<<endl; //+
    cout<<((!isSorted(b.begin(), b.end(), [](int x, int y) { return x < y; }))? "TRUE" : "FALSE")<<endl; //-
    cout<<((isSorted(a.begin(), a.end()))? "TRUE" : "FALSE")<<endl; //+
    cout<<((!isSorted(b.begin(), b.end()))? "TRUE" : "FALSE")<<endl; //-
    cout<<((isSorted(c.begin(), c.end(), [](int x, int y) { return x > y; }))? "TRUE" : "FALSE")<<endl; //+
    cout<<((isSorted(h.begin(), h.end(), [](pair<int, int> x, pair<int, int> y) { return x < y; }))? "TRUE" : "FALSE")<<endl; //+
    cout<<"\n";

cout<<"isPalindrom:"<<endl;
    cout<<((isPalindrome(e.begin(), e.end(), [](int x, int y) { return x == y; }))? "TRUE" : "FALSE")<<endl;
    cout<<((!isPalindrome(f.begin(), f.end(), [](int x, int y) { return x == y; }))? "TRUE" : "FALSE")<<endl;
    cout<<((isPalindrome(e1.begin(), e1.end(), [](int x, int y) { return x == y; }))? "TRUE" : "FALSE")<<endl;
    cout<<((isPalindrome(f1.begin(), f1.end(), [](int x, int y) { return x == y; }))? "TRUE" : "FALSE")<<endl;
    cout<<((isPalindrome(s.begin(), s.end(), [](int x, int y) { return x + y > 0; }))? "TRUE" : "FALSE")<<endl;
    cout<<((isPalindrome(g.begin(), g.end(), [](int x, int y) { return x == y; }))? "TRUE" : "FALSE")<<endl;



    return 0;
}

//any_of - возвращает true, если хотя бы один из элементов диапазона удовлетворяет некоторому предикату. Иначе false

//none_of - возвращает true, если все элементы диапазона не удовлетворяют некоторому предикату. Иначе false

//is_sorted - возвращает true, если все элементы диапазона находятся в отсортированном порядке относительно некоторого критерия

//is_palindrome - возвращает true, если заданная последовательность является палиндромом относительно некоторого условия. Иначе false.