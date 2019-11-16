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
const int INF = 1000000000;
const int MAX = 100005;
const int MAX1 = 2007;
const int MAX2 = 4007;
const int LEN = 21;
const int BASE = 1000000000;
const double EPS = 1e-7;
const int MOD = 1234567891;
//g++ -std=c++11 your_file.cpp -o your_program

int v, e, s;
vector<pi> G[2505];
ll dist[2505];

void dijkstra(){
    priority_queue<pl, vector<pl>, greater<pl> > Q;
    Q.push({0, s});
    REP(i, v + 1) dist[i] = 1e18;
    dist[s] = 0;
    while (!Q.empty()){
        pl tmp = Q.top();
        Q.pop();
        if (dist[tmp.second] != tmp.first) continue;
        for (auto x : G[tmp.second]){
            if (dist[x.first] > tmp.first + x.second){
                dist[x.first] = tmp.first + x.second;
                Q.push({dist[x.first], x.first});
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in("");
    ofstream out("");
    cin >> v >> e >> s;
    REP(i, e){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }
    dijkstra();
    FOR(i, 1, v + 1) cout << ((dist[i] == 1e18) ? -1 : dist[i]) << endl;
    return 0;
}
