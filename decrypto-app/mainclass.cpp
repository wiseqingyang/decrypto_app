#include "mainclass.h"

#include <QMessageBox>
#include <QFile>
#include "cstring"
#include "QDebug"
#include <QFileDialog>
#include "QRegularExpression"
#include "QCryptographicHash"
#include "TestUtils.h"

/************************************************************************/
/*  加密解密是用的github开源代码，										*/
/*  地址https://github.com/bricke/Qt-AES									*/
/************************************************************************/


MainClass::MainClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	/*setwindowicon*/

	setWindowIcon(QIcon(QStringLiteral("Icon")));
	connect(ui.radioButton, &QRadioButton::toggled, this, &MainClass::onRadioButtonToggle);
	connect(ui.pushButton, &QPushButton::clicked, this, &MainClass::selectFileOrDoc);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &MainClass::decrypto);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &MainClass::encrypto);

	fileType = TYPE_DIR;	// 默认是文件夹模式
	srcFilePath = "";
	srcDirPath = "";
	//encryption = QAESEncryption(QAESEncryption::AES_128, QAESEncryption::ECB);
	cryptoKey = QByteArray("23EF118D977EB53401B75C1B4E98FC39", 128);
}

MainClass::~MainClass()
{
}

void MainClass::onRadioButtonToggle(bool is)
{
	fileType = is ? TYPE_DIR : TYPE_FILE;
	QString text = QString::fromLocal8Bit(is ? "源目录" : "源文件");
	ui.label->setText(text);
	qDebug() << "select " << text;
}

void MainClass::selectFileOrDoc()
{
	if (fileType == TYPE_DIR)
	{
		srcDirPath = QFileDialog::getExistingDirectory(
			this, "",
			"/");
		ui.lineEdit->setText(srcDirPath);
		qDebug() << "choose dic " << srcDirPath;
	}
	else
	{
		srcFilePath = QFileDialog::getOpenFileName(this, tr("open file"), "/");
		ui.lineEdit->setText(srcFilePath);
		qDebug() << "choose dic " << srcFilePath;
	}
}

void MainClass::encrypto()
{
	oprateFile(true);
}

void MainClass::decrypto()
{
	oprateFile(false);
}

void MainClass::oprateFile(bool en)
{
	decryptoNum = 0;
	if (decryptoing)
	{
		return;
	}
	decryptoing = true;
	if (fileType == TYPE_DIR && srcDirPath.length() > 0)
	{
		QDir dir(srcDirPath);
		QString fileName = dir.dirName();
		QString prefixPath = dir.path().remove(QRegularExpression(QString("%1$").arg(dir.dirName())));
		QString destPath = QString("%1de_%2").arg(prefixPath).arg(fileName);
		decryptoDir(srcDirPath, destPath, en);		
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("解密完成，共%1个文件").arg(decryptoNum), NULL, NULL);
	}
	else if (srcFilePath.length() > 0)
	{
		QDir dir(srcFilePath);

		QString fileName = dir.dirName();
		QString prefixPath = dir.path().remove(QRegularExpression(QString("%1$").arg(dir.dirName())));
		QString destPath = QString("%1de_%2").arg(prefixPath).arg(fileName);
		if (en)
		{
			TestUtils::encryptoFile(srcFilePath, destPath);
		}
		else
		{
			bool success = TestUtils::decryptoFile(srcFilePath, destPath);
			if (success)
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("解密完成，共1个文件"), NULL, NULL);
			else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("解密失败，不是有效的加密文件"), NULL, NULL);
			}
		}	
		
	}
	decryptoing = false;
}

void MainClass::decryptoDir(QString &srcDirPath, QString &destPath, bool en)
{
	qDebug() << "src filepath " << srcDirPath << " dest path " << destPath;
	QDir dir(srcDirPath);
	QFileInfoList list = dir.entryInfoList();
	QDir destDir(destPath);
	if (!destDir.exists())
	{
		QString fileName = destDir.dirName();
		destDir.cdUp();
		bool result = destDir.mkdir(fileName);
		qDebug() << destDir.path() << " make sub dir " << fileName << " " << result;
	}
	for (QFileInfoList::iterator ite = list.begin(); ite != list.end(); ite++)
	{
		qDebug() << (ite->isAbsolute() ? "true" : "false") << " " << ite->isDir() << " " << ite->fileName();
		if (ite->fileName() != "." &&  ite->fileName() != "..") {			
			if (ite->isDir())
			{
				decryptoDir(QString("%1/%2").arg(srcDirPath).arg(ite->fileName()), QString("%1/%2").arg(destPath).arg(ite->fileName()), en);
			}
			else
			{
				bool success = true;
				if (en) 
				{
					TestUtils::encryptoFile(QString("%1/%2").arg(srcDirPath).arg(ite->fileName()), QString("%1/%2").arg(destPath).arg(ite->fileName()));
				}
				else
				{
					success = TestUtils::decryptoFile(QString("%1/%2").arg(srcDirPath).arg(ite->fileName()), QString("%1/%2").arg(destPath).arg(ite->fileName()));
				}
				if (success)
				{
					decryptoNum++;
				} 
			}
		}		
	}
}

