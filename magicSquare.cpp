#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int maxn=31;
int m[maxn][maxn];
int book[maxn];
int main() {
    int n;
    while(cin>>n){
        int s=1;
       memset(m,0,sizeof(m));
       m[n-1][n/2]=s;
       int x=0,y=n/2;
       while(s<n*n){
           s++;
           int nx=(x+1+n)%n;
           int ny=(y+1+n)%n;
           if(m[nx][ny]!=0)
           {
               nx=(x+1+n)%n;
           }
           x=nx;
           y=ny;
           m[x][y]=s;
       }
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++) {
               cout << m[i][j] << " ";
           }
           cout<<endl;
       }

    }
    return 0;
}
