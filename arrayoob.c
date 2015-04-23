
int arrayoob_basic(void) {
	int a[10];
	a[11] = 0;
	return a[11];
}

int arrayoob_maybe(int i)
{
	int a[10];
	a[i] = 0;
	return a[i];
}

int arrayoob_definite(void)
{
	return arrayoob_maybe(11);
}
