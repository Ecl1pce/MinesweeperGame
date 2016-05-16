#include "optionswindow.h"
#include "ui_optionswindow.h"
#include "mainwindow.h"

OptionsWindow::OptionsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsWindow)
{
    ui->setupUi(this);

    this->setFixedSize(SCREEN_SIZE);

    QPixmap background(":/resources/images/options_background.jpg");
        QPalette qPalette;
        qPalette.setBrush(this->backgroundRole(),QBrush(background));
        this->setPalette(qPalette);

    ui->backButton->setStyleSheet(QPushButtonStyle);
    ui->saveButton->setStyleSheet(QPushButtonStyle);

    connect(ui->backButton, SIGNAL(clicked(bool)), this, SLOT(backToMenu()));
    connect(ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(saveChanges()));
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

void OptionsWindow::saveChanges()
{

}
