#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set < int > a;
int b[100005];
bool ok = true;
vector < int > arr;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x = 0, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        a.insert(b[i]);
    }
    if (k < a.size())
    {
        int d = 0;
        for (auto i : a)
        {
            d++;
            cout << i << " ";
            if (d == k) 
                break;
        }
    }
    else
    {
        for (auto i : a)
            arr.push_back(i);
        sort(b, b + n);
        int j = k - a.size();
        int u = 0;
        while (j > 0)
        {
            ok = true;
            while (u < n - 1)
            {
                if (b[u] == b[u + 1])
                {
                    arr.push_back(b[u]);
                    j--;
                    ok = false;
                }
                u++;
                if (ok == false) 
                    break;
            }
        }
        sort(arr.begin(), arr.end());
        for (auto i : arr) 
            cout << i << " ";
    }
}