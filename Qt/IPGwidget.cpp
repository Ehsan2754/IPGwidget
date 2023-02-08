#include "IPGwidget.h"
#include "ui_IPGwidget.h"
IPGwidget::IPGwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IPGwidget)
{
    ui->setupUi(this);
    stream_thread = new IPGStreamThread();
}

IPGwidget::~IPGwidget()
{
    delete stream_thread;
    delete ui;
}


void IPGwidget::on_btnSend2_clicked()
{
    std::string input = ui->textEdit1->toPlainText().toUtf8().toStdString();
    /* checking if input is empty string */
    if (input != std::string("")){
        stream_thread->addToQueue(input);
    }
    ui->textEdit1->document()->clear();
}
