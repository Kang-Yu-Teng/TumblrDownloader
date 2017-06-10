#ifndef PYTHONTHREAD_H
#define PYTHONTHREAD_H

#include <QThread>
#include <QProcess>

class PythonThread:public QThread
{
    Q_OBJECT
public:
    PythonThread();
    void setArg(QStringList);
    QStringList qList;
    QProcess * pyProcess;
signals:
    void sendMessage(QString);
protected:
    void run();
private slots:
    void liveReader();

};

#endif // PYTHONTHREAD_H
