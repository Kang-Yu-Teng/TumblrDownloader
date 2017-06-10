#include "pythonthread.h"
#include <string>
#include <QProcess>
#include <iostream>
#include <QDir>

using namespace std;

QString stoq(const string &s)
{
return QString(QString::fromLocal8Bit(s.c_str()));
}
string qtos(const QString &s)
{
return string((const char *)s.toLocal8Bit());
}

PythonThread::PythonThread()
{

}


void PythonThread::run()
{
    sendMessage(stoq("thread running"));

    QProcess p;
    QString pythonCommand = "python " + qList[0] + " " + qList[1];

    sendMessage(qList[0]);
    sendMessage(qList[1]);

    p.execute(pythonCommand);

    p.waitForFinished(-1);

    QString p_stdout = p.readAllStandardOutput();
    sendMessage(p_stdout);


    if(QString::compare( qList[0], "")!=0){
        QString srcDir;
        QString destDir;
        srcDir = QDir::currentPath()+"/"+"images/"+qList[1];
        destDir = qList[2]+"/"+qList[1];
        QFile::rename(srcDir,destDir);
    }
    sendMessage(qList[0]+" "+stoq("finish"));
}

void PythonThread::setArg(QStringList inQList)
{
    qList=inQList;
}
