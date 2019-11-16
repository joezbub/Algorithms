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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("guard.in");
    ofstream out("guard.out");
    clock_t begin = clock();
    int n;
    ll h;
    cin >> n >> h;
    pair<int, pi> arr[25];
    REP(i, n){
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {c, {a, b}};
    }
    ll res = -1;
    sort(arr, arr + n, greater<pair<int, pi> >());
    FOR(i, 1, pow(2, n)){
        ll sum = 0;
        ll tmp[n + 1];
        int safe[n + 1];
        FILL(tmp, 0);
        int ct = 0;
        REP(j, n){
            if ((i >> j) & 1){
                sum += (ll)arr[j].B.A;
                tmp[ct] = (ll)arr[j].B.B;
                safe[ct] = arr[j].A;
                ++ct;
            }
        }
        if (sum < h){
            continue;
        }
        ll tmpres = safe[ct - 1];
        FOR(j, 1, ct){
            tmp[j] += tmp[j - 1];
        }
        bool f = 0;
        REP(j, ct - 1){
            ll t = safe[j] - (tmp[ct - 1] - tmp[j]);
            if (t < 0) {
                f = 1;
                break;
            }
            tmpres = min(tmpres, t);
        }
        if (f) {
            continue;
        }
        res = max(tmpres, res);
    }
    if (res == -1) cout << "Mark is too tall" << endl;
    else cout << res << endl;
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}