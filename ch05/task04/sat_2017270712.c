#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct node* nodePtr;
typedef struct node {
	char value;
	int data;
	nodePtr leftChild;
	nodePtr rightChild;
} node;

nodePtr setting(char **_string) {
	nodePtr temp;
	nodePtr root = (nodePtr)calloc(1, sizeof(node));
	nodePtr je;
	nodePtr infoTemp;
	char ln[10] = "1";

	for (; (*_string)[0]; (*_string)++) {
		if (root->rightChild != NULL) {
			temp = (nodePtr)calloc(1, sizeof(node));
			temp->leftChild = root;
			root = temp;
		}

		switch ((*_string)[0]) {
		case '(':
			(*_string)++;
			if (root->leftChild == NULL)
				root = setting(_string);
			else {
				root->rightChild = (nodePtr)calloc(1, sizeof(node));
				root->rightChild = setting(_string);
			}
			while (*((*_string)++) != ')');
			(*_string)--;
			break;

		case ')':
			return root->leftChild;
			break;

		case '&':
			root->value = '&';
			root->data = (*_string)[0];
			break;

		case '|':
			root->value = '|';
			root->data = (*_string)[0];
			break;

		case '!':
			if (root->leftChild == NULL)
				infoTemp = root = (nodePtr)calloc(1, sizeof(node));
			else
				infoTemp = root->rightChild = (nodePtr)calloc(1, sizeof(node));

			infoTemp->value = '!';
			(*_string)++;
			je = (nodePtr)calloc(1, sizeof(node));
			ln[0] = (*_string)[0];
			je->data = atoi(ln);
			je->value = 'i';
			infoTemp->rightChild = je;
			break;

		default:
			root->leftChild = (nodePtr)calloc(1, sizeof(node));
			root->leftChild->value = 'i';
			ln[0] = (*_string)[0];
			root->leftChild->data = atoi(ln);

			break;
		}

		if (((*_string)[1] == '1') || ((*_string)[1] == '0')) {
			(*_string)++;
			root->rightChild = (nodePtr)calloc(1, sizeof(node));
			root->rightChild->value = 'i';
			ln[0] = (*_string)[0];
			root->rightChild->data = atoi(ln);
		}
	}
	return root;
}

int sat(nodePtr _node) {
	if ((_node->leftChild != NULL) && (_node->leftChild->value != 'i'))
		sat(_node->leftChild);
	if ((_node->rightChild != NULL) && (_node->rightChild->value != 'i'))
		sat(_node->rightChild);

	switch (_node->value)
	{
	case '&':
		_node->data = _node->leftChild->data && _node->rightChild->data;
		break;
	case '|':
		_node->data = _node->leftChild->data || _node->rightChild->data;
		break;
	case '!':
		_node->data = !(_node->rightChild->data);
		break;
	case 'i':
		return _node->data;
	default:
		printf("state error!!!!\n");
	}
	_node->value = 'i';
	return _node->data;

}

int main(void) {
	char aaa[50];
	char *bbb = aaa;
	nodePtr root = 0;

	int x1, x2, x3;
	for (int i = 0; i < 8; i++) {
		x1 = i&1; x2 = (i&2)>>1; x3 = (i&4)>>2;
		sprintf_s(aaa,40, "(%d&!%d)|(!%d&%d)|!%d\x00", x1, x2, x1, x3, x3);
		bbb = aaa;
		root = setting(&bbb);
		printf("%s\n", aaa);
		printf("%d\n", sat(root));
	}

	system("pause");
	return 0;
}
