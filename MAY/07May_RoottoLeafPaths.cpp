class Solution {
  public:
    void dfs(Node* node, vector<int>& currentPath, vector<vector<int>>& allPaths) {
        if (node == NULL) return;

        currentPath.push_back(node->data);

        if (node->left == NULL && node->right == NULL) {
            allPaths.push_back(currentPath);
        } else {
            dfs(node->left, currentPath, allPaths);
            dfs(node->right, currentPath, allPaths);
        }

        currentPath.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        dfs(root, currentPath, allPaths);
        return allPaths;
    }
};
