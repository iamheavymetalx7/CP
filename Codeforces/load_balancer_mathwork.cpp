// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> arrival(m);
vector<int> bursttime(m);

int main() {
	cin>>n>>m;
	cout<<n<<" "<<m<<endl;
	for(int i=0;i<m;i++){
		cin>>arrival[i];
	}
	for(int i=0;i<m;i++){
		cin>>bursttime[i];
	}
	vector<pair<int,int>> vec;
	for(int i=0;i<m;i++){
		vec.push_back({arrival[i],bursttime[i]});
	}

	sort(vec.begin(),vec.end());

	for (auto x: vec){
		cout<<x.first<<" "<<x.second<<endl;
	}
}