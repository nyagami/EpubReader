g++ -std=c++17 -Ilib ./lib/pugixml.cpp ./lib/Epub.cpp main.cpp -o program.exe
./program.exe ./cache/1 > output1.txt
./program.exe ./cache/2 > output2.txt
./program.exe ./cache/3 > output3.txt
./program.exe ./cache/4 > output4.txt
./program.exe ./cache/5 > output5.txt

rm program.exe