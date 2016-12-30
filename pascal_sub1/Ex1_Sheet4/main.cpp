#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

template<typename T>
vector<T> mergeVectors(vector<T> v1, vector<T> v2) {
    typename vector<T>::iterator v2first = v2.begin(), v2last = v2.end();
    while(v2first != v2last){
        v1.push_back(*v2first);
        v2first++;
    }
    return v1;
}

template<typename T>
set<T> mergeSets(set<T> s1, set<T> s2){
    typename set<T>::iterator s1first = s1.begin(), s1last = s1.end();
    while(s1first != s1last){
        s2.insert(*s1first);
        s1first++;
    }
    return s2;
}

template<typename T>
set<T> addVectorToSet(set<T> s, vector<T> v){
    typename vector<T>::iterator vfirst = v.begin(), vlast = v.end();
    while(vfirst != vlast){
        s.insert(*vfirst);
        vfirst++;
    }
    return s;
}

template<typename T>
vector<T> addSetToVector(vector<T> v, set<T> s){
    typename set<T>::iterator sfirst = s.begin(), slast = s.end();
    while(sfirst != slast){
        v.push_back(*sfirst);
        sfirst++;
    }
    return v;
}

template<typename T>
list<T> mergeLists(list<T> l1, list<T> l2){
    typename list<T>::iterator l2first = l2.begin(), l2last = l2.end();
    while(l2first != l2last){
        l1.push_back(*l2first);
        l2first++;
    }
    return l1;
}

template<typename T>
list<T> addVectorToList(list<T> l, vector<T> v){
    typename vector<T>::iterator vfirst = v.begin(), vlast = v.end();
    while(vfirst != vlast){
        l.push_back(*vfirst);
        vfirst++;
    }
    return l;
}

template<typename T>
list<T> addSetToList(list<T> l, set<T> s){
    typename set<T>::iterator sfirst = s.begin(), slast = s.end();
    while(sfirst != slast){
        l.push_back(*sfirst);
        sfirst++;
    }
    return l;
}

template<typename T>
vector<T> addListToVector(vector<T> v, list<T> l){
    typename list<T>::iterator lfirst = l.begin(), llast = l.end();
    while(lfirst != llast){
        v.push_back(*lfirst);
        lfirst++;
    }
    return v;
}

template<typename T>
set<T> addListToSet(set<T> s, list<T> l){
    typename list<T>::iterator lfirst = l.begin(), llast = l.end();
    while(lfirst != llast){
        s.insert(*lfirst);
        lfirst++;
    }
    return s;
}

int main() {
    vector<int> s1 = {1,2,3};
    list<int> s2 = {4,5,6};
    vector<int> v = addListToVector(s1,s2);
    for(vector<int>::iterator it = v.begin(); it!=v.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}