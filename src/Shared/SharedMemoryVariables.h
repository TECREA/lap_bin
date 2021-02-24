#ifndef SHAREDMEMORYVARIABLES_H
#define SHAREDMEMORYVARIABLES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
    
#define LAPST01_KEYNUMBER      0x73AA2211
#define LAPST01_KEYFILE        "/home/pi/lapst01_iokeyfile" 

    
#define LAPST01_SEMAPHORE_NAME   "/camkitsem01"      

    
#define PROCESS_MONITOR         	0
#define PROCESS_DAQ             	1
#define PROCESS_REGISTER        	2
#define PROCESS_REMOTE_REPORT   	3    
#define PROCESS_MODBUS_TCPMASTER     	4
#define PROCESS_MODBUS_SLAVE            5
#define PROCESS_ALARMC_CHECK            6
#define PROCESS_MODBUS_TCP              7
    
typedef float real_t;    
    
typedef enum {
              E_ConectivityChanged,
              E_InternetDisconection,        
              E_DCVoltageAlarm, 
              E_ACVoltageAlarm, 
              E_DigitalInputsAlarm, 
             } AppEvent_t;    
    
#pragma pack(push)
#pragma pack(1)
typedef struct{
    //Input registers
    real_t ACVoltageSample[2];
    real_t DCVoltageSample[1];
    real_t DCCurrentSample[3];
    real_t ACLineFrequency[2];    
    AppEvent_t EventCode;  //36
    //input  bits registers
    uint8_t DigitalInputs[4];  
    uint8_t InternetConectivityAvailable;
    uint8_t EthernetHardwreAvaible;
    uint8_t WifiHardwareAvailable;
    uint8_t CellularHardwareAvailable;
    uint8_t PPP_ConectivityAvailable;  //9
    //Outputs bit coils
    uint8_t RelayOutput;
    uint8_t DCCurrentSelectorFlag[3]; //4
       
    //private(do not use)
    pid_t AppProcessID[8];  //69ipcs
    //modbus request
    uint16_t inputreg[80], coilreg[80];
    uint8_t inputbit[80], outputreg[80];	
    char GPSData[100];
    uint8_t ConectiontoServerDone;
    uint8_t UserLED[4];
}IOSamples_t;
#pragma pack(pop)
extern IOSamples_t *SharedIOSamples;
extern sem_t *SemaphoreIO;
    


#ifdef __cplusplus
}
#endif

#endif /* SHAREDMEMORYVARIABLES_H */

