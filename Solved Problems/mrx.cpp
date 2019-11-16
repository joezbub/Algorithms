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
    REP(i, n){
        string s;
        cin >> s;
        cout << "Case #" << i + 1 << ": ";
        if (SZ(s) == 1){
            if (s[0] == '1' or s[0] == '0') cout << 0 << endl;
            else cout << 1 << endl;
            continue;
        }
        else{
            bool f = 0;
            REP(j, SZ(s)){
                if (s[j] != '(' && s[j] != ')' && s[j] != '^' && s[j] != '&' && s[j] != '|' && (s[j] != '1' && s[j] != '0')) {
                    f = 1;
                    break;
                }
            }
            if (!f){
                cout << 0 << endl;
                continue;
            }
        }
        int res = 0;
        stack<char> st;
        REP(j, SZ(s)){
            if (s[j] == ')'){
                char c1 = st.top();
                st.pop();
                char c2 = st.top();
                st.pop();
                char c3 = st.top();
                st.pop();
                st.pop();
                //cout << c1 << " " << c2 << " " << c3 << endl;
                if (isdigit(c1) && isdigit(c3)){
                    bool d1, d2;
                    d1 = c1 - '0';
                    d2 = c3 - '0';
                    if (c2 == '^'){
                        st.push((d1 xor d2) + '0');
                    }
                    else if (c2 == '&'){
                        st.push((d1 & d2) + '0');
                    }
                    else st.push((d1 | d2) + '0');
                }
                else if ((c1 == 'x' && c3 == 'X') or (c1 == 'X' && c3 == 'x') or (c1 == 'x' && c3 == 'x') or (c1 == 'X' && c3 == 'X')){
                    if (c2 != '^') ++res;
                    if (c1 != c3){
                        st.push('1');
                    }
                    else st.push('0');
                }
                else if ((isdigit(c1) && c1 == '0') or (isdigit(c3) && c3 == '0')){
                    if (c2 != '&') ++res;
                    st.push('0');
                }
                else {
                    if (c2 != '|') ++res;
                    st.push('1');
                }
            }
            else{
                st.push(s[j]);
            }
        }
        cout << res << endl;
    }
    clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
    return 0;
}