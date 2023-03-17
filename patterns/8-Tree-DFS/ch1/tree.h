#ifndef _TREE_H_
#define _TREE_H_

// System headers

// Local includes

// Using declarations

// Statics, typedefs, globals

class TreeNode {
public:
    // Constructor
    TreeNode(int v) : _val(v), _lChildP(nullptr), _rChildP(nullptr) {}

    // Accessors
    inline int value() const { return _val; }
    inline TreeNode* left() const { return _lChildP; }
    inline TreeNode* right() const { return _rChildP; }

    inline void setVal(int v) { _val = v; }
    inline void setLeft(TreeNode* t) { _lChildP = t; }
    inline void setRight(TreeNode* t) { _rChildP = t; }

private:
    TreeNode();

    // Data members
    int _val;
    TreeNode* _lChildP;
    TreeNode* _rChildP;
};

class Tree {
public:
    static unsigned int treeDiameter(TreeNode* root);
private:
    static unsigned int computeSubtreeHeightRec(TreeNode* tNode);
};

#endif /* _TREE_H_ */
