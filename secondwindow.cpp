#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "QPixmap"
#include "mainwindow.h"
#include <string>
#include <QTextStream> // Подключаем класс QTextStream
#include <QFile> // Подключаем класс QFile

secondwindow::secondwindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/1.jpg");
    int w = ui ->img->width();
    int h = ui ->img->height();

    ui->img->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_pushButton_2_clicked()
{
 this->close();
 emit firstWindow(); // И вызываем сигнал на открытие главного окна
}

void secondwindow::slot(QString f, QString n, QString o,
                        QString dr, QString nt, QString spec,
                        QString doc, QString date_pr, QString time_pr,
                        QString kategor)
{
  //  MainWindow mainwindow;
ui->textEdit->clear(); // Очистить Edit

ui->textEdit->append("||||||||||||||||||||||||||||||||||||||");

   QString ran;
   ran.setNum((rand()%9999+1111)*68436);
   QString talon = "Номер талона: " + ran + "\n";
   ui->textEdit->append(talon); // номер талона

   QString fio = "Пациент: " + f + " " + n + " " + o + ", " + dr + " г.р.";
   ui->textEdit->append(fio); // ФИО и дата рождения

   QString data = "Номер телефона: " + nt+ "\n";
    ui->textEdit->append(data); // Дата рождения

   QString zapis = "Запись на прием: " + date_pr + " в " + time_pr;
   ui->textEdit->append(zapis); // Дата и время приема

   QString doctor =kategor+ " " + spec + ": " + doc;
   ui->textEdit->append(doctor + "\n"); // Врач
   ui->textEdit->append("-------------------------------------------------\n \n");


}

// кнопка "Выход"
void secondwindow::on_pushButton_clicked()
{
  close();
}


void secondwindow::on_pushButton_3_clicked()
{
    QFile fileOut("data.txt"); // Связываем объект с файлом data.txt
            if(fileOut.open(QIODevice::Append | QIODevice::Text))
            { // Если файл успешно открыт для записи в текстовом режиме
                QTextStream writeStream(&fileOut);// Создаем объект класса QTextStream
                // и передаем ему адрес объекта fileOut
                writeStream.setCodec("UTF-8");
                QString e = ui->textEdit->toPlainText();
                fileOut.write(e.toUtf8());
                fileOut.close();
                }

}


void secondwindow::on_pushButton_4_clicked()
{
 ui->textEdit->clear();

 QFile fileIn("data.txt"); // Связываем объект с файлом data.txt

 if(fileIn.open(QIODevice::ReadOnly | QIODevice::Text))
  { // Если файл успешно открыт для чтения
    while (!fileIn.atEnd())
     {
        QTextStream stream(&fileIn);
        stream.setCodec("UTF-8");
        QString str = stream.readAll();
        ui->textEdit->setText(str);

     }
}
    fileIn.close(); // Закрываем файл
}

