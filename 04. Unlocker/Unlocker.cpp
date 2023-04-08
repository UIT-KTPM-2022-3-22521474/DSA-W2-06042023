#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    int count[10] = { 0 };
    for (char c : s) {
        int digit = c - '0';
        sum += digit;
        count[digit]++;
    }
    if (sum % 3 == 1) {
        if (count[1] > 0) {
            for (int i = s.size() - 1; i >= 0; i--) {
                if ((s[i] - '0') == 1) {
                    s.erase(i, 1);
                    break;
                }
            }
        }
        else {
            int cnt = 0;
            for (int i = 2; i <= 8; i += 3) {
                cnt += count[i];
            }
            if (cnt >= 2) {
                int removed = 0;
                for (int i = s.size() - 1; i >= 0 && removed < 2; i--) {
                    if ((s[i] - '0') == 2 || (s[i] - '0') == 5 || (s[i] - '0') == 8) {
                        s.erase(i, 1);
                        removed++;
                    }
                }
            }
            else {
                cout << "-1\n";
                return 0;
            }
        }
    }
    else if (sum % 3 == 2) {
        if (count[2] > 0) {
            for (int i = s.size() - 1; i >= 0; i--) {
                if ((s[i] - '0') == 2) {
                    s.erase(i, 1);
                    break;
                }
            }
        }
        else {
            int cnt = 0;
            for (int i = 1; i <= 7; i += 3) {
                cnt += count[i];
            }
            if (cnt >= 2) {
                int removed = 0;
                for (int i = s.size() - 1; i >= 0 && removed < 2; i--) {
                    if ((s[i] - '0') == 1 || (s[i] - '0') == 4 || (s[i] - '0') == 7) {
                        s.erase(i, 1);
                        removed++;
                    }
                }
            }
            else {
                cout << "-1\n";
                return 0;
            }
        }
    }
    sort(s.rbegin(), s.rend());
    while (s.size() > 1 && s.back() == '0') {
        s.pop_back();
    }
    cout << s << endl;
    return 0;
}