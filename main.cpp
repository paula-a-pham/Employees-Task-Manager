#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //make object of controller class;
    Controller obj;
    QApplication a(argc, argv);
    MainWindow w(&obj);
    //read from excel file and store data in unordered map;
    obj.read_user_info();
    w.show();
    a.exec();
    //save all thing in unordered map in excel file;
    obj.save_user_info();
    //save all thing in array in excel file named with username of user has loged in;
    obj.write_to_file("tasks");
    obj.write_to_file("draft_tasks");
    obj.write_to_file("done");
    return 0;
}
