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
    ifstream cin("graphsservice.txt");
    ofstream cout("graphsservice.out");
    clock_t begin = clock();
    int t;
    cin >> t;
    REP(q, t){
        cout << "Case #" << q + 1 << ": ";
        int n, m;
        cin >> n >> m;
        ll G[n + 1][n + 1];
        REP(i, n + 1){
            REP(j, n + 1) G[i][j] = (ll)1e6;
        }
        REP(i, n + 1) G[i][i] = 0;
        vector<pair<pi, int> > vec;
        REP(i, m){
            int a, b, c;
            cin >> a >> b >> c;
            G[a][b] = c;
            G[b][a] = c;
            vec.pb({{a, b}, c});
        }
        FOR(i, 1, n + 1){
            FOR(j, 1, n + 1){
                FOR(k, 1, n + 1){
                    if (G[j][i] != (ll)1e6 && G[i][k] != (ll)1e6 && G[j][i] + G[i][k] < G[j][k]) G[j][k] = G[k][j] = G[j][i] + G[i][k];
                }
            }
        }
        bool f = 0;
        REP(i, m){
            if (G[vec[i].A.A][vec[i].A.B] != vec[i].B) {
                cout << "Impossible" << endl;
                f = 1;
            }
        }
        if (f) continue;
        ll ans = (ll)n * (n - 1) / 2;
        cout << ans << endl;
        FOR(i, 1, n){
            FOR(j, i + 1, n + 1){
                cout << i << " " << j << " " << G[i][j] << endl;
            }
        }
    }
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}