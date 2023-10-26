#include "../catch2/catch.hpp"
#include "Position.h"
#include "TypeCase.h"
#include "Game.h"

#define RUN_TEST 0

#if RUN_TEST


//TEST_CASE("test"){
//    SECTION("test instanciation"){
//        std::array<int,5> a = {1,2,3,4,5};
//        REQUIRE(a.size() == 5);
//        for(int i = 0; i < a.size(); i++)
//            REQUIRE(a[i] == i + 1);
//    }
//}

TEST_CASE("TypeCase"){
    TypeCase::Element el1 = TypeCase::BABA;
    TypeCase::Element el2 = TypeCase::Element::BABA;

    REQUIRE(el1 == el2);



    SECTION("CONNECTOR"){
        TypeCase tp = TypeCase::Connector::IS;
        TypeCase tp2 = TypeCase::Connector::IS;
        TypeCase tp3 = TypeCase::Element::BABA;
        REQUIRE(tp == tp2);
        REQUIRE(tp != tp3);
        REQUIRE(tp.isConnector() == true);
        REQUIRE(tp.isElement() == false);
        REQUIRE(tp.isElement_Text() == false);
        REQUIRE(tp.isAction() == false);
    }
    SECTION("Element"){
        TypeCase tp1 = TypeCase::Element::BABA;
        TypeCase tp2 = TypeCase::Element::FLAG;
        TypeCase tp3 = TypeCase::Element::FLAG;
        REQUIRE(tp1 != tp2);
        REQUIRE(tp2 == tp3);
        REQUIRE(tp1.isConnector() == false);
        REQUIRE(tp1.isElement() == true);
        REQUIRE(tp1.isElement_Text() == false);
        REQUIRE(tp1.isAction() == false);
        REQUIRE(tp2.isConnector() == false);
        REQUIRE(tp2.isElement() == true);
        REQUIRE(tp2.isElement_Text() == false);
        REQUIRE(tp2.isAction() == false);
        REQUIRE(tp1.isBaba() == true);
        REQUIRE(tp3.isFlag() == true);
        REQUIRE(tp1.isBabaText() == false);
        REQUIRE(tp3.isFlagText() == false);
        REQUIRE(typeid(tp3.getElement()) == typeid(TypeCase::Element));
        REQUIRE(typeid(tp3.getElement()) != typeid(TypeCase::Element_Text));
    }
    SECTION("Element_Text"){
        TypeCase tp1 = TypeCase::Element_Text::BABA_TEXT;
        TypeCase tp2 = TypeCase::Element_Text::FLAG_TEXT;
        TypeCase tp3 = TypeCase::Element_Text::FLAG_TEXT;
        REQUIRE(tp1 != tp2);
        REQUIRE(tp2 == tp3);
        REQUIRE(tp1.isConnector() == false);
        REQUIRE(tp1.isElement() == false);
        REQUIRE(tp1.isElement_Text() == true);
        REQUIRE(tp1.isAction() == false);
        REQUIRE(tp2.isConnector() == false);
        REQUIRE(tp2.isElement() == false);
        REQUIRE(tp2.isElement_Text() == true);
        REQUIRE(tp2.isAction() == false);
        REQUIRE(tp1.isBabaText() == true);
        REQUIRE(tp3.isFlagText() == true);
    }
    SECTION("Action"){
        TypeCase tp1 = TypeCase::Action::STOP;
        TypeCase tp2 = TypeCase::Action::YOU;
        TypeCase tp3 = TypeCase::Action::YOU;
        REQUIRE(tp1 != tp2);
        REQUIRE(tp2 == tp3);
        REQUIRE(tp1.isConnector() == false);
        REQUIRE(tp1.isElement() == false);
        REQUIRE(tp1.isElement_Text() == false);
        REQUIRE(tp1.isAction() == true);
        REQUIRE(tp2.isConnector() == false);
        REQUIRE(tp2.isElement() == false);
	REQUIRE(tp2.isElement_Text() == false);
        REQUIRE(tp2.isAction() == true);
    }
}

TEST_CASE("Position"){
    Position pos1 = Position(2,3);
    Position pos2 = Position(2,3);
    Position pos3 = pos1;
    Position pos4 = Position(8,8);
    Position pos5 = Position(4,4);
    Position pos6 = pos5 + pos5;
    REQUIRE(pos1.equals(pos2));
    REQUIRE(pos1.equals(pos3));
    REQUIRE(!pos1.equals(pos4));
    REQUIRE((pos5 + pos5).equals(pos4));
    REQUIRE(pos6.equals(pos4));
}


TEST_CASE("Square"){
    Position pos = Position(2,3);
    Square s1 = Square(pos);
    REQUIRE(s1.isAction() == false);
    REQUIRE(s1.isBaba() == false);
    REQUIRE(s1.isBabaText() == false);
    REQUIRE(s1.isRockText() == false);
    REQUIRE(s1.isMetal() == false);
    REQUIRE(s1.isWin() == false);
    TypeCase tpMetal = TypeCase::Element::METAL;
    TypeCase tpBaba = TypeCase::Element::BABA;
    TypeCase tpRock_Text = TypeCase::Element_Text::ROCK_TEXT;
    TypeCase tpFlag_Text = TypeCase::Element_Text::FLAG_TEXT;
    TypeCase tpConnector = TypeCase::Connector::IS;
    TypeCase tpYou = TypeCase::Action::YOU;
    TypeCase tpPush = TypeCase::Action::PUSH;
    TypeCase tpWin = TypeCase::Action::WIN;
    TypeCase tpStop = TypeCase::Action::STOP;
    TypeCase tpSink = TypeCase::Action::SINK;

    SECTION("Add and remove TypeCase from a square"){
        s1.addTypeCase(tpMetal);
        REQUIRE(s1.isMetal() == true);
        s1.removeTypeCase(TypeCase::METAL);
        REQUIRE(s1.isMetal() == false);
        s1.addTypeCase(tpBaba);
        REQUIRE(s1.isBaba() == true);
        REQUIRE(s1.isBabaText() == false);
        //New rule created BABA is YOU
        s1.update(TypeCase::Element::BABA,TypeCase::Action::YOU, true);
        REQUIRE(s1.isAttrYou() == true);
        REQUIRE(s1.isPlayer() == true);
        s1.update(TypeCase::Element::METAL, TypeCase::Action::STOP, true);
        REQUIRE(s1.isAttrStop() == false);
        s1.addTypeCase(TypeCase::Element::METAL);
        s1.update(TypeCase::Element::METAL, TypeCase::Action::STOP, true);
        REQUIRE(s1.isAttrStop() == true);
    }

    SECTION("Return check"){
        Position pos2 = Position(1,1);
        Square s2 = Square(pos2);
        s2.addTypeCase(tpRock_Text);
        REQUIRE(s2.getElement_Text() == TypeCase::Element_Text::ROCK_TEXT);

        Position pos3 = Position(2,2);
        Square s3 = Square(pos3);
        s3.addTypeCase(tpSink);
        REQUIRE(s3.getAction() == TypeCase::Action::SINK);
    }
}



TEST_CASE("Board"){
    Board b = Board();
    SECTION("Contains"){
        REQUIRE(b.contains(Position(0,0)) == true);
        REQUIRE(b.contains(Position(5,5)) == true);
        REQUIRE(b.contains(Position(17,17)) == true);
        REQUIRE(b.contains(Position(18,18)) == false);
        REQUIRE(b.contains(Position(-1,-5)) == false);
        REQUIRE(b.contains(Position(-1,5)) == false);
        REQUIRE(b.contains(Position(5,-1)) == false);
        REQUIRE(b.contains(Position(25,56)) == false);
        REQUIRE(b.contains(Position(35,7)) == false);
        REQUIRE(b.contains(Position(5,87)) == false);
    }
    SECTION("finding stuff"){
        REQUIRE(b.isBaba(Position(5,8)) == true);
        REQUIRE(b.isBaba(Position(7,8)) == false);
        REQUIRE(b.isBaba(Position(25,75)) == false);
        REQUIRE(b.isFlag(Position(12,8)) == true);
        REQUIRE(b.isFlag(Position(5,8)) == false);
        REQUIRE(b.isWall(Position(10,10)) == true);
        REQUIRE(b.isWall(Position(12,8)) == false);

        REQUIRE(b.isElement(Position(12,8)) == true);
        REQUIRE(b.isElement(Position(10,10)) == true);
        REQUIRE(b.isElement(Position(5,8)) == true);

        REQUIRE(b.isFlagText(Position(11,12)) == true);
        REQUIRE(b.isFlagText(Position(12,8)) == false);
        REQUIRE(b.isFlagText(Position(12,8)) == false);
        REQUIRE(b.isElement_Text(Position(4,12)) == true);
        REQUIRE(b.isElement_Text(Position(4,4)) == true);
        REQUIRE(b.isElement_Text(Position(11,4)) == true);

        REQUIRE(b.isConnector(Position(5,12)) == true);
        REQUIRE(b.isConnector(Position(10,10)) == false);

        REQUIRE(b.isAction(Position(6,12)) == true);
        REQUIRE(b.isYou(Position(6,12)) == true);
        REQUIRE(b.isAction(Position(6,4)) == true);
        REQUIRE(b.isStop(Position(6,4)) == true);

        Position pos = Position(1,1);   //Nothing
        REQUIRE(b.isBaba(pos) == false);
        REQUIRE(b.isFlag(pos) == false);
        REQUIRE(b.isWall(pos) == false);
        REQUIRE(b.isElement(pos) == false);
        REQUIRE(b.isFlagText(pos) == false);
        REQUIRE(b.isElement_Text(pos) == false);
        REQUIRE(b.isConnector(pos) == false);
        REQUIRE(b.isAction(pos) == false);
        REQUIRE(b.isStop(pos) == false);
        REQUIRE(b.isGrass(pos) == false);}

    SECTION("New level"){
        b.clear();
        b.setUp(1);
        REQUIRE(b.isBaba(Position(5,8)) == false); //Old Pos
        REQUIRE(b.isBaba(Position(12,8)) == true);

        REQUIRE(b.contains(Position(0,0)) == true);
        REQUIRE(b.contains(Position(5,5)) == true);
        REQUIRE(b.contains(Position(17,17)) == true);
        REQUIRE(b.contains(Position(18,18)) == false);
        REQUIRE(b.contains(Position(-1,-5)) == false);
        REQUIRE(b.contains(Position(-1,5)) == false);
        REQUIRE(b.contains(Position(5,-1)) == false);
        REQUIRE(b.contains(Position(25,56)) == false);
        REQUIRE(b.contains(Position(35,7)) == false);
        REQUIRE(b.contains(Position(5,87)) == false);
    }
}



TEST_CASE("Game"){
    cout << endl << "Start of Game test" << endl;
    Game game = Game();
    game.setUpRules();

    REQUIRE(game.getBoardSize() == 18);
    REQUIRE(game.getBoardSize() != 11);
    REQUIRE(game.getBoardSize() != 494);

    SECTION("isCurrentPlayer"){
        TypeCase elt = game.isCurrentPlayer();
        std::vector<Position> v = game.positionsTypeList(elt);
        REQUIRE(v.size() == 1);
        //Move player, check if game.positionsTypeList(elt) return the correct list (shouldn't right now)
        //Change rules to make something else the player and recheck
        game.move(TypeCase::Element::BABA,Position(5,8),Position(5,9));

    }
    SECTION(""){

    }
    SECTION(""){

    }
}
#endif

