#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

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

        vector<long long> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        vector<long long> prefix(n + 1, 1);
        vector<long long> suffix(n + 1, 1);
        vector<long long> suffixSum(n + 1, 0);

        for (int i = 0; i < n - 1; i++)
        {
            prefix[i + 1] =
                prefix[i] * (n - 1 - i) % MOD;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] =
                suffix[i + 1] * (n - 1 - i) % MOD;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            suffixSum[i] =
                (suffixSum[i + 1] + a[i]) % MOD;
        }

        long long answer = 0;

        for (int i = 0; i < n - 1; i++)
        {
            long long count = n - 1 - i;

            long long differenceSum =
                (suffixSum[i + 1] - (a[i] % MOD) * count % MOD + MOD) % MOD;

            long long ways =
                prefix[i] * suffix[i + 1] % MOD;

            answer =
                (answer + differenceSum * ways) % MOD;
        }

        cout << answer << endl;
    }

    return 0;
}