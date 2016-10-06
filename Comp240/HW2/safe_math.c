//
// Created by Duc Le on 10/2/16.
//
#include <math.h>
#include <stdio.h>
#include <fenv.h>
#include <errno.h>
#include <float.h>
#include <assert.h>

double safe_atanh(double arg) {
    double result;
    if isnan(arg) {
        fprintf(stderr,"INPUT is NAN\n");
    }
    if (arg>-1 && arg<1) {
        fprintf(stderr,"DOMAIN error occurred.\n");
    }
    if ((arg == 1) || (arg == -1)) { // Handle for pole error
        fprintf(stderr,"Pole error occurred\n");
    }

    if (math_errhandling & MATH_ERREXCEPT) {
        feclearexcept(FE_ALL_EXCEPT);
    }

    errno = 0;

    result = atanh(arg);

    if ((math_errhandling & MATH_ERRNO) && errno != 0) {
        fprintf(stderr,"Range error occurred, reported by MATH_ERRNO: %d\n",errno);
    } else if ((math_errhandling & MATH_ERREXCEPT) && fetestexcept(FE_OVERFLOW | FE_UNDERFLOW) != 0) {
        fprintf(stderr,"Range error occurred by OVERFLOW\n");
    } else if ((math_errhandling & MATH_ERREXCEPT) && fetestexcept(FE_INVALID) != 0)
        fprintf(stderr,"Input is INVALID\n");
    return result;
}

double safe_pow(double x, double y) {
    double result;
    if (x<0 && (floor(y) != y || ceil(y) != y)) {
        fprintf(stderr,"Domain error occurred\n");
    }
    if ((x == 0) && (y < 0)) { // Handle for pole error
        fprintf(stderr,"Pole error occurred\n");
    }

    if (math_errhandling & MATH_ERREXCEPT) {
        feclearexcept(FE_ALL_EXCEPT);
    }

    errno = 0;

    result = pow(x,y);

    if ((math_errhandling & MATH_ERRNO) && errno != 0) {
        fprintf(stderr,"Range error occurred, reported by MATH_ERRNO: %d\n",errno);
    } else if ((math_errhandling & MATH_ERREXCEPT) && fetestexcept(FE_OVERFLOW | FE_UNDERFLOW) !=0) {
        fprintf(stderr, "Range error occurred by OVERFLOW\n");
    } else if ((math_errhandling & MATH_ERREXCEPT) && fetestexcept(FE_INVALID) != 0) {
        fprintf(stderr, "Input is INVALID\n");
    } else if ((math_errhandling & MATH_ERREXCEPT) && fetestexcept(FE_DIVBYZERO) != 0) {
        fprintf(stderr,"Input makes DIVBYZERO occur\n");
    }

    return result;
}

double safe_hypo(double x, double y) {
    if (math_errhandling & MATH_ERREXCEPT) {
        feclearexcept(FE_ALL_EXCEPT);
    }

    errno = 0;

    double result = hypot(x,y);

    if ((math_errhandling & MATH_ERRNO) && errno != 0) {
        fprintf(stderr,"Range error occurred, reported by MATH_ERRNO: %d\n",errno);

    } else if ((math_errhandling & MATH_ERREXCEPT) && fetestexcept(FE_OVERFLOW | FE_UNDERFLOW) != 0) {
        fprintf(stderr, "Range error occurred by OVERFLOW\n");

    } else if ((math_errhandling & MATH_ERREXCEPT) && fetestexcept(FE_INVALID) != 0) {
        fprintf(stderr,"Input is INVALID \n");
    } else if isnan(result) {
        fprintf(stderr, "Input is NAN\n");
    }


    return result;
}


int main() {
    // Testing for safe_atanh
//    assert(safe_atanh(0.2) == atanh(0.2));
//    assert(isnan(safe_atanh(1.55)));
//    assert(isnan(safe_atanh(DBL_MAX)));
//    assert(safe_atanh(1) == atanh(1));
//    assert(safe_atanh(-1) == atanh(-1));
//    assert(isnan(safe_atanh(INFINITY)));
//    assert(isnan(safe_atanh(1.1)));
//    assert(isnan(safe_atanh(NAN)));
//    assert(safe_atanh(0.0) == atanh(0.0));
//    assert(safe_atanh(-0.0) == atanh(-0.0));

//    assert(safe_pow(3,4) == pow(3,4));
//    assert(safe_pow(0.0,-7) == pow(0.0,-7));
//    assert(safe_pow(-0.0,-9) == pow(-0.0,-9));
//    assert(safe_pow(0.0,-4) == pow(0.0,-4));
//    assert(safe_pow(-0.0,-4) == pow(-0.0,-4));
//    assert(safe_pow(0.0,-4.4) == pow(0.0,-4.4));
//    assert(safe_pow(-0.0,-4.4) == pow(-0.0,-4.4));
//    assert(safe_pow(0.0,-INFINITY) == pow(0.0,-INFINITY));
//    printf("%f\n", safe_pow(-0.0,-INFINITY));
//    assert(safe_pow(0,9) == pow(0,9));
//    assert(safe_pow(-0.0,9) == pow(-0.0,9));
//    assert(safe_pow(0.0,4) == pow(0.0,4));
//    assert(safe_pow(-0.0,4) == pow(-0.0,4));
    assert(safe_pow(0.0,4.1) == pow(0.,4.1));
//    printf("%f\n", safe_pow(-0.0,4.1));
//    printf("%f\n", safe_pow(-1,+INFINITY));
//    printf("%f\n", safe_pow(-1,-INFINITY));
//    printf("%f\n", safe_pow(1,9));
//    printf("%f\n", safe_pow(1,-9));
//    printf("%f\n", safe_pow(1,9.1));
//    printf("%f\n", safe_pow(1,-9.1));
//    printf("%f\n", safe_pow(1,NAN));
//    printf("%f\n", safe_pow(5,0.0));
//    printf("%f\n", safe_pow(-5,-0.0));
//    printf("%f\n", safe_pow(5.1,0.0));
//    printf("%f\n", safe_pow(-5.1,-0.0));
//    printf("%f\n", safe_pow(NAN,0.0));
//    printf("%f\n", safe_pow(NAN,-0.0));
//    printf("%f\n", safe_pow(-5,2.7)); // Check this for domain error
//    printf("%f\n", safe_pow(0.5,-INFINITY));
//    printf("%f\n", safe_pow(5,-INFINITY));
//    printf("%f\n", safe_pow(0.5,+INFINITY));
//    printf("%f\n", safe_pow(5,+INFINITY));
//    printf("%f\n", safe_pow(-INFINITY,-5));
//    printf("%f\n", safe_pow(-INFINITY,-4));
//    printf("%f\n", safe_pow(-INFINITY,-5.1));
//    printf("%f\n", safe_pow(-INFINITY,5));
//    printf("%f\n", safe_pow(-INFINITY,4));
//    printf("%f\n", safe_pow(-INFINITY,5.1));
//    printf("%f\n", safe_pow(+INFINITY,-10));
//    printf("%f\n", safe_pow(+INFINITY,-11));
//    printf("%f\n", safe_pow(+INFINITY,-10.1));
//    printf("%f\n", safe_pow(+INFINITY, -INFINITY));
//    printf("%f\n", safe_pow(+INFINITY, 9));
//    printf("%f\n", safe_pow(+INFINITY, 9.1));
//    printf("%f\n", safe_pow(+INFINITY, 10));
//    printf("%f\n", safe_pow(+INFINITY, +INFINITY));

//    printf("%f\n", safe_pow(-121321321,123123123));
//    printf("%f\n", safe_pow(10, -5000));

//    printf("%f\n", safe_hypo(+INFINITY,NAN));
//    printf("%f\n", safe_hypo(+INFINITY,123));
//    printf("%f\n", safe_hypo(+INFINITY,-123));
//    printf("%f\n", safe_hypo(-INFINITY,NAN));
//    printf("%f\n", safe_hypo(-INFINITY,123));
//    printf("%f\n", safe_hypo(-INFINITY,-123));
//    printf("%f\n", safe_hypo(NAN,NAN));
//    printf("%f\n", safe_hypo(1,NAN));
//    printf("%f\n", safe_hypo(DBL_MAX,DBL_MAX));

//    printf("%f\n", atanh(1));
//    printf("%f\n", safe_atanh(NAN));

//    printf("%f\n", safe_hypo(1.6e308,1.7e308));
    return 0;
}
