
int board[5][5];
void place(int);
int valid(int,int);
void show_board()
{	
	int i,j;
	for (i=1;i<=3;i++) {
		for (j=1;j<=3;j++) {
			if (board[i][j]) {
				printf("@");
			}
			else {
				printf("0");
			}
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{	
	place(1);
	return 0;
}

int valid(int row,int col)
{	
	int i;
	for (i=1;i<row;i++) {
		if (board[i][col]) return 0;
	}
	return 1;
}

void place(int row){
	int i;
	if (row>3) show_board();
	else {
		for (i=1;i<=3;i++) {
			if (valid(row,i)) {
				board[row][i] = 1;
				place(row+1);
				board[row][i] = 0;	
			}	
		}
	}
	
}

