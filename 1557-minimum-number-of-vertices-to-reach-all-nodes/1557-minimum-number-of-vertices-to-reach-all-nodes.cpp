class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
        vector<bool> inNodes;
        inNodes.reserve(n);
        for (int i = 0; i < n; i++) {
            inNodes.push_back(false);
        }
        for(vector<int> edge: edges) {
            inNodes[edge[1]] = true;
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(!inNodes.at(i))
                ans.push_back(i);
        }
        return ans;
    }
};