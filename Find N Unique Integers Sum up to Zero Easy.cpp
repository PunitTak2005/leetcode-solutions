#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        // Agar n odd hai toh 0 dal do
        if (n % 2 == 1) {
            result.push_back(0);
            n--;  // ab even bacha
        }
        // Pairs banao (-i, i)
        for (int i = 1; i <= n / 2; i++) {
            result.push_back(i);
            result.push_back(-i);
        }
        return result;
    }
};

int main() {
    Solution s;
    int n = 5;
    vector<int> ans = s.sumZero(n);
    
    cout << "[ ";
    for (int x : ans) cout << x << " ";
    cout << "]" << endl;
    return 0;
}
