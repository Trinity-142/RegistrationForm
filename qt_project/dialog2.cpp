#include "dialog2.h"
#include "ui_dialog2.h"
#include <mainwindow.h>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    setWindowTitle("Confirmation");
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    close();
}
