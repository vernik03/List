#include "mainwindow.h"
#include "ui_mainwindow.h"


int elem=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setMinimumSize(500, 300);
    setWindowTitle("Contact List Viewer");
             area   = new QScrollArea(this);
           layout  =  new QVBoxLayout;
         layout2  =   new QVBoxLayout;
         list_of_buttons=new ContactListProvider("../Test_list/names_list.txt","../Test_list/avatars.txt", &show_fav, this);
       /*  QVector<QPushButton*> list;

      for(int i=0; i<10; i++){
             QPushButton* button_X=new QPushButton;

             button_X->setMinimumSize(300, 60);
              button_X->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
              button_X->setStyleSheet("QPushButton {  color: white; background-color: rgb(0,128,128); border-radius: 5px; font-family: Montserrat; font-weight: normal;font-size: 22px; line-height: 35px; display: flex; align-items: left; text-align: left; padding-left:70px}"
                                            "QPushButton:hover {  color:  rgb(0,128,128);background-color:white; }");
                 button_X->setText("Lorem Ipsum");
                 QPixmap folderbutt("D:/Мои фото и видео/20190818_103157-02.jpeg");
                 QWidget icon;
                   button_X->setIcon(folderbutt);

             list.push_back(button_X);
             elem++;
         }*/

         frame   =  new   QWidget;

         for(int i=0; i<list_of_buttons->contact_list.size(); i++){
            layout->addWidget(list_of_buttons->contact_list[i]->button);
            elem++;
              //  list_of_buttons->contact_list[i]->button->show();
         }

   frame->setLayout(layout);
    area->setWidget(frame);
     frame->setGeometry(0, 0, this->width()-33, elem*100);
      area->setGeometry(0, 0, this->width(), this->height());
      layout->setSpacing(5);

      layout2->addWidget(area);
      this->setLayout(layout2);
     area->show();
     this->setGeometry(0,0,800,600);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event){
  frame->setGeometry(0, 0, this->width()-33, elem*100);
 area->setGeometry(0, 0, this->width(), this->height());
   layout->setSpacing(10);
  // for(int i=0; i<list_of_buttons->contact_list.size(); i++){
  //    list_of_buttons->contact_list[i]->favourite->setGeometry(this->width()-50, 25,40,40);
 //  }
}

void MainWindow::repaint_buttons(){

    for(int i=0; i<list_of_buttons->contact_list.size(); i++){

    if(   list_of_buttons->contact_list[i]->favourite_enable==0){
       list_of_buttons->contact_list[i]->show_button->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0)}"
                                 "QPushButton:hover {background-color: rgba(0,0,0,0)}");
    }
    else if(   list_of_buttons->contact_list[i]->favourite_enable==1 && show_fav==0){

       list_of_buttons->contact_list[i]->show_button->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(../Test_list/show_favourite.png);background-repeat:no-repeat;}"
                                  "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(../Test_list/show_favourite_hover.png)}");
    }
    else if(  list_of_buttons->contact_list[i]->favourite_enable==1 &&  show_fav==1){

        list_of_buttons->contact_list[i]->show_button->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(../Test_list/show_all.png);background-repeat:no-repeat;}"
                                 "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(../Test_list/show_all_hover.png)}");

    }
}
    prepare_items_for_print();
}

void MainWindow::prepare_items_for_print()
{
    int val=area->verticalScrollBar()->value();
 elem=0;
 for(int i=0; i<list_of_buttons->contact_list.size(); i++){

            list_of_buttons->contact_list[i]->button->hide();

 }

 while(layout->count()!=0){
    layout->removeItem(layout->itemAt(0));
 }
    if(show_fav){
        for(int i=0; i<list_of_buttons->contact_list.size(); i++){
            if (list_of_buttons->contact_list[i]->favourite_enable==1){
                layout->addWidget(list_of_buttons->contact_list[i]->button);
                elem++;
                list_of_buttons->contact_list[i]->button->show();

                }
            }
     }
     else{
 for(int i=0; i<list_of_buttons->contact_list.size(); i++){

            layout->addWidget(list_of_buttons->contact_list[i]->button);
            elem++;
            list_of_buttons->contact_list[i]->button->show();

 }

    }
qDebug()<<elem;
     frame->setLayout(layout);
     frame->setGeometry(0, 0, this->width()-33, elem*100);
    area->setGeometry(0, 0, this->width(), this->height());
      layout->setSpacing(10);
      area->verticalScrollBar()->setValue(val);

}
