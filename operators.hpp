#define NEGATIVE_ONE -1
#include <limits>

namespace weird_operators {
	float divide(float num, float divider) {
		if (divider == 0.0f) {
			return INFINITY;
		}

		float result = 0.0f;
		int sign = ((num < 0) ^ (divider < 0)) ? -1 : 1;

		num = fabs(num);
		divider = fabs(divider);

		while (num >= divider) {
			num -= divider;
			result++;
		}

		// Handle the fractional part
		float fraction = 0.5f;
		while (num > 0.0f && fraction > 0.00001f) {
			if (num >= divider * fraction) {
				num -= divider * fraction;
				result += fraction;
			}
			fraction *= 0.5f;
		}

		return sign * result; 
	}
	float mod(float num, float divider) {
		if (divider == 0) return 0; 

		float result = num;
		while (result >= divider) { 
			result -= divider;
		}
		return result < 0 ? result + divider : result;
	}
	float multiply(float num, float multiplier) {
		float result = 0;
		if (multiplier == 0 || num == 0) { 
			return result;
		}

		for (int i = 0; i < multiplier; i++) {
			result += num;
			if (result / num != multiplier) { 
				break;
			}
		}

		return result;
	}
	float add(float num, float num2)
	{
		return num - -(num2);
	}
	float subtract(float num, float num2)
	{
		return num + (num2 * NEGATIVE_ONE); //Technically still using the "-". But afaik there is no way to do that without it, and in my defense, the minus is outside the function.
	}
}