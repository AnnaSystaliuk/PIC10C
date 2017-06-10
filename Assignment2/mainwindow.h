#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//main file
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
    void on_homeworkSlider_valueChanged(int value);

    void on_homeworkSlider_2_valueChanged(int value);

    void on_homeworkSlider_3_valueChanged(int value);

    void on_homeworkSlider_4_valueChanged(int value);

    void on_homeworkSlider_5_valueChanged(int value);

    void on_homeworkSlider_6_valueChanged(int value);

    void on_homeworkSlider_7_valueChanged(int value);

    void on_homeworkSlider_8_valueChanged(int value);

    void on_midtermSlider_valueChanged(int value);

    void on_midtermSlider_2_valueChanged(int value);

    void on_finalSlider_valueChanged(int value);

    void updateValue();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_spinBox_5_valueChanged(int arg1);

    void on_spinBox_6_valueChanged(int arg1);

    void on_spinBox_7_valueChanged(int arg1);

    void on_spinBox_8_valueChanged(int arg1);

    void on_spinBox_9_valueChanged(int arg1);

    void on_spinBox_10_valueChanged(int arg1);

    void on_spinBox_11_valueChanged(int arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
