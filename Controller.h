#ifndef CONTROLLER_H
#define CONTROLLER_H
// include user.h to inherite all thing in it;
#include "Users.h"
#include <unordered_map>
//make a new data type for user information contain username, password and email;
struct log_info
{
    string user_name , password , mail;
};

class Controller
{
private:
    // make user and pass to select any user loged in;
    string user , pass;
public:
    //make object from class user to inherite all thing in it;
    Users* user_data = new Users;
    //make unordered map to store data for all users have signed up;
    unordered_map<string , log_info*> user_info;
    //save all thing in unordered map in excel file;
    void save_user_info();
    //read from excel file and store data in unordered map;
    void read_user_info();
    //read from file excel and store data in spesific array refer to fun parameter;
    void read_from_file(Task_data arr_list[], string txt);
    //save all thing in array in excel file named with username of user has loged in;
    void write_to_file(string txt);
    //get and set all atribute to use it in different classes;
    const string &getUser() const;
    void setUser(const string &newUser);
    const string &getPass() const;
    void setPass(const string &newPass);
};
#endif // CONTROLLER_H
