class Solution {
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, vector<TreeNode*>& leafs, TreeNode* node) {
        if (!root) return;
        
        if (!root->left && !root->right) 
            leafs.push_back(root);
        
        markParent(root->left, parent, leafs, root);
        markParent(root->right, parent, leafs, root);

        if(node != NULL) parent[root] = node;
    }
    
    int bfs(TreeNode* leaf, unordered_map<TreeNode*, TreeNode*>& parent, int distance) {
        unordered_map<TreeNode*, bool> vis;
        queue<pair<TreeNode*, int>> q;
        q.push({leaf, 0});
        vis[leaf] = true;
        int cnt = 0;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist > distance) break;

            // Count only other leaf nodes (excluding itself)
            if (dist > 0 && !node->left && !node->right) 
                cnt++;

            // Visit neighbors
            if (node->left && !vis[node->left]) {
                vis[node->left] = true;
                q.push({node->left, dist + 1});
            }
            if (node->right && !vis[node->right]) {
                vis[node->right] = true;
                q.push({node->right, dist + 1});
            }
            if (parent[node] && !vis[parent[node]]) {
                vis[parent[node]] = true;
                q.push({parent[node], dist + 1});
            }
        }
        
        return cnt;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> leafs;

        TreeNode* dummy = NULL;
        markParent(root, parent, leafs, dummy);
        int cnt = 0;

        for (int i = 0; i < leafs.size(); i++) {
            cnt += bfs(leafs[i], parent, distance);
        }

        // Since every pair is counted twice, divide by 2
        return cnt / 2;
    }
};
