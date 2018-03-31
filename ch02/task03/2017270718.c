void smadd(matrix a, matrix b, matrix d) {
	// hjroh
	// a[i].value의 사이즈만 어떻게 처리했다면 좋았겠네요.
	// 나머지는 좋습니다.
	// 아, d의 0번째 element를 설정하지 않은 부분은 수정해야 합니다.
	
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
