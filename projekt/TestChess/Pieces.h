#pragma once
#include <qpixmap.h>
#include <qstring.h>
#include "../21L-PROI_Szachy/Point.h"
#include <vector>
#include <map>
#include <string>
#include <cmath>

const unsigned int N = 8;

class ChessPiece
{
public:
	static std::map<int, std::string> mapOfFields;
	int getY() const;
	int getX() const;
	bool isWhite() const;
	bool isOnTop() const;
	bool wasMoved() const;
	virtual void move(int y, int x, ChessPiece* chessBoard[N][N], std::list<std::string>& listOfMoves, bool secondPlayer = true);
	virtual void castling(ChessPiece* chessBoard[N][N], ChessPiece* king, std::list<std::string>& listOfMoves, bool& whiteTurn);
	virtual std::vector<Point<int>> availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control = true) = 0;
protected:
	int currentY;
	int currentX;
	bool white;
	bool onTop;
	bool moved;
	void removeIllegalMoves(ChessPiece* chessBoard[N][N], std::vector<Point<int>>& cords, ChessPiece* king);
};

class Queen : public ChessPiece
{
public:
	Queen(int, int, bool, bool);
	std::vector<Point<int>> availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control = true);
};

class King : public ChessPiece
{
public:
	void move(int y, int x, ChessPiece* chessBoard[N][N], std::list<std::string>& listOfMoves, bool secondPlayer = true);
	void castling(ChessPiece* chessBoard[N][N], ChessPiece* king, std::list<std::string>& listOfMoves, bool& whiteTurn);
	static bool isChecked(ChessPiece* chessBoard[N][N], ChessPiece* king);
	King(int, int, bool, bool);
	std::vector<Point<int>> availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control = true);
};

class Bishop : public ChessPiece
{
public:
	Bishop(int, int, bool, bool);
	std::vector<Point<int>> availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control = true);
};

class Knight : public ChessPiece
{
public:
	Knight(int, int, bool, bool);
	std::vector<Point<int>> availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control = true);

};

class Pawn : public ChessPiece
{
public:
	void move(int y, int x, ChessPiece* chessBoard[N][N], std::list<std::string>& listOfMoves, bool secondPlayer = true);
	Pawn(int, int, bool, bool);
	std::vector<Point<int>> availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control = true);
};

class Rook : public ChessPiece
{
public:
	void move(int y, int x, ChessPiece* chessBoard[N][N], std::list<std::string>& listOfMoves, bool secondPlayer = true);
	Rook(int, int, bool, bool);
	std::vector<Point<int>> availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control = true);
};

