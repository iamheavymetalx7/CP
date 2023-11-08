/*
Problem Statement
Send feedback
In a cricket academy, students' favorite jersey numbers are captured in array 
'A' of size 'N'.
A jersey number achieves "majority" if its occurrence in 'A' is greater
 than or equal to the sum of occurrences of all other numbers.
You can remove certain numbers from 'A'. What is the largest possible
 size of 'A' after removals where a single jersey number maintains its majority?
For Example:-
Let 'N' = 5, 'A' = [4, 1, 3, 1, 2].
By removing the number at index 1 (1-based indexing), The array becomes
 [1, 3, 1, 21, and the jersey number '1' has occurrences equal to the
  sum of occurrences of other jersey numbers.
Thus, the answer is 4.

Detailed explanation (Input/output format, Notes, Images )
Input Format:-
First-line contains an integer 'T', which denotes the number of testcases
For every testcase:
First-line contains an integer 'N', denoting the number of students in that batch.
Second-line contains 'N' space-separated integers, denoting the jersey numbers preferred by the students.
Output Format:-
For each batch, return the maximum number of students such that a jersey number retains its majority.
Note:-
You don't need to print anything. Just implement the given function.

Constraints:-
1 <='T' <= 10
1 ＜='N'＜=10^5
1 <= 'A［i］'<= 10^5
The sum of 'N' over all batches does not exceed 10^5.
Time Limit: 1 sec
Sample Input 1:-
2
4
1234
6
121223

Sample Output 1:-
2
6
Explanation of sample input 1:-
First test case:-
We can remove elements at indexes 3 and 4 (1-based indexing).
The array becomes I1, 21, and the occurrence of '2' is equal to the sum of the occurrences of other elements.
So the answer is 2.
Second test case:-
The occurrence of '2' is equal to the sum of the occurrences of other elements already.
So the answer is 6.


Sample Input 2:-
2
7
4514342
4
3332
Sample Output 2:-
6
4


public class Solution {
public static int maximumLength(int []a) {


}
}

*/

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
    
    void solve()
    {	int n;
        cin>>n;
        map<int,int> mp;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        int maxi = -1;
        for(auto x: mp){
            maxi = max(maxi, x.second);
        }

        int ans = 2*maxi;
        cout<<min(ans,n)<<endl;

     
    }
    
    signed main()
    {
        fast
        int t;

    
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        cin>>t;

        while(t--) {
            solve();
        }
        return 0;
    }