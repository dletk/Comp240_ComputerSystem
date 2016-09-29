//
// Created by Duc Le on 9/25/16.
//
#include <stdio.h>
#include <assert.h>
#include <limits.h>

int main() {
    assert(uadd_ok(1,2)==1);
    assert(uadd_ok(100,200)==1);
    assert(uadd_ok(1,UINT_MAX)==0);

    return 0;
}

int uadd_ok(unsigned int x, unsigned int y) {
    unsigned s;
    s = x + y;
    if (x>s) {
        return 0;
    } else {
        return 1;
    }
    // We can replace all the if statement above with this line: return s>=x;
}