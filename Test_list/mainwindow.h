#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "header.h"
#include <QMainWindow>
#include <QScrollArea>
#include <QLayout>
#include <QPushButton>
#include <QWidget>
#include <QSizePolicy>
#include <QVector>
#include "contactlistprovider.h"
#include <QScrollBar>
#include <QResizeEvent>

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
    void prepare_search_results();

protected:
   void resizeEvent(QResizeEvent *event);
    void prepare_items_for_print();


private:

    Ui::MainWindow *ui;
    QScrollArea* area;
    QVBoxLayout* layout;
    QVBoxLayout* layout2;
    QWidget* frame;
    header* head;
    QGridLayout* pgrdLayout;

    ContactListProvider* list_of_buttons;
    bool show_fav=0;
    bool is_grid=0;
    QString search_request="";
};
#endif // MAINWINDOW_H
