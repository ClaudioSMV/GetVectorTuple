#include "GetVectorTuple.h"
#include "UI.h"
#include "TreeOut.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

GetVectorTuple::GetVectorTuple(TTree *tree) : fChain(0) {
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("clas12_data/ntuples_dc_020136.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("clas12/ntuples_dc_020136.root");
      }
      f->GetObject("data", tree);

   }
   Init(tree);
}

GetVectorTuple::~GetVectorTuple() {
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t GetVectorTuple::GetEntry(Long64_t entry) {
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t GetVectorTuple::LoadTree(Long64_t entry) {
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
    //   Notify();
   }
   return centry;
}

void GetVectorTuple::Init(TTree *tree) {
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   // fChain->SetMakeClass(1);

   // fChain->SetBranchAddress("run_num", &run_num);
   fChain->SetBranchAddress("event_num", &event_num);
   fChain->SetBranchAddress("E_beam", &E_beam);
   fChain->SetBranchAddress("pid", &pid);
   fChain->SetBranchAddress("charge", &charge);
   fChain->SetBranchAddress("status", &status);
   fChain->SetBranchAddress("mass", &mass);
   fChain->SetBranchAddress("v_x", &v_x);
   fChain->SetBranchAddress("v_y", &v_y);
   fChain->SetBranchAddress("v_z", &v_z);
   fChain->SetBranchAddress("p_x", &p_x);
   fChain->SetBranchAddress("p_y", &p_y);
   fChain->SetBranchAddress("p_z", &p_z);
   fChain->SetBranchAddress("p", &p);
   // fChain->SetBranchAddress("theta", &theta);
   // fChain->SetBranchAddress("phi", &phi);
   fChain->SetBranchAddress("beta", &beta);
   fChain->SetBranchAddress("trigger_status", &trigger_status);
   fChain->SetBranchAddress("sector", &sector);
   fChain->SetBranchAddress("chi2", &chi2);
   // fChain->SetBranchAddress("NDF", &NDF);
   fChain->SetBranchAddress("E_PCAL", &E_PCAL);
   fChain->SetBranchAddress("E_ECIN", &E_ECIN);
   fChain->SetBranchAddress("E_ECOU", &E_ECOU);
   fChain->SetBranchAddress("E_total", &E_total);
   // fChain->SetBranchAddress("Delta_TOF", &Delta_TOF);
   fChain->SetBranchAddress("Nphe_LTCC", &Nphe_LTCC);
   fChain->SetBranchAddress("Nphe_HTCC", &Nphe_HTCC);
   fChain->SetBranchAddress("Q2", &Q2);
   fChain->SetBranchAddress("nu", &nu);
   fChain->SetBranchAddress("x_bjorken", &x_bjorken);
   fChain->SetBranchAddress("y_bjorken", &y_bjorken);
   fChain->SetBranchAddress("W2", &W2);
   fChain->SetBranchAddress("z_h", &z_h);
   fChain->SetBranchAddress("p_T2", &p_T2);
   fChain->SetBranchAddress("p_L2", &p_L2);
   fChain->SetBranchAddress("phi_PQ", &phi_PQ);
   fChain->SetBranchAddress("theta_PQ", &theta_PQ);
}

void GetVectorTuple::Loop(TTree *output, struct rec_p &rec) {
    if (fChain == 0)
        return;

    Long64_t nentries = fChain->GetEntries();

    int iElectron = 0;
    int electron_idx = 0;
    // bool is_trigger_electron = true;
    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry = 0; jentry < nentries; jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0)
            break;

        if (jentry % 100000 == 0)
            printf("Progress at %6.2f%%\n", 100. * (double)jentry/nentries);

        nb = fChain->GetEntry(jentry);
        // nbytes += nb;
        // if (Cut(ientry) < 0) continue;

        if (trigger_status) { // Clear particles' info from previous electron
            ClearParticleVar_REC(rec);
            electron_idx = event_num;
            continue;
        }

        // Loop over entries associated to trigger
        while ((event_num == electron_idx) && (jentry < nentries)) {
            if (this->GetCategorization() == "pi+" || this->GetCategorization() == "pi-") {
                AssignParticleVar_REC(this, rec);
                nbytes += nb;
            }
            jentry++;
            nb = fChain->GetEntry(jentry);
        }
        // Get back to last-associated-particle entry after exiting loop
        jentry--;
        nb = fChain->GetEntry(jentry);

        if (rec.pid.size() > 0) { // save only if there was at least one good pion
            iElectron++;
            AssignElectronVar_REC(this, rec, iElectron);
            output->Fill();
        }
    }
}

int main(int argc, char **argv) {

    parseCommandLine(argc, argv);
    printOptions();

    // assign options
    TString gInputFile = "ntuples_dc_" + gRunNumber + ".root";
    // TString gOutputFile = "GVT" + gTargetOption + "_" + gRunNumber + ".root";
    TString gOutputFile = "GVT_" + gRunNumber + ".root";

    // Input
    TFile *fin = TFile::Open("clas12_data/" + gInputFile, "READ");
    TTree *intree = (TTree*)fin->Get("data");

    // Output
    TFile *fout = TFile::Open("output/" + gOutputFile, "RECREATE");
    TTree *outtree = new TTree("ntuple_data", "Data of particles");

    struct rec_p rec;
    SetOutputBranches_REC(outtree, rec);

    GetVectorTuple *vtuple = new GetVectorTuple(intree);
    vtuple->Loop(outtree, rec);

    // write and close output file
    fout->Write();
    fout->Close();
    std::cout << "File " << gOutputFile << " has been created!" << std::endl;

    return 0;
}
