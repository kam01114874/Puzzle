#include "mainwindow.h"
#include "cli/consoleui.h"

#include <QApplication>

#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, char *argv[])
{
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    if (argc > 1 && std::string(argv[1]) == "--cli") {
        ConsoleUI consoleGame;
        consoleGame.run();
        return 0;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
