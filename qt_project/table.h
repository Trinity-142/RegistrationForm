#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>



namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);

    bool find_row(QString email, int row_count)
    {
        for (int i = 0; i < row_count; i++)
        {
            if(model->data(model->index(i,0)) == email)
            {
                return true;
                break;
            }
        }
        return false;
    }

    bool check_password(QString password, int row_count)
    {
        for (int i = 0; i < row_count; i++)
        {
            if(model->data(model->index(i,1)) == password)
            {
                return true;
                break;
            }
        }
        return false;
    }


    ~Table();
private:
    Ui::Table *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    int row;




public slots:
    void sign_in(QString email, QString password);
private slots:
    void on_pushButton_clicked();
    void on_tableView_clicked(const QModelIndex &index);
};

#endif // TABLE_H
