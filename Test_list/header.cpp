#include "header.h"

header::header(QMainWindow *mw, bool *show_fav, bool *is_grid, QString *search_request)
{
    this->show_fav=show_fav;
     this->is_grid=is_grid;
    this->search_request=search_request;
    body = new QWidget(mw);
    field = new QLineEdit();
    favourite = new QPushButton();
   /* grid = new QPushButton();
    grid->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(Test_list/header/make_grid.png);background-repeat:no-repeat;}"
                              "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(Test_list/header/make_grid_hover.png)}");
      grid->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
       grid->setMinimumSize(40, 40);

    QObject::connect(grid, SIGNAL(clicked()), this, SLOT(on_pushButton_grid_clicked()));*/

    search= new QPushButton();
    search->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(Test_list/header/search.png);background-repeat:no-repeat;}"
                              "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(Test_list/header/search_hover.png)}");
      search->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
       search->setMinimumSize(40, 40);
         QObject::connect(search, SIGNAL(clicked()), this, SLOT(on_pushButton_search_clicked()));
        QObject::connect(search, SIGNAL(clicked()), mw, SLOT(prepare_search_results()));


        /*  favourite->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(Test_list/header/fav.png);background-repeat:no-repeat;}"
                                    "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(Test_list/header/fav_hover.png)}");
          */
      favourite->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
         favourite->setMinimumSize(40, 40);
               QObject::connect(favourite, SIGNAL(clicked()), this, SLOT(on_pushButton_show_fav_clicked()));
                QObject::connect(favourite, SIGNAL(clicked()), mw, SLOT(repaint_buttons()));
      if(*show_fav==0){ favourite->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(Test_list/header/fav.png);background-repeat:no-repeat;}"
                                    "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(Test_list/header/fav_hover.png)}");
             }
        else if(*show_fav==1){  favourite->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(Test_list/header/not_fav.png);background-repeat:no-repeat;}"
                                    "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(Test_list/header/not_fav_hover.png)}");
          }


    body->setMinimumSize(400, 85);
     body->setMaximumSize(10000, 85);
     body->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
     body->setObjectName("name");
     body->setStyleSheet("QWidget#name {  color: magenta; background-color: rgb(0,128,128); border-radius: 5px; font-family: Montserrat; font-weight: normal;font-size: 22px; line-height: 35px; text-align: left; padding-left:95px}");
    phbxLayout=new QHBoxLayout;
  //  phbxLayout->addWidget(grid);
   // phbxLayout->addSpacing(15);
    //phbxLayout->addStretch(1);
    phbxLayout->addWidget(field, 3);
    phbxLayout->addSpacing(10);
    phbxLayout->addWidget(search);
    //phbxLayout->addStretch(1);
    phbxLayout->addSpacing(10);
    phbxLayout->addWidget(favourite);

    apply_shadow();

    field->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    field->setMinimumHeight(40);
    field->setMaximumHeight(40);
    phbxLayout->setStretch(1, 1);
    phbxLayout->setSpacing(0);
    body->setLayout(phbxLayout);


}

QWidget* header::getBody(){
    return body;
}


void header::apply_shadow()
{
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(90);
    shadow->setOffset(0, 3);
    shadow->setColor(QColor(0, 0, 0, 124));
    body->setGraphicsEffect(shadow);
}

void header::on_pushButton_show_fav_clicked()
{
    (*show_fav)=!(*show_fav);
    if(*show_fav==0){ favourite->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(Test_list/header/fav.png);background-repeat:no-repeat;}"
                                  "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(Test_list/header/fav_hover.png)}");
           }
      else if(*show_fav==1){  favourite->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(Test_list/header/not_fav.png);background-repeat:no-repeat;}"
                                  "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(Test_list/header/not_fav_hover.png)}");
        }
}

/*void header::on_pushButton_grid_clicked()
{
    (*is_grid)=!(*is_grid);
    if(*is_grid==0){   grid->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(Test_list/header/make_grid.png);background-repeat:no-repeat;}"
                                            "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(Test_list/header/make_grid_hover.png)}");
                       }
      else if(*is_grid==1){  grid->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(Test_list/header/make_list.png);background-repeat:no-repeat;}"
                                                 "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(Test_list/header/make_list_hover.png)}");
           }
}*/

QPushButton* header::getFavourite(){
    return favourite;
}

void header::on_pushButton_search_clicked()
{
   qDebug()<<"Searching...";
    *search_request=field->text();
}

