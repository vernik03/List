#include "contactlistprovider.h"

ContactListProvider::ContactListProvider(std::string filename,std::string filename_img,bool *show_fav, QMainWindow* main)
{

   std::string name;
    std::ifstream in(filename);
    std::string img;
     std::ifstream in_img(filename_img);
        if (in.is_open()&&in_img.is_open())
        {
            while (getline(in, name))
            {
                getline(in_img, img);
                QString str=QString::fromUtf8(name.c_str());
                QString str_img=QString::fromUtf8(img.c_str());
                Button* button=new Button(str,str_img, show_fav, main);
                contact_list.push_back(button);
            }
        }
        in.close();
}
