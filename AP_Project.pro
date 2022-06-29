QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Global.cpp \
    add_to_cart.cpp \
    admin.cpp \
    article.cpp \
    cart.cpp \
    client.cpp \
    cloths.cpp \
    create_account.cpp \
    forget_password.cpp \
    load1.cpp \
    load2.cpp \
    load3.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    sporting_goods.cpp \
    transaction.cpp \
    widget_kala.cpp

HEADERS += \
    Global.h \
    Person.h \
    add_to_cart.h \
    admin.h \
    article.h \
    cart.h \
    client.h \
    cloths.h \
    create_account.h \
    forget_password.h \
    load1.h \
    load2.h \
    load3.h \
    login.h \
    mainwindow.h \
    sporting_goods.h \
    transaction.h \
    widget_kala.h

FORMS += \
    add_to_cart.ui \
    admin.ui \
    cart.ui \
    client.ui \
    create_account.ui \
    forget_password.ui \
    load1.ui \
    load2.ui \
    load3.ui \
    login.ui \
    mainwindow.ui \
    transaction.ui \
    widget_kala.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc

DISTFILES +=
