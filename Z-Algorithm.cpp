/**  @Author: Thiago Henrique Neves Coelho
  *  Date: 09/25/2017
  *  Algorithm: Z-Algorithm
  */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;

string str[N];
int z[N];

void z_alg(string v, int z[], int n) {
	z[0] = 0;
	int l = 0, r = 0;
	for(int i = 1; i < n; i++) {
		if(i > r) {
			l = r = i;
			while(r < n && v[r] == v[r-l]) r++;
			z[i] = r - l;
			r--;
		}
		else {
			z[i] = min(z[i-l], r - i + 1);
			if(i + z[i] < n && v[i+z[i]] == v[z[i]]) {
				l = i;
				r = i + z[i];
				while(r < n && v[r] == v[r-l]) r++;
				z[i] = r - l;
				r--;
			}
		}
	}
}

int main(void) {


	return 0;
}