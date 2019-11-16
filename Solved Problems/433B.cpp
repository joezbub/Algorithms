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
//g++ -std=c++11 your_file.cpp -o your_program

ll arr[MAX], sarr[MAX];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in("");
    ofstream out("");
    int n;
    cin >> n;
    FOR(i, 1, n + 1){
        int tmp;
        cin >> tmp;
        arr[i] = sarr[i] = tmp;
    }
    sort(sarr, sarr + n + 1);
    //REP(i, n + 1) cout << sarr[i] << " ";
    //cout << endl;
    FOR(i, 2, n + 1){
        arr[i] += arr[i - 1];
        sarr[i] += sarr[i - 1];
    }
    int m;
    cin >> m;
    while (m--){
        int b, l, r;
        cin >> b >> l >> r;
        if (b == 1){
            cout << arr[r] - arr[l - 1] << endl;
        }
        else cout << sarr[r] - sarr[l - 1] << endl;
    }
    return 0;
}