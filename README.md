# ttgammaFlattener
Code to flatten ntuples for the training of the ELD in the ttgamma analysis

# Usage
source setup.sh
mkdir build ; cd build
cmake ../
make 
./ttgammaFlattener <someinput>.root
