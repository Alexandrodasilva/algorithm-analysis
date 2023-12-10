#/bin/bash

gcc graham.c -o graham -lm
gcc point_generator_cerco.c -o gen
gcc point_generator_cerco2.c -o gen2

j=0
for i in {1..5}
do
	n=$(shuf -i 100-1000 -n 1)
	l=$(shuf -i 100-1000 -n 1)
  ./gen $n $l > "$i".in
  ./graham < "$i".in > "$i".out
  j=$i
done

j=$((j+1))
./gen2 10000 10000 > "$j".in
./graham < "$j".in > "$j".out

j=$((j+1))
./gen2 50000 100000 > "$j".in
./graham < "$j".in > "$j".out

j=$((j+1))
./gen2 100000 500000 > "$j".in
./graham < "$j".in > "$j".out
