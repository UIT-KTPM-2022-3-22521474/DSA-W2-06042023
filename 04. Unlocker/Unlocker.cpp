#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end(), greater<char>());
    int sum = 0;
    for (char c : s) 
        sum += (c - '0');
    if (sum % 3 == 0)
        cout << s << endl;
    else 
    {
        string ans = "";
        if (sum % 3 == 1) 
        {
            bool deleted = false;
            for (char c : s) 
            {
                if ((c - '0') % 3 == 1) 
                {
                    deleted = true;
                    continue;
                }
                if ((c - '0') % 3 == 2) 
                {
                    if (deleted) 
                        ans += c;                  
                    else
                        deleted = true;
                    continue;
                }
                ans += c;
            }
        }
        else 
        {            
            bool deleted = false;
            for (char c : s) {
                if ((c - '0') % 3 == 2)
                {
                    deleted = true;
                    continue;
                }
                if ((c - '0') % 3 == 1) 
                {
                    if (deleted)
                        ans += c;                    
                    else
                        deleted = true;                   
                    continue;
                }
                ans += c;
            }
        }
        if (ans == "")
            cout << "-1" << endl;
        else
            cout << ans << endl;        
    }
    return 0;
}