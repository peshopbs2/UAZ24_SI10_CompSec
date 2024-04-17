#include <stdio.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void clear(BIO *bp_public, BIO *bp_private, RSA *r, BIGNUM *big)
{
    BIO_free_all(bp_public);
    BIO_free_all(bp_private);
    RSA_free(r);
    BN_free(big);
}

int main()
{
    //TODO: create separate functions for allocating the big num, rsa, generating/saving public/private key
    RSA *r = NULL;
    BIO *bp_public = NULL, *bp_private = NULL;
    int bits = 2048;
    int result = 0;
    BIGNUM *big = BN_new();
    if(big == NULL)
    {
        fprintf(stderr, "Error allocating big number\n");
        return EXIT_FAILURE;
    }
    
    result = BN_set_word(big, RSA_F4);
    if(result != 1)
    {
        fprintf(stderr, "Error setting exponent");
        clear(bp_public, bp_private, r, big);
        return EXIT_FAILURE;
    }
    
    r = RSA_new();
    if(r == NULL)
    {
        fprintf(stderr, "Error allocating RSA\n");
        return EXIT_FAILURE;
    }
    
    result = RSA_generate_key_ex(r, bits, big, NULL);
    if(result != 1)
    {
        fprintf(stderr, "Error generating RSA key\n");
        clear(bp_public, bp_private, r, big);
        return EXIT_FAILURE;
    }
    
    bp_public = BIO_new_file("public.pem", "w+");
    if(bp_public == NULL)
    {
        fprintf(stderr, "Error opening public key file\n");
        return EXIT_FAILURE;
    }
    result = PEM_write_bio_RSAPublicKey(bp_public, r);
    if(result != 1)
    {
        fprintf(stderr, "Error writing public key\n");
        clear(bp_public, bp_private, r, big);
        return EXIT_FAILURE;
    }
    
    bp_private = BIO_new_file("private.pem", "w+");
    if(bp_private == NULL)
    {
        fprintf(stderr, "Error opening private key file\n");
        return EXIT_FAILURE;
    }
    result = PEM_write_bio_RSAPrivateKey(bp_private, r, NULL, NULL, 0, NULL, NULL);
    if(result != 1)
    {
        fprintf(stderr, "Error writing private key\n");
        clear(bp_public, bp_private, r, big);
        return EXIT_FAILURE;
    }
    
    printf("Done");
    return EXIT_SUCCESS;
}
