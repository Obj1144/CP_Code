#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 998244353;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
 
  int64_t ans = 1;
  for (int i = 1; i < n && ans;i++) {
    if (a[i - 1] % a[i]) {
      ans = 0;
    }
    else {
      int t = a[i - 1] / a[i];
      int up = m / a[i];
      ans %= P;
      if (t == 1) {
        ans *= up;
        continue;
      }
 
      vector<int> f;
      for (int j = 2; j * j <= t; j++) {
        if (t % j) continue;
        while (t % j == 0) {
          t /= j;
        }
        f.push_back(j);
      }
      if (t != 1) f.push_back(t), t = 1;
      if (f.size() == 1 && t == 1) {
        ans *= up - up / f[0];
        continue;
      }
 
      // t不是素数
      int64_t sum = 0;
      for (int i = 1; i < (1 << f.size()); i++) {
        int cnt = 0;
        int64_t curu = up;
        for (int j = 0; j < f.size(); j++) {
          if (i & (1 << j)) {
            curu /= f[j];
            cnt++;
          }
        }
        if (cnt & 1) sum -= curu;
        else sum += curu;
      }
      ans *= up - abs(sum);
    }
  }
  cout << ans % P << "\n" << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
    int tt;
    cin>>tt;
    while(tt--){
      solve();
    }
    return 0;
}