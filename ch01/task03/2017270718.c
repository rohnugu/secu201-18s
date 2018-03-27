void smadd(matrix a, matrix b, matrix d) {
	assert((a != NULL) && (b != NULL) && (d != NULL));
	int i, j, k;
	int dRow = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9;j++) {
			if (a[i].row == b[j].row && a[i].col == b[j].col) {
				d[dRow].value = a[i].value + b[j].value;
				d[dRow].row = a[i].row;
				d[dRow].col = a[i].col;
				dRow++;
			}
		}
	}
};
