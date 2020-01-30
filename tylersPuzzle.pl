

% intersection(W1, W2, I1, I2) is true if
% word W1 has an intersection with word W2
%	at index I1 for word W1 and I2 for word W2
%	indexes counting starts at 0.
intersection(Word1, Word2, Index1, Index2):-
	dif(Word1, Word2),
	word(Word1, List1, Length1),
	nth0(Index1, List1, Letter),
	Index1 < Length1,
	word(Word2, List2, Length2),
	nth0(Index2, List2, Letter),
	Index2 < Length2.


  % Implementation of our custom crossword

  % my_cw is true if W1, W2, W3, W4, W5, W6, W7, W8, W9, W10
  % 	are all words that fulfill the constrains
  % 	of this crossword puzzle
  my_cw(W1,W2,W3,W3D,W4,W5,W6,W7,W8,W9,W10,W11,W12):-
        intersection(W1, W3, 1, 3),
        intersection(W2, W3, 1, 6),
        intersection(W3, W4, 5, 0),
        intersection(W3D, W5, 2, 0),
        intersection(W3D, W7, 3, 0),
        intersection(W3D, W9, 5, 0),
        intersection(W4, W9, 5, 5),
        intersection(W6, W5, 0, 1),
        intersection(W6, W7, 1, 1),
        intersection(W8, W9, 1, 2),
        intersection(W9, W10, 1, 0),
        intersection(W9, W11, 3, 0),
        intersection(W9, W12, 6, 0),
        word(W1, _, 5),
        word(W2, _, 2),
        word(W3, _, 7),
        word(W4, _, 6),
        word(W5, _, 2),
        word(W6, _, 2),
        word(W7, _, 2),
        word(W8, _, 2),
        word(W9, _, 7),
        word(W10, _, 3),
        word(W11, _, 3),
        word(W12, _, 3).



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
