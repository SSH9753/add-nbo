#include <stdint.h>
#include <stdio.h>

uint32_t nbo(uint32_t n){
    return ((n&0xff000000) >> 24) |((n&0x00ff0000) >> 8) |((n&0x0000ff00) << 8) |((n&0x000000ff) << 24);
}

int main(int argc, char **argv){
    uint32_t a,b,c;
    FILE * rfp1, *rfp2;
    
    rfp1 = fopen(argv[1],"rb");
    fread(&a,sizeof(uint32_t),1,rfp1);
    rfp2 = fopen(argv[2],"rb");
    fread(&b,sizeof(uint32_t),1,rfp2);

    a = nbo(a);
    b = nbo(b);
    c = a+b;
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)",a,a,b,b,c,c);

    return 0;
}