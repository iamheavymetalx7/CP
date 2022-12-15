#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, n, i, j, k, p1;
    string ans;
    
    ll p[100001];
    
    for(i=0; i<=100000; i++){
        p[i]=1;
    }
    
    for(i=2; i<=100000; i++)
    {
        if(p[i]==1){
            for(j=i*i; j<=100000; j+=i){
                p[j]=0;
            }
        }
    }
    
    vector<ll> pr;
    
    for(i=2; i<=100000; i++){
        if(p[i]==1){
            pr.push_back(i);
        }
    }
    
    p1=pr.size();
    
    cin>>t;
    
    for(;t--;)
    {
        cin>>n;
        
        ans="NO";
        
        ll a[n];
        
        for(i=0; i<n; i++){
            cin>>a[i];
        }
        
        unordered_map<ll, bool> mp;
        
        for(i=0; i<n; i++){
            for(j=0; j<p1; j++){
                if(pr[j]*pr[j]>a[i]){
                    break;
                }
                
                if((a[i]%(pr[j]))==0){
                    if(mp[pr[j]]==true){
                        ans="YES";
                        break;
                    }else{
                        mp[pr[j]]=true;
                    }
                    
                    while((a[i]%pr[j])==0){
                        a[i]=a[i]/pr[j];
                    }
                }
                
                
            }
            
            if(mp[a[i]]==true && a[i]>1){
                ans="YES";
                break;
            }else if(a[i]>1){
                mp[a[i]]=true;
            }
            
            
            if(ans=="YES"){
                break;
            }
        }
        
        cout<<ans<<"\n";
    }
}