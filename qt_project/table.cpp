#include "table.h"
#include "ui_table.h"



Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    setWindowTitle("UsersDataBase");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");
    if(db.open()){
        qDebug("Open");
    }
    else{
        qDebug("Not open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE RegisteredUsers(Email TEXT, Password TEXT);");

    model = new QSqlTableModel(this, db);
    model->setTable("RegisteredUsers");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);




}

Table::~Table()
{
    delete ui;
}

void Table::sign_in(QString email, QString password)
{
    QSqlRecord record = model->record();
    record.setValue("Email", email);
    record.setValue("Password", password);
    model->insertRecord(-1, record);
    model->submitAll();
}

void Table::on_pushButton_clicked()
{
    model->removeRow(row);
}

void Table::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}
