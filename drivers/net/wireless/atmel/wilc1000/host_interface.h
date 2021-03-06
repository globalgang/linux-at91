/*!  
*  @file	host_interface.h
*  @brief	File containg host interface APIs
*  @author	zsalah
*  @sa		host_interface.c
*  @date	8 March 2012
*  @version	1.0
*/

#ifndef HOST_INT_H
#define HOST_INT_H

#include "coreconfigurator.h"
#include "coreconfigsimulator.h"
/*****************************************************************************/
/*								Macros                                       */
/*****************************************************************************/
#if 0
#define WID_BSS_TYPE				0x0000
#define WID_CURRENT_TX_RATE			0x0001
#define WID_CURRENT_CHANNEL			0x0002
#define WID_PREAMBLE				0x0003
#define WID_STATUS					0x0005
#define WID_SCAN_TYPE				0x0007
#define WID_KEY_ID					0x0009
#define	WID_DTIM_PERIOD				0x0010
#define	WID_POWER_MANAGEMENT		0x000B
#define WID_AUTH_TYPE				0x000D
#define WID_SITE_SURVEY				0x000E
#define WID_DTIM_PERIOD				0x0010
#define WID_DISCONNECT				0x0016
#define WID_SHORT_SLOT_ALLOWED		0x001A
#define WID_START_SCAN_REQ			0x001E
#define WID_RSSI					0x001F
#define WID_JOIN_REQ				0x0020
#define WID_11N_TXOP_PROT_DISABLE	0x00B0
#define WID_RTS_THRESHOLD			0x1000
#define WID_FRAG_THRESHOLD			0x1001
#define WID_SHORT_RETRY_LIMIT		0x1002
#define WID_LONG_RETRY_LIMIT		0x1003
#define WID_BEACON_INTERVAL			0x1006
#define WID_ACTIVE_SCAN_TIME		0x100C
#define WID_PASSIVE_SCAN_TIME		0x100D
#define WID_SITE_SURVEY_SCAN_TIME	0x100E
#define WID_AUTH_TIMEOUT			0x1010
#define WID_11I_PSK					0x3008
#define WID_SITE_SURVEY_RESULTS		0x3012
#define WID_ADD_PTK					0x301B
#define WID_ADD_RX_GTK				0x301C
#define WID_ADD_TX_GTK				0x301D
#define WID_ADD_WEP_KEY				0x3019
#define	WID_REMOVE_WEP_KEY			0x301A
#define WID_REMOVE_KEY				0x301E
#define WID_ASSOC_REQ_INFO			0x301F
#define WID_ASSOC_RES_INFO			0x3020
#define WID_PMKID_INFO				0x3082
#define WID_SCAN_CHANNEL_LIST		0x4084
#define WID_11I_MODE			    0x000C
#endif
#define FAIL		0x0000
#define SUCCESS		0x0001

#define IP_ALEN  4

#define BIT2                    ((WILC_Uint32)(1 << 2))
#define BIT1                    ((WILC_Uint32)(1 << 1))
#define BIT0                    ((WILC_Uint32)(1 << 0))

#define AP_MODE     	0x01
#define STATION_MODE	0x02
#define GO_MODE	0x03
#define CLIENT_MODE	0x04


#define MAX_NUM_STA                 9
#define ACTIVE_SCAN_TIME			10
#define PASSIVE_SCAN_TIME			1200
#define MIN_SCAN_TIME				10
#define MAX_SCAN_TIME				1200
#define DEFAULT_SCAN				0
#define USER_SCAN					BIT0
#define OBSS_PERIODIC_SCAN			BIT1
#define OBSS_ONETIME_SCAN			BIT2
#define GTK_RX_KEY_BUFF_LEN			24
#define ADDKEY						0x1
#define REMOVEKEY					0x2
#define DEFAULTKEY					0x4
#define ADDKEY_AP					0x8
#define MAX_NUM_SCANNED_NETWORKS	100 //30		// rachel
#define MAX_NUM_SCANNED_NETWORKS_SHADOW	130
#define MAX_NUM_PROBED_SSID            10  /*One more than the number of scanned ssids*/
#define CHANNEL_SCAN_TIME 			250//250

#define TX_MIC_KEY_LEN				8
#define RX_MIC_KEY_LEN				8
#define PTK_KEY_LEN					16

#define TX_MIC_KEY_MSG_LEN			26
#define RX_MIC_KEY_MSG_LEN			48
#define PTK_KEY_MSG_LEN				39

#define PMKSA_KEY_LEN				22
#define ETH_ALEN  6
#define PMKID_LEN  					16
#define WILC_MAX_NUM_PMKIDS  16
#define WILC_SUPP_MCS_SET_SIZE	16
#define WILC_ADD_STA_LENGTH	40 /* Not including the rates field cause it has variable length*/
#define SCAN_EVENT_DONE_ABORTED 
/*****************************************************************************/
/* Data Types                                                                */
/*****************************************************************************/
//typedef unsigned char	uint8;
//typedef signed char     int8;
//typedef unsigned short	uint16;
//typedef unsigned long   uint32;
//typedef uint32   Bool;

#if 0
typedef enum {WID_CHAR  = 0,
              WID_SHORT = 1,
              WID_INT   = 2,
              WID_STR   = 3,
              WID_ADR   = 4,
              WID_BIN   = 5,
              WID_IP    = 6,
              WID_UNDEF = 7
} WID_TYPE_T;
#endif
typedef struct
{
    WILC_Uint16     cfg_wid;
    WID_TYPE_T	  cfg_type;
    WILC_Sint8     *pu8Para;
} cfg_param_t;

typedef struct _tstrStatistics
{
	WILC_Uint8 	u8LinkSpeed;
	WILC_Sint8	s8RSSI;
	WILC_Uint32 	u32TxCount;
	WILC_Uint32 	u32RxCount;
	WILC_Uint32 	u32TxFailureCount;
	
}tstrStatistics;


typedef enum
{
	HOST_IF_IDLE  					= 0,
	HOST_IF_SCANNING	  			= 1,
	HOST_IF_CONNECTING				= 2,
	HOST_IF_WAITING_CONN_RESP		= 3,
	HOST_IF_CONNECTED				= 4,
	HOST_IF_P2P_LISTEN				=5,
	HOST_IF_FORCE_32BIT  			= 0xFFFFFFFF
}tenuHostIFstate;

typedef struct _tstrHostIFpmkid
{
	WILC_Uint8 bssid[ETH_ALEN];
	WILC_Uint8 pmkid[PMKID_LEN];
}tstrHostIFpmkid;

typedef struct _tstrHostIFpmkidAttr
{
	WILC_Uint8 numpmkid;
	tstrHostIFpmkid pmkidlist[WILC_MAX_NUM_PMKIDS];
}tstrHostIFpmkidAttr;
#if 0
/* Scan type parameter for scan request */
typedef enum
{
	PASSIVE_SCAN = 0,
    ACTIVE_SCAN  = 1,
    NUM_SCANTYPE
} tenuScanType;

typedef enum {SITE_SURVEY_1CH    = 0,
              SITE_SURVEY_ALL_CH = 1,
              SITE_SURVEY_OFF    = 2
} SITE_SURVEY_T;
#endif
typedef enum{AUTORATE	= 0,
			 MBPS_1		= 1,
			 MBPS_2		= 2,
			 MBPS_5_5	= 5,
			 MBPS_11	= 11,
			 MBPS_6		= 6,
			 MBPS_9		= 9,
			 MBPS_12	= 12,
			 MBPS_18	= 18,
			 MBPS_24	= 24,
			 MBPS_36	= 36,
			 MBPS_48	= 48,
			 MBPS_54	= 54

}CURRENT_TX_RATE_T;

typedef struct
{
	WILC_Uint32 u32SetCfgFlag;
	WILC_Uint8 ht_enable;
	WILC_Uint8 bss_type;
	WILC_Uint8 auth_type;
	WILC_Uint16 auth_timeout;
	WILC_Uint8 power_mgmt_mode;
	WILC_Uint16 short_retry_limit;
	WILC_Uint16 long_retry_limit;
	WILC_Uint16 frag_threshold;
	WILC_Uint16 rts_threshold;
	WILC_Uint16 preamble_type;
	WILC_Uint8 short_slot_allowed;
	WILC_Uint8 txop_prot_disabled;
	WILC_Uint16 beacon_interval;
	WILC_Uint16 dtim_period;
	SITE_SURVEY_T site_survey_enabled;
	WILC_Uint16 site_survey_scan_time;
	WILC_Uint8 scan_source;
	WILC_Uint16 active_scan_time;
	WILC_Uint16 passive_scan_time;
	CURRENT_TX_RATE_T curr_tx_rate;

}tstrCfgParamVal;

typedef enum {
	RETRY_SHORT		= 1 << 0,
	RETRY_LONG		= 1 << 1,
	FRAG_THRESHOLD	= 1 << 2,
	RTS_THRESHOLD	= 1 << 3,
	BSS_TYPE  = 1 << 4,
	AUTH_TYPE = 1 << 5,
	AUTHEN_TIMEOUT = 1 << 6,
	POWER_MANAGEMENT = 1 << 7,
	PREAMBLE = 1 << 8,
	SHORT_SLOT_ALLOWED = 1 << 9,
	TXOP_PROT_DISABLE = 1 << 10,
	BEACON_INTERVAL = 1 << 11,
	DTIM_PERIOD = 1 << 12,
	SITE_SURVEY = 1 << 13,
	SITE_SURVEY_SCAN_TIME = 1 << 14,
	ACTIVE_SCANTIME = 1 << 15,
	PASSIVE_SCANTIME = 1 << 16,
	CURRENT_TX_RATE = 1 << 17,
	HT_ENABLE = 1 <<18,
}tenuCfgParam;

typedef struct
{
	WILC_Uint8 au8bssid[6];
	WILC_Sint8 s8rssi;
}tstrFoundNetworkInfo;

typedef enum {SCAN_EVENT_NETWORK_FOUND  = 0,
SCAN_EVENT_DONE = 1,
SCAN_EVENT_ABORTED = 2,
SCAN_EVENT_FORCE_32BIT  = 0xFFFFFFFF
}tenuScanEvent;

typedef enum
{
	CONN_DISCONN_EVENT_CONN_RESP  		= 0,
	CONN_DISCONN_EVENT_DISCONN_NOTIF 	= 1,
       CONN_DISCONN_EVENT_FORCE_32BIT  	= 0xFFFFFFFF
}tenuConnDisconnEvent;

typedef enum
{
	WEP,
	WPARxGtk,
	//WPATxGtk,
	WPAPtk,
	PMKSA,
}tenuKeyType;


/*Scan callBack function definition*/
typedef void(*tWILCpfScanResult)(tenuScanEvent, tstrNetworkInfo*, void*,void*);

/*Connect callBack function definition*/
typedef void(*tWILCpfConnectResult)(tenuConnDisconnEvent, 
									tstrConnectInfo*, 
									WILC_Uint8, 
									tstrDisconnectNotifInfo*, 
									void*);

#ifdef WILC_P2P
typedef void(*tWILCpfRemainOnChanExpired)(void*, WILC_Uint32);	/*Remain on channel expiration callback function*/
typedef void(*tWILCpfRemainOnChanReady)(void*);	/*Remain on channel callback function*/
#endif

//typedef WILC_Uint32 WILC_WFIDrvHandle;
typedef struct
{
	WILC_Sint32 s32Dummy;
}
*WILC_WFIDrvHandle;

/*!
*  @struct 		tstrRcvdNetworkInfo
*  @brief		Structure to hold Received Asynchronous Network info
*  @details		
*  @todo		
*  @sa			
*  @author		Mostafa Abu Bakr
*  @date		25 March 2012
*  @version		1.0 
*/
typedef struct _tstrRcvdNetworkInfo
{
	WILC_Uint8* pu8Buffer;
	WILC_Uint32 u32Length;
} tstrRcvdNetworkInfo;

/*BugID_4156*/
typedef struct _tstrHiddenNetworkInfo
{
	WILC_Uint8  *pu8ssid;
	WILC_Uint8  u8ssidlen;
	
}tstrHiddenNetworkInfo;

typedef struct _tstrHiddenNetwork
{
  //MAX_SSID_LEN
	tstrHiddenNetworkInfo *pstrHiddenNetworkInfo;
  	WILC_Uint8  u8ssidnum;
	
} tstrHiddenNetwork;

typedef struct
{		
	/* Scan user call back function */
	tWILCpfScanResult	pfUserScanResult;

	/* User specific parameter to be delivered through the Scan User Callback function */
	void* u32UserScanPvoid;

	WILC_Uint32 u32RcvdChCount;
	tstrFoundNetworkInfo astrFoundNetworkInfo[MAX_NUM_SCANNED_NETWORKS];	
}tstrWILC_UsrScanReq;

typedef struct
{
	WILC_Uint8* pu8bssid;
	WILC_Uint8* pu8ssid;
	WILC_Uint8 u8security;
	AUTHTYPE_T tenuAuth_type;
	size_t ssidLen;
	WILC_Uint8* pu8ConnReqIEs;
	size_t ConnReqIEsLen;
	/* Connect user call back function */
	tWILCpfConnectResult	pfUserConnectResult;
	WILC_Bool	IsHTCapable;
	/* User specific parameter to be delivered through the Connect User Callback function */
	void* u32UserConnectPvoid;
}tstrWILC_UsrConnReq;

typedef struct
{
	WILC_Uint32	u32Address;
}tstrHostIfSetDrvHandler;

typedef struct
{
	WILC_Uint32	u32Mode;
}tstrHostIfSetOperationMode;

/*BugID_5077*/
typedef struct
{
	WILC_Uint8	u8MacAddress[ETH_ALEN];
}tstrHostIfSetMacAddress;

/*BugID_5213*/
typedef struct
{
	WILC_Uint8*	u8MacAddress;
}tstrHostIfGetMacAddress;

/*BugID_5222*/
typedef struct
{
	WILC_Uint8	au8Bssid[ETH_ALEN];
	WILC_Uint8	u8Ted;
	WILC_Uint16	u16BufferSize;
	WILC_Uint16	u16SessionTimeout;
}tstrHostIfBASessionInfo;

#ifdef WILC_P2P
typedef struct
{
	WILC_Uint16     u16Channel;
	WILC_Uint32  u32duration;
	tWILCpfRemainOnChanExpired pRemainOnChanExpired;
	tWILCpfRemainOnChanReady pRemainOnChanReady;
	void *  pVoid;
	WILC_Uint32 u32ListenSessionID;
}tstrHostIfRemainOnChan;

typedef struct
{

WILC_Bool        bReg;
WILC_Uint16     u16FrameType;
WILC_Uint8       u8Regid;


}tstrHostIfRegisterFrame;


#define   ACTION         0xD0
#define   PROBE_REQ   0x40
#define   PROBE_RESP  0x50
#define   ACTION_FRM_IDX   0
#define   PROBE_REQ_IDX     1


enum p2p_listen_state
{
	P2P_IDLE,
	P2P_LISTEN,
	P2P_GRP_FORMATION
};

#endif
typedef struct
{
	/* Scan user structure */
	tstrWILC_UsrScanReq strWILC_UsrScanReq;
	
	/* Connect User structure */
	tstrWILC_UsrConnReq strWILC_UsrConnReq;

	#ifdef WILC_P2P
	/*Remain on channel struvture*/
	tstrHostIfRemainOnChan strHostIfRemainOnChan;
	WILC_Uint8 u8RemainOnChan_pendingreq;
	WILC_Uint64 u64P2p_MgmtTimeout;
	WILC_Uint8   u8P2PConnect;
	#endif

	tenuHostIFstate enuHostIFstate;

	//WILC_Bool bPendingConnRequest;

	#ifndef CONNECT_DIRECT
	WILC_Uint32 u32SurveyResultsCount;
	wid_site_survey_reslts_s astrSurveyResults[MAX_NUM_SCANNED_NETWORKS];
	#endif
	
	WILC_Uint8 au8AssociatedBSSID[ETH_ALEN];
	tstrCfgParamVal strCfgValues;
//semaphores
	WILC_SemaphoreHandle gtOsCfgValuesSem;
	WILC_SemaphoreHandle hSemTestKeyBlock;
	
	WILC_SemaphoreHandle hSemTestDisconnectBlock;
	WILC_SemaphoreHandle hSemGetRSSI;
	WILC_SemaphoreHandle hSemGetLINKSPEED;
	WILC_SemaphoreHandle hSemGetCHNL;
	WILC_SemaphoreHandle hSemInactiveTime;
//timer handlers
	WILC_TimerHandle hScanTimer;
	WILC_TimerHandle hConnectTimer;
	#ifdef WILC_P2P
	WILC_TimerHandle hRemainOnChannel;
	#endif

	WILC_Bool IFC_UP;
}tstrWILC_WFIDrv;

/*!
*  @enum 		tenuWILC_StaFlag
*  @brief			Used to decode the station flag set and mask in tstrWILC_AddStaParam
*  @details		
*  @todo		
*  @sa			tstrWILC_AddStaParam, enum nl80211_sta_flags
*  @author		Enumeraion's creator
*  @date			12 July 2012
*  @version		1.0 Description
*/

typedef enum
{
	WILC_STA_FLAG_INVALID = 0,
	WILC_STA_FLAG_AUTHORIZED,			/*!<  station is authorized (802.1X)*/
	WILC_STA_FLAG_SHORT_PREAMBLE,	/*!< station is capable of receiving frames	with short barker preamble*/
	WILC_STA_FLAG_WME,				/*!< station is WME/QoS capable*/
	WILC_STA_FLAG_MFP,					/*!< station uses management frame protection*/
	WILC_STA_FLAG_AUTHENTICATED		/*!< station is authenticated*/
}tenuWILC_StaFlag;

typedef struct
{
	WILC_Uint8 au8BSSID[ETH_ALEN];
	WILC_Uint16 u16AssocID;
	WILC_Uint8 u8NumRates;
	WILC_Uint8* pu8Rates;
	WILC_Bool bIsHTSupported;
	WILC_Uint16 u16HTCapInfo;
	WILC_Uint8 u8AmpduParams;
	WILC_Uint8 au8SuppMCsSet[16];
	WILC_Uint16 u16HTExtParams;
	WILC_Uint32 u32TxBeamformingCap;
	WILC_Uint8 u8ASELCap;
	WILC_Uint16 u16FlagsMask;		/*<! Determines which of u16FlagsSet were changed>*/
	WILC_Uint16 u16FlagsSet;		/*<! Decoded according to tenuWILC_StaFlag */
}tstrWILC_AddStaParam;

//extern void CfgDisconnected(void* pUserVoid, WILC_Uint16 u16reason, WILC_Uint8 * ie, size_t ie_len);

/*****************************************************************************/
/*																			 */
/*							Host Interface API								 */
/*																			 */
/*****************************************************************************/

/**
*  @brief 		removes wpa/wpa2 keys
*  @details 	only in BSS STA mode if External Supplicant support is enabled. 
				removes all WPA/WPA2 station key entries from MAC hardware.
*  @param[in,out] handle to the wifi driver
*  @param[in] 	6 bytes of Station Adress in the station entry table
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_remove_key(WILC_WFIDrvHandle hWFIDrv,const WILC_Uint8* pu8StaAddress);
/**
*  @brief 		removes WEP key
*  @details 	valid only in BSS STA mode if External Supplicant support is enabled.
				remove a WEP key entry from MAC HW. 
				The BSS Station automatically finds the index of the entry using its 
				BSS ID and removes that entry from the MAC hardware.
*  @param[in,out] handle to the wifi driver
*  @param[in] 	6 bytes of Station Adress in the station entry table
*  @return 		Error code indicating success/failure
*  @note 		NO need for the STA add since it is not used for processing 
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_remove_wep_key(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8 u8Index);
/**
*  @brief 		sets WEP deafault key
*  @details 	Sets the index of the WEP encryption key in use, 
				in the key table	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	key index ( 0, 1, 2, 3)
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_set_WEPDefaultKeyID(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8 u8Index);

/**
*  @brief 		sets WEP deafault key
*  @details 	valid only in BSS STA mode if External Supplicant support is enabled. 
				sets WEP key entry into MAC hardware when it receives the 
				corresponding request from NDIS.
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing WEP Key in the following format
				|---------------------------------------|
				|Key ID Value | Key Length |	Key		|
				|-------------|------------|------------|
				|	1byte	  |		1byte  | Key Length	|
				|---------------------------------------|

*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_add_wep_key_bss_sta(WILC_WFIDrvHandle hWFIDrv, const WILC_Uint8* pu8WepKey, WILC_Uint8 u8WepKeylen, WILC_Uint8 u8Keyidx);
/**
*  @brief 		host_int_add_wep_key_bss_ap
*  @details 	valid only in AP mode if External Supplicant support is enabled. 
				sets WEP key entry into MAC hardware when it receives the 
				corresponding request from NDIS.
*  @param[in,out] handle to the wifi driver


*  @return 		Error code indicating success/failure
*  @note 		
*  @author		mdaftedar
*  @date		28 Feb 2013
*  @version		1.0
*/
WILC_Sint32 host_int_add_wep_key_bss_ap(WILC_WFIDrvHandle hWFIDrv, const WILC_Uint8* pu8WepKey, WILC_Uint8 u8WepKeylen, WILC_Uint8 u8Keyidx,WILC_Uint8 u8mode, AUTHTYPE_T tenuAuth_type);

/**
*  @brief 		adds ptk Key
*  @details 	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing PTK Key in the following format
|-------------------------------------------------------------------------|
|Sta Adress | Key Length |	Temporal Key | Rx Michael Key |Tx Michael Key |
|-----------|------------|---------------|----------------|---------------|
|	6 bytes |	1byte	 |   16 bytes	 |	  8 bytes	  |	   8 bytes	  |
|-------------------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_add_ptk(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8* pu8Ptk,WILC_Uint8 u8PtkKeylen,
	const WILC_Uint8* mac_addr,WILC_Uint8* pu8RxMic,WILC_Uint8* pu8TxMic,WILC_Uint8 mode,WILC_Uint8 u8Ciphermode,WILC_Uint8 u8Idx);

/**
*  @brief 		host_int_get_inactive_time
*  @details 	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing inactive time

*  @return 		Error code indicating success/failure
*  @note 		
*  @author		mdaftedar
*  @date		15 April 2013
*  @version		1.0
*/
WILC_Sint32 host_int_get_inactive_time(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8 * mac,WILC_Uint32* pu32InactiveTime);

/**
*  @brief 		adds Rx GTk Key
*  @details 	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing Rx GTK Key in the following format
|----------------------------------------------------------------------------|
|Sta Address | Key RSC | KeyID | Key Length | Temporal Key	| Rx Michael Key |
|------------|---------|-------|------------|---------------|----------------|
|	6 bytes	 | 8 byte  |1 byte |  1 byte	|   16 bytes	|	  8 bytes	 |
|----------------------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
	WILC_Sint32 host_int_add_rx_gtk(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8RxGtk,WILC_Uint8 u8GtkKeylen,
			WILC_Uint8 u8KeyIdx,WILC_Uint32 u32KeyRSClen, WILC_Uint8* KeyRSC,
			WILC_Uint8* pu8RxMic,WILC_Uint8* pu8TxMic,WILC_Uint8 mode,WILC_Uint8 u8Ciphermode);


/**
*  @brief 		adds Tx GTk Key
*  @details 	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing Tx GTK Key in the following format
				|----------------------------------------------------|
				| KeyID | Key Length | Temporal Key	| Tx Michael Key |
				|-------|------------|--------------|----------------|
				|1 byte |  1 byte	 |   16 bytes	|	  8 bytes	 |
				|----------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_add_tx_gtk(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8 u8KeyLen,WILC_Uint8* pu8TxGtk,WILC_Uint8 u8KeyIdx);

/**
*  @brief 		caches the pmkid 
*  @details 	valid only in BSS STA mode if External Supplicant	 	
				support is enabled. This Function sets the PMKID in firmware 
				when host drivr receives the corresponding request from NDIS. 
				The firmware then includes theset PMKID in the appropriate 
				management frames		 	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing PMKID Info in the following format
|-----------------------------------------------------------------|
|NumEntries |	BSSID[1] | PMKID[1] |  ...	| BSSID[K] | PMKID[K] |
|-----------|------------|----------|-------|----------|----------|
|	   1	|		6	 |   16		|  ...	|	 6	   |	16	  |
|-----------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

WILC_Sint32 host_int_set_pmkid_info(WILC_WFIDrvHandle hWFIDrv, tstrHostIFpmkidAttr* pu8PmkidInfoArray);
/**
*  @brief 		gets the cached the pmkid info
*  @details 	valid only in BSS STA mode if External Supplicant	 	
				support is enabled. This Function sets the PMKID in firmware 
				when host drivr receives the corresponding request from NDIS. 
				The firmware then includes theset PMKID in the appropriate 
				management frames		 	
*  @param[in,out] handle to the wifi driver, 

				  message containing PMKID Info in the following format
		|-----------------------------------------------------------------|
		|NumEntries |	BSSID[1] | PMKID[1] |  ...	| BSSID[K] | PMKID[K] |
		|-----------|------------|----------|-------|----------|----------|
		|	   1	|		6	 |   16		|  ...	|	 6	   |	16	  |
		|-----------------------------------------------------------------|
*  @param[in] 	
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

WILC_Sint32 host_int_get_pmkid_info(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8* pu8PmkidInfoArray, 
									   WILC_Uint32 u32PmkidInfoLen);

/**
*  @brief 		sets the pass phrase
*  @details 	AP/STA mode. This function gives the pass phrase used to
				generate the Pre-Shared Key when WPA/WPA2 is enabled	
				The length of the field can vary from 8 to 64 bytes, 
				the lower layer should get the  	
*  @param[in,out] handle to the wifi driver, 	
*  @param[in] 	 String containing PSK 
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_set_RSNAConfigPSKPassPhrase(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8PassPhrase, 
														  WILC_Uint8 u8Psklength);
/**
*  @brief 		gets the pass phrase
*  @details 	AP/STA mode. This function gets the pass phrase used to
				generate the Pre-Shared Key when WPA/WPA2 is enabled	
				The length of the field can vary from 8 to 64 bytes, 
				the lower layer should get the  	
*  @param[in,out] handle to the wifi driver, 
				  String containing PSK 
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_get_RSNAConfigPSKPassPhrase(WILC_WFIDrvHandle hWFIDrv,
												WILC_Uint8* pu8PassPhrase, WILC_Uint8 u8Psklength);

/**
*  @brief 		gets mac address
*  @details
*  @param[in,out] handle to the wifi driver,

*  @return 		Error code indicating success/failure
*  @note
*  @author		mdaftedar
*  @date		19 April 2012
*  @version		1.0
*/
WILC_Sint32 host_int_get_MacAddress(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8* pu8MacAddress);

/**
*  @brief 		sets mac address
*  @details
*  @param[in,out] handle to the wifi driver,

*  @return 		Error code indicating success/failure
*  @note
*  @author		mabubakr
*  @date		16 July 2012
*  @version		1.0
*/
WILC_Sint32 host_int_set_MacAddress(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8* pu8MacAddress);

/**
*  @brief 		wait until msg q is empty
*  @details
*  @param[in,out] 

*  @return 		Error code indicating success/failure
*  @note
*  @author		asobhy
*  @date		19 march 2014
*  @version		1.0
*/
WILC_Sint32 host_int_wait_msg_queue_idle(void);

/**
*  @brief 		gets the site survey results
*  @details 	  	
*  @param[in,out] handle to the wifi driver, 
				  Message containing  site survey results in the 
				  following formate 
|---------------------------------------------------|
| MsgLength | fragNo.	| MsgBodyLength	| MsgBody	|					
|-----------|-----------|---------------|-----------|
|	 1		|	  1		|		1		|	 1		|					
-----------------------------------------	 |  ----------------
										     |   						
						|---------------------------------------|
						| Network1 | Netweork2 | ... | Network5 |
						|---------------------------------------|
						|	44	   |	44	   | ... |	 44		|
-------------------------- | ---------------------------------------
							 |
|---------------------------------------------------------------------|
| SSID | BSS Type | Channel | Security Status| BSSID | RSSI |Reserved |
|------|----------|---------|----------------|-------|------|---------|
|  33  |	 1	  |	  1		|		1		 |	  6	 |	 1	|	 1	  |
|---------------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
#ifndef CONNECT_DIRECT
WILC_Sint32 host_int_get_site_survey_results(WILC_WFIDrvHandle hWFIDrv, 
											WILC_Uint8 ppu8RcvdSiteSurveyResults[][MAX_SURVEY_RESULT_FRAG_SIZE], 
											WILC_Uint32 u32MaxSiteSrvyFragLen);
#endif

/**
*  @brief 		sets a start scan request
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]	Scan Source one of the following values
				DEFAULT_SCAN        0									
				USER_SCAN           BIT0								
				OBSS_PERIODIC_SCAN  BIT1								
				OBSS_ONETIME_SCAN   BIT2	
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

WILC_Sint32 host_int_set_start_scan_req(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8 scanSource);
/**
*  @brief 		gets scan source of the last scan
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
				Scan Source one of the following values
				DEFAULT_SCAN        0									
				USER_SCAN           BIT0								
				OBSS_PERIODIC_SCAN  BIT1								
				OBSS_ONETIME_SCAN   BIT2	
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
 WILC_Sint32 host_int_get_start_scan_req(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8* pu8ScanSource);

/**
*  @brief 		sets a join request
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]	Index of the bss descriptor 	
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

WILC_Sint32 host_int_set_join_req(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8bssid,
							     WILC_Uint8* pu8ssid, size_t ssidLen,
							     const WILC_Uint8* pu8IEs, size_t IEsLen,
							     tWILCpfConnectResult pfConnectResult, void* pvUserArg, 
							     WILC_Uint8 u8security, AUTHTYPE_T tenuAuth_type, 
							     WILC_Uint8 u8channel,
							     void* pJoinParams);

/**
*  @brief 		Flush a join request parameters to FW, but actual connection
*  @details 	The function is called in situation where WILC is connected to AP and 
			required to switch to hybrid FW for P2P connection 	
*  @param[in] handle to the wifi driver,
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		Amr Abdel-Moghny
*  @date		19 DEC 2013
*  @version		8.0
*/

WILC_Sint32 host_int_flush_join_req(WILC_WFIDrvHandle hWFIDrv);


/**
*  @brief 		disconnects from the currently associated network
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]	Reason Code of the Disconnection
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_disconnect(WILC_WFIDrvHandle hWFIDrv, WILC_Uint16 u16ReasonCode);

/**
*  @brief 		disconnects a sta
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]	Association Id of the station to be disconnected	
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_disconnect_station(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8 assoc_id);
/**
*  @brief 		gets a Association request info
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
				Message containg assoc. req info in the following format
------------------------------------------------------------------------
|                        Management Frame Format                    |
|-------------------------------------------------------------------| 
|Frame Control|Duration|DA|SA|BSSID|Sequence Control|Frame Body|FCS |
|-------------|--------|--|--|-----|----------------|----------|----|
| 2           |2       |6 |6 |6    |		2       |0 - 2312  | 4  |
|-------------------------------------------------------------------|
|                                                                   |
|             Association Request Frame - Frame Body                |
|-------------------------------------------------------------------|
| Capability Information | Listen Interval | SSID | Supported Rates |
|------------------------|-----------------|------|-----------------|
|			2            |		 2         | 2-34 |		3-10        |
| ---------------------------------------------------------------------
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

WILC_Sint32 host_int_get_assoc_req_info(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8AssocReqInfo, 
										    WILC_Uint32 u32AssocReqInfoLen);
/**
*  @brief 		gets a Association Response info
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
				Message containg assoc. resp info 
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

WILC_Sint32 host_int_get_assoc_res_info(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8AssocRespInfo, 
										    WILC_Uint32 u32MaxAssocRespInfoLen, WILC_Uint32* pu32RcvdAssocRespInfoLen);
/**
*  @brief 		gets a Association Response info
*  @details 	Valid only in STA mode. This function gives the RSSI	
				values observed in all the channels at the time of scanning.
				The length of the field is 1 greater that the total number of 
				channels supported. Byte 0 contains the number of channels while
				each of Byte N contains	the observed RSSI value for the channel index N.							
*  @param[in,out] handle to the wifi driver,
				array of scanned channels' RSSI 
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_get_rx_power_level(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8RxPowerLevel, 
										   WILC_Uint32 u32RxPowerLevelLen);

/**
*  @brief 		sets a channel
*  @details 	 	
*  @param[in,out] handle to the wifi driver, 
*  @param[in]	Index of the channel to be set		
|-------------------------------------------------------------------| 
|          CHANNEL1      CHANNEL2 ....		             CHANNEL14	|
|  Input:         1             2					            14	|
|-------------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_set_mac_chnl_num(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8 u8ChNum);

/**
*  @brief 		gets the current channel index
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
				current channel index
|-----------------------------------------------------------------------| 
|          CHANNEL1      CHANNEL2 ....                     CHANNEL14	|
|  Input:         1             2                                 14	|
|-----------------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_get_host_chnl_num(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8ChNo);
/**
*  @brief 		gets the sta rssi
*  @details 	gets the currently maintained RSSI value for the station. 
				The received signal strength value in dB. 
				The range of valid values is -128 to 0.
*  @param[in,out] handle to the wifi driver,
				rssi value in dB
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_get_rssi(WILC_WFIDrvHandle hWFIDrv, WILC_Sint8* ps8Rssi);
WILC_Sint32 host_int_get_link_speed(WILC_WFIDrvHandle hWFIDrv, WILC_Sint8* ps8lnkspd);
/**
*  @brief 		scans a set of channels
*  @details 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]		Scan source
				Scan Type	PASSIVE_SCAN = 0,							
							ACTIVE_SCAN  = 1
				Channels Array
				Channels Array length
				Scan Callback function
				User Argument to be delivered back through the Scan Cllback function
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_scan(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8 u8ScanSource,
					     WILC_Uint8 u8ScanType, WILC_Uint8* pu8ChnlFreqList,
					     WILC_Uint8 u8ChnlListLen, const WILC_Uint8* pu8IEs,
					     size_t IEsLen, tWILCpfScanResult ScanResult,
					     void* pvUserArg,tstrHiddenNetwork  *pstrHiddenNetwork);
/**
*  @brief 		sets configuration wids values
*  @details 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]	WID, WID value				
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 hif_set_cfg(WILC_WFIDrvHandle hWFIDrv, tstrCfgParamVal * pstrCfgParamVal);

/**
*  @brief 		gets configuration wids values
*  @details 	
*  @param[in,out] handle to the wifi driver, 
				WID value
*  @param[in]	WID, 				
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 hif_get_cfg(WILC_WFIDrvHandle hWFIDrv,WILC_Uint16 u16WID,WILC_Uint16* pu16WID_Value);
/*****************************************************************************/
/*							Notification Functions							 */
/*****************************************************************************/
/**
*  @brief 		notifies host with join and leave requests
*  @details 	This function prepares an Information frame having the
				information about a joining/leaving station.
*  @param[in,out] handle to the wifi driver,
*  @param[in]	6 byte Sta Adress
				Join or leave flag:
				Join = 1,
				Leave =0
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
void host_int_send_join_leave_info_to_host
						(WILC_Uint16 assocId, WILC_Uint8* stationAddr, WILC_Bool joining);

/**
*  @brief 		notifies host with stations found in scan
*  @details 	sends the beacon/probe response from scan
*  @param[in,out] handle to the wifi driver,
*  @param[in]	Sta Address,
				Frame length,
				Rssi of the Station found
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
void host_int_send_network_info_to_host
			(WILC_Uint8 *macStartAddress,WILC_Uint16 u16RxFrameLen, WILC_Sint8 s8Rssi);

/**
*  @brief 		host interface initialization function
*  @details 	
*  @param[in,out] handle to the wifi driver,
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_init(WILC_WFIDrvHandle* phWFIDrv);

/**
*  @brief 		host interface initialization function
*  @details 	
*  @param[in,out] handle to the wifi driver,
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
WILC_Sint32 host_int_deinit(WILC_WFIDrvHandle hWFIDrv);


/*!
 *  @fn		WILC_Sint32 host_int_add_beacon(WILC_WFIDrvHandle hWFIDrv,WILC_Uint8 u8Index)
 *  @brief		Sends a beacon to the firmware to be transmitted over the air
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	u32Interval	Beacon Interval. Period between two successive beacons on air
 *  @param[in]	u32DTIMPeriod DTIM Period. Indicates how many Beacon frames
 * 		(including the current frame) appear before the next DTIM	 
 *  @param[in]	u32Headlen	Length of the head buffer in bytes
 *  @param[in]	pu8Head		Pointer to the beacon's head buffer. Beacon's head
 *		is the part from the beacon's start till the TIM element, NOT including the TIM
 *  @param[in]	u32Taillen	Length of the tail buffer in bytes
 *  @param[in]	pu8Tail		Pointer to the beacon's tail buffer. Beacon's tail
 *		starts just after the TIM inormation element
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		10 Julys 2012
 *  @version		1.0 Description

 */
WILC_Sint32 host_int_add_beacon(WILC_WFIDrvHandle hWFIDrv, WILC_Uint32 u32Interval,
									 WILC_Uint32 u32DTIMPeriod,
									 WILC_Uint32 u32HeadLen, WILC_Uint8* pu8Head,
									 WILC_Uint32 u32TailLen, WILC_Uint8* pu8tail);


/*!
 *  @fn		WILC_Sint32 host_int_del_beacon(WILC_WFIDrvHandle hWFIDrv)
 *  @brief		Removes the beacon and stops trawilctting it over the air
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		10 Julys 2012
 *  @version		1.0 Description
 */
WILC_Sint32 host_int_del_beacon(WILC_WFIDrvHandle hWFIDrv);

/*!
 *  @fn		WILC_Sint32 host_int_add_station(WILC_WFIDrvHandle hWFIDrv, tstrWILC_AddStaParam strStaParams)
 *  @brief		Notifies the firmware with a new associated stations
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	pstrStaParams	Station's parameters
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		12 July 2012
 *  @version		1.0 Description
 */
WILC_Sint32 host_int_add_station(WILC_WFIDrvHandle hWFIDrv, tstrWILC_AddStaParam* pstrStaParams);

/*!
 *  @fn		WILC_Sint32 host_int_del_allstation(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8MacAddr)
 *  @brief		Deauthenticates clients when group is terminating
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	pu8MacAddr	Station's mac address
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Mai Daftedar
 *  @date		09 April 2014
 *  @version		1.0 Description
 */
WILC_Sint32 host_int_del_allstation(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8 pu8MacAddr[][ETH_ALEN]);

/*!
 *  @fn		WILC_Sint32 host_int_del_station(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8MacAddr)
 *  @brief		Notifies the firmware with a new deleted station
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	pu8MacAddr	Station's mac address
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		15 July 2012
 *  @version		1.0 Description
 */
WILC_Sint32 host_int_del_station(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8MacAddr);

/*!
 *  @fn		WILC_Sint32 host_int_edit_station(WILC_WFIDrvHandle hWFIDrv, tstrWILC_AddStaParam strStaParams)
 *  @brief		Notifies the firmware with new parameters of an already associated station
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	pstrStaParams	Station's parameters
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		15 July 2012
 *  @version		1.0 Description
 */
WILC_Sint32 host_int_edit_station(WILC_WFIDrvHandle hWFIDrv, tstrWILC_AddStaParam* pstrStaParams);

/*!
 *  @fn		WILC_Sint32 host_int_set_power_mgmt(WILC_WFIDrvHandle hWFIDrv, WILC_Bool bIsEnabled, WILC_Uint32 u32Timeout)
 *  @brief		Set the power management mode to enabled or disabled
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	bIsEnabled	TRUE if enabled, FALSE otherwise
 *  @param[in]	u32Timeout	A timeout value of -1 allows the driver to adjust
 *							the dynamic ps timeout value
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		24 November 2012
 *  @version		1.0 Description
 */
WILC_Sint32 host_int_set_power_mgmt(WILC_WFIDrvHandle hWFIDrv, WILC_Bool bIsEnabled, WILC_Uint32 u32Timeout);
/*  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	bIsEnabled	TRUE if enabled, FALSE otherwise
 *  @param[in]	u8count		count of mac address entries in the filter table
 *
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		24 November 2012
 *  @version		1.0 Description
 */
WILC_Sint32 host_int_setup_multicast_filter(WILC_WFIDrvHandle hWFIDrv, WILC_Bool bIsEnabled, WILC_Uint32 u32count);
/**
*  @brief           host_int_setup_ipaddress
*  @details 	   set IP address on firmware
*  @param[in]    
*  @return 	    Error code.
*  @author		Abdelrahman Sobhy
*  @date	
*  @version	1.0
*/
WILC_Sint32 host_int_setup_ipaddress(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8IPAddr, WILC_Uint8 idx);


/**
*  @brief           host_int_delBASession
*  @details 	   Delete single Rx BA session
*  @param[in]    
*  @return 	    Error code.
*  @author		Abdelrahman Sobhy
*  @date	
*  @version	1.0
*/
WILC_Sint32 host_int_delBASession(WILC_WFIDrvHandle hWFIDrv, char* pBSSID,char TID);

/**
*  @brief           host_int_delBASession
*  @details 	   Delete all Rx BA session
*  @param[in]    
*  @return 	    Error code.
*  @author		Abdelrahman Sobhy
*  @date	
*  @version	1.0
*/
WILC_Sint32 host_int_del_All_Rx_BASession(WILC_WFIDrvHandle hWFIDrv, char* pBSSID,char TID);


/**
*  @brief           host_int_get_ipaddress
*  @details 	   get IP address on firmware
*  @param[in]    
*  @return 	    Error code.
*  @author		Abdelrahman Sobhy
*  @date	
*  @version	1.0
*/
WILC_Sint32 host_int_get_ipaddress(WILC_WFIDrvHandle hWFIDrv, WILC_Uint8* pu8IPAddr, WILC_Uint8 idx);

#ifdef WILC_P2P
/**
*  @brief           host_int_remain_on_channel
*  @details 	   
*  @param[in]    
*  @return 	    Error code.
*  @author	
*  @date	
*  @version	1.0
*/
WILC_Sint32 host_int_remain_on_channel(WILC_WFIDrvHandle hWFIDrv, WILC_Uint32 u32SessionID, WILC_Uint32 u32duration,WILC_Uint16 chan,tWILCpfRemainOnChanExpired RemainOnChanExpired, tWILCpfRemainOnChanReady RemainOnChanReady,void* pvUserArg);

/**
*  @brief           	host_int_ListenStateExpired
*  @details 	   
*  @param[in]    	Handle to wifi driver
				Duration to remain on channel
				Channel to remain on
				Pointer to fn to be called on receive frames in listen state
				Pointer to remain-on-channel expired fn
				Priv
*  @return 	    	Error code.
*  @author	
*  @date	
*  @version		1.0
*/
WILC_Sint32 host_int_ListenStateExpired(WILC_WFIDrvHandle hWFIDrv, WILC_Uint32 u32SessionID);

/**
*  @brief           host_int_frame_register
*  @details 	   
*  @param[in]    
*  @return 	    Error code.
*  @author	
*  @date	
*  @version	1.0
*/
WILC_Sint32 host_int_frame_register(WILC_WFIDrvHandle hWFIDrv, WILC_Uint16 u16FrameType,WILC_Bool bReg);
#endif
/**
*  @brief           host_int_set_wfi_drv_handler
*  @details 	   
*  @param[in]    
*  @return 	    Error code.
*  @author	
*  @date	
*  @version	1.0
*/
WILC_Sint32 host_int_set_wfi_drv_handler(WILC_Uint32 u32address);
WILC_Sint32 host_int_set_operation_mode(WILC_WFIDrvHandle hWFIDrv, WILC_Uint32 u32mode);

static WILC_Sint32 Handle_ScanDone(void* drvHandler,tenuScanEvent enuEvent);

static int host_int_addBASession(WILC_WFIDrvHandle hWFIDrv, char* pBSSID,char TID,short int BufferSize,
	short int SessionTimeout,void * drvHandler);


void host_int_freeJoinParams(void* pJoinParams);

WILC_Sint32 host_int_get_statistics(WILC_WFIDrvHandle hWFIDrv, tstrStatistics* pstrStatistics);

/*****************************************************************************/
/*																			 */
/*									EOF										 */
/*																			 */
/*****************************************************************************/
#endif 
