# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int a[1000];
int n;

inline void init() {
    memset(a, 0, sizeof(a));
    n = 0;
}

inline int get_x(int locate) {
    if (locate > n || locate < 1) return -1;
    return a[locate];
}

inline int get_length() {
    return n;
}

inline int locate_x(int x) {
    //if (locate > n || locate <1) return -1;
    for (int i = 1; i <= n; i++)
        if (a[i] == x) return i;
    return -1;
}

inline int get_pre(int locate) {
    if (locate > n || locate <= 1) return -1;
    return a[locate - 1];
}

inline int get_suc(int locate) {
    if (locate >= n || locate < 1) return -1;
    return a[locate + 1];
}

inline int insert(int locate, int x) {
    if (!n) {
        a[1] = x;
        n++;
        return 0;
    }
    if (locate > n || locate < 1) return -1;
    for (int i = n; i >= locate; i--)
        a[i + 1] = a[i];
    a[locate] = x;
    n++;
    return 0;
}

inline int delete_x(int locate) {
    if (locate > n || locate < 1) return -1;
    for (int i = locate; i <= n; i++) a[i] = a[i + 1];
    n--;
    return 0;
}

inline int judge() {
    return n ? 0 : 1;
}

inline void bfs() {
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}

int main() {
    puts("itz homework. plz judge.");
    for (;;) {
        int opt;
        puts("put the order you want to check");
        puts("1.init\n2.get_x\n3.locate_x\n4.get_pre\n5.get_suc\n6.insert\n7.delete_x\n8.judge_empty\n9.bfs\n10.get_length\n-1.break");
        puts("plz input"), scanf("%d", &opt);
        if (opt == 1) init();
        if (opt == 2) {
            int x;
            scanf("%d", &x);
            x = get_x(x);
            if (x == -1) puts("illegal");
            else printf("%d\n", x);
        }
        if (opt == 3) {
            int x;
            scanf("%d", &x);
            x = locate_x(x);
            if (x == -1) puts("illegal");
            else printf("%d\n", x);
        }
        if (opt == 4) {
            int x;
            scanf("%d", &x);
            x = get_pre(x);
            if (x == -1) puts("illegal");
            else printf("%d\n", x);
        }
        if (opt == 5) {
            int x;
            scanf("%d", &x);
            x = get_suc(x);
            if (x == -1) puts("illegal");
            else printf("%d\n", x);
        }
        if (opt == 6) {
            puts("plz input locate and value");
            int x, locate;
            scanf("%d%d", &locate, &x);
            x = insert(locate, x);
            if (x == -1) puts("illegal");
            else puts("success");
        }
        if (opt == 7) {
            int x;
            scanf("%d", &x);
            x = delete_x(x);
            if (x == -1) puts("illegal");
            else puts("success");
        }
        if (opt == 8) {
            int x;
            x = judge();
            if (x == 0) puts("empty");
            else printf("not empty .the length is %d\n", x);
        }
        if (opt == 9) {
            puts("values are as follows");
            bfs();
        }
        if (opt == 10) {
            int x;
            x = get_length();
            printf("%d\n", x);
        }
        if (opt == -1) break;
    }
    puts("thankz");
}