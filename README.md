Project Description

Program, that generates pseudo-random numbers for each line in file.

Configuration

main -f &lt;file&gt; -n &lt;number cap&gt; [-s &lt;seed&gt;]

default seed =1

How to compile and run

git clone https://github.com/NeXachu/CryptoDZ1.git

cd CryptoDZ1/

gcc main.c -o main

main -f test/names.txt -n 20
