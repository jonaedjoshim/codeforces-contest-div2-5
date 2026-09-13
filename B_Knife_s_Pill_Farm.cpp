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
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (m == 1)
        {
            cout << *max_element(a.begin(), a.end()) << endl;
            continue;
        }

        priority_queue<long long> pq;
        long long sum = 0;

        for (int i = 0; i < m - 1; i++)
        {
            pq.push(a[i]);
            sum += a[i];
        }

        long long ans = LLONG_MIN;

        for (int i = m - 1; i < n; i++)
        {
            ans = max(ans, (long long)m * a[i] - sum);

            pq.push(a[i]);
            sum += a[i];

            if ((int)pq.size() > m - 1)
            {
                sum -= pq.top();
                pq.pop();
            }
        }

        cout << ans << endl;
    }

    return 0;
}