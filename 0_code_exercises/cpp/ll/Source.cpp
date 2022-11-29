#include <conio.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node { int key; };
struct LL { Node a; LL* next; };
struct Stack { Node a; Stack* prev; };

void pop(LL** ll) {
    LL* begin = (*ll)->next;
    while (begin) {
        if (begin->next->next == NULL) {
            delete begin->next;
            begin->next = NULL;
            break;
        }
        begin = begin->next;
    }
}

void append(LL** ll, int v) {
    LL* begin = (*ll)->next;
    while (begin) {
        if (begin->next == NULL) {
            begin->next = new LL;
            begin->next->a.key = v;
            begin->next->next = NULL;
            break;
        }
        begin = begin->next;
    }
}

void ll_print(LL** ll) {
    if (*ll == NULL)
        return;

    LL* begin = *ll;
    while (begin) {
        cout << begin->a.key << " -> ";
        begin = begin->next;
    }
    cout << "NULL\n";
}

void init(LL** ll) {
    Node a[5] = { 1,2,3,4,5 };
    (*ll)->a.key = 0;
    (*ll)->next = NULL;

    LL* end = *ll;
    for (int i(0); i < 5; i++) {
        end->next = new LL;
        end = end->next;
        end->a = a[i];
        end->next = NULL;
    }
}

void pop(Stack** stack) {
    if ((*stack)->prev) {
        (*stack)->a = (*stack)->prev->a;
        *stack = (*stack)->prev;
    }
}

void stack_print(Stack** ll) {
    if (*ll == NULL)
        return;

    Stack* begin = *ll;
    cout << "NULL";
    while (begin) {
        cout << " <- " << begin->a.key;
        begin = begin->prev;
    }
    cout << endl;
}

void init(Stack** ll) {
    Node a[5] = { 1,2,3,4,5 };
    (*ll)->a.key = 0;
    (*ll)->prev = NULL;

    for (int i(0); i < 5; i++) {
        Stack* tmp = *ll;
        *ll = new Stack;
        (*ll)->prev = tmp;
        (*ll)->a = a[i];
    }
}

int main()
{
    LL* begin = NULL;
    begin = new LL;
    init(&begin);
    ll_print(&begin);
    pop(&begin);
    ll_print(&begin);
    append(&begin, 92);
    ll_print(&begin);

    Stack* stackBegin = NULL;
    stackBegin = new Stack;
    init(&stackBegin);
    stack_print(&stackBegin);
    pop(&stackBegin);
    stack_print(&stackBegin);

    (void)_getch();
    return 0;
}