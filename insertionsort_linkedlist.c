#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
	int data;
	struct node* next;
};typedef struct node Node;


Node *push(Node *head,int val){
	printf("in push\n");
	Node *newnode=malloc(sizeof(Node));
	assert(newnode);
	newnode->data=val;

	if(head==NULL || head->data>=newnode->data){
		newnode->next=head;
		head=newnode;
		return head;
	}
	Node* current=head;printf("blablabla\n");
    while(current->next!=NULL && current->next->data < newnode->data){
		printf("inside while\n");
		current=current->next;	
	}


		newnode->next=current->next;
		current->next=newnode;
		//head=current;
		return head;
	
	

}
void printlist(Node* head){
	Node *temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


int main(){
	Node *mylist=NULL;
	mylist=push(mylist,6);
	
	mylist=push(mylist,9);
	mylist=push(mylist,9);
	mylist=push(mylist,9);
	mylist=push(mylist,9);
	mylist=push(mylist,8);
	
	mylist=push(mylist,7);
	mylist=push(mylist,1);
	mylist=push(mylist,2);
	mylist=push(mylist,3);
	//push(&mylist,2);
	mylist=push(mylist,10);
	mylist=push(mylist,1);
	printlist(mylist);

	return 0;
}