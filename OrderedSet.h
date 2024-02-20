#ifndef UNTITLED_ORDEREDSET_H
#define UNTITLED_ORDEREDSET_H

#include "mySet.h"
#include <iostream> // Include <iostream> for ostream

using namespace std;
class OrderedSet : public mySet {
public:
    OrderedSet() = default;
    OrderedSet(mySet S);

    void SortSet();
    bool addelt(int x);

    friend ostream& operator<<(ostream& ost, const OrderedSet& OS); // Added  for ostream
};

#endif