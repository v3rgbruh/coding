#include <iostream>

struct Node
{
    Node* NextNode;
    Node* PrevNode;
    int* Data;
};

Node* EmplaceNode(Node* PreviousNode, int Data) {
    Node* NewNode = new Node();
    NewNode->PrevNode = PreviousNode;
    NewNode->Data = (int*)Data;

    if (!PreviousNode)
        return NewNode;
    
    Node* PrevNext = PreviousNode->NextNode;
    PreviousNode->NextNode = NewNode;
    NewNode->NextNode = PrevNext;
    
    return NewNode;
}

bool DeleteNode(Node* NodeToDelete) {
    Node* Prev = NodeToDelete->PrevNode;
    Node* Next = NodeToDelete->NextNode;
    if (Prev)
    {
        if (Next)
            Next->PrevNode = Prev;
        Prev->NextNode = Next;
        return true;
    }
    return false;
}

int TraverseNodes(Node* LastNode){
    Node* Last = LastNode;
    while (Last->PrevNode) {
        std::cout << reinterpret_cast<int>(Last->Data) << " -> ";
        Last = Last->PrevNode;
    };
    
    std::cout << reinterpret_cast<int>(Last->Data) << "\n";
    return 0;
}

void DeletingBanner() {
    std::cout << "\n.__________________________.\n";
    std::cout << "|   DELETING ONE ELEMENT   |\n";
    std::cout << ".__________________________.\n\n";
}

int main()
{
    Node* ll = EmplaceNode(nullptr, 5);
    ll = EmplaceNode(ll, 6);
    ll = EmplaceNode(ll, 3);
    auto ToDelete = ll = EmplaceNode(ll, 9);
    ll = EmplaceNode(ll, 10);
    ll = EmplaceNode(ll, 8);

    // Will print from last to first 
    // 8 -> 10 -> 9 -> 3 -> 6 -> 5
    TraverseNodes(ll);
    DeleteNode(ToDelete);
    DeletingBanner();
    // 8 -> 10 -> 3 -> 6 -> 5
    TraverseNodes(ll);

    return 0;
}

