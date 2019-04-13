#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

struct node
{
    int r, c;
    int count;
    vector<vector<bool>> board;
    vector<pair<int, int>> route;
    bool ok;
};


node f(int R, int C)
{
    vector<vector<bool>> board(R, vector<bool>(C, false));

    node n;
    n.c = -1451;
    n.r = -3331;
    n.count = 0;
    n.board = board;

    stack<node> s;
    s.push(n);

    while(!s.empty())
    {
        n = s.top();
        s.pop();

        if( n.route.size() == R * C )
        {
            n.ok = true;
            return n;
        }

        for( int r = 0; r < R; r++ )
        {
            for( int c = 0; c < C; c++ )
            {
                if( n.board[r][c] == false )
                {
                    node next = n;
                    next.r = r;
                    next.c = c;

                    if( n.r != r && n.c != c && r - c != n.r - n.c && r + c != n.r + n.c )
                    {
                        next.count = n.count + 1;
                        next.route.push_back(make_pair(next.r + 1, next.c + 1));
                        next.board[r][c] = true;
                        s.push(next);
                    }
                }
            }
        }
    }

    return n;
}


int main()
{
    int T, R, C;
    cin >> T;

    for( int t = 1; t <= T; t++ )
    {
        cin >> R >> C;

        node res = f(R, C);

        if( res.ok == true )
        {
            cout << "Case #" << t << ": " << "POSSIBLE" << endl;
            for( auto a : res.route )
            {
                cout << a.first << " " << a.second << endl;
            }
        }
        else
        {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
        }
    }
}