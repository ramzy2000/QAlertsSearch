#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDate>
#include <QString>

QString getMonth(int month)
{
    switch(month)
    {
    case 1:
        return "Jan";
    case 2:
        return "Feb";
    case 3:
        return "Mar";
    case 4:
        return "Apr";
    case 5:
        return "May";
    case 6:
        return "Jun";
    case 7:
        return "Jul";
    case 8:
        return "Aug";
    case 9:
        return "Sep";
    case 10:
        return "Oct";
    case 11:
        return "Nov";
    case 12:
        return "Dec";
    default:
        return "";
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    calendar = ui->calendarWidget;

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QDate date = calendar->selectedDate();
        int day = date.day();
        int month = date.month();
        QString firstPart = "https://qalerts.app/?q=";
        QString monthStr = getMonth(month);
        QString dayStr = QString::number(day);
        qDebug() << getMonth(month);

        QString res = "start msedge " + firstPart + monthStr + "+" + dayStr + ",";

        system(res.toStdString().c_str());
    });
}

Widget::~Widget()
{
    delete ui;
}

