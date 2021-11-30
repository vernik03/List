#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QLayout>
#include <QPushButton>
#include <QWidget>
#include <QSizePolicy>
#include <QVector>
#include "contactlistprovider.h"
#include <QScrollBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void repaint_buttons();

protected:
   void resizeEvent(QResizeEvent *event);
    void prepare_items_for_print();

private:

    Ui::MainWindow *ui;
    QScrollArea* area;
    QVBoxLayout* layout;
    QVBoxLayout* layout2;
    QWidget* frame;

    ContactListProvider* list_of_buttons;
    bool show_fav=0;
};
#endif // MAINWINDOW_H
