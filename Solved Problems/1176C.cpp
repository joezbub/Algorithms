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

set<int> a;
set<int> b;
set<int> c;
set<int> d;
set<int> e;
set<int> f;
int arr[500005];

bool dfs(int ind){
    if (arr[ind] == 4) {
        auto pos = b.lower_bound(ind + 1);
        if (pos == b.end()) return 0;
        else {
            int tmp = *pos;
            if (dfs(tmp)) {
                b.erase(pos);
                return true;
            }
            else return 0;
        }
    }
    else if (arr[ind] == 8){
        auto pos = c.lower_bound(ind + 1);
        if (pos == c.end()) return 0;
        else {
            int tmp = *pos;
            if (dfs(tmp)) {
                c.erase(pos);
                return true;
            }
            else return 0;
        }
    }
    else if (arr[ind] == 15){
        auto pos = d.lower_bound(ind + 1);
        if (pos == d.end()) return 0;
        else {
            int tmp = *pos;
            if (dfs(tmp)) {
                d.erase(pos);
                return true;
            }
            else return 0;
        }
    }
    else if (arr[ind] == 16){
        auto pos = e.lower_bound(ind + 1);
        if (pos == e.end()) return 0;
        else {
            int tmp = *pos;
            if (dfs(tmp)) {
                e.erase(pos);
                return true;
            }
            else return 0;
        }
    }
    else if (arr[ind] == 23){
        auto pos = f.lower_bound(ind + 1);
        if (pos == f.end()) return 0;
        else {
            f.erase(pos);
            return true;
        }
    }
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    clock_t begin = clock();
    int n;
    cin >> n;
    REP(i, n) {
        cin >> arr[i];
        if (arr[i] == 4) a.insert(i);
        else if (arr[i] == 8) b.insert(i);
        else if (arr[i] == 15) c.insert(i);
        else if (arr[i] == 16) d.insert(i);
        else if (arr[i] == 23) e.insert(i);
        else f.insert(i);
    }
    int ct = 0;
    for (auto x : a) {
        if (dfs(x)){
            ct += 6;
        }
    }
    cout << n - ct << endl;
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}
/*
100
4 42 23 23 8 42 16 23 42 16 42 8 4 23 4 4 23 42 16 42 23 23 23 42 4 42 8 8 16 23 15 23 16 4 42 15 15 23 16 15 16 4 4 15 23 42 42 15 8 23 8 23 4 15 16 15 42 8 23 16 15 42 23 8 4 16 15 16 23 16 16 4 23 16 8 23 16 15 23 4 4 8 15 4 4 15 8 23 23 4 4 8 8 4 42 15 4 4 42 16
 */