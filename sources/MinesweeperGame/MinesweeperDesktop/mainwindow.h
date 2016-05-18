#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "optionswindow.h"
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

private slots:
    void goToOptions();
    void goToStartGame();

signals:

private:
    Ui::MainWindow *ui;
    OptionsWindow *optionsWnd;
    GameWindow *gameWnd;


    const QSize SCREEN_SIZE{850, 600};

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



};

#endif // MAINWINDOW_H
