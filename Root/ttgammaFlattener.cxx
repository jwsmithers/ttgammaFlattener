//////////////////////////////
//Joshua.Wyatt.Smith@cern.ch//
//////////////////////////////
#include "ttgammaFlattener.h"
#include <iostream>
#include <memory>

using namespace std;


void m_nan_cleaner_upper(vector<float> *variable){
  for(uint i = 0; i < variable->size(); i++){
    std::cout << variable->at(i) <<std::endl;
  }
}


void m_add_branches(
  TChain *fChain,
  TEntryList *entryList,
  TTree *newtree,
  string filename,
  string channel)
  {

  newtree->Branch("jet_pt_1st_correct",&m_jet_pt_1st_correct);   
  newtree->Branch("jet_pt_2nd_correct",&m_jet_pt_2nd_correct);   
  newtree->Branch("jet_pt_3rd_correct",&m_jet_pt_3rd_correct);   
  newtree->Branch("jet_pt_4th_correct",&m_jet_pt_4th_correct);   
  newtree->Branch("jet_pt_5th_correct",&m_jet_pt_5th_correct);   
  newtree->Branch("jet_pt_6th_correct",&m_jet_pt_6th_correct);   

  newtree->Branch("ph_drsubljet_sel",&m_ph_drsubljet_sel);   
  newtree->Branch("ph_drlept_sel",&m_ph_drlept_sel);   
  newtree->Branch("ph_e_sel",&m_ph_e_sel);   
  newtree->Branch("ph_phi_sel",&m_ph_phi_sel);   
  newtree->Branch("ph_drleadjet_sel",&m_ph_drleadjet_sel);   
  newtree->Branch("ph_mgammalept_sel",&m_ph_mgammalept_sel);   
  newtree->Branch("ph_mgammaleptlept_sel",&m_ph_mgammaleptlept_sel);   
  newtree->Branch("ph_HFT_MVA_sel",&m_ph_HFT_MVA_sel);   
  newtree->Branch("ph_isoFCT_sel",&m_ph_isoFCT_sel);   

  newtree->Branch("ph_ptcone20_sel",&m_ph_ptcone20_sel);   
  newtree->Branch("ph_ptcone30_sel",&m_ph_ptcone30_sel);   
  newtree->Branch("ph_ptcone40_sel",&m_ph_ptcone40_sel);   

  newtree->Branch("ph_topoetcone20_sel",&m_ph_topoetcone20_sel);
  newtree->Branch("ph_topoetcone30_sel",&m_ph_topoetcone30_sel);
  newtree->Branch("ph_topoetcone40_sel",&m_ph_topoetcone40_sel);

  newtree->Branch("jet_tagWeightBin_leading_correct",&m_jet_tagWeightBin_leading_correct);   
  newtree->Branch("jet_tagWeightBin_subleading_correct",&m_jet_tagWeightBin_subleading_correct);   
  newtree->Branch("jet_tagWeightBin_subsubleading_correct",&m_jet_tagWeightBin_subsubleading_correct);   

  newtree->Branch("ph_SF_eff_sel",&m_ph_SF_eff_sel);   
  newtree->Branch("ph_SF_iso_sel",&m_ph_SF_iso_sel);   


  newtree->Branch("weight_mm_ejets_peak",&m_weight_mm_ejets_peak);   
  newtree->Branch("weight_mm_ejets_up",&m_weight_mm_ejets_up);   
  newtree->Branch("weight_mm_ejets_down",&m_weight_mm_ejets_down);   

  newtree->Branch("weight_mm_mujets_peak",&m_weight_mm_mujets_peak);  
  newtree->Branch("weight_mm_mujets_up",&m_weight_mm_mujets_up);    
  newtree->Branch("weight_mm_mujets_down",&m_weight_mm_mujets_down);

  float total_events=0;
  float total_events_unweighted=0;

  activateBranches(fChain); 

  int nentries = entryList->GetN();
  std::cout<< nentries << " entries" << std::endl;

  for (Long64_t event =0;event<nentries;event++) {
    int entryNumber = fChain->GetEntryNumber(event);
    if (entryNumber < 0) break;
       fChain->GetEntry(entryNumber);
    loadBar(event, nentries, 100, 50);

    // Get good photons
    m_ph_drsubljet_sel = ph_drsubljet->at(selph_index1);
    m_ph_drlept_sel = ph_drlept->at(selph_index1);
    m_ph_e_sel = ph_e->at(selph_index1);
    m_ph_phi_sel = ph_phi->at(selph_index1);
    m_ph_drleadjet_sel = ph_drleadjet->at(selph_index1);
    m_ph_mgammalept_sel = ph_mgammalept->at(selph_index1);
    m_ph_mgammaleptlept_sel = ph_mgammaleptlept->at(selph_index1);
    m_ph_HFT_MVA_sel = ph_HFT_MVA->at(selph_index1);
    m_ph_isoFCT_sel = ph_isoFCT->at(selph_index1);

    m_ph_ptcone20_sel = ph_ptcone20->at(selph_index1);
    m_ph_ptcone30_sel = ph_ptcone30->at(selph_index1);
    m_ph_ptcone40_sel = ph_ptcone40->at(selph_index1);

    m_ph_topoetcone20_sel = ph_topoetcone20->at(selph_index1);
    m_ph_topoetcone30_sel = ph_topoetcone30->at(selph_index1);
    m_ph_topoetcone40_sel = ph_topoetcone40->at(selph_index1);



    // Get good weights
    m_ph_SF_eff_sel = ph_SF_eff->at(selph_index1);
    m_ph_SF_iso_sel = ph_SF_iso->at(selph_index1);

    // Get certain jets 
    for(uint jetn = 0; jetn < jet_pt->size();jetn++){
      try {
        m_jet_pt_1st_correct = jet_pt->at(0);
        } catch(const std::out_of_range& oor) {
        continue;
        }
      try {
        m_jet_pt_2nd_correct = jet_pt->at(1);
        } catch(const std::out_of_range& oor) {
        continue;
        }
      try {
        m_jet_pt_3rd_correct = jet_pt->at(2);
        } catch(const std::out_of_range& oor) {
        continue;
        }
      try {
        m_jet_pt_4th_correct = jet_pt->at(3);
        } catch(const std::out_of_range& oor) {
        continue;
        }
      try {
        m_jet_pt_5th_correct = jet_pt->at(4);
        } catch(const std::out_of_range& oor) {
        continue;
        }
      try {
        m_jet_pt_6th_correct = jet_pt->at(5);
        } catch(const std::out_of_range& oor) {
        continue;
        }
    }

    // Sort btag weigths and add to mbranch // 
    std::sort (jet_tagWeightBin->begin(), jet_tagWeightBin->end(), std::greater<int>()); 

    for (uint sorted = 0; sorted < jet_tagWeightBin->size(); sorted++) {
      try {
      m_jet_tagWeightBin_leading_correct = jet_tagWeightBin->at(0);
      } catch(const std::out_of_range& oor) {
        continue;
      }
      try {
      m_jet_tagWeightBin_subleading_correct = jet_tagWeightBin->at(1);
      } catch(const std::out_of_range& oor) {
        continue;
      }
     try {
      m_jet_tagWeightBin_subsubleading_correct = jet_tagWeightBin->at(2);
      } catch(const std::out_of_range& oor) {
        continue;
      }
    }

    // If QCD, add some branches
    if (filename.find("QCDfakes") != std::string::npos) {
      if (channel == "ejets") {
        m_weight_mm_ejets_peak = weights_mm_ejets->at(17);
        m_weight_mm_ejets_up = weights_mm_ejets->at(52);
        m_weight_mm_ejets_down = weights_mm_ejets->at(43);

        m_weight_mm_mujets_peak = 0;
        m_weight_mm_mujets_up = 0;
        m_weight_mm_mujets_down = 0;

      } else if (channel == "mujets") {

        m_weight_mm_mujets_peak = weights_mm_mujets->at(75);
        m_weight_mm_mujets_up = weights_mm_mujets->at(86);
	m_weight_mm_mujets_down = weights_mm_mujets->at(91);

        m_weight_mm_ejets_peak = 0;
        m_weight_mm_ejets_up = 0;
        m_weight_mm_ejets_down = 0;
     }

    } else {
        m_weight_mm_ejets_peak = 0;
        m_weight_mm_ejets_up = 0;
        m_weight_mm_ejets_down = 0;
        m_weight_mm_mujets_peak = 0;
        m_weight_mm_mujets_up = 0;
        m_weight_mm_mujets_down = 0;
    }
    

    total_events_unweighted=total_events_unweighted+1;
    if (filename.find("QCDfakes") != std::string::npos) {
         total_events = total_events+1*weights_mm_ejets->at(17) + 1*weights_mm_mujets->at(75);
    } else {
      total_events = total_events + 1 * (weight_mc * weight_pileup
          * weight_bTagSF_Continuous * ph_SF_eff->at(selph_index1)
          * ph_SF_iso->at(selph_index1)
          * weight_leptonSF * weight_jvt * event_norm * event_lumi);
    }
    newtree->Fill();

  }// end event loop
  std::cout << "Number of weighted events = "<< total_events << std::endl;
  std::cout << "Number of unweighted events = "<< total_events_unweighted << std::endl;


}// end add_nn loop

int main(int argc, char** argv)
{
  gROOT->ProcessLine( "gErrorIgnoreLevel = kFatal;");
  std::cout << "Found " << argc-1 << " files to run over:" << std::endl;

  //string inputPath = "/eos/user/c/caudron/TtGamma_ntuples/v009/CR1/";
  string inputPath = "/eos/atlas/user/j/jwsmith/reprocessedNtuples/v009/QE2_yichen/";
  string channels[] ={"ejets","mujets"};
  //string channels[] ={"emu","mumu","ee"};
  // Where we save to:
  // Remember to make the directory. I.e. mkdir ../SR1 ; cd ../SR1 ; mkdir emu mumu etc
  // I'm just too lazy.
  //string outputPath = "/eos/atlas/user/j/jwsmith/reprocessedNtuples/v007_training/SR1/";
  string outputPath = "../v009_training/QE2/";

  TTree *newtree;
  TChain *fChain;
  TFile *newfile;

  for (int i = 1; i < argc; ++i) {
    for(const string &c : channels){


      string filename = argv[i];
      string file = inputPath+c+"/"+filename;
      string newPath = outputPath + c+"/"+filename;
      std::cout<<"#######################################"<< std::endl;
      std::cout<<c<<": "<< filename<< std::endl;
      std::cout<<c<<": Saving to "<<newPath<< std::endl;

      newfile = new TFile((newPath.c_str()), "update");


       if (filename.find("QCDfakes") != std::string::npos) {
         fChain = new TChain("nominal_Loose");
       }
       else {
         fChain = new TChain("nominal");
       }
 
      fChain->Add((file).c_str());


      TCut cut;
      //Channel specific selection:
      if (c.find("ejets") != std::string::npos) {
        // Direct SR cuts
        //cut="selph_index1 >=0 && event_ngoodphotons==1 && event_njets >= 4 && event_nbjets77 >= 1 && abs(ph_mgammalept[selph_index1] - 91188) > 5000 && ph_drlept[selph_index1] > 1.0 && ph_isoFCT[selph_index1]";
        // QE2 cuts
        cut=" ((ejets_2015 && (HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose)) || (ejets_2016 && ((HLT_e26_lhtight_nod0_ivarloose && el_pt[0] < 61000.) || ((HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0) && el_pt[0] > 61000)))) && (selph_index1 >=0 && event_ngoodphotons==1 && event_njets >= 4 && event_nbjets77 >= 1 && abs(ph_mgammalept[selph_index1] - 91188) > 5000 && ph_drlept[selph_index1] > 1.0 && ph_isoFCT[selph_index1])";

      }
      if (c.find("mujets") != std::string::npos) {
        // Direct SR cuts
        //cut="selph_index1 >=0 && event_ngoodphotons==1 && event_njets >= 4 && event_nbjets77 >= 1 && ph_drlept[selph_index1] > 1.0 && ph_isoFCT[selph_index1]";
        // QE2 cuts
        cut="((mujets_2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50)) || (mujets_2016 && ((HLT_mu24 && mu_pt[0] < 51000.) || (HLT_mu50 && mu_pt[0] > 51000.)))) && (selph_index1 >=0 && event_ngoodphotons==1 && event_njets >= 4 && event_nbjets77 >= 1 && ph_drlept[selph_index1] > 1.0 && ph_isoFCT[selph_index1])";
      }
      if (c.find("ee") != std::string::npos) {
        cut="selph_index1 >=0 && event_ngoodphotons == 1 && event_nbjets77 >= 1 && met_met > 30000 && (event_mll < 85000 || event_mll > 95000) && (ph_mgammaleptlept[selph_index1] < 85000 || ph_mgammaleptlept[selph_index1] > 95000) && ph_drlept[selph_index1] > 1.0 && ph_isoFCT[selph_index1]";
        //cut="event_ngoodphotons == 1 && event_nbjets77 >= 1 && ph_drlept[selph_index1] > 1.0 && ph_isoFCT[selph_index1]";
      }
      if (c.find("emu") != std::string::npos) {
        cut="event_ngoodphotons == 1 && event_nbjets77 >= 1 && ph_drlept[selph_index1] > 1.0 && ph_isoFCT[selph_index1]";
      }
      if (c.find("mumu") != std::string::npos) {
        cut="event_ngoodphotons == 1 && event_nbjets77 >= 1 && met_met > 30000 && (event_mll < 85000 || event_mll > 95000) && (ph_mgammaleptlept[selph_index1] < 85000 || ph_mgammaleptlept[selph_index1] > 95000) && ph_drlept[selph_index1] > 1.0 && ph_isoFCT[selph_index1]";
        //cut="event_ngoodphotons == 1 && event_nbjets77 >= 1 &&  ph_drlept[selph_index1] > 1.0 && ph_isoFCT[selph_index1]";
      }

      TCut overlapRemoval;
      // Signal
      if(filename.find("ttgamma") != std::string::npos) {
        overlapRemoval="event_photonorigin<10";
      } 
      // ttbar
      if(filename.find("ttbar") != std::string::npos) {
        overlapRemoval="event_photonorigin>=10";
      } 
      else{
        overlapRemoval="";
      }

      fChain->Draw(">>entrylist",cut&&overlapRemoval,"entrylist");
      TEntryList *elist = (TEntryList*)gDirectory->Get("entrylist");
 
      fChain->SetEntryList(elist);
      newtree = fChain->CloneTree(0);
      if(fChain->GetEntries() == 0){
        std::cout<<"No events, is this an error? Skipping..."<<std::endl;
        continue;
      }
      newtree->SetName("nominal");
      m_add_branches(fChain,elist,newtree, filename,c);
      newfile->cd();
      newtree->Write();
      newfile->Close();
    }
  }

  return 0;
}
