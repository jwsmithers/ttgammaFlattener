#!/bin/bash
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/user/atlasLocalSetup.sh
localSetupROOT
mkdir -p v009_clean/CR1/ejets
mkdir -p v009_clean/CR1/mujets
mkdir -p v009_clean/CR1/mumu
mkdir -p v009_clean/CR1/ee
mkdir -p v009_clean/CR1/emu
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 3641XX.Wenu.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 3641XX.Wmunu.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 3641XX.Wtaunu.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 3641XX.Zee.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 3641XX.Zmumu.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 3641XX.Ztautau.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 364XXX.eegamma.p3152.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 364XXX.enugamma.p3152.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 364XXX.mumugamma.p3152.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 364XXX.munugamma.p3152.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 364XXX.taunugamma.p3152.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 364XXX.tautaugamma.HM.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 410082.ttgamma_noallhad.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 4100XX.ST_others.p3138.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 4100XX.ST_Wt_inclusive.p3138.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 410225.ttbar_nonallhad_P8_AF.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 410501.ttbar_nonallhad_P8_97pc.p3138.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 410511.ttbar_nonallhad_P8_AF.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 410512.ttbar_nonallhad_P8_AF.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree 410525.ttbar_nonallhad_P8_AF.p2952.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data15periodD.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data15periodE.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data15periodF.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data15periodG.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data15periodH.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data15periodJ.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data16periodA.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data16periodB.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data16periodC.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data16periodD.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data16periodE.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data16periodF.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data16periodG.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data16periodI.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data16periodK.p2950.v009.001.root
/afs/cern.ch/work/j/jwsmith/github/ttgammaFlattener/build/unshittifyTree data16periodL.p2950.v009.001.root
