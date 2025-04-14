// #include "mainwindow.h"

#include <iostream>
#include "game.h"

// #include <QApplication>

//int main(int argc, char *argv[])
int main()
{
    int size;

    std::cout << "Wybierz rozmiar planszy (3–7): ";
    std::cin >> size;

    if (size < 3 || size > 7) {
        std::cerr << "Niepoprawny rozmiar. Dozwolone wartości to 3, 4, 5, 6 lub 7." << std::endl;
        return 1;
    }

    Game game(size); // Tworzymy planszę sizexsize

    std::cout << "Początkowa plansza:\n";
    game.getBoard().draw(); // const& do Board, tylko odczyt
    std::cout << std::endl;


    std::cout << "Plansza po przetasowaniu:\n";
    game.reset();
    game.getBoard().draw();



    return 0;
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
