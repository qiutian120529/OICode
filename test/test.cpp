#include <bits/stdc++.h>
#define ls rt << 1
#define rs rt << 1 | 1
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;

namespace solve{

    const int N = 1e5 + 10;

    struct SegmentTree {

        struct node {
            i64 cnt, sum;
        } tree[N << 2];
        
        void clear( int rt, int l, int r ) {
            if ( l == r ) {
                tree[rt].sum = 0;
                tree[rt].cnt = 0;
                return ;
            }
            int mid = ( l + r ) >> 1;
            clear( ls, l, mid );
            clear( rs, mid + 1, r );
            tree[rt].sum = tree[ls].sum + tree[rs].sum;
            tree[rt].cnt = tree[ls].cnt + tree[rs].cnt;
        }

        void insert( int rt, int l, int r, int p, int val ) {
            if ( p < l || r < p )
                return ;
            if ( l == r ) {
                tree[rt].cnt++;
                tree[rt].sum += val;
                return ;
            }
            int mid = ( l + r ) >> 1;
            insert( ls, l, mid, p, val );
            insert( rs, mid + 1, r, p, val );
            tree[rt].sum = tree[ls].sum + tree[rs].sum;
            tree[rt].cnt = tree[ls].cnt + tree[rs].cnt;
        }

        int query( int rt, int l, int r, int k ) {
            // std::cout << tree[rt].sum << ' ' << tree[rt].cnt  << ' ' << l << ' ' << r << '\n';
            if ( l == r ) { 
                return tree[rt].cnt * ( tree[rt].sum <= k);
            }
            int mid = l + r >> 1;
            if ( tree[ls].sum <= k )
                return tree[ls].cnt + query( rs, mid + 1, r, k - tree[ls].sum );
            else
                return query( ls, l, mid, k );
        }

    };

    int n, m;
    int a[N];

    std::map<int, int> mp;
    std::vector<std::pair<int, int>> k;
    SegmentTree tree;

    void solve(){
        k.clear();
        mp.clear();
        
        std::cin >> n >> m;
        tree.clear( 1, 1, n );
        for ( int i = 1; i <= n; i++ )
            std::cin >> a[i], k.push_back( { a[i], i } );
        
        std::sort( k.begin(), k.end() );

        for ( int i = 0; i < k.size(); i++ )
            mp[k[i].second] = i + 1;
        
        for ( int i = 1; i <= n; i++ ) {
            // std::cout << std::endl << i << std::endl;
            // tree.query( 1, 1, n, m - a[i] );
            std::cout << i - tree.query( 1, 1, n, m - a[i] ) - 1 << ' ';
            tree.insert( 1, 1, n, mp[i], a[i] );
        }
        std::cout << '\n';
    }

}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int T; std::cin >> T;
    while ( T-- )
        solve::solve();
    return 0;
}