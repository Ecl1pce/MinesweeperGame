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
    //layout->setGeometry();

    backButton = new QPushButton("Выход");
    backButton->setStyleSheet(QPushButtonStyle);
    connect(backButton, SIGNAL(clicked(bool)), this, SLOT(backToMenu()));

    mainLayout = new QVBoxLayout;

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
    mainLayout->addLayout(fieldLayout);
    mainLayout->addWidget(backButton);
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
               //button->setText("Лох))00)");
           }
           if (core->getPieceOfField(i,j).isFlag())
           {
               buttons[i][j]->setStyleSheet(FlagButtonStyle);
           }
        }
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
