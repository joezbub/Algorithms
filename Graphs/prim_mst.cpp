#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define pb push_back
#define mp make_pair
#define Pi 3.14159265358979

typedef long long ll;
typedef vector <int> vi;
typedef vector<ll> vl;
typedef pair <int, int> pi;
typedef pair <int, ll> pl;
typedef pair <double, double> pd;

//change these according to prob constraints
const ll INF = 1e18;
const int MAX = 100005;
const int MAX1 = 2600;
const int MAX2 = 4007;
const int LEN = 21;
const int BASE = 1000000000;
const double EPS = 1e-7;
const int MOD = 1234567891;
//g++ -std=c++11 your_file.cpp -o your_program

int v, e;
vector<pl> G[MAX1];
vector<ll> dist;
bool inmst[MAX1];

void prim(){
    dist.assign(MAX1, INF);
    dist[1] = 0;
    priority_queue<pl, vector<pl>, greater<pl> > Q;
    Q.push(mp(0, 1));
    while (!Q.empty()){
        pl tmp = Q.top();
        Q.pop();
        if (dist[tmp.second] != tmp.first) continue;
        inmst[tmp.second] = 1;
        for (auto x : G[tmp.second]){
            if (!inmst[x.first] && dist[x.first] > x.second){
                dist[x.first] = x.second;
                Q.push(mp(x.second, x.first));
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in("");
    ofstream out("");
    cin >> v >> e;
    ll res = 0;
    REP(i, e){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }
    prim();
    FOR(i, 1, v + 1){
        if (inmst[i]) res += dist[i];
    }
    cout << res << endl;
    return 0;
}
