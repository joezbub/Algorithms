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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    clock_t begin = clock();
    int n;
    cin >> n;
    ll arr[2][MAX], dp[2][MAX];
    FILL(dp, 0);
    REP(i, 2){
        REP(j, n){
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    FOR(i, 1, n){
        REP(j, 2){
            if (j == 0){
                if (i >= 2) dp[j][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[j][i];
                else dp[j][i] = dp[1][i - 1] + arr[j][i];
            }
            else{
                if (i >= 2) dp[j][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[j][i];
                else dp[j][i] = dp[0][i - 1] + arr[j][i];
            }
        }
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}