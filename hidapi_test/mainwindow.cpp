#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hidapi.h"
#include <QDebug>

hid_device *handle;
#define MAX_STR 255

unsigned char send_buff[9] = {0x10, 0x55, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int res;
    unsigned char buf[65];
    wchar_t wstr[MAX_STR];
    int i;

    // Open the device using the VID, PID,
    // and optionally the Serial number.
    handle = hid_open(0x8888, 0x0006, NULL);

    // Read the Manufacturer String
    res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
    qDebug() << QString("Manufacturer String:").arg(wstr);

    // Read the Product String
    res = hid_get_product_string(handle, wstr, MAX_STR);
    qDebug() << QString("Product String: %s\n").arg(wstr);

    // Read the Serial Number String
    res = hid_get_serial_number_string(handle, wstr, MAX_STR);
    qDebug("Serial Number String: (%d) %s\n", wstr[0], wstr);

    // Read Indexed String 1
    res = hid_get_indexed_string(handle, 1, wstr, MAX_STR);
    qDebug() << QString("Indexed String 1: %s\n").arg(wstr);

    pReadHid = new ReadHid();
    pReadHid->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int res;
    res = hid_write(handle, send_buff, 9);
}
