class Solution {
  public:
    vector<int> leftView(Node *root) {
        if (!root) return {};
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* cur = q.front(); q.pop();
                if (i == 0) res.push_back(cur->data);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }
}; 