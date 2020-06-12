#include "TestUtils.h"
#include "QCryptographicHash"
#include "qaesencryption.h"
#include <QDebug>
#include "qstring.h"
#include <QFile>

#include <QUnhandledException>
#include <QException>

TestUtils::TestUtils()
{
}


TestUtils::~TestUtils()
{
}


// char* Aes(char *key, int *destLen, char *src, int srcLen)
// {
// 	mbedtls_aes_context aes_ctx;
// 	mbedtls_aes_init(&aes_ctx);
// 	//设置加密密钥  
// 	mbedtls_aes_setkey_enc(&aes_ctx, (unsigned char *)key, 128);
// 	//获取块的数量
// 	int block = srcLen / 16 + 1;
// 	//动态分配内存
// 	*destLen = block * 16;
// 	char *dest = new char[*destLen];
// 	//清空
// 	memset(dest, 0, *destLen);
// 	//分块加密，每块16字节长度
// 	unsigned char input[16];
// 	unsigned char outout[16];
// 
// 	int b = 0;
// 	while (b < block){
// 		int offset = b * 16;
// 		int len = 0;
// 		if ((srcLen - 16 - offset) > 0){
// 			len = 16;
// 		}
// 		else{
// 			len = srcLen - offset;
// 		}
// 		memset(input, 0, 16);
// 		memset(outout, 0, 16);
// 		memcpy(input, &src[offset], len);
// 		//加密
// 		mbedtls_aes_crypt_ecb(&aes_ctx, MBEDTLS_AES_ENCRYPT, input, outout);
// 		memcpy(&dest[b * 16], outout, 16);
// 		b++;
// 	}
// 	qDebug() << dest << " " << *destLen;
// 	return dest;
// }

// void TestUtils::openSSLEncrypto()
// {
// 	int len = 0;
// 	char* abc = "1234567812345678";
// 	char* a = Aes("1234567812345678", &len, abc, strlen(abc));
// 	QString dest = a;
// 	qDebug() << len;
// 	qDebug() << QByteArray(a, len).toBase64();
// }

void TestUtils::encryptoFile(QString filePath, QString destFile)
{
	qDebug() << "encrypto file " << filePath << " destFile " << destFile;
	QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::CBC, QAESEncryption::PKCS7);

	QString key("1111222233334444");
	QString iv("1234567891234567");

	QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
	QByteArray hashIV = QCryptographicHash::hash(iv.toLocal8Bit(), QCryptographicHash::Md5);

	QByteArray encodeText = encryption.encode(OpenFile(filePath), hashKey, hashIV);
	WriteFile(destFile, encodeText);
}

bool TestUtils::decryptoFile(QString filePath, QString destFile)
{
	qDebug() << "decrypto file " << filePath << " destFile " << destFile;
	QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::CBC, QAESEncryption::PKCS7);

	QString key("1111222233334444");
	QString iv("1234567891234567");

	QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
	QByteArray hashIV = QCryptographicHash::hash(iv.toLocal8Bit(), QCryptographicHash::Md5);
	hashKey = key.toLocal8Bit();
	hashIV = iv.toLocal8Bit();
	QByteArray encodeText;
	QByteArray fileText = OpenFile(filePath);
	if (fileText.size() % 16) {
		qDebug() << "fileText.size " << fileText.size();
		return false;
	}
	encodeText = encryption.decode(fileText, hashKey, hashIV);
	
	WriteFile(destFile, encryption.removePadding(encodeText));
	return true;
}

//打开文件，将文件中的内容返回一个QbyteArray的数组
QByteArray TestUtils::OpenFile(QString fileName){
	QFile file(fileName);
	file.open((QIODevice::ReadWrite));
	QByteArray temp = file.read(file.bytesAvailable());
	file.close();
	return temp;
}

//将一个QbyteArray数组写入到指定文件中去。
//使用二进制数组进行文件的读写能够有效避免各种由于编码格式和类型转换造成的问题
void TestUtils::WriteFile(QString fileName, QByteArray data){
	QFile file(fileName);
	qDebug() << file.open((QIODevice::ReadWrite | QIODevice::Truncate));
	qDebug() << "have write" << file.write(data);
	file.close();
	return;
}