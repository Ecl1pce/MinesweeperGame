#include "choicelevelwindow.h"
#include "ui_choicelevelwindow.h"
#include "gamewindow.h"
#include "mainwindow.h"

ChoiceLevelWindow::ChoiceLevelWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChoiceLevelWindow)
{
    ui->setupUi(this);

    QPixmap background(":/resources/images/options_background.jpg");
        QPalette qPalette;
        qPalette.setBrush(this->backgroundRole(),QBrush(background));
        this->setPalette(qPalette);

    this->setWindowTitle("Choice your level");
    this->setWindowIcon(QIcon(":/resources/images/icon.png"));

    title = new QLabel("     Level:");
    title->setStyleSheet(" color: #ffffff; font-size: 30px;");
    mainLayout = new QVBoxLayout;
    easyLevelButton = new QPushButton("Easy");
    easyLevelButton->setStyleSheet(QPushButtonStyle);
    easyLevelButton->setFixedSize(175,50);
    mediumLevelButton = new QPushButton("Medium");
    mediumLevelButton->setStyleSheet(QPushButtonStyle);
    mediumLevelButton->setFixedSize(175,50);
    hardLevelButton = new QPushButton("Hard");
    hardLevelButton->setStyleSheet(QPushButtonStyle);
    hardLevelButton->setFixedSize(175,50);
    myLevelButton = new QPushButton("My level");
    myLevelButton->setStyleSheet(QPushButtonStyle);
    myLevelButton->setFixedSize(175,50);
    cancelButton = new QPushButton("Cancel");
    cancelButton->setStyleSheet(QPushButtonStyle);
    cancelButton->setFixedSize(175,50);

    mainLayout->addWidget(title);
    mainLayout->addSpacing(50);
    mainLayout->addWidget(easyLevelButton);
    mainLayout->addWidget(mediumLevelButton);
    mainLayout->addWidget(hardLevelButton);
    mainLayout->addWidget(myLevelButton);
    mainLayout->addSpacing(30);
    mainLayout->addWidget(cancelButton);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);

    connect(easyLevelButton, SIGNAL(clicked(bool)), this, SLOT(startEasyGame()));
    connect(mediumLevelButton, SIGNAL(clicked(bool)), this, SLOT(startMediumGame()));
    connect(hardLevelButton, SIGNAL(clicked(bool)), this, SLOT(startHardGame()));
    connect(myLevelButton, SIGNAL(clicked(bool)), this, SLOT(startMyLevelGame()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(back()));



}

ChoiceLevelWindow::~ChoiceLevelWindow()
{
    delete ui;
}

void ChoiceLevelWindow::startEasyGame()
{
    GameWindow *window = new GameWindow(9,9,10);
    window->show();
    this->close();
}
void ChoiceLevelWindow::startMediumGame()
{
    GameWindow *window = new GameWindow(16,16,40);
    window->show();
    this->close();
}
void ChoiceLevelWindow::startHardGame()
{
    GameWindow *window = new GameWindow(16,30,99);
    window->show();
    this->close();
}
void ChoiceLevelWindow::startMyLevelGame()
{

}
void ChoiceLevelWindow::back()
{
    MainWindow *window = new MainWindow;
    window->show();
    this->close();
}
