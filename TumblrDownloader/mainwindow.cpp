#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include "pythonthread.h"
#include <QThread>

using namespace std;

#ifndef STRING_TRANS
#define STRING_TRANS

QString s2q(const string &s)
{
return QString(QString::fromLocal8Bit(s.c_str()));
}
string q2s(const QString &s)
{
return string((const char *)s.toLocal8Bit());
}

#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getMessage(QString msg)
{
    ui->textBrowser->append(msg);
}

void MainWindow::on_pushButton_clicked()
{
    QString qFileName;
    qFileName = s2q("tumblrdownloader.py");

    QString qTumblrSite;
    qTumblrSite = ui->lineEdit->text();

    QString qDownloadPath;
    qDownloadPath = ui->lineEdit_2->text();

    ui->textBrowser->append(qTumblrSite);
    ui->textBrowser->append(qDownloadPath);

    PythonThread * pyThread = new PythonThread();
    QStringList qList;
    qList << qFileName << qTumblrSite << qDownloadPath;
    pyThread->setArg(qList);
    connect(pyThread,SIGNAL(sendMessage(QString)),this,SLOT(getMessage(QString)));

    pyThread->start();

}
