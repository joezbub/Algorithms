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

int par[100005];

ll pow(ll a, ll b, int m)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}

int root(int v){
    if (par[v] < 0) return v;
    else return par[v] = root(par[v]);
}

void connect(int u, int v){
    int n = root(u), m = root(v);
    if (n == m) return;
    if (par[n] < par[m]){
        par[n] += par[m];
        par[m] = n;
    }
    else {
        par[m] += par[n];
        par[n] = m;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    clock_t begin = clock();
    REP(i, 100005) par[i] = -1;
    int n, k;
    cin >> n >> k;
    REP(i, n - 1){
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0){
            connect(a, b);
        }
    }
    ll res = 0;
    set<int> S;
    FOR(i, 1, n + 1){
        int r = root(i);
        if (S.find(r) != S.end()) continue;
        S.insert(r);
        res += pow(-1 * (ll)par[r], (ll)k, MOD);
    }
    cout << ((pow(n, k, MOD) - res) % MOD + MOD) % MOD << endl;
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}