#include <stdio.h>
#include <stdarg.h> // tipul de date va_list si macrocomenzile va_start, va_arg, si va_end

double max(int n, ...)
{
	double m = -1E10;
	double x;
	va_list list;

	va_start(list, n);

	for (int i = 0; i < n; i++)
	{
		x = va_arg(list, double);
		if (x > m) { m = x; }
	}

	va_end(list);

	return m;
}

int main()
{
	double mx;

	mx = max(4, 2.5, 6., 5.7, 1.);

	printf("Maximul este %.2lf", mx);
}
