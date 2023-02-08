#include "IPGwidget.h"
#include "ui_IPGwidget.h"

IPGwidget::IPGwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IPGwidget)
{
    ui->setupUi(this);
}

IPGwidget::~IPGwidget()
{
    delete ui;
}


void IPGwidget::on_btnSend2_clicked()
{
    std::string input = ui->textEdit1->toPlainText().toUtf8().toStdString();
    ui->btnSend2->setText(QString::fromStdString(input));
    ui->textEdit1->document()->clear();
}
