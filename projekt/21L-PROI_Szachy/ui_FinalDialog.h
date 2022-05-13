/********************************************************************************
** Form generated from reading UI file 'FinalDialogJydKIz.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FINALDIALOGJYDKIZ_H
#define FINALDIALOGJYDKIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FinalDialog
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *newGameButton;
    QPushButton *exitButton;

    void setupUi(QDialog *FinalDialog)
    {
        if (FinalDialog->objectName().isEmpty())
            FinalDialog->setObjectName(QString::fromUtf8("FinalDialog"));
        FinalDialog->resize(461, 171);
        label = new QLabel(FinalDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 30, 241, 61));
        widget = new QWidget(FinalDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 130, 365, 27));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newGameButton = new QPushButton(widget);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));

        horizontalLayout->addWidget(newGameButton);

        exitButton = new QPushButton(widget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout->addWidget(exitButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(FinalDialog);
        QObject::connect(newGameButton, SIGNAL(clicked()), FinalDialog, SLOT(accept()));
        QObject::connect(exitButton, SIGNAL(clicked()), FinalDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FinalDialog);
    } // setupUi

    void retranslateUi(QDialog *FinalDialog)
    {
        FinalDialog->setWindowTitle(QCoreApplication::translate("FinalDialog", "Koniec gry", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("FinalDialog", "Zapis do pliku", nullptr));
        newGameButton->setText(QCoreApplication::translate("FinalDialog", "Nowa gra", nullptr));
        exitButton->setText(QCoreApplication::translate("FinalDialog", "Koniec", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinalDialog: public Ui_FinalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FINALDIALOGJYDKIZ_H
