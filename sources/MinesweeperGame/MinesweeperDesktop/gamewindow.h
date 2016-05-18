#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "ui_gamewindow.h"
#include "field.h"
#include "qmypushbutton.h"
#include <QGridLayout>
#include <QPushButton>
#include <QDialog>
#include <vector>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QLabel>
#include <QIcon>
#include <QSize>
#include <QMouseEvent>

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void repaint();



private:
    vector<vector<QMyPushButton*> > buttons;
    Ui::GameWindow *ui;
    Field *core;
    QPushButton *backButton;
    QGridLayout *fieldLayout;
    QVBoxLayout *mainFieldLayout;
    QVBoxLayout *panelLayout;
    QHBoxLayout *mainLayout;
    int i,j;
    QSize *fieldButtonSize;
    QLabel *fieldHeightNumber;
    QLabel *fieldLengthNumber;
    QLabel *allCellsNumber;
    QLabel *cellsLeftNumber;
    QLabel *minesLeftNumber;
    QLabel *flagsLeftNumber;


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
};



#endif // GAMEWINDOW_H
