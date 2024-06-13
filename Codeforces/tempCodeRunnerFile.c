#include <bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    Node* nextNode;
}

class LinkedList{
    private:
        Node* first;
    public:
        LinkedList(){
            first = NULL;
        }
        void additem(int d);
        void show();
}

void LinkedList::additem(int d){
    Node* next = new Node;
    next->val = d;
    next->nextNode = first;
    first = next;
}

void LinkedList::show(){
    while(first!=NULL){
        cout<<first->val<<endl;
        first = first->next;

    }
}

int main(){
    LinkedList li;
    li.additem(5);
    li.additem(10);
    li.additem(13);
    li.show();
    return 0;

}