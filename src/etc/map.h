#include "etc.h"








void mapping(int a[], int n) {
    vector<pii> _m;
    for (int i = 0; i < n; ++i) {
        _m.push_back(make_pair(a[i], i));
    }
    sort(_m.begin(), _m.end());

    int _t = 0;
    for (int i = 0; i < n; ++i) {
        a[ _m[i].second ] = _t;
        if (i + 1 < n && _m[i].first != _m[i + 1].first) {
            ++_t;
        }
    }
}
