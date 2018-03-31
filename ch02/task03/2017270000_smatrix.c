#include "smatrix.h"

void smadd(matrix a, matrix b, matrix d) {
	assert( (a != NULL) && (b != NULL) && (d != NULL) );
	assert( (a[0].row > 0) && (a[0].col > 0) );
	assert( (a[0].row == b[0].row) && (a[0].col == b[0].col) );	/* Incompatible matrices */
	
	d[0].row = a[0].row;
	d[0].col = a[0].col;

	int i=1, j=1;
	int count = 0;

	while( (i <= a[0].value) && (j <= b[0].value) ) {
		switch ( COMPARE(d[0].row * a[i].row + a[i].col, d[0].row * b[j].row + b[j].col) ) {
			case -1: /* orderA '<' orderB */
				d[++count].value = a[i].value;
				d[count].row = a[i].row;
				d[count].col = a[i].col;
				i++;
				break;
			case  0: /* orderA '=' orderB */
				d[++count].value = a[i].value + b[j].value;
				d[count].row = b[j].row;
				d[count].col = b[j].col;
				i++;
				j++;
				break;
			case  1: /* orderA '>' orderB */
				d[++count].value = b[j].value;
				d[count].row = b[j].row;
				d[count].col = b[j].col;
				j++;
		}
	}
	// we have (i > a[0].value) || (j > b[0].value)
	if( i > a[0].value ) { // only b's element(s) should be inserted if available
		while( j <= b[0].value ) {
			d[++count].value = b[j].value;
			d[count].row = b[j].row;
			d[count].col = b[j].col;
			j++;
		}
	} else { // only a's element(s) should be inserted if available
		while( i <= a[0].value ) {
			d[++count].value = a[i].value;
			d[count].row = a[i].row;
			d[count].col = a[i].col;
			i++;
		}
	}

	d[0].value = count;
}
