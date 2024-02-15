#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count=0;
	struct node* trav=head;
	if (head==NULL){
		return NULL;
	}
	// Counts until NULL located.
	while(trav!=NULL){
		count++;
		trav=trav->next;
	}
	return count;

}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	// Allocated a word that can host all given examples.
	struct node* letter = head;
	char* word = (char*)malloc(10*sizeof(char));
	int i = 0;
	
	if (head == NULL){
		return NULL;
	}
	
	// Populate the word/array.
	while(letter!=NULL){
		word[i]=letter->letter;
		letter=letter->next;
		i++;
	}
	word[i]='\0';
	return word;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	// Allocates memory for a letter.
	struct node* spell= (node*)malloc(sizeof(node));
	spell->letter=c;
	spell->next=NULL;
	
	// Starts word.
	if(*pHead==NULL){
		*pHead=spell;
	}

	// Completes spelling.
	else{
		node* trav=*pHead;
		while(trav->next!=NULL){
			trav=trav->next;
		}
		trav->next=spell;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	// Allocate node for freeing memory.
	struct node* delete = *pHead;
	
	// Traverse linked list freeing nodes.
	while (delete!=NULL){
		struct node *trav=delete;
		trav=trav->next;
		free(delete);
		delete=trav;
	}
	*pHead=NULL;
	
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}