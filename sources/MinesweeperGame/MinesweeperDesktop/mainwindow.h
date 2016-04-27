#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "optionswindow.h"

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

    QString QPushButtonStyle =
                "QPushButton "
                "{"
                    " border: 1px solid #000000;"
                    " border-image: url(:/images/button.jpg);"
                    " padding: 7.5px 15px;"
                    " border-radius: 10px;"
                    " color: #000000;"
                    " font-size: 22px;"
                "}"
                "QPushButton:pressed "
                "{"
                    " border-color #00ffff;"
                "}"
                "QPushButton:flat "
                "{"
                    " border: none;"
                "}";



};

#endif // MAINWINDOW_H
