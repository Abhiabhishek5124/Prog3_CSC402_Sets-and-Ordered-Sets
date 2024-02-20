#ifndef MYSET_H
#define MYSET_H

#include <vector>
#include <iostream>
using namespace std;

class mySet {
protected:
    vector<int> elts;
    int size;

public:
    mySet();
    bool isempty();
    bool isfound(int x);
    bool addelt(int x);
    bool deleteelt(int x);
    int getsize();
    mySet Union(mySet& S);
    mySet Intersection(mySet& S);
    mySet Difference(mySet& S);

    // Getter for elts vector
    const vector<int>& getElts() const;

    // Setter for elts vector
    void setElts(const vector<int>& newElts);


    friend ostream& operator<<(ostream& ost, const mySet& S);
    bool operator==(mySet& other);
};

#endif //
