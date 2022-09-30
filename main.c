int fibo(int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return (fibo(n-1) + fibo(n-2));
}

int n1 = 777;
int n2;
int n3;

int main()
{
	return fibo(8);
}