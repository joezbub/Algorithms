/*
Change hoes like clothes, I can’t get attached
‘Cause these hoes fire starters like lit matches

— XXXtentacion (Jahseh Onfroy) 1998 - 2018 R.I.P
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

typedef long long ll;
typedef vector <int> vi;
typedef vector<ll> vl;
typedef pair <int, int> pi;
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

int dist[105];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in("");
    ofstream out("");
    int n, s, t;
    cin >> n;
    REP(i, n) cin >> dist[i];
    cin >> s >> t;
    if (s == t){
        cout << 0 << endl;
        return 0;
    }
    else if (t < s) swap(s, t);
    int sum1 = 0, sum2 = 0;
    FOR(i, s, t) sum1 += dist[i - 1];
    FOR(i, t, n + 1) sum2 += dist[i - 1];
    REP(i, s - 1) sum2 += dist[i];
    //cout << sum1 << " " << sum2 << endl;
    cout << min(sum1, sum2) << endl;
    return 0;
}