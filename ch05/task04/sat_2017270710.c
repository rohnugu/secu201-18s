#include <stdio.h>
#include <stdlib.h>

typedef enum { not, and, or , true, false }logic;

typedef struct node *treePointer;
typedef struct node {
	treePointer leftChild;
	int value;
	logic data;
	treePointer rightChild;
} node;

int count;
char stack[50];

void Push(char *s, char *p) {
	s[++count] = *p;
}

void Pop(char *s, char *p) {
	int i;
	for (i = 0; p[i]; i++) 
		Push(s, &p[i]);
}

void PostOrderEval(treePointer node) {
	if (node) {
		PostOrderEval(node->leftChild);
		PostOrderEval(node->rightChild);
		switch (node->data) {
		case not:
			node->value = !node->rightChild->value;
			break;
		case and:
			node->value = node->rightChild->value&&node->leftChild->value;
			break;
		case or :
			node->value = node->rightChild->value || node->leftChild->value;
			break;
		case true:
			node->value = 1;                            //True = 1
			break;
		case false:
			node->value = 0;                            //False = 0
			break;
		}
	}
}

void CreateNode(node **n, char *item) {
	(*n)->leftChild = NULL;
	(*n)->rightChild = NULL;
	switch (*item) {
	case '&':
		(*n)->data = and;
		break;
	case '|':
		(*n)->data = or ;
		break;
	case '!':
		(*n)->data = not;
		break;
	case '0':
		(*n)->data = false;
		break;
	case '1':
		(*n)->data = true;
		break;
	}
}

int main()
{

	return 0;
}

