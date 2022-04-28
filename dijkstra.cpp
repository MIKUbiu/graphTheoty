#include <bits/stdc++.h>

using namespace std;
//输入的第一行包含2个正整数n和s，表示图中共有n个顶点，且源点为s。其中n不超过50，s小于n。
//以后的n行中每行有n个用空格隔开的整数。对于第i行的第j个整数，如果大于0，则表示第i个顶点有指向第j个顶点的有向边，且权值为对应的整数值；如果这个整数为0，则表示没有i指向j的有向边。当i和j相等的时候，保证对应的整数为0。



const int INF = 1 << 20;
const int maxn = 101;
int g[maxn][maxn];
int S[maxn];//记录已添加到路径中的点
int dist[maxn];//保存各点到源点的距离
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream cin("E.in");
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int T;
            cin >> T;
            if (i != j && T == 0) {
                g[i][j] = INF;
            } else g[i][j] = T;
        }
    }
    for (int i = 0; i < n; i++) {
        dist[i] = g[s][i];//初始化dist数组
    }
    S[s] = 1;
    for (int i = 0; i < n; i++) {
        int mindis = INF;//保存未选择的点到已选择的点最短距离
        int u;
        for (int j = 0; j < n; j++) {
            if (!S[j] && dist[j] < mindis) {
                mindis = dist[j];
                u = j;
            }
        }
        //把u加入S,并通过u点更新dist数组
        S[u] = 1;
        for (int j = 0; j < n; j++) {
            if (!S[j] && dist[j] > dist[u] + g[u][j])
                dist[j] = dist[u] + g[u][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == s)continue;
        if (dist[i] == INF) { cout << -1 << " "; }
        else cout << dist[i] << " ";
    }
    return 0;
}
