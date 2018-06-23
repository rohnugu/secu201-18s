#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef enum {
	true, false, not, and, or, l_parent, r_parent, end
} logic;

typedef struct _node *treePointer;
typedef struct _node {
	logic data;
	short int value;
	treePointer leftChild;
	treePointer rightChild;
} node;

treePointer save_form[100];		// formula
treePointer save_post[100];		// postfix
treePointer stack[STACK_SIZE];
treePointer root = NULL;

int var[SIZE];

const int isp[] = { 0, 0, 0, 1, 2, 3, 4, 0 };
const int icp[] = { 0, 0, 5, 1, 2, 3, 4, 0 };

void push(int *top, treePointer item);

treePointer pop(int *top);

void postorderEval(treePointer ptr);
void convertWord(char *ptr);

logic getToken(treePointer *str_arr, treePointer *symbol, int *n);

void tokenPrint();
void count(char *str, int *space, int *cnt);
void tempSituation(int *var_space, char *str, int cnt);
void postfix();
void convertTree();
int power(int x, int y);

int main()
{
	int n = 0, round;
	int result;
	char str[100];
	char copy[100];

	printf("formula를 입력하세요: ");

	gets(str);
	strcpy(copy, str);
	printf("문자열 = %s\n", copy);
	count(str, var, &n);
	round = power(2, n);

	while (round--) 
	{
		tempSituation(var, copy, n);
		printf("%s\n", copy);
		convertWord(copy);
		postfix();
		tokenPrint();
		convertTree();
		postorderEval(root);

		result = root->value;

		if (result)
			printf("\nresult= 1\n");
		else
			printf("\nresult= 0\n");
	}
	return 0;
}

int power(int x, int y) {
	int result = 1;
	for (int i = 0; i < y; i++) {
		result *= x;
	}
	return result;
}

void count(char *str, int *space, int *count) {
	do 
	{
		switch (*str) 
		{
		case '-':
		case '^':
		case 'v':
		case '(':
		case ')':
			break;
		default:
			*space++ = 1;
			(*count)++;
		}
	} while (*++str != NULL);

	printf("변수= %d\n", *count);
}

void tempSituation(int *var_space, char *str, int count) {
	int round = 0;
	for (int i = 0, j = 0; str[i] != NULL; i++)
	{
		switch (str[i]) 
		{
		case '-':
		case '^':
		case 'v':
		case '(':
		case ')':
			break;
		default:
			str[i] = var_space[j++] + '0';
		}
	}

	int k = 0;

	for (int i = 0; i < count; i++)
		k |= var_space[i] << ((count - 1) - i);
	k -= 1;
	for (int i = 0; i < count; i++) {
		var_space[i] = (k & power(2, (count - 1) - i))
			>> ((count - 1) - i);
	}
}

void push(int *top, treePointer item) {
	if (*top == STACK_SIZE) {
		printf("stack이 가득차있습니다.\n");
		exit(0);
	}
	stack[++(*top)] = item;
}

treePointer pop(int *top) {
	if (*top == -1)
		return end;
	return stack[(*top)--];
}

void postorderEval(treePointer ptr) {
	if (ptr) 
	{
		postorderEval(ptr->leftChild);
		postorderEval(ptr->rightChild);

		switch (ptr->data) 
		{
		case true:
			ptr->value = TRUE;
			break;
		case false:
			ptr->value = FALSE;
			break;
		case not:
			ptr->value = !ptr->rightChild->value;
			break;
		case and:
			ptr->value = ptr->rightChild->value &&
				ptr->leftChild->value;
			break;
		case or :
			ptr->value = ptr->rightChild->value ||
				ptr->leftChild->value;
			break;
		}
	}
}

void convertWord(char *ptr) {
	int count = 0;
	while (ptr[count] != NULL) {
		save_form[count] = (treePointer)malloc(sizeof(node));
		switch (ptr[count]) {
		case '1':
			save_form[count]->data = true;
			break;
		case '0':
			save_form[count]->data = false;
			break;
		case '^':
			save_form[count]->data = and;
			break;
		case 'v':
			save_form[count]->data = or ;
			break;
		case '-':
			save_form[count]->data = not;
			break;
		case '(':
			save_form[count]->data = l_parent;
			break;
		case ')':
			save_form[count]->data = r_parent;
			break;
		default:
			printf("error\n");
			exit(0);
		}
		save_form[count]->value = 0;
		save_form[count]->leftChild = NULL;
		save_form[count]->rightChild = NULL;
		count++;
	}
	save_form[count] = (treePointer)malloc(sizeof(node));
	save_form[count]->data = end;
	save_form[count]->value = 0;
	save_form[count]->leftChild = NULL;
	save_form[count]->rightChild = NULL;
}

logic getToken(treePointer *str_arr, treePointer *symbol, int *n) {
	*symbol = str_arr[(*n)++];
	switch ((*symbol)->data) 
	{
	case true:
	case false:
	case and:
	case or :
	case not:
	case l_parent:
	case r_parent:
		return (*symbol)->data;
	default:
		return end;
	}
}

void postfix() {
	treePointer symbol;
	treePointer *str = save_post;

	int n = 0;
	int top = 0;
	logic token;

	stack[0] = (treePointer)malloc(sizeof(node));
	(stack[0])->data = end;
	(stack[0])->leftChild = NULL;
	(stack[0])->rightChild = NULL;
	(stack[0])->value = 0;

	for (token = getToken(save_form, &symbol, &n);
		token != end;
		token = getToken(save_form, &symbol, &n)) 
	{
		if (token == true || token == false)
			*(str++) = symbol;
		else if (token == r_parent)
		{
			while (stack[top]->data != l_parent)
				*str++ = pop(&top);
			pop(&top);
		}
		else 
		{
			while (isp[stack[top]->data] > icp[token])
				*str++ = pop(&top);
			push(&top, symbol);
		}
	}
	while (top > -1)
		*str++ = pop(&top);
}

void convertTree() {
	int n = 0;
	int top = -1;

	logic token;
	treePointer symbol;
	treePointer op, op2;

	token = getToken(save_post, &symbol, &n);
	while (token != end)
	{
		if (token == true || token == false || symbol == root)
			push(&top, symbol);
		else 
		{
			if (token == not) 
			{
				op = pop(&top);
				symbol->rightChild = op;
			}
			else 
			{
				op2 = pop(&top);
				op = pop(&top);
				symbol->leftChild = op;
				symbol->rightChild = op2;
			}
			root = symbol;
			push(&top, root);
		}
		token = getToken(save_post, &symbol, &n);
	}
	if (top == 0)
		root = stack[top];
}

void tokenPrint() {
	treePointer *str = save_post;
	printf("postfix : ");
	while (*str != NULL) 
	{
		switch ((*str)->data) 
		{
		case true:
			printf("1"); *str++;
			break;
		case false:
			printf("0"); *str++;
			break;
		case not:
			printf("-"); *str++;
			break;
		case and:
			printf("^"); *str++;
			break;
		case or :
			printf("v"); *str++;
			break;
		default:
			*str++;
		}
	}
}
