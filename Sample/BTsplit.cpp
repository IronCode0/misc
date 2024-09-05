#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};


vector<int> val;
int getSum(Node* root,Node* skip) {
    if (root == NULL || root == skip) return 0;
    int L = getSum(root->left, skip);
    int R = getSum(root->right, skip);
    if ( L &&  R) return (val[root->data] & L & R);
    if ( L && !R) return (val[root->data] & L);
    if (!L &&  R) return (val[root->data] & R);
    if (!L && !R) return val[root->data];
    return (val[root->data]);
}
int BTsplit(Node* root, Node* subroot) {
    int LU = getSum(root,subroot->left)
      , LD = getSum(subroot->left,NULL)
      , RU = getSum(root,subroot->right)
      , RD = getSum(subroot->right,NULL)
      , splitCount = (LU == LD) + (RU == RD);
    if (subroot->left)  splitCount +=BTsplit(root,subroot->left);
    if (subroot->right) splitCount +=BTsplit(root,subroot->right);
    return splitCount;
}



int main() {
    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->right = new Node(3);
    val = {5,5,7,5};
    cout << BTsplit(root,root) << endl;
    val = {3,7,3,3};
    cout << BTsplit(root,root) << endl;
    return 0;
}
