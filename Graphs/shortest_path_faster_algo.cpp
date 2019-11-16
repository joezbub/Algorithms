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

int n, m;
int dist[N], cnt[N];
bool inqueue[N];
vector<pair<int, int> > g[N];

bool spfa(int source) 
{
	queue<int> q;

	for(int i=1;i<=n;i++)
	{
		cnt[i]=0;
		dist[i]=INF;
	}

	dist[source]=0;
	q.push(source);
	inqueue[source]=true;

	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		inqueue[v]=false;

		for(auto &edge:g[v])
		{
			int to=edge.first;
			int w=edge.second;

			if(dist[v] + w < dist[to])
			{
				dist[to] = dist[v] + w;
				dist[to] = max(dist[to], -INF);
				if(!inqueue[to])
				{
					q.push(to);
					inqueue[to]=true;
					cnt[to]++;
					if(cnt[to]>n)
						return true;
				}
			}
		}
	}
  
  int main(){
  
  }
