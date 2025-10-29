#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *ptr_first = NULL;
Node *ptr_last = NULL;

// Tambah di awal
void add_first(int value)
{
    Node *newNode = new Node{value, NULL, ptr_first};

    if (ptr_first == NULL)
    {
        ptr_last = newNode; // List kosong
    }
    else
    {
        ptr_first->prev = newNode;
    }
    ptr_first = newNode;
}

// Tambah di akhir
void add_last(int value)
{
    Node *newNode = new Node{value, ptr_last, NULL};

    if (ptr_last == NULL) // (hapus titik koma di sini)
    {
        ptr_first = newNode;
    }
    else
    {
        ptr_last->next = newNode;
    }

    ptr_last = newNode;
}

// Tambah setelah nilai tertentu
void add_target(int targetvalue, int newvalue)
{
    Node *current = ptr_first;
    while (current != NULL && current->data != targetvalue)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        if (current == ptr_last)
        {
            add_last(newvalue);
        }
        else
        {
            Node *newNode = new Node{newvalue, current, current->next};
            current->next->prev = newNode;
            current->next = newNode;
        }
    }
}

// Tampilkan isi list
void view()
{
    Node *current = ptr_first;
    if (current == NULL)
    {
        cout << "List Kosong\n";
        return;
    }
    while (current != NULL)
    {
        cout << current->data << (current->next != NULL ? " <-> " : "");
        current = current->next;
    }
    cout << endl;
}

// Hapus node pertama
void delete_first()
{
    if (ptr_first == NULL)
        return;

    Node *temp = ptr_first;

    if (ptr_first == ptr_last)
    {
        ptr_first = NULL;
        ptr_last = NULL;
    }
    else
    {
        ptr_first = ptr_first->next;
        ptr_first->prev = NULL;
    }
    delete temp;
}

// Hapus node terakhir
void delete_last()
{
    if (ptr_last == NULL)
        return;

    Node *temp = ptr_last;

    if (ptr_first == ptr_last) // perbaikan kondisi
    {
        ptr_first = NULL;
        ptr_last = NULL;
    }
    else
    {
        ptr_last = ptr_last->prev;
        ptr_last->next = NULL;
    }
    delete temp;
}

// Hapus node dengan nilai tertentu
void delete_target(int targetvalue)
{
    Node *current = ptr_first;
    while (current != NULL && current->data != targetvalue)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        if (current == ptr_first)
        {
            delete_first();
            return;
        }
        if (current == ptr_last)
        {
            delete_last();
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

// Edit nilai node
void edit_node(int targetvalue, int newvalue)
{
    Node *current = ptr_first;
    while (current != NULL && current->data != targetvalue)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        current->data = newvalue;
    }
}

int main()
{
    add_first(10);
    add_first(5);
    add_last(20);
    cout << "Awal\t\t\t: ";
    view();

    delete_first();
    cout << "Setelah delete_first\t: ";
    view();

    delete_last();
    cout << "Setelah delete_last\t: ";
    view();

    add_last(30);
    add_last(40);
    cout << "Setelah tambah\t\t: ";
    view();

    delete_target(30);
    cout << "Setelah delete_target\t: ";
    view();

    add_target(40, 99);
    cout << "Setelah add_target(40,99): ";
    view();

    edit_node(99, 100);
    cout << "Setelah edit_node(99→100): ";
    view();

    return 0;
}
