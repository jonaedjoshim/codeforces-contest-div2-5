#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        vector<int> pos;

        for (int i = 0; i < n; i++)
        {
            if (p[i] != i + 1)
            {
                pos.push_back(i);
            }
        }

        bool ok = true;

        for (int l = 0, r = (int)pos.size() - 1; l <= r; l++, r--)
        {
            if (p[pos[l]] != pos[r] + 1)
            {
                ok = false;
                break;
            }

            if (p[pos[r]] != pos[l] + 1)
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}