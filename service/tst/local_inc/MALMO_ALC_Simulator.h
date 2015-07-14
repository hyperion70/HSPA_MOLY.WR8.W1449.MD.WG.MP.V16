#if defined(__TST_MALMO_SUPPORT__) && defined(__TST_ON_AOS_PC__)

#ifndef __MALMO_ALC_SIMULATOR_DEF__
#define __MALMO_ALC_SIMULATOR_DEF__

#include <string>

struct AlcRequestStr
{
	unsigned int packetType;
	unsigned int packetLength;
	unsigned int packetGroup;
};

class ALC_Module
{
#define MAX_LIT_TABLE_NUM (8)
#define MAX_ALC_TYPE_NUM (2)
#define MAX_ALC_GBL_NUM (4)
#define ALC_TYPE_L1 (0)
#define ALC_TYPE_PS (1)
#define LIT_PTR_NULL (-1)
#define ALC_PDI_PACKET_SIZE (4) //4-words PDI


private:	
	struct AlcLitStr
	{
		bool valid;
		unsigned int type;
		unsigned int csm;
		unsigned int writeStartPtr;
		unsigned int writePtr;
		unsigned int leftLength;
		unsigned int checksum;
	};

	AlcLitStr m_LitTable[MAX_LIT_TABLE_NUM];
	int m_currentLitPtr;

	unsigned int m_alcCurrentCsm;
	AlcRequestStr m_alcCurrentRequest;
	unsigned int m_alcCurrentData; 	

	unsigned int m_alcCurrentWritePtr[MAX_ALC_TYPE_NUM];	

	unsigned int m_alcRstartPtr[MAX_ALC_TYPE_NUM];	
	unsigned int m_alcRendPtr[MAX_ALC_TYPE_NUM];		

	unsigned int m_currentLitOccupiedNumber;
	unsigned int m_alcErrorCount;

	//For file output
	unsigned int *m_alc_write_buffer[MAX_LIT_TABLE_NUM];
	unsigned int m_alc_write_buffer_current_ptr[MAX_LIT_TABLE_NUM];
	unsigned int m_alc_write_buffer_start_ptr[MAX_LIT_TABLE_NUM];
	unsigned int m_alc_write_buffer_max_size[MAX_LIT_TABLE_NUM];
	FILE* m_alcWriteFile[MAX_ALC_TYPE_NUM];

	void Reset();


public:
	bool InitWriteFile( std::string alc_l1_filename, std::string alc_ps_filename );
	void WriteRequest(unsigned int type, unsigned int group, unsigned int length);
	void WriteCsm(unsigned int csm);
	void WriteData(unsigned int data);

	ALC_Module(){ Reset(); };
	~ALC_Module();
};

#endif

#endif  //#if defined(__TST_MALMO_SUPPORT__) && defined(__TST_ON_AOS_PC__)