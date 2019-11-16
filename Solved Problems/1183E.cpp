#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
#define endl '\n'

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define pb push_back
#define mp make_pair
#define Pi 3.14159265358979
#define A first
#define B second

typedef long long ll;
typedef vector <int> vi;
typedef vector<ll> vl;
typedef pair <int, int> pi;
typedef pair <ll, int> pl;
typedef pair <ll, ll> pll;
typedef pair <double, double> pd;

//change these according to prob constraints
const int INF = 1000000000;
const int MAX = 100005;
const int MAX1 = 1005;
const int MAX2 = 105;
const int LEN = 105;
const int BASE = 1000000000;
const double EPS = 1e-7;
const int MOD = 1000000007;
//g++ -std=c++11 your_file.cpp -o your_program

ll pow(ll a, ll b){
    ll ans=1;
    while(b){
        if(b&1)
            ans=(ans*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return ans;
}

struct MyStringLengthCompare
{
    bool operator () (const std::string & p_lhs, const std::string & p_rhs)
    {
        const size_t lhsLength = p_lhs.length() ;
        const size_t rhsLength = p_rhs.length() ;

        if(lhsLength == rhsLength)
        {
            return (p_lhs < p_rhs) ; // when two strings have the same
            // length, defaults to the normal
            // string comparison
        }

        return (lhsLength < rhsLength) ; // compares with the length
    }
} ;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    clock_t begin = clock();
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    set<string, MyStringLengthCompare> S;
    queue<string> Q;
    Q.push(s);
    while (!Q.empty()){
        if (SZ(S) >= 100) break;
        string tmp = Q.front();
        Q.pop();
        if (S.find(tmp) != S.end()) continue;
        S.insert(tmp);
        REP(i, SZ(tmp)){
            Q.push(tmp.substr(0, i) + tmp.substr(i + 1, SZ(tmp) - i - 1));
        }
    }
    int res = 0;
    int ct = 0;
    for (auto it = S.rbegin(); it != S.rend(); ++it){
        ++ct;
        string tmp = *it;
        res += n - SZ(tmp);
        if (ct == k){
            cout << res << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}