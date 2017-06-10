#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_4_valueChanged(int value);

    void on_horizontalSlider_5_valueChanged(int value);

    void on_horizontalSlider_6_valueChanged(int value);

    void on_horizontalSlider_7_valueChanged(int value);

    void on_horizontalSlider_8_valueChanged(int value);

    void on_horizontalSlider_9_valueChanged(int value);

    void on_horizontalSlider_10_valueChanged(int value);

    void on_horizontalSlider_11_valueChanged(int value);

    void on_radioButton_pressed();

    void calculate();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
