#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QDialog>

namespace Ui {
class OptionsWindow;
}

class OptionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsWindow(QWidget *parent = 0);
    ~OptionsWindow();

signals:

public slots:
    void backToMenu();

private:
    Ui::OptionsWindow *ui;

};

#endif // OPTIONSWINDOW_H
