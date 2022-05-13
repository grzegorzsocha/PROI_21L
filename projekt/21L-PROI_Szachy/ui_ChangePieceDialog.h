/********************************************************************************
** Form generated from reading UI file 'ChangePieceDialoggXNEFR.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CHANGEPIECEDIALOGGXNEFR_H
#define CHANGEPIECEDIALOGGXNEFR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PieceDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioQueen;
    QRadioButton *radioKnight;
    QRadioButton *radioBishop;
    QRadioButton *radioRook;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(430, 165);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioQueen = new QRadioButton(Dialog);
        radioQueen->setObjectName(QString::fromUtf8("radioQueen"));

        horizontalLayout->addWidget(radioQueen);

        radioKnight = new QRadioButton(Dialog);
        radioKnight->setObjectName(QString::fromUtf8("radioKnight"));

        horizontalLayout->addWidget(radioKnight);

        radioBishop = new QRadioButton(Dialog);
        radioBishop->setObjectName(QString::fromUtf8("radioBishop"));

        horizontalLayout->addWidget(radioBishop);

        radioRook = new QRadioButton(Dialog);
        radioRook->setObjectName(QString::fromUtf8("radioRook"));

        horizontalLayout->addWidget(radioRook);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Dialog);
        QObject::connect(pushButton, SIGNAL(clicked()), Dialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Wyb\303\263r figury", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Na jak\304\205 figur\304\231 wymieni\304\207 pionka?", nullptr));
        radioQueen->setText(QCoreApplication::translate("Dialog", "Hetman", nullptr));
        radioKnight->setText(QCoreApplication::translate("Dialog", "Ko\305\204", nullptr));
        radioBishop->setText(QCoreApplication::translate("Dialog", "Goniec", nullptr));
        radioRook->setText(QCoreApplication::translate("Dialog", "Wie\305\274a", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PieceDialog: public Ui_PieceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CHANGEPIECEDIALOGGXNEFR_H
