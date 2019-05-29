QT += core
QT -= gui

CONFIG += c++11

TARGET = gui
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    status/status.cpp \
    status/statusbleed.cpp \
    status/statuschannelcontinuous.cpp \
    status/statuschanneling.cpp \
    status/statushot.cpp \
    status/statusleyline.cpp \
    status/statuspain.cpp \
    status/statusseed.cpp \
    status/statusshield.cpp \
    status/statussowerheal.cpp \
    status/statusthirst.cpp \
    status/statusvoidsick.cpp \
    combatant/classbarbman.cpp \
    combatant/classbloodmage.cpp \
    combatant/classbluemage.cpp \
    combatant/classoutsider.cpp \
    combatant/classpain.cpp \
    combatant/classprovidence.cpp \
    combatant/classsower.cpp \
    combatant/combatant.cpp
LIBS += -LC:/SFML/lib
LIBS += -LC:/SFML/bin

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

HEADERS += \
    status/status.h \
    status/statusbleed.h \
    status/statuschannelcontinuous.h \
    status/statuschanneling.h \
    status/statushot.h \
    status/statusleyline.h \
    status/statuspain.h \
    status/statusseed.h \
    status/statusshield.h \
    status/statussowerheal.h \
    status/statusthirst.h \
    status/statusvoidsick.h \
    combatant/classbarbman.h \
    combatant/classbloodmage.h \
    combatant/classbluemage.h \
    combatant/classoutsider.h \
    combatant/classpain.h \
    combatant/classprovidence.h \
    combatant/classsower.h \
    combatant/combatant.h \
    game3v3include.h
