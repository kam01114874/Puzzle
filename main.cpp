// #include "mainwindow.h"

#include <iostream>
#include "board.h"

// #include <QApplication>

//int main(int argc, char *argv[])
int main()
{
    Board board(3); // Tworzymy planszę 3x3

    std::cout << "🔹 Początkowa plansza:\n";
    board.draw();

    // Ręczne wykonanie kilku ruchów
    board.move(Direction::Right);  // Przesuwamy kafelek 1 w lewo
    std::cout << "\n🔸 Plansza po przesunięciu kafelka 1 w lewo:\n";
    board.draw();

    board.move(Direction::Down);   // Przesuwamy kafelek 4 w górę
    std::cout << "\n🔸 Plansza po przesunięciu kafelka 4 w górę:\n";
    board.draw();



    // Sprawdzenie poprawności ułożenia
    if (board.isSolved()) {
        std::cout << "\n✅ Plansza ułożona poprawnie!\n";
    } else {
        std::cout << "\n❌ Plansza NIE jest ułożona poprawnie!\n";
    }

    return 0;
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
