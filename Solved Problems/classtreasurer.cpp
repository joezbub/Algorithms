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

vector<int> pows;

ll power(ll x, ll y){
    ll res = 1;
    x=x%MOD;
    while (y > 0){
        if (y & 1)res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res;
}

void init(){
    pows.pb(1);
    FOR(i, 1, 1000001){
        pows.pb(power(2, i));
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("class_treasurer.txt");
    ofstream cout("class_treasurer.out");
    clock_t begin = clock();
    init();
    int t;
    cin >> t;
    REP(q, t){
        cout << "Case #" << q + 1 << ": ";
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int d = 0;
        ll res = 0;
        RREP(i, n){
            if (s[i] == 'A'){
                if (d != 0) d--;
            }
            else{
                if (d < k) d++;
                else if (d == k) {
                    res = (res + (ll)pows[i + 1]) % MOD;
                    if (d != 0) d--;
                }
            }
        }
        cout << res << endl;
    }
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}