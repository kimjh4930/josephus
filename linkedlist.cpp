#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

using namespace std;

class LinkedList{
public:
    int length;
    Node* head;
    Node* p;
    
    LinkedList();
    ~LinkedList();
    
    void add (int data);
    void print();
};

LinkedList::LinkedList (){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList (){

    Node* next = head;
    Node* cur = NULL;

    while(next != NULL){
        cur = next;
        next = next->next;
        delete cur;
    }

    cout << "LIST DELETED";
}

void LinkedList::add (int data){
    Node* node = new Node();

    node->data = data;

    if(this->length == 0){
        this->head = node;
    }
    this->p->next = node;
    this->p = node;
    this->length++;

    // Node* node = new Node();
    // node->data = data;
    // node->next = this->head;
    // this->head = node;
    // this->length++;
}

void LinkedList::print(){
    Node* p = this->head;

    while( p != NULL ){
        cout << p->data << ", ";
        p = p->next;
    }
    cout << endl;
    // Node* head = this->head;
    // int i=1;
    // while(head) {
    //     cout << head->data << ", ";
    //     head = head->next;
    //     i++;
    // }
    // cout << endl;
}


int main(){

    LinkedList* list = new LinkedList();

    for(int i=0; i<10; i++){
        int number = (rand() % 100);
        list->add(number);
        cout << number << ", ";
    }
    cout << endl;
    list->print();                                                                                                                                     

    delete list;
    return 0;
}