

#ifdef _WIN32

#else

#endif


extern "C"
int abs1(int i)
{
    if (i < 0)
    {
        return -i;
    }
    else
    {
        return +1;
    }
}

extern "C"
int add2(
    int i0
,   int i1
)
{
    return i0 + i1;
}

extern "C"
int add3(
    int i0
,   int i1
,   int i2
)
{
    return i0 + i1 + i2;
}

extern "C"
int add10(
    int i0
,   int i1
,   int i2
,   int i3
,   int i4
,   int i5
,   int i6
,   int i7
,   int i8
,   int i9
)
{
    return i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9;
}


/* ///////////////////////////// end of file //////////////////////////// */

