/**  @Author: Thiago Henrique Neves Coelho
  *  Date: 09/25/2017
  *  Algorithm: Minimun Paths in a tree using Lowest Common Ancestor
  */

#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define ii pair<int,int>
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f

using namespace std;

const int MAXN = 1e5 + 50;
const int LOGMAX = 25;

int vd[MAXN][LOGMAX], dad[MAXN], mrc[MAXN];
vi v[MAXN];

void dfs(int a, int pai, int lvl) {
	mrc[a] = lvl;
	dad[a] = pai;
	for(int i = 0; i < v[a].size(); i++) if(mrc[v[a][i]] == 0) dfs(v[a][i], a, lvl + 1);
}

void build(int n) {
	dfs(0, 0, 1);
	for(int i = 0; i < n; i++) vd[i][0] = dad[i];
	for(int j = 1; j < LOGMAX; j++) {
		for(int i = 0; i < n; i++) {
			vd[i][j] = vd[vd[i][j-1]][j-1];
		}
	}
}

int dist(int a, int b) {
	int d = 0;
	if(mrc[a] > mrc[b]) swap(a, b);
	for(int i = LOGMAX - 1; i >= 0; i--) {
		if(mrc[vd[b][i]] > mrc[a]) {
			b = vd[b][i];
			d += 1 << i;
		}
	}
	if(mrc[b] != mrc[a]) {
		d++;
		b = vd[b][0];
	}

	for(int i = LOGMAX - 1; i >= 0; i--) {
		if(vd[b][i] != vd[a][i]) {
			a = vd[a][i];
			b = vd[b][i];
			d += 2*(1 << i);
		}
	}
	if(b != a) d += 2;
	return d;
}

int main(void) {


	return 0;
}
