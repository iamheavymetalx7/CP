// #include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int solve(int idx,int mask,int m,vector<int>&a,vector<vector<int>>&dp){
  if(idx==m){
    if(mask)return 1;
    return 0;
  }
  
  if(dp[idx][mask]!=-1)return dp[idx][mask];
  
  int t=0,nt=0,ans=0;
  
  nt=solve(idx+1,mask,m,a,dp); nt%=mod;
  if(!(mask & a[idx])){
    t=solve(idx+1,(mask|a[idx]),m,a,dp); t%=mod;
  }
  ans=(nt+t)%mod;
  
  return dp[idx][mask]=ans;
}

int main() {
  int n; cin>>n;
  vector<int>v={2,3,5,7,11,13,17,19,23,29};
  vector<int>a;
  
  for(int i=0;i<n;i++){
    int f=0,mask=0,k; cin>>k;
    for(int j=0;j<10;j++){
      if(k%(v[j]*v[j])==0){f=1; break;}
      if(k%v[j]==0)mask+=1<<j;
    } 
    if(f)continue;
    else a.push_back(mask);
  }
  
  int m=a.size();
  vector<vector<int>>dp(m+1,vector<int>((1<<10),-1));
  cout<<solve(0,0,m,a,dp);
}