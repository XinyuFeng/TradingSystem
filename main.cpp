#include "widget.h"
#include <QApplication>
#include "logindlg.h"
#include "user.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginDlg login;
    login.exec();
    return a.exec();
}
