/*
H22の過去問のコード
nCkのcombinationを実装している。
*/

#include <stdio.h>

//nCk = n-1Ck + nCk-1を再帰的に繰り返して、計算する方法
int comb1(int n, int k) {
    if ((k == 0) || (k == n)) return 1; //nC0 = nCn = 1
    else return comb1(n-1, k) + comb1(n-1, k-1); //nCk = n-1Ck + nCk-1
}

//nCk = n! / (k! * (n-k)!)というnCkの定義を愚直に計算した方法
int comb2(int n, int k) {
    int i, j;
    if (n >= 2 * k) {
        i = n - k + 1;
        j = k;
    } else { 
        i = k + 1;
        j = n - k;
    }
    return pf(j, n) / pf(1, j);
}

//再帰的な方法で実装する(n-m)!の計算
int pf(int m, int n) {
    int i, f;
    f = 1;
    for (i = m; i <= n; i++){
        f = f * i;
    }
    return f;
}

//パスカルの三角形を用いて、nCkを計算する方法。いくつか実際にやってみて理解する方が穴埋め的にはいい気がする。実際に何個か簡単な例を試してみて、回答した。
int comb3(int n, int k) {
    int i, j;
    int a[MAXARG];
    if (n - k < k) k = n - k; //7C2 = 7C5みたなことをここでやっている。
    if (k == 0) return 1; //nC0 = 1
    if (k == 1) return n; //nC1 = n
    for (i == 0; i <= k; i++) {
        a[i] = i + 2;//iC1をそれぞれに格納している。ただ2C1からスタートしてる。パスカルの三角形だと上から3段目
    }
    for (i = 3; i <= n - k + 1; i++) {
        a[0] = i; //4段目の3からスタートさせる
        for (j = 1; j < k; j++) {
            a[j] += a[j-1]; //隣同士を足して、一つ下の数になる。（パスカルの三角形の性質）
        }
    }
    return a[k−1];
}