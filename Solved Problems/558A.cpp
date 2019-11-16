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

vector<pi> neg, pos;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in("");
    ofstream out("");
    int n;
    ll sum = 0;
    cin >> n;
    REP(i, n){
        int a, b;
        cin >> a >> b;
        sum += b;
        if (a > 0) pos.pb(mp(a, b));
        else neg.pb(mp(a, b));
    }
    sort(ALL(pos));
    sort(ALL(neg), greater<pi>());
    if (SZ(pos) == SZ(neg)) {
        cout << sum << endl;
        return 0;
    }
    int sz = min(SZ(pos), SZ(neg));
    sum = 0;
    if (sz == SZ(pos)){
        REP(i, SZ(pos)) sum += pos[i].second;
        REP(i, SZ(pos) + 1) sum += neg[i].second;
    }
    else {
        REP(i, SZ(neg)) sum += neg[i].second;
        REP(i, SZ(neg) + 1) sum += pos[i].second;
    }
    cout << sum << endl;
    return 0;
}