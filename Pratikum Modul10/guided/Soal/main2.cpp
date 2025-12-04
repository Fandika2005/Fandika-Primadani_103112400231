#include <iostream>
#include "bstree2.h"
#include "bstree2.cpp"

using namespace std;

int main() {
    cout << "TUGAS 3: PreOrder & PostOrder Traversal" << endl;
    
    address root = Nil;

    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);

    cout << "\nPreOrder  : ";
    printPreOrder(root);
    
    cout << "\nInOrder   : ";
    printInorder(root);
    
    cout << "\nPostOrder : ";
    printPostOrder(root);
    
    cout << endl << endl;
    cout << "Kedalaman   : " << hitungKedalaman(root, 0) << endl;
    cout << "Jumlah Node : " << hitungNode(root) << endl;
    cout << "Total Info  : " << hitungTotal(root) << endl;

    return 0;
}