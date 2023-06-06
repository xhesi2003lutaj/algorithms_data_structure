#include<iostream>
using namespace std;

class list{
		int data;
		list* next;

		public:
		list(){
				data=0;
				next=NULL;
		}
		list(int data){
				this->data=data;
				next=NULL;
		}
		list* insert(list* head,int data){


				if(head==NULL){
						//cout<<"inside insert\n";
						list* temp=new list(data);
						head=temp;
						return head;
				}else{
						list*newnode=new list(data);
						newnode->next=head;
						head=newnode;
						//cout<<"end of list insert \n";
						return head;
				}

		}
		void printlist(list* head){
				list* temp=head;
				while(temp!=NULL){
						cout<<temp->data<<" ";
						temp=temp->next;
				}
				cout<<endl;
		}
		//printf("\n");

};

class bst{
		int data;
		bst* left;
		bst* right;
		//bst* root=NULL;
		public:
		list* list=NULL;
		bst(int data);
		bst(){
				data=0;
				right=NULL;
				left=NULL;
		} 
		void dosth(){
				list->printlist(list);
		}


		bst* insert(bst* tree,int data);
		void printtree(bst* tree);
};
bst::bst(int data){

		this->data=data;

		right=left=NULL;
}
bst* bst::insert(bst* tree,int data){

		if(!tree){
				/*  bst* add=new bst;
					add->data=data;
					tree->root=add; */
				return new bst(data);
		}
		else{
				// bst* temp=tree;
				// while(temp!=NULL){
				if(data < tree->data){
						tree->left= insert(tree->left,data);
						//temp=temp->right;
				}else if(data> tree->data){
						tree->right=insert(tree->right,data);
						//temp=temp->left;
				}
				//}
		}
		return tree;
}
void bst::printtree(bst* tree){

		bst* temp=tree;
		if(tree==NULL){
				return;
		}else{
				printtree(tree->right);
				list=list->insert(list,tree->data);
				cout<<tree->data<<endl;

				printtree(tree->left);
		}
}


int main(){
		bst* tree=NULL;
		bst b;
		tree=b.insert(tree,5);
		b.insert(tree,4);
		b.insert(tree,3);
		b.insert(tree,2);
		b.insert(tree,1);
		b.insert(tree,10);
		cout<<"binary tree traversal\n";
		b.printtree(tree);
		cout<<"linked list ";
		b.dosth();
        printf("\nThe asymptotic time complexity of this algorithm:\nThe proccess of buliding the BST takes O(long n)\nAccressing every element in the tree to form the linked list O(n)\nBuilding  the linked list O(n), as we are adding at the beggining of the list\nPrinting also takes O(n).Overal time complexity is O(long n+ n +n+n)=O(n).\n");
       
		return 0;

}
