#include "smatrix.h"

void storeSum(matrix d, int *totalD, int row, int column, int *sum);

unsigned int smcreate(matrix *a, const unsigned int rows, const unsigned int cols) {
	assert(a != NULL);

	unsigned int capacity = MIN( rows*cols, MAX_ELEMENTS );
	*a = malloc( capacity * sizeof(element));
	(*a)[0].row = rows;
	(*a)[0].col = cols;
	(*a)[0].value = 0; // zero matrix
	return capacity;
}

void smremove(matrix *a) {
	if(a == NULL) // 포인터의 포인터 주소가 안 주어진 상태로 함수가 실행되면
		return;
	if(*a == NULL) // 배열의 base point가 NULL이면
		return;
	free(*a); // if *a does not point to a dynamically allocated memory from malloc/smcreate, it will do an undefined behavior!
	*a = NULL;
}

void smtranspose(matrix a, matrix b) {
	assert( (a != NULL) && (b != NULL) );
	assert( b[0].row * b[0].col >= a[0].value ); // dynamic allocation 문제 처리 고려함

	/* b is set to the transpose of a */
	int numTerms, currentb;
	numTerms	= a[0].value; 	/* total number of elements */
	b[0].row 	= a[0].col; 	/* rows in b = columns in a */
	b[0].col 	= a[0].row;		/* columns in b = rows in a */
	b[0].value 	= numTerms;

	if( numTerms > 0 ) { /* non zero matrix */
		currentb = 1;
		for(int i=0; i<a[0].col; i++)
			/*transpose by the columns in a */
			for(int j=1; j <= numTerms; j++)
				/* find elements from the current column */
				if( a[j].col == i ) {
					/* elements is in current column, add it to b */
					b[currentb].row 	= a[j].col;
					b[currentb].col 	= a[j].row;
					b[currentb].value 	= a[j].value;
					currentb++;
				}
	}
}

void smfastTranspose(matrix a, matrix b) {
	unsigned int rowTerms[MAX_COLS], startingPos[MAX_COLS];

	/* the transpose of a is placed in b */
	assert( (a != NULL) && (b != NULL) );
	assert( b[0].row * b[0].col >= a[0].value ); // dynamic allocation 문제 처리 고려함

	int numTerms;
	numTerms	= a[0].value; 	/* total number of elements */
	b[0].row 	= a[0].col; 	/* rows in b = columns in a */
	b[0].col 	= a[0].row;		/* columns in b = rows in a */
	b[0].value 	= numTerms;

	if( numTerms > 0 ) { /* nonzero matrix */
		for(int i=0; i < b[0].row; i++)
			rowTerms[i] = 0; /* elements in row i of b */

		for(int i=1; i <= numTerms; i++)
			rowTerms[a[i].col]++;
		
		startingPos[0] = 1; /* starting position of row i in b*/
		
		for(int i=1; i < b[0].row; i++)
			startingPos[i] = startingPos[i-1] + rowTerms[i-1];

/*		printf("rowTerms=");
		for(int i=0;i<b[0].row; i++)
			printf("\t%d", rowTerms[i]);
		printf("\n");

		printf("startingPos=");
		for(int i=0;i<b[0].row; i++)
			printf("\t%d", startingPos[i]);
		printf("\n");
*/
		for(int i=1; i <= numTerms; i++) {
			int j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

void smadd(matrix a, matrix b, matrix d){
	d[0].col=a[0].col>=b[0].col?a[0].col:b[0].col;
	d[0].row=a[0].row>=b[0].row?a[0].row:b[0].row;
	// hjroh
	// 두 matrix의 행/열 크기를 비교해 큰 쪽이 되도록 하는 건
	// 나쁘지 않은 아이디어지만, 교재의 ADT SparseMatrix 명세는
	// 크기가 같은 두 행렬의 합을 정의하고 있으니까
	// 명세대로 작성하는 게 올바릅니다.
	// 프로그래머가 자의적으로 요구사항을 해석한 뒤,
	// 그로 인한 문제가 생기면 프로그래머가 책임을 져야 하니까요.
	int ct_i;
	int ct_j;
	int value=0;
	// hjroh
	// value라는 변수의 의미가 불분명합니다.
	// 더군다나 구조체에 value라는 멤버 변수가 있으니
	// 읽는 사람이 헷갈립니다.
	for(int ct_i=0;ct_i<d[0].row;ct_i++){
		// hjroh
		// 앞에서 ct_i를 선언한 상태에서 for에서 다시 선언한 건
		// 바람직하지 않습니다. 불필요한 스택 공간을 낭비할 필요가 없죠.
		// 그리고 a, b, d의 index는 2차원 배열의 index가 아니라
		// 1차원 배열의 인덱스라서, 아래 코드는 전부 동작하지 않겠네요.
		for(int ct_j=0;ct_j<d[0].col;ct_j++){
			if(a[ct_i+1].row==b[ct_i+1].row&&a[ct_j+1].col<b[ct_j+1].row){
				// hjroh
				// ct_i+1 같은 경우는 ct_i + 1로 띄어쓰는 게 좋습니다.
				// 코드를 빠르게 읽다보면 ct_(i+1)로 오해할 수 있으니까요.
				value++;
				d[ct_i+1].value=a[ct_i+1].value;
			}	
			else if(a[ct_i+1].row==b[ct_i+1].row&&a[ct_j+1].col==b[ct_j+1].row){
				value++;
				d[ct_i+1].value=a[ct_i+1].value+b[ct_i].value;	
			}
			else if(a[ct_i+1].row==b[ct_i+1].row&&a[ct_j+1].col>b[ct_j+1].col){
				value++;
				d[ct_i+1].value==b[ct_i+1].value;
			}
}

}


}


void smmultiply(matrix a, matrix b, matrix d) {
	/* multiply two sparse matrices */
	assert( (a != NULL) && (b != NULL) && (d != NULL) );
	assert (a[0].col == b[0].row);	/* Incompatible matrices */
	assert (a[0].col > 0);

	int rowBegin = 1, row = a[1].row, totalD = 0, sum=0;

	int rowsA = a[0].row, colsA = a[0].col, totalA = a[0].value;
	int                   colsB = b[0].col, totalB = b[0].value;

	matrix newA;
	int capacity = smcreate(&newA, totalA + 2, 1); /* warning: newA has incorrect info */
	assert(capacity >= totalA + 2);
	memcpy( newA, a, (totalA + 1) * sizeof(element) );

	matrix newB;
	capacity = smcreate(&newB, totalB + 2, 1);
	assert(capacity >= totalB + 2);
	smfastTranspose(b, newB);

	/* set boundary condition */
	newA[totalA+1].row = rowsA;
	newB[totalB+1].row = colsB;
	newB[totalB+1].col = 0;
	for (int i = rowBegin; i <= totalA; ) {
		int column = newB[1].row;
		for(int j=1; j <= totalB+1; ) {
			/* multiply row of a by column of b */
			if(newA[i].row != row) {
				storeSum(d, &totalD, row, column, &sum);
				i = rowBegin;
				for(; newB[j].row == column; j++);
				column = newB[j].row;
			} else if(newB[j].row != column) {
				storeSum(d, &totalD, row, column, &sum);
				i = rowBegin;
				column = newB[j].row;
			} else switch (COMPARE(newA[i].col, newB[j].col)) {
				case -1: i++; break; /* '<' go to next element in a */
				case  0: /* '==' add elements, go to next element in a and b */
					sum += newA[i++].value * newB[j++].value;
					break;
				case  1: j++; /* '>' advanced to next element in b */
			}
		} /* end of for j <= totalB+1 */
		for (; a[i].row == row; i++);
		rowBegin = i; row = a[i].row;
	} /* end of for i <= totalA */
	d[0].row   = rowsA;
	d[0].col   = colsB;
	d[0].value = totalD;
}

void storeSum(matrix d, int *totalD, int row, int column, int *sum) {
	/* if *sum != 0, then it along with its row and column
	   position is stored as the *totalD+1 entry in d */
	if (*sum) {
		assert (*totalD < MAX_ELEMENTS - 1);
		/* printf("%d \n", *totalD); */
		d[++*totalD].row = row;
		d[*totalD].col = column;
		d[*totalD].value = *sum;
		*sum = 0;
	}
}

void smprint(matrix a, bool pointer) {
	assert(a != NULL);

	for(int i=0; i<=a[0].value; i++) {
		if(pointer)
			printf("%p\t%d\t%d\t%d\n", &a[i], a[i].row, a[i].col, a[i].value);
		else
			printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);

	}
}

void smvisualprint(matrix a, bool pointer)
{
	assert(a != NULL);

	int visual[MAX_ROWS][MAX_COLS] = {0};

	for(int k=1; k <= a[0].value; k++)
		visual[a[k].row][a[k].col] = a[k].value;

	for(int i=0; i<a[0].row; i++) {
		for(int j=0; j<a[0].col; j++) {
			if(pointer)
				printf("%p\t", &visual[i][j]);
			else
				printf("%d\t", visual[i][j]);
		}
		printf("\n");
	}
}
