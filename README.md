# ChessGame

The game of chess, or chess, is a board game between two players on either side of a board called a "chessboard" made up of sixty-four squares, 32 light and 32 dark, called the white squares and the black boxes. This game was completely recreated in C as part of a university project.

⚠️ All of the code and function comments were designed in French. An English language version is planned later.

## Installation
First of all, make sure you have an IDE or a terminal allowing the compilation and interpretation of the C language (VS Code, CLion, Code::Blocks, ...) as well as the CMake utility to carry out correctly compiling.

Once this is done, download the entire repository and run the CMake utility. Set the source code directory and set the build directory and then generate the build files.

Finally, you just need to write the following commands in a terminal to run the program:

```bash
user@myComputer ~ % cd /build
user@myComputer ~ % make start
user@myComputer ~ % ./start
```

## Features

- [x] Basic functions (empty, get_square, etc)
- [x] Basic display (print_square and print_board)
- [x] FEN rating (write_FEN et read_FEN)
- [x] Color display
- [x] Construction of masks
- [x] Lists of Possible Moves / Lists of Movable Pieces / Lists of Attacking Pieces / List of Takeable Pieces
- [x] Player's gameplay
- [ ] Random gameplay
- [ ] I.A gameplay
- [ ] History of pieces taken
- [x] King in check
- [ ] Time system

## Contributing

Special thanks to Khamzat Baoudinov with whom I collaborated for the realization of this project.

If you want to contribute to the project, make sure the project is still executable after creating the CMake files.

## License

[MIT](https://choosealicense.com/licenses/mit/)
