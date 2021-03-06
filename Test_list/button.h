#ifndef BUTTON_H
#define BUTTON_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QScrollArea>
#include <QLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <QVector>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QFile>
#include "windows.h"

class Button:QObject
{
    Q_OBJECT
private slots:
   void on_pushButton_clicked();
    void on_pushButton_call_clicked();
  // void on_pushButton_call_clicked(QString  s);
  // void on_pushButton_show_fav_clicked();
signals:
   void change_star_signal();

public:
    Button(QString  s,QString  s_img, bool *show_fav, QMainWindow* main);
    QPushButton* button;
    QPushButton* gridButton;
    QLabel* icon;
    QPushButton* favourite;
    bool favourite_enable=0;
    QString getName();
  //   QPushButton* show_button;

private:
    bool *show_fav;
    QString name;
};

#endif // BUTTON_H
