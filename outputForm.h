/*
 *  PiResiduos
 *
 *  Copyright 2016,2017 by it's authors. 
 *
 *  Some rights reserved. See COPYING, AUTHORS.
 *  This file may be used under the terms of the GNU General Public
 *  License version 3.0 ,or any later version of GPL, as published by the Free Software Foundation
 *  and appearing in the file COPYING included in the packaging of
 *  this file.
 *
 *  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 *  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */
/**
@file formulario.h
*/
#ifndef _OUTPUT_FORM_
#define _OUTPUT_FORM_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cups/cups.h>
#include <sys/stat.h>
#include <unistd.h>

#include <math.h>
#include <setjmp.h>
#include "hpdf.h"
#include "generic_tools.h"
#include "qtdatabase.h"
#include "database.h"
#include "station.h"
#include "formulario.h"


class outputForm: public baseForm
{
 public:
 outputForm(int type) : baseForm(type,0){formSCADA=2;};
 outputForm() : baseForm(){};
  ~outputForm(){};

  int getFormType(){return LOAD_FORM;};
  
  int storeDepMov(qtDatabase & localDatabase,qtDatabase & remoteDatabase,int remote_host_connected);
  int storeDepTransfer(qtDatabase & my_local_database, qtDatabase & my_remote_database, int remote_host_connected);
   /*ORDERS*/
  void setOrders(qtDatabase & myDatabase, long station_code);
  std::vector<std::string> retOrdersTable();
  std::vector<struMovement> retOrders(){return allOrders;};
  struMovement selOrder(unsigned int index);

  /*TRANSIT*/
  int storeTransit(qtDatabase & myDatabase,qtDatabase & remoteDatabase, station * myStation, int remote_host_connected);
  void setTransit(std::vector<std::vector<std::string>> transit){vctAllTransit.clear(); vctAllTransit = transit; return;};
  std::vector<std::vector<std::string>> retTransit(){return vctAllTransit;};
  int isPlateInTransit(std::string);
  int setTransitMov(int,std::string,qtDatabase &myDatabase);
  int delTransit(int index,std::string plate, qtDatabase & myDatabase, qtDatabase & myRemoteDatabase, std::string host, int port, long station_code);

  /*TRANSFERS*/
  void setTransferMov(long myCode, station *& myStation);
  
  int isArrMov();
 
  //product permits
  //datatabase dependant
  void setArrCosProdPermits(qtDatabase & myDatabase){setArrCosProdPermitsBase(myDatabase,"SAL");};
  void forceCurrentProduct();
  void unforceCurrentProduct();
  int getFzCurrentProduct();
  //
  //int setArrPlateImage(std::string newPlateImage){myArrMovement.IMAGEN_MATRICULA = newPlateImage; return 0;};
  //std::string retArrPlateImage(){return myArrMovement.IMAGEN_MATRICULA;};
  //
  //scaling 
  int isArrPesoOk();
  int isDepPesoOk();
  int retDepScaleExpected();
  void setAndCalcScaleOut(unsigned int scale);
  int saveScaleOut(qtDatabase & myDatabase, qtDatabase &myRemoteDatabase, const char * remoteHost, int remotePort );
  //
  //codigo movimiento
  int setMovCode(std::string lastCode, int stationCode, int movementTypeCode);
  //
  //DI INFORMATION
  void setAllDiData(qtDatabase & localDatabase, station *myStation, long ourCode, long defDriverCode);
  int getAllOrderInfo(qtDatabase & localDatabase, long order_code);
  int isDiComplete();

  void createPdf(std::string printerId);

  int createTicket(std::string printerId, std::string ticketCode);
  void calculateTicketHeight(int& lines);
  void ticketHeader(HPDF_Doc &myPdf, HPDF_Page &myPage, int &line, HPDF_Font &font, std::string ticketCode, float fsize_small);
  void ticketStationTitle(HPDF_Doc &myPdf, HPDF_Page &myPage, int &line, HPDF_Font &font, float size_big, float size_medium);
  void ticketRegistrationData(HPDF_Doc &myPdf, HPDF_Page &myPage, int &line, HPDF_Font &font, float size_big, float size_medium, float size_small);
  void ticketDestinationData(HPDF_Doc &myPdf, HPDF_Page &myPage, int &line, HPDF_Font &font, float size_big, float size_medium, float size_small);
  void ticketTransportData(HPDF_Doc &myPdf, HPDF_Page &myPage, int &line, HPDF_Font &font, float size_big, float size_medium, float size_small);
  void ticketProductData(HPDF_Doc &myPdf, HPDF_Page &myPage, int &line, HPDF_Font &font, float size_big, float size_medium, float size_small);
  void ticketWeightData(HPDF_Doc &myPdf, HPDF_Page &myPage, int &line, HPDF_Font &font, float size_big, float size_medium, float size_small);
  void ticketPaidData(HPDF_Doc &myPdf, HPDF_Page &myPage, int &line, HPDF_Font &font, float size_big, float size_medium, float size_small);
  void ticketCommentData(HPDF_Doc &myPdf, HPDF_Page &myPage, int &line, HPDF_Font &font, float size_big, float size_medium, float size_small);
  void ticketStaffData(HPDF_Doc &myPdf, HPDF_Page &myPage, int &line, HPDF_Font &font, float size_big, float size_medium, float size_small);
  
    
 private:
  std::vector<std::vector<std::string>> vctAllOrders;
  std::vector<std::vector<std::string>> vctAllTransit;
  std::vector <struMovement> allOrders;
};

#endif
