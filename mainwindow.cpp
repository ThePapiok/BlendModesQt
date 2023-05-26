#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_suwak_valueChanged(int value)
{

    values=value;
}


void MainWindow::on_button1_clicked()
{
    ui->widget->setWarstwa(1);
}


void MainWindow::on_button2_clicked()
{
    ui->widget->setWarstwa(2);
}


void MainWindow::on_button3_clicked()
{
    ui->widget->lista[ui->widget->getWarstwa()].mix=ui->widget->normalMix;
    ui->widget->load();

}


void MainWindow::on_button4_clicked()
{
    ui->widget->lista[ui->widget->getWarstwa()].mix=ui->widget->multiplyMix;
    ui->widget->load();

}

void MainWindow::on_button5_clicked()
{
    ui->widget->lista[ui->widget->getWarstwa()].mix=ui->widget->subbtractiveMix;
    ui->widget->load();

}


void MainWindow::on_button6_clicked()
{
    ui->widget->lista[ui->widget->getWarstwa()].mix=ui->widget->additiveMix;
    ui->widget->load();

}

void MainWindow::on_button7_clicked()
{
    ui->widget->lista[ui->widget->getWarstwa()].mix=ui->widget->differenceMix;
    ui->widget->load();
}


void MainWindow::on_suwak_sliderReleased()
{
    ui->widget->lista[ui->widget->getWarstwa()].alfa=values/100.0;
    ui->widget->load();
}

