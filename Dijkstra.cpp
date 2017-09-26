/**  @Author: Thiago Henrique Neves Coelho
  *  Date: 09/25/2017
  *  Algorithm: Dijkstra Algorithm for minimun paths
  */

#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const ll N = 100;

vii v[N];
ll dist[N], mrc[N];

void dijkstra(int o, int n) {
	memset(dist,INF,sizeof(ll)*(n+1));
	memset(mrc,0,sizeof(int)*(n+1));
	set<ii> av;
	set<ii>::iterator it;
	av.insert(mp(0, o));
	while(!av.empty()) {
		it = av.begin();
		if(it->f < dist[it->s]) dist[it->s] = it->f;
		if(mrc[it->s] == 1) {av.erase(it); continue;}
		mrc[it->s] = 1;
		for(int i = 0; i < v[it->s].size(); i++) av.insert(mp(dist[it->s] + (ll)v[it->s][i].s, (ll)v[it->s][i].f));
		av.erase(it);
	}
}


int main(void){


	return 0;
}
