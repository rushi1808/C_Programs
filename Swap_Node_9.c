#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;
node* createNode(int value){
	node* newNode=(node*)malloc(sizeof(node));
	newNode->data=value;
	newNode->next=NULL;
	return newNode;
}
void printLL(node* head){
	while(head!=NULL){
		printf("%d->",head->data);
		head=head->next;
	}
}
node* pairSwapping(node* head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	node* newhead=head->next;
	node* pre=NULL;
	node* curr=head;
	node* future=NULL;
	while(curr!=NULL&&curr->next!=NULL){
		future=curr->next;
		curr->next=future->next;
		future->next=curr;
		if(pre!=NULL){
		pre->next=future;	
		}
		pre=curr;
		curr=curr->next;
	}
	return newhead;
}

int main(){
	node* link1=createNode(1);
	link1->next=createNode(2);
	link1->next->next=createNode(3);
	link1->next->next->next=createNode(4);
	//1->2->3->
	printf("\nprint your first linkList\n");
	printLL(link1);
	
	node* head=pairSwapping(link1);
	printf("\n list after swapping\n");
	
	printLL(head);	
	return 0;
}