cmake_minimum_required(VERSION 3.17)
project(CS_236_Lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS_236_Lab4 main.cpp CommentAutoma.cpp DatalogProgram.cpp Database.cpp Interpreter.cpp IDAutoma.cpp Lexer.cpp MatcherAutomaton.cpp Parser.cpp Parameter.cpp Predicate.cpp Relation.cpp Rule.cpp StringAutoma.cpp Token.cpp UndefinedStringAutoma.cpp UndefinedCommentAutoma.cpp Tuple.cpp)