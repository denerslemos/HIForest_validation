#include <iostream>
#include <fstream>
#include <TString.h>
#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TLegend.h>
#include <TLine.h>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctime>
#include <sstream>
#include "TH2.h"
#include "TCutG.h"
#include "TMath.h"
#include "TApplication.h"

using namespace std;

void CompGOROOTForestAODvsminiAOD () {



TString histnames[26]={"hiBin","hiEB", "hiEE", "hiEEminus", "hiEEplus", "hiET", "hiHF", "hiHFhit", "hiHFhitMinus", "hiHFhitPlus", "hiHFminus", "hiHFminusEta4", "hiHFplus", "hiHFplusEta4", "hiNpix", "hiNpixelTracks", "hiNtracks", "hiNtracksEtaCut", "hiNtracksEtaPtCut", "hiNtracksPtCut", "hiZDC", "hiZDCminus", "hiZDCplus", "vx", "vy", "vz"};
double  zoomxmin[26]={0.0, 0.0,   0.0,   0.0,   0.0,   0.0,   0.0,  0.0, 0.0,  0.0,  0.0, 0.0,   0.0, 0.0,   0.0,     0.0,    0.0,   0.0, 0.0,   0.0,   -1,    -1,    -1,  -0.45, -0.45, -20.0};
double zoomxmax[26]={   200.,  2500.0, 3000.0,  1400.0,       1400.0,    1200.0, 5000.0, 140000.0,      70000.0,        70000.0,       2500.0,       1000.0,        2500.0,      1000.0,         100000.0,    10000.0,          3500.0,        5000.0,         2000.0,              2000.0, 1.0, 1.0, 1.0, 0.45, 0.45, 20.0}; 

int zbins[26]={200,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400};

Int_t nVars=26;

TString filename1, filename2;
TString leg1, leg2;	
filename1="HiForestAODMinimumBias4_103X_6kEvt.root"; //AOD
filename2="HiForestMiniAOD.root";// MiniAOD

TFile* f1 = new TFile(Form("%s",filename1.Data()),"READ");
TFile* f2 = new TFile(Form("%s",filename2.Data()),"READ");

//read Trees 

Int_t phfCoincFilter2Th4;
Int_t numMinHFTower4;

//->AOD
TTree * tree1 = (TTree *)f1->Get("hiEvtAnalyzer/HiTree");
tree1->SetBranchStatus("*",0);  // disable all branches
tree1->SetBranchStatus("hiBin",1); //activate this		
tree1->SetBranchStatus("hiEB",1); //activate this
tree1->SetBranchStatus("hiEE",1); //activate this
tree1->SetBranchStatus("hiEEminus",1); //activate this
tree1->SetBranchStatus("hiEEplus",1); //activate this
tree1->SetBranchStatus("hiET",1); //activate this
tree1->SetBranchStatus("hiHF",1); //activate this
tree1->SetBranchStatus("hiHFhit",1); //activate this
tree1->SetBranchStatus("hiHFhitMinus",1); //activate this
tree1->SetBranchStatus("hiHFhitPlus",1); //activate this
tree1->SetBranchStatus("hiHFminus",1); //activate this
tree1->SetBranchStatus("hiHFminusEta4",1); //activate this
tree1->SetBranchStatus("hiHFplus",1); //activate this
tree1->SetBranchStatus("hiHFplusEta4",1); //activate this
tree1->SetBranchStatus("hiNpix",1); //activate this
tree1->SetBranchStatus("hiNpixelTracks",1); //activate this
tree1->SetBranchStatus("hiNtracks",1); //activate this
tree1->SetBranchStatus("hiNtracksEtaCut",1); //activate this
tree1->SetBranchStatus("hiNtracksEtaPtCut",1); //activate this	
tree1->SetBranchStatus("hiNtracksPtCut",1); //activate this
tree1->SetBranchStatus("hiZDC",1); //activate this
tree1->SetBranchStatus("hiZDCminus",1); //activate this
tree1->SetBranchStatus("hiZDCplus",1); //activate this
tree1->SetBranchStatus("vx",1); //activate this
tree1->SetBranchStatus("vy",1); //activate this
tree1->SetBranchStatus("vz",1); //activate this
tree1->AddFriend("skimanalysis/HltTree");
tree1->SetBranchStatus("pprimaryVertexFilter",1); //activate this
tree1->SetBranchStatus("pclusterCompatibilityFilter",1); //activate this
tree1->SetBranchStatus("phfCoincFilter2Th4",1); //activate this		
tree1->SetBranchAddress("phfCoincFilter2Th4",&phfCoincFilter2Th4);


//->miniAOD  
TTree * tree2 = (TTree *)f2->Get("hiEvtAnalyzer/HiTree");
tree2->SetBranchStatus("*",0);  // disable all branches
tree2->SetBranchStatus("hiBin",1); //activate this		
tree2->SetBranchStatus("hiEB",1); //activate this
tree2->SetBranchStatus("hiEE",1); //activate this
tree2->SetBranchStatus("hiEEminus",1); //activate this
tree2->SetBranchStatus("hiEEplus",1); //activate this
tree2->SetBranchStatus("hiET",1); //activate this
tree2->SetBranchStatus("hiHF",1); //activate this
tree2->SetBranchStatus("hiHFhit",1); //activate this
tree2->SetBranchStatus("hiHFhitMinus",1); //activate this
tree2->SetBranchStatus("hiHFhitPlus",1); //activate this
tree2->SetBranchStatus("hiHFminus",1); //activate this
tree2->SetBranchStatus("hiHFminusEta4",1); //activate this
tree2->SetBranchStatus("hiHFplus",1); //activate this
tree2->SetBranchStatus("hiHFplusEta4",1); //activate this
tree2->SetBranchStatus("hiNpix",1); //activate this
tree2->SetBranchStatus("hiNpixelTracks",1); //activate this
tree2->SetBranchStatus("hiNtracks",1); //activate this
tree2->SetBranchStatus("hiNtracksEtaCut",1); //activate this
tree2->SetBranchStatus("hiNtracksEtaPtCut",1); //activate this	
tree2->SetBranchStatus("hiNtracksPtCut",1); //activate this
tree2->SetBranchStatus("hiZDC",1); //activate this
tree2->SetBranchStatus("hiZDCminus",1); //activate this
tree2->SetBranchStatus("hiZDCplus",1); //activate this
tree2->SetBranchStatus("vx",1); //activate this
tree2->SetBranchStatus("vy",1); //activate this
tree2->SetBranchStatus("vz",1); //activate this
tree2->SetBranchStatus("numMinHFTower4",1); //activate this
tree2->SetBranchAddress("numMinHFTower4",&numMinHFTower4);
tree2->AddFriend("skimanalysis/HltTree");
tree2->SetBranchStatus("pprimaryVertexFilter",1); //activate this
tree2->SetBranchStatus("pclusterCompatibilityFilter",1); //activate this

//tree2->SetBranchStatus("phfCoincFilter2Th4",1); //activate this			
/*
tree2->AddFriend("ppTrack/trackTree");
tree2->SetBranchStatus("trkMVA",1); //activate this		
tree2->SetBranchStatus("trkAlgo",1); //activate this		
 */ 
gStyle->SetOptStat(0);
gStyle->SetOptTitle(0);


TH1D* hf1[nVars]; 
TH1D* hf2[nVars];
TH1D* hr21[nVars];

TString hf1names[26]={"hf1[0]", "hf1[1]", "hf1[2]", "hf1[3]", "hf1[4]", "hf1[5]", "hf1[6]", "hf1[7]", "hf1[8]", "hf1[9]", "hf1[10]", "hf1[11]", "hf1[12]", "hf1[13]", "hf1[14]", "hf1[15]", "hf1[16]", "hf1[17]", "hf1[18]", "hf1[19]", "hf1[20]", "hf1[21]", "hf1[22]", "hf1[23]", "hf1[24]", "hf1[25]"};
TString hf2names[26]={"hf2[0]", "hf2[1]", "hf2[2]", "hf2[3]", "hf2[4]", "hf2[5]", "hf2[6]", "hf2[7]", "hf2[8]", "hf2[9]", "hf2[10]", "hf2[11]", "hf2[12]", "hf2[13]", "hf2[14]", "hf2[15]", "hf2[16]", "hf2[17]", "hf2[18]", "hf2[19]", "hf2[20]", "hf2[21]", "hf2[22]", "hf2[23]", "hf2[24]", "hf2[25]"};

Int_t n_ev1 = tree1->GetEntriesFast(); //total number of events
Int_t n_ev2 = tree2->GetEntriesFast(); //total number of events

int num_ev1 = 0;
int num_ev_pass1=0;
int num_ev_fail1=0;

int num_ev2 = 0;
int num_ev_pass2=0;
int num_ev_fail2=0;

for (int ii=0;ii<n_ev1;ii++) {
tree1->GetEntry(ii);
num_ev1=num_ev1+1;
if(phfCoincFilter2Th4>0){num_ev_pass1=num_ev_pass1+1;}else{num_ev_fail1=num_ev_fail1+1;}
}

for (int ii=0;ii<n_ev2;ii++) {
tree2->GetEntry(ii);
num_ev2=num_ev2+1;
if(numMinHFTower4<2){num_ev_fail2=num_ev_fail2+1;}else{num_ev_pass2=num_ev_pass2+1;}
}

cout << "============================================" << endl;
cout << "Nev1: " << num_ev1 << ", Nev2: " << num_ev2 << endl;
cout << "phfCoincFilter2Th4_ADO: Number of events passed = " << num_ev_pass1 << ", number of events fail = " << num_ev_fail1 << endl;
cout << "numMinHFTower4_miniAOD: Number of events passed = " << num_ev_pass2 << ", number of events fail = " << num_ev_fail2 << endl;
cout << "============================================" << endl;


for (int j=0;j<nVars;j++) {
    //show histogram names
    TString histtt = histnames[j].Data();
	cout << histtt << endl;
	TString hf1n = hf1names[j].Data();
	cout << hf1n << endl;
	TString hf2n = hf2names[j].Data();	
	cout << hf2n << endl;				 			

    //make histograms
    hf1[j] = new TH1D(Form("%s",hf1names[j].Data()),Form("%s",hf1names[j].Data()),zbins[j],zoomxmin[j],zoomxmax[j]);
	hf2[j] = new TH1D(Form("%s",hf2names[j].Data()),Form("%s",hf2names[j].Data()),zbins[j],zoomxmin[j],zoomxmax[j]);
    //make tree >> histogram
    tree1->Draw(histtt+">>"+hf1n,"pprimaryVertexFilter && phfCoincFilter2Th4 && pclusterCompatibilityFilter","goff");					
	tree2->Draw(histtt+">>"+hf2n,"pprimaryVertexFilter && pclusterCompatibilityFilter && numMinHFTower4 >= 2","goff");							 										
    //normalize
    hf1[j]->Scale(1/hf1[j]->Integral());
	hf2[j]->Scale(1/hf2[j]->Integral());
	hr21[j]=(TH1D*)hf2[j]->Clone();
	hr21[j]->Sumw2();
    hr21[j]->Divide(hf2[j],hf1[j],1,1,"B");
    
	gStyle->SetCanvasDefH(539); gStyle->SetCanvasDefW(567);
	TCanvas* cz1 = new TCanvas("cz1","");
	TPad* pz1 = new TPad("pz1","",0.0,0.30,1.0,1.0,21);
	TPad* pz2 = new TPad("pz2","",0.0,0.0,1.0,0.30,21);

	pz1->SetFillColor(0);
	pz2->SetFillColor(0);

	pz1->SetTopMargin(0.05);
	pz1->SetBottomMargin(0.0);
	pz1->SetLeftMargin(0.15);
	pz1->SetRightMargin(0.05);

	pz2->SetTopMargin(0.05);
	pz2->SetBottomMargin(0.3);
	pz2->SetLeftMargin(0.15);
	pz2->SetRightMargin(0.05);

	pz1->Draw();
	pz2->Draw();

	pz1->cd();
	pz1->SetLogy(1);

	hf1[j]->SetFillColor(8);
	hf1[j]->SetMarkerSize(1.2);
	hf1[j]->SetMarkerStyle(24);
	hf1[j]->SetMarkerColor(kRed);
	hf1[j]->SetLineColor(kRed);
	hf1[j]->SetStats(kFALSE);

	hf2[j]->SetMarkerSize(1.0);
	hf2[j]->SetMarkerStyle(25);
	hf2[j]->SetMarkerColor(kBlack);
	hf2[j]->SetLineColor(kBlack);


	hf1[j]->GetYaxis()->SetRangeUser(0.000009,10);
	hf1[j]->GetXaxis()->SetRangeUser(zoomxmin[j],zoomxmax[j]);
	hf2[j]->GetXaxis()->SetRangeUser(zoomxmin[j],zoomxmax[j]);


	hf1[j]->Draw("pe");
    hf1[j]->Draw("same pe");
	hf2[j]->Draw("same pe");
	hf1[j]->GetYaxis()->SetTitle("Normalized Distributions");
	hf1[j]->GetYaxis()->SetTitleSize(0.05);
        hf1[j]->GetYaxis()->SetLabelSize(0.05);
	TLegend* leg11 = new TLegend(0.65,0.70,0.9,0.85);
	leg11->AddEntry(hf1[j],"AOD","lp" );
	leg11->AddEntry(hf2[j],"MiniAOD","lp");
        leg11->SetTextSize(0.07);
   	leg11->SetFillStyle(1);
	leg11->SetLineWidth(0);
	leg11->Draw();

	pz2->cd();
	hr21[j]->GetXaxis()->SetRangeUser(zoomxmin[j],zoomxmax[j]);
	hr21[j]->GetYaxis()->SetRangeUser(0.0,2.05);	
	hr21[j]->SetMarkerStyle(20);
	hr21[j]->SetMarkerColor(kBlack);
	hr21[j]->SetStats(kFALSE);
	hr21[j]->GetXaxis()->SetTitle(Form("%s",histnames[j].Data()));
	hr21[j]->GetYaxis()->SetTitle("Ratio");
	hr21[j]->GetXaxis()->SetTitleOffset(0.75);
	hr21[j]->GetXaxis()->SetTitleSize(0.14);
	hr21[j]->GetYaxis()->SetTitleSize(0.12);
	hr21[j]->GetYaxis()->SetTitleOffset(0.4);
	hr21[j]->GetYaxis()->SetLabelSize(0.09);
	hr21[j]->GetXaxis()->SetLabelSize(0.12);
        hr21[j]->GetYaxis()->CenterTitle(1);
	hr21[j]->Draw("pe");

    TLegend* leg12 = new TLegend(0.65,0.80,0.90,0.95);
	leg12->AddEntry(hr21[j],"MiniAOD / AOD","lp");
	leg12->SetFillStyle(1);
	leg12->SetLineWidth(0);
	leg12->Draw();

	TLine* lz2 = new TLine(zoomxmin[j],1.0,zoomxmax[j],1.0);
	lz2->SetLineStyle(7);
	lz2->SetLineWidth(2);
	lz2->Draw();
    cz1->Update();
	cz1->SaveAs(Form("./results/Forest_h_%s.pdf",histnames[j].Data()));
	cz1->Update();
	}
}

