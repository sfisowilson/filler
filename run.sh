gcc -Wall -Wextra -Werror -o sfiso.filler *.c ./libft/libft.a
./resources/filler_vm -p1 ./sfiso.filler -p2 ./sfiso.filler -s -f ./resources/maps/map01
