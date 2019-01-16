#ifndef __LLCLIENTTYPES_H__
#define __LLCLIENTTYPES_H__

#define TOKEN_ID_MAX_LEN				50
#define MAX_APPLIANCES					128

typedef struct
{
	unsigned long  	major;
	unsigned long  	minor;
} LLCLIENT_SERVER_VERSION;

typedef struct
{
	char			TokenIDsArr[MAX_APPLIANCES][TOKEN_ID_MAX_LEN];
	long			TokenIDsArrLen;
	long			TokenIDCurrent;
} TOKEN_IDS_CONTEXT;


typedef enum
{
    LLCLIENT_SERVER_KIND_NONE            = 0,
	LLCLIENT_SERVER_KIND_STANDALONE		= 1,
	LLCLIENT_SERVER_KIND_MASTER			= 2,
	LLCLIENT_SERVER_KIND_SLAVE			= 3
}LLCLIENT_ENUM_SERVER_KIND;

typedef enum {
		LLCLIENT_NONE_DIRECTORY_KIND	        = 0,	
		LLCLIENT_ACTIVE_DIRECTORY_KIND		= 1,	
		LLCLIENT_NDS_DIRECTORY_KIND		    = 2,
        LLCLIENT_PUSH_DIRECTORY_KIND         = 3,  //when insert a new dir kind update the LAST_DIRECTORY_KIND
        LLCLIENT_LDAP_DIRECTORY_KIND         = 4
}LLCLIENT_ENUM_DIRECTORY_KIND;

typedef enum LLCLIENT_ENUM_AUTH_MODE
{
    LLCLIENT_AUTH_MODE_NONE                      = 0,
	LLCLIENT_AUTH_MODE_SSPI                      = 1,    // SSPI SSO
    LLCLIENT_AUTH_MODE_VERIFY_USER_SRV_SIDE      = 2,    // user/pwd verified by server
    LLCLIENT_AUTH_MODE_SSPI_USRPWD               = 3,    // SSPI with user/pwd params
    LLCLIENT_AUTH_MODE_VERIFY_DB_USER_SRV_SIDE   = 4,     // The user and his credential declared in the
                                                // CoSign DB
    LLCLIENT_AUTH_MODE_SAML_SRV_SIDE				= 5     // The user and his credential declared in the
}LLCLIENT_ENUM_AUTH_MODE;

typedef enum LLCLIENT_ENUM_TOKEN_KIND
{
    LLCLIENT_TOKEN_KIND_NONE = 0,
	LLCLIENT_TOKEN_KIND_TOTP = 1,
} LLCLIENT_ENUM_TOKEN_KIND;

typedef enum LLCLIENT_ENUM_TOKEN_PURPOSES
{
    LLCLIENT_TOKEN_PURPOSES_NONE = 0,
	LLCLIENT_TOKEN_PURPOSES_LOGIN = 1,
	LLCLIENT_TOKEN_PURPOSES_SIGN = 2
} LLCLIENT_ENUM_TOKEN_PURPOSES;

// The following flags are duplicate in MOB
//MASK
typedef enum LLCLIENT_ENUM_AUTHENTICATION_TYPE_FLAGS
{
	LLCLIENT_AUTHENTICATION_TYPE_FLAGS_SAML_CREDS				= 0x00000001,
	LLCLIENT_AUTHENTICATION_TYPE_FLAGS_IGNORE_PWD_EXPIRED		= 0x00000002,		// use this flag to ignore pwd expired for user, we used it for user activation in Common criteria.
	LLCLIENT_AUTHENTICATION_TYPE_FLAGS_IGNORE_PWD_ERROR_COUNTER	= 0x00000004,		// use this flag to ignore pwd counter error , used in CC mode when OTP calculation involved
	LLCLIENT_AUTHENTICATION_TYPE_FLAGS_INTERNAL_OTP				= 0x04000000
	
}LLCLIENT_ENUM_AUTHENTICATION_TYPE_FLAGS;



typedef enum LLCLIENT_ENUM_GRAPHICAL_OBJECT_TYPE
{

	LLCLIENT_GRAPHICAL_OBJECT_TYPE_GRAPHICAL_IMAGE				= 0x00000001,
	LLCLIENT_GRAPHICAL_OBJECT_TYPE_INITIAL_IMAGE				= 0x00000002,
	LLCLIENT_GRAPHICAL_OBJECT_TYPE_LOGO_IMAGE					= 0x00000004,

}LLCLIENT_ENUM_GRAPHICAL_OBJECT_TYPE;




#endif