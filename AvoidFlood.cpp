#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);  // Default: dry lake 1 on dry days
        unordered_map<int, int> full;  // lake -> last day it rained
        set<int> dryDays;  // indices of days with 0 (can dry on these)

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);  // store dry day
            } else {
                int lake = rains[i];
                ans[i] = -1;  // raining day

                if (full.find(lake) != full.end()) {
                    // lake already full, find a dry day after last rain
                    int lastRain = full[lake];
                    auto it = dryDays.upper_bound(lastRain);
                    if (it == dryDays.end()) {
                        return {}; // no valid dry day → flood
                    }
                    ans[*it] = lake;  // dry this lake
                    dryDays.erase(it);
                }
                full[lake] = i;  // update last rain day
            }
        }

        return ans;
    }
};
