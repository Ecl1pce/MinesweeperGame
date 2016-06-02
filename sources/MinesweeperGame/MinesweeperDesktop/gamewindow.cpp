#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"


GameWindow::GameWindow(int sizeX, int sizeY, int minesNumber) :
    QMainWindow(),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    QPixmap background(":/resources/images/options_background.jpg");
        QPalette qPalette;
        qPalette.setBrush(this->backgroundRole(),QBrush(background));
        this->setPalette(qPalette);

    sizeOfFieldX = sizeX;
    sizeOfFieldY = sizeY;
    minesInTheField = minesNumber;

    core = new Field(sizeOfFieldX, sizeOfFieldY, minesInTheField);
    fieldLayout = new QGridLayout;

    backButton = new QPushButton("Back to menu");
    backButton->setStyleSheet(QPushButtonStyle);
    backButton->setFixedSize(175,50);

    refreshButton = new QPushButton("Refresh game");
    refreshButton->setStyleSheet(QPushButtonStyle);
    refreshButton->setFixedSize(175,50);

    QObject::connect(backButton, SIGNAL(clicked(bool)), this, SLOT(backToMenu()));
    QObject::connect(refreshButton, SIGNAL(clicked(bool)), this, SLOT(refreshGame()));

    mainFieldLayout = new QVBoxLayout;
    panelLayout = new QVBoxLayout;
    mainLayout = new QHBoxLayout;

    vector<QMyPushButton*> tmpVect;
    for (int i = 0; i < core->getSizeX(); i++)
    {
        for (int j = 0; j < core->getSizeY(); j++)
        {
            QMyPushButton* newButton;
            tmpVect.push_back(newButton);
        }
        buttons.push_back(tmpVect);
    }

    QLabel *fieldHeight = new QLabel("Height of field:   ");
    fieldHeight->setStyleSheet(QLabelStyle);
    QLabel *fieldLength = new QLabel("Length of field:   ");
    fieldLength->setStyleSheet(QLabelStyle);
    QLabel *allCells = new QLabel("Cells in the field:");
    allCells->setStyleSheet(QLabelStyle);
    QLabel *cellsLeft = new QLabel("Cells left:           ");
    cellsLeft->setStyleSheet(QLabelStyle);
    QLabel *minesLeft = new QLabel("Mines left:         ");
    minesLeft->setStyleSheet(QLabelStyle);
    QLabel *flagsLeft = new QLabel("You have flags:  ");
    flagsLeft->setStyleSheet(QLabelStyle);


    fieldHeightNumber = new QLabel(QString::number(core->getSizeX()));
        fieldHeightNumber->setStyleSheet(QLabelStyle);
    fieldLengthNumber = new QLabel(QString::number(core->getSizeY()));
        fieldLengthNumber->setStyleSheet(QLabelStyle);
    allCellsNumber = new QLabel(QString::number(core->getSizeX() * core->getSizeY()));
        allCellsNumber->setStyleSheet(QLabelStyle);
    cellsLeftNumber = new QLabel(QString::number(core->cellsLeft));
        cellsLeftNumber->setStyleSheet(QLabelStyle);
    minesLeftNumber = new QLabel(QString::number(core->minesLeft));
        minesLeftNumber->setStyleSheet(QLabelStyle);
    flagsLeftNumber = new QLabel(QString::number(core->flagsLeft));
        flagsLeftNumber->setStyleSheet(QLabelStyle);

    QHBoxLayout *panelHorizontal1 = new QHBoxLayout;
    panelHorizontal1->addWidget(fieldHeight);
    panelHorizontal1->addWidget(fieldHeightNumber);
    QHBoxLayout *panelHorizontal2 = new QHBoxLayout;
    panelHorizontal2->addWidget(fieldLength);
    panelHorizontal2->addWidget(fieldLengthNumber);
    QHBoxLayout *panelHorizontal3 = new QHBoxLayout;
    panelHorizontal3->addWidget(allCells);
    panelHorizontal3->addWidget(allCellsNumber);
    QHBoxLayout *panelHorizontal4 = new QHBoxLayout;
    panelHorizontal4->addWidget(cellsLeft);
    panelHorizontal4->addWidget(cellsLeftNumber);
    QHBoxLayout *panelHorizontal5 = new QHBoxLayout;
    panelHorizontal5->addWidget(minesLeft);
    panelHorizontal5->addWidget(minesLeftNumber);
    QHBoxLayout *panelHorizontal6 = new QHBoxLayout;
    panelHorizontal6->addWidget(flagsLeft);
    panelHorizontal6->addWidget(flagsLeftNumber);

    //timer = new QTimer;
    //timer->start(10000);

    panelLayout = new QVBoxLayout;
    mainPanelLayout = new QVBoxLayout;
    panelBox = new QGroupBox;

    panelLayout->addSpacing(5);
    panelLayout->addLayout(panelHorizontal1);
    panelLayout->addLayout(panelHorizontal2);
    panelLayout->addLayout(panelHorizontal3);
    panelLayout->addLayout(panelHorizontal4);
    panelLayout->addLayout(panelHorizontal5);
    panelLayout->addLayout(panelHorizontal6);
    panelBox->setLayout(panelLayout);

    mainPanelLayout->addWidget(panelBox);
    //mainPanelLayout->addWidget(timer);
    mainPanelLayout->addStretch(1);
    mainPanelLayout->addWidget(refreshButton);
    mainPanelLayout->addWidget(backButton);
    mainPanelLayout->setSpacing(20);




    for (int i = 0; i < core->getSizeX(); i++)
        for (int j = 0; j < core->getSizeY(); j++)
        {
            buttons[i][j] = new QMyPushButton;
            fieldButtonSize = new QSize(32,32);
            buttons[i][j]->setStyleSheet(QFieldButtonStyle);
            buttons[i][j]->setFixedSize(*fieldButtonSize);
            //buttons[i][j]->setText("Do it!");
            fieldLayout->addWidget(buttons[i][j], i, j, 1, 1);
            buttons[i][j]->setProperty("coordinates", i * 1000 + j);
            connect(buttons[i][j], SIGNAL(pressed()), this, SLOT(clickedLeft()));
            connect(buttons[i][j], SIGNAL(rClicked()), this, SLOT(setFlag()));
            //QMyPushButton *but = new QMyPushButton;
            //connect(but, SIGNAL())

        }
    //mainFieldLayout->addSpacing(15);
    fieldLayout->setSpacing(0);
    mainFieldLayout->addLayout(fieldLayout);

    //mainLayout->addSpacing(15);
    mainLayout->addLayout(mainFieldLayout);
    mainLayout->addSpacing(25);
    mainLayout->addLayout(mainPanelLayout);
    //mainLayout->addSpacing(15);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
    this->setWindowTitle("Minesweeper TOP Game");
    this->setWindowIcon(QIcon(":/resources/images/icon.png"));

    connect(this, SIGNAL(allCellsOpen()), this, SLOT(winGame()));
    connect(this, SIGNAL(allah_BABAH()), this, SLOT(loseGame()));


}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::clickedLeft()
{
QMyPushButton *button = qobject_cast<QMyPushButton*>(sender());
QVariant index = button->property("coordinates");
int coordinates = index.toInt();
int x = coordinates / 1000;
int y = coordinates - x * 1000;
if (core->getPieceOfField(x,y).isFlag() == 0)
{
    core->open(x,y);
    repaint();
    if (core->getPieceOfField(x,y).isMine())
    {
        core->openAllCells();
        repaint();
        emit allah_BABAH();
    }
    if (core->minesLeft == 0)
        emit allCellsOpen();

}
}
void GameWindow::repaint()
{
    for (int i = 0; i < core->getSizeX(); i++)
        for (int j = 0; j < core->getSizeY(); j++)
        {
           //buttons[i][j]->setStyleSheet(QFieldButtonStyle);

           if (core->getPieceOfField(i,j).isOpen() && core->getPieceOfField(i,j).isMine() == 0)
           {
               buttons[i][j]->setStyleSheet(OpenButtonStyle);
               if (core->getPieceOfField(i,j).getValue())
                    buttons[i][j]->setText(QString::number(core->getPieceOfField(i,j).getValue()));

           }
           if (core->getPieceOfField(i,j).isOpen() && core->getPieceOfField(i,j).isMine())
           {
               buttons[i][j]->setStyleSheet(MinesButtonStyle);
               //buttons[i][j]->setIcon(QIcon(":/resources/images/mine.png"));
               //button->setText("Лох))00)");
           }
           if (core->getPieceOfField(i,j).isFlag())
           {
               buttons[i][j]->setStyleSheet(FlagButtonStyle);
           }
        }
    cellsLeftNumber->setText(QString::number(core->cellsLeft));
    flagsLeftNumber->setText(QString::number(core->flagsLeft));
    minesLeftNumber->setText(QString::number(core->minesLeft));
}

void GameWindow::backToMenu()
{
    MainWindow *mainWnd = new MainWindow;
    mainWnd->show();
    this->close();
}

void GameWindow::setFlag()
{
    QMyPushButton *button = qobject_cast<QMyPushButton*>(sender());
    QVariant index = button->property("coordinates");
    int coordinates = index.toInt();
    int x = coordinates / 1000;
    int y = coordinates - x * 1000;
    if (core->getPieceOfField(x,y).isOpen() == 0 || core->getPieceOfField(x,y).isFlag())
        core->setFlag(x,y);
    if (core->getPieceOfField(x,y).isFlag())
        button->setStyleSheet(FlagButtonStyle);
    if (core->getPieceOfField(x,y).isFlag() == 0)
        button->setStyleSheet(QFieldButtonStyle);
    repaint();

    if (core->minesLeft == 0)
        emit allCellsOpen();
}

void GameWindow::loseGame()
{
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon(":/resources/images/icon.png"));
    msgBox.setWindowTitle("Поражение!");
    msgBox.setText("Поздравляем!");
    msgBox.setInformativeText("Ты проиграл! Ухади!");

    msgBox.exec();
}

void GameWindow::winGame()
{
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon(":/resources/images/icon.png"));
    msgBox.setWindowTitle("Победа!");
    msgBox.setText("Поздравляем!");
    msgBox.setInformativeText("Ты победил! Ухади!");

    msgBox.exec();
}

void GameWindow::refreshGame()
{
    GameWindow *newWindow = new GameWindow(sizeOfFieldX, sizeOfFieldY, minesInTheField);
    newWindow->show();
    this->close();
}
