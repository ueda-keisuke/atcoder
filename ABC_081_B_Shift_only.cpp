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
    int N;
    cin >> N;

    vector<int> a(N);

    for( int n = 0; n < N; n++ )
    {
        int A;
        cin >> A;
        a.push_back(A);
    }

    int count = 0;

    while(true)
    {
        bool exitflag = false;
        for( auto x : a )
        {
            if( x % 2 != 0 )
            {
                // 奇数があったら
                exitflag = true;
                break;
            }
        }

        if( exitflag == true )
        {
            break;
        }

        count++;
        for( auto &x : a )
        {
            x /= 2;
        }
    }

    cout << count << endl;
}