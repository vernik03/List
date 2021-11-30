#ifndef CONTACTLISTPROVIDER_H
#define CONTACTLISTPROVIDER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVector>
#include "button.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QFile>
#include <QDebug>
#include <QDir>



class ContactListProvider
{
public:

    ContactListProvider(std::string filename,std::string filename_img,bool *show_fav, QMainWindow *main);
QVector<Button*> contact_list;
};

#endif // CONTACTLISTPROVIDER_H
