#include <bits/stdc++.h>
using namespace std;
string reversed_string(string s)
{
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    string s;
    cin >> s;
    map<char, int> mp_odd;
    map<char, int> mp_even;
    for (char &ch : s)
    {
        if (mp_odd.find(ch) != mp_odd.end())
        {
            mp_even[ch] = mp_odd[ch] + 1;
            mp_odd.erase(ch);
        }
        else if (mp_even.find(ch) != mp_odd.end())
        {
            mp_odd[ch] = mp_even[ch] + 1;
            mp_even.erase(ch);
        }
        else
        {
            mp_odd[ch] = 1;
        }
    }
    if (mp_odd.size() > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    string res = "";
    for (auto &e : mp_even)
    {
        res += string(e.second / 2, e.first);
    }
    string middle = "";
    for (auto &e : mp_odd)
    {
        middle += string(e.second, e.first);
    }
    cout << (res + middle + reversed_string(res));
}