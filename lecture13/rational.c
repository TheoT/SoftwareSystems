#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int numer;
    int denom;
} Rational;

// Returns a new Rational with the given numer and denom.
// If unable to allocate, prints an error message and exits.
Rational *make_rational(int numer, int denom) {
    Rational *rat = malloc(sizeof(Rational));
    rat->numer = numer;
    rat->denom = denom;
    return rat;
    // make error statement
}

// Computes a floating-point approximation of a Rational.
double rational_to_double(Rational *rational) {
    union {
        float f;
        double d;
    } r;
    float q1;
    float q2;
    // r.f = ((float) (rational->numer) )/ ((float) (rational->denom));
    q1 = (double) (rational->numer);
    q2 = (double) (rational->denom);
    // FILL THIS IN
    return q1/q2;
}

// Multiplies two rational numbers; returns a new Rational.
Rational *mult_rational(Rational *r1, Rational *r2) {
    Rational *rational = make_rational(0, 0);
    rational->numer = r1->numer * r2->numer;
    rational->denom = r1->denom * r2->denom;
    return rational;

}

// Frees a Rational.
void free_rational(Rational *rational) {
    free(rational);
}

// Prints a rational in fraction form.
void print_rational(Rational *rational) {
    printf("%d / %d\n", rational->numer, rational->denom);
}

int main(void)
{
    Rational *rational = make_rational(3, 7);
    print_rational(rational);

    double d = rational_to_double(rational);
    printf("%lf\n", d);

    Rational *square = mult_rational(rational, rational);
    print_rational(square);
	
    free_rational(rational);
    free_rational(square);

    return EXIT_SUCCESS;
}
