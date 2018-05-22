//¹Ì¿ÏÀÇ ÄÚµå
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef enum { not, and, or , true, false }logical;
typedef struct node *treePointer;
typedef struct node{
	treePointer leftChild;
	logical data;
	short int value;
	treePointer rightChild;
}node;

char stack[100];
int top;

void pushStack(char *s, char *p) {
	s[++top] = *p;
}

void to_stack(char *s, char *p) {
	int i;
	for (i = 0; p[i]; i++) {
		pushStack(s, &p[i]);
	}
}

void postOrderEval(treePointer node) {
	if (node) {
		postOrderEval(node->leftChild);
		postOrderEval(node->rightChild);
		switch (node->data) {
		case not:
			node->value = !node->rightChild->value;
			break;
		case and:
			node->value = node->rightChild->value&&node->leftChild->value;
			break;
		case or:
			node->value = node->rightChild->value || node->leftChild->value;
			break;
		case true:
			node->value = TRUE;
			break;
		case false:
			node->value = FALSE;
			break;
		}
	}
}
//
void main() {
	char ch[100];
	printf("input postfix formula(TURE=1, FALSE=0) >> ");
	//(x & y) | ( !x & z) | ! z
	// x y & x ! z & | z ! |
	gets(ch);
	to_stack(stack, ch);
	int count = strlen(ch);
	node *p = malloc(sizeof(node)*count);
	int i;
	for (i = 0; i < count; i++) {
		CreateNode(&p[i], stack[count-1-i]);
	}
	p[0].rightChild = &p[1].data;
	p[1].rightChild = &p[2].data;
	p[0].leftChild = &p[3].data;
	p[3].rightChild =&p[4].data;
	p[4].rightChild = &p[5].data;
	p[4].leftChild = &p[6].data;
	p[6].rightChild = &p[7].data;
	p[8].rightChild = &p[9].data;
	p[8].leftChild = &p[10].data;

	printf("%d", count);
}

void CreateNode(node **N,char *item) {
	(*N)->leftChild = NULL;
	(*N)->rightChild = NULL;
	switch (*item) {
	case '&':
		(*N)->data = and;
		break;
	case '|':
		(*N)->data = or ;
		break;
	case '!':
		(*N)->data = not;
		break;
	case '0':
		(*N)->data = false;
		break;
	case '1':
		(*N)->data = true;
		break;
	}
}

