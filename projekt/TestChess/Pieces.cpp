#include "Pieces.h"
#include <qdebug.h>

std::map<int, std::string> ChessPiece::mapOfFields = {
	{0, "A"},
	{1, "B"},
	{2, "C"},
	{3, "D"},
	{4, "E"},
	{5, "F"},
	{6, "G"},
	{7, "H"}
};


bool ChessPiece::isWhite() const
{
	return white;
}

void ChessPiece::move(int y, int x, ChessPiece* chessBoard[N][N], std::list<std::string>& listOfMoves, bool secondPlayer)
{
	currentY = y;
	currentX = x;
	moved = true;
}

int ChessPiece::getY() const
{
	return currentY;
}

int ChessPiece::getX() const
{
	return currentX;
}

bool ChessPiece::isOnTop() const
{
	return onTop;
}

bool ChessPiece::wasMoved() const
{
	return moved;
}

void ChessPiece::castling(ChessPiece* chessBoard[N][N], ChessPiece* king, std::list<std::string>& listOfMoves, bool& whiteTurn)
{
}


void ChessPiece::removeIllegalMoves(ChessPiece* chessBoard[N][N], std::vector<Point<int>>& cords, ChessPiece* king)
{
	int x{};
	int y{};
	int originalX = currentX;
	int originalY = currentY;
	ChessPiece* originalPiece{};
	auto it = cords.begin();
	while (it != cords.end())
	{
		x = it->getX();
		y = it->getY();
		originalPiece = chessBoard[y][x];
		chessBoard[y][x] = this;
		chessBoard[currentY][currentX] = nullptr;
		currentY = y;
		currentX = x;

		if (King::isChecked(chessBoard, king))
			it = cords.erase(it);
		else
			++it;
		chessBoard[currentY][currentX] = originalPiece;
		chessBoard[originalY][originalX] = this;
		currentX = originalX;
		currentY = originalY;
	}
}


Queen::Queen(int posY, int posX, bool white, bool onTop)
{
	currentX = posX;
	currentY = posY;
	this->white = white;
	this->onTop = onTop;
	this->moved = false;
}

Bishop::Bishop(int posY, int posX, bool white, bool onTop)
{
	currentX = posX;
	currentY = posY;
	this->white = white;
	this->onTop = onTop;
	this->moved = false;
}


void Rook::move(int y, int x, ChessPiece* chessBoard[N][N], std::list<std::string>& listOfMoves, bool secondPlayer)
{
	currentX = x;
	currentY = y;
	moved = true;
}


Rook::Rook(int posY, int posX, bool white, bool onTop)
{
	currentX = posX;
	currentY = posY;
	this->white = white;
	this->onTop = onTop;
	this->moved = false;
}


void Pawn::move(int y, int x, ChessPiece* chessBoard[N][N], std::list<std::string>& listOfMoves, bool secondPlayer)
{
	if (y == 0 || y == 7)
	{
		int answer = (rand() % 4) + 1;

		switch (answer)
		{
		case 1:
			chessBoard[y][x] = new Queen(y, x, this->white, this->onTop);
			listOfMoves.push_back("Pawn promoted to Queen");
			break;
		case 2:
			chessBoard[y][x] = new Knight(y, x, this->white, this->onTop);
			listOfMoves.push_back("Pawn promoted to Knight");
			break;
		case 3:
			chessBoard[y][x] = new Bishop(y, x, this->white, this->onTop);
			listOfMoves.push_back("Pawn promoted to Bishop");
			break;
		case 4:
			chessBoard[y][x] = new Rook(y, x, this->white, this->onTop);
			listOfMoves.push_back("Pawn promoted to Rook");
			break;
		}
		delete this;
	}
	else
	{
		currentY = y;
		currentX = x;
	}
	moved = true;
}


Pawn::Pawn(int posY, int posX, bool white, bool onTop)
{
	currentX = posX;
	currentY = posY;
	this->white = white;
	this->onTop = onTop;
	this->moved = false;
}

Knight::Knight(int posY, int posX, bool white, bool onTop)
{
	currentX = posX;
	currentY = posY;
	this->white = white;
	this->onTop = onTop;
	this->moved = false;
}


void King::move(int y, int x, ChessPiece* chessBoard[N][N], std::list<std::string>& listOfMoves, bool secondPlayer)
{
	currentX = x;
	currentY = y;
	moved = true;
}

void King::castling(ChessPiece* chessBoard[N][N], ChessPiece* king, std::list<std::string>& listOfMoves, bool& whiteTurn)
{

	if ((white && onTop) || (!white && !onTop))
	{
		if (!this->moved && chessBoard[currentY][0] != nullptr && !(chessBoard[currentY][0]->wasMoved()) && chessBoard[currentY][1] == nullptr && chessBoard[currentY][2] == nullptr)
		{
			bool isBeaten = false;
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					if (chessBoard[i][j] != nullptr && chessBoard[i][j]->isWhite() != white)
					{
						for (auto point : chessBoard[i][j]->availableMoves(chessBoard, king))
						{
							if (!(point == Point<int>(currentY, 1) || point == Point<int>(currentY, 2)) && chessBoard[currentY][0] != nullptr)
							{
								isBeaten = true;
								break;
							}
						}
					}
				}
			}
			if (!isBeaten)
			{
				chessBoard[currentY][0]->move(chessBoard[currentY][0]->getY(), 2, chessBoard, listOfMoves);
				ChessPiece* temp = chessBoard[currentY][currentX];
				this->move(this->currentY, 1, chessBoard, listOfMoves);
				chessBoard[currentY][1] = temp;
				chessBoard[currentY][2] = chessBoard[currentY][0];
				chessBoard[currentY][0] = nullptr;
				chessBoard[currentY][3] = nullptr;
				std::string castlingDesc = "Castling: ";
				castlingDesc += "D" + std::to_string(currentY) + "<->" + "B" + std::to_string(currentY) + "   " + "A" + std::to_string(currentY) + "<->" + "C" + std::to_string(currentY);
				listOfMoves.push_back(castlingDesc);
			}
		}

		else if (!this->moved && chessBoard[currentY][7] != nullptr && !(chessBoard[currentY][7]->wasMoved()) && chessBoard[currentY][6] == nullptr && chessBoard[currentY][5] == nullptr && chessBoard[currentY][4] == nullptr)
		{
			bool isBeaten = false;
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					if (chessBoard[i][j] != nullptr && chessBoard[i][j]->isWhite() != white)
					{
						for (auto point : chessBoard[i][j]->availableMoves(chessBoard, king))
						{
							if (!(point == Point<int>(currentY, 4) || point == Point<int>(currentY, 5)))
							{
								isBeaten = true;
								break;
							}
						}
					}
				}
			}
			if (!isBeaten)
			{
				chessBoard[currentY][7]->move(chessBoard[currentY][7]->getY(), 4, chessBoard, listOfMoves);
				ChessPiece* temp = chessBoard[currentY][currentX];
				this->move(this->currentY, 5, chessBoard, listOfMoves);
				chessBoard[currentY][5] = temp;
				chessBoard[currentY][4] = chessBoard[currentY][7];
				chessBoard[currentY][7] = nullptr;
				chessBoard[currentY][3] = nullptr;
				std::string castlingDesc = "Castling: ";
				castlingDesc += "H" + std::to_string(currentY) + "<->" + "E" + std::to_string(currentY) + "   " + "D" + std::to_string(currentY) + "<->" + "F" + std::to_string(currentY);
				listOfMoves.push_back(castlingDesc);
			}
		}
	}
	else
	{
		if (!this->moved && chessBoard[currentY][0] != nullptr && !(chessBoard[currentY][0]->wasMoved()) && chessBoard[currentY][1] == nullptr && chessBoard[currentY][2] == nullptr && chessBoard[currentY][3] == nullptr)
		{
			bool isBeaten = false;
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					if (chessBoard[i][j] != nullptr && chessBoard[i][j]->isWhite() != white)
					{
						for (auto point : chessBoard[i][j]->availableMoves(chessBoard, king))
						{
							if (!(point == Point<int>(currentY, 2) || point == Point<int>(currentY, 3)) && chessBoard[currentY][0] != nullptr)
							{
								isBeaten = true;
								break;
							}
						}
					}
				}
			}
			if (!isBeaten)
			{
				chessBoard[currentY][0]->move(chessBoard[currentY][0]->getY(), 3, chessBoard, listOfMoves);
				ChessPiece* temp = chessBoard[currentY][currentX];
				this->move(this->currentY, 2, chessBoard, listOfMoves);
				chessBoard[currentY][2] = temp;
				chessBoard[currentY][3] = chessBoard[currentY][0];
				chessBoard[currentY][0] = nullptr;
				chessBoard[currentY][4] = nullptr;
				std::string castlingDesc = "Castling: ";
				castlingDesc += "A" + std::to_string(currentY) + "<->" + "D" + std::to_string(currentY) + "   " + "E" + std::to_string(currentY) + "<->" + "C" + std::to_string(currentY);
				listOfMoves.push_back(castlingDesc);
			}
		}

		else if (!this->moved && chessBoard[currentY][7] != nullptr && !(chessBoard[currentY][7]->wasMoved()) && chessBoard[currentY][6] == nullptr && chessBoard[currentY][5] == nullptr)
		{
			bool isBeaten = false;
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					if (chessBoard[i][j] != nullptr && chessBoard[i][j]->isWhite() != white)
					{
						for (auto point : chessBoard[i][j]->availableMoves(chessBoard, king))
						{
							if (!(point == Point<int>(currentY, 5) || point == Point<int>(currentY, 6)))
							{
								isBeaten = true;
							}
						}
					}
				}
			}
			if (!isBeaten)
			{
				chessBoard[currentY][0]->move(chessBoard[currentY][0]->getY(), 5, chessBoard, listOfMoves);
				ChessPiece* temp = chessBoard[currentY][currentX];
				this->move(this->currentY, 6, chessBoard, listOfMoves);
				chessBoard[currentY][6] = temp;
				chessBoard[currentY][5] = chessBoard[currentY][7];
				chessBoard[currentY][7] = nullptr;
				chessBoard[currentY][4] = nullptr;
				std::string castlingDesc = "Castling: ";
				castlingDesc += "H" + std::to_string(currentY) + "<->" + "F" + std::to_string(currentY) + "   " + "E" + std::to_string(currentY) + "<->" + "G" + std::to_string(currentY);
				listOfMoves.push_back(castlingDesc);
			}
		}
	}
}

bool King::isChecked(ChessPiece* chessBoard[N][N], ChessPiece* king)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (chessBoard[i][j] != nullptr && chessBoard[i][j]->isWhite() != king->isWhite())
			{
				for (auto move : chessBoard[i][j]->availableMoves(chessBoard, king, false))
				{
					if (move == Point<int>(king->getY(), king->getX()))
						return true;
				}
			}
		}
	}

	return false;
}

King::King(int posY, int posX, bool white, bool onTop)
{
	currentX = posX;
	currentY = posY;
	this->white = white;
	this->onTop = onTop;
	this->moved = false;
}


std::vector<Point<int>> Pawn::availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control)
{
	std::vector<Point<int>> cords;

	if (onTop && currentY == 1 && chessBoard[currentY + 2][currentX] == nullptr && chessBoard[currentY + 1][currentX] == nullptr)
	{
		cords.push_back(Point<int>(currentY + 2, currentX));
	}
	if (!onTop && currentY == 6 && chessBoard[currentY - 2][currentX] == nullptr && chessBoard[currentY - 1][currentX] == nullptr)
	{
		cords.push_back(Point<int>(currentY - 2, currentX));
	}
	if (currentY + 1 <= 7)
	{
		if (onTop && chessBoard[currentY + 1][currentX] == nullptr)
		{
			cords.push_back(Point<int>(currentY + 1, currentX));
		}
	}
	if (currentY - 1 >= 0)
	{
		if (!onTop && chessBoard[currentY - 1][currentX] == nullptr)
		{
			cords.push_back(Point<int>(currentY - 1, currentX));
		}
	}
	if (currentY + 1 <= 7 && currentX + 1 <= 7)
	{
		if (onTop && chessBoard[currentY + 1][currentX + 1] != nullptr)
		{
			if (chessBoard[currentY + 1][currentX + 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY + 1, currentX + 1));
		}
	}
	if (currentY - 1 >= 0 && currentX + 1 <= 7)
	{
		if (!onTop && chessBoard[currentY - 1][currentX + 1] != nullptr)
		{
			if (chessBoard[currentY - 1][currentX + 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY - 1, currentX + 1));
		}
	}
	if (currentY + 1 <= 7 && currentX - 1 >= 0)
	{
		if (onTop && chessBoard[currentY + 1][currentX - 1] != nullptr)
		{
			if (chessBoard[currentY + 1][currentX - 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY + 1, currentX - 1));
		}
	}
	if (currentY - 1 >= 0 && currentX - 1 >= 0)
	{
		if (!onTop && chessBoard[currentY - 1][currentX - 1] != nullptr)
		{
			if (chessBoard[currentY - 1][currentX - 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY - 1, currentX - 1));
		}
	}

	if (!control)
		return cords;

	removeIllegalMoves(chessBoard, cords, king);

	return cords;
}


std::vector<Point<int>> Bishop::availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control)
{
	std::vector<Point<int>> cords;
	for (int i = currentY + 1, j = currentX + 1; i < N && j < N; i++, j++)
	{
		if (chessBoard[i][j] != nullptr)
		{
			if (chessBoard[i][j]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, j));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, j));
		}
	}
	for (int i = currentY + 1, j = currentX - 1; i < N && j >= 0; i++, j--)
	{
		if (chessBoard[i][j] != nullptr)
		{
			if (chessBoard[i][j]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, j));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, j));
		}
	}
	for (int i = currentY - 1, j = currentX + 1; i >= 0 && j < N; i--, j++)
	{
		if (chessBoard[i][j] != nullptr)
		{
			if (chessBoard[i][j]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, j));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, j));
		}
	}
	for (int i = currentY - 1, j = currentX - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (chessBoard[i][j] != nullptr)
		{
			if (chessBoard[i][j]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, j));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, j));
		}
	}

	if (!control)
		return cords;

	removeIllegalMoves(chessBoard, cords, king);

	return cords;
}
std::vector<Point<int>> Rook::availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control)
{
	std::vector<Point<int>> cords;
	for (int i = currentY + 1; i < N; ++i)
	{
		if (chessBoard[i][currentX] != nullptr)
		{
			if (chessBoard[i][currentX]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, currentX));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, currentX));
		}
	}
	for (int i = currentY - 1; i >= 0; --i)
	{
		if (chessBoard[i][currentX] != nullptr)
		{
			if (chessBoard[i][currentX]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, currentX));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, currentX));
		}
	}
	for (int i = currentX + 1; i < N; ++i)
	{
		if (chessBoard[currentY][i] != nullptr)
		{
			if (chessBoard[currentY][i]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY, i));
			break;
		}
		else
		{
			cords.push_back(Point<int>(currentY, i));
		}
	}
	for (int i = currentX - 1; i >= 0; --i)
	{
		if (chessBoard[currentY][i] != nullptr)
		{
			if (chessBoard[currentY][i]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY, i));
			break;
		}
		else
		{
			cords.push_back(Point<int>(currentY, i));
		}
	}

	if (!control)
		return cords;

	removeIllegalMoves(chessBoard, cords, king);

	return cords;
}
std::vector<Point<int>> King::availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control)
{
	std::vector<Point<int>> cords;
	if (currentY + 1 <= 7)
	{
		if (chessBoard[currentY + 1][currentX] == nullptr)
			cords.push_back(Point<int>(currentY + 1, currentX));
		else {
			if (chessBoard[currentY + 1][currentX]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY + 1, currentX));
		}
	}

	if (currentX + 1 <= 7)
	{
		if (chessBoard[currentY][currentX + 1] == nullptr)
			cords.push_back(Point<int>(currentY, currentX + 1));
		else {
			if (chessBoard[currentY][currentX + 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY, currentX + 1));
		}
	}

	if (currentY - 1 >= 0)
	{
		if (chessBoard[currentY - 1][currentX] == nullptr)
			cords.push_back(Point<int>(currentY - 1, currentX));
		else {
			if (chessBoard[currentY - 1][currentX]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY - 1, currentX));
		}
	}

	if (currentX - 1 >= 0)
	{
		if (chessBoard[currentY][currentX - 1] == nullptr)
			cords.push_back(Point<int>(currentY, currentX - 1));
		else {
			if (chessBoard[currentY][currentX - 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY, currentX - 1));
		}
	}

	if (currentX + 1 <= 7 && currentY + 1 <= 7)
	{
		if (chessBoard[currentY + 1][currentX + 1] == nullptr)
			cords.push_back(Point<int>(currentY + 1, currentX + 1));
		else {
			if (chessBoard[currentY + 1][currentX + 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY + 1, currentX + 1));
		}
	}

	if (currentX - 1 >= 0 && currentY + 1 <= 7)
	{
		if (chessBoard[currentY + 1][currentX - 1] == nullptr)
			cords.push_back(Point<int>(currentY + 1, currentX - 1));
		else
		{
			if (chessBoard[currentY + 1][currentX - 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY + 1, currentX - 1));
		}
	}

	if (currentX + 1 <= 7 && currentY - 1 >= 0)
	{
		if (chessBoard[currentY - 1][currentX + 1] == nullptr)
			cords.push_back(Point<int>(currentY - 1, currentX + 1));
		else {
			if (chessBoard[currentY - 1][currentX + 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY - 1, currentX + 1));
		}
	}

	if (currentX - 1 >= 0 && currentY - 1 >= 0)
	{
		if (chessBoard[currentY - 1][currentX - 1] == nullptr)
			cords.push_back(Point<int>(currentY - 1, currentX - 1));
		else
		{
			if (chessBoard[currentY - 1][currentX - 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY - 1, currentX - 1));
		}
	}

	if (!control)
		return cords;

	removeIllegalMoves(chessBoard, cords, king);

	return cords;
}

std::vector<Point<int>> Knight::availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control)
{
	std::vector<Point<int>> cords;
	if (currentY + 1 <= 7 && currentX + 2 <= 7)
	{
		if (chessBoard[currentY + 1][currentX + 2] == nullptr)
			cords.push_back(Point<int>(currentY + 1, currentX + 2));
		else {
			if (chessBoard[currentY + 1][currentX + 2]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY + 1, currentX + 2));
		}
	}

	if (currentY + 1 <= 7 && currentX - 2 >= 0)
	{
		if (chessBoard[currentY + 1][currentX - 2] == nullptr)
			cords.push_back(Point<int>(currentY + 1, currentX - 2));
		else
		{
			if (chessBoard[currentY + 1][currentX - 2]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY + 1, currentX - 2));
		}
	}

	if (currentY - 1 >= 0 && currentX + 2 <= 7)
	{
		if (chessBoard[currentY - 1][currentX + 2] == nullptr)
			cords.push_back(Point<int>(currentY - 1, currentX + 2));
		else
		{
			if (chessBoard[currentY - 1][currentX + 2]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY - 1, currentX + 2));
		}
	}

	if (currentY - 1 >= 0 && currentX - 2 >= 0)
	{
		if (chessBoard[currentY - 1][currentX - 2] == nullptr)
			cords.push_back(Point<int>(currentY - 1, currentX - 2));
		else
		{
			if (chessBoard[currentY - 1][currentX - 2]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY - 1, currentX - 2));
		}
	}

	if (currentY + 2 <= 7 && currentX + 1 <= 7)
	{
		if (chessBoard[currentY + 2][currentX + 1] == nullptr)
			cords.push_back(Point<int>(currentY + 2, currentX + 1));
		else
		{
			if (chessBoard[currentY + 2][currentX + 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY + 2, currentX + 1));
		}
	}

	if (currentY + 2 <= 7 && currentX - 1 >= 0)
	{
		if (chessBoard[currentY + 2][currentX - 1] == nullptr)
			cords.push_back(Point<int>(currentY + 2, currentX - 1));
		else
		{
			if (chessBoard[currentY + 2][currentX - 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY + 2, currentX - 1));
		}
	}

	if (currentY - 2 >= 0 && currentX + 1 <= 7)
	{
		if (chessBoard[currentY - 2][currentX + 1] == nullptr)
			cords.push_back(Point<int>(currentY - 2, currentX + 1));
		else
		{
			if (chessBoard[currentY - 2][currentX + 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY - 2, currentX + 1));
		}
	}

	if (currentY - 2 >= 0 && currentX - 1 >= 0)
	{
		if (chessBoard[currentY - 2][currentX - 1] == nullptr)
			cords.push_back(Point<int>(currentY - 2, currentX - 1));
		else
		{
			if (chessBoard[currentY - 2][currentX - 1]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY - 2, currentX - 1));
		}
	}

	if (!control)
		return cords;

	removeIllegalMoves(chessBoard, cords, king);

	return cords;
}

std::vector<Point<int>> Queen::availableMoves(ChessPiece* chessBoard[N][N], ChessPiece* king, bool control)
{
	std::vector<Point<int>> cords;
	for (int i = currentY + 1; i < N; ++i)
	{
		if (chessBoard[i][currentX] != nullptr)
		{
			if (chessBoard[i][currentX]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, currentX));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, currentX));
		}
	}
	for (int i = currentY - 1; i >= 0; --i)
	{
		if (chessBoard[i][currentX] != nullptr)
		{
			if (chessBoard[i][currentX]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, currentX));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, currentX));
		}
	}
	for (int i = currentX + 1; i < N; ++i)
	{
		if (chessBoard[currentY][i] != nullptr)
		{
			if (chessBoard[currentY][i]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY, i));
			break;
		}
		else
		{
			cords.push_back(Point<int>(currentY, i));
		}
	}
	for (int i = currentX - 1; i >= 0; --i)
	{
		if (chessBoard[currentY][i] != nullptr)
		{
			if (chessBoard[currentY][i]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(currentY, i));
			break;
		}
		else
		{
			cords.push_back(Point<int>(currentY, i));
		}
	}

	for (int i = currentY + 1, j = currentX + 1; i < N && j < N; i++, j++)
	{
		if (chessBoard[i][j] != nullptr)
		{
			if (chessBoard[i][j]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, j));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, j));
		}
	}
	for (int i = currentY + 1, j = currentX - 1; i < N && j >= 0; i++, j--)
	{
		if (chessBoard[i][j] != nullptr)
		{
			if (chessBoard[i][j]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, j));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, j));
		}
	}
	for (int i = currentY - 1, j = currentX + 1; i >= 0 && j < N; i--, j++)
	{
		if (chessBoard[i][j] != nullptr)
		{
			if (chessBoard[i][j]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, j));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, j));
		}
	}
	for (int i = currentY - 1, j = currentX - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (chessBoard[i][j] != nullptr)
		{
			if (chessBoard[i][j]->isWhite() != this->isWhite())
				cords.push_back(Point<int>(i, j));
			break;
		}
		else
		{
			cords.push_back(Point<int>(i, j));
		}
	}

	if (!control)
		return cords;

	removeIllegalMoves(chessBoard, cords, king);

	return cords;
}
