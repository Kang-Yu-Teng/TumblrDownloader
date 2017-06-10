#ifndef PYTHONTHREAD_H
#define PYTHONTHREAD_H

#include <QThread>

class PythonThread:public QThread
{
    Q_OBJECT
public:
    PythonThread();
    void setArg(QStringList);
    QStringList qList;
signals:
    void sendMessage(QString);
protected:
    void run();


};

#endif // PYTHONTHREAD_H
