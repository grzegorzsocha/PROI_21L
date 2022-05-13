#pragma once
#include <string>
#include <QtWidgets/qdialog.h>
#include <qpushbutton.h>
#include "ui_FinalDialog.h"
#include "MainWindow.h"

class FinalGameDialog : public QDialog
{
    Q_OBJECT

public:
    FinalGameDialog(std::string text, MainWindow* window, QWidget* parent = Q_NULLPTR);

private:
    Ui::FinalDialog ui;
};
