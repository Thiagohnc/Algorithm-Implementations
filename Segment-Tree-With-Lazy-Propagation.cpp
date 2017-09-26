/**  @Author: Thiago Henrique Neves Coelho
  *  Date: 09/25/2017
  *  Algorithm: Segment Tree with Lazy Propagation
  */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAXN = 3e5;

ll v[MAXN], st[3*MAXN], lt[3*MAXN];

ll minl(ll a, ll b) {
	if(a < b) return a;
	return b;
}

void propagate(ll lt[], ll st[], ll idx, ll l, ll r) {
	ll lc = 2*idx + 1;
	ll rc = 2*idx + 2;

	st[idx] += lt[idx];
	if(l != r) {
		lt[rc] += lt[idx];
		lt[lc] += lt[idx];
	}
	lt[idx] = 0;
}

ll build(ll st[], ll lt[], ll v[], ll idx, ll l, ll r) {
	ll mid = (l + r)/2;
	ll lc = 2*idx + 1;
	ll rc = 2*idx + 2;
	
	lt[idx] = 0;
	if(l == r) return st[idx] = v[l];
	
	return st[idx] = minl(build(st, lt, v, lc, l, mid), build(st, lt, v, rc, mid + 1, r));
}

ll update(ll st[], ll lt[], ll v[], ll val, ll i, ll idx, ll l, ll r) {
	ll mid = (l + r)/2;
	ll lc = 2*idx + 1;
	ll rc = 2*idx + 2;
	
	propagate(lt, st, idx, l, r);
	
	if(l == r) return st[idx] = v[i] = val;
	
	propagate(lt, st, lc, l, mid);
	propagate(lt, st, rc, mid + 1, r);
	
	if(i <= mid) return st[idx] = minl(update(st, lt, v, val, i, lc, l, mid), st[rc]);
	if(i > mid) return st[idx] = minl(st[lc], update(st, lt, v, val, i, rc, mid + 1, r));
	return st[idx] = minl(update(st, lt, v, val, i, lc, l, mid), update(st, lt, v, val, i, rc, mid + 1, r));
}

ll query(ll st[], ll lt[], ll idx, ll l, ll r, ll a, ll b) {
	ll mid = (l + r)/2;
	ll lc = 2*idx + 1;
	ll rc = 2*idx + 2;
	
	propagate(lt, st, idx, l, r);
	
	if(a <= l && b >= r) return st[idx];
	
	if(b <= mid) return query(st, lt, lc, l, mid, a, b);
	if(a > mid) return query(st, lt, rc, mid + 1, r, a, b);
	return minl(query(st, lt, lc, l, mid, a, b), query(st, lt, rc, mid + 1, r, a, b));
}

void rupdate(ll st[], ll lt[], ll val, ll idx, ll l, ll r, ll a, ll b) {
	ll mid = (l + r)/2;
	ll lc = 2*idx + 1;
	ll rc = 2*idx + 2;
	
	if(a <= l && b >= r) lt[idx] += val;

	propagate(lt, st, idx, l, r);
	propagate(lt, st, lc, l, mid);
	propagate(lt, st, rc, mid + 1, r);

	if(a <= l && b >= r) return;
	
	if(b <= mid) rupdate(st, lt, val, lc, l, mid, a, b);
	else if(a > mid) rupdate(st, lt, val, rc, mid + 1, r, a, b);
	else if(a > l || b <= r) {
		rupdate(st, lt, val, lc, l, mid, a, b);
		rupdate(st, lt, val, rc, mid + 1, r, a, b);
	}
	
	st[idx] = minl(st[lc], st[rc]);
}

int main(void) {
	
	return 0;
}