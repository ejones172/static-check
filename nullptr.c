
int nullptr_basic(void)
{
	int* x = 0;
	return *x;
}

int nullptr_branch(int x)
{
	int* p = 0;
	int y;
	if (x > 0) {
		p = &y;
		*p = x;
	}

	return *p;
}
