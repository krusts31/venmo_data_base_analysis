make
./a.out 1 > files/get_note.sh 2> files/stats.txt
./a.out 2 > files/get_comment_one.sh
./a.out 3 > files/get_comment_two.sh

bash files/get_note.sh
bash files/get_comment_one.sh
bash files/get_comment_two.sh
