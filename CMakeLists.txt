# CMakeLists.txt
# le dièese commence une ligne de commentaire
project(projet) # nom du projet
set(SRC board/board.cpp mask/mask.cpp view/view.cpp game/game.cpp )
set(HEADER board/board.hpp mask/mask.hpp types/types.hpp view/view.hpp game/game.hpp)
add_executable(start main.cpp ${SRC} ${HEADER})
add_executable(test test.cpp ${SRC} ${HEADER})
