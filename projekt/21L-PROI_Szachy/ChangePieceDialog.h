#pragma once

#include <QtWidgets/qdialog.h>
#include <qpushbutton.h>
#include "ui_ChangePieceDialog.h"

class ChangePieceDialog : public QDialog
{
    Q_OBJECT

public:
    ChangePieceDialog(QWidget* parent = Q_NULLPTR);
    int choosenPiece();

private:
    Ui::PieceDialog ui;
};
