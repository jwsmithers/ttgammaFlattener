# ttgammaFlattener
Code to flatten ntuples for the training of the ELD in the ttgamma analysis

# Usage
`source setup.sh`

`mkdir build ; cd build`

`cmake ../`

`make ttgammaFlattener`

`./ttgammaFlattener <someinput>.root`

# unshittifyTree
In case a tree has some bad variables, this will help get rid of them.

`make unshittifyTree`

`./unshittifyTree <someinput>.root`

