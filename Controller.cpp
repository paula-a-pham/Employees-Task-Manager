#include "Controller.h"
#include <fstream>
//read from file excel and store data in spesific array refer to fun parameter;
void Controller::read_from_file(Task_data arr_list[], string txt)
{
    string file_name = user + "_" + txt + ".csv";
    ifstream read_data_file(file_name);
    int temp_count = 0;
    while (!read_data_file.eof())
    {
        string a, b, c, d, e, f, g, h, i;
        date_details start, end;
        getline(read_data_file, a, ',');
        getline(read_data_file, b, ',');
        getline(read_data_file, c, ',');
        getline(read_data_file, d, ',');
        getline(read_data_file, e, ',');
        getline(read_data_file, f, ',');
        getline(read_data_file, g, ',');
        getline(read_data_file, h, ',');
        getline(read_data_file, i, '\n');
        arr_list[temp_count].setTask_name(a);
        arr_list[temp_count].setTask_description(b);
        start.day = atoi(c.c_str());
        start.month = atoi(d.c_str());
        start.year = atoi(e.c_str());
        end.day = atoi(f.c_str());
        end.month = atoi(g.c_str());
        end.year = atoi(h.c_str());
        arr_list[temp_count].setStart_date(start);
        arr_list[temp_count].setDeadline_date(end);
        arr_list[temp_count].setTask_priority(atoi(i.c_str()));
        arr_list[temp_count].setIndex(temp_count);
        if (txt == "tasks")
            user_data->setCount(temp_count);
        else if (txt == "draft_tasks")
            user_data->setCount_draft(temp_count);
        else
            user_data->setCount_done(temp_count);
        temp_count++;
    }
    read_data_file.close();
}
//save all thing in array in excel file named with username of user has loged in;
void Controller::write_to_file(string txt)
{
    ofstream data_file( user +"_" + txt + ".csv");
    int count_num;
    int temp_size;
    Task_data* arr_list;
    if (txt == "tasks")
    {
        count_num = user_data->getCount();
        temp_size = user_data->getSize();
        arr_list = new Task_data[temp_size];
        arr_list = user_data->getArr_list();
    }
    else if (txt == "draft_tasks")
    {
        count_num = user_data->getCount_draft();
        temp_size = user_data->getSize_draft();
        arr_list = new Task_data[temp_size];
        arr_list = user_data->getDraft_list();
    }
    else
    {
        count_num = user_data->getCount_done();
        temp_size = user_data->getSize_done();
        arr_list = new Task_data[temp_size];
        arr_list = user_data->getDone_list();
    }
    for (int i = 0; i < count_num; i++)
    {
        if (txt == "tasks")
        {
            data_file << arr_list[i].getTask_name() << "," << arr_list[i].getTask_description() << "," << arr_list[i].getStart_date().day << "," << arr_list[i].getStart_date().month << "," << arr_list[i].getStart_date().year << "," << arr_list[i].getDeadline_date().day << "," << arr_list[i].getDeadline_date().month << "," << arr_list[i].getDeadline_date().year << "," << arr_list[i].getTask_priority() << endl;
        }
        else if (txt == "draft_tasks")
        {
            data_file << arr_list[i].getTask_name() << "," << arr_list[i].getTask_description() << "," << arr_list[i].getStart_date().day << "," << arr_list[i].getStart_date().month << "," << arr_list[i].getStart_date().year << "," << arr_list[i].getDeadline_date().day << "," << arr_list[i].getDeadline_date().month << "," << arr_list[i].getDeadline_date().year << "," << arr_list[i].getTask_priority() << endl;
        }
        else
        {
            data_file << arr_list[i].getTask_name() << "," << arr_list[i].getTask_description() << "," << arr_list[i].getStart_date().day << "," << arr_list[i].getStart_date().month << "," << arr_list[i].getStart_date().year << "," << arr_list[i].getDeadline_date().day << "," << arr_list[i].getDeadline_date().month << "," << arr_list[i].getDeadline_date().year << "," << arr_list[i].getTask_priority() << endl;
        }
    }
    data_file.close();
}
const string &Controller::getUser() const
{
    return user;
}

void Controller::setUser(const string &newUser)
{
    user = newUser;
}

const string &Controller::getPass() const
{
    return pass;
}

void Controller::setPass(const string &newPass)
{
    pass = newPass;
}
//save all thing in unordered map in excel file;
void Controller::save_user_info()
{
    ofstream write_to_file("user_info.csv");
    unordered_map<string , log_info*>::iterator it;
    for(it = user_info.begin() ; it != user_info.end() ; it++)
    {
        write_to_file << it->second->user_name << ',' << it->second->password << ',' << it->second->mail << endl;
    }
    write_to_file.close();
}
//read from excel file and store data in unordered map;
void Controller::read_user_info()
{
    ifstream read_from_file("user_info.csv");
    for (int i = 0; !read_from_file.eof(); i++)
    {
        log_info* temp = new log_info;
        getline(read_from_file , temp->user_name , ',');
        getline(read_from_file , temp->password , ',');
        getline(read_from_file , temp->mail , '\n');
        user_info[temp->user_name] = temp;
    }
    read_from_file.close();
}
