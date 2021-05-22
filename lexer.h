//                 lexer.h 2021
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
class tLexer:public tBaseLexer{
public:
  // конструктор
  tLexer() : tBaseLexer() {

    // lab4
  addstr(Adec, 0, "+-", 2);
  addrange(Adec, 0, '0', '9', 1);
  addrange(Adec, 1, '0', '9', 1);
  addrange(Adec, 2, '0', '9', 1);
  addstr(Adec, 1, ".", 3);
  addrange(Adec, 3, '0', '9', 4);
  addrange(Adec, 4, '0', '9', 4);
  addstr(Adec, 4, "eE", 5);
  addstr(Adec, 5, "+-", 7);
  addrange(Adec, 5, '0', '9', 6);
  addrange(Adec, 7, '0', '9', 6);
  Adec.final(6);


  //создать автоматы:
  // 0-9
  // a-z
  // A-Z
  //  -
  //  ?
  //  !

  // идентификатор !--    0-9*? -*?
  addrange(Aid, 0, 'a', 'z', 1);
  addrange(Aid, 0, 'A', 'Z', 1);
  addstr(Aid, 0, "!", 2);
  addstr(Aid, 0, "?", 3);

  addrange(Aid, 1, '0', '9', 1);
  addrange(Aid, 1, 'a', 'z', 1);
  addrange(Aid, 1, 'A', 'Z', 1);
  addstr(Aid, 1, "!", 2);
  addstr(Aid, 1, "?", 3);
  addstr(Aid, 1, "-", 1);

  addrange(Aid, 2, '0', '9', 1);
  addrange(Aid, 2, 'a', 'z', 1);
  addrange(Aid, 2, 'A', 'Z', 1);
  addstr(Aid, 2, "!", 1);
  addstr(Aid, 2, "?", 3);
  addstr(Aid, 2, "-", 4);

  addrange(Aid, 3, '0', '9', 1);
  addrange(Aid, 3, 'a', 'z', 1);
  addrange(Aid, 3, 'A', 'Z', 1);
  addstr(Aid, 3, "!", 1);
  addstr(Aid, 3, "?", 3);
  addstr(Aid, 3, "-", 1);

  addrange(Aid, 4, '0', '9', 1);
  addrange(Aid, 4, 'a', 'z', 1);
  addrange(Aid, 4, 'A', 'Z', 1);
  addstr(Aid, 4, "!", 1);
  addstr(Aid, 4, "?", 3);

  Aid.final(1);
  Aid.final(2);


  // last check
//  3/ 1:  $id  good
//  4/ 1:  $id  eE
//  5/ 1:    ?  count-change
//  6/ 1:    ?  !
//  7/ 1:  $id  A!
//  8/ 1:  $id  abc123
//  9/ 1:  $id  ?!
// 10/ 1:    ?  a---b
// 11/ 1:    ?  a--!b
// 12/ 1:    ?  a--?b
// 13/ 1:    ?  a-!-b
// 14/ 1:    ?  a-!!b
// 15/ 1:    ?  a-!?b
// 16/ 1:    ?  a-?-b
// 17/ 1:    ?  a-?!b
// 18/ 1:    ?  a-??b
// 19/ 1:    ?  a!--b
// 20/ 1:    ?  a!-!b
// 21/ 1:    ?  a!-?b
// 22/ 1:    ?  a!!-b
// 23/ 1:  $id  a!!!b
// 24/ 1:  $id  a!!?b
// 25/ 1:    ?  a!?-b
// 26/ 1:  $id  a!?!b
// 27/ 1:  $id  a!??b
// 28/ 1:    ?  a?--b
// 29/ 1:    ?  a?-!b
// 30/ 1:    ?  a?-?b
// 31/ 1:    ?  a?!-b
// 32/ 1:  $id  a?!!b
// 33/ 1:  $id  a?!?b
// 34/ 1:    ?  a??-b
// 35/ 1:  $id  a??!b
// 36/ 1:  $id  a???b
// 37/ 1:    ?  123abc
// 38/ 1:    ?  -c
// 39/ 0:    ?  %a!


  // идентификатор предиката ?!    0-9*{?}
  // 0-9
  // a-z
  // A-Z
  //  -
  //  ?
  //  !

  addrange(Aidq, 0, 'a', 'z', 1);
  addrange(Aidq, 0, 'A', 'Z', 1);
  addstr(Aidq, 0, "!", 2);
  addstr(Aidq, 0, "-", 1);
  addstr(Aidq, 0, "?", 2);

  addrange(Aidq, 1, '0', '9', 1);
  addrange(Aidq, 1, 'a', 'z', 1);
  addrange(Aidq, 1, 'A', 'Z', 1);
  addstr(Aidq, 1, "-", 1);
  addstr(Aidq, 1, "!", 1);
  addstr(Aidq, 1, "?", 2);

  addrange(Aidq, 2, '0', '9', 1);
  addrange(Aidq, 2, 'a', 'z', 1);
  addrange(Aidq, 2, 'A', 'Z', 1);
  addstr(Aidq, 2, "-", 1);
  addstr(Aidq, 2, "?", 2);

  Aidq.final(2);
}
};
#endif