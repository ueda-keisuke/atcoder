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
    int T;
    cin >> T;

    for( int t = 1; t <= T; t++ )
    {
        int N;
        vector<string> words;
        cin >> N;

        for( int n = 0; n < N; n++ )
        {
            string s;
            cin >> s;
            std::reverse(s.begin(), s.end());
            words.push_back(s);
        }

        sort( words.begin(), words.end() );

        map<int,int> m;

        for( int i = 0; i < words.size() - 1; i++ )
        {
            for( int j = i + 1; j < words.size(); j++ )
            {
                int length = 0;
                unsigned long min = std::min(words[i].length(), words[j].length());
                for( int k = 0; k < min; k++ )
                {
                    if( words[i][k] != words[j][k] )
                    {
                        break;
                    }
                    length++;
                }

                if( length != 0 )
                    m[length]++;
            }
        }

//        for( auto x : m )
//        {
//            cout << x.first << "->" << x.second << endl;
//        }
//        cout << m.size() << endl;
//        cout << endl;

        cout << "Case #" << t << ": " << m.size() * 2 << endl;
    }
}