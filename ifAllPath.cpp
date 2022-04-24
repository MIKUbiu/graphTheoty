#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int m,n;
const int maxn=101;
int g[maxn][maxn];
struct Edge{
    int x,y;
}E[1000];
int F[maxn];
int degree[maxn];
void Init(int n){
    for(int i=1;i<=n;i++)
        F[i]=i;
}
int Find(int n){
    return n==F[n]?n:F[n]=Find(F[n]);
}
bool Union(int x,int y){
    int nx=Find(x);
    int ny=Find(y);
    if(nx==ny)return false;
    F[ny]=nx;//根节点之间相互链接
    return true;
}
int main() {
    cin>>m>>n;
    int sx,sy;
    cin>>sx>>sy;
    Init(m);
    for(int i=1;i<=n;i++)
    {
        cin>>E[i].x>>E[i].y;
        degree[E[i].x]++;
        degree[E[i].y]++;
        Union(E[i].x,E[i].y);
    }
    int odd=0;//统计度数为奇数的定点个数
    for(int i=1;i<=m;i++){
        if(degree[i]&1)odd++;
    }
    if(!Union(sx,sy)&&odd==0)cout<<"YES"<<endl;
    else if(!Union(sx,sy)&&odd==2&&degree[sx]&1&&degree[sy]&1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}
