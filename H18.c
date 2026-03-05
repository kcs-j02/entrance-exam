/*
H18の過去問のコード
バブルソートとクイックソートを実装している
個人的に2023年の試験で出題されると予想してる
→全く予想的中ならず
*/

#include <stdio.h>

// aとbの大小を比較する
int comp(int a, int b) {
    if (a < b) {
        return 1;
    } else {
        return 0;
    }
}

// aとbの値を交換する
void swap(int *a, int *b) {
    int t;
    t = *a; *a = *b; *b = t;
}

//バブルソート（昇順にソートする）
void sort1(int a[], int n) {
    int i, j;
    //iはソートができているところを示している。jが後ろから前にきて、一つずつ大小を関係を比較して、swapさせていく。そこでiのところまで来たら終了する。
    for (i = 0; i < n-1; i++) {
        for (j = n-1; j > i; j--) {
            if (comp(a[j], a[j-1])) {
                swap(&a[j], &a[j-1]); 
            }
        }
    }
}

// pivotを境に左側がpivotより小さくなるようにして、右側がpivot以上になるように分けることをpartitionという。ただpivotを境に大小が分かれているだけであって、ソートされているわけではないことに注意。
int partiton(int a[], int l, int r) {
    int i, j, pv;
    i = l-1; //範囲内における先頭
    j = r; //範囲内における最後
    pv = a[r];
    // 無限ループ（pivot以上とpivotより小さい数を交換し続ける）
    while(1) {
        while (comp(a[++i], pv)); // ここでpivotより大きい値のindexがわかる（pivotより大きいとreturn 0になるから）-> pivot以上の値を判定
        while(i < --j && comp(pv, a[j])); // i < --jはiより前に行かないようにするため。comp(pv, a[j])ですでにpivot以上の値を判定して、pivotより小さい時にreturn 0になる。 -> pivotより小さい値を判定
        if (i >= j) {
            //　先頭と最後が一緒になったらもう調べる必要がないからループを抜けて終了する
            break;
        }
        swap(&a[i], &a[j]); //pivot以上の値とpivotより小さい値を交換する
    }
    swap(&a[i], &a[r]); //ここまでくるとあとはpivotが適切な位置にいればいいため、最後に交換する
    return i; //最終的なpivotの位置を返り値にする
}

//クイックソートはpartitionを再帰的に行うことでソートするアルゴリズムである。pivotを境に左右に分かれて、その左右でそれぞれpartitionを行う。それを繰り返すことで最後は配列の先頭と最後が同じpartitionになる為、そこが再帰の最後に相当する。
void sort2_i(int a[], int l, int r) {
    int v;
    if (l >= r) {
        return;
    }
    //再帰的にpartitionを繰り返す。そうすることでソートされる
    v = partiton(a, l, r);
    sort2_i(a, l, v-1);
    sort_2_i(a, v+1, r);
}

//クイックソート
void sort2(int a[], int n) {
    sort2_i(a, 0, n-1);
}