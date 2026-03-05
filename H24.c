/*
H24の過去問のコード
二分探索木を実装している
*/


#include <stdio.h>

//構造体としてnodeを作成。親の値とその左右の子の値を格納する
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node;

//二分探索
/*
大前提として、二分木は親の値を基準とした時に、右側が親より大きく、左側が親より小さくなる。そして全て左詰めで構成される。
目的の値をkeyとする。
*/
node* search(node *ptr, int key) {
    if (ptr == NULL) return (NULL);
    if (key < ptr -> key)       return (search(ptr -> left, key)); //親より目的の値が小さければ左側に移動する
    else if (key == ptr -> key) return (ptr); //親と目的の値が同じであれば、その時点で探索終了
    else                        return (search(ptr -> right, key)); //親より目的の値が大きければ右側に移動する
}

//insertをする
node* insert(node *root, int key) {
    node *new, *ptr;
    if (new = malloc(sizeof(node) == NULL)) exit(1); //メモリは十分に準備されている
    new -> key = key;
    new -> left = new -> right = NULL;
    if (root == NULL) return (new); //first node as root。一番最初はこれ
    ptr = root;
    while (ptr != NULL) {
        if (key < ptr -> key) {
            if (ptr -> left == NULL) {
                ptr -> left = new; break;
            }
            ptr = ptr -> left;
        } else {
            if (ptr -> right == NULL) {
                ptr -> right = new; break;
            }
            ptr = ptr -> right ;
        }
    }
    return (root);
}