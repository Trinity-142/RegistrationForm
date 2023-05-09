#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>
#include <dialog2.h>
#include <dialog3.h>
#include <dialog4.h>
#include <dialog5.h>
#include <table.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    Dialog2 *dialog2;
    Dialog3 *dialog3;
    Dialog4 *dialog4;
    Dialog5 *dialog5;
    Table *table;


signals:
    void sign_in(QString email, QString password);

};
#endif // MAINWINDOW_H
