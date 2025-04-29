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
node* insertBST(node* root,int value){
	if(root==NULL){
		root=createNode(value);
	}
	if(value<root->data){
		root->left=insertBST(root->left,value);
	}
	else if(value>root->data){
			root->right=insertBST(root->right,value);
		}
	return root;
}
void leftTra(node* root){
	if(root){
		if(root->left){
			printf("%d ",root->data);
			leftTra(root->left);
		}
		else if(root->right){
			printf("%d ",root->data);
			leftTra(root->right);
		}
	}
	
}
// Function to print leaf nodes
void leafNodesTra(node* root) {
    if (root) {
        leafNodesTra(root->left);
        if (!root->left && !root->right) {
            printf("%d ", root->data);
        }
        leafNodesTra(root->right);
    }
}
// Function to print the right boundary (excluding leaf nodes, in reverse order)
void rightTra(node* root) {
    if (root) {
        if (root->right) {
            rightTra(root->right);
            printf("%d ", root->data);
        } 
        else if (root->left) {
            rightTra(root->left);
            printf("%d ", root->data);
        }
    }
}
void inOrder(node* root){
	if(root!=NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}
int boundaryTra(node* root){
	printf("%d ",root->data);
	
	leftTra(root->left);
	leafNodesTra(root);
	rightTra(root->right);
	
}
int main(){
	node* root=NULL;
	root=insertBST(root,56);
	insertBST(root,34);
	insertBST(root,62);
	insertBST(root,40);
	insertBST(root,52);
	insertBST(root,60);
	insertBST(root,76);
	
	printf("\n print your tree\n");
	
	inOrder(root);
		printf("\n print your boundary tree\n");
	boundaryTra(root);
	
	return 0;
}