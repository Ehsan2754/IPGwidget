/********************************************************************************
** Form generated from reading UI file 'IPGwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IPGWIDGET_H
#define UI_IPGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IPGwidget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacerTop;
    QHBoxLayout *Row1;
    QSpacerItem *spacerLeft1;
    QTextEdit *textEdit1;
    QSpacerItem *spacerRight1;
    QSpacerItem *verticalSpacerRow2;
    QHBoxLayout *Row2;
    QSpacerItem *spacerLeft2;
    QPushButton *btnSend2;
    QSpacerItem *spacerRight2;
    QSpacerItem *verticalSpacerBottom;

    void setupUi(QWidget *IPGwidget)
    {
        if (IPGwidget->objectName().isEmpty())
            IPGwidget->setObjectName(QString::fromUtf8("IPGwidget"));
        IPGwidget->resize(424, 324);
        IPGwidget->setMinimumSize(QSize(424, 324));
        IPGwidget->setBaseSize(QSize(400, 300));
        IPGwidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"           background-color: #161616;\n"
"\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(IPGwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacerTop = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacerTop);

        Row1 = new QHBoxLayout();
        Row1->setObjectName(QString::fromUtf8("Row1"));
        spacerLeft1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Row1->addItem(spacerLeft1);

        textEdit1 = new QTextEdit(IPGwidget);
        textEdit1->setObjectName(QString::fromUtf8("textEdit1"));
        textEdit1->setMinimumSize(QSize(380, 240));
        textEdit1->setBaseSize(QSize(380, 240));
        textEdit1->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"           background-color: #a5a5a5;\n"
"           color: #fcfcfc;\n"
"           border: 1px solid #ff0000;\n"
"       }"));

        Row1->addWidget(textEdit1);

        spacerRight1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Row1->addItem(spacerRight1);


        verticalLayout->addLayout(Row1);

        verticalSpacerRow2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacerRow2);

        Row2 = new QHBoxLayout();
        Row2->setObjectName(QString::fromUtf8("Row2"));
        spacerLeft2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Row2->addItem(spacerLeft2);

        btnSend2 = new QPushButton(IPGwidget);
        btnSend2->setObjectName(QString::fromUtf8("btnSend2"));
        btnSend2->setMinimumSize(QSize(40, 20));
        btnSend2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"           background-color: #5b6366;\n"
"           color: #fcfcfc;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"  			background-color: #619bd5;\n"
"}\n"
"\n"
"QPushButton:!pressed {\n"
"  			background-color: initial;\n"
"}"));

        Row2->addWidget(btnSend2);

        spacerRight2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Row2->addItem(spacerRight2);


        verticalLayout->addLayout(Row2);

        verticalSpacerBottom = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacerBottom);


        retranslateUi(IPGwidget);

        QMetaObject::connectSlotsByName(IPGwidget);
    } // setupUi

    void retranslateUi(QWidget *IPGwidget)
    {
        IPGwidget->setWindowTitle(QCoreApplication::translate("IPGwidget", "IPGwidget", nullptr));
#if QT_CONFIG(tooltip)
        btnSend2->setToolTip(QCoreApplication::translate("IPGwidget", "<html><head/><body><p>Send text to the stream</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSend2->setText(QCoreApplication::translate("IPGwidget", "SEND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IPGwidget: public Ui_IPGwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPGWIDGET_H
