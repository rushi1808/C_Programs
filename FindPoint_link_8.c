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
node* findMergePoint(node* l1,node* l2){
	if(l1==NULL)return l2;
	if(l2==NULL)return l1;
	node* ptr1=l1;
	node* ptr2=l2;
	while(ptr1!=ptr2){
		ptr1=(ptr1==NULL)?l2:ptr1->next;
		ptr2=(ptr2==NULL)?l1:ptr2->next;
	}
	return ptr1;
}
int main(){
	node* link1=createNode(2);
	link1->next=createNode(4);
	link1->next->next=createNode(6);
	//2->4->6
	printf("\nprint your first linkList\n");
	printLL(link1);
	
	node* link2=createNode(3);
	link2->next=createNode(5);
	link2->next->next=createNode(7);
	//3->5->7
	printf("\n print your 2nd link List\n");
	printLL(link2);
	
	node* mergePoint=createNode(10);
	
	link1->next->next->next=mergePoint;
	link2->next->next->next=mergePoint;
	
	mergePoint->next=createNode(12);
	mergePoint->next->next=createNode(15);
	
	printf("\nlist 1st after mergePoint\n");
	printLL(link1);
	printf("\nlist 2nd after mergePoint\n");
	printLL(link2);
	node* merge=findMergePoint(link1,link2);
	if(merge!=NULL){
		printf("\n your merge point is= %d",merge->data);
	}else{
		printf(" mergePoint not found");
	}
	
	return 0;
}