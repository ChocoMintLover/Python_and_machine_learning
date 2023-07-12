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

int go_board[19][19];
pair<int, int> dir[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
                         {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
bool is_s_win = false;
pair<int, pii> answer;

int dfs(int d, int in_a_row, int y, int x) {
    int ny = y + dir[d].first;
    int nx = x + dir[d].second;

    if(0 <= ny && ny < 19 && 0 <= nx && nx < 19 
    && go_board[ny][nx] == go_board[y][x]) {
        return dfs(d, in_a_row + 1, ny, nx);
    }
    return in_a_row;
}

void Solve() {
    forn(i, 19)
        forn(j, 19)
            cin >> go_board[i][j];
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            if(go_board[i][j] != 0) {
                for(int d = 0; d < 4; d++) {
                    int ni = i + dir[d].first;
                    int nj = j + dir[d].second;
                    if(go_board[ni][nj] == go_board[i][j]) {
                        int in_a_row = dfs(d, 2, ni, nj);
                        int bi = i + dir[(d + 4) % 8].first;
                        int bj = j + dir[(d + 4) % 8].second;
                        
                        if(go_board[bi][bj] == go_board[i][j])
                            in_a_row += dfs((d + 4) % 8, in_a_row + 1, bi, bj);
                        if(in_a_row == 5) {
                                int ai = i;
                                int aj = j;
                                if(d != 0) {
                                    while(go_board[ai + dir[d].first][aj + dir[d].second] 
                                    == go_board[ai][aj]) {
                                        ai -= dir[d].first;
                                        aj -= dir[d].second;
                                    }
                                } else { 
                                    while(go_board[ai - dir[d].first][aj - dir[d].second] 
                                    == go_board[ai][aj]) {
                                        ai -= dir[d].first;
                                        aj -= dir[d].second;
                                    }
                                }
                            ai++, aj++;
                            cout << go_board[i][j] << endl << ai << " " << aj << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "0" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}