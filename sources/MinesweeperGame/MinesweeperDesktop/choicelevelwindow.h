#ifndef CHOICELEVELWINDOW_H
#define CHOICELEVELWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLabel>

namespace Ui {
class ChoiceLevelWindow;
}

class ChoiceLevelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChoiceLevelWindow(QWidget *parent = 0);
    ~ChoiceLevelWindow();
    QVBoxLayout *mainLayout;
    QPushButton *easyLevelButton;
    QPushButton *mediumLevelButton;
    QPushButton *hardLevelButton;
    QPushButton *myLevelButton;
    QPushButton *cancelButton;
    QLabel *title;

private:
    Ui::ChoiceLevelWindow *ui;

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
private slots:
       void startEasyGame();
       void startMediumGame();
       void startHardGame();
       void startMyLevelGame();
       void back();
};

#endif // CHOICELEVELWINDOW_H
