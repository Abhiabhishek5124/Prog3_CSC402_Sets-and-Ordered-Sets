#include "mySet.h"
#include <algorithm>
using namespace std;

mySet::mySet() : size(0) {
}

const vector<int>& mySet::getElts() const {
    return elts;
}

int mySet::getsize() {
    return size;
}

bool mySet::isempty() {
    return size == 0;
}

bool mySet::isfound(int x) {
    return find(elts.begin(), elts.end(), x) != elts.end();
}

bool mySet::addelt(int x) {
    if (!isfound(x)) {
        // Insert the element at the beginning of the vector
        elts.insert(elts.begin(), x);
        size++;
        return true;
    }
    return false;
}




bool mySet::deleteelt(int x) {
    // Find the iterator pointing to the element x
    auto it = find(elts.begin(), elts.end(), x);

    // Check if the element x exists in the set
    if (it != elts.end()) {
        // If found, erase the element
        elts.erase(it);
        // Decrease the size of the set
        size--;
        // Return true to indicate successful deletion
        return true;
    }
    // If element x is not found, return false
    return false;
}



mySet mySet::Union(mySet& S) {
    mySet temp;
    for (int i : elts) //for (int i : this->elts)
        temp.addelt(i);
    for (int j : S.elts)
        temp.addelt(j);
    return temp;
}

mySet mySet::Intersection(mySet& S) {
    mySet temp;
    for (int i : elts) {
        if (S.isfound(i))
            temp.addelt(i);
    }
    return temp;
}

mySet mySet::Difference(mySet& S) {
    mySet temp;
    for (int i : elts) {
        if (!S.isfound(i))
            temp.addelt(i);
    }
    return temp;
}


bool mySet::operator==(mySet& other) {
    if (size != other.size)
        return false;

    vector<int> temp_elts = other.elts;
    for (int i : elts) {
        auto it = find(temp_elts.begin(), temp_elts.end(), i);
        if (it == temp_elts.end())
            return false;
        temp_elts.erase(it);
    }
    return true;
}
