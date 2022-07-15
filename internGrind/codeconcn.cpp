#include <bits/stdc++.h>
using namespace std;
int t[1000000];
int a[100000];
int n, k;

//approach is based on the fact of processing ranges using BIT or segment tree

void buildtree(int s, int e, int idx)
{
    if (s == e)
    {
        t[idx] = a[s];
        return;
    }
    int mid = s + (e - s) / 2;
    buildtree(s, mid, 2 * idx + 1);
    buildtree(mid + 1, e, 2 * idx + 2);
    t[idx] = t[2 * idx + 1] ^ t[2 * idx + 2];
}

int qry(int s, int e, int idx, int l, int r)
{
    if (l > e or s > r)
    {
        return 0;
    }
    if (l <= s and r >= e)
    {
        return t[idx];
    }
    int mid = s + (e - s) / 2;
    return qry(s, mid, 2 * idx + 1, l, r) ^ qry(s, mid, 2 * idx + 1, l, r);
}


int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    buildtree(0, n - 1, 0);
    int i = 0;
    int cnt;
    if(qry(0, n - 1, 0, i, i + k - 1)>0){
        cnt=1;
    }else{
        cnt=0;
    }
    for (i = 1; i + k < n; ++i)
    {
        if(abs(qry(0, n - 1, 0, i - 1, i + k- 2) - qry(0, n - 1, 0, i, i + k - 1))>0)
            cnt++;
    }

    cout << cnt << endl;
}
