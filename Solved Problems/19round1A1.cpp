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

int n, m;
vi G[405];
int arr[25][25], fin[25][25];
bool f;

void dfs(int ct, int r, int c){
    arr[r][c] = ct;
    if (ct == n * m - 1) {
        f = 1;
        REP(i, n){
            REP(j, m){
                fin[i][j] = arr[i][j];
            }
        }
        return;
    }
    for (auto x : G[m * r + c]){
        int nxtr = x / m;
        int nxtc = x % m;
        if (arr[nxtr][nxtc] == -1){
            dfs(ct + 1, nxtr, nxtc);
        }
    }
    arr[r][c] = -1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    clock_t begin = clock();
    int t;
    cin >> t;
    REP(i, t){
        cout << "Case #" << i + 1 << ": ";
        FILL(arr, -1);
        f = 0;
        cin >> n >> m;
        REP(i, n){
            REP(j, m){
                REP(k, n){
                    if (k == i) continue;
                    REP(l, m){
                        if (j == l) continue;
                        if (i - j == k - l or i + j == k + l) continue;
                        G[m * i + j].pb(m * k + l);
                    }
                }
            }
        }
        dfs(0, 0, 0);
        pi ans[405];
        if (!f){
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout << "POSSIBLE" << endl;
            REP(i, n){
                REP(j, m){
                    ans[fin[i][j]] = {i, j};
                }
            }
            REP(i, n * m){
                cout << ans[i].A + 1 << " " << ans[i].B + 1 << endl;
            }
        }
        REP(i, 405) G[i].clear();
    }
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}