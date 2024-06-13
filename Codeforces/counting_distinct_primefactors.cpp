#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100005];
    memset(arr,0,sizeof(arr));
    for(int i=2;i<100005;i++){
            if(arr[i]==0){
                arr[i]++;
                for(int j=2*i;j<100005;j+=i){
                    arr[j]++;
                }
            }
        }

    // distinct primes

    vector<vector<int>> pref(100005,vector<int>(6,0));


    for(int i=1;i<100005;i++){
        for(int j=0;j<6;j++){
            pref[i][j] = pref[i-1][j] + (arr[i]==j);
        }
    }

    int t; cin>>t;
    while(t--){
        int l,r,q;
        cin>>l>>r>>q;

        cout<<pref[r][q]-pref[l-1][q]<<endl;

        
    }
    return 0;

}