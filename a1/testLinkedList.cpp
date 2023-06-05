#include"LinkedList.h"
int main(){
    Node<int> *head=NULL;
    //adding 20 elements
    for(int i=0;i<20;i++){
        head=head->addbigin(head,i);
    }

    cout<<"The number of elements in the list: "<<head->returnels(head)<<endl;
    printf("\nadding at the end: ");
    head=head->addend(head,777);
    head->printlist(head);
    cout<<endl<<"Returning the first element of the list: "<<head->return_first(head)<<endl;
    cout<<"Returning the last element of the list: "<<head->return_last(head)<<endl;
    head=head->return_first_remove(head);
    head->printlist(head);//printing 
    head=head->return_last_remove(head);
    head->printlist(head);
    return 0;
} 