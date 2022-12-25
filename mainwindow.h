#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString value();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    secondwindow *window; // 2 окно

signals:
    void signal(QString f, QString n, QString o,
                QString dr, QString nt, QString spec,
                QString doc, QString date_pr, QString time_pr,
                QString kategor);


};
#endif // MAINWINDOW_H
