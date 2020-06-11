
int adder(int a);
void longParam(int, int, int, int);

int main()
{
	int cnt = 5;
	int ans = adder(cnt);
	printf("%d\n", ans);	
	return 0;
}

int adder(int a) {
	return a + 1;
}

void longParam(int one, int two, int three, int four) {
	//do something
}
