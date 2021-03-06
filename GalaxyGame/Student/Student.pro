#-------------------------------------------------
#
# Project created by QtCreator 2017-06-14T12:45:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GalaxyGame
TEMPLATE = app
CONFIG += c++14


SOURCES += \
    main.cc\
    eventhandler.cc \
    galaxy.cc \
    statistics.cc \
    mainwindow.cc \
    constants.cc \
    creditsdialog.cpp \
    customitem.cc \
    customlistwidgetitem.cc \
    playership.cpp \
    buyhealthdialog.cc \
    starsystemitem.cc \
    fullhealthshipwidgetitem.cc \
    normalshipwidgetitem.cc \
    abandonshipwidgetitem.cc \
    gameoverdialog.cc \
    highscoresdialog.cc \
    notenoughhealthdialog.cc \
    configdialog.cc

HEADERS  += \
    galaxy.hh \
    eventhandler.hh \
    statistics.hh \
    mainwindow.hh \
    constants.hh \
    creditsdialog.h \
    customitem.hh \
    customlistwidgetitem.hh \
    utilities.hh \
    playership.h \
    buyhealthdialog.hh \
    starsystemitem.hh \
    fullhealthshipwidgetitem.hh \
    normalshipwidgetitem.hh \
    abandonshipwidgetitem.hh \
    gameoverdialog.hh \
    highscoresdialog.hh \
    notenoughhealthdialog.hh \
    configdialog.hh

INCLUDEPATH += $$PWD/../Course
DEPENDPATH += $$PWD/../Course

CONFIG(release, debug|release) {
   DESTDIR = release
}

CONFIG(debug, debug|release) {
   DESTDIR = debug
}

win32 {
    copyfiles.commands += @echo NOW COPYING ADDITIONAL FILE(S) for Windows &
    copyfiles.commands += @call xcopy ..\\..\\GalaxyGame\\Assets Assets /i /s /e /y
}
unix:!macx {
    copyfiles.commands += @echo \"NOW COPYING ADDITIONAL FILE(S) for Linux\" &&
    copyfiles.commands += cp -r ../../GalaxyGame/Assets $$DESTDIR
}
macx {
    copyfiles.commands += @echo \"NOW COPYING ADDITIONAL FILE(S) for MacOS\" &&
    copyfiles.commands += mkdir -p $$DESTDIR/GalaxyGame.app/Contents/MacOS &&
    copyfiles.commands += cp -r ../../GalaxyGame/Assets $$DESTDIR &&
    copyfiles.commands += cp -r ../../GalaxyGame/Assets $$DESTDIR/GalaxyGame.app/Contents/MacOS/
}

LIBS += -L$$OUT_PWD/../Course/
LIBS += -L$$OUT_PWD/../Course/$${DESTDIR}/ -lCourse


QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles

FORMS += \
    mainwindow.ui \
    dialog.ui \
    creditsdialog.ui \
    buyhealthdialog.ui \
    gameoverdialog.ui \
    highscoresdialog.ui \
    notenoughhealthdialog.ui
