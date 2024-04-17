#include <stdio.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#define MAXN 1024
#define KEYFILE "public.pem"

void print_hex(unsigned char *cipher, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%02x", cipher[i]);
    }
    printf("\n");
}

RSA *load_public_key(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        fprintf(stderr, "Unable to open file");
        return NULL;
    }
    
    RSA *rsa  = PEM_read_RSAPublicKey(fp, NULL, NULL, NULL);
    fclose(fp);
    if(rsa == NULL)
    {
        fprintf(stderr, "Error reading public key\n");
        return NULL;
    }
    return rsa;
}

int encrypt_message(RSA *rsa, const unsigned char *plaintext, unsigned char *ciphertext)
{
    int result = RSA_public_encrypt(strlen((const char*) plaintext) + 1,
        plaintext, ciphertext, rsa, RSA_PKCS1_OAEP_PADDING);
    if(result == -1)
    {
        ERR_print_errors_fp(stderr);
        return -1;
    }
    return result;
}
int main()
{
    unsigned char plaintext[MAXN];
    scanf("%s", plaintext);
    unsigned char ciphertext[MAXN];
    
    RSA* rsa = load_public_key(KEYFILE);
    if(rsa == NULL)
    {
        return EXIT_FAILURE;
    }
    
    int encrypted_length = encrypt_message(rsa, plaintext, ciphertext);
    if(encrypted_length == -1)
    {
        fprintf(stderr, "Error encrypting message");
        RSA_free(rsa);
        return EXIT_FAILURE;
    }
    
    printf("Encrypted: \n");
    print_hex(ciphertext, strlen(ciphertext));
    RSA_free(rsa);
    return EXIT_SUCCESS;
}
