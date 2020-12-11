#include "MyRSA.h"
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#define PUBLICKEY  "\
		 -----BEGIN PUBLIC KEY-----\n\
         MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDjWg9fScDDM2ydoEYZbbTDHyE6\n\
         xNsOrNCCaBso6KXwvnSLzwxETpxkLkaFdI7GXYqATDtL7xCcyGY4d4Wz4iOk3CqF\n\
         E58+hJ9/jlX8HsAX5HyPxF2kmVa8XhH7ttoEe5AkYExzxWpDYPUFOGuoOIb3OY4G\n\
         hyAarREefC7yk467sQIDAQAB\n\
         -----END PUBLIC KEY-----\n"
#define  PADDING   RSA_PKCS1_PADDING          //��䷽ʽ
#pragma comment(lib,"Crypt32.lib")
//#pragma comment(lib,"..\\lib\\libcrypto.lib")
//#pragma comment(lib,"..\\lib\\libssl.lib")
MyRSA::MyRSA()
{

}


MyRSA::~MyRSA()
{

}
/**
* ע��ע�⣺������һ����Կͬʱ�����ܽ��ܡ�ֻ�ܹ�Կ����+˽Կ���� / ˽Կ����+��Կ����
 *
* ��Կ���ڿͻ��ˣ�˽Կ���ڷ����
* */
/**
   * ��Կ����
* */
std::string MyRSA::encryptRSAbyPublickey(const std::string & data, int * lenreturn)
{
	int ret, flen;
	BIO *bio = NULL;
	RSA *r = NULL;

	bio = BIO_new_mem_buf("-----BEGIN PUBLIC KEY-----\n"
		"MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDjWg9fScDDM2ydoEYZbbTDHyE6\n"
		"xNsOrNCCaBso6KXwvnSLzwxETpxkLkaFdI7GXYqATDtL7xCcyGY4d4Wz4iOk3CqF\n"
		"E58+hJ9/jlX8HsAX5HyPxF2kmVa8XhH7ttoEe5AkYExzxWpDYPUFOGuoOIb3OY4G\n"
		"hyAarREefC7yk467sQIDAQAB\n"
		"-----END PUBLIC KEY-----\n", -1);   //���ַ�����ȡRSA��Կ

	if (bio == NULL)
	{
		return "";
	}

	r = PEM_read_bio_RSA_PUBKEY(bio, NULL, NULL, NULL);

	flen = RSA_size(r);

	if (PADDING == RSA_PKCS1_PADDING || PADDING == RSA_SSLV23_PADDING) {
	//	//        flen -= 11;
	}

	lenreturn = &flen;

	std::string gkbn;

	char *dst = (char *)malloc(flen + 1);
	memset(dst, 0, flen + 1);

	int status = RSA_public_encrypt(data.length(), (unsigned char *)data.c_str(),
		(unsigned char *)dst, r, RSA_PKCS1_PADDING);
	if (status < 0) {

		//LOGE("RSA ��Կ����ʧ��--->%d", status);
		return "";

	}

	gkbn.assign((char *)dst, status);

	RSA_free(r);
	BIO_set_close(bio, BIO_CLOSE);
	BIO_free(bio);

	free(dst);
	CRYPTO_cleanup_all_ex_data();
	

	return gkbn;
}

std::string MyRSA::decryptRSAbyPublicKey(const std::string & data)
{
	int ret, flen;
	BIO *bio = NULL;
	RSA *r = NULL;
	//LOGE("RSA ��Կ���ܿ�ʼ--->%d", 1);
	if ((bio = BIO_new_mem_buf("-----BEGIN PUBLIC KEY-----\n"
		"MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDjWg9fScDDM2ydoEYZbbTDHyE6\n"
		"xNsOrNCCaBso6KXwvnSLzwxETpxkLkaFdI7GXYqATDtL7xCcyGY4d4Wz4iOk3CqF\n"
		"E58+hJ9/jlX8HsAX5HyPxF2kmVa8XhH7ttoEe5AkYExzxWpDYPUFOGuoOIb3OY4G\n"
		"hyAarREefC7yk467sQIDAQAB\n"
		"-----END PUBLIC KEY-----\n", -1)) == NULL)       //���ַ�����ȡRSA��Կ
	{
		//LOGE("BIO_new_mem_buf failed!\n");
	}
	//LOGE("RSA ��Կ���ܿ�ʼ--->%d", 2);
	r = PEM_read_bio_RSA_PUBKEY(bio, NULL, NULL, NULL);

	flen = RSA_size(r);
	//LOGE("RSA ��Կ���ܿ�ʼ--->%d", 3);
	if (PADDING == RSA_PKCS1_PADDING || PADDING == RSA_SSLV23_PADDING) {
		//        flen -= 11;
	}
	//LOGE("RSA ��Կ���ܿ�ʼ--->%d", 4);
	static std::string gkbn;
	gkbn.clear();
	//LOGE("RSA ��Կ���ܿ�ʼ--->%d", 5);
	char *dst = (char *)malloc(flen + 1);
	//bzero(dst, flen);
	memset(dst, 0, flen+1);
	//LOGE("RSA ��Կ���ܿ�ʼ--->%d", 6);
	int status = RSA_public_decrypt(data.length(), (unsigned char *)data.c_str(),
		(unsigned char *)dst, r, RSA_PKCS1_PADDING);//RSA_NO_PADDING //RSA_PKCS1_PADDING
	if (status < 0) {

		//LOGE("RSA ��Կ����ʧ��--->%d", status);
		return "";

	}

	gkbn.assign((char *)dst, status);//��ֹ β��0 ���ض�

	BIO_free_all(bio);

	free(dst);

	// CRYPTO_cleanup_all_ex_data(); //�������CRYPTO_EX_DATA��ȫ��hash���е����ݣ������ڴ�й©

	return gkbn;
}
