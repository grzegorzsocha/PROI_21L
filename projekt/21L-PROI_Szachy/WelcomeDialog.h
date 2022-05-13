#pragma once

#include <QtWidgets/qdialog.h>
#include <qpushbutton.h>
#include "ui_WelcomeDialog.h"

class WelcomeDialog : public QDialog
{
    Q_OBJECT

public:
    WelcomeDialog(QWidget* parent = Q_NULLPTR);
    bool choosenTop();
    bool choosenPlayer();

private:
    Ui::Dialog ui;
};
