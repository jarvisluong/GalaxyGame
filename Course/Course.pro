
TARGET = Course
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++14


HEADERS += \
    iaction.hh \
    ieventhandler.hh \
    igalaxy.hh \
    igamerunner.hh \
    initialize.hh \
    istatistics.hh

unix {
    target.path = /usr/lib
    INSTALLS += target
}
