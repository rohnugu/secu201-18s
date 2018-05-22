#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef enum {true, false , not, and, or } logical;

typedef struct _node *treePointer;
typedef struct _node {
	treePointer leftChild;
	logical data;
	short int value;
	treePointer rightChild;
} node;


void postOrderEval(treePointer node);

/* stack 구현부 */
typedef struct _element {
	char value;
} element;

typedef element * stack;

int stack_capacity;
int stack_top;

int exp_len;

void createStack(stack* _stack, int defaultSize) {
	if (defaultSize > 0)
		*_stack = (stack*)malloc(defaultSize * sizeof(element));
	else
		*_stack = NULL;

	stack_capacity = defaultSize;
	stack_top = -1;
}

void pushStack(stack* _stack, char c) {
	stack_top++;
	(*_stack)[stack_top].value = c;
	//printf("PUSH:\t\t(%c)\n", (*_stack)[stack_top].value);
}

char popStack(stack *_stack) {
	stack_top--;
	return (*_stack)[stack_top + 1].value;
}

char readStack(stack  *_stack) {
 	return (*_stack)[stack_top].value;
}
/* 만든 거 */
void convertToPost(char* exp);
int precedence(char oprt);
void makeTree(treePointer node, char* exp);


void main() {

	char exp[256];
	int i;

	node root;

	printf("input infix expression : ");
	gets(exp);

	/* 입력한 식을 후위 식으로 표현 */
	convertToPost(exp);
	printf("Postfix exprssion : %s\n",exp);
	

	/* 후위 식을 tree로 표현 */
	exp_len = strlen(exp);
	makeTree(&root, exp);	

	/* 돌리기 */
	postOrderEval(&root);
	
	if (root.value) {
		printf("Satisfiable combination!\n");
	}
	else
		printf("No satisfiable combination\n");

	system("pause");
}

treePointer CreateNewNode() {
	treePointer newNode = (treePointer)malloc(sizeof(node));
	newNode->data = 0;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	
	return newNode;
}

void makeTree(treePointer node, char* exp) {
	treePointer newNode = NULL;
	char token = exp[exp_len - 1];
	
	exp_len--;
	if (exp_len != -1) {
		switch (token) {
		case '|':
			node->data = or ;
			node->leftChild = CreateNewNode();
			makeTree(node->leftChild, exp);
			node->rightChild = CreateNewNode();
			makeTree(node->rightChild, exp);
			break;
		case '&':
			node->data = and;
			node->leftChild = CreateNewNode();
			makeTree(node->leftChild, exp);
			node->rightChild = CreateNewNode();
			makeTree(node->rightChild, exp);
			break;
		case '!':
			node->data = not;
			node->rightChild = CreateNewNode();
			makeTree(node->rightChild, exp);
			break;
		case '1':
			node->data = true;
			break;
		case '0':
			node->data = false;
			break;
		default:
			;
		}
	}
}

void convertToPost(char* exp) {  // 후위 수식으로 바꿔줌.
	char tmp[256] = {' ',' '};
	int i, tmp_top=0;

	stack stackOper = NULL;

	createStack(&stackOper, 100);

	for (i = 0; i < strlen(exp); i++) {
		if (exp[i] != ' ') {
			if (exp[i] == '1' || exp[i] == '0') { // tmp[i]는 참, 거짓
				tmp[tmp_top] = exp[i];
				tmp_top++;
			}
			else {  // tmp[i]가 부호
				if (stack_top != -1 && readStack(&stackOper)) {
					while (precedence(exp[i]) <= precedence(readStack(&stackOper))) {//
						tmp[tmp_top] = popStack(&stackOper);
						tmp_top++;
					}
				}
				pushStack(&stackOper, exp[i]);
			}
		}
	}

	while (stack_top != -1) {
		tmp[tmp_top] = (popStack(&stackOper));
		tmp_top++;
	}
	strcpy(exp, tmp);
}

int precedence(char oprt) {
	if (oprt == '|')
		return 0;
	else if (oprt == '&')
		return 1;
	else if (oprt == '!')
		return 2;
}


void postOrderEval(treePointer node) {
	/* modified post order traversal to evaluate a propositional calculus tree */
	if (node) {
		postOrderEval(node->leftChild);
		postOrderEval(node->rightChild);
		switch (node->data) {
		case not:
			node->value = !(node->rightChild->value);
			break;
		case and:
			node->value = (node->rightChild->value) && (node->leftChild->value);
			break;
		case or :
			node->value = (node->rightChild->value) || (node->leftChild->value);
			break;
		case true:
			node->value = TRUE;
			break;
		case false:
			node->value = FALSE;
		}
	}
}
