/********************************************************************************
** Form generated from reading UI file 'WelcomeDialogrSTXTo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WELCOMEDIALOGRSTXTO_H
#define WELCOMEDIALOGRSTXTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *opponentPlayer;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *opponentComputer;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QRadioButton *whiteOnTop;
    QSpacerItem *horizontalSpacer;
    QRadioButton *blackOnTop;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(400, 185);
        Dialog->setMinimumSize(QSize(400, 185));
        Dialog->setMaximumSize(QSize(400, 185));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 150, 75, 23));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 80, 217, 43));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        opponentPlayer = new QRadioButton(layoutWidget);
        opponentPlayer->setObjectName(QString::fromUtf8("opponentPlayer"));
        opponentPlayer->setChecked(true);

        horizontalLayout_2->addWidget(opponentPlayer);

        horizontalSpacer_2 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        opponentComputer = new QRadioButton(layoutWidget);
        opponentComputer->setObjectName(QString::fromUtf8("opponentComputer"));

        horizontalLayout_2->addWidget(opponentComputer);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 20, 211, 43));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        whiteOnTop = new QRadioButton(layoutWidget1);
        whiteOnTop->setObjectName(QString::fromUtf8("whiteOnTop"));
        whiteOnTop->setChecked(true);

        horizontalLayout->addWidget(whiteOnTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        blackOnTop = new QRadioButton(layoutWidget1);
        blackOnTop->setObjectName(QString::fromUtf8("blackOnTop"));

        horizontalLayout->addWidget(blackOnTop);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Wyb\303\263r opcji gry", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Jaki rywal?", nullptr));
        opponentPlayer->setText(QCoreApplication::translate("Dialog", "Inny gracz", nullptr));
        opponentComputer->setText(QCoreApplication::translate("Dialog", "Komputer", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Kt\303\263re pionki na g\303\263rze?", nullptr));
        whiteOnTop->setText(QCoreApplication::translate("Dialog", "Bia\305\202e", nullptr));
        blackOnTop->setText(QCoreApplication::translate("Dialog", "Czarne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WELCOMEDIALOGRSTXTO_H
