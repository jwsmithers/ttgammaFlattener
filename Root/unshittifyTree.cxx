//////////////////////////////
//Joshua.Wyatt.Smith@cern.ch//
//////////////////////////////
#include <iostream>
#include <string>
#include <tuple>
#include <fstream>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <string>
#include <fstream>
#include "TFile.h"
#include "TSystem.h"
#include "TTree.h"
#include <string>
#include "TSystemDirectory.h"
#include "TSystemFile.h"
#include <sstream>
#include <memory>
#include <typeinfo>
#include "TGraph.h"

using namespace std;

int main(int argc, char** argv)
{
  gROOT->ProcessLine( "gErrorIgnoreLevel = kFatal;");
  std::cout << "Found " << argc-1 << " files to run over:" << std::endl;

  string inputPath = "/eos/user/c/caudron/TtGamma_ntuples/v009/CR1/";
  //string channels[] ={"ejets","mujets"};
  string channels[] ={"ejets","mujets", "emu","mumu","ee"};
  // Where we save to:
  // Remember to make the directory. I.e. mkdir ../SR1 ; cd ../SR1 ; mkdir emu mumu etc
  // I'm just too lazy.
  string outputPath = "../CR1_clean/";

  for (int i = 1; i < argc; ++i) {
    for(const string &c : channels){


      string filename = argv[i];
      string file = inputPath+c+"/"+filename;
      string newPath = outputPath + c+"/"+filename;
      std::cout<<"#######################################"<< std::endl;
      std::cout<<c<<": "<< filename<< std::endl;
      std::cout<<c<<": Saving to "<<newPath<< std::endl;


      //Get old file, old tree and set top branch address
      TFile *oldfile = new TFile(file.c_str());
      TTree *oldtree = (TTree*)oldfile->Get("nominal");
      oldtree->SetBranchStatus("*",1);
      oldtree->SetBranchStatus("jet_pt_1st",0);
      oldtree->SetBranchStatus("jet_pt_2nd",0);
      oldtree->SetBranchStatus("jet_pt_3rd",0);
      oldtree->SetBranchStatus("jet_pt_4th",0);
      oldtree->SetBranchStatus("jet_pt_5th",0);
      oldtree->SetBranchStatus("jet_pt_6th",0);
      oldtree->SetBranchStatus("jet_tagWeightBin_leading",0);
      oldtree->SetBranchStatus("jet_tagWeightBin_subleading",0);
      oldtree->SetBranchStatus("jet_tagWeightBin_subsubleading",0);
      oldtree->SetBranchStatus("event_ELD_MVA",0);

      //Create a new file + a clone of old tree header. Do not copy events
      TFile *newfile = new TFile((newPath.c_str()),"recreate");
      TTree *newtree = oldtree->CloneTree(0);

      newtree->CopyEntries(oldtree);

      newfile->Write();
      delete oldfile;
      delete newfile;

    }
  }

  return 0;
}
