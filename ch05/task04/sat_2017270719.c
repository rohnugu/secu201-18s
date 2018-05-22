#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
typedef struct _node *treePointer;
typedef struct _node {
	
	int value;
	char data;
	treePointer leftChild;
	treePointer rightChild;
}node;
treePointer root = NULL;
treePointer store;
typedef struct _stack *stackPointer;
typedef struct _stack {
	int top;
	char data[MAX];
}stack;
stack store_stack;
stack pre_stack;

void convert_stack(char item) {
	store_stack.data[++store_stack.top] = item;
}
void push(stack *_temp , char item) {
	if (_temp->top == MAX) {
		printf("stack is full\n");
		exit(0);
	}
	_temp->data[++(_temp->top)] =item;
}
char pop(stack *_temp) {
	if (_temp->top == -1) {
		printf("stack is empty\n");
		exit(0);
	}
	return _temp->data[(_temp->top)--];
}
void postfix() {
	int i;
	stack temp;
	char symbol;
	temp.top = -1;
	int n = store_stack.top;
	for (i = 0; i <= store_stack.top; i++) {
		if (store_stack.data[i] == '0' || store_stack.data[i] == '1') {
			printf("%c", store_stack.data[i]);
			push(&pre_stack , store_stack.data[i]);
		}
		else if (store_stack.data[i] == ')') {
			n = i;
			while (temp.data[temp.top] != '(') {
				symbol = pop(&temp);
				printf("%c",symbol);
				push(&pre_stack, symbol);
			}
			
		}
		else {
			push(&temp , store_stack.data[i]);
			
		}
		
	}
	while (temp.top != 0) {
		symbol = pop(&temp);
		printf("%c", symbol);
		push(&pre_stack, symbol);
		
	}
}
bool isOperator(char c) {
	if (c == '!' || c == '&' || c == '|') {
		return true;
	}
	else
		return false;
	
}
treePointer newNode(char c) {
	treePointer temp = (treePointer)malloc(sizeof(node));
	temp->leftChild = temp->rightChild = NULL;
	temp->data = c;
	return temp;
}
treePointer branch[MAX];
void tree_push(treePointer t ,  int *top) {
	if (*top == MAX) {
		printf("tree stack is full\n");
		exit(0);
	}
	branch[++(*top)] = t;

}
treePointer tree_top(int *top) {
	return branch[*top];
}
treePointer tree_pop(int *top) {
	if (*top == -1) {
		printf("tree stack is empty\n");
		exit(0);
	}
	return branch[(*top)--];
}
int convert_to_tree(stack *_temp) {
	treePointer t, t1 ,t2;
	
	int len = strlen(_temp->data);
	int top = -1;
	stack tmp;
	int i = 0;
	for (i = 0; i < len; i++) {
		if (!(isOperator(_temp->data[i]))) {
			t = newNode(_temp->data[i]);
			tree_push(t , &top);
		}
		else
		{
			t = newNode(_temp->data[i]);

			
			t->leftChild = tree_pop(&top);
			
			t->rightChild = tree_pop(&top);
			tree_push(t , &top);	
			
		}
	}
	t = tree_pop(&top);
	return top;
}
void postorderEval(treePointer node) {
	if (node) {
		postorderEval(node->leftChild);
		postorderEval(node->rightChild);
		switch (node->data) {
		case '!':
			node->value = !node->rightChild->value;
			break;
		case '&':
			node->value = node->leftChild->value && node->rightChild->value;
			break;
		case '|':
			node->value = node->leftChild->value || node->rightChild->value;
			break;
		case '0':
			node->value = 0;
			break;
		case '1':
			node->value = 1;
			break;
		}
	}
	
}
int main()
{
	pre_stack.top = -1;
	int count = 0;
	store_stack.top = -1;
	int top_branch;
	int result;
	char a[MAX];
	printf("input the proposition : ");
	gets(a);
	while (a[count] != NULL) {
		convert_stack(a[count]);
		count++;
	}
	postfix();
	top_branch = convert_to_tree(&pre_stack);
	postorderEval(branch);
	if (branch[0]->value) {
		printf("   ==  TRUE\n");

	}
	else
		printf("   ==  FALSE\n");

 	return 0;
}