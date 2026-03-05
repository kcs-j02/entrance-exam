/*
2020の過去問のコード
マージソートを中心にソート関連の実装
*/

#include <stdio.h>

//バブルソート
void sort_a(int a[], int n) {
    int i, j, tmp;

    for (i = 0; i < n -1; ++i) {
        fpr (j = n - 1; i < j; --j) {
            if (a[j] < a[j - 1]) {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}

//挿入ソート
/*
挿入ソートはi番目の数字をtmpに入れて、i番目以降の数値と比較していく。途中でより小さい数字になったらtmpを交換し、それより前の配列と比較して適切な位置まで持っていく。バブルの少し改良？されたver
*/
void sort_b(int a[], int n) {
    int i, j, tmp;

    for (j = 1; j < n; ++j) {
        tmp = a[j];
        i = j - 1;
        while (0 <= i && tmp < a[i]) {
            a[i + 1] = a[i];
            --i;
        }
        a[i + 1] = tmp;
    }
}

//マージソート
int mergesort(int a[], int begin, int end, int w[]) {
    int mid = (begin + end) / 2;
    int i = begin, j = mid + 1, k, c = 0;

    printf("(%d, %d)\n", begin, end);
    //begin == endの時は最小単位まで分けられたということ
    if (begin < end) {
        mergeq(a, begin, mid, w); //半分に分けた前半
        mergesort(a, mid + 1, end, w); //半分に分けた後半

        for (k = begin; k <= end; ++k) {
            if (mid < i) {
                w[k] = a[j++]; //左側のブロックがすでにマージし終えた場合に右側のブロックを順にマージしていく
            } else if (end < j) {
                w[k] = a[i++]; //右側のブロックがすでにマージし終えた場合に左側のブロックを順にマージしていく
            } else {
                /* ++c; */
                if (a[i] < a[j]) {
                    w[k] = a[i++]; //左側のブロックの値の方が小さいため、左の値をマージ
                } else {
                    w[k] = a[j++]; //右側のブロックの値の方が小さいため、右の値をマージ
                }
            }
        }
        for (k = begin; k <= end; ++k) {
            a[k] = w[k]; //最後に一時的に格納したwからaに全て移す
        }
    }
    return 0;
}