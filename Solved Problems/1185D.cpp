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

int arr[200005];
map<int, int> mymp;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream in("");
    ofstream out("");
    clock_t begin = clock();
    int n;
    cin >> n;
    if (n == 2 or n == 3){
        cout << 1 << endl;
        return 0;
    }
    REP(i, n){
        cin >> arr[i];
        mymp[arr[i]] = i + 1;
    }
    sort(arr, arr + n);
    bool f = 0;
    FOR(i, 1, n - 1){
        if (arr[i + 1] - arr[i] != (arr[n - 1] - arr[1]) / (n - 2)){
            f = 1;
            break;
        }
    }
    if (!f) {
        cout << mymp[arr[0]] << endl;
        return 0;
    }
    f = 0;
    REP(i, n - 2){
        if (arr[i + 1] - arr[i] != (arr[n - 2] - arr[0]) / (n - 2)){
            f = 1;
            break;
        }
    }
    if(!f){
        cout << mymp[arr[n - 1]] << endl;
        return 0;
    }
    int diff = (arr[n - 1] - arr[0]) / (n - 2);
    f = 0;
    int pos = -1;
    FOR(i, 1, n){
        if (!f && arr[i] != arr[0] + diff * i){
            f = 1;
            pos = arr[i];
        }
        else if (f && arr[i] != arr[0] + diff * (i - 1)){
            cout << -1 << endl;
            return 0;
        }
    }
    if (!f) cout << 1 << endl;
    else cout << mymp[pos] << endl;
    /*
    int high = n - 1, low = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << low << " " << mid << " " << high << endl;
        if (arr[mid] != arr[0] + mid * diff && mid + 1 < n && arr[mid + 1] - arr[mid] != diff) {
            cout << mymp[arr[mid]] << endl;
            return 0;
        }
        if (arr[mid] != arr[0] + mid * diff && mid > 0 && arr[mid] - arr[mid - 1] != diff) {
            cout << mymp[arr[mid - 1]] << endl;
            return 0;
        }
        if (arr[mid] == arr[0] + mid * diff) low = mid + 1;
        else high = mid - 1;
    }
     */
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}