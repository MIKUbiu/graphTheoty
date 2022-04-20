#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
const int maxn = 101;
int F[maxn];
//第一行有两个整数n, m。
//n(0 < n < 100)表示有n个英雄；m(0 < m < 100)表示接下来有m行数据。
//	接下来m行，每行都有两个整数a, b。表示a，b英雄在同一个阵营。在默认情况下，任意两个英雄不在同一阵营。
int Find(int a) {
	if (a == F[a])return a;
	else return F[a] = Find(F[a]);//路径压缩让F[a]=根节点的值
}
bool Union(int a, int b) {
	int na = Find(a);
	int nb = Find(b);
	if (na == nb)return false;
	F[nb] = na;//让b的根节点=a的根节点???一定不是F[b]=na;这样只是把b的节点连接到a的根节点
	return true;
}
int count(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (F[i] == i)cnt++;
	}
	return cnt;
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++)
			F[i] = i;
		while (m--) {
			int a, b;
			cin >> a >> b;
			Union(a, b);
		}
		for (int i = 1; i <= n; i++) {
			cerr << F[i] << "->" << i << endl;
		}
		cout << count(n) << endl;
	}
	return 0;
}
