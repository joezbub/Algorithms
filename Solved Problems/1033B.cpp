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

bool isp(ll tmp){
    while (1) {
        if (tmp == 2 or tmp == 3) return true;
        ll p = tmp;
        if ((p + 1) % 6 != 0 && (p - 1) % 6 != 0) {
            for (int i = 2; i * i <= p; ++i) {
                if (p % i == 0) return false;
            }
        }
        p += 1;
        tmp -= 1;
        if (p % 6 != 0) tmp /= 6;
        else tmp = p / 6;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    int t;
    cin >> t;
    while (t--){
        ll a, b;
        cin >> a >> b;
        ll tmp = a + b;
        if (a - b == 1 && isp(tmp)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}