#include "optionswindow.h"
#include "ui_optionswindow.h"
#include "mainwindow.h"

OptionsWindow::OptionsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsWindow)
{
    ui->setupUi(this);

    QPixmap background(":/images/options_background.jpg");
        QPalette qPalette;
        qPalette.setBrush(this->backgroundRole(),QBrush(background));
        this->setPalette(qPalette);

    connect(ui->backButton, SIGNAL(clicked(bool)), this, SLOT(backToMenu()));
}

OptionsWindow::~OptionsWindow()
{
    delete ui;
}


void OptionsWindow::backToMenu()
{
    MainWindow *mainWnd = new MainWindow;
    mainWnd->show();
    this->close();
}
