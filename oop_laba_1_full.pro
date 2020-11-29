QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acid.cpp \
    add_acid_window.cpp \
    add_protein_window.cpp \
    main.cpp \
    mainwindow.cpp \
    protein.cpp \
    protein_edit_window.cpp \
    proteincollection.cpp \
    show_full_protein_window.cpp \
    show_protein_window.cpp \
    sum_protein_window.cpp

HEADERS += \
    acid.h \
    add_acid_window.h \
    add_protein_window.h \
    mainwindow.h \
    protein.h \
    protein_edit_window.h \
    proteincollection.h \
    show_full_protein_window.h \
    show_protein_window.h \
    sum_protein_window.h

FORMS += \
    add_acid_window.ui \
    add_protein_window.ui \
    mainwindow.ui \
    protein_edit_window.ui \
    show_full_protein_window.ui \
    show_protein_window.ui \
    sum_protein_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
