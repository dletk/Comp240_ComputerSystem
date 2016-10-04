//
// Created by Duc Le on 10/2/16.
//
#include <math.h>
#include <stdio.h>
#include <fenv.h>
#include <errno.h>

double safe_atanh(double arg) {
    double result;
    if ((arg > 1) | (arg < -1)) {
        printf("Input is not in domain, return 0\n");
        return 0.0;
    }
    if ((arg == 1) | (arg == -1)) { // Handle for pole error
        printf("Pole error occurred, return 0\n");
        return 0.0;
    }

    if (math_errhandling & MATH_ERREXCEPT) {
        feclearexcept(FE_ALL_EXCEPT);
    }

    errno = 0;

    result = atanh(arg);

    if ((math_errhandling & MATH_ERRNO) && errno != 0) {
        printf("The result is out of range to expressed, return 0\n");
        return 0.0;
    } else if ((math_errhandling & MATH_ERREXCEPT) && fetestexcept(FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW | FE_INVALID) != 0) {
        printf("The result is out of range to expressed, return 0\n");
        return 0.0;
    }

    return result;
}

double safe_pow(double x, double y) {
    double result;
    if (x<0 && (floor(y) != y || ceil(y) != y)) {
        printf("Input is not in domain, return 0\n");
        return 0.0;
    }
    if ((x == 0) && (y < 0)) { // Handle for pole error
        printf("Pole error occurred, return 0\n");
        return 0.0;
    }

    if (math_errhandling & MATH_ERREXCEPT) {
        feclearexcept(FE_ALL_EXCEPT);
    }

    errno = 0;

    result = pow(x,y);

    if ((math_errhandling & MATH_ERRNO) && errno != 0) {
        printf("The result is out of range to expressed, return 0\n");
        return 0.0;
    } else if ((math_errhandling & MATH_ERREXCEPT) && fetestexcept(FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW | FE_INVALID) !=0) {
        printf("The result is out of range to expressed, return 0\n");
        return 0.0;
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
        printf("The result is out of range to expressed, return 0\n");
        return 0.0;
    } else if ((math_errhandling & MATH_ERREXCEPT) && fetestexcept(FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW | FE_INVALID) != 0) {
        printf("The result is out of range to expressed, return 0\n");
        return 0.0;
    }

    return result;
}


int main() {
    printf("%f\n", safe_atanh(sqrt(2)/2));
    printf("%f\n", atanh(sqrt(2)/2));
    printf("%f\n", safe_atanh(NAN));
    printf("%f\n", safe_pow(10, -4000));
    printf("%f\n", safe_hypo(1.6e308,1.7e308));
    return 0;
}
