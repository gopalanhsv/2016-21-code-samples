// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>

// Local includes
#include "tree.h"

// Using declarations
using std::vector;
using std::cout;
using std::endl;
using std::domain_error;
using std::copy;
using std::ostream_iterator;

// Statics, typedefs, globals

void
printVecOfVec(const vector<vector<int> >& vOfV) {
    cout << endl;
    for (auto v : vOfV) {
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

void
testFn(TreeNode* tree) {
    try {
        vector<vector<int> > bfsVec = Tree::levelOrderTraverse(tree);
        cout << "Level Order Traversal Output is: ";
        printVecOfVec(bfsVec);
    } catch (domain_error& e) {
        throw e;
    }
}

TreeNode*
constructTestTree1() {

    TreeNode *root, *left, *right;
    root = new TreeNode(1);
    left = new TreeNode(2);
    right = new TreeNode(3);
    root->setLeftChild(left);
    root->setRightChild(right);

    left->setLeftChild(new TreeNode(4));
    left->setRightChild(new TreeNode(5));

    right->setLeftChild(new TreeNode(6));
    right->setRightChild(new TreeNode(7));

    return root;
}

void
testFn1() {
    TreeNode* root = constructTestTree1();
    try {
        testFn(root);
    } catch (domain_error& e) {
        throw e;
    }
}

TreeNode*
constructTestTree2() {

    TreeNode *root, *left, *right;
    root = new TreeNode(12);
    left = new TreeNode(7);
    right = new TreeNode(1);
    root->setLeftChild(left);
    root->setRightChild(right);

    left->setRightChild(new TreeNode(9));

    right->setLeftChild(new TreeNode(10));
    right->setRightChild(new TreeNode(5));

    return root;
}

void
testFn2() {
    TreeNode* root = constructTestTree2();
    try {
        testFn(root);
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        testFn1();
        testFn2();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
