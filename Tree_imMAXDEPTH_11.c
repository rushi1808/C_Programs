#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;
node* createNode(int value){
	node* newNode=(node*)malloc(sizeof(node));
	newNode->data=value;
	newNode->left=NULL;	
	newNode->right=NULL;
	return newNode;
}
node* insertBST(node* root,int data){
	if(root==NULL){
		root=createNode(data);
	}
	 if(data<root->data){
	 	root->left=insertBST(root->left,data);
	 }
	 else if(data>root->data){
	 	root->right=insertBST(root->right,data);
	 }
	 return root;
}
void inOrder(node* root){
	if(root!=NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}

int main(){
	node* root=NULL;
	root=insertBST(root,50);
	insertBST(root,30);
	insertBST(root,70);
	insertBST(root,20);
	insertBST(root,40);
	insertBST(root,60);
	insertBST(root,80);
	printf("\n print your inorder traverse\n");
	inOrder(root);
	

	return 0;
}