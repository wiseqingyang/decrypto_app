#pragma once


#include <QtWidgets/QMainWindow>

class TestUtils
{
public:
	TestUtils();
	~TestUtils();

	static void encryptoFile(QString filePath, QString destFile);
	static bool decryptoFile(QString filePath, QString destFile);
	static QByteArray OpenFile(QString fileName);
	static void WriteFile(QString fileName, QByteArray data);
};

