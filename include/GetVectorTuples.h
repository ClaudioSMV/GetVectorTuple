//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul  8 15:29:27 2025 by ROOT version 6.28/12
// from TTree data/data
// found on file: clas12/ntuples_dc_020136.root
//////////////////////////////////////////////////////////

#ifndef GetVectorTuples_h
#define GetVectorTuples_h

#include "Headers.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>

class GetVectorTuples {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   // Float_t         run_num;
   // Float_t         event_num;
   Float_t         E_beam;
   Float_t         pid;
   Float_t         charge;
   Float_t         status;
   Float_t         mass;
   Float_t         v_x;
   Float_t         v_y;
   Float_t         v_z;
   Float_t         p_x;
   Float_t         p_y;
   Float_t         p_z;
   Float_t         p;
   // Float_t         theta;
   // Float_t         phi;
   Float_t         beta;
   Float_t         trigger_status;
   Float_t         sector;
   Float_t         chi2;
   // Float_t         NDF;
   Float_t         E_PCAL;
   Float_t         E_ECIN;
   Float_t         E_ECOU;
   Float_t         E_total;
   // Float_t         Delta_TOF;
   Float_t         Nphe_LTCC;
   Float_t         Nphe_HTCC;
   Float_t         Q2;
   Float_t         nu;
   Float_t         x_bjorken;
   Float_t         y_bjorken;
   Float_t         W2;
   Float_t         z_h;
   Float_t         p_T2;
   Float_t         p_L2;
   Float_t         phi_PQ;
   Float_t         theta_PQ;

   // // List of branches
   // TBranch        *b_run_num;   //!
   // TBranch        *b_event_num;   //!
   // TBranch        *b_E_beam;   //!
   // TBranch        *b_pid;   //!
   // TBranch        *b_charge;   //!
   // TBranch        *b_status;   //!
   // TBranch        *b_mass;   //!
   // TBranch        *b_v_x;   //!
   // TBranch        *b_v_y;   //!
   // TBranch        *b_v_z;   //!
   // TBranch        *b_p_x;   //!
   // TBranch        *b_p_y;   //!
   // TBranch        *b_p_z;   //!
   // TBranch        *b_p;   //!
   // TBranch        *b_theta;   //!
   // TBranch        *b_phi;   //!
   // TBranch        *b_beta;   //!
   // TBranch        *b_trigger_status;   //!
   // TBranch        *b_sector;   //!
   // TBranch        *b_chi2;   //!
   // TBranch        *b_NDF;   //!
   // TBranch        *b_E_PCAL;   //!
   // TBranch        *b_E_ECIN;   //!
   // TBranch        *b_E_ECOU;   //!
   // TBranch        *b_E_total;   //!
   // TBranch        *b_Delta_TOF;   //!
   // TBranch        *b_Nphe_LTCC;   //!
   // TBranch        *b_Nphe_HTCC;   //!
   // TBranch        *b_Q2;   //!
   // TBranch        *b_nu;   //!
   // TBranch        *b_x_bjorken;   //!
   // TBranch        *b_y_bjorken;   //!
   // TBranch        *b_W2;   //!
   // TBranch        *b_z_h;   //!
   // TBranch        *b_p_T2;   //!
   // TBranch        *b_p_L2;   //!
   // TBranch        *b_phi_PQ;   //!
   // TBranch        *b_theta_PQ;   //!

   GetVectorTuples(TTree *tree=0);
   virtual ~GetVectorTuples();
   // virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TTree *output, struct rec_p &rec);
   // virtual Bool_t   Notify();
   // virtual void     Show(Long64_t entry = -1);


private:
   const Double_t kEbeamDefault = 5.014;  // The energy of incoming electron beam
   const Double_t kMpi = 0.139570;  // mass of the pion
   const Double_t kMprt = 0.938272;  // mass of the proton
   const Double_t kMntr = 0.939565;  // mass of the neutron
   const Double_t kGOOD = -1000.;  // The key for the exceptions

public:
   Double_t W() {
      return TMath::Sqrt(W2);
   }

   Double_t PhiLab() {
      // Returns the azimuthal angle in Lab frame for the particle in the row k
      TVector3 v3p(p_x, p_y, p_z);
      Double_t PhiLab_value = v3p.Phi() * TMath::RadToDeg();
      if (PhiLab_value < -30.) {
         return PhiLab_value + 360.;
      } else if (PhiLab_value > 330.) {
         return PhiLab_value - 360.;
      }                     // closure
      return PhiLab_value;  // default
   }

   Double_t ThetaLab() {
      // Returns the polar angle in Lab frame for the particle in the row k
      TVector3 v3p(p_x, p_y, p_z);
      return v3p.Theta() * TMath::RadToDeg();
   }

   Double_t Eh() {
      return TMath::Sqrt(mass * mass + p * p);
   }

   Double_t Mx2() { // (Int_t k, Bool_t kind = 0, Double_t Identificator::mass = 0.13957) {
      // Returns missing mass of the particle
      return W2 - 2. * nu * z_h * (nu + kMprt) + mass * mass +
         2. * TMath::Sqrt((Q2 + nu * nu) * p_L2);
   }

   Double_t T() {
      // Mandelstam variable T=(q-Ph)2
      return 2. * TMath::Sqrt((nu * nu + Q2) * p_L2) + mass * mass - Q2 - 2. * nu * nu * z_h;
   }

   Double_t Mass2() {
      // Returns the mass squared from the SC Time of Flight for the particle in the row k
      return p * p * (TMath::Power(beta, -2) - 1);
   }

   Double_t Xf() {
      // Returns the Feynman X scaling variable for the particle in the row k
      // (only valid for charged pions!)
      if (pid != 211 && pid != -211) { // Default value for particle different to pion
         return kGOOD;
      }
      Double_t PlCM;     // PlCM: Longitudinal momentum of the hadron in the Center of Mass frame
      Double_t PlCMmax;  // Max PlCM's value expected (according to S.Moran thesis)
      PlCM = (TMath::Sqrt(p_L2) - z_h * nu * TMath::Sqrt(Q2 + nu * nu) / (nu + kMprt)) *
         (nu + kMprt) / W();
      PlCMmax = TMath::Sqrt(TMath::Power(W(), 4) + TMath::Power(kMpi * kMpi - kMntr * kMntr, 2) -
         2 * W2 * (kMpi * kMpi + kMntr * kMntr)) / (2 * W());
      return PlCM / PlCMmax;
   }

   TString GetCategorization() {
      if (pid == 11 && charge == -1) {
         return "electron";
      } else if (pid == -211 && charge == -1) {
         return "pi-";
      } else if (pid == -11 && charge == 1) {
         return "positron";
      } else if (pid == 211 && charge == 1) {
         return "pi+";
      } else if (pid == 2212 && charge == 1) {
         return "proton";
      // } else if (IsGamma()) {
      //     return "gamma";
      }  // closure
      return "not recognized";
}

};

#endif
