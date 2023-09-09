#include <bits/stdc++.h>
#define loc(x, y) ((x - 1) * m + y)
#define lowbit(x) (x & -x)
using namespace std;
typedef long long ll;
const int N = 1e6 + 5, INF = 0x3f3f3f3f;
const double PI = acos(-1), EPS = 1e-5;
const ll mod = 998244353, G = 3, Gi = 332748118;
namespace fast_IO {
    // char getchar() {
    //     static const int IN_LEN = 1 << 18 | 1;
    //     static char buf[IN_LEN], *s, *t;
    //     return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    // }
    ll read() {
        ll num = 0;
        char c;
        bool tag = false;
        while ((c = getchar()) != '-' && c != '+' && (c < '0' || c > '9') && ~c);
        if (!~c)return EOF;
        if (c == '-')tag = true;
        else if (c == '+')tag = false;
        else num = c ^ 48;
        while ((c = getchar()) >= '0' && c <= '9')
            num = (num << 1) + (num << 3) + (c ^ 48);
        if (tag)return -num;
        return num;
    }
    void write(ll x) {
        if (x < 0)putchar('-'), x = -x;
        if (x >= 10)write(x / 10);
        putchar(x % 10 ^ 48);
    }
}
char s[N];
int nt[N], sz[N];
vector<int>to[N];
void getnt(int n) {
    nt[0] = -1; nt[1] = 0;
    for (int i = 2; i <= n; ++i) {
        nt[i] = nt[i - 1];
        while (nt[i] && s[i] != s[nt[i] + 1])
            nt[i] = nt[nt[i]];
        if (s[i] == s[nt[i] + 1])++nt[i];
    }
}
void dfs(int x) {
    sz[x] = 1;
    for (auto y : to[x]) {
        dfs(y);
        sz[x] += sz[y];
    }
}
 
int main() {
    int n = fast_IO::read(), k = fast_IO::read();
    scanf("%s", s + 1);
    getnt(n);
    for (int i = 1; i <= n; ++i)
        to[nt[i]].push_back(i);
    dfs(0);
    int ans = 0;
    for (int i = n; i; i = nt[i])
        if (sz[i] >= k) {
            ans = i;
            break;
        }
    if (ans == 0) {
        puts("-1");
    }
    else {
        s[ans + 1] = 0;
        puts(s + 1);
    }
    return 0;
}