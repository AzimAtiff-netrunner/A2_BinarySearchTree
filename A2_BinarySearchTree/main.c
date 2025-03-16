#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tree.h"

int main() {
	srand(time(NULL)); //seed 
	InitTree();//initialize

	int Chars = 11 + rand() % 10; //random character generator to insert

	printf("Inserting %d amount of random numbers in the tree:\n", Chars);

	link HeadRoot = NULL;
	//insert random characters
	for (int i = 0; i < Chars; i++) {
		struct Item data; 
		data.RandChar = 'a' + rand() % 26; //generate random lower case letter
		printf("%c ", data.RandChar); 
		HeadRoot = insert(HeadRoot, data); 
	}
	printf("\n");
	printf("\nCharacters sorted: \n");
	TraverseInOrder(HeadRoot); //call in order function to sort chars

	printf("\n");
	printf("\namoutn of Nodes in the tree: %d\n", Count(HeadRoot)); //printf amount of nodes

	printf("Height of tree: %d\n", Height(HeadRoot));//print height of tree

	return 0; 
}