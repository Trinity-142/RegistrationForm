#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Registration");
    dialog = new Dialog;
    dialog2 = new Dialog2;
    dialog3 = new Dialog3;
    dialog4 = new Dialog4;
    dialog5 = new Dialog5;
    table = new Table;
    connect(this, &MainWindow::sign_in, table, &Table::sign_in);


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    if ((((ui->lineEdit->text()) == "admin") and (ui->lineEdit_2->text()) == "admin123"))
    {
        table->show();
    }
    else if (!table->find_row(ui->lineEdit->text(), 1000000))
    {
        dialog4->setModal(true);
        dialog4->exec();
    }
    else if ((ui->lineEdit->text() != "") and (ui->lineEdit_2->text() != "") and (table->find_row(ui->lineEdit->text(), 1000000)) and (table->check_password(ui->lineEdit_2->text(), 1000000)))
    {
        dialog->setModal(true);
        dialog->exec();
    }
    else if (!table->check_password(ui->lineEdit_2->text(), 1000000))
    {
        dialog5->setModal(true);
        dialog5->exec();
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    if (table->find_row(ui->lineEdit->text(), 1000000))
    {
        dialog3->setModal(true);
        dialog3->exec();
    }
    else if ((((ui->lineEdit->text()) != "") and (ui->lineEdit_2->text()) != ""))
    {
        emit sign_in(ui->lineEdit->text(), ui->lineEdit_2->text());
        dialog2->setModal(true);
        dialog2->exec();
    }
}

