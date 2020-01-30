
word(abalone,[a,b,a,l,o,n,e],7).
word(abandon,[a,b,a,n,d,o,n],7).
word(enhance,[e,n,h,a,n,c,e],7).
word(anagram,[a,n,a,g,r,a,m],7).
word(connect,[c,o,n,n,e,c,t],7).
word(elegant,[e,l,e,g,a,n,t],7).


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
  my_cw(W1,W2,W3,W4,W5,W6):-
        intersection(W1, W4, 1, 1),
        intersection(W1, W5, 3, 1),
        intersection(W1, W6, 5, 1),
        intersection(W2, W4, 1, 3),
        intersection(W2, W5, 3, 3),
        intersection(W2, W6, 5, 3),
        intersection(W3, W4, 1, 5),
        intersection(W3, W5, 3, 5),
        intersection(W3, W6, 5, 5),
        word(W1, _, 7),
        word(W2, _, 7),
        word(W3, _, 7),
        word(W4, _, 7),
        word(W5, _, 7),
        word(W6, _, 7).



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
