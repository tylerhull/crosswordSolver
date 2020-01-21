
% Prolog Sudoku Solver (C) 2007 Markus Triska (triska@gmx.at)
% Public domain code.

:- use_module(library(bounds)).

% Pss is a list of lists representing the game board.

sudoku(Pss) :-
    flatten(Pss, Ps),
    Ps in 1..9,
    maplist(all_different, Pss),
    Pss = [R1,R2,R3,R4,R5,R6,R7,R8,R9],
    columns(R1, R2, R3, R4, R5, R6, R7, R8, R9),
    blocks(R1, R2, R3), blocks(R4, R5, R6), blocks(R7, R8, R9),
    label(Ps).

columns([], [], [], [], [], [], [], [], []).
columns([A|As],[B|Bs],[C|Cs],[D|Ds],[E|Es],[F|Fs],[G|Gs],[H|Hs],[I|Is]) :-
    all_different([A,B,C,D,E,F,G,H,I]),
    columns(As, Bs, Cs, Ds, Es, Fs, Gs, Hs, Is).

blocks([], [], []).
blocks([X1,X2,X3|R1], [X4,X5,X6|R2], [X7,X8,X9|R3]) :-
    all_different([X1,X2,X3,X4,X5,X6,X7,X8,X9]),
    blocks(R1, R2, R3).

%-------------------------------------------------------------------------------
% This block of code will add prolog terms from the user supplied text file 
readFileSee(InputFile) :- seeing(OldStream),
                          see(InputFile),
                          repeat,   % Use repeat to read all lines
                          read(Term),
                          (( Term == end_of_file) -> true ; % Read till EOF
                            write(Term),assertz(Term), fail % Write to the terminal
                                                            % Add to knowledge
                                                            % base with assertz
                          ),
                          seen,
                          see(OldStream).
