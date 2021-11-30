#include "button.h"

Button::Button(QString  s,QString  s_img, bool *show_fav, QMainWindow *mw)

{
    this->show_fav=show_fav;
    button=new QPushButton;

    button->setMinimumSize(400, 85);
     button->setMaximumSize(10000, 85);
     button->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
     button->setStyleSheet("QPushButton {  color: white; background-color: rgb(0,128,128); border-radius: 5px; font-family: Montserrat; font-weight: normal;font-size: 22px; line-height: 35px; text-align: left; padding-left:95px}"
                                   "QPushButton:hover {  color:  rgb(0,128,128);background-color:white; }");
      button->setText(s);
      QFile testPic(s_img);
      s_img.remove(s_img.size()-1,1 );

        icon=new QLabel(button);
        icon->setGeometry(30,25,40,40);
         icon->setStyleSheet("border-radius: 100px;background-image: url("+s_img+");background-position: center;");

         favourite=new QPushButton(button);
         QObject::connect(favourite, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
      favourite->setGeometry(button->width()-30, 25,40,40);
favourite->setMaximumSize(40,40);
if (favourite_enable==0){
      favourite->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(../Test_list/star_5.png);background-repeat:no-repeat;}"
                                "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(../Test_list/star_6.png)}");
}



           show_button=new QPushButton(button);
           QObject::connect(show_button, SIGNAL(clicked()), this, SLOT(on_pushButton_show_fav_clicked()));
           show_button->setGeometry(button->width()-30, 27,146,35);
           show_button->setMaximumSize(146,35);
        if(   favourite_enable==0){
           show_button->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0)}"
                                     "QPushButton:hover {background-color: rgba(0,0,0,0)}");
}

        else if(   favourite_enable==1 &&  *show_fav==0){

            show_button->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(../Test_list/show_favourite.png);background-repeat:no-repeat;}"
                                      "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(../Test_list/show_favourite_hover.png)}");
        }
        else if(   favourite_enable==1 &&  *show_fav==1){

            show_button->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(../Test_list/show_all.png);background-repeat:no-repeat;}"
                                      "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(../Test_list/show_all_hover.png)}");
      }

           QHBoxLayout* star_layout =new QHBoxLayout;
               star_layout->addStretch(80);
                star_layout->addWidget(show_button);
               star_layout->addStretch(1);
               star_layout->addWidget(favourite);
               star_layout->addStretch(2);
               button->setLayout(star_layout);


               QObject::connect(this, SIGNAL(change_star_signal()), mw, SLOT(repaint_buttons()));



}

void Button::on_pushButton_clicked()
{if (favourite_enable==0){
    favourite_enable=1;
    favourite->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(../Test_list/star_4.png);background-repeat:no-repeat;}"
                              "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(../Test_list/star_7.png)}");
}
    else {
          favourite_enable=0;
        favourite->setStyleSheet("QPushButton{ background-color: rgba(0,0,0,0);background-image: url(../Test_list/star_5.png);background-repeat:no-repeat;}"
                                  "QPushButton:hover {background-color: rgba(0,0,0,0); background-image: url(../Test_list/star_6.png)}");
  }

change_star_signal();
}

void Button::on_pushButton_show_fav_clicked()
{

(*show_fav)=!(*show_fav);

change_star_signal();

}
