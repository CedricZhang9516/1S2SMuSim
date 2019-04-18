//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// P00RunData.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "P00RunData.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "Geometry.hh"

#include "G4Track.hh"
#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4TouchableHandle.hh"
#include "G4VProcess.hh"
#include "G4VPhysicalVolume.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........
P00RunData::P00RunData()
  : G4Run(), fVolumeNames{{ "Target"}}
  , hitTgt0(0), hitTgt1(0), extTgt0(0), extTgt1(0)
{
  for ( auto& edep : fEdep)            { edep = 0.; }
  for ( auto& xPosition : fXPosition ) { xPosition = 0.; }
  for ( auto& yPosition : fYPosition ) { yPosition = 0.; }
  for ( auto& zPosition : fZPosition ) { zPosition = 0.; }
  for ( auto& kinEnergy : fKinEnergy ) { kinEnergy = 0.; }
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........
P00RunData::~P00RunData()
{;}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........

G4int P00RunData::GetProcID( const G4String& procName )
{
       if( procName == "UserDefinedLimit" ) return 1;
  else if( procName == "Transportation"   ) return 2;
  else if( procName == "muIoni"           ) return 3;
  else if( procName == "Decay"            ) return 4;
  else if( procName == "msc"              ) return 5;
       G4cout << "GetProcID: Unexpected process name: "
	      << procName << G4endl;
       return 0;
}

void
P00RunData::SetAllVars( const G4Step* aStep, TreeVars& tv,
			const G4int& iSetLevel=0, const G4int& index=0 )
{
  SetTrkVars(aStep,tv,iSetLevel);
  SetPntVars(aStep,tv,index);
  //  SetStpVars(aStep,tv);
  //  SetPntVars(aStep,tv,0);
  //  SetPntVars(aStep,tv,1);
}

void
P00RunData::SetTrkVars( const G4Step* aStep, TreeVars& tv,
			const G4int& iSetLevel=0 )
{
  G4Track* aTrack = aStep->GetTrack();

  tv.trkStat   = (G4int)aTrack->GetTrackStatus();
  tv.trkStpNum = aTrack->GetCurrentStepNumber();
  tv.trkLen    = aTrack->GetTrackLength();
  //  tv.stpLen    = aTrack->GetStepLength(); // Also available from step info.

  //--> Also available from step-point info.
  if( iSetLevel > 0 ){
    const G4int index= 2;
    tv.pntPrpT[index] = aTrack->GetProperTime();
    tv.pntLocT[index] = aTrack->GetLocalTime();
    tv.pntVelo[index] = aTrack->GetVelocity();
    tv.pntKinE[index] = aTrack->GetKineticEnergy();
    tv.pntVtx[index]  = aTrack->GetPosition();
    tv.pntMom[index]  = aTrack->GetMomentum();
    //  tv.pol        = aTrack->GetPolarization();
    //  tv.glbtime    = aTrack->GetGlobalTime();
    //  tv.totE       = aTrack->GetTotalEnergy();
  }
}

void
P00RunData::SetStpVars( const G4Step* aStep, TreeVars& tv )
{
  tv.stpLen     = aStep->GetStepLength();
  tv.stpDelT    = aStep->GetDeltaTime();
  tv.stpDelTotE = aStep->GetTotalEnergyDeposit();
  tv.stpDelNiE  = aStep->GetNonIonizingEnergyDeposit();
  tv.stpDelVtx  = aStep->GetDeltaPosition();
}

void
P00RunData::SetPntVars( const G4Step* aStep, TreeVars& tv,
			const G4int& index=0 )
{
  G4StepPoint* aPoint = nullptr;
  switch( index ){
  case 0: aPoint = aStep->GetPreStepPoint();  break;
  case 1: aPoint = aStep->GetPostStepPoint(); break;
  default:
    std::cout << "SetPntVars::unexpected index: " << index << std::endl;
    return;
  }

  const G4VProcess* aProcess = aPoint->GetProcessDefinedStep();
  G4String procName("UserDefinedLimit");
  G4int procType= -1;
  if( aProcess ){
    procName= aProcess->GetProcessName();
    procType= (G4int)aProcess->GetProcessType();
  }

  G4VPhysicalVolume* vol= aPoint->GetPhysicalVolume();
  G4int volId= -1;
  if( vol ) volId = Geometry::volumeID[vol->GetName()];

  tv.pntStpStat[index] = (G4int)aPoint->GetStepStatus();
  tv.pntPrcType[index] = procType;
  tv.pntPrcId[index]   = GetProcID(procName);
  tv.pntVolId[index]   = volId;
  tv.pntBeta[index]    = aPoint->GetBeta();  // Velocity in unit of c.
  tv.pntGamma[index]   = aPoint->GetGamma(); // = 1/sqrt[1-beta*beta].

  //-- Also available from track info.
  tv.pntPrpT[index]    = aPoint->GetProperTime();
  tv.pntLocT[index]    = aPoint->GetLocalTime();
  tv.pntVelo[index]    = aPoint->GetVelocity();
  tv.pntKinE[index]    = aPoint->GetKineticEnergy();
  tv.pntVtx[index]     = aPoint->GetPosition();
  tv.pntMom[index]     = aPoint->GetMomentum();
  //    tv.pol         = aPoint->GetPolarization();
  //    tv.glbtime     = aPoint->GetGlobalTime();
  //    tv.totE        = aPoint->GetTotalEnergy();
}

void
P00RunData::ClearVars( TreeVars& tv )
{
  G4ThreeVector zeroVct(0,0,0);

  tv.tgtLevel   = 0;
  
  tv.trkStat    = -1;
  tv.trkStpNum  = -1;
  tv.trkLen     = -1;

  tv.stpLen     = -1;
  tv.stpDelT    = -1;
  tv.stpDelTotE = -1;
  tv.stpDelNiE  = -1;
  tv.stpDelVtx  = zeroVct;

  for( G4int index= 0; index<2; index++ ){
    tv.pntStpStat[index] = -1;
    tv.pntPrcType[index] = -1;
    tv.pntPrcId[index]   = -1;
    tv.pntVolId[index]   = -1;
    tv.pntBeta[index]    = -1;
    tv.pntGamma[index]   = -1;
  }
  
  for( G4int index= 0; index<3; index++ ){
    tv.pntPrpT[index] = -1;
    tv.pntLocT[index] = -1;
    tv.pntVelo[index] =  0;
    tv.pntKinE[index] = -1;
    tv.pntVtx[index]  = zeroVct;
    tv.pntMom[index]  = zeroVct;
    //  tv.pol        = zeroVct;
    //  tv.glbtime    = -1;
    //  tv.totE       = -1;
  }
}

void
P00RunData::CreateColumns( G4AnalysisManager* mgr, const G4String& prefix )
{
  mgr->CreateNtupleIColumn(prefix+"TgtLevel");

  mgr->CreateNtupleIColumn(prefix+"TrkStat");
  mgr->CreateNtupleIColumn(prefix+"StpNum");
  mgr->CreateNtupleDColumn(prefix+"TrkLen");

  /*
  mgr->CreateNtupleDColumn(prefix+"StpLen");
  mgr->CreateNtupleDColumn(prefix+"StpDelT");
  mgr->CreateNtupleDColumn(prefix+"StpDelTotE");
  mgr->CreateNtupleDColumn(prefix+"StpDelNiE");
  mgr->CreateNtupleDColumn(prefix+"StpDelVtxX");
  mgr->CreateNtupleDColumn(prefix+"StpDelVtxY");
  mgr->CreateNtupleDColumn(prefix+"StpDelVtxZ");
  */
  
  mgr->CreateNtupleIColumn(prefix+"StpStat");
  mgr->CreateNtupleIColumn(prefix+"PrcType");
  mgr->CreateNtupleIColumn(prefix+"PrcId"  );
  mgr->CreateNtupleIColumn(prefix+"VolId"  );
  mgr->CreateNtupleDColumn(prefix+"Beta"   );
  mgr->CreateNtupleDColumn(prefix+"Gamma"  );

  mgr->CreateNtupleDColumn(prefix+"PrpT");
  mgr->CreateNtupleDColumn(prefix+"LocT");
  mgr->CreateNtupleDColumn(prefix+"Velo");
  mgr->CreateNtupleDColumn(prefix+"KinE");
  mgr->CreateNtupleDColumn(prefix+"VtxX");
  mgr->CreateNtupleDColumn(prefix+"VtxY");
  mgr->CreateNtupleDColumn(prefix+"VtxZ");
  mgr->CreateNtupleDColumn(prefix+"Mom" );
  mgr->CreateNtupleDColumn(prefix+"MomX");
  mgr->CreateNtupleDColumn(prefix+"MomY");
  mgr->CreateNtupleDColumn(prefix+"MomZ");

  /*
  for( G4int index= 0; index<2; index++ ){
    G4String snum = std::to_string(index);
    mgr->CreateNtupleIColumn(prefix+"StpStat"+snum);
    mgr->CreateNtupleIColumn(prefix+"PrcType"+snum);
    mgr->CreateNtupleIColumn(prefix+"PrcId"  +snum);
    mgr->CreateNtupleIColumn(prefix+"VolId"  +snum);
    mgr->CreateNtupleDColumn(prefix+"Beta"   +snum);
    mgr->CreateNtupleDColumn(prefix+"Gamma"  +snum);
  }

  for( G4int index= 0; index<3; index++ ){
    G4String snum = std::to_string(index);
    mgr->CreateNtupleDColumn(prefix+"PrpT"+snum);
    mgr->CreateNtupleDColumn(prefix+"LocT"+snum);
    mgr->CreateNtupleDColumn(prefix+"Velo"+snum);
    mgr->CreateNtupleDColumn(prefix+"KinE"+snum);
    mgr->CreateNtupleDColumn(prefix+"VtxX"+snum);
    mgr->CreateNtupleDColumn(prefix+"VtxY"+snum);
    mgr->CreateNtupleDColumn(prefix+"VtxZ"+snum);
    mgr->CreateNtupleDColumn(prefix+"Mom" +snum);
    mgr->CreateNtupleDColumn(prefix+"MomX"+snum);
    mgr->CreateNtupleDColumn(prefix+"MomY"+snum);
    mgr->CreateNtupleDColumn(prefix+"MomZ"+snum);
  }
  */
}

void
P00RunData::FillColumns( G4AnalysisManager* mgr, const G4int& tid,
			 G4int& cid, const TreeVars& tv, const G4int& index )
{
  mgr->FillNtupleIColumn(tid,cid++,tv.tgtLevel);

  mgr->FillNtupleIColumn(tid,cid++,tv.trkStat);
  mgr->FillNtupleIColumn(tid,cid++,tv.trkStpNum);
  mgr->FillNtupleDColumn(tid,cid++,tv.trkLen);

  /*
  mgr->FillNtupleDColumn(tid,cid++,tv.stpLen);
  mgr->FillNtupleDColumn(tid,cid++,tv.stpDelT);
  mgr->FillNtupleDColumn(tid,cid++,tv.stpDelTotE);
  mgr->FillNtupleDColumn(tid,cid++,tv.stpDelNiE);
  mgr->FillNtupleDColumn(tid,cid++,tv.stpDelVtx.x());
  mgr->FillNtupleDColumn(tid,cid++,tv.stpDelVtx.y());
  mgr->FillNtupleDColumn(tid,cid++,tv.stpDelVtx.z());
  */
  
  //  for( G4int index= 0; index<2; index++ ){
    mgr->FillNtupleIColumn(tid,cid++,tv.pntStpStat[index]);
    mgr->FillNtupleIColumn(tid,cid++,tv.pntPrcType[index]);
    mgr->FillNtupleIColumn(tid,cid++,tv.pntPrcId[index]  );
    mgr->FillNtupleIColumn(tid,cid++,tv.pntVolId[index]  );
    mgr->FillNtupleDColumn(tid,cid++,tv.pntBeta[index]   );
    mgr->FillNtupleDColumn(tid,cid++,tv.pntGamma[index]  );
    //  }

    //  for( G4int index= 0; index<3; index++ ){
    mgr->FillNtupleDColumn(tid,cid++,tv.pntPrpT[index]);
    mgr->FillNtupleDColumn(tid,cid++,tv.pntLocT[index]);
    mgr->FillNtupleDColumn(tid,cid++,tv.pntVelo[index]);
    mgr->FillNtupleDColumn(tid,cid++,tv.pntKinE[index]);
    mgr->FillNtupleDColumn(tid,cid++,tv.pntVtx[index].x());
    mgr->FillNtupleDColumn(tid,cid++,tv.pntVtx[index].y());
    mgr->FillNtupleDColumn(tid,cid++,tv.pntVtx[index].z());
    mgr->FillNtupleDColumn(tid,cid++,tv.pntMom[index].mag());
    mgr->FillNtupleDColumn(tid,cid++,tv.pntMom[index].x());
    mgr->FillNtupleDColumn(tid,cid++,tv.pntMom[index].y());
    mgr->FillNtupleDColumn(tid,cid++,tv.pntMom[index].z());
    //  }
}

void
P00RunData::CreateTreeGen( const G4String& name, const G4String& title )
{
  auto mgr = G4AnalysisManager::Instance();
  mgr->CreateNtuple(name,title);
  //  CreateColumns(mgr,"prd");
  //  CreateColumns(mgr,"end");

  mgr->CreateNtupleDColumn("prdKinE");
  mgr->CreateNtupleDColumn("prdMom" );
  mgr->CreateNtupleDColumn("prdVtxX");
  mgr->CreateNtupleDColumn("prdVtxY");
  mgr->CreateNtupleDColumn("prdVtxZ");

  mgr->CreateNtupleIColumn("endTgtLevel");
  mgr->CreateNtupleIColumn("endTrkStat");
  mgr->CreateNtupleIColumn("endStpStat");
  mgr->CreateNtupleIColumn("endPrcId"  );
  mgr->CreateNtupleIColumn("endVolId"  );

  mgr->CreateNtupleDColumn("endKinE");
  mgr->CreateNtupleDColumn("endMom" );
  mgr->CreateNtupleDColumn("endVtxX");
  mgr->CreateNtupleDColumn("endVtxY");
  mgr->CreateNtupleDColumn("endVtxZ");

  mgr->FinishNtuple();
}

/*
void
P00RunData::CreateTreeTgt( const G4String& name, const G4String& title )
{
  auto mgr = G4AnalysisManager::Instance();
  mgr->CreateNtuple(name,title);
  CreateColumns(mgr,"hit0");
  CreateColumns(mgr,"hit1");
  CreateColumns(mgr,"ext0");
  CreateColumns(mgr,"ext1");
  mgr->FinishNtuple();
}
*/

void P00RunData::FillTreeGen( G4AnalysisManager* mgr, const G4int& tid )
{
  G4int cid = 0;

  //  FillColumns(mgr,tid,cid,tvGenPrd,0);
  //  FillColumns(mgr,tid,cid,tvGenEnd,1);

  mgr->FillNtupleDColumn(tid,cid++,tvGenPrd.pntKinE[0]);
  mgr->FillNtupleDColumn(tid,cid++,tvGenPrd.pntMom[0].mag());
  mgr->FillNtupleDColumn(tid,cid++,tvGenPrd.pntVtx[0].x());
  mgr->FillNtupleDColumn(tid,cid++,tvGenPrd.pntVtx[0].y());
  mgr->FillNtupleDColumn(tid,cid++,tvGenPrd.pntVtx[0].z());

  mgr->FillNtupleIColumn(tid,cid++,tvGenEnd.tgtLevel);
  mgr->FillNtupleIColumn(tid,cid++,tvGenEnd.trkStat);
  mgr->FillNtupleIColumn(tid,cid++,tvGenEnd.pntStpStat[1]);
  mgr->FillNtupleIColumn(tid,cid++,tvGenEnd.pntPrcId[1]  );
  mgr->FillNtupleIColumn(tid,cid++,tvGenEnd.pntVolId[1]  );

  mgr->FillNtupleDColumn(tid,cid++,tvGenEnd.pntKinE[1]);
  mgr->FillNtupleDColumn(tid,cid++,tvGenEnd.pntMom[1].mag());
  mgr->FillNtupleDColumn(tid,cid++,tvGenEnd.pntVtx[1].x());
  mgr->FillNtupleDColumn(tid,cid++,tvGenEnd.pntVtx[1].y());
  mgr->FillNtupleDColumn(tid,cid++,tvGenEnd.pntVtx[1].z());
  
  mgr->AddNtupleRow(tid);
}
/*
void P00RunData::FillTreeTgt( G4AnalysisManager* mgr, const G4int& tid )
{
  G4int cid = 0;
  FillColumns(mgr,tid,cid,tvTgtHit0);
  FillColumns(mgr,tid,cid,tvTgtHit1);
  FillColumns(mgr,tid,cid,tvTgtExt0);
  FillColumns(mgr,tid,cid,tvTgtExt1);
  mgr->AddNtupleRow(tid);
}
*/
void P00RunData::FillPerEvent()
{
  //  inline G4bool G4TNtupleManager<tools::wroot::ntuple>::FillNtupleTColumn
  //    (G4int ntupleId, G4int columnId, const std::string& value)
  //
  //  virtual G4bool AddNtupleRow(G4int ntupleId) final;

  auto mgr = G4AnalysisManager::Instance();
  /*
  for ( auto kinEnergy : fKinEnergy) {
    mgr->FillNtupleDColumn(1, 0, kinEnergy);
  }
  mgr->AddNtupleRow(1);

  bool IsTargetDecay = true;
  for ( auto edep : fEdep ) {
    if( edep==0 ) IsTargetDecay = false;
  }
  if( IsTargetDecay ){
    //-- fXPosition is a 1-dimension array that contain xPosition numbers
    //   for each volumn specified in P00RunData.hh
    for ( auto xPosition : fXPosition ) {
      mgr->FillNtupleDColumn(0, 0, xPosition);
    }
    for ( auto yPosition : fYPosition ) {
      mgr->FillNtupleDColumn(0, 1, yPosition);
    }
    for ( auto zPosition : fZPosition ) {
      mgr->FillNtupleDColumn(0, 2, zPosition);
    }
    mgr->AddNtupleRow(0);
  }
  */
  
  FillTreeGen(mgr,0);
  //  if( hitTgt0 > 0 || hitTgt1 > 0 ){
  //    FillTreeTgt(mgr,3);
  //  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........
void P00RunData::Reset()
{ 
  for ( auto& edep : fEdep )           { edep = 0.; }
  for ( auto& xPosition : fXPosition ) { xPosition = 0.; }
  for ( auto& yPosition : fYPosition ) { yPosition = 0.; }
  for ( auto& zPosition : fZPosition ) { zPosition = 0.; }
  for ( auto& kinEnergy : fKinEnergy ) { kinEnergy =0.; }

  hitTgt0 = 0;
  hitTgt1 = 0;
  extTgt0 = 0;
  extTgt1 = 0;
  
  ClearVars(tvGenPrd);
  ClearVars(tvGenEnd);
  //  ClearVars(tvTgtHit0);
  //  ClearVars(tvTgtHit1);
  //  ClearVars(tvTgtExt0);
  //  ClearVars(tvTgtExt1);
}
