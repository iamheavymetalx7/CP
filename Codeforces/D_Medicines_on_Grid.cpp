#include <bits/stdc++.h>
    using namespace std;
    // #define int long long
    #define pi (3.141592653589)
    #define mod 1000000007
    #define float double
    #define ff first
    #define ss second
    #define mk make_pair
    #define pb push_back
    #define rep(i, start, end) for (int i = start; i < end; i++)
    // #define ld long double
    #define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int inf = 1000000000000000000;
    using ii = pair<int, int>;
            int n,m;



    // bool check(int xx, int yy, vector<vector<char>>& mat){
    //     if (xx>=1 && xx<=n && yy>=1 && yy<=m && (mat[xx][yy]=='.')){
    //         return true;
    //     }
    //     return false;
    // }
    
    void solve()
    {
        cin>>n>>m;
        int sx,sy;
        int tx,ty;
        vector<vector<char>> vec(n+1, vector<char>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>vec[i][j];
                if(vec[i][j]=='S'){
                    sx=i;sy=j;
                }
                if (vec[i][j]=='T'){
                    tx=i;
                    ty=j;
                }
            }
        }

        vector<vector<int>> dist(n+1,vector<int>(m+1,-1));
        int N;
        cin>>N; 
        vector<vector<int>> pwr(n+1,vector<int>(m+1,0));
        int pp,qq,pq;
        for(int i=0;i<N;i++){
            cin>>pp>>qq>>pq;
            pwr[pp][qq] =pq;

        }

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<pwr[i][j]<<' ';
        //     }s
        //     cout<<endl;
        // }
        // cout<<endl;


        queue<array<int,2>> q;

        q.push({sx,sy});
        // cout<<pwr[sx][sy]<<endl;
        dist[sx][sy]=max(0,pwr[sx][sy]);

        vector<int> dx ={1,0,-1,0};
        vector<int> dy = {0,1,0,-1};



        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int cx = cur[0];
            int cy = cur[1];
            if (dist[cx][cy]==0){
                continue;
            }


            for(int i=0;i<4;i++){
                auto nx = cx+dx[i];
                auto ny = cy+dy[i];

                if(nx<1||nx>n||ny<1||ny>m)continue;
                if(vec[nx][ny]=='#')continue;

                if (dist[nx][ny]<max(dist[cx][cy]-1,pwr[nx][ny])){
                    
                    dist[nx][ny] = max(dist[cx][cy]-1, pwr[nx][ny]);

                    q.push({nx,ny});
                }
                    
                
        }
        
        
    
    }
    if (dist[tx][ty]!=-1){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;

    }

    signed main()
    {
        fast
        // int t; cin>>t; while(t--)
    
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        solve();
        return 0;
    }