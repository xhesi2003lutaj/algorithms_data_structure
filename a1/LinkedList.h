#include<iostream>
#include<cassert>
using namespace std;
/*
a generic list using templates using a doubly linked list
*/

template<class T>
class Node{
    private:
    T data;
    Node *next;
    Node *prev;
    public:
    Node(){}//constructor
    ~Node(){}// destructor
    //adding a new element at the front 
    Node *addbigin(Node *head,T dat);
    void printlist(Node* list);
    int returnels(Node *head);
    Node *addend(Node *list,T dat);
    /*returning 
    (with and without remove)
    the first and last
    element*/
    T return_first(Node *list);
    T return_last(Node *list);
    Node* return_first_remove(Node *list);
    Node* return_last_remove(Node *list);
};
template<class T>
Node<T> *Node<T>::addbigin(Node *head,T dat){
    Node *newnode=new Node;
    assert(newnode);

        newnode->data=dat;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
        return head;
}
template<class T>
void Node<T>::printlist(Node* list){
    while (list!=NULL)
    {
        cout<<list->data<<" ";
        list=list->next;
    }
    printf("\n");
}
//coun the elemnts in the list
template<class T>
int Node<T>::returnels(Node *head){
    int count=0;
    while (head!=NULL)
    {   count++;
        head=head->next;
    }
    return count;
}
template<class T>
Node<T> *Node<T>::addend(Node *list,T dat){
    Node *newnode=new Node;
    newnode->data=dat;
    Node *temp=list;
    while (temp->next!=NULL)
    {
        temp=temp->next;
        
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
   // list=temp; would return the first and last added
    return list;
}
template<class T>
T Node<T>::return_first(Node *list){
    
    return list->data;
}
template<class T>
T Node<T>::return_last(Node *list){
    while (list->next!=NULL)
    {
        list=list->next;
    }
    return list->data;
    
}
template<class T>
Node<T> *Node<T>::return_first_remove(Node *list){
        Node *temp=list;
        list=list->next;
        list->prev=NULL;
     
        temp->next=NULL;
        temp->prev=NULL;
        printf("\n");
        cout<<"First with remove "<<temp->data<<endl;
         delete temp;
         return list;
         
        
    }
template<class T>
Node<T>* Node<T>::return_last_remove(Node *list){
        Node *temp=list;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        printf("\n");
        cout<<"Last with remove: "<<temp->next->data<<endl;
        temp->next=NULL;
       // temp->prev=NULL;
        delete (temp->next);
        return list;
        

    }