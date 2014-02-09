int bitcount(unsigned x)
{
    for (int b = 0; x != 0; x &= (x-1)) {
        b++;
    }

    return b;
}
