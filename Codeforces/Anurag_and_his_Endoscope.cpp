#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define ff first
#define ss second
#define mk make_pair
#define pb push_back
#define rep(i, start, end) for (int i = start; i < end; i++)
#define ld long double
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
int inf = 1000000000000000000;
using ii = pair<int, int>;
int n,m,cx,cy,l;    
int pipe[1000][1000], visited[1000][1000];


bool valid(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<m);
}
bool left(int x,int y){
    return (pipe[x][y]==1 || pipe[x][y]==3 || pipe[x][y]==6 || pipe[x][y]==7);
}
bool right(int x,int y){
    return (pipe[x][y]==1 || pipe[x][y]==3 || pipe[x][y]==4 || pipe[x][y]==5);
}
bool up(int x,int y){
    return (pipe[x][y]==1 || pipe[x][y]==2 || pipe[x][y]==4 || pipe[x][y]==7);
}
bool down(int x,int y){
    return (pipe[x][y]==1 || pipe[x][y]==2 || pipe[x][y]==6 || pipe[x][y]==5);
}

int finale(int x, int y, int l){
    int ans =0;
    // cout<<"i am here final"<<endl;

    queue<vector<int>> q;
    q.push({x,y,l});
    visited[x][y]=1;

    while(!q.empty()){
        vector<int> curr= q.front();
        int x= curr[0];
        int y= curr[1];
        int l= curr[2];

        q.pop();
        if (l==0){
            continue;
        }
        ans++;

        if (valid(x,y-1)&&left(x,y)&&right(x,y-1)&& visited[x][y-1]==0){
            visited[x][y-1]=1;
            q.push({x,y-1,l-1});
        }

        if (valid(x,y+1)&&right(x,y)&&left(x,y+1)&& visited[x][y+1]==0){
            visited[x][y+1]=1;
            q.push({x,y+1,l-1});
        }

        if (valid(x-1,y)&&up(x,y)&&down(x-1,y)&& visited[x-1][y]==0){
            visited[x-1][y]=1;
            q.push({x-1,y,l-1});
        }

        if (valid(x+1,y)&&down(x,y)&&up(x+1,y)&& visited[x+1][y]==0){
            visited[x+1][y]=1;
            q.push({x+1,y,l-1});
        }
    }
    return ans;
    


}

void solve()
{	
cin>>n>>m>>cx>>cy>>l;


for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>pipe[i][j];
        visited[i][j]=0;
    }
}

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    }
}




if (pipe[cx][cy]>0){
    cout<<finale(cx,cy,l)<<endl;
}
else{
    cout<<0<<endl;
}

    
}

signed main()
{
    fast
    int t; cin>>t;


    while(t--){
        solve();
    }
    return 0;
}