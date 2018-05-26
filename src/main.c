#include <rgbe.h>
#include <xmmintrin.h>

int main(void)
{
    _mm_setcsr(_mm_getcsr() | 0x8040);
    rgbeInitEngine();
    rgbeRunEngine();
    return 0;
}
