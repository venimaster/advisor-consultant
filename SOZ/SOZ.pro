#-------------------------------------------------
#
# Project created by QtCreator 2011-11-28T14:00:59
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += webkit

TARGET = SOZ
TEMPLATE = app

INCLUDEPATH += leftPanels\ Etaps

PRECOMPILED_HEADER = stable.h


SOURCES += main.cpp\
        mainwindow.cpp \
    namepanel.cpp \
    helpbutton.cpp \
    leftpanel.cpp \
    centralpanel.cpp \
    etapbutton.cpp \
    bottompanel.cpp \
    mylineedit.cpp \
    tester.cpp \
    psyh.cpp \
    answervariantbutton.cpp \
    dbwork.cpp \
    testerdaleebutton.cpp \
    gradients.cpp \
    obrabotchik.cpp \
    radiopushbutton.cpp \
    leftPanels/regpanel.cpp \
    leftPanels/etappanel.cpp \
    leftPanels/registrationpanel.cpp \
    leftPanels/autorisationpanel.cpp \
    testpanel.cpp \
    helppanel.cpp \
    mytextedit.cpp \
    Etaps/etap2.cpp \
    Etaps/psyhtest.cpp \
    hipanel.cpp \
    Etaps/psyhtestvariantbutton.cpp \
    literature.cpp

HEADERS  += mainwindow.h \
    namepanel.h \
    helpbutton.h \
    leftpanel.h \
    centralpanel.h \
    etapbutton.h \
    bottompanel.h \
    mylineedit.h \
    tester.h \
    psyh.h \
    answervariantbutton.h \
    dbwork.h \
    testerdaleebutton.h \
    gradients.h \
    obrabotchik.h \
    radiopushbutton.h \
    leftPanels/regpanel.h \
    leftPanels/etappanel.h \
    leftPanels/registrationpanel.h \
    leftPanels/autorisationpanel.h \
    stable.h \
    testpanel.h \
    helppanel.h \
    mytextedit.h \
    Etaps/etap2.h \
    Etaps/psyhtest.h \
    hipanel.h \
    Etaps/psyhtestvariantbutton.h \
    literature.h

RESOURCES += \
    images.qrc
