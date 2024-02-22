class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for (int i = 0; i < 26; i++) parent[i] = i;
        for (string s : equations) {
            if (s[1] == '=') {
                int x = find(parent, s[0] - 'a');
                int y = find(parent, s[3] - 'a');
                parent[x] = y;
            }
        }
        for (string s : equations) {
            if (s[1] == '!') {
                int x = find(parent, s[0] - 'a');
                int y = find(parent, s[3] - 'a');
                if (x == y) return false;
            }
        }
        return true;
    }
    int find(vector<int>& parent, int i) {
        if (parent[i] != i) parent[i] = find(parent, parent[i]);
        return parent[i];
    }
};