#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QProcess>
MainWindow::MainWindow(Controller* controller , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    obj_controller = controller;
}

MainWindow::~MainWindow()
{
    delete ui;
}
//display all thing in complete array after login;
void MainWindow::done_view()
{
    int temp_size = obj_controller->user_data->getSize_done();
    Task_data* done_list = obj_controller->user_data->getDone_list();
    for(int i = 0 ; i<obj_controller->user_data->getCount_done() ; i++)
    {
        string task_name = "Task Name : " + done_list[i].getTask_name();
        string task_description = "\nTask Description : " + done_list[i].getTask_description();
        string task_periority = "\nTask Periority : " + to_string(done_list[i].getTask_priority());
        string task_start_date = "\nStart Dat : " + to_string(done_list[i].getStart_date().day) + " - " + to_string(done_list[i].getStart_date().month) + " - " + to_string(done_list[i].getStart_date().year);
        string task_deadline_date = "\nDeadline Dat : " + to_string(done_list[i].getDeadline_date().day) + " - " + to_string(done_list[i].getDeadline_date().month) + " - " + to_string(done_list[i].getDeadline_date().year);
        string task_data = task_name + task_description + task_periority + task_start_date + task_deadline_date;
        QLabel *data = new QLabel;
        data->setText(task_data.c_str());
        data->setMinimumWidth(50);
        data->setMinimumHeight(200);
        data->setMaximumHeight(200);
        data->setStyleSheet("QLabel{font-size:25px;border: 2px solid ;border-radius: 20px;border-color: #77a0d9;background-color:#111b21;padding-top:10px;padding-bottom:10px;padding-left:25px;}");
        ui->done_show->addWidget(data);
    }
}
//remove all thing in gui for loged out user;
void MainWindow::destroy_widget()
{
    if ( ui->done_show->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->done_show->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }

    if ( ui->draft_show->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->draft_show->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }

    if ( ui->show_periority_1->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->show_periority_1->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    if ( ui->show_periority_2->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->show_periority_2->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    if ( ui->show_periority_3->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->show_periority_3->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    if ( ui->show_periority_4->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->show_periority_4->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    if ( ui->show_periority_5->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->show_periority_5->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    if ( ui->show_periority_6->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->show_periority_6->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    if ( ui->show_periority_7->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->show_periority_7->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    if ( ui->show_periority_8->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->show_periority_8->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    if ( ui->show_periority_9->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->show_periority_9->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    if ( ui->show_periority_10->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->show_periority_10->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
}
//display task on screen when use add or edit task;
void MainWindow::widget_templete(int index)
{
    string task_name = ui->task_name_en->text().toStdString();
    string task_description = ui->task_description_2->text().toStdString();
    int periority = ui->task_periority_en->value();
    int day_start = ui->day_start->value();
    int month_start = ui->month_start->value();
    int year_start = ui->year_start->value();
    int day_end = ui->day_end->value();
    int month_end = ui->month_end->value();
    int year_end = ui->yaer_end->value();

    string task_name2 = "Task Name : " + task_name;
    string task_description2 = "\nTask Description : " + task_description;
    string task_periority = "\nTask Periority : " + to_string(periority);
    string task_start_date = "\nStart Dat : " + to_string(day_start) + " - " + to_string(month_start) + " - " + to_string(year_start);
    string task_deadline_date = "\nDeadline Dat : " + to_string(day_end) + " - " + to_string(month_end) + " - " + to_string(year_end);
    string task_data = task_name2 + task_description2 + task_periority + task_start_date + task_deadline_date;
    QLabel *data = new QLabel;
    data->setText(task_data.c_str());
    data->setMinimumWidth(50);
    data->setMinimumHeight(200);
    data->setMaximumHeight(200);
    data->setStyleSheet("QLabel{font-size:25px;border: 2px solid ;border-radius: 20px;border-color: #77a0d9;background-color:#111b21;padding-top:10px;padding-bottom:10px;padding-left:25px;}");

    QPushButton* finish_btn = new QPushButton("Finish");
    finish_btn->setMinimumWidth(50);
    finish_btn->setMinimumHeight(80);
    finish_btn->setStyleSheet("QPushButton{font-size:25px;color : white;border: 2px solid ;border-radius: 20px;border-color: #77a0d9;background-color:#111b21;fixed-width: 80px;margin-left: 20px;margin-right:20px;margin-bottom:10px;margin-top : 10px;padding-top:5px;padding-bottom:5px;}QPushButton:hover{background-color: #5682bf;}");
    QPushButton* edit_btn = new QPushButton("Edit");
    edit_btn->setMinimumWidth(50);
    edit_btn->setMinimumHeight(80);
    edit_btn->setStyleSheet("QPushButton{font-size:25px;color : white;border: 2px solid ;border-radius: 20px;border-color: #77a0d9;background-color:#111b21;fixed-width: 80px;margin-left: 20px;margin-right:20px;margin-bottom:10px;margin-top : 10px;padding-top:5px;padding-bottom:5px;}QPushButton:hover{background-color: #5682bf;}");
    QPushButton* delete_btn = new QPushButton("Delete");
    delete_btn->setMinimumWidth(50);
    delete_btn->setMinimumHeight(80);
    delete_btn->setStyleSheet("QPushButton{font-size:25px;color : white;border: 2px solid ;border-radius: 20px;border-color: #77a0d9;background-color:#111b21;fixed-width: 80px;margin-left: 20px;margin-right:20px;margin-bottom:10px;margin-top : 10px;padding-top:5px;padding-bottom:5px;}QPushButton:hover{background-color: #5682bf;}");

    QFrame* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    ui->display_show->addWidget(line);
    QWidget *horizontalLineWidget = new QWidget;
    horizontalLineWidget->setFixedHeight(2);
    horizontalLineWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    horizontalLineWidget->setStyleSheet(QString("background-color: #95b7e5;"));

    QVBoxLayout* label_layout = new QVBoxLayout;
    QHBoxLayout* button_layout = new QHBoxLayout;
    QVBoxLayout* total_layout = new QVBoxLayout;
    label_layout->addWidget(data);
    button_layout->addWidget(finish_btn);
    button_layout->addWidget(edit_btn);
    button_layout->addWidget(delete_btn);
    total_layout->addLayout(label_layout);
    total_layout->addLayout(button_layout);
    total_layout->addWidget(line);
    QWidget* window = new QWidget();
    window->setLayout(total_layout);
    switch(ui->task_periority_en->value())
    {
    case 1:
    {
        ui->show_periority_1->addWidget(window);
        ui->show_periority_1->addWidget(line);
        break;
    }
    case 2:
    {
        ui->show_periority_2->addWidget(window);
        ui->show_periority_2->addWidget(line);
        break;
    }
    case 3:
    {
        ui->show_periority_3->addWidget(window);
        ui->show_periority_3->addWidget(line);
        break;
    }
    case 4:
    {
        ui->show_periority_4->addWidget(window);
        ui->show_periority_4->addWidget(line);
        break;
    }
    case 5:
    {
        ui->show_periority_5->addWidget(window);
        ui->show_periority_5->addWidget(line);
        break;
    }
    case 6:
    {
        ui->show_periority_6->addWidget(window);
        ui->show_periority_6->addWidget(line);
        break;
    }
    case 7:
    {
        ui->show_periority_7->addWidget(window);
        ui->show_periority_7->addWidget(line);
        break;
    }
    case 8:
    {
        ui->show_periority_8->addWidget(window);
        ui->show_periority_8->addWidget(line);
        break;
    }
    case 9:
    {
        ui->show_periority_9->addWidget(window);
        ui->show_periority_9->addWidget(line);
        break;
    }
    case 10:
    {
        ui->show_periority_10->addWidget(window);
        ui->show_periority_10->addWidget(line);
        break;
    }
    }
    QObject::connect(finish_btn, &QPushButton::clicked, [=]()
    {
        obj_controller->user_data->finish_task("array" , index);
        ui->done_show->addWidget(data);
        delete window;
        QMessageBox messageBox;
        string message;
        if(obj_controller->user_data->arr_empty(obj_controller->user_data->getCount()))
        {
            message = "Great you have finished all tasks !";
        }
        else
        {
            message = "Great task finished successfully\nWork hardly to finish next one";
        }
        messageBox.information(0,"Done",message.c_str());
    });
    QObject::connect(edit_btn, &QPushButton::clicked, [=]()
    {
        ui->task_name_en_edit->setText(task_name.c_str());
        ui->task_description_edit->setText(task_description.c_str());
        ui->task_periority_en_edit->setValue(periority);
        ui->day_start_edit->setValue(day_start);
        ui->month_start_edit->setValue(month_start);
        ui->year_start_edit->setValue(year_start);
        ui->day_end_edit->setValue(day_end);
        ui->month_end_edit->setValue(month_end);
        ui->yaer_end_edit->setValue(year_end);
        delete window;
        obj_controller->user_data->arr_delete_at(index , "array");
        ui->all_pages->setCurrentIndex(4);
    });

    QObject::connect(delete_btn, &QPushButton::clicked, [=]()
    {
        obj_controller->user_data->arr_delete_at(index , "array");
        delete window;
    });
}
//display all thing in array after login;
void MainWindow::add_task_to_screen(Task_data arr_list[] , string txt)
{
    int temp =0;
    if(txt == "tasks")
    {
        temp = obj_controller->user_data->getCount();
    }
    else
    {
        temp = obj_controller->user_data->getCount_draft();
    }
    for(int i = 0 ; i<temp ; i++)
    {
        string task_name = arr_list[i].getTask_name();
        string task_description = arr_list[i].getTask_description();
        int periority = arr_list[i].getTask_priority();
        int day_start = arr_list[i].getStart_date().day;
        int month_start = arr_list[i].getStart_date().month;
        int year_start = arr_list[i].getStart_date().year;
        int day_end = arr_list[i].getDeadline_date().day;
        int month_end = arr_list[i].getDeadline_date().month;
        int year_end = arr_list[i].getDeadline_date().year;

        string task_name2 = "Task Name : " + task_name;
        string task_description2 = "\nTask Description : " + task_description;
        string task_periority = "\nTask Periority : " + to_string(periority);
        string task_start_date = "\nStart Dat : " + to_string(day_start) + " - " + to_string(month_start) + " - " + to_string(year_start);
        string task_deadline_date = "\nDeadline Dat : " + to_string(day_end) + " - " + to_string(month_end) + " - " + to_string(year_end);
        string task_data = task_name2 + task_description2 + task_periority + task_start_date + task_deadline_date;

        QLabel *data = new QLabel;
        data->setText(task_data.c_str());
        data->setMinimumWidth(50);
        data->setMinimumHeight(200);
        data->setMaximumHeight(200);
        data->setStyleSheet("QLabel{font-size:25px;border: 2px solid ;border-radius: 20px;border-color: #77a0d9;background-color:#111b21;padding-top:10px;padding-bottom:10px;padding-left:25px;}");

        QPushButton* finish_btn = new QPushButton("Finish");
        finish_btn->setMinimumWidth(50);
        finish_btn->setMinimumHeight(80);
        finish_btn->setStyleSheet("QPushButton{font-size:25px;color : white;border: 2px solid ;border-radius: 20px;border-color: #77a0d9;background-color:#111b21;fixed-width: 80px;margin-left: 20px;margin-right:20px;margin-bottom:10px;margin-top : 10px;padding-top:5px;padding-bottom:5px;}QPushButton:hover{background-color: #5682bf;}");
        QPushButton* edit_btn = new QPushButton("Edit");
        edit_btn->setMinimumWidth(50);
        edit_btn->setMinimumHeight(80);
        edit_btn->setStyleSheet("QPushButton{font-size:25px;color : white;border: 2px solid ;border-radius: 20px;border-color: #77a0d9;background-color:#111b21;fixed-width: 80px;margin-left: 20px;margin-right:20px;margin-bottom:10px;margin-top : 10px;padding-top:5px;padding-bottom:5px;}QPushButton:hover{background-color: #5682bf;}");
        QPushButton* delete_btn = new QPushButton("Delete");
        delete_btn->setMinimumWidth(50);
        delete_btn->setMinimumHeight(80);
        delete_btn->setStyleSheet("QPushButton{font-size:25px;color : white;border: 2px solid ;border-radius: 20px;border-color: #77a0d9;background-color:#111b21;fixed-width: 80px;margin-left: 20px;margin-right:20px;margin-bottom:10px;margin-top : 10px;padding-top:5px;padding-bottom:5px;}QPushButton:hover{background-color: #5682bf;}");

        QFrame* line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        ui->display_show->addWidget(line);
        QWidget *horizontalLineWidget = new QWidget;
        horizontalLineWidget->setFixedHeight(2);
        horizontalLineWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        horizontalLineWidget->setStyleSheet(QString("background-color: #95b7e5;"));

        QVBoxLayout* label_layout = new QVBoxLayout;
        QHBoxLayout* button_layout = new QHBoxLayout;
        QVBoxLayout* total_layout = new QVBoxLayout;
        label_layout->addWidget(data);
        button_layout->addWidget(finish_btn);
        button_layout->addWidget(edit_btn);
        button_layout->addWidget(delete_btn);
        total_layout->addLayout(label_layout);
        total_layout->addLayout(button_layout);
        total_layout->addWidget(line);
        QWidget* window = new QWidget();
        window->setLayout(total_layout);
        if(txt == "tasks")
        {
            switch(periority)
            {
            case 1:
            {
                ui->show_periority_1->addWidget(window);
                ui->show_periority_1->addWidget(line);
                break;
            }
            case 2:
            {
                ui->show_periority_2->addWidget(window);
                ui->show_periority_2->addWidget(line);
                break;
            }
            case 3:
            {
                ui->show_periority_3->addWidget(window);
                ui->show_periority_3->addWidget(line);
                break;
            }
            case 4:
            {
                ui->show_periority_4->addWidget(window);
                ui->show_periority_4->addWidget(line);
                break;
            }
            case 5:
            {
                ui->show_periority_5->addWidget(window);
                ui->show_periority_5->addWidget(line);
                break;
            }
            case 6:
            {
                ui->show_periority_6->addWidget(window);
                ui->show_periority_6->addWidget(line);
                break;
            }
            case 7:
            {
                ui->show_periority_7->addWidget(window);
                ui->show_periority_7->addWidget(line);
                break;
            }
            case 8:
            {
                ui->show_periority_8->addWidget(window);
                ui->show_periority_8->addWidget(line);
                break;
            }
            case 9:
            {
                ui->show_periority_9->addWidget(window);
                ui->show_periority_9->addWidget(line);
                break;
            }
            case 10:
            {
                ui->show_periority_10->addWidget(window);
                ui->show_periority_10->addWidget(line);
                break;
            }
            }
        }
        else
        {
            ui->draft_show->addWidget(window);
        }
        QObject::connect(finish_btn, &QPushButton::clicked, [=]()
        {
            if(txt == "tasks")
            {
                obj_controller->user_data->finish_task("array" , i);
            }
            else
            {
                obj_controller->user_data->finish_task("draft" , i);
            }

            ui->done_show->addWidget(data);
            delete window;
            QMessageBox messageBox;
            string message;
            if(obj_controller->user_data->arr_empty(obj_controller->user_data->getCount()))
            {
                message = "Great you have finished all tasks !";
            }
            else
            {
                int temp_size = obj_controller->user_data->getSize();
                Task_data* temp = new Task_data[temp_size];
                temp = obj_controller->user_data->getArr_list();
                message = "Great task finished successfully\nNext task is : " + temp[0].getTask_name();
            }
            messageBox.information(0,"Done",message.c_str());
        });
        QObject::connect(edit_btn, &QPushButton::clicked, [=]()
        {
            ui->task_name_en_edit->setText(task_name.c_str());
            ui->task_description_edit->setText(task_description.c_str());
            ui->task_periority_en_edit->setValue(periority);
            ui->day_start_edit->setValue(day_start);
            ui->month_start_edit->setValue(month_start);
            ui->year_start_edit->setValue(year_start);
            ui->day_end_edit->setValue(day_end);
            ui->month_end_edit->setValue(month_end);
            ui->yaer_end_edit->setValue(year_end);

            delete window;
            if(txt == "tasks")
            {
                obj_controller->user_data->arr_delete_at(i , "array");
            }
            else
            {
                obj_controller->user_data->arr_delete_at(i , "draft");
            }

            ui->all_pages->setCurrentIndex(4);
        });
        QObject::connect(delete_btn, &QPushButton::clicked, [=]()
        {
            if(txt == "tasks")
            {
                obj_controller->user_data->arr_delete_at(i , "array");
            }
            else
            {
                obj_controller->user_data->arr_delete_at(i , "draft");
            }
            delete window;
        });
    }
}

void MainWindow::on_sign_btn_clicked()
{
    ui->log_sign->setCurrentIndex(1);
}

void MainWindow::on_exit_login_clicked()
{
    obj_controller->save_user_info();
    obj_controller->write_to_file("tasks");
    obj_controller->write_to_file("draft_tasks");
    obj_controller->write_to_file("done");
    exit(EXIT_FAILURE);
}

void MainWindow::on_cancel_sign_btn_clicked()
{
    ui->log_sign->setCurrentIndex(0);
}
//collect data in sign in;
void MainWindow::on_confirm_sign_btn_clicked()
{
    if(ui->user_sign->text() != NULL && ui->email_sign->text() != NULL && ui->pass1_sign->text() != NULL && ui->pass2_sign->text() != NULL)
    {
        if(obj_controller->user_info.find(ui->user_sign->text().toStdString()) == obj_controller->user_info.end())
        {
            if(ui->pass1_sign->text() == ui->pass2_sign->text())
            {
                log_info* temp = new log_info;
                temp->user_name = ui->user_sign->text().toStdString();
                temp->mail = ui->email_sign->text().toStdString();
                temp->password = ui->pass1_sign->text().toStdString();
                QMessageBox::information(this , "Thanks" , "Sign Up Successful !", QMessageBox::Information , QMessageBox::Ok);
                obj_controller->user_info[temp->user_name] = temp;
                ui->log_sign->setCurrentIndex(0);
                ui->user_sign->clear();
                ui->email_sign->clear();
                ui->pass1_sign->clear();
                ui->pass2_sign->clear();
                obj_controller->setUser(temp->user_name);
                obj_controller->write_to_file("tasks");
                obj_controller->write_to_file("draft_tasks");
                obj_controller->write_to_file("done");
            }
            else
            {
                QMessageBox messageBox;
                messageBox.critical(0,"Invalid Data","Sorry, Password does not match !");
                ui->pass1_sign->clear();
                ui->pass2_sign->clear();
            }
        }
        else
        {
            QMessageBox::information(this , "Sorry" , "Sorry, This user dad taken !", QMessageBox::Information , QMessageBox::Ok);
            ui->user_sign->clear();
        }
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Data","No data entered or data not completed !");
    }

}

void MainWindow::on_home_btn_clicked()
{
    ui->all_pages->setCurrentIndex(1);
}

void MainWindow::on_logo_btn_clicked()
{
    ui->all_pages->setCurrentIndex(0);
}

void MainWindow::on_calendar_btn_clicked()
{
    ui->all_pages->setCurrentIndex(2);
}

void MainWindow::on_about_btn_clicked()
{
    ui->all_pages->setCurrentIndex(3);
}
//make use log out when it's seccion is finished;
void MainWindow::on_logout_btn_clicked()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "Log Out", "Do you want to logout ?",
        QMessageBox::Cancel | QMessageBox::Yes);
    if(reply == QMessageBox::Yes)
    {
        obj_controller->save_user_info();
        obj_controller->write_to_file("tasks");
        obj_controller->write_to_file("draft_tasks");
        obj_controller->write_to_file("done");
        ui->befora_after->setCurrentIndex(0);
        destroy_widget();
    }
}

void MainWindow::on_exit_btn_clicked()
{
    obj_controller->save_user_info();
    obj_controller->write_to_file("tasks");
    obj_controller->write_to_file("draft_tasks");
    obj_controller->write_to_file("done");
    exit(EXIT_FAILURE);
}
//remove data from data entery;
void MainWindow::on_reset_btn_clicked()
{
    ui->task_name_en->clear();
    ui->task_description_2->clear();
    ui->task_periority_en->clear();
    ui->day_start->clear();
    ui->month_start->clear();
    ui->year_start->clear();
    ui->day_end->clear();
    ui->month_end->clear();
    ui->yaer_end->clear();
}
//let user login and check it's data;
void MainWindow::on_login_btn_clicked()
{
    if(ui->user_login->text() != NULL && ui->pass_login->text() != NULL)
    {
        if(obj_controller->user_info[ui->user_login->text().toStdString()] == nullptr)
        {
            QMessageBox messageBox;
            messageBox.warning(0,"Warining","Sorry, This user not found make one and try again !");
            ui->user_login->clear();
            ui->pass_login->clear();
        }
        else
        {
            if(ui->user_login->text().toStdString() == obj_controller->user_info[ui->user_login->text().toStdString()]->user_name)
            {
                if(ui->pass_login->text().toStdString() == obj_controller->user_info[ui->user_login->text().toStdString()]->password)
                {
                    QMessageBox messageBox;
                    messageBox.information(0,"Thanks","Login Successful !");

                    int Temp_size_1 = obj_controller->user_data->getSize();
                    int Temp_size_2 = obj_controller->user_data->getSize_draft();
                    int Temp_size_3 = obj_controller->user_data->getSize_done();
                    Task_data* temp_1 = new Task_data[Temp_size_1];
                    Task_data* temp_2 = new Task_data[Temp_size_2];
                    Task_data* temp_3 = new Task_data[Temp_size_3];
                    ui->befora_after->setCurrentIndex(1);
                    obj_controller->setUser(ui->user_login->text().toStdString());
                    obj_controller->setPass(ui->pass_login->text().toStdString());
                    ui->user_login->clear();
                    ui->pass_login->clear();
                    obj_controller->read_from_file(temp_1,"tasks");
                    obj_controller->read_from_file(temp_2,"draft_tasks");
                    obj_controller->read_from_file(temp_3,"done");
                    obj_controller->user_data->setArr_list(temp_1);
                    obj_controller->user_data->setDraft_list(temp_2);
                    obj_controller->user_data->setDone_list(temp_3);
                    obj_controller->user_data->check_task();
                    add_task_to_screen(temp_1 , "tasks");
                    add_task_to_screen(temp_2 , "draft_tasks");
                    done_view();
                }
                else
                {
                    QMessageBox messageBox;
                    messageBox.critical(0,"Wrong","Wrong password !");
                    ui->pass_login->clear();
                }
            }
            else
            {
                QMessageBox messageBox;
                messageBox.critical(0,"Wrong","Wrong username !");
                ui->user_login->clear();
                ui->pass_login->clear();
            }
        }
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Data","No data entered or data not completed !");
    }
}
//add task in array and diaplay it on gui;
void MainWindow::on_add_btn_clicked()
{
    if(ui->task_name_en->text() != NULL && ui->task_description_2->text() !=NULL)
    {
        Task_data* temp = new Task_data;
        date_details temp_start ;
        date_details temp_deadline ;
        temp_start.day = ui->day_start->value();
        temp_start.month = ui->month_start->value();
        temp_start.year = ui->year_start->value();
        temp_deadline.day = ui->day_end->value();
        temp_deadline.month = ui->month_end->value();
        temp_deadline.year = ui->yaer_end->value();
        if(temp->check_date(temp_start,temp_deadline))
        {
            temp->setTask_name(ui->task_name_en->text().toStdString());
            temp->setTask_description(ui->task_description_2->text().toStdString());
            temp->setStart_date(temp_start);
            temp->setDeadline_date(temp_deadline);
            temp->setTask_priority(ui->task_periority_en->value());
            int index = obj_controller->user_data->add_task(temp);
            widget_templete(index);
            on_reset_btn_clicked();
            QMessageBox messageBox;
            messageBox.information(0,"Done","Your task addeed successfully !");
        }
        else
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Invalid Data","Invalid date !");
            ui->day_start->clear();
            ui->month_start->clear();
            ui->year_start->clear();
            ui->day_end->clear();
            ui->month_end->clear();
            ui->yaer_end->clear();
        }
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Data","No data entered or data not completed !");
    }
}

void MainWindow::on_periority_num_currentIndexChanged(int index)
{
    ui->display_show->setCurrentIndex(index);
}
//add task to array after edit it;
void MainWindow::on_save_edit_btn_clicked()
{
    if(ui->task_name_en_edit->text() != NULL && ui->task_description_edit->text() !=NULL)
    {
        Task_data* temp = new Task_data;
        date_details temp_start ;
        date_details temp_deadline ;
        temp_start.day = ui->day_start_edit->value();
        temp_start.month = ui->month_start_edit->value();
        temp_start.year = ui->year_start_edit->value();
        temp_deadline.day = ui->day_end_edit->value();
        temp_deadline.month = ui->month_end_edit->value();
        temp_deadline.year = ui->yaer_end_edit->value();
        if(temp->check_date(temp_start,temp_deadline))
        {
            temp->setTask_name(ui->task_name_en_edit->text().toStdString());
            temp->setTask_description(ui->task_description_edit->text().toStdString());
            temp->setStart_date(temp_start);
            temp->setDeadline_date(temp_deadline);
            temp->setTask_priority(ui->task_periority_en_edit->value());
            int index = obj_controller->user_data->add_task(temp);
            ui->task_name_en->setText(ui->task_name_en_edit->text());
            ui->task_description_2->setText(ui->task_description_edit->text());
            ui->day_start->setValue(ui->day_start_edit->value());
            ui->month_start->setValue(ui->month_start_edit->value());
            ui->year_start->setValue(ui->year_start_edit->value());
            ui->day_end->setValue(ui->day_end_edit->value());
            ui->month_end->setValue(ui->month_end_edit->value());
            ui->yaer_end->setValue(ui->yaer_end_edit->value());
            ui->task_periority_en->setValue(ui->task_periority_en_edit->value());
            widget_templete(index);
            on_reset_btn_clicked();

            QMessageBox messageBox;
            messageBox.information(0,"Done","Your task edited successfully !");
            ui->all_pages->setCurrentIndex(1);
        }
        else
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Invalid Data","Invalid date !");
            ui->day_start->clear();
            ui->month_start->clear();
            ui->year_start->clear();
            ui->day_end->clear();
            ui->month_end->clear();
            ui->yaer_end->clear();
        }
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Data","No data entered or data not completed !");
    }
}
