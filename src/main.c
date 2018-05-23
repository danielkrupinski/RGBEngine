#include <xmmintrin.h>
#include "engine.h"

int main(void)
{
    _mm_setcsr(_mm_getcsr() | 0x8040);
    rgbeInit();
    runEngine();
    return 0;
}
