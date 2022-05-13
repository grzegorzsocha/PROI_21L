#include "MainWindow.h"
#include "WelcomeDialog.h"
#include "FinalDialog.h"
#include <fstream>
#include <qfiledialog.h>
#include <QMouseEvent>
#include <qstandardpaths.h>
#include <qaction.h>
#include <QDebug>
#include <string>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    lastClicked = Point<int>(-1, -1);
    srand(time(NULL));
    setupLabels();
    showDialog();
    connect(ui.actionNowa_gra, &QAction::triggered, this, &MainWindow::showDialog);
    connect(ui.actionZapis_do_pliku, &QAction::triggered, this, &MainWindow::saveToFile);
}


void MainWindow::showDialog()
{
    WelcomeDialog dialog;
    dialog.show();
    dialog.exec();
    whiteOnTop = dialog.choosenTop();
    secondPlayer = dialog.choosenPlayer();
    whiteTurn = true;
    highlightedSquares.clear();
    listOfMoves.clear();
    reloadBoard();
    if (!secondPlayer && whiteOnTop)
        computerMove();
    refreshBoard();
}

void MainWindow::setupLabels()
{
    int x{};
    int y{};
    for (unsigned int i = 0; i < N; ++i)
    {
        y = i * 64 + 20;
        for (unsigned j = 0; j < N; ++j)
        {
            x = j * 64;
            QLabel* label = new QLabel(this);
            label->setGeometry(QRect(x, y, 64, 64));
            label->setMinimumSize(QSize(64, 64));
            label->setMaximumSize(QSize(64, 64));
            squares[i][j] = label;
        }
    }
}

void MainWindow::reloadBoard()
{
    for (auto& chessBoardRow : chessBoard)
        for (auto& chessBoardField : chessBoardRow)
        {
            if (chessBoardField != nullptr)
            {
                delete chessBoardField;
                chessBoardField = nullptr;
            }
            
        }

    for (unsigned int i = 0; i < N; ++i)
    {
        chessBoard[1][i] = new Pawn(1, i, whiteOnTop, true);
        chessBoard[6][i] = new Pawn(6, i, !whiteOnTop, false);
    }
    if (whiteOnTop)
    {
        kings[0] = new King(0, 3, whiteOnTop, true);
        chessBoard[0][3] = kings[0];
        chessBoard[0][4] = new Queen(0, 4, whiteOnTop, true);
        kings[1] = new King(7, 3, !whiteOnTop, false);
        chessBoard[7][3] = kings[1];
        chessBoard[7][4] = new Queen(7, 4, !whiteOnTop, false);
    }
    else
    {
        chessBoard[0][3] = new Queen(0, 3, whiteOnTop, true);
        kings[1] = new King(0, 4, whiteOnTop, true);
        chessBoard[0][4] = kings[1];
        chessBoard[7][3] = new Queen(7, 3, !whiteOnTop, false);
        kings[0] = new King(7, 4, !whiteOnTop, false);
        chessBoard[7][4] = kings[0];
    }

    chessBoard[0][0] = new Rook(0, 0, whiteOnTop, true);
    chessBoard[0][1] = new Knight(0, 1, whiteOnTop, true);
    chessBoard[0][2] = new Bishop(0, 2, whiteOnTop, true);
    chessBoard[0][5] = new Bishop(0, 5, whiteOnTop, true);
    chessBoard[0][6] = new Knight(0, 6, whiteOnTop, true);
    chessBoard[0][7] = new Rook(0, 7, whiteOnTop, true);

    chessBoard[7][0] = new Rook(7, 0, !whiteOnTop, false);
    chessBoard[7][1] = new Knight(7, 1, !whiteOnTop, false);
    chessBoard[7][2] = new Bishop(7, 2, !whiteOnTop, false);
    chessBoard[7][5] = new Bishop(7, 5, !whiteOnTop, false);
    chessBoard[7][6] = new Knight(7, 6, !whiteOnTop, false);
    chessBoard[7][7] = new Rook(7, 7, !whiteOnTop, false);
}

void MainWindow::refreshBoard()
{
    for (unsigned int i = 0; i < N; ++i)
    {
        for (unsigned j = 0; j < N; ++j)
        {
            if (chessBoard[i][j] != nullptr)
                squares[i][j]->setPixmap(chessBoard[i][j]->getImg());
            else
                squares[i][j]->setPixmap(QPixmap());
            squares[i][j]->setStyleSheet(QString());
        }
    }
}

void MainWindow::computerMove()
{
    int y = rand() % 8;
    int x = rand() % 8;
    ChessPiece* king{};
    if (whiteTurn)
        king = kings[0];
    else
        king = kings[1];
    do
    {
        y = rand() % 8;
        x = rand() % 8;
    } while (chessBoard[y][x] == nullptr || (chessBoard[y][x] != nullptr && (chessBoard[y][x]->isWhite() != whiteTurn ||  chessBoard[y][x]->availableMoves(chessBoard, king).size() == 0)));

    auto possibleMoves = chessBoard[y][x]->availableMoves(chessBoard, king);

    auto selectedMove = possibleMoves[rand() % possibleMoves.size()];

    move(Point<int>(y, x), selectedMove);

    whiteTurn = !whiteTurn;
}

void MainWindow::isCheckmate()
{
    bool checkmate = true;

    ChessPiece* king{};
    if (!whiteTurn)
    {
        king = kings[0];
    }
    else
    {
        king = kings[1];
    }

    for (auto& chessBoardRow : chessBoard)
    {
        for (auto& chessBoardField : chessBoardRow)
        {
            if (chessBoardField != nullptr && chessBoardField->isWhite() != whiteTurn && chessBoardField->availableMoves(chessBoard, king).size() > 0)
            {
                checkmate = false;
            }
            if (!checkmate)
                break;
        }
        if (!checkmate)
            break;
    }

    if (checkmate)
    {
        std::string text;
        if (whiteTurn)
            text = "Wygra\305\202 gracz z bialymi pionkami";
        else
            text = "Wygra\305\202 gracz z czarnymi pionkami";
        listOfMoves.push_back(text);
        FinalGameDialog finalDialog(text, this);
        finalDialog.show();
        if (finalDialog.exec())
            showDialog();
        else
            exit(0);
    }
}


void MainWindow::move(const Point<int>& source, const Point<int>& destination)
{
    int destY{ destination.getY() };
    int destX{ destination.getX() };
    int sourceY{ source.getY() };
    int sourceX{ source.getX() };
    if (chessBoard[destY][destX] != nullptr)
        delete chessBoard[destY][destX];
    chessBoard[destY][destX] = chessBoard[sourceY][sourceX];
    chessBoard[destY][destX]->move(destY, destX, chessBoard, listOfMoves, secondPlayer);
    chessBoard[sourceY][sourceX] = nullptr;
    std::string moveDesc = ChessPiece::mapOfFields[sourceX] + std::to_string(sourceY+1) + "->" + ChessPiece::mapOfFields[destX] + std::to_string(destY+1);
    listOfMoves.push_back(moveDesc);
    refreshBoard();
}


MainWindow::~MainWindow()
{
    for (auto& squareRow : squares)
        for (auto& square : squareRow)
            delete square;

    for (auto& chessBoardRow : chessBoard)
        for (auto& chessBoardField : chessBoardRow)
            delete chessBoardField;
}


void MainWindow::mousePressEvent(QMouseEvent* event)
{
    int clieckedPosX = event->x() / 64;
    int clieckedPosY = (event->y() - 20) / 64;

    if (chessBoard[clieckedPosY][clieckedPosX] != nullptr && chessBoard[clieckedPosY][clieckedPosX]->isWhite() == whiteTurn)
    {
        refreshBoard();
        ChessPiece* king{};
        if (whiteTurn)
        {
            king = kings[0];
        }
        else
        {
            king = kings[1];
        }
        highlightedSquares = chessBoard[clieckedPosY][clieckedPosX]->availableMoves(chessBoard, king);
        for (auto& square : highlightedSquares)
        {
            int yToHighLight = square.getX();
            int xToHighLight = square.getY();
            squares[xToHighLight][yToHighLight]->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));
        }
        lastClicked = Point<int>(clieckedPosY, clieckedPosX);
    }
    else
    {
        for (auto& square : highlightedSquares)
        {
            if (square == Point<int>(clieckedPosY, clieckedPosX))
            {
                
                move(Point<int>(lastClicked.getY(), lastClicked.getX()), square);
                refreshBoard();

                isCheckmate();

                highlightedSquares.clear();
                whiteTurn = !whiteTurn;
                
                if (!secondPlayer)
                {
                    computerMove();
                    refreshBoard();
                    isCheckmate();
                }
                
                break;
            }
        }
        
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent* event)
{
    int clieckedPosX = event->x() / 64;
    int clieckedPosY = (event->y() - 20) / 64;
    ChessPiece* king{};
    if (whiteTurn)
    {
        king = kings[1];
    }
    else
    {
        king = kings[0];
    }
    if (chessBoard[clieckedPosY][clieckedPosX] != nullptr && chessBoard[clieckedPosY][clieckedPosX]->isWhite() == whiteTurn)
    {
        chessBoard[clieckedPosY][clieckedPosX]->castling(chessBoard, king, listOfMoves, whiteTurn);
    }
    refreshBoard();
}

void MainWindow::saveToFile() const
{
    QString filename = QFileDialog::getSaveFileName(nullptr, "Zapis pliku do gry", "zapis_gry", "Text files(*.txt)");
    std::ofstream outputFile;
    outputFile.open(filename.toStdString());
    if (whiteOnTop)
        outputFile << "Pionki na g\303\263rze: bia\305\202e" << std::endl;
    else    
        outputFile << "Pionki na g\303\263rze: czarne" << std::endl;
    if (secondPlayer)
        outputFile << "Przeciwnik: drugi gracz" << std::endl;
    else
        outputFile << "Przeciwnik: komputer" << std::endl;
    for (auto move : listOfMoves)
        outputFile << move << std::endl;
    outputFile.close();
}
