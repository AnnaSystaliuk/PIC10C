#include "mainwindow.h"
#include "ui_mainwindow.h"

//function declarations

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(ui->horizontalSlider->value() == 0)
    {
        ui->spinBox->setValue(value);
    }
    else
    {
        ui->spinBox->setValue(value+1);
    }

    calculate();
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    if(ui->horizontalSlider_2->value() == 0)
    {
        ui->spinBox_2->setValue(value);
    }
    else
    {
        ui->spinBox_2->setValue(value+1);
    }
    calculate();

}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    if(ui->horizontalSlider_3->value() == 0)
    {
        ui->spinBox_3->setValue(value);
    }
    else
    {
        ui->spinBox_3->setValue(value+1);
    }
    calculate();

}

void MainWindow::on_horizontalSlider_4_valueChanged(int value)
{
    if(ui->horizontalSlider_4->value() == 0)
    {
        ui->spinBox_4->setValue(value);
    }
    else
    {
        ui->spinBox_4->setValue(value+1);
    }
    calculate();

}

void MainWindow::on_horizontalSlider_5_valueChanged(int value)
{
    if(ui->horizontalSlider_5->value() == 0)
    {
        ui->spinBox_5->setValue(value);
    }
    else
    {
        ui->spinBox_5->setValue(value+1);
    }
    calculate();

}

void MainWindow::on_horizontalSlider_6_valueChanged(int value)
{
    if(ui->horizontalSlider_6->value() == 0)
    {
        ui->spinBox_6->setValue(value);
    }
    else
    {
        ui->spinBox_6->setValue(value+1);
    }
    calculate();

}

void MainWindow::on_horizontalSlider_7_valueChanged(int value)
{
    if(ui->horizontalSlider_7->value() == 0)
    {
        ui->spinBox_7->setValue(value);
    }
    else
    {
        ui->spinBox_7->setValue(value+1);
    }
    calculate();

}

void MainWindow::on_horizontalSlider_8_valueChanged(int value)
{
    if(ui->horizontalSlider_8->value() == 0)
    {
        ui->spinBox_8->setValue(value);
    }
    else
    {
        ui->spinBox_8->setValue(value+1);
    }
    calculate();

}

void MainWindow::on_horizontalSlider_9_valueChanged(int value)
{
    if(ui->horizontalSlider_9->value() == 0)
    {
        ui->spinBox_9->setValue(value);
    }
    else
    {
        ui->spinBox_9->setValue(value+1);
    }
    calculate();

}

void MainWindow::on_horizontalSlider_10_valueChanged(int value)
{
    if(ui->horizontalSlider_10->value() == 0)
    {
        ui->spinBox_10->setValue(value);
    }
    else
    {
        ui->spinBox_10->setValue(value+1);
    }
    calculate();

}

void MainWindow::on_horizontalSlider_11_valueChanged(int value)
{
    if(ui->horizontalSlider_11->value() == 0)
    {
        ui->spinBox_11->setValue(value);
    }
    else
    {
        ui->spinBox_11->setValue(value+1);
    }
    calculate();
}

void MainWindow::on_radioButton_pressed()
{
calculate();
}


void MainWindow::calculate()
{
    int sumHw = ui->spinBox->value()+ui->spinBox_2->value()+ui->spinBox_3->value()
            +ui->spinBox_4->value()+ui->spinBox_5->value()+ui->spinBox_6->value()
            +ui->spinBox_7->value()+ui->spinBox_8->value();

    int sumMT = ui->spinBox_9->value() + ui->spinBox_11->value();
    int finalExam = ui->spinBox_10->value();

    if(ui->radioButton->isChecked())
    {
        int finalSum = (sumHw * 0.125) * 0.25 + (sumMT * 0.5) * 0.4 + finalExam * 0.35;
        ui->finalGrade->setText(QString("%1").arg(finalSum));
    } else if(ui->radioButton_2->isChecked())
    {

    }
}
