#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Tree.h"

link Create(struct Item msg, link pRight, link pLeft) {//create a new tree node using malloc
	link pNewNode = (link)malloc(sizeof(*pNewNode)); //allocate memory
	if (!pNewNode) {//if failed to allocate memory exit. 
		printf("memory allocation failed");
		exit(1); 
	}
	pNewNode->msg = msg; 
	pNewNode->pLeft = pLeft; 
	pNewNode->pRight = pRight; 
	return pNewNode; 
}

void TraverseInOrder(link HeadRoot) {
	
	if (HeadRoot == NULL) {// if head root is null return 0
		return; 
	}
	TraverseInOrder(HeadRoot->pLeft); //visit left subtree first
	printf("%c ", HeadRoot->msg.RandChar);
	TraverseInOrder(HeadRoot->pRight); //then visit right subtree
	return; //return 0
}

void InitTree() {//create an empty binary search tree
	HeadRoot = NULL; //start empty
}

link insert(link HeadRoot, ITEM item) {//inserts a new char 
	if (HeadRoot == NULL) {
		return Create(item, NULL, NULL); 
	}
	int rc = item.RandChar - HeadRoot->msg.RandChar;//compares wheter to go left or right
	if (rc < 0) {
		HeadRoot->pLeft = insert(HeadRoot->pLeft, item); //go left and rerusvely call insert()
	}
	else {
		HeadRoot->pRight = insert(HeadRoot->pRight, item);//go right and recursvely call insert()
	}
	return HeadRoot; 
}

link Search(link HeadRoot, char* SearchKey) {
	if (HeadRoot == NULL) {
		return NULL; //NULL if headroot cant be found
	}

	if (SearchKey == HeadRoot->msg.RandChar) {
		return HeadRoot; //return if the node is found 
	}
	if (SearchKey < HeadRoot->msg.RandChar) {
		return Search(HeadRoot->pLeft, SearchKey);//search left
	}
	else {
		return Search(HeadRoot->pRight, SearchKey);//search right 
	}
}

int Count(link HeadRoot) {//count nodes 
	if (HeadRoot == NULL) {//if headroot is nothing 
		return 0;// return 0
	}
	else {//else count nodes in both left and right subtrees (recuresively) 
		return (Count(HeadRoot->pLeft) + Count(HeadRoot->pRight) + 1); 
	}
}
int Height(link HeadRoot){ //determine tree height 
	int LeftH, RightH; 
	if (HeadRoot == NULL) {
		return 0; 
	}
	//traverse the entrie tree to get the height of each subtree recursively
	LeftH = Height(HeadRoot->pLeft);
	RightH = Height(HeadRoot->pRight); 
	//the taller subtree determines the height
	if (LeftH > RightH) {
		return (LeftH + 1); 
	}
	else {
		return (RightH + 1); 
	}
} 