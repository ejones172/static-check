
int uninitialized_local_var(void)
{
	int x;
	return x;
}

int uninitialized_local_var_branch(void)
{
	int x;
	if (x) {
		return 1;
	}
	else {
		return 0;
	}
}

int uninitialized_local_ptr(void)
{
	int* p;
	return *p;
}

int uninitialized_local_ptr_branch(void)
{
	int* p;
	if (*p) {
		return 1;
	}
	else {
		return 0;
	}
}

int uninitialized_out_of_scope(int x)
{
	int* p = &x;
	if (x) {
		int y = 10;
		p = &y;
	}
	return *p;
}

int* uninitialized_out_of_scope2(void)
{
	int x;
	int* p = &x;
	return p;
}

int uninitialized_out_of_scope3(int x)
{
	int* p = &x;
	if (x) {
		int y;
		p = &y;
	}
	*p = 10;
	return *p;
}
