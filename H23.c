/*
H23の過去問のコード
n-クイーン問題を実装している
*/

#include <stdio.h>
int a[1024];

//aの配列を先頭からカンマ区切りで出力する関数
void printa(int n) {
    int i;
    if (n > 0) printf("%d", a[0]);
    for (i = 1; i < n; i++) {
        printf(", %d", a[i]);
    }
    printf("\n");
}

// 駒が置けるかどうかをチェックしている
int check(int x, int y) {
    int k;
    for (k = 0; k < x; k++) {
        if (a[k] == y) return 0; //すでに効き筋であればreturn 0になる
    }
    return 1; //効き筋でなければreturn 1になる
}

//全パターン調べて解を求めるn-クイーン問題。n * nのマス全てで効き筋かどうかを調べる。出力は全パターンを列挙した形。0,1,2であれば3! = 6通り出力される
void f(int n, int x) {
    if (x >= n) {
        printa(n);
    }
    else {
        int y = 0;
        while (y < n) {
            if (check(x, y)) {
                a[x] = y;
                f(n, x+1);
            }
            y = y + 1;
        }
    }
}



int check(int x, int y) {
    int k;
    for (k = 0; k < x; k++) {
        if (a[k] == y ||
            a[k] == y + k - x || //右斜め上
            a[k] == y - k + x //右斜め下
        )
            return 0;
    }
    return 1;
}

//バックトラック法
/*
基本的な流れとしては、y行x列のマスを一つずつ調べ、置けるマスがあったら次の列へ移動する。全ての列で調べ終わったら無限ループから抜けて、実行終了する
*/
void f(int n, int x) {
    int y = 0;
    while(1){
        while (y < n) {
            if (check(x, y)) {
                a[x] = y;
                x = x + 1;
                if (x >= n) {
                    printa(n);
                    goto backtrack;
                }
                y = 0;
            }
            else {
                y = y + 1;
            }
        }
    backtrack:
        x = x - 1;
        if (x < 0) return;
        y = a[x] + 1; //ここがa[x]だと無限ループになるから注意
    }
}

int main(void) {
    f(3, 0);
    return 0;
}
