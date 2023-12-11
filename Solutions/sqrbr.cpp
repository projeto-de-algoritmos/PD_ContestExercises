#include <bits/stdc++.h>
using namespace std;
long long mat[50][50];

long long pd(long long i, long long open, long long n, set<long long> xs){
    long long ans;
    if (i == n) return open ? 0 : 1;
    if (mat[i][open] != -1) return mat[i][open];

    ans = pd(i + 1, open + 1, n, xs);
    if (xs.count(i) == 0 and open) ans += pd(i + 1, open - 1, n, xs);
    mat[i][open] = ans;
    return ans;
}
long long solve(long long n, set<long long> xs){
    memset(mat, -1, sizeof mat);
    return pd(0, 0, 2 * n, xs);
}
int main(){
    long long t, n, k;
    cin >> t;

    while (t--){
        cin >> n >> k;
        set<long long> xs;
        for (int i = 0; i < k; i++){
            int x;
            cin >> x;
            xs.insert(x - 1);
        }
        cout << solve(n, xs) << '\n';
    }
    return 0;
}