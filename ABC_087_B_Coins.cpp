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

int main()
{
    int A, B, C, X;
    int ans = 0;

    cin >> A >> B >> C >> X;

    for( int a = 0; a <= A; a++ )
    {
        for( int b = 0; b <= B; b++ )
        {
            for( int c = 0; c <= C; c++ )
            {
                if( (500 * a + 100 * b + 50 * c) == X )
                    ans++;
            }
        }
    }

    cout << ans << endl;
}