/*
2022年の最新年度のコードの(b)
最長共通部分文字列、最長共通部分列、編集距離
この問題は難しいので、鉄則本p.125の最長共通部分列問題を参照するといいと思います。
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
    //ここまでは(a)と同じ
    for (i = 0; i < s1_len; i++) {
        for (j = 0; j < s2_len; j++) {
            if (s1[i] == s2[j]) {
                mat[i+1][j+1] = mat[i][j] + 1; //連続して共通する場合
            }
            else if (mat[i][j+1] > mat[i][j]) {
                mat[i+1][j+1] = mat[i][j+1]; 
            } else {
                mat[i+1][j+1] = mat[i+1][j];
            }
        }
    }
    return mat[i][j];
}