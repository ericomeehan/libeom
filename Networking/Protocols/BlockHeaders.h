#ifndef BlockHeaders_h
#define BlockHeaders_h

struct BlockHeaders // Bytes:
{
    unsigned char previous[64]; // 0 - 63
    unsigned long nonce;        // 64 - 71

    unsigned char by[64]; // 72 - 135
    char timestamp[20];   // 136 - 165
    unsigned long size;   // 156 - 164
};

struct Block
{
    struct BlockHeaders headers;
    unsigned char data;
};

#endif /* BlockHeaders_h */
