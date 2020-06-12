#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QtWidgets/QMainWindow>
#include "ui_mainclass.h"
#include "qaesencryption.h"

typedef unsigned long DWORD;
typedef unsigned char UCHAR, *PUCHAR;
typedef void *PVOID, *LPVOID;
typedef unsigned char byte;
typedef DWORD *PDWORD, *LPDWORD;

enum FileType
{
	TYPE_DIR,
	TYPE_FILE,
};

class MainClass : public QMainWindow
{
	Q_OBJECT

public:
	MainClass(QWidget *parent = 0);
	~MainClass();

// 	DWORD OnAesEncrypt(LPVOID InBuffer, DWORD InLength, LPVOID OutBuffer);
// 	DWORD OnAesUncrypt(LPVOID InBuffer, DWORD InLength, LPVOID OutBuffer);
public slots:
	void onRadioButtonToggle(bool);
	void selectFileOrDoc();
	void encrypto();
	void decrypto();

private:
	Ui::MainClassClass ui;
	
	FileType fileType;
	QByteArray cryptoKey;
	QString srcDirPath;
	QString srcFilePath;

	int decryptoNum = 0;
	bool decryptoing = false;

	void decryptoDir(QString &filePath, QString &destPath, bool en = false);
	void oprateFile(bool en);
};

#endif // MAINCLASS_H
