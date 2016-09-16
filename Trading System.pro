#-------------------------------------------------
#
# Project created by QtCreator 2014-11-04T13:38:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainWidget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    logindlg.cpp \
    user.cpp \
    controller.cpp \
    goods.cpp \
    foods.cpp \
    seller.cpp \
    buyer.cpp \
    charging.cpp \
    purchasing.cpp \
    importtype.cpp \
    foodsimporting.cpp \
    electronicimporting.cpp \
    dailyimporting.cpp \
    electronics.cpp \
    dailyuse.cpp \
    vip.cpp \
    tokencharge.cpp \
    clickpurchasing.cpp

HEADERS  += widget.h \
    logindlg.h \
    user.h \
    controller.h \
    goods.h \
    foods.h \
    seller.h \
    buyer.h \
    charging.h \
    purchasing.h \
    importtype.h \
    foodsimporting.h \
    electronicimporting.h \
    dailyimporting.h \
    electronics.h \
    dailyuse.h \
    vip.h \
    tokencharge.h \
    clickpurchasing.h

FORMS    += widget.ui \
    logindlg.ui \
    charging.ui \
    purchasing.ui \
    importtype.ui \
    foodsimporting.ui \
    electronicimporting.ui \
    dailyimporting.ui \
    tokencharge.ui \
    clickpurchasing.ui
