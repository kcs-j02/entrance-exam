/*
2022年の最新年度のコードの(a)
最長共通部分文字列、最長共通部分列、編集距離
*/

#include <stdio.h>

int lcs(char s1[], char s2[], int s1_len, int s2_len)
{
    int i, j, k, mat[6][6];
    for (i = 0; i < s1_len+1; i++) {
        mat[i][0] = 0;
    }
    for (i = 0; i < s2_len+1; i++) {
        mat[0][i] = 0;
    }
    k = 0; //何文字共通かを表す変数なので、初期値は0にする
    //s1とs2で全探索する
    for (i = 0; i < s1_len; i++) {
        for (j = 0; j < s2_len; j++) {
            if (s1[i] == s2[j]) {
                mat[i+1][j+1] = mat[i][j] + 1; //連続して共通する場合
                if (mat[i+1][j+1] > k) {
                    k = mat[i+1][j+1]; //最大共通文字を入れる
                }
                else {
                    mat[i+1][j+1] = 0; //文字が異なればカウントをリセットする
                }
            }
        }
    }
    return k;
}