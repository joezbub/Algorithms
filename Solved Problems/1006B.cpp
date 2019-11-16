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
//g++ -std=c++11 your_file.cpp -o your_program

vector<pi> arr;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in("");
    ofstream out("");
    int n, k;
    cin >> n >> k;
    REP(i, n){
        int tmp;
        cin >> tmp;
        arr.pb(mp(tmp, i));
    }
    vi inds;
    sort(ALL(arr));
    int myi = n - 1;
    ll res = 0;
    REP(i, k){
        res += arr[myi].first;
        inds.pb(arr[myi].second);
        myi--;
    }
    cout << res << endl;
    sort(ALL(inds));
    REP(i, k - 1){
        cout << (i ? inds[i] - inds[i - 1] : inds[0] + 1) << " ";
    }
    cout<<(k>1 ? n-1-inds[k-2]:n) << endl;
    return 0;
}