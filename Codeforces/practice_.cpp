#include "stdc++.h"
using namespace std;

int main(){
    pair<int, string> p;
    p = make_pair(20,"abc");
    cout<<p.first<<"\n"<<p.second;


    int a[] = {1,2,3};
    int b[] = {2,3,4};
    pair<int,int> p_array[3];
    p_array[0] = {1,2};
    p_array[1] = {2,3};
    p_array[2] = {3,4};

    for(int i=0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<"\n";
    }

    return 0;
}