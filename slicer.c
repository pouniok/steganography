#include<stdio.h>

int b, p=7;

/**
 * Slice the file in 8 parts corresponding to the different bits
 */
int main(int c, char** v){
	for(; !feof(stdin); !p-- ? putchar(b), p=7, b=0 : 0) {
		b |= (getchar() >> *v[1] - 48 & 1) << p;
  }

	p < 6 ?putchar(b) : 0;
}
