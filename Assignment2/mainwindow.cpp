#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_homeworkSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    updateValue();
}

void MainWindow::on_homeworkSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    updateValue();

}

void MainWindow::on_homeworkSlider_3_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
    updateValue();

}

void MainWindow::on_homeworkSlider_4_valueChanged(int value)
{
    ui->spinBox_4->setValue(value);
    updateValue();

}

void MainWindow::on_homeworkSlider_5_valueChanged(int value)
{
    ui->spinBox_5->setValue(value);
    updateValue();

}

void MainWindow::on_homeworkSlider_6_valueChanged(int value)
{
    ui->spinBox_6->setValue(value);
    updateValue();
}

void MainWindow::on_homeworkSlider_7_valueChanged(int value)
{
    ui->spinBox_7->setValue(value);
    updateValue();
}

void MainWindow::on_homeworkSlider_8_valueChanged(int value)
{
    ui->spinBox_8->setValue(value);
    updateValue();
}

void MainWindow::on_midtermSlider_valueChanged(int value)
{
    ui->spinBox_9->setValue(value);
    updateValue();

}

void MainWindow::on_midtermSlider_2_valueChanged(int value)
{
    ui->spinBox_10->setValue(value);
    updateValue();

}

void MainWindow::on_finalSlider_valueChanged(int value)
{
    ui->spinBox_11->setValue(value);
    updateValue();

}

void MainWindow::updateValue()
{
    int sumHomework = ui->spinBox->value() +  ui->spinBox_2->value() +  ui->spinBox_3->value() +  ui->spinBox_4->value() +
                      ui->spinBox_5->value() +  ui->spinBox_6->value() +  ui->spinBox_7->value() +  ui->spinBox_8->value();

    if(ui->radioButton->isChecked())
    {
        int sumMidterm =  ui->spinBox_9->value() +  ui->spinBox_10->value();

        int finalResult = (sumHomework * 0.125) * 0.25 + (sumMidterm * 0.5) * 0.4 + ui->spinBox_11->value()* 0.35;
        ui->finalLabel->setText(QString("<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">%1</span></p></body></html>").arg(finalResult));

    }else if(ui->radioButton_2->isChecked())
    {
        int midterm = ui->spinBox_9->value();
        if(midterm < ui->spinBox_10->value()) midterm = ui->spinBox_10->value();
        int finalResult = (sumHomework * 0.125) * 0.25 + (midterm * 1) * 0.3 + ui->spinBox_11->value()* 0.44;
        ui->finalLabel->setText(QString("<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">%1</span></p></body></html>").arg(finalResult));
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->homeworkSlider->setValue(arg1);
    updateValue();

}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    ui->homeworkSlider_2->setValue(arg1);
    updateValue();

}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    ui->homeworkSlider_3->setValue(arg1);
    updateValue();

}

void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
    ui->homeworkSlider_4->setValue(arg1);
    updateValue();
}

void MainWindow::on_spinBox_5_valueChanged(int arg1)
{
    ui->homeworkSlider_5->setValue(arg1);
    updateValue();
}

void MainWindow::on_spinBox_6_valueChanged(int arg1)
{
    ui->homeworkSlider_6->setValue(arg1);
    updateValue();
}

void MainWindow::on_spinBox_7_valueChanged(int arg1)
{
    ui->homeworkSlider_7->setValue(arg1);
    updateValue();
}

void MainWindow::on_spinBox_8_valueChanged(int arg1)
{
    ui->homeworkSlider_8->setValue(arg1);
    updateValue();
}

void MainWindow::on_spinBox_9_valueChanged(int arg1)
{
    ui->midtermSlider->setValue(arg1);
    updateValue();
}

void MainWindow::on_spinBox_10_valueChanged(int arg1)
{
    ui->midtermSlider_2->setValue(arg1);
    updateValue();

}

void MainWindow::on_spinBox_11_valueChanged(int arg1)
{
    ui->finalSlider->setValue(arg1);
    updateValue();

}

void MainWindow::on_radioButton_clicked()
{
    updateValue();
}

void MainWindow::on_radioButton_2_clicked()
{
    updateValue();
}
