#include "logindlg.h"
#include "ui_logindlg.h"
#include <QtWidgets>
#include "controller.h"
#include "widget.h"
#include "vipscreen.h"
#include "sellerscreen.h"

loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDlg)
{
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet ("border-radius:10px;");
    //==========实现上边角圆弧==========
        QRect rect = this->rect();
        QPainterPath path;
        path.addRoundRect(rect,20,20);
        QPolygon polygon= path.toFillPolygon().toPolygon();//获得这个路径上的所有的点
        QRegion region(polygon);//根据这些点构造这个区域
        setMask(region);
        //==========实现上边角圆弧==========

}

loginDlg::~loginDlg()
{
    delete ui;
}

void loginDlg::on_loginBtn_clicked()
{
    QString usrname;
    QString password;

    usrname = ui->usrLineEdit->text();
    password = ui->pwdLineEdit->text();

    if(Controller::GetInstance()->login(usrname,password) == 1)
    {
         accept();
         Widget* w = new Widget;
         w->show();
    }

    else if(Controller::GetInstance()->login(usrname,password) == 2)
    {
        accept();
        Widget* w = new Widget;
        w->show();
    }

    else if(Controller::GetInstance()->login(usrname,password) == 3)
    {
        accept();
        Widget* w = new Widget;
        w->show();
    }

    else
        QMessageBox::warning(this,tr("Warning"),tr("usr name or password error!"),QMessageBox::Yes);
}

