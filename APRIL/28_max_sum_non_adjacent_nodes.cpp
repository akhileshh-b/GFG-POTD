// 28. Maximum Sum of Non-Adjacent Nodes
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    pair<int,int> solve(Node* root) {
        if (!root) return {0,0};
        auto l = solve(root->left), r = solve(root->right);
        return {root->data + l.second + r.second, max(l.first,l.second) + max(r.first,r.second)};
    }
    int getMaxSum(Node* root) {
        auto p = solve(root);
        return max(p.first, p.second);
    }
};