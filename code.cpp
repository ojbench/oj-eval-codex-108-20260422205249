#include <bits/stdc++.h>
using namespace std;

// Bounded knapsack using binary splitting + 1D DP
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<int> w, v;
    w.reserve(200000); v.reserve(200000);

    for(int i=0;i<n;++i){
        int p, wi, vi; cin >> p >> wi >> vi;
        // binary split p into sums of powers of two
        for(int k=1; p>0; k<<=1){
            int take = min(k, p);
            p -= take;
            w.push_back(wi * take);
            v.push_back(vi * take);
        }
    }

    vector<long long> dp(m+1, 0);
    for(size_t i=0;i<w.size();++i){
        int wi = w[i];
        long long vi = v[i];
        for(int j=m; j>=wi; --j){
            dp[j] = max(dp[j], dp[j-wi] + vi);
        }
    }

    cout << dp[m] << '\n';
    return 0;
}
