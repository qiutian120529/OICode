#include<bits/stdc++.h>
using namespace std;
#define int long long

/* --------------- fast io --------------- */ // begin
namespace Fread {
const int SIZE = 1 << 21;
char buf[SIZE], *S, *T;
inline char getchar() {
    if (S == T) {
        T = (S = buf) + fread(buf, 1, SIZE, stdin);
        if (S == T) return '\n';
    }
    return *S++;
}
} // namespace Fread
namespace Fwrite {
const int SIZE = 1 << 21;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
    fwrite(buf, 1, S - buf, stdout);
    S = buf;
}
inline void putchar(char c) {
    *S++ = c;
    if (S == T) flush();
}
struct NTR {
    ~ NTR() { flush(); }
} ztr;
} // namespace Fwrite
#ifdef ONLINE_JUDGE
#define getchar Fread :: getchar
#define putchar Fwrite :: putchar
#endif
namespace Fastio {
struct Reader {
    template<typename T>
    Reader& operator >> (T& x) {
        char c = getchar();
        T f = 1;
        while (c < '0' || c > '9') {
            if (c == '-') f = -1;
            c = getchar();
        }
        x = 0;
        while (c >= '0' && c <= '9') {
            x = x * 10 + (c - '0');
            c = getchar();
        }
        x *= f;
        return *this;
    }
    Reader& operator >> (char& c) {
        c = getchar();
        while (c == ' ' || c == '\n') c = getchar();
        return *this;
    }
    Reader& operator >> (char* str) {
        int len = 0;
        char c = getchar();
        while (c == ' ' || c == '\n') c = getchar();
        while (c != ' ' && c != '\n' && c != '\r') { // \r\n in windows
            str[len++] = c;
            c = getchar();
        }
        str[len] = '\0';
        return *this;
    }
    Reader(){}
} cin;
const char endl = '\n';
struct Writer {
    template<typename T>
    Writer& operator << (T x) {
        if (x == 0) { putchar('0'); return *this; }
        if (x < 0) { putchar('-'); x = -x; }
        static int sta[45];
        int top = 0;
        while (x) { sta[++top] = x % 10; x /= 10; }
        while (top) { putchar(sta[top] + '0'); --top; }
        return *this;
    }
    Writer& operator << (char c) {
        putchar(c);
        return *this;
    }
    Writer& operator << (char* str) {
        int cur = 0;
        while (str[cur]) putchar(str[cur++]);
        return *this;
    }
    Writer& operator << (const char* str) {
        int cur = 0;
        while (str[cur]) putchar(str[cur++]);
        return *this;
    }
    Writer(){}
} cout;
} // namespace Fastio
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
/* --------------- fast io --------------- */ // end

const int N = 2e5 + 10, INF = -1e15;

int n, m, q, x[N];

struct Tag {
  int sum, val, pre, suf;
  bool operator==(const Tag &i) const {
    return (sum == i.sum) && (val == i.val) && (pre == i.pre) && (suf == i.suf);
  }
};

struct SegTree {
  Tag tag[N << 2];
  Tag I = {0, 0, 0, 0}, NOT = {0, INF, INF, INF};

  inline Tag comb(const Tag &tag1, const Tag &tag2) {
    Tag tmp;
    tmp.sum = tag1.sum + tag2.sum;
    tmp.pre = max(tag1.sum + tag2.pre, tag1.pre);
    tmp.suf = max(tag1.suf + tag2.sum, tag2.suf);
    tmp.val = max({tag1.val, tag2.val, tag1.suf + tag2.pre});
    return tmp;
  }

  inline void edit(int st, int v){
    tag[st].sum += v;
    tag[st].val += v;
    tag[st].pre += v;
    tag[st].suf += v;
  }

  inline void build(int o, int l, int r, int f){
    if(l == r){
      edit(o, x[l] * f);
      return ;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid, f);
    build(o << 1 | 1, mid + 1, r, f);
    tag[o] = comb(tag[o << 1], tag[o << 1 | 1]);
  }

  inline Tag query(int o, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr){
      return tag[o];
    }
    if (ql > r || qr < l) {
      return NOT;
    }
    int mid = (l + r) >> 1;
    return comb(query(o << 1, l, mid, ql, qr), query(o << 1 | 1, mid + 1, r, ql, qr));
  }
} T1, T2;

signed main(){
  // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> x[i];
  }
  T1.build(1, 1, n, 1);
  T2.build(1, 1, n, -1);
  for(int i = 1; i <= m; i++){
    int l, r;
    cin >> l >> r;
    cout << max(abs(T1.query(1, 1, n, l, r).val), abs(T2.query(1, 1, n, l, r).val)) << "\n";
  }
  return 0;
}