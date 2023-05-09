#include "dialog4.h"
#include "ui_dialog4.h"

Dialog4::Dialog4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog4)
{
    ui->setupUi(this);
    setWindowTitle("ERROR");
}

Dialog4::~Dialog4()
{
    delete ui;
}

void Dialog4::on_pushButton_clicked()
{
    close();
}
