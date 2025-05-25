g++ -std=c++17 -Ilib ./lib/pugixml.cpp ./lib/Epub.cpp main.cpp -o program
./program ./cache/1 > output1.txt
./program ./cache/2 > output2.txt
./program ./cache/3 > output3.txt
./program ./cache/4 > output4.txt

rm program