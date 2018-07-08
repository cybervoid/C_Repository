git fetch
git reset --hard origin/master
git pull
cd ./C_Node_Run/Node
make -f ./Makefile
cd ./dist/debug/GNU-MacOSX
./node s 3
cd ~/C_Repository
