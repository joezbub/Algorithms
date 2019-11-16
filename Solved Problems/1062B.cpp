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

int tot = 0;

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

ll doit(ll num){
    ll n = num;
    int ct[1000005];
    FILL(ct, 0);
    set<int> pr;
    while (n % 2 == 0){
        pr.insert(2);
        n /= 2;
        ct[2]++;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            pr.insert(i);
            n = n/i;
            ct[i]++;
        }
    }
    if (n > 2 && n != num){
        pr.insert(n);
        ct[n]++;
    }
    if (n == num){
        cout << num << " " << 0 << endl;
        return 0;
    }
    n = num;
    bool f = 0;
    for (auto x : pr){
        if (ct[x] & 1){
            n *= x;
            f = 1;
        }
    }
    int count = 0;
    while (sqrt(n) * sqrt(n) == n){
        ++count;
        n = sqrt(n);
    }
    if (f) {
        tot += 1 + count;
        return n;
    }
    else{
        tot += count;
        return n;
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    clock_t begin = clock();
    ll num;
    cin >> num;
    while (1){
        int tmp = doit(num);
        int tmpct = tot;
        if (tmp == doit(tmp)) {
            cout << tmp << " " << tmpct << endl;
            return 0;
        }
        else tot = tmpct;
        num = tmp;
    }
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}