/*
    Manlove, Chris

    April 23, 2023

    LAHacks
*/

#ifndef SHA256_H
#define SHA256_H
#include <string>
#include <cstring>


#define DBL_INT_ADD(a,b,c) if (a > 0xffffffff - (c)) b++; a += c;
#define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
#define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
#define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

typedef struct {
	unsigned char data[64];
	unsigned int datalen;
	unsigned int bitlen[2];
	unsigned int state[8];
} SHA256_CTX;

void SHA256Transform(SHA256_CTX* ctx, unsigned char data[]);
void SHA256Init(SHA256_CTX* ctx);
void SHA256Update(SHA256_CTX* ctx, unsigned char data[], unsigned int len);
void SHA256Final(SHA256_CTX* ctx, unsigned char hash[]);
std::string sha256(char* data);
//unsigned char* sha256(char* data);

#endif