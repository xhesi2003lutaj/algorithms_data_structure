#include<cstdlib>
#include<iostream>
using namespace std;

class bst{
		int data;
		bst* left;
		bst* right;
		//bst* root=NULL;
		public:
		
		bst(int data){
            this->data=data;
            left=right=NULL;

        }
		bst(){
				data=0;
				right=NULL;
				left=NULL;
		} 
        bst* insert(bst* tree,int data);
        void printree(bst* tree){
            if(tree==NULL){
                return;
            }
            else{
                printree(tree->left);
                cout<<tree->data<<" ";
                printree(tree->right);
            }
        }
};
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
class list{
    int data;
    list*next;
    public:
    bst *tree=NULL;
    bst b;
    list(){
        data=0;
        next=NULL;
    }
    list(int data){
        this->data=data;
        next=NULL;
    }
    void dosth(){
        tree->printree(tree);
    }
    list* insertlist(list*head,int data){

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
    void getelement(list*head){
        list*temp=head;
        tree=b.insert(tree,temp->data);
        temp=temp->next;
        int t;
        while(temp!=NULL){
            t=temp->data;
            b.insert(tree,t);
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    list* list=NULL;
    for(int i=0;i<=20;i++){
        list=list->insertlist(list,i);

    }
    cout<<"linked list\n";
    list->getelement(list);
    cout<<"BST from linked list\n";
    list->dosth();
    printf("\n");
    printf("\n  The serach timw complexity of the resulting binary tree is O(log n), as we are just inserting in the tree \n    and not accesing every single element as in the linked list\n   The asymtotic time complexity of the algorithm as a whole is O(n)+O(log n)+O(n)for printing= O(2n+log n)=O(n)\n\n");


}