#include "OrderedSet.h"
#include <algorithm>

using namespace std;

OrderedSet::OrderedSet(mySet S) {
    size = S.getsize();
    // Copy the elements from S using the getter method
    elts = S.getElts();
    // Sort the elements in the elts vector
    SortSet();
}

void OrderedSet::SortSet() {
    // Sort the elts vector
    sort(elts.begin(), elts.end());
}

bool OrderedSet::addelt(int x) {
    if (!isfound(x)) {
        elts.push_back(x);
        // Sort the elements after adding the new element
        SortSet();
        size++;
        return true;
    }
    return false;
}

ostream& operator<<(ostream& ost, const OrderedSet& OS) {
    if (OS.elts.size()==0) {
        ost << "Ordered Set is EMPTY"<<endl;
    } else {
        ost << "{ ";
        int count = 0;
        for (int i = 0; i < OS.elts.size(); ++i) {
            if (i == OS.elts.size() - 1) {
                ost << OS.elts[i];
            } else {
                ost << OS.elts[i] << " ,";
            }
            count++;
            if (count == 10 && i != OS.elts.size() - 1) {
                ost << "\n";
                count = 0;
            }
        }
        ost << " }";
        if (count != 0) {  // If count is not 0, meaning there are remaining elements
            ost << "\n";    // Move to the next line before printing the closing brace
        }
    }
    return ost;
}
