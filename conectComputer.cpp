#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int maxn=501;
int F[maxn];
int m,n;
int Init(int m){
    for(int i=1;i<=m;i++){
        F[i]=i;
    }
}
int Find(int n){
    return n==F[n]?n:F[n]=Find(F[n]);
}
bool Union(int x,int y){
    int nx=Find(x);
    int ny=Find(y);
    if(nx==ny)return false;
    F[ny]=nx;
    return true;
}
int Count(int m){
    int cnt=0;
    for(int i=1;i<=m;i++)
        if(F[i]==i)cnt++;
    return cnt;
}
int main() {
    while(cin>>m>>n){
        Init(m);
        if(m==0&&n==0)break;
        while(n--){
            int x,y;
            cin>>x>>y;
            Union(x,y);
        }
        cout<<Count(m)-1<<endl;
    }
    return 0;
}
