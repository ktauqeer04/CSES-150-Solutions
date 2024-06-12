//----------HEADER----------
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
//----------TEMPLATES----------
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
//----------MACROS----------
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define lli long long int
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define nl cout<<'\n'
#define E cerr<<'\n'
#define all(x) x.begin(),x.end()
#define fl(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>=b; --i)
#define IOS ios_base::sync_with_stdio(false)
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//----------CONSTANTS----------
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
//----------GLOBALS----------

//----------SOLUTION----------


int main(){

    int n; cin >> n;
    vector<ll>apples(n);
    lli sum = 0;
    for(int i = 0; i < n; i++){
        cin >> apples[i];
        sum += apples[i]; // find total weight of the apples
    }

    // find all the possible combinations 
    // the question is like take an apple or not take an apple
    // we have to generate all the subsets and for every subset we have to 
    // find the the weight of that particular subset
    
    // after finding the weight of that subset (i.e we have made one group of apples)
    // we have to find the remaining weight of the another group
    // then we can find the minimum difference between two groups 

    // we first iterate through every possible outcomes
    // the outcomes we can find using 2^n formula 
    // in cpp (1 << n) means 2^n 
    // we have to denote every apple in a bit
    // means if there are 5 apples then 5 bits represent five apples
    // eg. n =  5 means 00000 total bits denote 5 apples
    // this iteration will go from 00000 -> 11111
    // 0 means we dont take that apple. so in the case of 00000 we dont take any apple
    // 11111 means we take every apple
    // 10101 means we take 0th, 2nd and 4th apple (0 based indexing)

    lli minDifference = INT_MAX;
    for(int i = 0; i < (1 << n); i++){
        lli currSum = 0;
        for(int j = 0; j < n; j++){
            (i & (1 << j)) ? currSum += apples[j] : currSum += 0;
        }
        lli curr = abs((sum - currSum) - currSum);
        minDifference = min(minDifference, curr);
    }

    cout << minDifference << endl;

    

	return 0;
}