#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<math.h>

double squ(double x)
{
	return x * x;
}

double length(double x1, double y1, double x2, double y2)
{
	return sqrt(squ(x1-x2) + squ(y1-y2));
}

//int main()
//{
//	double x1, y1, x2, y2, x3, y3;
//	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
//	double a, b, c, p;
//	a = length(x1, y1, x2, y2);
//	b = length(x1, y1, x3, y3);
//	c = length(x2, y2, x3, y3);
//	p = (a + b + c) / 2;
//	double s = sqrt(p * (p - a) * (p - b) * (p - c));
//	printf("%.2f", s);
//	return 0;
//}