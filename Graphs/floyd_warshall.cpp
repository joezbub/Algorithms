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
#define watch(x) cout << (#x) << " is " << (x) << endl
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
const int INF = 0x3f3f3f3f;
const int MAX = 100005;
const int MAX1 = 1005;
const int MAX2 = 105;
const int LEN = 105;
const int BASE = 1000000000;
const double EPS = 1e-7;
const int MOD = 1000000007;
//g++ -std=c++11 your_file.cpp -o your_program

int dist[MAX][MAX];

void FloydWarshall()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ifstream in("");
	ofstream out("");
	clock_t begin = clock();
  
	FOR(i, 1, n + 1) FOR(j, 1, n + 1) dist[i][j] = INF;
  FOR(i, 1, n + 1) dist[i][i] = 0;
  
	clock_t end = clock();
    double esecs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << esecs << " seconds" << endl;
	return 0;	
}
