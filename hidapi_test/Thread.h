#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include "hidapi.h"

extern hid_device *handle;

//写文件线程
class ReadHid : public QThread
{
    Q_OBJECT
public:
    ReadHid(QObject *parent = 0);

protected:
    void run();
signals:

public slots:


private:

};

#endif // THREAD_H
