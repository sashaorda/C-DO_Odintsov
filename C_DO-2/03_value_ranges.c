#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    /* signed char */
    signed char signed_char_min = SCHAR_MIN;
    signed char signed_char_max = SCHAR_MAX;

    /* unsigned char */
    unsigned char unsigned_char_min = 0U;
    unsigned char unsigned_char_max = UCHAR_MAX;

    /* signed short */
    signed short signed_short_min = SHRT_MIN;
    signed short signed_short_max = SHRT_MAX;

    /* unsigned short */
    unsigned short unsigned_short_min = 0U;
    unsigned short unsigned_short_max = USHRT_MAX;

    /* signed int */
    signed int signed_int_min = INT_MIN;
    signed int signed_int_max = INT_MAX;

    /* unsigned int */
    unsigned int unsigned_int_min = 0U;
    unsigned int unsigned_int_max = UINT_MAX;

    /* signed long */
    signed long signed_long_min = LONG_MIN;
    signed long signed_long_max = LONG_MAX;

    /* unsigned long */
    unsigned long unsigned_long_min = 0UL;
    unsigned long unsigned_long_max = ULONG_MAX;

    /* signed long long */
    signed long long signed_long_long_min = LLONG_MIN;
    signed long long signed_long_long_max = LLONG_MAX;

    /* unsigned long long */
    unsigned long long unsigned_long_long_min = 0ULL;
    unsigned long long unsigned_long_long_max = ULLONG_MAX;

    /* float */
    float float_min = FLT_MIN;
    float float_max = FLT_MAX;

    /* double */
    double double_min = DBL_MIN;
    double double_max = DBL_MAX;

    /* long double */
    long double long_double_min = LDBL_MIN;
    long double long_double_max = LDBL_MAX;

    printf("========== signed char ==========\n");
    printf("min = %d\t0x%X\n", signed_char_min, (unsigned char)signed_char_min);
    printf("max = %d\t0x%X\n\n", signed_char_max, (unsigned char)signed_char_max);

    printf("========== unsigned char ==========\n");
    printf("min = %u\t0x%X\n", unsigned_char_min, unsigned_char_min);
    printf("max = %u\t0x%X\n\n", unsigned_char_max, unsigned_char_max);

    printf("========== signed short ==========\n");
    printf("min = %hd\t0x%hX\n", signed_short_min, (unsigned short)signed_short_min);
    printf("max = %hd\t0x%hX\n\n", signed_short_max, (unsigned short)signed_short_max);

    printf("========== unsigned short ==========\n");
    printf("min = %hu\t0x%hX\n", unsigned_short_min, unsigned_short_min);
    printf("max = %hu\t0x%hX\n\n", unsigned_short_max, unsigned_short_max);

    printf("========== signed int ==========\n");
    printf("min = %d\t0x%X\n", signed_int_min, (unsigned int)signed_int_min);
    printf("max = %d\t0x%X\n\n", signed_int_max, (unsigned int)signed_int_max);

    printf("========== unsigned int ==========\n");
    printf("min = %u\t0x%X\n", unsigned_int_min, unsigned_int_min);
    printf("max = %u\t0x%X\n\n", unsigned_int_max, unsigned_int_max);

    printf("========== signed long ==========\n");
    printf("min = %ld\t0x%lX\n", signed_long_min, (unsigned long)signed_long_min);
    printf("max = %ld\t0x%lX\n\n", signed_long_max, (unsigned long)signed_long_max);

    printf("========== unsigned long ==========\n");
    printf("min = %lu\t0x%lX\n", unsigned_long_min, unsigned_long_min);
    printf("max = %lu\t0x%lX\n\n", unsigned_long_max, unsigned_long_max);

    printf("========== signed long long ==========\n");
    printf("min = %lld\t0x%llX\n", signed_long_long_min, (unsigned long long)signed_long_long_min);
    printf("max = %lld\t0x%llX\n\n", signed_long_long_max, (unsigned long long)signed_long_long_max);

    printf("========== unsigned long long ==========\n");
    printf("min = %llu\t0x%llX\n", unsigned_long_long_min, unsigned_long_long_min);
    printf("max = %llu\t0x%llX\n\n", unsigned_long_long_max, unsigned_long_long_max);

    printf("========== float ==========\n");
    printf("min = %f\n", float_min);
    printf("min = %e\n", float_min);
    printf("min = %a\n\n", float_min);

    printf("max = %f\n", float_max);
    printf("max = %e\n", float_max);
    printf("max = %a\n\n", float_max);

    printf("========== double ==========\n");
    printf("min = %lf\n", double_min);
    printf("min = %e\n", double_min);
    printf("min = %a\n\n", double_min);

    printf("max = %lf\n", double_max);
    printf("max = %e\n", double_max);
    printf("max = %a\n\n", double_max);

    printf("========== long double ==========\n");
    printf("min = %Lf\n", long_double_min);
    printf("min = %Le\n", long_double_min);
    printf("min = %La\n\n", long_double_min);

    printf("max = %Lf\n", long_double_max);
    printf("max = %Le\n", long_double_max);
    printf("max = %La\n", long_double_max);

    return 0;
}