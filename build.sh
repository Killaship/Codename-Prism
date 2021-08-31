echo "Now building..."
git pull
gcc src/shell.c -Wall -Wextra -o prism
echo "Building complete, now running."
echo ""
echo "TIP FOR NOOBZ:"
echo "If program hangs, press ^C to quit. (Assuming you're running under linux, with bash shell.)"
echo ""
./prism
