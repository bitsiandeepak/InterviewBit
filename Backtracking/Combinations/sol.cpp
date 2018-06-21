class Solution {
    public:
        void combineHelper(vector<int> &current, int n, int k, vector<vector<int> > &ans) {
            if (k == 0) {
                vector<int> newEntry = current; 
                reverse(newEntry.begin(), newEntry.end());
                ans.push_back(newEntry);
                return;
            }
            if (n == 0 || n < k) return;
            // We have 2 options here. We can either include n or not. 
            // Option 1 : Do not include n.
            combineHelper(current, n - 1, k, ans);
            // Option 2 : Include n. 
            current.push_back(n);
            combineHelper(current, n - 1, k - 1, ans);
            current.pop_back();
            return;
        }

        vector<vector<int> > combine(int n, int k) {
            vector<vector<int> > ans; 
            vector<int> current;
            combineHelper(current, n, k, ans);
            sort(ans.begin(), ans.end());
            return ans;
        }
};
