#include <bits/stdc++.h>
#define endl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v)    v.begin(), v.end()
#define rall(v)   v.rbegin(),v.rend()
#define pb        push_back
#define sz(a)     (int)a.size()
#define pii       pair<int, int>
#define vi        vector<int>
#define debg      cout << "DEBUG" << endl;
typedef short sh;
typedef char ch;
typedef long long ll;
typedef double db;
typedef long double ld;
    
using namespace std;

int train[100001][200];

void Solve() {
    set<int[200]> st;
    vector<int> used_idx;
    cout << st.
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int inst, tr, se;
        cin >> inst >> tr >> se;
        used_idx.push_back(tr);
        
        switch(inst) {
            case 1:
                if(train[tr][se] == 0)
                    train[tr][se] = 1;
                break;
            case 2:
                if(train[tr][se] == 1)
                    train[tr][se] = 0;
                break;
            case 3:
                for(int i = 19; i >= 0; i--) {
                    if(i != 0) {
                        if(train[tr][i - 1] == 1) {
                            train[tr][i] = 1;
                            train[tr][i - 1] = 0;
                        }
                    }
                }
                break;
            case 4:
                for(int i = 0; i < 20; i++) {
                    if(i != 19) {
                        if(train[tr][i + 1] == 1) {
                            train[tr][i] = 1;
                            train[tr][i + 1] = 0;
                        }
                    }
                }
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}