#include "ChangePieceDialog.h"


ChangePieceDialog::ChangePieceDialog(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
}

int ChangePieceDialog::choosenPiece()
{
	if (ui.radioQueen->isChecked())
		return 1;
	if (ui.radioKnight->isChecked())
		return 2;
	if (ui.radioBishop->isChecked())
		return 3;
	return 4;
}
