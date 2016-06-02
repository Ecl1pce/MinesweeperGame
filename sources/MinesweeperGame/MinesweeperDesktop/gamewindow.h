#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "ui_gamewindow.h"
#include "field.h"
#include "qmypushbutton.h"
#include <QGridLayout>
#include <QPushButton>
#include <vector>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QLabel>
#include <QIcon>
#include <QSize>
#include <QMouseEvent>
#include <QIcon>
#include <QMessageBox>
#include <QGroupBox>
#include <QTimer>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(int sizeX, int sizeY, int minesNumber);
    ~GameWindow();
    void repaint();

signals:
    void allah_BABAH();
    void allCellsOpen();

private:
    vector<vector<QMyPushButton*> > buttons;
    Ui::GameWindow *ui;
    Field *core;
    QPushButton *backButton;
    QPushButton *refreshButton;
    QGridLayout *fieldLayout;
    QVBoxLayout *mainFieldLayout;
    QVBoxLayout *panelLayout;
    QHBoxLayout *mainLayout;
    int i,j;
    int sizeOfFieldX;
    int sizeOfFieldY;
    int minesInTheField;
    QSize *fieldButtonSize;
    QLabel *fieldHeightNumber;
    QLabel *fieldLengthNumber;
    QLabel *allCellsNumber;
    QLabel *cellsLeftNumber;
    QLabel *minesLeftNumber;
    QLabel *flagsLeftNumber;
    QGroupBox *panelBox;
    QVBoxLayout *mainPanelLayout;
    QTimer *timer;


    QString QPushButtonStyle =
                "QPushButton "
                "{"
                    " border: 1px solid #000000;"
                    " border-image: url(:/resources/images/button.jpg);"
                    " padding: 7.5px 15px;"
                    " border-radius: 10px;"
                    " color: #000000;"
                    " font-size: 22px;"
                "}"
                "QPushButton:flat "
                "{"
                    " border: none;"
                "}"
                "QPushButton:hover "
                "{"
                    " border-image: url(:/resources/images/button_hover);"
                "}"
                "QPushButton:pressed "
                "{"
                    " border-image: url(:/resources/images/button_background.jpg);"
                    " border-color #00ffff;"
                "}";

    QString QFieldButtonStyle =
            "QPushButton "
            "{"
                " border-image: url(:/resources/images/field_button2.png);"
            "}"
            "QPushButton:hover "
            "{"
                " border-image: url(:/resources/images/field_button2_pressed.png);"
            "}";

    QString MinesButtonStyle =
                "QPushButton "
                "{"
                    " border-image: url(:/resources/images/field_button5.png);"
                "}";
    QString FlagButtonStyle =
                "QPushButton "
                "{"
                     " border-image: url(:/resources/images/field_button1.png);"
                "}";
    QString OpenButtonStyle =
            "QPushButton "
            "{"
                " border-image: url(:/resources/images/field_button3.png);"
                " font-size: 20px;"
            "}";
    QString QLabelStyle =
            "QLabel "
            "{"
                " color: #ffffff;"
                " font-size: 20px;"
            "}";

private slots:
    void clickedLeft();
    void backToMenu();
    void setFlag();
    void winGame();
    void loseGame();
    void refreshGame();
};

#endif // GAMEWINDOW_H
