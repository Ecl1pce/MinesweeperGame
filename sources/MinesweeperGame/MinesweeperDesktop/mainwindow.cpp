#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap background(":/resources/images/background.png");
        QPalette qPalette;
        qPalette.setBrush(this->backgroundRole(),QBrush(background));
        this->setPalette(qPalette);

        this->setFixedSize(SCREEN_SIZE);

        ui->exitButton->setStyleSheet(QPushButtonStyle);
        ui->startGameButton->setStyleSheet(QPushButtonStyle);
        ui->optionsButton->setStyleSheet(QPushButtonStyle);

        connect(ui->optionsButton, SIGNAL(clicked(bool)),this, SLOT(goToOptions()));
        connect(ui->startGameButton, SIGNAL(clicked(bool)), this, SLOT(goToStartGame()));



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
   gameWnd = new GameWindow;
   gameWnd->show();
   this->close();
}

