#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Controller.h"
#include <QMessageBox>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //display all thing in array after login;
    void add_task_to_screen(Task_data arr_list[] , string txt);
    //display task on screen when use add or edit task;
    void widget_templete(int index);
    //display all thing in complete array after login;
    void done_view();
    //remove all thing in gui for loged out user;
    void destroy_widget();
    MainWindow(Controller* controller , QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sign_btn_clicked();

    void on_exit_login_clicked();

    void on_cancel_sign_btn_clicked();

    void on_confirm_sign_btn_clicked();

    void on_home_btn_clicked();

    void on_logo_btn_clicked();

    void on_calendar_btn_clicked();

    void on_about_btn_clicked();

    void on_logout_btn_clicked();

    void on_exit_btn_clicked();

    void on_reset_btn_clicked();

    void on_add_btn_clicked();

    void on_login_btn_clicked();

    void on_periority_num_currentIndexChanged(int index);


    void on_save_edit_btn_clicked();
private:
    Controller* obj_controller;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
