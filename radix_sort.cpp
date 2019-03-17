#include <iostream>

class Node {
public:
    int data;
    Node* next;
    // Node* prev;
};

using namespace std;

class LinkedList {
public:
    Node* head;
    Node* p;
    int length;

    LinkedList();
    ~LinkedList();

    void add(int data);
    int getValue(int index);
    void remove();
    void print();
};

LinkedList* arraylist[10];
int arr[10000];

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

    if(length == 0){
        this->head = newNode;
    }else{
        this->p->next = newNode;
    }
    this->p = newNode;
    this->length++;
}

void LinkedList::remove(){
    Node* temp = this->head;

    if(this->length == 1){
        // cout << "delete : " << temp->data << endl;
        delete this->head;
    }else{
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        this->p = temp;
        // cout<<"delete : " << temp->next->data<<endl;
        this->p->next = NULL;
        delete temp->next;
    } 
    this->length--;
}

int LinkedList::getValue(int index){
    Node* temp = this->head;
    int i=1;

    while(i <= index){
        temp = temp->next;
        i++;
    }

    return temp->data;

}

void LinkedList::print(){
    Node* curr = this->head;
    
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void inputList (int value, int div){

    int returnValue = value%(div*10);

    if(returnValue != 0){
        returnValue /= div;
    }

    LinkedList* tempList = arraylist[returnValue];
    tempList->add(value);
    
}

int* returnToArray (){
    int array[10000];
    int index = 0;

    for(int i=0; i<10; i++){
        if(arraylist[i]->head == NULL){
            continue;
        }
        Node* curr = arraylist[i]->head;

        while(curr != NULL){
            array[index] = curr->data;
            curr = curr->next;
            index++;
        }
    }

    return array;
}

int main(){

    int size = 0;
    cin >> size;
    int max = 0;

    for(int i=0; i<size; ++i){
        cin >> arr[i];
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int count=0;
    while(max != 0){
        max /= 10;
        count++;
    }

    for(int i=0; i<10; ++i){
        LinkedList* list = new LinkedList();
        arraylist[i] = list;
    }

    int* tempArr = arr;
    int div = 1;
    for(int j=0; j<count-1; ++j){
        for(int i=0; i<size; ++i){
            inputList(tempArr[i], div);
        }

        tempArr = returnToArray();

        div *= 10;
        for(int i=0; i<10; ++i){
            delete arraylist[i];
            LinkedList* list = new LinkedList();
            arraylist[i] = list;
        }
    }

    for(int i=0; i<size; i++){
        cout << tempArr[i] << " ";
    }
    cout << endl;
    return 0;

}