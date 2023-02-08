#ifndef IPGWIDGET_H
#define IPGWIDGET_H

#include <QWidget>
#include "../lib/IPGStreamThread.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class IPGwidget; }
QT_END_NAMESPACE

class IPGwidget : public QWidget
{
    Q_OBJECT

public:
    IPGwidget(QWidget *parent = nullptr);
    ~IPGwidget();

private slots:
    void on_btnSend2_clicked();

private:
    Ui::IPGwidget *ui;
    IPGStreamThread *stream_thread;
};
#endif // IPGWIDGET_H
