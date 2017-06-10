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
    sendMessage(qList[0]);
    sendMessage(qList[1]);

    QProcess p;

#ifdef __unix__ /* __unix__ is usually defined by compilers targeting Unix systems */
    QString python = "python";
#elif defined _WIN32 /* _WIN32 is usually defined by compilers targeting 32 or 64 bit Windows systems */
    QString python = "c:/python27/python";
#endif

    QString pythonCommand = python + " " + qList[0] + " " + qList[1];

    QStringList arg;
    arg << qList[0] << qList[1];

/*
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("PYTHONPATH","C:\\Python27\\Lib;C:\\Python27\\DLLs;C:\\Python27\\Lib\\lib-tk;C:\\Python27;");
    env.insert("PATH", env.value("Path") + "C:\\Python27\\Lib;C:\\Python27\\DLLs;C:\\Python27\\Lib\\lib-tk;C:\\Python27");
    env.insert("PYTHONPATH","C:\\Python27\\Lib;C:\\Python27\\DLLs;C:\\Python27\\Lib\\lib-tk;C:\\Python27");
    p.setProcessEnvironment(env);
    QString env_variable;
    QStringList paths_list = env.toStringList();

    foreach( env_variable, paths_list )
        sendMessage( env_variable);
*/
    p.execute(pythonCommand);
    //p.start(python,arg);
    //p.start(pythonCommand);
    //p.startDetached(pythonCommand);
    //p.execute(qList[0],arg);

    //QString p_stdout;
    //p.waitForReadyRead();

    //p_stdout = p.readAllStandardOutput();
    //sendMessage(p_stdout);

    p.waitForFinished(-1);

    //p_stdout = p.readAllStandardOutput();
    //sendMessage(p_stdout);


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
