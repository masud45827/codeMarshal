#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
ll ar[2000004];
vl pr;
ll fun(ll x, ll m, ll c) {
  vl v;
  ll i, j;
  for (i = 0; pr[i]*pr[i] <= c; i++) {
    if (c % pr[i] == 0) {
      while (c % pr[i] == 0) {
        c /= pr[i];
      }
      v.pb(pr[i]);
    }
  }
  if (c != 1) v.pb(c);
  ll n = v.size();
  ll ans = 0;
  for (i = 1; i < (1 << n); i++) {
    ll mul = 1;
    ll c = 0;
    for (j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        c++;
        mul *= v[j];
      }
    }
    ll delta = (x + m) / mul - (x - 1) / mul ;
    if (c % 2) ans += delta;
    else ans -= delta;
  }
  return m + 1 - ans;
}
int main() {
  int t = 1, fac = 1;
  ll n = 1000005, i, j;
  for (i = 2; i * i <= n; i++) {
    for (j = i * i; j <= n; j += i) {
      ar[j] = 1;
    }
  }
  for (i = 2; i <= n; i++) {
    if (!ar[i]) {
      pr.pb(i);
    }
  }
  scanf("%d", &t);
  while (t--) {
    ll x, y, a, b, k, m, c;
    scanf("%lld %lld %lld", &a, &b, &m);
    printf("Case %d: ", fac);
    fac++;
    if (a <= b) swap(a, b);
    c = a - b;
    if (c == 0) {
      if (a == 1) printf("1\n");
      else printf("0\n");
      continue;
    }
    ll ans = fun(b, m, c);
    printf("%lld\n", ans);
  }
}

