#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long TotalArea ( long long a[], long long r, long long n ) {
    long long area = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= r) {
            area += ( 1LL << a[i] ) * ( 1LL << a[i] );
        }
    }
    return area;
}

int main ( void ) {
    long long h, w, n, a[1001];
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int r = 0; r <= 25; r++) {
        long long lh = h / ( 1LL << r );
        long long lw = w / ( 1LL << r );
        long long la = lh * lw * ( 1LL << r ) * ( 1LL << r );
        long long aa = TotalArea ( a, r, n );
        if (aa > la) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}