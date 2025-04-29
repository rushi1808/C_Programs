#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;
node* createNode(int data){
	node* nn=(node*)malloc(sizeof(node));
	nn->data=data;
	nn->next=NULL;
	return nn;
}
void printLL(node* curr){
	node* temp=curr;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
node* mergeLL(node* l1,node* l2){
	if(l1==NULL)return l2;
	if(l2==NULL)return l1;
	node* head;
	if(l1->data<=l2->data){
		head=l1;
		head->next=mergeLL(l1->next,l2);	
	}
	else{
			head=l2;
		head->next=mergeLL(l1,l2->next);
	}
	return head;
}
int main(){
	node* l1=createNode(2);
	l1->next=createNode(4);
		printf("1st linklist\n");
	printLL(l1);
		node* l2=createNode(3);
	l2->next=createNode(5);
	printf("\n2st linklist\n");
	printLL(l2);
	
	node* head=mergeLL(l1,l2);
		printf("\nfinal linklist\n");
	printLL(head);
return 0;	
}