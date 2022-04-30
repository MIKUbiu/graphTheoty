#include <bits/stdc++.h>
using namespace std;
const int maxn=101;;
int F[maxn];
int g[maxn][maxn];
struct Edge{
    int x,y,w;
    bool operator <(const Edge &e)const{
        return w<e.w;
    }
}edge[1000];
int Find(int n){
    return n==F[n]?n:F[n]=Find(F[n]);
}
bool Union(int x,int y){
    int nx=Find(x);
    int ny=Find(y);
    if(nx==ny)return false;
    F[nx]=ny;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        F[i]=i;
    }
    for(int i=0;i<m;i++){
        cin>>edge[i].x>>edge[i].y>>edge[i].w;
    }
    sort(edge,edge+m);//kruskal算法每次是选最小的边且不构成回路加入的边加入，所以要排序
    int tot=0;
    int cnt=0;
    for(int i=0;i<m;i++){
        if(!Union(edge[i].x,edge[i].y))continue;
        tot+=edge[i].w;
        cnt++;
        if(cnt==n-1)break;//访问全部顶点，只需合并n-1次
    }
    cout<<tot<<endl;
    return 0;
}
