/*
For the brave souls who are here: You are the chosen ones, the valiant
knights of coding who toil away, without rest, fixing my most awful
code. To you, true saviors, kings of men, I say this:
never gonna give you up, never gonna let you down,
never gonna run around and desert you. Never gonna make you cry,
never gonna say goodbye. Never gonna tell a lie and hurt you.
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
#include <unordered_map>
#include <vector>
//#include <boost/math/common_factor.hpp>
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

char arr[1005][1005];
bool vis[1005][1005];
int dim;
string ans;

bool dfs(string s, int r, int c){
    if (r == dim - 1 && c == dim - 1) {
        ans = s;
        return true;
    }
    vis[r][c] = 1;
    if (arr[r][c] == 'E') {
        if (r + 1 < dim && !vis[r + 1][c]) {
            if (dfs(s + 'S', r + 1, c)){
                return true;
            }
        }
    }
    else if (arr[r][c] == 'S'){
        if (c + 1 < dim && !vis[r][c + 1]) {
            if (dfs(s + 'E', r, c + 1)){
                return true;
            }
        }
    }
    else {
        if (r + 1 < dim && !vis[r + 1][c]){
            if (dfs(s + 'S', r + 1, c)) return true;
        }
        if (c + 1 < dim && !vis[r][c + 1]){
            if (dfs(s + 'E', r, c + 1)) return true;
        }
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("ownway.in");
    ofstream out("");
    clock_t begin = clock();
    int n;
    cin >> n;
    REP(i, n){
        REP(j, 1005){
            REP(k, 1005) {
                arr[j][k] = ' ';
                vis[j][k] = 0;
            }
        }
        cout << "Case #" << i + 1 << ": ";
        cin >> dim;
        string dir;
        cin >> dir;
        pi start = {0, 0};
        REP(j, SZ(dir)) {
            if (dir[j] == 'E') {
                arr[start.A][start.B] = 'E';
                start = {start.A, start.B + 1};
            } else if (dir[j] == 'S') {
                arr[start.A][start.B] = 'S';
                start = {start.A + 1, start.B};
            }
        }
        dfs("", 0, 0);
        cout << ans << endl;
        ans = "";
    }
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}