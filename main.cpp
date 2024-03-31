#include <stdio.h>
#include "operators.hpp"

int main()
{
	printf("10 / 5 is %f", weird_operators::divide(10, 5));
	printf("\n4 mod 2 is %f", weird_operators::mod(4, 2));
	printf("\n5 * 2 is %f", weird_operators::multiply(5, 2));
	printf("\n2 + 2 is %f", weird_operators::add(2, 2));
	printf("\n4 - 2 is %f", weird_operators::subtract(4, 2));
}