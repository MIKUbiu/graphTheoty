
#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
int inDgree[maxn];
int outDgree[maxn];
int m=0;
struct Edge{
    int x,y;
}E[1000];
vector<int>v;
void In(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int t;
            cin>>t;
            if(t==1){
                inDgree[j]++;
                outDgree[i]++;
                E[m++]={i,j};
            }

        }
}
bool topo(int n){
    queue<int>Q;
    for(int i=0;i<n;i++)
    {
        if(inDgree[i]==0)Q.push(i);
    }
    int cnt=0;
    while(!Q.empty()){
        auto p=Q.front();
        v.push_back(p);
        cnt++;
        for(auto e:E) {
            if (e.x == p) {
                inDgree[e.y]--;//要删除的点，删除他的出度的边，且对应的点入度加一；
                if (inDgree[e.y] == 0)Q.push(e.y);//减一之后检查该点的入度是否为0，为0则入队
            }
        }
        Q.pop();
    }//change
    return cnt==n;//如果所有点都能入队，则表示没有环存在
}
int main() {
    int n;
    cin>>n;
    In(n);
    if(topo(n)){
        copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    }else cout<<"ERROR"<<endl;


    return 0;
}
