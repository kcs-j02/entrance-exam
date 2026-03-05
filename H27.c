/*
H27の過去問のコード
長さ1以上の連続する項の和で最大のものを求める
*/

#include <stdio.h>

//xとyの大きい方が出力される
int max(int x, int y) {
    return x > y ? x : y; //xとyで大きい方がreturnされる
}

//iからjまでの合計を求める関数
int sum(int a[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s = s + a[k];
    }
    return s;
}

//愚直に全パターンの計算をする方法。計算量はO(n^3)
int f(int a[], int n) {
    int s = a[0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            s = max(s, sum(a, i, j));
        }
    }
    return s;
}

//sumをなくすことでforループを一つ減らして、計算量がO(n^2)になっている
int f(int a[], int n) {
    int s = a[0];
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = i; j < n; j++) {
            t = t + a[j]; //これがsumの代わりになっている。前回までの計算を利用することで効率よくsumが計算できる
            s = max(s, t);
        }
    }
    return s;
}

//a0~an-1までの項の和
int g(int a[], int n) {
    int t = a[0];
    for (int k = 1; k < n; k++) {
        t = max(t + a[k], a[k]);
    }
    return t;
}

//比較。計算量はfとgでそれぞれforループを一回ずつして計2回なので、O(n^2)となる
int f(int a[], int n) {
    int s = a[0];
    for (int k = 1; k < n; k++) {
        s = max(s, g(a, k + 1));
    }
    return s;
}

//fとgをまとめたので、forループがさらに一つ減って、計算量はO(n)となる
int f(int a[], int n) {
    int t = a[0], s = a[0];
    for (int k = 1; k < n; k++) {
        t = max(t + a[k], a[k]);
        s = max(s, t);
    }
    return s;
}