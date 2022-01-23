#ifndef HEADER_H
#define HEADER_H

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDebug>
#include <QString>
#include <QGraphicsDropShadowEffect>

class header: QObject
{
    Q_OBJECT
private slots:
   void on_pushButton_show_fav_clicked();
   //void on_pushButton_grid_clicked();
   void on_pushButton_search_clicked();

public:
    header(QMainWindow* main, bool *show_fav, bool *is_grid, QString *search_request);
    QPushButton* getFavourite();
    void apply_shadow();
    QWidget* body;
    QLineEdit* field;
    QPushButton* favourite;
    //QPushButton* grid;
    QPushButton* search;
    bool *show_fav;
    bool *is_grid;
    QWidget* getBody();
    QHBoxLayout* phbxLayout;
    QString *search_request;

};

#endif // HEADER_H
