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
            head = new header(this, &show_fav, &is_grid, &search_request);
         layout2  =   new QVBoxLayout;

         list_of_buttons=new ContactListProvider("Test_list/names_list.txt","Test_list/avatars.txt", &show_fav, this);


         frame   =  new   QWidget;

         for(int i=0; i<list_of_buttons->contact_list.size(); i++){
            layout->addWidget(list_of_buttons->contact_list[i]->button);
            elem++;
         }

   frame->setLayout(layout);
    area->setWidget(frame);
     frame->setGeometry(0, 0, this->width()-33, elem*100);
      area->setGeometry(0, 0, this->width(), this->height());
      layout->setSpacing(5);
this->resize(this->size());
      layout2->addWidget(head->getBody());
      layout2->addStretch(1);
      layout2->setSpacing(0);
      head->getBody()->show();
      layout2->addWidget(area);
      QWidget* temp=new QWidget;
      this->setCentralWidget(temp);
      temp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


      this->centralWidget()->setLayout(layout2);

     area->show();
     this->setGeometry(0,0,800,600);
     this->resize(this->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event){
    this->centralWidget()->resize(this->width(), this->height());
  frame->setGeometry(0, head->getBody()->height(), this->width()-33, elem*100);
 area->setGeometry(0, head->getBody()->height(), this->width(), this->height());
 head->getBody()->setGeometry(0,0, this->width(), this->height()/20);

}

void MainWindow::repaint_buttons(){

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
        if (elem==0){
            for(int i=0; i<list_of_buttons->contact_list.size(); i++){

                       layout->addWidget(list_of_buttons->contact_list[i]->button);
                       elem++;
                       list_of_buttons->contact_list[i]->button->show();

            }
            head->getFavourite()->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(Test_list/header/fav.png);background-repeat:no-repeat;}"
                                              "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(Test_list/header/fav_hover.png)}");
         show_fav=false;
        }
     }
     else{
 for(int i=0; i<list_of_buttons->contact_list.size(); i++){

            layout->addWidget(list_of_buttons->contact_list[i]->button);
            elem++;
            list_of_buttons->contact_list[i]->button->show();

 }

    }
     frame->setLayout(layout);
     frame->setGeometry(0, head->getBody()->height(), this->width()-33, elem*100);
    area->setGeometry(0, head->getBody()->height(), this->width(), this->height());
    head->getBody()->setGeometry(0,0, this->width(), this->height()/20);
      layout->setSpacing(10);
      area->verticalScrollBar()->setValue(val);
      this->resize(this->size());



}

void MainWindow::prepare_search_results()
{
    int val=area->verticalScrollBar()->value();
 elem=0;
 for(int i=0; i<list_of_buttons->contact_list.size(); i++){

            list_of_buttons->contact_list[i]->button->hide();

 }

 while(layout->count()!=0){
    layout->removeItem(layout->itemAt(0));
 }
    for(int i=0; i<list_of_buttons->contact_list.size(); i++){

       if (list_of_buttons->contact_list[i]->getName().contains(search_request, Qt::CaseInsensitive)) {
           layout->addWidget(list_of_buttons->contact_list[i]->button);
           elem++;
           list_of_buttons->contact_list[i]->button->show();
           //qDebug()<<search_request;
       }
    }
    frame->setLayout(layout);
    frame->setGeometry(0, head->getBody()->height(), this->width()-33, elem*100);
   area->setGeometry(0, head->getBody()->height(), this->width(), this->height());
   head->getBody()->setGeometry(0,0, this->width(), this->height()/20);
     layout->setSpacing(10);
     area->verticalScrollBar()->setValue(val);
     this->resize(this->size());

}
