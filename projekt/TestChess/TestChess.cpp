#include "CppUnitTest.h"
#include "../21L-PROI_Szachy/Point.h"
#include "Pieces.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestChess
{
	TEST_CLASS(TestChess)
	{
	public:
		
		TEST_METHOD(TestPointConstructorDefault)
		{
			Point<int> p;
			Assert::AreEqual(p.getX(), 0);
			Assert::AreEqual(p.getY(), 0);
		}
		TEST_METHOD(TestPointConstructorGivenCords)
		{
			Point<int> p(2, 3);
			Assert::AreEqual(p.getY(), 2);
			Assert::AreEqual(p.getX(), 3);
		}
		TEST_METHOD(TestPointConstructorCopy)
		{
			Point<int> p(2, 3);
			Point<int> p2(p);
			Assert::AreEqual(p.getY(), 2);
			Assert::AreEqual(p.getX(), 3);
			Assert::AreEqual(p2.getY(), 2);
			Assert::AreEqual(p2.getX(), 3);
		}
		TEST_METHOD(TestPointGetY)
		{
			Point<int> p(3, 5);
			Point<int> p2(6, 6);
			Assert::AreEqual(p.getY(), 3);
			Assert::AreEqual(p2.getY(), 6);
		}
		TEST_METHOD(TestPointGetX)
		{
			Point<int> p(3, 5);
			Point<int> p2(6, 6);
			Assert::AreEqual(p.getX(), 5);
			Assert::AreEqual(p2.getX(), 6);
		}
		TEST_METHOD(TestPointSetNewCords)
		{
			Point<int> p(3, 5);
			Assert::AreEqual(p.getY(), 3);
			Assert::AreEqual(p.getX(), 5);
			p.setNewCoords(4, 7);
			Assert::AreEqual(p.getY(), 4);
			Assert::AreEqual(p.getX(), 7);
		}
		TEST_METHOD(TestPointEqualOperator)
		{
			Point<int> p(4, 6);
			Point<int> p2(4, 6);
			Assert::IsTrue(p == p2);
			p2.setNewCoords(4, 3);
			Assert::IsFalse(p == p2);
		}
		TEST_METHOD(TestPointNotEqualOperator)
		{
			Point<int> p(4, 6);
			Point<int> p2(4, 6);
			Assert::IsFalse(p != p2);
			p2.setNewCoords(9, 4);
			Assert::IsTrue(p != p2);
		}
		TEST_METHOD(TestChessPieceGetY)
		{
			ChessPiece* pawn = new Pawn(4, 5, true, true);
			Assert::AreEqual(pawn->getY(), 4);
			delete pawn;
		}
		TEST_METHOD(TestChessPieceGetX)
		{
			ChessPiece* pawn = new Pawn(0, 0, true, true);
			Assert::AreEqual(pawn->getX(), 0);
			delete pawn;
		}
		TEST_METHOD(TestChessPieceIsWhite)
		{
			ChessPiece* pawn = new Pawn(0, 0, true, true);
			Assert::IsTrue(pawn->isWhite());
			delete pawn;
			pawn = new Pawn(0, 0, false, true);
			Assert::IsFalse(pawn->isWhite());
			delete pawn;
		}
		TEST_METHOD(TestChessPieceIsOnTop)
		{
			ChessPiece* pawn = new Pawn(0, 0, true, false);
			Assert::IsFalse(pawn->isOnTop());
			delete pawn;
			pawn = new Pawn(0, 0, false, true);
			Assert::IsTrue(pawn->isOnTop());
			delete pawn;
		}
		TEST_METHOD(TestChessPieceWasMoved)
		{
			ChessPiece* pawn = new Pawn(3, 4, true, true);
			ChessPiece* chessBoard[8][8]{};
			chessBoard[3][4] = pawn;
			std::list<std::string> listOfMoves;
			Assert::IsFalse(pawn->wasMoved());
			pawn->move(3, 6, chessBoard, listOfMoves);
			Assert::IsTrue(pawn->wasMoved());
		}
		TEST_METHOD(TestChessPieceMove)
		{
			ChessPiece* pawn = new Pawn(3, 5, true, true);
			ChessPiece* chessBoard[8][8]{};
			chessBoard[3][5] = pawn;
			std::list<std::string> listOfMoves;
			Assert::AreEqual(pawn->getY(), 3);
			Assert::AreEqual(pawn->getX(), 5);
			pawn->move(3, 6, chessBoard, listOfMoves);
		}
		TEST_METHOD(TestPawnConstructor)
		{		
			ChessPiece* pawn = new Pawn(1, 7, true, false);
			Assert::AreEqual(pawn->getY(), 1);
			Assert::AreEqual(pawn->getX(), 7);
			Assert::AreEqual(pawn->isWhite(), true);
			Assert::AreEqual(pawn->isOnTop(), false);
			Assert::AreEqual(pawn->wasMoved(), false);			
		}
		TEST_METHOD(TestBishopConstructor)
		{		
			ChessPiece* bishop = new Bishop(6, 7, true, true);
			Assert::AreEqual(bishop->getY(), 6);
			Assert::AreEqual(bishop->getX(), 7);
			Assert::AreEqual(bishop->isWhite(), true);
			Assert::AreEqual(bishop->isOnTop(), true);
			Assert::AreEqual(bishop->wasMoved(), false);			
		}
		TEST_METHOD(TestKnightConstructor)
		{		
			ChessPiece* knight = new Knight(2, 5, true, true);
			Assert::AreEqual(knight->getY(), 2);
			Assert::AreEqual(knight->getX(), 5);
			Assert::AreEqual(knight->isWhite(), true);
			Assert::AreEqual(knight->isOnTop(), true);
			Assert::AreEqual(knight->wasMoved(), false);
		}
		TEST_METHOD(TestRookConstructor)
		{		
			ChessPiece* rook = new Rook(3, 4, false, false);
			Assert::AreEqual(rook->getY(), 3);
			Assert::AreEqual(rook->getX(), 4);
			Assert::AreEqual(rook->isWhite(), false);
			Assert::AreEqual(rook->isOnTop(), false);
			Assert::AreEqual(rook->wasMoved(), false);			
		}
		TEST_METHOD(TestQueenConstructor)
		{		
			ChessPiece* queen = new Queen(5, 5, false, false);
			Assert::AreEqual(queen->getY(), 5);
			Assert::AreEqual(queen->getX(), 5);
			Assert::AreEqual(queen->isWhite(), false);
			Assert::AreEqual(queen->isOnTop(), false);
			Assert::AreEqual(queen->wasMoved(), false);			
		}
		TEST_METHOD(TestKingConstructor)
		{
			ChessPiece* king = new King(7, 4, false, true);
			Assert::AreEqual(king->getY(), 7);
			Assert::AreEqual(king->getX(), 4);
			Assert::AreEqual(king->isWhite(), false);
			Assert::AreEqual(king->isOnTop(), true);
			Assert::AreEqual(king->wasMoved(), false);
		}
		TEST_METHOD(TestPawnAvailableMovesStartPos)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[1][4] = new Pawn(1, 4, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[1][4]->availableMoves(chessBoard, king).size(), (size_t)2);
		}
		TEST_METHOD(TestPawnAvailableMovesOutOfStart)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[2][4] = new Pawn(2, 4, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[2][4]->availableMoves(chessBoard, king).size(), (size_t)1);
		}
		TEST_METHOD(TestPawnAvailableMovesBeat)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[2][4] = new Pawn(2, 4, true, true);
			chessBoard[3][5] = new Pawn(3, 5, false, true);
			chessBoard[3][3] = new Pawn(3, 3, false, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[2][4]->availableMoves(chessBoard, king).size(), (size_t)3);
		}
		TEST_METHOD(TestPawnAvailableMovesStartBeat)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[1][4] = new Pawn(1, 4, true, true);
			chessBoard[2][5] = new Pawn(2, 5, false, true);
			chessBoard[2][3] = new Pawn(2, 3, false, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[1][4]->availableMoves(chessBoard, king).size(), (size_t)4);
		}
		TEST_METHOD(TestPawnAvailableMovesStartNoMoves)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[1][4] = new Pawn(1, 4, true, true);
			chessBoard[2][4] = new Pawn(2, 4, false, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[1][4]->availableMoves(chessBoard, king).size(), (size_t)0);
		}
		TEST_METHOD(TestPawnAvailableMovesStartBeatOnly)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[1][4] = new Pawn(1, 4, true, true);
			chessBoard[2][4] = new Pawn(2, 4, false, true);
			chessBoard[2][3] = new Pawn(2, 3, false, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[1][4]->availableMoves(chessBoard, king).size(), (size_t)1);
		}
		TEST_METHOD(TestPawnAvailableMovesStartOneMove)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[1][4] = new Pawn(1, 4, true, true);
			chessBoard[3][4] = new Pawn(3, 4, false, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[1][4]->availableMoves(chessBoard, king).size(), (size_t)1);
		}
		TEST_METHOD(TestBishopAvailableMovesStart)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][2] = new Bishop(0, 2, true, true);
			chessBoard[1][1] = new Pawn(1, 1, true, true);
			chessBoard[1][3] = new Pawn(1, 3, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][2]->availableMoves(chessBoard, king).size(), (size_t)0);
		}
		TEST_METHOD(TestBishopAvailableMovesStartPos)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][2] = new Bishop(0, 2, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][2]->availableMoves(chessBoard, king).size(), (size_t)7);
		}
		TEST_METHOD(TestBishopAvailableMovesStartPosRightBlocked)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][2] = new Bishop(0, 2, true, true);
			chessBoard[1][3] = new Pawn(1, 3, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][2]->availableMoves(chessBoard, king).size(), (size_t)2);
		}
		TEST_METHOD(TestBishopAvailableMovesStartPosLeftBlocked)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][2] = new Bishop(0, 2, true, true);
			chessBoard[1][1] = new Pawn(1, 1, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][2]->availableMoves(chessBoard, king).size(), (size_t)5);
		}
		TEST_METHOD(TestBishopAvailableMovesStartPosLeftBlockedOpponent)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][2] = new Bishop(0, 2, true, true);
			chessBoard[1][1] = new Pawn(1, 1, false, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][2]->availableMoves(chessBoard, king).size(), (size_t)6);
		}
		TEST_METHOD(TestBishopAvailableMovesMiddleBoard)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[3][5] = new Bishop(3, 5, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[3][5]->availableMoves(chessBoard, king).size(), (size_t)11);
		}
		TEST_METHOD(TestRookAvailableMovesStartPos)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][0] = new Rook(0, 0, true, true);
			chessBoard[1][0] = new Pawn(1, 0, true, true);
			chessBoard[0][1] = new Pawn(0, 1, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][0]->availableMoves(chessBoard, king).size(), (size_t)0);
		}
		TEST_METHOD(TestRookAvailableMovesStartPosDownBlocked)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][0] = new Rook(0, 0, true, true);
			chessBoard[1][0] = new Pawn(1, 0, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][0]->availableMoves(chessBoard, king).size(), (size_t)2);
		}
		TEST_METHOD(TestRookAvailableMovesStartPosRightBlocked)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][0] = new Rook(0, 0, true, true);
			chessBoard[0][1] = new Pawn(0, 1, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][0]->availableMoves(chessBoard, king).size(), (size_t)7);
		}
		TEST_METHOD(TestRookAvailableMovesStartPosOpponentBlocked)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][0] = new Rook(0, 0, true, true);
			chessBoard[0][1] = new Pawn(0, 1, false, true);
			chessBoard[1][0] = new Pawn(1, 0, false, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][0]->availableMoves(chessBoard, king).size(), (size_t)2);
		}
		TEST_METHOD(TestRookAvailableMovesMiddleBoard)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[4][4] = new Rook(4, 4, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[4][4]->availableMoves(chessBoard, king).size(), (size_t)14);
		}
		TEST_METHOD(TestKnightAvailAbleMovesStartPos)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][6] = new Knight(0, 6, true, true);
			chessBoard[1][4] = new Pawn(1, 4, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][6]->availableMoves(chessBoard, king).size(), (size_t)2);
		}
		TEST_METHOD(TestKnightAvailAbleMovesStartPosNotBlocked)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][6] = new Knight(0, 6, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][6]->availableMoves(chessBoard, king).size(), (size_t)3);
		}
		TEST_METHOD(TestKnightAvailAbleMovesMiddleBoard)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[4][4] = new Knight(4, 4, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[4][4]->availableMoves(chessBoard, king).size(), (size_t)8);
		}
		TEST_METHOD(TestQueenAvailableMovesStartPos)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][4] = new Queen(0, 4, true, true);
			chessBoard[1][3] = new Pawn(1, 3, true, true);
			chessBoard[1][4] = new Pawn(1, 4, true, true);
			chessBoard[1][5] = new Pawn(1, 5, true, true);
			chessBoard[0][5] = new Bishop(0, 5, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][4]->availableMoves(chessBoard, king).size(), (size_t)0);
		}
		TEST_METHOD(TestQueenAvailableMovesStartPosNotBlocked)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][4] = new Queen(0, 4, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][4]->availableMoves(chessBoard, king).size(), (size_t)17);
		}
		TEST_METHOD(TestQueenAvailableMovesStartPosOpponent)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[0][4] = new Queen(0, 4, true, true);
			chessBoard[0][5] = new Pawn(1, 3, false, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][4]->availableMoves(chessBoard, king).size(), (size_t)15);
		}
		TEST_METHOD(TestQueenAvailableMovesStartMiddleBoard)
		{
			ChessPiece* chessBoard[8][8]{};
			chessBoard[4][4] = new Queen(4, 4, true, true);
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[4][4]->availableMoves(chessBoard, king).size(), (size_t)27);
		}
		TEST_METHOD(TestKingAvailableMethodsStartPos)
		{
			ChessPiece* chessBoard[8][8]{};
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::AreEqual(chessBoard[0][3]->availableMoves(chessBoard, king).size(), (size_t)5);
		}
		TEST_METHOD(TestKingAvailableMethodsMiddleBoard)
		{
			ChessPiece* chessBoard[8][8]{};
			ChessPiece* king = chessBoard[4][4] = new King(4, 4, true, true);
			Assert::AreEqual(chessBoard[4][4]->availableMoves(chessBoard, king).size(), (size_t)8);
		}
		TEST_METHOD(TestKingAvailableMethodsPossibleCheck)
		{
			ChessPiece* chessBoard[8][8]{};
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			chessBoard[1][3] = new Pawn(1, 3, false, false);
			Assert::AreEqual(chessBoard[0][3]->availableMoves(chessBoard, king).size(), (size_t)3);
		}
		TEST_METHOD(TestKingChecked)
		{
			ChessPiece* chessBoard[8][8]{};
			ChessPiece* king = chessBoard[0][3] = new King(0, 3, true, true);
			Assert::IsFalse(King::isChecked(chessBoard, king));
			chessBoard[1][2] = new Pawn(1, 2, false, false);
			Assert::IsTrue(King::isChecked(chessBoard, king));
		}
		TEST_METHOD(TestCastling1)
		{
			bool whiteTurn = false;
			ChessPiece* chessBoard[8][8]{};
			std::list<std::string> listOfMoves;
			King* king = new King(0, 3, true, true);
			chessBoard[0][3] = king;
			chessBoard[0][2] = new Bishop(0, 2, true, true);
			ChessPiece* rook = chessBoard[0][7] = new Rook(0, 7, true, true);
			king->castling(chessBoard, king, listOfMoves, whiteTurn);
			Assert::AreEqual(king->getY(), 0);
			Assert::AreEqual(king->getX(), 5);
			Assert::AreEqual(rook->getY(), 0);
			Assert::AreEqual(rook->getX(), 4);
		}
		TEST_METHOD(TestCastling2)
		{
			bool whiteTurn = false;
			ChessPiece* chessBoard[8][8]{};
			std::list<std::string> listOfMoves;
			King* king = new King(0, 3, true, true);
			chessBoard[0][3] = king;
			chessBoard[0][4] = new Queen(0, 4, true, true);
			ChessPiece* rook = chessBoard[0][0] = new Rook(0, 0, true, true);
			king->castling(chessBoard, king, listOfMoves, whiteTurn);
			Assert::AreEqual(king->getY(), 0);
			Assert::AreEqual(king->getX(), 1);
			Assert::AreEqual(rook->getY(), 0);
			Assert::AreEqual(rook->getX(), 2);
		}
		TEST_METHOD(TestCastling3)
		{
			bool whiteTurn = false;
			ChessPiece* chessBoard[8][8]{};
			std::list<std::string> listOfMoves;
			King* king = new King(7, 3, false, false);
			chessBoard[7][3] = king;
			chessBoard[7][2] = new Bishop(7, 2, false, false);
			ChessPiece* rook = chessBoard[7][7] = new Rook(7, 7, false, false);
			king->castling(chessBoard, king, listOfMoves, whiteTurn);
			Assert::AreEqual(king->getY(), 7);
			Assert::AreEqual(king->getX(), 5);
			Assert::AreEqual(rook->getY(), 7);
			Assert::AreEqual(rook->getX(), 4);
		}
		TEST_METHOD(TestCastling4)
		{
			bool whiteTurn = false;
			ChessPiece* chessBoard[8][8]{};
			std::list<std::string> listOfMoves;
			King* king = new King(7, 3, false, false);
			chessBoard[7][3] = king;
			chessBoard[7][4] = new Queen(7, 4, false, false);
			ChessPiece* rook = chessBoard[7][0] = new Rook(7, 0, false, false);
			king->castling(chessBoard, king, listOfMoves, whiteTurn);
			Assert::AreEqual(king->getY(), 7);
			Assert::AreEqual(king->getX(), 1);
			Assert::AreEqual(rook->getY(), 7);
			Assert::AreEqual(rook->getX(), 2);
		}
	};
}