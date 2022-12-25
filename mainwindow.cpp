#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    window = new secondwindow(this);
    // подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(window, &secondwindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::value()
{
    // передаваемый текст в другую форму
    return ui->lineEdit->text();
}


void MainWindow::on_pushButton_clicked()
{

 window->show();

 connect(this, &MainWindow::signal, window, &secondwindow::slot );
 value();
 hide();
 emit signal(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),
             ui->dateEdit->text(),ui->lineEdit_4->text(),
             ui->comboBox->currentText(),ui->comboBox_2->currentText(),
             ui->dateEdit_2->text(), ui->dateTimeEdit->text(),ui->comboBox_3->currentText());

}

