include "matrix.h"

void mcreate(matrix *a, const unsigned int row, const unsigned int col) {
        assert(a != NULL);
        assert( (row > 0) && (col > 0) );

        if(a->e != NULL)
                mremove(a);

        a->rows = row;
        a->cols = col;

        a->e = malloc(a->rows * sizeof(float*));

        for(int i=0;i<a->rows;i++)
                a->e[i] = malloc(a->cols * sizeof(float));
}

void mremove(matrix *a) {
        assert(a != NULL);

        if(a->e == NULL) {
                a->rows = 0;
                a->cols = 0;
                return;
        }

        for(int i=0;i<a->rows;i++) {
                free(a->e[i]);
        }
        free(a->e);
        a->rows = 0;
        a->cols = 0;
        a->e = NULL;
}

void mtranspose(matrix a, matrix *b) {
        assert(b != NULL);
        assert( (a.rows > 0) && (a.cols > 0) );

        if ( (b->rows != a.cols) || (b->cols != a.rows) ) {
                mremove(b);
                mcreate(b, a.cols, a.rows);
        }

        for(int i=0;i<a.rows;i++)
                for(int j=0;j<a.cols;j++)
                        b->e[j][i] = a.e[i][j];
}

void madd(matrix a, matrix b, matrix *d) {
        assert(d != NULL);
        assert( (a.rows > 0) && (a.cols > 0) );
        assert( (a.rows == b.rows) && (a.cols == b.cols) );

        if ( (a.rows != d->rows) || (a.cols != d->cols) ) {
                mremove(d);
                mcreate(d, a.rows, a.cols);
        }

        for(int i=0;i<a.rows;i++)
                for(int j=0;j<a.cols;j++)
                        d->e[i][j] = a.e[i][j] + b.e[i][j];
}

void mmultiply(matrix a, matrix b, matrix *d) {
        assert(d != NULL);
        assert( (a.rows > 0) && (a.cols > 0) && (b.rows > 0) && (b.cols > 0) );
        assert( (a.cols == b.rows) );

        if ( (a.rows != d->rows) || (b.cols != d->cols) ) {
                mremove(d);
                mcreate(d, a.rows, b.cols);
        }

        for(int i=0;i<a.rows;i++)
                for(int j=0;j<b.cols;j++) {
                        d->e[i][j] = 0;
                        for(int k=0;k<a.cols;k++)
                                d->e[i][j] += a.e[i][k] * b.e[k][j];
                }
}

void melementmultiply(matrix a, matrix b, matrix *d){ // element-wise multiplication
        assert(d != NULL);
        assert( (a.rows > 0) && (a.cols > 0) );
        assert( (a.rows == b.rows) && (a.cols == b.cols) );

        if ( (a.rows != d->rows) || (a.cols != d->cols) ) {
                mremove(d);
                mcreate(d, a.rows, a.cols);
        }

        for(int i=0;i<a.rows;i++)
                for(int j=0;j<a.cols;j++)
                        d->e[i][j] = a.e[i][j] * b.e[i][j];
}

void mprint(matrix a, bool pointer) {
        if(a.e == NULL) {
                printf("Empty Matrix\n");
                return;
        }

        for(int i=0;i<a.rows;i++) {
                for(int j=0;j<a.cols;j++) {
                        if(!pointer)
                                printf("%f\t", a.e[i][j]);
                        else
                                printf("%p\t", &a.e[i][j]);
                }
                printf("\n");
        }
}
void smatrix_add(matrix a, matrix b , matrix *d){

        assert(a != NULL);
        assert((a.rows[0] >  0 && a.cols[0] > 0));
        assert((a.rows[0] == b.rows[0]) && (a.cols == b.cols[0]));
        int i;
        int j;
        int StarPoint = 1;
        //d의 row값과 col값을 초기화 시켜준다
        d->rows[0] = a.rows[0];
        d->cols[0] = a.cols[0];
        BR = 1;
        AR = 1;
        for(i = StartPoint ; i < a.rows[0] , i ++){
                if(a.rows[StartPoint] == b.rows[] ){
                        if(a.cols[AR] == b.cols[BR] ){
                                d->value = a.value + b.value;
                                BR++;
                        }
                        else if()



                }










}