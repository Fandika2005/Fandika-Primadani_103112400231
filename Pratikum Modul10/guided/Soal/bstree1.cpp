#include "bstree.h"

using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    }
    if (x < root->info) {
        return findNode(x, root->left);
    }
    return findNode(x, root->right);
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}
int hitungNode(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + hitungNode(root->left) + hitungNode(root->right);
    }
}
int hitungTotal(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return root->info + hitungTotal(root->left) + hitungTotal(root->right);
    }
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    } else {
        int kiri = hitungKedalaman(root->left, start + 1);
        int kanan = hitungKedalaman(root->right, start + 1);
        
        if (kiri > kanan) {
            return kiri;
        } else {
            return kanan;
        }
    }
}