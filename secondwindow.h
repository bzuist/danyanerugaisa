#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QFile> // Подключаем класс QFile

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();

signals:
    void MainWindow();  // Сигнал для первого окна на открытие
    void firstWindow();

private slots:
    void on_pushButton_2_clicked();
    // Слот-обработчик нажатия кнопки

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::secondwindow *ui;

public slots:
    void slot(QString f, QString n, QString o,
              QString dr, QString nt, QString spec,
              QString doc, QString date_pr, QString time_pr,
              QString kategor);
};

#endif // SECONDWINDOW_H
