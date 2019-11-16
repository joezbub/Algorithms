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

int dp[1005][1005];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    string s1, s2;
    cin >> s1 >> s2;
    if (SZ(s1) < SZ(s2)) swap(s1, s2);
    dp[0][0] = (s1[0] == s2[0]) ? 1 : 0;
    FOR(i, 1, SZ(s1)) dp[0][i] = (dp[0][i - 1] or s1[0] == s2[i]) ? 1 : 0, dp[i][0] = (dp[i - 1][0] or s1[i] == s2[0]) ? 1 : 0;
    FOR(i, 1, SZ(s1)){
        FOR(j, 1, SZ(s2)){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i] == s2[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[SZ(s1) - 1][SZ(s2) - 1] << endl;
    return 0;
}
