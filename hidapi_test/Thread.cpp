
#include "Thread.h"
#include <QFile>
#include <QDebug>

//写文件线程初始化
ReadHid::ReadHid(QObject *parent) :
    QThread(parent)
{
    qDebug() << "Thread Init!" ;
}

//
void ReadHid::run()
{
    unsigned char buf[65];
    int i;
    int ret;
    while(1)
    {
        ret = hid_read(handle, buf, 65);

        // Print out the returned buffer.
        for (i = 0; i < ret; i++)
            qDebug("buf[%d]: %d\n", i, buf[i]);

        msleep(1000);
    }
}

