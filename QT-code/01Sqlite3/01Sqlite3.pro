TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt



SOURCES += main.c
INCLUDEPATH +="D:\qt\5.0.1\mingw47_32\include\QtNetwork"
INCLUDEPATH  += $$_PRO_FILE_PWD_/sqlite3

LIBS                    += -L $$_PRO_FILE_PWD_/sqlite3  -lsqlite3
