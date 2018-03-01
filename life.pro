QT += widgets
requires(qtConfig(combobox))

HEADERS       = renderarea.h \
                window.h \
    lifegame.h
SOURCES       = main.cpp \
                renderarea.cpp \
                window.cpp \
    lifegame.cpp


# install
target.path = $$[QT_INSTALL_EXAMPLES]/Life
INSTALLS += target
