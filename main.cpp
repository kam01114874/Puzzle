// #include "mainwindow.h"

#include <iostream>
#include "game.h"
#include "board.h"

// #include <QApplication>

//int main(int argc, char *argv[])
int main()
{
    int size;

    std::cout << "Wybierz rozmiar planszy (3–7): ";
    std::cin >> size;
    std::cout << std::endl;

    if (size < 3 || size > 7) {
        std::cerr << "Niepoprawny rozmiar. Dozwolone wartości to 3, 4, 5, 6 lub 7." << std::endl;
        return 1;
    }

    Game game(size); // Tworzymy planszę sizexsize

    std::cout << "Początkowa plansza:\n";
    game.getBoard().draw(); // const& do Board, tylko odczyt
    std::cout << std::endl;


    std::cout << "Plansza po przetasowaniu:\n";
    game.start();
    game.getBoard().draw();
    std::cout << std::endl;

    char n;

    while (!game.isWon())
    {
        std::cout << "Menu: r - reset gry, x - zakończ grę\n";
        std::cout << "Wybierz kierunek kafelka do przesunięcia w puste miejsce: w - Up, s - Down, a - Left, d - Right";
        std::cout << std::endl;
        std::cin >> n;
        Direction d;
        switch (n) {
            case 'w': d = Direction::Up;     break;
            case 's': d = Direction::Down;   break;
            case 'a': d = Direction::Left;   break;
            case 'd': d = Direction::Right;  break;
            case 'r': {
                game.reset();
                std::cout << "\nPlansza po resecie:\n";
                std::cout << std::endl;
                game.getBoard().draw();
                continue;
            }
            case 'x': return 1;
            default: {
                std::cout << "Nieprawidłowy kierunek!\n";
                std::cout << std::endl;
                continue;
            }
        }
        std::cout << std::endl;

        if (game.getBoard().move(d)) {
            std::cout << "Aktualizacja planszy:\n";
            std::cout << std::endl;
            game.getBoard().draw();
            game.incrementMoveCount();
            std::cout << "Ilość wykonanych ruchów: " << game.getMoveCount();
            std::cout << std::endl;
            std::cout << std::endl;
        }
        else {
            std::cout << "Nieprawidłowy kierunek!\n";
            std::cout << std::endl;
        }
    }

    if (game.isWon())
    {
        std::cout << "Układanka ułożona poprawnie! Gratulacje!\n";
    }


    return 0;
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
