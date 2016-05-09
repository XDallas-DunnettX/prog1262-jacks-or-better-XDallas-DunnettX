#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T14:22:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DeckOfCards
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    card.cpp \
    deck.cpp \
    hand.cpp

HEADERS  += mainwindow.h \
    card.h \
    deck.h \
    hand.h

FORMS    += mainwindow.ui
