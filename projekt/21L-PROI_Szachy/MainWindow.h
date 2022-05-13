#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <list>
#include <time.h>
#include "Pieces.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void saveToFile() const;
    MainWindow(QWidget* parent = Q_NULLPTR);
    ~MainWindow();

private:
    Ui::MainWindowClass ui;
    QLabel* squares[N][N];
    ChessPiece* chessBoard[N][N]{};
    ChessPiece* kings[2];
    std::list<std::string> listOfMoves;
    std::vector<Point<int>> highlightedSquares;
    Point<int> lastClicked;
    void setupLabels();
    void showDialog();
    void reloadBoard();
    void refreshBoard();
    void computerMove();
    void isCheckmate();
    void move(const Point<int>& source, const Point<int>& destination);
    bool whiteOnTop;
    bool secondPlayer;
    bool whiteTurn;
};
