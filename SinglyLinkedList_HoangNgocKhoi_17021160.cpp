/*--------------------
By: Hoang Ngoc Khoi
104 lines code
---------------------*/
#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *nextNode;
    Node(){
        value = 0;
        nextNode = NULL;
    }
};

Node* deleteNode(Node* head, int index);            //Phep delete 1 node
Node* addNode(Node* head, int index, int value);    //Phep them 1 node
void printNode(Node *head);           //In danh sach lien ket ra man hinh

int main(){
    cout << "Bai tap nghien cuu Single Linked List!" << endl;

    Node *pHead = new Node();                         //Tao node head
    int n;                             //So luong phep toan(delete, insert)
    cout << "Nhap so luong phep toan: ";
    cin >> n;

    cout << "Lan luot nhap vao cac phep toan: " << endl;
    string input;                              //Ten cua phep can nhap
    int _index, _value;                         //Vi tri, gia tri
    for(int i = 0; i < n; i ++) {
        cin >> input;
        if(input == "insert") {             //Neu la insert
            cin >> _index >> _value;        //Nhap tiep vi tri va gia tri
            pHead = addNode(pHead, _index, _value);     //Them vao
        }

        if(input == "delete") {                        //Neu la delete
            cin >> _index;                   //Nhap vi tri can xoa
            pHead = deleteNode(pHead, _index);
        }
    }

    printNode(pHead);                        //In ra danh sach cuoi cung

    return 0;
}


Node* deleteNode(Node* head, int index){
    Node *ptr = head;
    Node *ptr2 = NULL;
    for(int i = 0; i <= index; i++){
        if(index == 0) {                            //delete first
            head = ptr -> nextNode;
            delete ptr;
            return head;
        }

        if(i == index) {                              //delete random
            ptr2 -> nextNode = ptr -> nextNode;
            delete ptr;
            return head;
        }
        ptr2 = ptr;                                //ptr2 chay sau ptr
        ptr = ptr -> nextNode;
    }
}

Node* addNode(Node* head, int index, int value){
    Node *ptr = head;
    Node *newNode = new Node;
    newNode -> value = value;

    if(ptr -> nextNode == NULL && index == 0) {       //List chua co gi
        ptr -> value = value;
        return head;
    }

    for(int i = 0; i <= index; i++){
        if(index == 0){                               //add first
            newNode -> nextNode = ptr;
            return newNode;
        }

        if(i == (index - 1)){                         //add random
            newNode -> nextNode = ptr -> nextNode;
            ptr -> nextNode = newNode;
            return head;
        }

        ptr = ptr -> nextNode;                        //Tang bien ptr
    }
}

void printNode(Node *head){                           //Print node
    Node *ptr = head;
    cout << "=> Danh sach lien ket hien tai la: ";
    while(ptr != NULL){
        cout << ptr -> value << " ";
        ptr = ptr -> nextNode;
    }
}
