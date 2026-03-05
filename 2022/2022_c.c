/*
2022年の最新年度のコード(c)
最長共通部分文字列、最長共通部分列、編集距離（レーベンシュタイン距離)
この(c)は過去問と比較しても、かなり難しい部類だと思います。なので、本番はこうなりそうだな程度に解答して違う問題に時間を割きましょう
この解説はこちらの鉄則本の解説が非常にわかりやすいので、そちらを参考にしてください（URLは下記）
→https://github.com/E869120/kyopro-tessoku/blob/main/editorial/chap04/chap04.pdf
*/

#include <stdio.h>

int Levenshtein(char s1[], char s2[], int s1_len, int s2_len) 
{ 
    int i, j, r, mat[6][6];
    for (i = 0; i < s1_len+1; i++) {
        mat[i][0] = 2 * i;
    }
    for (i = 0; i < s1_len+1; i++) {
        mat[0][i] = 2 * i;
    }
    for (i = 0; i < s1_len; i++) {
        for (j = 0; j < s2_len; j++) {
            if (s1[i] == s2[j]) {
                r = 0;
            } else {
                r = 3;
            }
            if (mat[i][j] + r < mat[i][j+1] + 2 && mat[i][j] + r < mat[i+1][j] + 2) {
                mat[i+1][j+1] = mat[i][j] + r;
            } else if (mat[i][j+1] + 2 < mat[i+1][j] + 2) {
                mat[i+1][j+1] = mat[i][j+1] + 2;
            } else {
                mat[i+1][j+1] = mat[i+1][j] + 2;
            }
        }
    }
    return mat[i][j];
}