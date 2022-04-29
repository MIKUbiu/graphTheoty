#include <bits/stdc++.h>

using namespace std;
const int maxn=51;
const int INF=1<<20;
int a[maxn];
int g[maxn][maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)a[i]=i;//初始化下标数组
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)cin>>g[i][j];
    int best=INF;
    do{
        int tot=0;
        for(int i=0;i<n;i++)
        tot+=g[a[i]][a[(i+1)%n]];//i+1表示下个城市   %n防止数组越界，并且回到最初的位置
        if(tot<best)best=tot;
    }while(next_permutation(a+1,a+n));//从a+1开始，没必要每次都从一个新的城市开始计算，因为是一个环，无论是从哪个位置开始，只要访问点的顺序在环上相同，最后距离都是一样的
    cout<<best;
    return 0;
}
