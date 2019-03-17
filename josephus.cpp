#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

using namespace std;

class LinkedList {
public:
    Node* head;
    Node* p;
    Node* curr;
    int length;

    LinkedList();
    ~LinkedList();

    void add(int data);
    void move(int interval);
    int remove();
    void print();
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    while(this->length != 0){
        remove();
    }
}

void LinkedList::add(int data){
    Node* newNode = new Node();
    newNode->data = data;

    if(this->length == 0){
        this->head = this->p = this->curr = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }else{
        this->p->next = newNode;
        newNode->prev = this->p;
        newNode->next = this->head;
        this->head->prev = newNode;
    }
    this->p = newNode;
    this->length++;
}

void LinkedList::move(int interval){
    for(int i=0; i<interval-1; i++){
        this->curr = this->curr->next;
    }
}

int LinkedList::remove(){
    Node* temp = this->curr;
    int data = temp->data;
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    this->curr = temp->next;
    this->length--;

    if(length == 0){
        this->head = this->p =this->curr = NULL;
    }

    delete temp;
    return data;
}

int main(){

    int num;
    int jump;
    cin >> num >> jump;

    LinkedList* list = new LinkedList();

    for(int i=1; i<=num; i++){
        list->add(i);
    }
    cout << "<";
    do{
        list->move(jump);
        int data = list->remove();
        if(list->length == 0){
            cout << data;
            break;
        }
        cout << data << ", ";
    }while(list->curr != NULL);
    cout << ">";
    return 0;
}