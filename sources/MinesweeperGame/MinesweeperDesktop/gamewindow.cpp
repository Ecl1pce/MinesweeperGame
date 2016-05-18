#include "gamewindow.h"
#include "mainwindow.h"


GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    QPixmap background(":/resources/images/options_background.jpg");
        QPalette qPalette;
        qPalette.setBrush(this->backgroundRole(),QBrush(background));
        this->setPalette(qPalette);

    core = new Field;
    fieldLayout = new QGridLayout;

    backButton = new QPushButton("Выход");
    backButton->setStyleSheet(QPushButtonStyle);
    backButton->setFixedSize(175,50);
    connect(backButton, SIGNAL(clicked(bool)), this, SLOT(backToMenu()));

    mainFieldLayout = new QVBoxLayout;
    panelLayout = new QVBoxLayout;
    mainLayout = new QHBoxLayout;

    vector<QPushButton*> tmpVect;
    for (int i = 0; i < core->getSizeX(); i++)
    {
        for (int j = 0; j < core->getSizeY(); j++)
        {
            QPushButton* newButton;
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
    QLabel *minesLeft = new QLabel("Mines left:          ");
    minesLeft->setStyleSheet(QLabelStyle);
    QLabel *flagsLeft = new QLabel("You have flags:   ");
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

    panelLayout = new QVBoxLayout;


    panelLayout->addLayout(panelHorizontal1);
    panelLayout->addLayout(panelHorizontal2);
    panelLayout->addLayout(panelHorizontal3);
    panelLayout->addLayout(panelHorizontal4);
    panelLayout->addLayout(panelHorizontal5);

    panelLayout->addLayout(panelHorizontal6);
    panelLayout->addStretch(1);
    panelLayout->addWidget(backButton);
    panelLayout->setSpacing(20);




    for (int i = 0; i < core->getSizeX(); i++)
        for (int j = 0; j < core->getSizeY(); j++)
        {
            buttons[i][j] = new QPushButton;
            fieldButtonSize = new QSize(32,32);
            buttons[i][j]->setStyleSheet(QFieldButtonStyle);
            buttons[i][j]->setFixedSize(*fieldButtonSize);
            //buttons[i][j]->setText("Do it!");
            fieldLayout->addWidget(buttons[i][j], i, j, 1, 1);
            buttons[i][j]->setProperty("coordinates", i * 1000 + j);
            connect(buttons[i][j], SIGNAL(clicked(bool)), this, SLOT(clickedLeft()));
            //connect(buttons[i][j], SIGNAL(pressed()), this, SLOT(longClick()));

        }
    mainFieldLayout->addLayout(fieldLayout);

    mainLayout->addLayout(mainFieldLayout);
    mainLayout->addSpacing(25);
    mainLayout->addLayout(panelLayout);

    this->setLayout(mainLayout);

//    QPixmap *button = new QPixmap(":/resources/images/green_button64.png");
//    QPixmap *button1 = new QPixmap(":/resources/images/field_button2.png");

//    QGraphicsScene *scene = new QGraphicsScene;
    //    scene->addPixmap(*button1);
    //    scene->addPixmap(*button);


    //    QGraphicsView *view = new QGraphicsView(scene);
    //    view->show();
    }

    void GameWindow::clickedLeft()
    {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QVariant index = button->property("coordinates");
    int coordinates = index.toInt();
    int x = coordinates / 1000;
    int y = coordinates - x * 1000;
    core->open(x,y);
    repaint();


}

GameWindow::~GameWindow()
{
    delete ui;
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

void GameWindow::longClick()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QVariant index = button->property("coordinates");
    int coordinates = index.toInt();
    int x = coordinates / 1000;
    int y = coordinates - x * 1000;
    core->setFlag(x,y);
    repaint();
}
