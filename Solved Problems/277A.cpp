/*
I just got lost in thought. It was unfamiliar territory.
- Steven Wright
*/

#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <vector>
//#include <boost/math/common_factor.hpp>
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
#define A first
#define B second

typedef long long ll;
typedef vector <int> vi;
typedef vector<ll> vl;
typedef pair <int, int> pi;
typedef pair <ll, int> pl;
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

int par[105];
vi G[105];

int root(int a){
    return (par[a] < 0 ? a : par[a] = root(par[a]));
}

void join(int a, int b){
    if ((a = root(a)) == (b = root(b))) return;
    //cout << a << " " << b << endl;
    if (par[b] < par[a]) swap(a, b);
    par[a] += par[b];
    par[b] = a;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    int n, m;
    bool f = 0;
    cin >> n >> m;
    FILL(par, -1);
    FOR(i, 1, n + 1){
        int n;
        cin >> n;
        if (n) f = 1;
        REP(j, n){
            int tmp;
            cin >> tmp;
            G[tmp].pb(i);
        }
    }
    if (!f) {
        cout << n << endl;
        return 0;
    }
    /*
    FOR(i, 1, m + 1){
        REP(j, SZ(G[i])){
            cout << G[i][j] << " ";
        }
        cout << "\n";
    }
    */
    FOR(i, 1, m + 1){
        REP(j, SZ(G[i])){
            FOR(k, j + 1, SZ(G[i])){
                join(G[i][j], G[i][k]);
            }
        }
    }
    int res = 0;
    FOR(i, 1, n + 1) {
        if (par[i] < 0) ++res;
    }
    cout << res - 1 << endl;
    return 0;
}