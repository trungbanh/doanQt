#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
void MainWindow::on_pushButton_clicked()
{
    ui->widget->text = ui->lineEdit->text();
    ui->widget->mode = 1 ;
    ui->widget->x=0;
}
void MainWindow::on_pushButton_2_clicked()
{
    ui->widget->mode = 2;
    ui->widget->x=0;
}
