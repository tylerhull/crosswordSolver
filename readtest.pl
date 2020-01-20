% Tyler Hull
% Prolog code to read from a file and add terms to a knowledge base.
% Modified from the following website:
% https://stackoverflow.com/questions/16100438/how-to-read-all-the-prolog-
% predicate-in-a-txt-file-using-read-predicate-in-prol

% This section of code will read from a file and add the contents to
% the prolog knowledge base. Then the contents of the file can be querried.
% Make sure that the file being read has terms in proper prolog syntax.

% 1. Compile the knowledge base with:
%   [readtest].

% 2. Call this function from the command line or a program with:
%    readFileSee('/home/tyler/Documents/crossword_solver/word_list.txt').
% 3. test with: word(doesn^t, _,_,_,_,_,_,_).
%            returns true.
%    test with: word(X, _,_,_,_,_,_,_).
%            returns all results. Cycle through them with the ; character.
%            Hit return key when you want to stop.


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
