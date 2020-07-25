//
// Created by LioraPinkhasov on 23/07/2020.
//
/*
#include "doctest.h"
#include "FamilyTree.hpp"


#include <string>
using namespace std;

family::Tree T("forest");
family::Tree T2("amazon");


TEST_CASE("addMother") {
    //add mothers T1
    T.addMother("super","tex");
    T.addMother("tex","liquid");
    T.addMother("liquid","glue");
    T.addMother("glue","hotglue");
    T.addMother("hotglue","woodglue");
    T.addMother("woodglue","caramicglue");
    T.addMother("carmicglue","patternglue");
    T.addMother("patternglue","chocolateglue");
    T.addMother("chocolateglue","cornglue");
    T.addMother("cornglue","soyaglue");
    T.addMother("soyaglue","honeyglue");
    T.addMother("honeyglue","gumglue");

    //define relation
            CHECK(T.relation("tex") == string("mother"));
            CHECK(T.relation("liquid") == string("mother"));
            CHECK(T.relation("glue") == string("mother"));
            CHECK(T.relation("hotglue") == string("mother"));
            CHECK(T.relation("woodglue") == string("mother"));
            CHECK(T.relation("carmicglue") == string("mother"));
            CHECK(T.relation("patternglue") == string("mother"));
            CHECK(T.relation("chocolateglue") == string("mother"));
            CHECK(T.relation("cornglue") == string("mother"));
            CHECK(T.relation("soyaglue") == string("mother"));
            CHECK(T.relation("honeyglue") == string("mother"));
            CHECK(T.relation("gumglue") == string("mother"));

    //find
            CHECK(T.find("Mother") == string("super, tex"));
            CHECK(T.find("Grandmother") == string("super, liquid"));
            CHECK(T.find("Great Grandmother") == string("super, glue"));
            CHECK(T.find("Great Great Grandmother") == string("super, hotglue"));
            CHECK(T.find("Great Great Great Grandmother") == string("super, woodglue"));
            CHECK(T.find("Great Great Great Great Grandmother") == string("super, carmicglue"));
            CHECK(T.find("Great Great Great Great Great Grandmother") == string("super, patternglue"));
            CHECK(T.find("Great Great Great Great Great Great Grandmother") == string("super, chocolateglue"));
            CHECK(T.find("Great Great Great Great Great Great Great Grandmother") == string("super, cornglue"));
            CHECK(T.find("Great Great Great Great Great Great Great Great Grandmother") == string("super, soyaglue"));
            CHECK(T.find("Great Great Great Great Great Great Great Great Great Grandmother") == string("super, honeyglue"));
            CHECK(T.find("Great Great Great Great Great Great Great Great Great Great Grandmother") == string("super, gumglue"));

    //add mother T2
    T2.addMother("super","tex");
    T2.addMother("tex","liquid");
    T2.addMother("liquid","glue");
    T2.addMother("glue","hotglue");
    T2.addMother("hotglue","woodglue");
    T2.addMother("woodglue","caramicglue");
    T2.addMother("carmicglue","patternglue");
    T2.addMother("patternglue","chocolateglue");
    T2.addMother("chocolateglue","cornglue");
    T2.addMother("cornglue","soyaglue");
    T2.addMother("soyaglue","honeyglue");
    T2.addMother("honeyglue","gumglue");

    //define relation
            CHECK(T2.relation("tex") == string("mother"));
            CHECK(T2.relation("liquid") == string("mother"));
            CHECK(T2.relation("glue") == string("mother"));
            CHECK(T2.relation("hotglue") == string("mother"));
            CHECK(T2.relation("woodglue") == string("mother"));
            CHECK(T2.relation("carmicglue") == string("mother"));
            CHECK(T2.relation("patternglue") == string("mother"));
            CHECK(T2.relation("chocolateglue") == string("mother"));
            CHECK(T2.relation("cornglue") == string("mother"));
            CHECK(T2.relation("soyaglue") == string("mother"));
            CHECK(T2.relation("honeyglue") == string("mother"));
            CHECK(T2.relation("gumglue") == string("mother"));

    //find
            CHECK(T2.find("Mother") == string("super, tex"));
            CHECK(T2.find("Grandmother") == string("super, liquid"));
            CHECK(T2.find("Great Grandmother") == string("super, glue"));
            CHECK(T2.find("Great Great Grandmother") == string("super, hotglue"));
            CHECK(T2.find("Great Great Great Grandmother") == string("super, woodglue"));
            CHECK(T2.find("Great Great Great Great Grandmother") == string("super, carmicglue"));
            CHECK(T2.find("Great Great Great Great Great Grandmother") == string("super, patternglue"));
            CHECK(T2.find("Great Great Great Great Great Great Grandmother") == string("super, chocolateglue"));
            CHECK(T2.find("Great Great Great Great Great Great Great Grandmother") == string("super, cornglue"));
            CHECK(T2.find("Great Great Great Great Great Great Great Great Grandmother") == string("super, soyaglue"));
            CHECK(T2.find("Great Great Great Great Great Great Great Great Great Grandmother") == string("super, honeyglue"));
            CHECK(T2.find("Great Great Great Great Great Great Great Great Great Great Grandmother") == string("super, gumglue"));


    //remove
    CHECK_NOTHROW(T.remove("super") );
    CHECK_NOTHROW(T.remove("tex") );
    CHECK_NOTHROW(T.remove("liquid") );
    CHECK_NOTHROW(T.remove("glue") );
    CHECK_NOTHROW(T.remove("hotglue") );
    CHECK_NOTHROW(T.remove("woodglue") );
    CHECK_NOTHROW(T.remove("carmicglue") );
    CHECK_NOTHROW(T.remove("patternglue") );

    //check throw as
    CHECK_THROWS_AS(T.remove("chocolateglue"), const std::exception&);
    CHECK_THROWS_AS(T.remove("cornglue"), const std::exception&);
    CHECK_THROWS_AS(T.remove("soyaglue"), const std::exception&);
    CHECK_THROWS_AS(T.remove("honeyglue"), const std::exception&);
    CHECK_THROWS_AS(T.remove("gumglue"), const std::exception&);

}

TEST_CASE("addFather") {
    //add Father
    T.addFather("Pidgey","Pidgeotto");
    T.addFather("Pidgeotto","Pidgeot");
    T.addFather("Pidgeot","Rattata");
    T.addFather("Rattata","Raticate");
    T.addFather("Raticate","Spearow");
    T.addFather("Spearow","Fearow");
    T.addFather("Fearow","Ekans");
    T.addFather("Ekans","Arbok");
    T.addFather("Arbok","Pikachu");
    T.addFather("Pikachu","Raichu");
    T.addFather("Raichu","Sandshrew");
    T.addFather("Sandshrew","Sandslash");
    T.addFather("Sandslash","Nidoran");
    T.addFather("Nidoran","Nidorina");
    T.addFather("Nidorina","Nidoqueen");
    T.addFather("Nidoqueen","Nidorino");

    //define relation
            CHECK(T.relation("Pidgeotto") == string("Father"));
            CHECK(T.relation("Pidgeot") == string("Father"));
            CHECK(T.relation("Rattata") == string("Father"));
            CHECK(T.relation("Raticate") == string("Father"));
            CHECK(T.relation("Spearow") == string("Father"));
            CHECK(T.relation("Fearow") == string("Father"));
            CHECK(T.relation("Ekans") == string("Father"));
            CHECK(T.relation("Arbok") == string("Father"));
            CHECK(T.relation("Pikachu") == string("Father"));
            CHECK(T.relation("Raichu") == string("Father"));
            CHECK(T.relation("Sandshrew") == string("Father"));
            CHECK(T.relation("Sandslash") == string("Father"));
            CHECK(T.relation("Nidoran") == string("Father"));
            CHECK(T.relation("Nidorina") == string("Father"));
            CHECK(T.relation("Nidoqueen") == string("Father"));
            CHECK(T.relation("Nidorino") == string("Father"));

    //find
            CHECK(T.find("Father") == string("Pidgey, Pidgeotto"));
            CHECK(T.find("GrandFather") == string("Pidgey, Pidgeot"));
            CHECK(T.find("Great GrandFather") == string("Pidgey, Rattata"));
            CHECK(T.find("Great Great GrandFather") == string("Pidgey, Raticate"));
            CHECK(T.find("Great Great Great GrandFather") == string("Pidgey, Spearow"));
            CHECK(T.find("Great Great Great Great GrandFather") == string("Pidgey, Fearow"));
            CHECK(T.find("Great Great Great Great Great GrandFather") == string("Pidgey, Ekans"));
            CHECK(T.find("Great Great Great Great Great Great GrandFather") == string("Pidgey, Arbok"));
            CHECK(T.find("Great Great Great Great Great Great Great GrandFather") == string("Pidgey, Pikachu"));
            CHECK(T.find("Great Great Great Great Great Great Great Great GrandFather") == string("Pidgey, Raichu"));
            CHECK(T.find("Great Great Great Great Great Great Great Great Great GrandFather") == string("Pidgey, Sandshrew"));
            CHECK(T.find("Great Great Great Great Great Great Great Great Great Great GrandFather") == string("Pidgey, Sandslash"));
            CHECK(T.find("Great Great Great Great Great Great Great Great Great Great Great GrandFather") == string("Pidgey, Nidoran"));
            CHECK(T.find("Great Great Great Great Great Great Great Great Great Great Great Great GrandFather") == string("Pidgey, Nidorina"));
            CHECK(T.find("Great Great Great Great Great Great Great Great Great Great Great Great Great GrandFather") == string("Pidgey, Nidoqueen"));
            CHECK(T.find("Great Great Great Great Great Great Great Great Great Great Great Great Great Great GrandFather") == string("Pidgey, Nidorino"));


    //remove
    CHECK_NOTHROW(T.remove("Pidgey") );
    CHECK_NOTHROW(T.remove("Pidgeotto") );
    CHECK_NOTHROW(T.remove("Pidgeot") );
    CHECK_NOTHROW(T.remove("Rattata") );
    CHECK_NOTHROW(T.remove("Raticate") );
    CHECK_NOTHROW(T.remove("Spearow") );
    CHECK_NOTHROW(T.remove("Fearow") );
    CHECK_NOTHROW(T.remove("Ekans") );

    //check throw as
    CHECK_THROWS_AS(T.remove("Arbok"), const std::exception&);
    CHECK_THROWS_AS(T.remove("Pikachu"), const std::exception&);
    CHECK_THROWS_AS(T.remove("Raichu"), const std::exception&);
    CHECK_THROWS_AS(T.remove("Sandshrew"), const std::exception&);
    CHECK_THROWS_AS(T.remove("Sandslash"), const std::exception&);
    CHECK_THROWS_AS(T.remove("Nidoran"), const std::exception&);
    CHECK_THROWS_AS(T.remove("Nidorina"), const std::exception&);
    CHECK_THROWS_AS(T.remove("Nidoqueen"), const std::exception&);
    CHECK_THROWS_AS(T.remove("Nidorino"), const std::exception&);

}*/