/**  @Author: Thiago Henrique Neves Coelho
  *  Date: 09/22/2017
  *  Algorithm: 2 Satisfiability Problem using Tarjan Algorithm for Strong Components
  *  This code is the solution for URI 1348 (X-Mart): https://www.urionlinejudge.com.br/judge/en/problems/view/1348
  */

/* Indexes for the graph are 2*idx + (false) */

#include <bits/stdc++.h>
#include <cstring>
#define pb push_back
#define vi vector<int>

using namespace std;

const int N = 3e4 + 50;

vi v[N];
int num, SC, top;
int stk[N], low[N], pre[N], sc[N];
bool stkB[N];

void DFSsc(int a) {
   low[a] = pre[a] = num++;
   stk[top++] = a;
   stkB[a] = true;
   for(int i = 0; i < v[a].size(); i++) {
      if(pre[v[a][i]] == -1) {
         DFSsc(v[a][i]);
         low[a] = min(low[a], low[v[a][i]]);
      }
      else if(stkB[v[a][i]]) low[a] = min(low[a], pre[v[a][i]]);
   }
   if(pre[a] == low[a]) {
      int u;
      do {
         u = stk[--top];
         sc[u] = SC;
         stkB[u] = false;
      }  while(u != a);
      SC++;
   }
}

void tarjan(int n) {
   num = top = SC = 0;
   memset(pre, -1, sizeof(int)*n);
   for(int i = 0; i < n; i++) {
      if(pre[i] == -1) DFSsc(i);
   }
}

bool sat(int n) {
   tarjan(n);
   for(int i = 0; i < n; i += 2)
      if(sc[i] == sc[i^1]) return false;
   return true;
}

int main(void) {
   int n, m;

   while(true) {
      scanf("%d %d", &n, &m);
      if(!n && !m) break;
      int a, b, c, d;
      for(int i = 0; i < n; i++) {
         scanf("%d %d %d %d", &a, &b, &c, &d);
         if(a == 0) a = b;
         if(b == 0) b = a;
         if(c == 0) c = d;
         if(d == 0) d = c;
         if(a != 0) {
            a = 2*(a-1);
            b = 2*(b-1);
            v[a^1].pb(b);
            v[b^1].pb(a);
         }
         if(c != 0) {
            c = 2*(c-1) + 1;
            d = 2*(d-1) + 1;
            v[c^1].pb(d);
            v[d^1].pb(c);
         }
      }
      if(sat(2*m)) puts("yes");
      else puts("no");
      for(int i = 0; i < 2*m; i++) v[i].clear();
   }


   return 0;
}
