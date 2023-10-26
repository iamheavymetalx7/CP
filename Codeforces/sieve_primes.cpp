#include "stdc++.h"
using namespace std;
int n;
int main(){
    cin >> n;
    vector<bool> prime(n+1,true);
    prime[0]=false;
    prime[1]=false;

    for( int i=2; i*i<=n;i++){
        if (prime[i]){
            for (int j=i*i;j<=n;j+=i){
                prime[j] = false;
            }
        }
    }

    vector<int> p;

    for(int i=0;i<n;i++){
        if (prime[i]){
            p.push_back(i);
        }
    }

    for (auto pp: p){
        cout<<pp<<" ";
    }

}
