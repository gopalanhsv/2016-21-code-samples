// System headers
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

// Local includes
#include "quickSort.h"

// Using declaration
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::sort;

// Statics, globals, typedefs

void
readInputVec(vector<int>& v) {
    v.clear();
    cout << "Enter elements to be sorted : " << endl;
    copy(
        istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
testMergeSort() {
    vector<int> v, testVec;
    readInputVec(v);
    cout << "Read input vector is : ";
    printVec(v);
    testVec = v;

    quickSort(v);
    sort(testVec.begin(), testVec.end());

    cout << "Sorted vector is : ";
    printVec(v);

    cout << "Hand written quicksort and std::sort results ";
    cout << ((v != testVec) ? "differ" : "same") << endl;
}

int
main() {
    testMergeSort();
    return 0;
}

