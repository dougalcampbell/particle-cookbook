/**
 * Using AES256 encryption/decryption
 *
 * @author @hirotakaster
 * @see https://community.particle.io/t/aes-256-options/47437
 */
#include "TlsTcpClient.h"
#include "mbedtls/aes.h"

void setup() {
    Serial.begin(9600);

    unsigned char key[32];
    unsigned char iv_enc[16] = {'i', 'n', 'i', 't', 'i', 'a', 'l', 'v', 'e', 'c', 't', 'o', 'r', ' ', ' ', ' '};
    unsigned char iv_dec[16] = {'i', 'n', 'i', 't', 'i', 'a', 'l', 'v', 'e', 'c', 't', 'o', 'r', ' ', ' ', ' '};
    unsigned char encbuff[128];
    unsigned char decbuff[128];
    unsigned char str[128];

    memset(str, 0, sizeof(str));
    memset(encbuff, 0, sizeof(encbuff));
    memset(decbuff, 0, sizeof(decbuff));
    
    for (int i = 0; i < 32; i++) key[i] = i;
    strcpy((char *)str, "Some text for AES 256 bytes :)");
    
    mbedtls_aes_context aes_ctx;
    
    mbedtls_aes_init(&aes_ctx);
    mbedtls_aes_setkey_enc(&aes_ctx, key, 256);
    mbedtls_aes_crypt_cbc(&aes_ctx, MBEDTLS_AES_ENCRYPT, 128, iv_enc, str, encbuff);

    mbedtls_aes_setkey_dec(&aes_ctx, key, 256);
    mbedtls_aes_crypt_cbc(&aes_ctx, MBEDTLS_AES_DECRYPT, 128, iv_dec, encbuff, decbuff);
    mbedtls_aes_free(&aes_ctx);
    Serial.print("Dec:"); Serial.println((char *)decbuff);

}

void loop() {
    delay(1000);
}
