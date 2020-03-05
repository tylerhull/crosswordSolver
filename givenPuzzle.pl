% These are the words in our knowledge base
word(abalone,a,b,a,l,o,n,e).
word(abandon,a,b,a,n,d,o,n).
word(enhance,e,n,h,a,n,c,e).
word(anagram,a,n,a,g,r,a,m).
word(connect,c,o,n,n,e,c,t).
word(elegant,e,l,e,g,a,n,t).


% ** This section defines the Puzzle. **
% V's describe vertical words.
% H's describe horizontal words.
crosswd(V1,V2,V3,H1,H2,H3) :-
  % Capital letters below are variables for
  % squares that overlap in the puzzle.
                word(V1,_,A,_,B,_,C,_),
                word(V2,_,D,_,E,_,F,_),
                word(V3,_,G,_,H,_,I,_),
                word(H1,_,A,_,D,_,G,_),
                word(H2,_,B,_,E,_,H,_),
                word(H3,_,C,_,F,_,I,_).



readFileSee(InputFile) :- seeing(OldStream),
                see(InputFile),
                repeat,   % Use repeat to read all lines
                read(Term),
                (( Term == end_of_file) -> true ; % Read till EOF
                write(Term),assertz(Term), fail % Write to the terminal
                                                % Add to knowledge
                                                % base with assertz
                ),
                seen,     % Clean up and close file 
                see(OldStream).
