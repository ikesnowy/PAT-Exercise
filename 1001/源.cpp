#include <cstdio>
#include <string>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	int sum_numerator = 0;
	int sum_denominator = 1;

	int addition_numerator = 0;
	int addition_denominator = 0;

	int maxG = 0;

	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d/%d", &addition_numerator, &addition_denominator);
		addition_numerator *= sum_denominator;
		sum_numerator *= addition_denominator;
		sum_denominator *= addition_denominator;
		sum_numerator += addition_numerator;
		maxG = gcd(sum_numerator, sum_denominator);
		if (maxG != 1)
		{
			sum_numerator /= maxG;
			sum_denominator /= maxG;
		}
	}

	if (sum_numerator == 0)
	{
		printf("%d", sum_numerator);
		return 0;
	}

	if (sum_numerator > 0 && sum_denominator < 0)
	{
		sum_numerator *= -1;
		sum_denominator *= -1;
	}

	int constent = sum_numerator / sum_denominator;
	if (constent != 0)
	{
		printf("%d", constent);
		sum_numerator -= sum_denominator * constent;
		if (sum_numerator != 0)
		{
			printf(" %d/%d\n", sum_numerator, sum_denominator);
		}
		return 0;
	}
	printf("%d/%d\n", sum_numerator, sum_denominator);
	return 0;
}