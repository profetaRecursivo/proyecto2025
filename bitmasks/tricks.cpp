//generacion de mascaras lexicograficas
unsigned int nextComb(unsigned int x) {
    unsigned int c = x & -x;
    unsigned int r = x + c;
    return (((r ^ x) >> 2) / c) | r;
}