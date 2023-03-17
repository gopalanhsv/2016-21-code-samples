// System headers
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// Local includes
#include "linkedList.h"

// Using declarations
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::back_inserter;
using std::copy;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(v));
}

LLNode*
convertVecToList(const vector<int>& v) {
    if (v.empty()) {
        return nullptr;
    }

    LLNode* head = new LLNode(v[0]);
    LLNode* node = head;
    for (vector<int>::size_type i = 1; i != v.size(); ++i) {
        node->setNext(new LLNode(v[i]));
        node = node->next();
    }
    return head;
}

void
printList(LLNode* head) {
    cout << endl;
    while (head != nullptr) {
        cout << head->value() << "-->";
        head = head->next();
    }
    cout << "null" << endl;
}

void
testFn() {
    vector<int> v;
    readVec(v);
    LLNode* llist = convertVecToList(v);
    cout << "Original linked list is : ";
    printList(llist);

    llist = LinkedList::rearrange(llist);
    cout << "Rearranged linked list is : ";
    printList(llist);
}

int
main() {
    testFn();
    return 0;
}
