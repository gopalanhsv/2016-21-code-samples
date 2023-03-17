// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "tree.h"

// Using declarations
using std::cout;
using std::endl;
using std::domain_error;

// Statics, typedefs, globals

void
testFn(TreeNode* tree, int tId) {
    cout << endl;
    unsigned long mps = Tree::treeMaxPathSum(tree);
    cout << "max path sum for tree #"
        << tId << " = " << mps << endl;
}

TreeNode*
constructTree1() {
    TreeNode *root, *left, *right;

    root = new TreeNode(1);
    left = new TreeNode(2);
    right = new TreeNode(3);
    root->setLeft(left);
    root->setRight(right);

    left->setLeft(new TreeNode(4));

    right->setLeft(new TreeNode(5));
    right->setRight(new TreeNode(6));

    return root;
}

TreeNode*
constructTree2() {
    TreeNode *tNode, *root, *left, *right;

    tNode = root = new TreeNode(1);
    left = new TreeNode(2);
    right = new TreeNode(3);
    tNode->setLeft(left);
    tNode->setRight(right);

    left->setLeft(new TreeNode(1));
    left->setRight(new TreeNode(2));

    right->setLeft(new TreeNode(5));
    right->setRight(new TreeNode(6));

    right->left()->setLeft(new TreeNode(7));
    right->left()->setRight(new TreeNode(8));

    right->right()->setRight(new TreeNode(9));

    return root;
}

void
test() {
    TreeNode *tree1, *tree2;
    tree1 = constructTree1();
    tree2 = constructTree2();
    try {
        testFn(tree1, 1);
        testFn(tree2, 2);
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        test();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
