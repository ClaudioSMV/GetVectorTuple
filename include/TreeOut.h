#ifndef TreeOut_h
#define TreeOut_h

// #include "Constants.hxx"
#include "Headers.h"
// #include "Math.hxx"
// #include "PDG.hxx"
#include "GetVectorTuples.h"

struct rec_p {
    // electron (46)
    Float_t Q2;      // Q^2 = -q^2 = -((electron's initial four-momentum) - (electron's final four-momentum))^2, in (GeV^2), more info in
                     // TIdentificatorV2.h/Q2()
    Float_t W;       //
    Float_t Nu;      // virtual photon's energy, Nu = (electron's initial energy) - (electron's final energy), in (GeV)
    Float_t Xb;      //
    Float_t Yb;      //
    Float_t vxe;     // x-vertex of electron, in (cm)
    Float_t vye;     // y-vertex of electron, in (cm)
    Float_t vze;     // z-vertex of electron, in (cm)
    Int_t SectorEl;  //
    Int_t TargType;  // 1 for liquid target, 2 for solid target, criteria written in TIdentificatorV2.h/TargType()
    Float_t Pex;     // x-component of electron's momentum, in (GeV)
    Float_t Pey;     // y-component of electron's momentum, in (GeV)
    Float_t Pez;     // z-component of electron's momentum, in (GeV)
    Float_t Pe;      // electron's momentum, in (GeV)
    Float_t BettaEl; //
    Float_t Etote;   //
    Float_t EPreE;   //
    Float_t Eine;    //
    Float_t Eoute;   //
    Float_t vxec;    // corrected x-vertex of electron, in (cm)
    Float_t vyec;    // corrected y-vertex of electron, in (cm)
    Float_t vzec;    // corrected z-vertex of electron, in (cm)
    // Float_t XECe;        //
    // Float_t YECe;        //
    // Float_t ZECe;        //
    Float_t ThetaLabEl; //
    Float_t PhiLabEl;   //
    // Float_t StatDCEl;    //
    // Float_t DCStatusEl;  //
    // Float_t StatECEl;    //
    // Float_t ECStatusEl;  //
    // Float_t TimeECEl;    //
    // Float_t PathECEl;    //
    // Float_t Chi2ECEl;    //
    // Float_t StatSCEl;    //
    // Float_t SCStatusEl;  //
    // Float_t TimeSCEl;    //
    // Float_t PathSCEl;    //
    // Float_t StatCCEl;    //
    // Float_t CCStatusEl;  //
    Float_t NpheEl;   //
    Float_t Chi2CCEl; //
    Float_t StatusEl; //
    // Float_t NRowsDCEl;   //
    // Float_t NRowsECEl;   //
    // Float_t NRowsSCEl;   //
    // Float_t NRowsCCEl;   //
    Float_t BeamEnergy; //
    // particle (49)
    std::vector<Float_t> Eh;       // energy of the outgoing particle, in (GeV)
    std::vector<Float_t> Zh;       // fraction energy of the outgoing particle, Zh = Eh/Nu
    std::vector<Float_t> ThetaPQ;  //
    std::vector<Float_t> Pt2;      //
    std::vector<Float_t> Pl2;      //
    std::vector<Float_t> PhiPQ;    //
    std::vector<Float_t> Mx2;      //
    std::vector<Float_t> T;        //
    std::vector<Float_t> PhiLab;   //
    std::vector<Float_t> ThetaLab; //
    std::vector<Float_t> vxh;      // x-vertex of particle, in (cm)
    std::vector<Float_t> vyh;      // y-vertex of particle, in (cm)
    std::vector<Float_t> vzh;      // z-vertex of particle, in (cm)
    std::vector<Int_t> Sector;     //
    std::vector<Float_t> Px;       // x-component of particle's momentum, in (GeV)
    std::vector<Float_t> Py;       // y-component of particle's momentum, in (GeV)
    std::vector<Float_t> Pz;       // z-component of particle's momentum, in (GeV)
    std::vector<Float_t> P;        // particle's momentum, in (GeV)
    std::vector<Float_t> Betta;    //
    std::vector<Float_t> Mass2;    //
    std::vector<Float_t> Etot;     //
    std::vector<Float_t> EPre;     //
    std::vector<Float_t> Ein;      //
    std::vector<Float_t> Eout;     //
    // std::vector<Float_t> XEC;       //
    // std::vector<Float_t> YEC;       //
    // std::vector<Float_t> ZEC;       //
    std::vector<Int_t> pid; // particle ID number (according to PDG)
    // std::vector<Float_t> T4;        //
    std::vector<Float_t> Xf;     // x-feynman
    std::vector<Float_t> deltaZ; //
    // std::vector<Float_t> StatDC;    //
    // std::vector<Float_t> DCStatus;  //
    // std::vector<Float_t> StatEC;    //
    // std::vector<Float_t> ECStatus;  //
    // std::vector<Float_t> TimeEC;    //
    // std::vector<Float_t> PathEC;    //
    // std::vector<Float_t> Chi2EC;    //
    // std::vector<Float_t> StatSC;    //
    // std::vector<Float_t> SCStatus;  //
    // std::vector<Float_t> TimeSC;    //
    // std::vector<Float_t> PathSC;    //
    // std::vector<Float_t> StatCC;    //
    // std::vector<Float_t> CCStatus;  //
    std::vector<Float_t> Nphe;   //
    std::vector<Float_t> Chi2CC; //
    std::vector<Float_t> Status; //
    // std::vector<Float_t> NRowsDC;   //
    // std::vector<Float_t> NRowsEC;   //
    // std::vector<Float_t> NRowsSC;   //
    // std::vector<Float_t> NRowsCC;   //
    // event (1)
    Float_t evnt; // event number
};

void SetOutputBranches_REC(TTree *tree, struct rec_p &rec) {
    // reconstructed electron (46 variables)
    tree->Branch("Q2", &rec.Q2);
    tree->Branch("W", &rec.W);
    tree->Branch("Nu", &rec.Nu);
    tree->Branch("Xb", &rec.Xb);
    tree->Branch("Yb", &rec.Yb);
    tree->Branch("vxe", &rec.vxe);
    tree->Branch("vye", &rec.vye);
    tree->Branch("vze", &rec.vze);
    tree->Branch("SectorEl", &rec.SectorEl);
    tree->Branch("TargType", &rec.TargType);
    tree->Branch("Pex", &rec.Pex);
    tree->Branch("Pey", &rec.Pey);
    tree->Branch("Pez", &rec.Pez);
    tree->Branch("Pe", &rec.Pe);
    tree->Branch("BettaEl", &rec.BettaEl);
    tree->Branch("Etote", &rec.Etote);
    tree->Branch("EPreE", &rec.EPreE);
    tree->Branch("Eine", &rec.Eine);
    tree->Branch("Eoute", &rec.Eoute);
    tree->Branch("vxec", &rec.vxec);
    tree->Branch("vyec", &rec.vyec);
    tree->Branch("vzec", &rec.vzec);
    // tree->Branch("XECe", &rec.XECe);
    // tree->Branch("YECe", &rec.YECe);
    // tree->Branch("ZECe", &rec.ZECe);
    tree->Branch("PhiLabEl", &rec.PhiLabEl);
    tree->Branch("ThetaLabEl", &rec.ThetaLabEl);
    // tree->Branch("StatDCEl", &rec.StatDCEl);
    // tree->Branch("DCStatusEl", &rec.DCStatusEl);
    // tree->Branch("StatECEl", &rec.StatECEl);
    // tree->Branch("ECStatusEl", &rec.ECStatusEl);
    // tree->Branch("TimeECEl", &rec.TimeECEl);
    // tree->Branch("PathECEl", &rec.PathECEl);
    // tree->Branch("Chi2ECEl", &rec.Chi2ECEl);
    // tree->Branch("StatSCEl", &rec.StatSCEl);
    // tree->Branch("SCStatusEl", &rec.SCStatusEl);
    // tree->Branch("TimeSCEl", &rec.TimeSCEl);
    // tree->Branch("PathSCEl", &rec.PathSCEl);
    // tree->Branch("StatCCEl", &rec.StatCCEl);
    // tree->Branch("CCStatusEl", &rec.CCStatusEl);
    tree->Branch("NpheEl", &rec.NpheEl);
    tree->Branch("Chi2CCEl", &rec.Chi2CCEl);
    tree->Branch("StatusEl", &rec.StatusEl);
    tree->Branch("BeamEnergy", &rec.BeamEnergy);
    // tree->Branch("NRowsDCEl", &rec.NRowsDCEl);
    // tree->Branch("NRowsECEl", &rec.NRowsECEl);
    // tree->Branch("NRowsSCEl", &rec.NRowsSCEl);
    // tree->Branch("NRowsCCEl", &rec.NRowsCCEl);
    // reconstructed particle (50 variables)
    tree->Branch("Eh", &rec.Eh);
    tree->Branch("Zh", &rec.Zh);
    tree->Branch("ThetaPQ", &rec.ThetaPQ);
    tree->Branch("Pt2", &rec.Pt2);
    tree->Branch("Pl2", &rec.Pl2);
    tree->Branch("PhiPQ", &rec.PhiPQ);
    tree->Branch("Mx2", &rec.Mx2);
    tree->Branch("T", &rec.T);
    tree->Branch("PhiLab", &rec.PhiLab);
    tree->Branch("ThetaLab", &rec.ThetaLab);
    tree->Branch("vxh", &rec.vxh);
    tree->Branch("vyh", &rec.vyh);
    tree->Branch("vzh", &rec.vzh);
    tree->Branch("Sector", &rec.Sector);
    tree->Branch("Px", &rec.Px);
    tree->Branch("Py", &rec.Py);
    tree->Branch("Pz", &rec.Pz);
    tree->Branch("P", &rec.P);
    tree->Branch("Betta", &rec.Betta);
    tree->Branch("Mass2", &rec.Mass2);
    tree->Branch("Etot", &rec.Etot);
    tree->Branch("EPre", &rec.EPre);
    tree->Branch("Ein", &rec.Ein);
    tree->Branch("Eout", &rec.Eout);
    // tree->Branch("XEC", &rec.XEC);
    // tree->Branch("YEC", &rec.YEC);
    // tree->Branch("ZEC", &rec.ZEC);
    tree->Branch("pid", &rec.pid);
    // tree->Branch("T4", &rec.T4);
    tree->Branch("Xf", &rec.Xf);
    tree->Branch("deltaZ", &rec.deltaZ);
    // tree->Branch("StatDC", &rec.StatDC);
    // tree->Branch("DCStatus", &rec.DCStatus);
    // tree->Branch("StatEC", &rec.StatEC);
    // tree->Branch("ECStatus", &rec.ECStatus);
    // tree->Branch("TimeEC", &rec.TimeEC);
    // tree->Branch("PathEC", &rec.PathEC);
    // tree->Branch("Chi2EC", &rec.Chi2EC);
    // tree->Branch("StatSC", &rec.StatSC);
    // tree->Branch("SCStatus", &rec.SCStatus);
    // tree->Branch("TimeSC", &rec.TimeSC);
    // tree->Branch("PathSC", &rec.PathSC);
    // tree->Branch("StatCC", &rec.StatCC);
    // tree->Branch("CCStatus", &rec.CCStatus);
    tree->Branch("Nphe", &rec.Nphe);
    tree->Branch("Chi2CC", &rec.Chi2CC);
    tree->Branch("Status", &rec.Status);
    // tree->Branch("NRowsDC", &rec.NRowsDC);
    // tree->Branch("NRowsEC", &rec.NRowsEC);
    // tree->Branch("NRowsSC", &rec.NRowsSC);
    // tree->Branch("NRowsCC", &rec.NRowsCC);
    // event-related (1 variable)
    tree->Branch("evnt", &rec.evnt);
}

void AssignElectronVar_REC(GetVectorTuples *t, struct rec_p &rec, Int_t evnt) {
    // reconstructed electron (46 variables)
    rec.Q2 = t->Q2;
    rec.W = t->W();
    rec.Nu = t->nu;
    rec.Xb = t->x_bjorken;
    rec.Yb = t->y_bjorken;
    rec.vxe = t->v_x;
    rec.vye = t->v_y;
    rec.vze = t->v_z;
    rec.SectorEl = t->sector;
    rec.Pex = t->p_x;
    rec.Pey = t->p_y;
    rec.Pez = t->p_z;
    rec.Pe = t->p;
    rec.BettaEl = t->beta;
    rec.Etote = t->E_total;
    rec.EPreE = t->E_PCAL;
    rec.Eine = t->E_ECIN;
    rec.Eoute = t->E_ECOU;
    // TVector3* fVert = t->GetCorrectedVert(); // No correction in Clas12 yet, so re-using def value
    rec.vxec = t->v_x; // fVert->X();
    rec.vyec = t->v_y; // fVert->Y();
    rec.vzec = t->v_z; // fVert->Z();
    // rec.TargType = t->TargTypeSM(gDataKind, gTargetOption, 0);
    rec.TargType = 2; // TODO: Check what defines whether a file is solid or liquid target!
    // rec.XECe = t->XEC(0);
    // rec.YECe = t->YEC(0);
    // rec.ZECe = t->ZEC(0);
    rec.PhiLabEl = t->PhiLab();
    rec.ThetaLabEl = t->ThetaLab();
    // rec.StatDCEl = t->StatDC(0);
    // rec.DCStatusEl = t->DCStatus(0);
    // rec.StatECEl = t->StatEC(0);
    // rec.ECStatusEl = t->ECStatus(0);
    // rec.TimeECEl = t->TimeEC(0);
    // rec.PathECEl = t->PathEC(0);
    // rec.Chi2ECEl = t->Chi2EC(0);
    // rec.StatSCEl = t->StatSC(0);
    // rec.SCStatusEl = t->SCStatus(0);
    // rec.TimeSCEl = t->TimeSC(0);
    // rec.PathSCEl = t->PathSC(0);
    // rec.StatCCEl = t->StatCC(0);
    // rec.CCStatusEl = t->CCStatus(0);
    rec.NpheEl = t->Nphe_HTCC; // NOTE: The LowThreshold (Nphe_LTCC) helps separating Pi from Kaon! Should be implemented somewhere else
    rec.Chi2CCEl = t->chi2; // This might be not correct. Check definition of original file!
    rec.StatusEl = t->status;
    rec.BeamEnergy = t->E_beam;
    // rec.NRowsDCEl = t->NRowsDC();
    // rec.NRowsECEl = t->NRowsEC();
    // rec.NRowsSCEl = t->NRowsSC();
    // rec.NRowsCCEl = t->NRowsCC();
    // event-related (1 variable)
    rec.evnt = evnt;
}

void AssignParticleVar_REC(GetVectorTuples *t, struct rec_p &rec) {
    // reconstructed particles (50 variables)
    // Int_t fPid = particleID(t->GetCategorization(row, gDataKind, gTargetOption));
    rec.pid.push_back(t->pid); // (fPid);
    rec.vxh.push_back(t->v_x);
    rec.vyh.push_back(t->v_y);
    rec.vzh.push_back(t->v_z);
    rec.Sector.push_back(t->sector);
    // TVector3* fVert = t->GetCorrectedVert();
    // rec.deltaZ.push_back(t->Z(row) - fVert->Z());
    // rec.XEC.push_back(t->XEC(row));
    // rec.YEC.push_back(t->YEC(row));
    // rec.ZEC.push_back(t->ZEC(row));
    rec.Etot.push_back(t->E_total);
    rec.EPre.push_back(t->E_PCAL);
    rec.Ein.push_back(t->E_ECIN);
    rec.Eout.push_back(t->E_ECOU);
    // Double_t fMass = particleMass(fPid);
    // TLorentzVector* fGamma = t->GetCorrPhotonMomentum(row);
    // Double_t fPx = t->Px();
    // Double_t fPy = t->Py();
    // Double_t fPz = t->Pz();
    // Double_t fP = TMath::Sqrt(fPx * fPx + fPy * fPy + fPz * fPz);
    // Double_t fE = (fPid == 22) * fGamma->E() + (fPid != 22) * TMath::Sqrt(fMass * fMass + fP * fP);
    // Double_t fZ = fE / t->Nu();
    rec.Px.push_back(t->p_x);
    rec.Py.push_back(t->p_y);
    rec.Pz.push_back(t->p_z);
    rec.P.push_back(t->p);
    rec.PhiLab.push_back(t->PhiLab());
    rec.ThetaLab.push_back(t->ThetaLab());
    rec.Eh.push_back(t->Eh());
    rec.Zh.push_back(t->z_h);
    rec.ThetaPQ.push_back(t->theta_PQ);
    rec.PhiPQ.push_back(t->phi_PQ);
    // Double_t fCosThetaPQ = (fPz * (kEbeam - t->Pz(0)) - fPx * t->Px(0) - fPy * t->Py(0)) / (TMath::Sqrt(t->Nu() * t->Nu() + t->Q2()) * fP);
    // Double_t fPt2 = fP * fP * (1 - fCosThetaPQ * fCosThetaPQ);
    // Double_t fPl2 = fP * fP * fCosThetaPQ * fCosThetaPQ;
    rec.Pt2.push_back(t->p_T2);
    rec.Pl2.push_back(t->p_L2);
    rec.Mx2.push_back(t->Mx2());
    rec.T.push_back(t->T());
    rec.Betta.push_back(t->beta); // BettaMeasured
    rec.Mass2.push_back(t->Mass2());
    // rec.T4.push_back(t->PathSC(0) / 30. - t->TimeSC(0) + t->TimeSC(row) -
    //                  (t->PathSC(row) / 30.) * TMath::Sqrt(TMath::Power(fMass / fP, 2) + 1));
    rec.Xf.push_back(t->Xf());
    // rec.StatDC.push_back(t->StatDC(row));
    // rec.DCStatus.push_back(t->DCStatus(row));
    // rec.StatEC.push_back(t->StatEC(row));
    // rec.ECStatus.push_back(t->ECStatus(row));
    // rec.TimeEC.push_back(t->TimeEC(row));
    // rec.PathEC.push_back(t->PathEC(row));
    // rec.Chi2EC.push_back(t->Chi2EC(row));
    // rec.StatSC.push_back(t->StatSC(row));
    // rec.SCStatus.push_back(t->SCStatus(row));
    // rec.TimeSC.push_back(t->TimeSC(row));
    // rec.PathSC.push_back(t->PathSC(row));
    // rec.StatCC.push_back(t->StatCC(row));
    // rec.CCStatus.push_back(t->CCStatus(row));
    rec.Nphe.push_back(t->Nphe_HTCC);
    rec.Chi2CC.push_back(t->chi2);
    rec.Status.push_back(t->status);
    // rec.NRowsDC.push_back(t->NRowsDC());
    // rec.NRowsEC.push_back(t->NRowsEC());
    // rec.NRowsSC.push_back(t->NRowsSC());
    // rec.NRowsCC.push_back(t->NRowsCC());
}

void ClearParticleVar_REC(struct rec_p &rec) {
    // reconstructed particles (50 variables)
    rec.pid.clear();
    rec.vxh.clear();
    rec.vyh.clear();
    rec.vzh.clear();
    rec.Sector.clear();
    // rec.deltaZ.clear();
    // rec.XEC.clear();
    // rec.YEC.clear();
    // rec.ZEC.clear();
    rec.Etot.clear();
    rec.EPre.clear();
    rec.Ein.clear();
    rec.Eout.clear();
    rec.Px.clear();
    rec.Py.clear();
    rec.Pz.clear();
    rec.P.clear();
    rec.PhiLab.clear();
    rec.ThetaLab.clear();
    rec.Eh.clear();
    rec.Zh.clear();
    rec.ThetaPQ.clear();
    rec.PhiPQ.clear();
    rec.Pt2.clear();
    rec.Pl2.clear();
    rec.Mx2.clear();
    rec.T.clear();
    rec.Betta.clear();
    rec.Mass2.clear();
    // rec.T4.clear();
    rec.Xf.clear();
    // rec.StatDC.clear();
    // rec.DCStatus.clear();
    // rec.StatEC.clear();
    // rec.ECStatus.clear();
    // rec.TimeEC.clear();
    // rec.PathEC.clear();
    // rec.Chi2EC.clear();
    // rec.StatSC.clear();
    // rec.SCStatus.clear();
    // rec.TimeSC.clear();
    // rec.PathSC.clear();
    // rec.StatCC.clear();
    // rec.CCStatus.clear();
    rec.Nphe.clear();
    rec.Chi2CC.clear();
    rec.Status.clear();
    // rec.NRowsDC.clear();
    // rec.NRowsEC.clear();
    // rec.NRowsSC.clear();
    // rec.NRowsCC.clear();
}

void NullElectronVar_REC(struct rec_p &rec) {
    // reconstructed electron (46 variables)
    rec.Q2 = INVLD;
    rec.W = INVLD;
    rec.Nu = INVLD;
    rec.Xb = INVLD;
    rec.Yb = INVLD;
    rec.vxe = INVLD;
    rec.vye = INVLD;
    rec.vze = INVLD;
    rec.SectorEl = INVLD;
    rec.Pex = INVLD;
    rec.Pey = INVLD;
    rec.Pez = INVLD;
    rec.Pe = INVLD;
    rec.BettaEl = INVLD;
    rec.Etote = INVLD;
    rec.EPreE = INVLD;
    rec.Eine = INVLD;
    rec.Eoute = INVLD;
    rec.vxec = INVLD;
    rec.vyec = INVLD;
    rec.vzec = INVLD;
    rec.TargType = INVLD;
    // rec.XECe = INVLD;
    // rec.YECe = INVLD;
    // rec.ZECe = INVLD;
    rec.ThetaLabEl = INVLD;
    rec.PhiLabEl = INVLD;
    // rec.StatDCEl = INVLD;
    // rec.DCStatusEl = INVLD;
    // rec.StatECEl = INVLD;
    // rec.ECStatusEl = INVLD;
    // rec.TimeECEl = INVLD;
    // rec.PathECEl = INVLD;
    // rec.Chi2ECEl = INVLD;
    // rec.StatSCEl = INVLD;
    // rec.SCStatusEl = INVLD;
    // rec.TimeSCEl = INVLD;
    // rec.PathSCEl = INVLD;
    // rec.StatCCEl = INVLD;
    // rec.CCStatusEl = INVLD;
    rec.NpheEl = INVLD;
    rec.Chi2CCEl = INVLD;
    rec.StatusEl = INVLD;
    rec.BeamEnergy = INVLD;
    // rec.NRowsDCEl = INVLD;
    // rec.NRowsECEl = INVLD;
    // rec.NRowsSCEl = INVLD;
    // rec.NRowsCCEl = INVLD;
}

void NullParticleVar_REC(struct rec_p &rec) {
    // reconstructed particles (50 variables)
    rec.pid.push_back(INVLD);
    rec.Eh.push_back(INVLD);
    rec.Zh.push_back(INVLD);
    rec.ThetaPQ.push_back(INVLD);
    rec.PhiPQ.push_back(INVLD);
    rec.Pt2.push_back(INVLD);
    rec.Pl2.push_back(INVLD);
    rec.Mx2.push_back(INVLD);
    rec.T.push_back(INVLD);
    rec.ThetaLab.push_back(INVLD);
    rec.PhiLab.push_back(INVLD);
    // rec.T4.push_back(INVLD);
    rec.Xf.push_back(INVLD);
    rec.vxh.push_back(INVLD);
    rec.vyh.push_back(INVLD);
    rec.vzh.push_back(INVLD);
    rec.Sector.push_back(INVLD);
    rec.Px.push_back(INVLD);
    rec.Py.push_back(INVLD);
    rec.Pz.push_back(INVLD);
    rec.P.push_back(INVLD);
    rec.Betta.push_back(INVLD);
    rec.Mass2.push_back(INVLD);
    rec.Etot.push_back(INVLD);
    rec.EPre.push_back(INVLD);
    rec.Ein.push_back(INVLD);
    rec.Eout.push_back(INVLD);
    // rec.XEC.push_back(INVLD);
    // rec.YEC.push_back(INVLD);
    // rec.ZEC.push_back(INVLD);
    // rec.deltaZ.push_back(INVLD);
    // rec.StatDC.push_back(INVLD);
    // rec.DCStatus.push_back(INVLD);
    // rec.StatEC.push_back(INVLD);
    // rec.ECStatus.push_back(INVLD);
    // rec.TimeEC.push_back(INVLD);
    // rec.PathEC.push_back(INVLD);
    // rec.Chi2EC.push_back(INVLD);
    // rec.StatSC.push_back(INVLD);
    // rec.SCStatus.push_back(INVLD);
    // rec.TimeSC.push_back(INVLD);
    // rec.PathSC.push_back(INVLD);
    // rec.StatCC.push_back(INVLD);
    // rec.CCStatus.push_back(INVLD);
    rec.Nphe.push_back(INVLD);
    rec.Chi2CC.push_back(INVLD);
    rec.Status.push_back(INVLD);
    // rec.NRowsDC.push_back(INVLD);
    // rec.NRowsEC.push_back(INVLD);
    // rec.NRowsSC.push_back(INVLD);
    // rec.NRowsCC.push_back(INVLD);
}

#endif
