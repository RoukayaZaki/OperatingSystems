gcc publisher.c -o publisher
gcc subscriber.c -o subscriber
for _ in {1..$1}
do
    ./subscriber &
done
./publisher $1
