#include "WelcomeDialog.h"

WelcomeDialog::WelcomeDialog(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    connect(ui.pushButton, &QPushButton::clicked, this, &QDialog::accept);
}

bool WelcomeDialog::choosenTop()
{
    //returns true if white on top, otherwise reurns false
    return ui.whiteOnTop->isChecked();
}

bool WelcomeDialog::choosenPlayer()
{
    //return true if second player is human, otherwise returns false
    return ui.opponentPlayer->isChecked();
}