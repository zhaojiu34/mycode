#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 1e5 + 1000;
int cnt;
int a[maxn], ans[maxn];
int n;
int gb(int l, int r)
{
    if (l >= r) return 0;
    int mid = l + r >> 1;
    gb(l, mid), gb(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            ans[k++] = a[i++];
        }
        else
            ans[k++] = a[j++], cnt += (mid - i + 1);
    }
    while (i <= mid) ans[k++] = a[i++];
    while (j <= r) ans[k++] = a[j++];
    for (i = l, j = 0; i <= r; i++, j++) {
        a[i] = ans[j];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    gb(0, n - 1);
    cout << cnt << endl;
    return 0;
}
