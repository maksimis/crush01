gcc -Wall -Wextra -Werror ex00/*.c -o rush-01
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
./rush-01 "1 2 3 2 3 1 2 2 1 4 2 2 4 1 2 2"  | cat -e
./rush-01 "5 2 3 2 3 1 2 2 1 4 2 2 4 1 2 2" | cat -e
./rush-01 "43211 2 2 2 4 3 2 1 1 2 2 2" | cat -e
./rush-01 "43211 2 2 2 4 3 2 1 1 2 2  d2" | cat -e
./rush-01 "43211 2 2 2 4 3 2 1 dfs 1 2 2 2" | cat -e
./rush-01 "afdaf 2 2 2 4 3 2 1 1 2 dafdf2 2" | cat -e
./rush-01 "z 2 3 2 3 1 2 2 1 4 2 2 4 1 2 2" | cat -e
./rush-01 "5 2 3 2 3 1 2 2 1 4 2 2 4 1 2 2 3" | cat -e
./rush-01 "5  2 3 2 3 1 2 2 1 4 2 2 4 1 2 2" | cat -e
./rush-01 "2 1 2 4 2 3 3 1 2 3 1 2 3 2 2 1" | cat -e
./rush-01 "3 2 2 1 1 2 2 3 3 2 3 1 1 2 2 4" | cat -e
./rush-01 "4 4 4 1 1 2 2 3 3 2 3 1 1 2 2 4" | cat -e