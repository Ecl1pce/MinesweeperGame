#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap background(":/images/background.png");
        QPalette qPalette;
        qPalette.setBrush(this->backgroundRole(),QBrush(background));
        this->setPalette(qPalette);

        ui->exitButton->setStyleSheet(QPushButtonStyle);
        ui->startGameButton->setStyleSheet(QPushButtonStyle);
        ui->optionsButton->setStyleSheet(QPushButtonStyle);

        connect(ui->optionsButton, SIGNAL(clicked(bool)),this, SLOT(goToOptions()));



}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::goToOptions()
{
    optionsWnd = new OptionsWindow;
    optionsWnd->show();
    this->close();
}

void MainWindow::goToStartGame()
{

}

