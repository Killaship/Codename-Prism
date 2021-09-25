echo "Now building..."
rm -rf prism
git pull
gcc src/shell.c -Wall -Wextra -o prism
echo "Building complete, now running."
./prism
