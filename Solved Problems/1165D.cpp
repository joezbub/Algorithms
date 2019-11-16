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

ll gcd(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

ll lcm(int a, int b){
    return ((ll)a * b) / gcd(a, b);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    clock_t begin = clock();
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        ll div[305];
        REP(i, n){
            cin >> div[i];
        }
        sort(div, div + n);
        ll ans = div[0] * div[n - 1];
        bool f = 0;
        //cout << ans << endl;
        vector<ll> vec;
        for (ll i = 2; i * i <= ans; ++i){
            if (ans % i == 0){
                //cout << i << endl;
                vec.pb(i);
                if (ans / i != i) vec.pb(ans / i);
            }
        }
        sort(ALL(vec));
        int ct = 0;
        for (ll x : vec){
            if (x != div[ct]) {
                f = 1;
                break;
            }
            ++ct;
        }
        if (f) cout << -1 << endl;
        else {
            cout << ans << endl;
        }
    }
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}