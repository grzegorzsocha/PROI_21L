#include "FinalDialog.h"
#include <qstring.h>

FinalGameDialog::FinalGameDialog(std::string text, MainWindow* window, QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.label->setText(QString::fromStdString(text));
	connect(ui.pushButton, &QPushButton::clicked, window, &MainWindow::saveToFile);
	setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
}