#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


struct link{
    int val;
    link* next;
};

class LinkedList{
    private:
        link*  first;
    public:
        LinkedList(){
            first = NULL;
        }
        void additem(int d);
        void display();
};

void LinkedList::additem(int d){
    link* node = new link;
    node->val = d;
    node->next = first;
    first = node;
}

void LinkedList::display(){
    link* curr = first;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr = curr->next;
    }

}

int main(){
    LinkedList li;
    li.additem(5);
    li.additem(12);
    li.additem(15);
    li.display();
    return 0;
}