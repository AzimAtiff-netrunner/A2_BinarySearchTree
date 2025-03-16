#pragma once

 typedef struct Item {
    char RandChar;
}ITEM;

typedef struct TreeNode* link;
typedef struct TreeNode{
    struct Item msg; //the data
    link pLeft; //left subtree
    link pRight; //right subtree
}TreeNode;
link HeadRoot; //pointer to head root

link Create(struct Item msg, link pRight, link pLeft);

void TraverseInOrder(link HeadRoot);

void InitTree();

link insert(link HeadRoot, ITEM item);

link Search(link HeadRoot, char* SearchKey);

int Count(); //count nodes 

int Height(link HeadRoot); //determine tree height 

void FreeMem(link HeadRoot);
