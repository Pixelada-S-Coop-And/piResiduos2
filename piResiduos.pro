######################################################################
# generated by pvdevelop at: mié mar 8 12:47:31 2017
######################################################################

TEMPLATE = app
CONFIG  += warn_on release
CONFIG  += qt 
QT      += sql widgets

# Input
#HEADERS += rldefine.h
HEADERS += pvapp.h      \  
           mask10_tools.h \
           mask10_data.h \ 
           mask10_slots.h \
           mask9_tools.h \
           mask9_data.h \ 
           mask9_slots.h \
           mask8_tools.h \
           mask8_data.h \ 
           mask8_slots.h \
           mask7_tools.h \
           mask7_data.h \ 
           mask7_slots.h \
           mask6_tools.h \
           mask6_data.h \ 
           mask6_slots.h \
           mask_tools.h \
           mask5_actualiza.h \
           mask5_tools.h \
           mask5_data.h \	
           mask5_slots.h \
           mask4_actualiza.h \
           mask4_tools.h \
           mask4_data.h \
           mask4_slots.h \
           mask3_slots.h \
           camera.h \
           mask2_actualiza.h \
           mask2_tools.h \
           mask2_data.h \
           mask2_slots.h \
           mask1_slots.h \
	   qtdatabase.h \
           database.h \
           bascula.h \
           outputForm.h \
           inputForm.h \
	   formulario.h \
	   tableta.h \
	   costumer.h \
	   station.h \
	   ini.h \
           mail.h \
           generic_tools.h \
	   staff.h \
	   driver.h \
           printable.h \
           printableTicket.h \
           printableDI.h
SOURCES += main.cpp     \
           mask10.cpp \
           mask9.cpp \
           mask8.cpp \
           mask7.cpp \
           mask6.cpp \
           mask5.cpp \
           mask4.cpp \
           mask3.cpp \
	   camera.cpp \
           mask2.cpp \
           mask1.cpp \
	   qtdatabase.cpp \
	   database.cpp  \
	   bascula.cpp  \
           outputForm.cpp \
           inputForm.cpp \
           formulario.cpp \
	   tableta.cpp  \
           station.cpp \
	   costumer.cpp \
	   ini.cpp \
           mail.cpp \
           generic_tools.cpp \
	   staff.cpp \
           driver.cpp \
           printable.cpp \
           printableTicket.cpp \
           printableDI.cpp


!macx {
QMAKE_CXXFLAGS    += -g -std=gnu++11
unix:LIBS	  += ./WacomGSS/build/Linux/x86_64/WacomGSS.a
unix:LIBS         += /usr/lib/libpvsmt.so -lpthread
#unix:LIBS        += /usr/lib/libpvsid.so
unix:INCLUDEPATH  += /opt/pvb/pvserver
unix:LIBS         += /usr/lib/librllib.so
unix:LIBS         += -lboost_system -lboost_thread
unix:LIBS	  += -lusb-1.0 -lcrypto -lssl -lpthread -lrt -lhpdf -lcups
unix:INCLUDEPATH  += /opt/pvb/rllib/lib
unix:INCLUDEPATH  += /usr/include/libusb-1.0
unix:INCLUDEPATH  += WacomGSS/include
unix:INCLUDEPATH  += ./lib
unix:INCLUDEPATH  += ./lib/SmtpClient-for-Qt/src
unix:LIBS         += ./lib/SmtpClient-for-Qt/libSMTPEmail.so

}

macx:LIBS         += /opt/pvb/pvserver/libpvsmt.a /usr/lib/libpthread.dylib
#macx:LIBS        += /opt/pvb/pvserver/libpvsid.a
macx:INCLUDEPATH  += /opt/pvb/pvserver
macx:LIBS         += /usr/lib/librllib.dylib
macx:INCLUDEPATH  += /opt/pvb/rllib/lib

#
# Attention:
# starting with mingw 4.8 we use mingw pthread and not our own mapping to windows threads
# you will have to adjust existing pro files
#
win32-g++ {
QMAKE_LFLAGS      += -static-libgcc
win32:LIBS        += $(PVBDIR)/win-mingw/bin/libserverlib.a 
win32:LIBS        += $(PVBDIR)/win-mingw/bin/librllib.a
win32:LIBS        += -lws2_32 -ladvapi32 -lpthread
win32:INCLUDEPATH += $(PVBDIR)/pvserver
win32:INCLUDEPATH += $(PVBDIR)/rllib/lib
}

#DEFINES += USE_INETD
TARGET = piResiduos
