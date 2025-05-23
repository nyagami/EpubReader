g++ -std=c++17 -Ilib ./lib/pugixml.cpp ./lib/Epub.cpp main.cpp -o program
./program /workspaces/EpubReader/cache/1 > output1.txt
./program /workspaces/EpubReader/cache/2 > output2.txt
./program /workspaces/EpubReader/cache/3 > output3.txt
./program /workspaces/EpubReader/cache/4 > output4.txt
./program /workspaces/EpubReader/cache/5 > output5.txt
./program /workspaces/EpubReader/cache/6 > output6.txt
./program /workspaces/EpubReader/cache/7 > output7.txt

rm program