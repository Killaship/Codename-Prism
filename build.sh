echo "Now building..."
git pull
gcc src/shell.c -Wall -Wextra -o prism
echo "Building complete, now running."
./prism
