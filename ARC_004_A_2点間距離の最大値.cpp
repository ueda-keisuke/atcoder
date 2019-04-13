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

    vector<pair<int,int>> points;

    for( int n = 0; n < N; n++ )
    {
        int x, y;
        cin >> x >> y;

        points.push_back(make_pair(x, y));
    }

    float max = 0;

    for( int i = 0; i < points.size() - 1; i++ )
    {
        for( int j = 1; j < points.size(); j++ )
        {
            pair<int, int> p1 = points[i];
            pair<int, int> p2 = points[j];

            float edge = sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
            max = std::max(edge, max);
        }
    }

    cout << max << endl;
}