#!/usr/bin/perl
#

my %BBtbl_EMI_NEW_INIT_FLOW = 
    (       
        'MT6253'  => 1,
        'MT6236'  => 1,
        'MT6236B' => 1,
        'MT6921'  => 1,
        'MT6252H' => 1,
        'MT6252'  => 1,
    );
    
my $DebugPrint    = 1;

require "tools/emigenMD.pl";

#****************************************************************************
# subroutine:  custom_EMI_c_file_body
# return:      
#****************************************************************************
sub custom_EMI_c_file_body
{
	  my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $BBtbl_LPSDRAM_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL) = @_;
    my $cs1_base_address = sprintf("0x%08X", &config_query_cs1_addr($MAKEFILE_OPTIONS_LOCAL->{'platform'}));
   
    ###
    my $custom_setEMI;

    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) == 1)
    {
        $custom_setEMI = &FuncBody_custom_setEMI_empty();
    }
    elsif ( (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2')) && ($LPSDRAM_CHIP_SELECT_LOCAL !~ /0xFF/i)
        && $BBtbl_LPSDRAM_LOCAL->{$MAKEFILE_OPTIONS_LOCAL->{'platform'}} )
    {
        $custom_setEMI = &FuncBody_custom_setEMI_for_lpsdram();
    }
    else
    {
        $custom_setEMI = &FuncBody_custom_setEMI_for_nor_ram_mcp();
    }

    ###
    my $custom_setAdvEMI;

    if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6251')
    {
    }
    elsif ( ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH') )
    {
        $custom_setAdvEMI = &FuncBody_custom_setAdvEMI_for_nor_ram_mcp($MAKEFILE_OPTIONS_LOCAL, $emi_clk_config_LOCAL);
    } # if ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP') )

    ###
    my $custom_initDRAM;

    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235B') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6238') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6239'))
    {
        if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
        {
            $custom_initDRAM .= "   return 0;\n";
        }
        elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM')
        {
            $custom_initDRAM .= "   return -1;\n";
        }
    }
    else
    {
        $custom_initDRAM .= "   return -1;\n";
    }

    ###
    my $custom_DynamicClockSwitch = &FuncBody_custom_dynamicclockswitch($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $BBtbl_LPSDRAM_LOCAL);

    ###
    my $EMI_Info;
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
    {
        ### aggregate MEM_Info EMI settings by MCP
        my $combo_mem_emi_info_struct;
        my $combo_emi_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT};
        for (1..$combo_emi_count)
        {
            my $combo_idx = $_ - 1;
            my ($emi_nor_op_str, $emi_nor_address_str, $emi_nor_data_str, $emi_psram_op_str, $emi_psram_address_str, $emi_psram_data_str);

            for (0..($emi_nor_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                $emi_nor_op_str .= "   EMI_NOR_BURST_OP_$idx\_MCP$combo_idx,\n";
                $emi_nor_address_str .= "   EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx,\n";
                $emi_nor_data_str .= "   EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx,\n";
            }
            for (0..($emi_psram_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                $emi_psram_op_str .= "   EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx,\n";
                $emi_psram_address_str .= "   EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx,\n";
                $emi_psram_data_str .= "   EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx,\n";
            }

            $combo_mem_emi_info_struct .= <<"__TEMPLATE";
   /**
      * EMI/MEM configuration information of MCP$combo_idx
      */

#if defined(MT6235) || defined(MT6235B)

   "EMI_INF",

   EMI_GENERAL_A_VAL_MCP$combo_idx,
   EMI_GENERAL_B_VAL_MCP$combo_idx,
   EMI_GENERAL_C_VAL_MCP$combo_idx,
   EMI_GENERAL_D_VAL_MCP$combo_idx,
   EMI_CONTROL_I_VAL_MCP$combo_idx,
   EMI_CONTROL_J_VAL_MCP$combo_idx,
   EMI_CONTROL_K_VAL_MCP$combo_idx,
   EMI_CONTROL_L_VAL_MCP$combo_idx,
   EMI_CONTROL_M_VAL_MCP$combo_idx,
   EMI_CONTROL_N_VAL_MCP$combo_idx,
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) /* MT6235 || MT6235B */

   "EMI_INF",

   EMI_GENERAL_A_VAL_MCP$combo_idx,
   EMI_GENERAL_B_VAL_MCP$combo_idx,
   EMI_GENERAL_C_VAL_MCP$combo_idx,
   EMI_GENERAL_D_VAL_MCP$combo_idx,
   EMI_CONTROL_I_VAL_MCP$combo_idx,
   EMI_CONTROL_J_VAL_MCP$combo_idx,
   EMI_CONTROL_K_VAL_MCP$combo_idx,
   EMI_CONTROL_L_VAL_MCP$combo_idx,
   EMI_CONTROL_M_VAL_MCP$combo_idx,
   EMI_CONTROL_N_VAL_MCP$combo_idx,

   EMI_DELAY_A_VAL_MCP$combo_idx,
   EMI_DELAY_B_VAL_MCP$combo_idx,
   EMI_DELAY_C_VAL_MCP$combo_idx,
   EMI_DELAY_D_VAL_MCP$combo_idx,
   EMI_DELAY_E_VAL_MCP$combo_idx,
   EMI_DELAY_F_VAL_MCP$combo_idx,
   EMI_DELAY_G_VAL_MCP$combo_idx,
   EMI_DELAY_H_VAL_MCP$combo_idx,
   EMI_DELAY_I_VAL_MCP$combo_idx,
   EMI_DELAY_J_VAL_MCP$combo_idx,   

#if defined(MT6268)
   EMI_ARB_A_VAL_MCP$combo_idx,
   EMI_ARB_B_VAL_MCP$combo_idx,
   EMI_ARB_C_VAL_MCP$combo_idx,
   EMI_ARB_D_VAL_MCP$combo_idx,
   EMI_ARB_E_VAL_MCP$combo_idx,
   EMI_ARB_F_VAL_MCP$combo_idx,
   EMI_ARB_G_VAL_MCP$combo_idx,
   EMI_ARB_H_VAL_MCP$combo_idx,
   EMI_ARB_I_VAL_MCP$combo_idx,
#elif defined(MT6236) || defined(MT6236B) /* MT6268 */
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
#endif /* MT6268 */

#elif defined(MT6276) /* MT6235 || MT6235B */
  
   "EMI_INF",
   
   EMI_DRV_A_VAL_MCP$combo_idx,
   EMI_DRV_B_VAL_MCP$combo_idx,

   EMI_ODL_A_VAL_MCP$combo_idx,
   EMI_ODL_B_VAL_MCP$combo_idx,
   EMI_ODL_C_VAL_MCP$combo_idx,
   EMI_ODL_D_VAL_MCP$combo_idx,
   EMI_ODL_E_VAL_MCP$combo_idx,
   EMI_ODL_F_VAL_MCP$combo_idx,
   EMI_ODL_G_VAL_MCP$combo_idx,

   EMI_CONTROL_I_VAL_MCP$combo_idx,
   EMI_CONTROL_J_VAL_MCP$combo_idx,
   EMI_CONTROL_K_VAL_MCP$combo_idx,
   EMI_CONTROL_L_VAL_MCP$combo_idx,
   EMI_CONTROL_N_VAL_MCP$combo_idx,

   EMI_IODUTY_A_VAL_MCP$combo_idx,
   EMI_IODUTY_B_VAL_MCP$combo_idx,  
   EMI_IODUTY_C_VAL_MCP$combo_idx,
   
   EMI_RXDUTY_A_VAL_MCP$combo_idx,
   EMI_RXDUTY_B_VAL_MCP$combo_idx,  
   EMI_RXDUTY_E_VAL_MCP$combo_idx,
   
   EMI_IOMISC_L_VAL_MCP$combo_idx,
   
#endif /* MT6235 || MT6235B */

   /**
      * End of EMI/MEM configuration information of MCP$combo_idx
      */
__TEMPLATE
        }
        
        $EMI_Info .= <<"__TEMPLATE__";
#ifdef __SV5_ENABLED__ // SV5 will always with __UBL__
#pragma arm section rodata = "BOOTLOADER_GFH_EXT"
#else
#pragma arm section rodata = "SECOND_PART"
#endif // __SV5_ENABLED__

#ifdef __SV5_ENABLED__ 
  #if defined(MT6276)
    const GFH_EMI_LIST_v5 EMI_INFO_2 =
  #else
    #error "BB chip is NOT supported by SV5"
  #endif
#else /* __SV5_ENABLED__ */
  const MTK_EMI_List EMI_INFO_2 =
#endif /* __SV5_ENABLED__ */
{
#ifdef __SV5_ENABLED__

  //GFH_HEADER(GFH_EPP_PARAM, 1),
  #if defined(MT6276)
    GFH_HEADER(GFH_EMI_LIST, 5),
  #endif
  
#else
   "MTK_CMB_EMI_LST",
#endif

   // chip_ver
#if defined(MT6235) || defined(MT6235B) /* MT6235 || MT6235B */
   3,
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) /* MT6235 || MT6235B */
   4,
#elif defined(MT6276) /* MT6235 || MT6235B */
   5,
#else /* MT6235 || MT6235B */
   0,
#endif /* MT6235 || MT6235B */

   // op_ver
#if defined(MT6276) 
   #if defined(__EMI_DEVICE_LPDDR1__) && defined(__EMI_CLK_166MHZ__)
   0x01,
   #elif defined(__EMI_DEVICE_LPDDR1__) && defined(__EMI_CLK_200MHZ__)
   0x02,
   #elif defined(__EMI_DEVICE_LPDDR2__) && defined(__EMI_CLK_166MHZ__) 
   0x11,
   #elif defined(__EMI_DEVICE_LPDDR2__) && defined(__EMI_CLK_200MHZ__) 
   0x12,
   #else
   0,
   #endif
#else
   0,
#endif
   
   0, // reserved_1
   0, // reserved_2

   $combo_emi_count, // mcp_num

$combo_mem_emi_info_struct
}; /* End of EMI_INFO_2 */

#pragma arm section rodata
__TEMPLATE__
        chomp $EMI_Info;
    }

    ###
    my $MEM_Info;
    if ((($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')) and (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'})!=1))
    {
        ### aggregate MEM_Info EMI settings by MCP
        my $combo_mem_emi_info_struct;
        my $combo_emi_count;
        if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
        {
            $combo_emi_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT};
        }
        else
        {
            $combo_emi_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT};
        }
        for (1..$combo_emi_count)
        {
            my $combo_idx = $_ - 1;
            my ($emi_nor_op_str, $emi_nor_address_str, $emi_nor_data_str, $emi_psram_op_str, $emi_psram_address_str, $emi_psram_data_str);

            for (0..($emi_nor_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                $emi_nor_op_str .= "   EMI_NOR_BURST_OP_$idx\_MCP$combo_idx,\n";
                $emi_nor_address_str .= "   EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx,\n";
                $emi_nor_data_str .= "   EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx,\n";
            }
            for (0..($emi_psram_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                $emi_psram_op_str .= "   EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx,\n";
                $emi_psram_address_str .= "   EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx,\n";
                $emi_psram_data_str .= "   EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx,\n";
            }

            $combo_mem_emi_info_struct .= <<"__TEMPLATE";
   /**
      * EMI/MEM configuration information of MCP$combo_idx
      */

   "MEM_INF",
   
   EMI_RAM_DIDR_MCP$combo_idx, //DIDR

#if defined(MT6236) || defined(MT6236B)

   /**
      * EMI control register value.
      */

   EMI_GENERAL_A_VAL_MCP$combo_idx,
   EMI_GENERAL_B_VAL_MCP$combo_idx,
   EMI_GENERAL_C_VAL_MCP$combo_idx,
   EMI_GENERAL_D_VAL_MCP$combo_idx,
   EMI_DELAY_J_VAL_MCP$combo_idx,

   EMI_CONA_ASYNC_MCP$combo_idx,
   EMI_CONB_ASYNC_MCP$combo_idx,

   EMI_CONA_BURST_MCP$combo_idx,
   EMI_CONE_BURST_MCP$combo_idx,

   EMI_CONB_BURST_MCP$combo_idx,
   EMI_CONF_BURST_MCP$combo_idx,

   EMI_RDCT_VAL_MCP$combo_idx,

   /**
      * NOR switch command sets.
      */
   $emi_nor_cmd_num_max_LOCAL,

$emi_nor_op_str
$emi_nor_address_str
$emi_nor_data_str

   /**
      * PSRAM switch command sets.
      */
   $emi_psram_cmd_num_max_LOCAL,

$emi_psram_op_str
$emi_psram_address_str
$emi_psram_data_str

#elif defined(MT6253)

   /**
      * EMI control register value.
      */
   EMI_CONA_ASYNC_MCP$combo_idx,
   EMI_CONB_ASYNC_MCP$combo_idx,
   0,
   0,
   EMI_GENERAL_CONTROL_MCP$combo_idx,
   
   EMI_CONA_BURST_MCP$combo_idx,
   EMI_CONB_BURST_MCP$combo_idx,
   0,
   0,
   EMI_GENERAL_CONTROL_BURST_MCP$combo_idx,
   
   EMI_CACHE_PREFETCH,

   /**
      * NOR switch command sets.
      */
   $emi_nor_cmd_num_max_LOCAL,

$emi_nor_op_str
$emi_nor_address_str
$emi_nor_data_str

   /**
      * PSRAM switch command sets.
      */
   $emi_psram_cmd_num_max_LOCAL,

$emi_psram_op_str
$emi_psram_address_str
$emi_psram_data_str

#elif defined(MT6252) || defined(MT6252H)

   EMI_CONA_ASYNC_MCP$combo_idx,
   EMI_CONB_ASYNC_MCP$combo_idx,
   0, // EMI_CONC_ASYNC_MCP$combo_idx
   
   EMI_GENERAL_CONTROL_ASYNC_MCP$combo_idx,
   EMI_EXTCON_ASYNC_MCP$combo_idx,

   EMI_DRIVING_CONTROL_A_MCP$combo_idx,
   EMI_DRIVING_CONTROL_B_MCP$combo_idx,
   EMI_DRIVING_CONTROL_C_MCP$combo_idx,

#if defined(__EMI_DEVICE_MODE_BURST__) 

   EMI_CONA_BURST_MCP$combo_idx,
   EMI_CONB_BURST_MCP$combo_idx,
   0, // EMI_CONC_BURST_MCP$combo_idx,

   EMI_GENERAL_CONTROL_BURST_MCP$combo_idx,
   
   EMI_EXTCON_BURST_MCP$combo_idx,
   EMI_EXTCON2_BURST_MCP$combo_idx,
   
   EMI_DRIVING_CONTROL_A_BURST_MCP$combo_idx,
   EMI_DRIVING_CONTROL_B_BURST_MCP$combo_idx,
   
#endif   

#if defined(__EMI_DEVICE_MODE_PAGE__)  
   0, // EMI_CONA_PAGE_MCP$combo_idx,
   0, // EMI_CONB_PAGE_MCP$combo_idx,
   0, // EMI_CONC_PAGE_MCP$combo_idx,

#endif   

/* for Page Mode, if there is no command for NOR, let the num = 0 */
#if defined(__EMI_DEVICE_MODE_BURST__) && !defined(MT6252)

   /**
      * NOR switch command sets.
      */
   $emi_nor_cmd_num_max_LOCAL,

$emi_nor_op_str
$emi_nor_address_str
$emi_nor_data_str

#endif /* __EMI_DEVICE_MODE_BURST__ && ! MT6252 */


#if defined(__EMI_DEVICE_MODE_BURST__) || defined(__EMI_DEVICE_MODE_PAGE__)

   /**
      * PSRAM switch command sets.
      */
   $emi_psram_cmd_num_max_LOCAL,

$emi_psram_op_str
$emi_psram_address_str
$emi_psram_data_str
   
#endif /* __EMI_DEVICE_MODE_BURST__ || __EMI_DEVICE_MODE_PAGE__ */

#endif  /* MT6236 || MT6236B */

   /**
      * End of EMI/MEM configuration information of MCP$combo_idx
      */
__TEMPLATE
        }
    
        ### overall MEM_Info structure
        $MEM_Info .= <<"__TEMPLATE__";
/**
   * This info is used to pass memory switching command to Flash Tool so that Flash Tool can switch the memory to target mode as well.
   * This is mainly for work-around Numonyx's unable to support mixed mode issue.
   * Currently we will only generate memory info under MT6253 & MT6253DV\@104MHz because Numonyx has already fixed this issue when other chips have gone into mass production.
   * If we do not generate the memory info, Flash Tool will bypass switching mode and use ASYNC mode to proceed the downloading, which is our expected behavior on MT6253DV\@52MHz case.
   * Care must be taken that on MT6253 chip, the __EMI_CLK_104MHZ__ option must be generated even it is a fixed clock rate chip.
   */

#pragma arm section rodata = "SECOND_PART"

/**
   * the structure will be put within the binary file so that Flash Tool could query it.
    1.m_identifier is changed from "MTK_MEM_INFO" to "MTK_MEM_CBL"
    2.EMI_NOR_CMD_num_max, EMI_PSRAM_CMD_num_max will be the largest one of all valid MCP 
      for all OPs which are not used by certain MCP, the OP must be MEM_CMD_OP_NOP
   */
const MTK_MEM_List CUST_MEM_INFO = 
{
   /**
      * header pattern information.
      */
   "MTK_CMB_MEM_LST",

   /**
      * version information.
      */
#if defined(MT6253) 
  #if defined(__EMI_CLK_104MHZ__)
    1,
    1,
  #elif defined(__EMI_CLK_52MHZ__)
    1,
    2,
  #else
    0xFFFFFFFF,
    0xFF,
  #endif
#else /* MT6253 */
   0xFFFFFFFF,
   0xFF,
#endif  /* MT6253 */

   __EMI_NOR_CMD_NUM, // EMI_NOR_CMD_num_max
   __EMI_PSRAM_CMD_NUM, // EMI_PSRAM_CMD_num_max

   __EMI_COMBO_ENTRY_COUNT, // Numbers of MCPs

$combo_mem_emi_info_struct
};
#pragma arm section rodata

__TEMPLATE__
        chomp $MEM_Info;
    }
    
    ###
    my $emi_reg_param_decl;
    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
    {
        $emi_reg_param_decl .= <<"__TEMPLATE";
#if defined(__EMI_COMBO_EN)

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */

/* Non-zero default value for EMI variable, avoid to use ZI for EMIINIT region.
   Note: since not all regions are initialized before EMI init flow,
         the using of EMIINITZI might corrupt data of other region which is still kept at load view
 */
  
#define __EMI_VAL_DEFUALT   0xFFFFFFFF

kal_int32 CMCP_Index = __EMI_VAL_DEFUALT; // Index of the MCP in list
kal_uint32 Sel_NOR_CMD_num = __EMI_VAL_DEFUALT;
kal_uint32 Sel_PSRAM_CMD_num = __EMI_VAL_DEFUALT;

#if ( defined(MT6236) || defined(MT6236B) )

   kal_uint32 EMI_GENERAL_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_GENERAL_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_GENERAL_C_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_GENERAL_D_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_DELAY_J_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_CONA_ASYNC = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONB_ASYNC = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_CONA_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONE_BURST;
   
   kal_uint32 EMI_CONB_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONF_BURST = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_RDCT_VAL = __EMI_VAL_DEFUALT;

   // Always BURST
   kal_uint32 EMI_NOR_BURST_OP[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_NOR_BURST_ADDRESS[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_NOR_BURST_DATA[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_OP[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_ADDRESS[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_DATA[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};

#elif defined(MT6253)
   kal_uint32 EMI_CONA_ASYNC = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONB_ASYNC = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONC_ASYNC = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_COND_ASYNC = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_GENERAL_CONTROL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_CONA_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONB_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONC_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_COND_BURST = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_GENERAL_CONTROL_BURST = __EMI_VAL_DEFUALT;

   // Always BURST
   kal_uint32 EMI_NOR_BURST_OP[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_NOR_BURST_ADDRESS[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_NOR_BURST_DATA[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_OP[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_ADDRESS[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_DATA[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};

#elif ( defined(MT6252H) || defined(MT6252) )
   kal_uint32 EMI_CONA_ASYNC = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONB_ASYNC = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONC_ASYNC = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_EXTCON_ASYNC = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_GENERAL_CONTROL_ASYNC = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_DRIVING_CONTROL_A = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DRIVING_CONTROL_B = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DRIVING_CONTROL_C = __EMI_VAL_DEFUALT;

#if defined(__EMI_DEVICE_MODE_BURST__)

   kal_uint32 EMI_CONA_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONB_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONC_BURST = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_GENERAL_CONTROL_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_EXTCON_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_EXTCON2_BURST = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_DRIVING_CONTROL_A_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DRIVING_CONTROL_B_BURST = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_PSRAM_BURST_OP[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_ADDRESS[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_DATA[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   
#endif /* __EMI_DEVICE_MODE_BURST__ */

#if defined(__EMI_DEVICE_MODE_PAGE__)

   kal_uint32 EMI_CONA_PAGE = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONB_PAGE = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONC_PAGE = __EMI_VAL_DEFUALT;
   
   kal_uint32 EMI_NOR_PAGE_OP[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_NOR_PAGE_ADDRESS[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_NOR_PAGE_DATA[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_PAGE_OP[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_PAGE_ADDRESS[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_PAGE_DATA[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};

#endif  /* __EMI_DEVICE_MODE_PAGE__ */


#endif  /* MT6253 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
#endif /* __MTK_TARGET__ */

#endif /* __EMI_COMBO_EN */
__TEMPLATE
    }
    elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2')
    {
        $emi_reg_param_decl .= <<"__TEMPLATE";
#if defined(__EMI_COMBO_EN)

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */

/* Non-zero default value for EMI variable, avoid to use ZI for EMIINIT region.
   Note: since not all regions are initialized before EMI init flow,
         the using of EMIINITZI might corrupt data of other region which is still kept at load view
 */
  
#define __EMI_VAL_DEFUALT   0xFFFFFFFF

kal_int32 CMCP_Index = __EMI_DCM_COMBO_INDEX_UND; // Index of the MCP in list

#if defined(MT6235) || defined(MT6235B)

   kal_uint32 EMI_GENERAL_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_GENERAL_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_GENERAL_C_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_GENERAL_D_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_I_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_J_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_K_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_L_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_M_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_N_VAL = __EMI_VAL_DEFUALT;
   
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) /* MT6235 || MT6235B */

   kal_uint32 EMI_GENERAL_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_GENERAL_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_GENERAL_C_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_GENERAL_D_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_I_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_J_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_K_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_L_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_M_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_N_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_DELAY_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DELAY_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DELAY_C_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DELAY_D_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DELAY_E_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DELAY_F_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DELAY_G_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DELAY_H_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DELAY_I_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DELAY_J_VAL = __EMI_VAL_DEFUALT; 

   kal_uint32 EMI_ARB_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ARB_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ARB_C_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ARB_D_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ARB_E_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ARB_F_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ARB_G_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ARB_H_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ARB_I_VAL = __EMI_VAL_DEFUALT;

#elif defined(MT6276) /* MT6235 || MT6235B */

   kal_uint32 EMI_DRV_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DRV_B_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_ODL_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_C_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_D_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_E_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_F_VAL = __EMI_VAL_DEFUALT; 
   kal_uint32 EMI_ODL_G_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_CONTROL_I_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_J_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_K_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_L_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_N_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_IODUTY_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_IODUTY_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_IODUTY_C_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_RXDUTY_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_RXDUTY_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_RXDUTY_E_VAL = __EMI_VAL_DEFUALT;
   
   kal_uint32 EMI_IOMISC_L_VAL = __EMI_VAL_DEFUALT;

#endif /* MT6235 || MT6235B */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
#endif /* __MTK_TARGET__ */

#endif /* __EMI_COMBO_EN */
__TEMPLATE
    }
    
    ### Fill-in the information of each memory
    my $combo_mem_dcm_ctrl_struct_68;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";

        $combo_mem_dcm_ctrl_struct_68 .= <<"__TEMPLATE";
   {
      EMI_CONTROL_J_VAL_MCP$combo_idx,
      EMI_CONTROL_L_VAL_MCP$combo_idx,
      EMI_CONTROL_J_15_36_VAL_MCP$combo_idx,
      EMI_CONTROL_L_15_36_VAL_MCP$combo_idx
   }$comma
__TEMPLATE
    }
    my $combo_mem_dcm_ctrl_struct_36;
    my $combo_mem_nor_psram_dcm_ctrl_struct_36;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";

        $combo_mem_dcm_ctrl_struct_36 .= <<"__TEMPLATE";
   {
      EMI_CONTROL_J_VAL_MCP$combo_idx,
      EMI_CONTROL_L_VAL_MCP$combo_idx,
      EMI_CONTROL_J_13_VAL_MCP$combo_idx,
      EMI_CONTROL_L_13_VAL_MCP$combo_idx
   }$comma
__TEMPLATE

       $combo_mem_nor_psram_dcm_ctrl_struct_36 .= <<"__TEMPLATE";
       {
      EMI_CONA_BURST_MCP$combo_idx,
      EMI_CONB_BURST_MCP$combo_idx,
      EMI_CONE_BURST_MCP$combo_idx,
      EMI_CONF_BURST_MCP$combo_idx,
      EMI_CONA_BURST_13MHZ_MCP$combo_idx,
      EMI_CONB_BURST_13MHZ_MCP$combo_idx,
      EMI_CONE_BURST_13MHZ_MCP$combo_idx,
      EMI_CONF_BURST_13MHZ_MCP$combo_idx
   }$comma
__TEMPLATE
    }
    my $combo_mem_dcm_ctrl_struct_35;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";

        $combo_mem_dcm_ctrl_struct_35 .= <<"__TEMPLATE";
   {
      EMI_CONTROL_J_VAL_MCP$combo_idx,
      EMI_CONTROL_K_VAL_MCP$combo_idx,
      EMI_CONTROL_L_VAL_MCP$combo_idx,
      EMI_CONTROL_M_VAL_MCP$combo_idx,
      EMI_GENERAL_A_VAL_MCP$combo_idx,
      EMI_GENERAL_B_VAL_MCP$combo_idx,
      EMI_GENERAL_C_VAL_MCP$combo_idx,
      EMI_CONTROL_J_13_VAL_MCP$combo_idx,
      EMI_CONTROL_K_13_VAL_MCP$combo_idx,
      EMI_CONTROL_L_13_VAL_MCP$combo_idx,
      EMI_CONTROL_M_13_VAL_MCP$combo_idx,
      EMI_GENERAL_A_13_VAL_MCP$combo_idx,
      EMI_GENERAL_B_13_VAL_MCP$combo_idx,
      EMI_GENERAL_C_13_VAL_MCP$combo_idx
   }$comma
__TEMPLATE
    }

    ###
    my $custom_setAdvEMI_header;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) == 1)
    {
        $custom_setAdvEMI_header .= <<"__TEMPLATE__";
#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE"
#endif /* __MTK_TARGET__ */
__TEMPLATE__
    }
    elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6253' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
    {
        $custom_setAdvEMI_header .= <<"__TEMPLATE__";
#if defined(__EMI_OPTION_DRIVER__)

#ifdef __MTK_TARGET__
#if defined(__EMI_INIT_FLOW_V1__)
#pragma arm section code = "INTSRAM_ROCODE"
#elif defined(__EMI_INIT_FLOW_V2__) /* __EMI_INIT_FLOW_V1__ */
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif  /* __EMI_INIT_FLOW_V1__ */
#endif /* __MTK_TARGET__ */
__TEMPLATE__
    }
    else
    {
        if ($BBtbl_EMI_NEW_INIT_FLOW{$MAKEFILE_OPTIONS_LOCAL->{'platform'}} and ($MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'NONE' and (!exists $MAKEFILE_OPTIONS_LOCAL->{'emmc_booting'} or $MAKEFILE_OPTIONS_LOCAL->{'emmc_booting'} eq 'NONE')))
        {
            $custom_setAdvEMI_header .= <<"__TEMPLATE__";
/**
  * On SRAM configuration, the old EMI init flow will perform Sync/Page EMI initialization at INTSRAM_ROCODE section, while 
  * the new EMI init flow will perform this flow at EMIINITCODE section.
  */
#if (defined(MT6236) || defined(MT6236B) || defined(MT6253))
#if !defined(__FUE__)
  /* __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
   * add this compile option to avoid compiling functions other than custom_setEMI()
   * The Bootloader will perform Sync/Page EMI initialization at the new EMI init flow, so we must be careful about 
   * the wrapping option so that Bootloader could reference this function.
   */
#endif /* MT6236 || MT6236B || MT6253 */

#if (defined(MT6236) || defined(MT6236B) || defined(MT6253))
#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */
#endif /* MT6236 || MT6236B || MT6253 */
__TEMPLATE__
        }
        else
        {
            $custom_setAdvEMI_header .= <<"__TEMPLATE__";
/**
  * On SRAM configuration, the old EMI init flow will perform Sync/Page EMI initialization at INTSRAM_ROCODE section, while 
  * the new EMI init flow will perform this flow at EMIINITCODE section.
  */
#if ( !defined(__UBL__) && !defined(__FUE__) )
  /* __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
   * add this compile option to avoid compiling functions other than custom_setEMI()
   * The Bootloader will perform Sync/Page EMI initialization at the new EMI init flow, so we must be careful about 
   * the wrapping option so that Bootloader could reference this function.
   */

#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE"
#endif /* __MTK_TARGET__ */
__TEMPLATE__
        }
    }
    chomp $custom_setAdvEMI_header;

    ###
    my $custom_setAdvEMI_tail;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) == 1)
    {
        $custom_setAdvEMI_tail .= <<"__TEMPLATE__";
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
__TEMPLATE__
    }
    elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6253' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
    {
        $custom_setAdvEMI_tail .= <<"__TEMPLATE__";
#ifdef __MTK_TARGET__
#if defined(__EMI_INIT_FLOW_V1__)
#pragma arm section code
#elif defined(__EMI_INIT_FLOW_V2__) /* __EMI_INIT_FLOW_V1__ */
#pragma arm section code, rodata, zidata
#endif  /* __EMI_INIT_FLOW_V1__ */
#endif /* __MTK_TARGET__ */

#endif /* __EMI_OPTION_DRIVER__ */

__TEMPLATE__
    }
    else
    {
        if ($BBtbl_EMI_NEW_INIT_FLOW{$MAKEFILE_OPTIONS_LOCAL->{'platform'}} and ($MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'NONE' and (!exists $MAKEFILE_OPTIONS_LOCAL->{'emmc_booting'} or $MAKEFILE_OPTIONS_LOCAL->{'emmc_booting'} eq 'NONE')))
        {
            $custom_setAdvEMI_tail .= <<"__TEMPLATE__";
#if (defined(MT6236) || defined(MT6236B) || defined(MT6253))
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */
#endif /* MT6236 || MT6236B || MT6253 */
__TEMPLATE__
        }
        else
        {
            $custom_setAdvEMI_tail .= <<"__TEMPLATE__";
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
__TEMPLATE__
        }
    }
    chomp $custom_setAdvEMI_tail;

    ###
    my $emi_necessary_driver_ifdef;
    if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6253' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
    {
        $emi_necessary_driver_ifdef .= <<"__TEMPLATE__";
#if defined(__EMI_NECESSARY_DRIVER__)
__TEMPLATE__
    }
    chomp $emi_necessary_driver_ifdef;

    ###
    my $emi_necessary_driver_endif;
    if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6253' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
    {
        $emi_necessary_driver_endif .= <<"__TEMPLATE__";
#endif /* __EMI_NECESSARY_DRIVER__ */
__TEMPLATE__
    }
    chomp $emi_necessary_driver_endif;
    
    ###
    my $emi_c_head;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) == 1)
    {
        $emi_c_head = <<"__TEMPLATE";
#if ( !defined(__UBL__) && !defined(__FUE__) )
  /* __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
   * add this compile option to avoid compiling functions other than custom_setEMI()
   */
__TEMPLATE
    }
    
    ###
    my $emi_c_tail;
    if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} ne 'MT6253' and $MAKEFILE_OPTIONS_LOCAL->{'platform'} ne 'MT6252H' and $MAKEFILE_OPTIONS_LOCAL->{'platform'} ne 'MT6252')
    {
        if ($BBtbl_EMI_NEW_INIT_FLOW{$MAKEFILE_OPTIONS_LOCAL->{'platform'}} and ($MAKEFILE_OPTIONS_LOCAL->{'nand_flash_booting'} eq 'NONE' and (!exists $MAKEFILE_OPTIONS_LOCAL->{'emmc_booting'} or $MAKEFILE_OPTIONS_LOCAL->{'emmc_booting'} eq 'NONE')))
        {
            $emi_c_tail .= <<"__TEMPLATE__";
#endif /* !__FUE__ */
__TEMPLATE__
        }
        else
        {
            $emi_c_tail .= <<"__TEMPLATE__";
#endif /* !__FUE__ && !__UBL__ */
__TEMPLATE__
        }
    }

    ###
    my $custom_setEMI_6252;
    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') or ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H'))
    {
    	$custom_setEMI_6252 .= <<"__TEMPLATE";
/*************************************************************************
* FUNCTION
*  setEMI_MT6252_series()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

/** 
  * Separated Init flow for MT6252(H)
  */ 
#if defined(MT6252) || defined(MT6252H)
kal_int8 setEMI_MT6252_series(void)
{
   unsigned short delay;

#if defined(__EMI_CLK_104MHZ__)

        /**
          * EMI switch to 104NHz 
          */
        *EMI_CLK_SEL |= 0x1;    

#endif  /* __EMI_CLK_104MHZ__ */

   /**
     * Initialize EMI SRARM controller timing if the rank is used.
     */
   if ( EMI_CSConfiguration[0] != UNUSED )
   {
      *(EMI_CONA) = EMI_CONA_ASYNC;
   }

   if ( EMI_CSConfiguration[1] != UNUSED )
   {
      *(EMI_CONB) = EMI_CONB_ASYNC;
   }

   if ( EMI_CSConfiguration[2] != UNUSED )
   {
      *(EMI_CONC) = EMI_CONC_ASYNC;
   }

   /**
       * Setting EMI general control register and cache/prefetch size if necessary. 
       */

   *EMI_GEN = EMI_GENERAL_CONTROL_ASYNC;
   *EMI_EXTCON = EMI_EXTCON_ASYNC;

   /**
     * MT6252H/L has 2 new registers for ED/EA/ECon/ECK driving control.
     */
   *EMI_IOA = EMI_DRIVING_CONTROL_A; 
   *EMI_IOB = EMI_DRIVING_CONTROL_B;

#if ( defined(MT6252H) && defined(__EMI_DEVICE_MODE_PAGE__) )

   *EMI_IOC = EMI_DRIVING_CONTROL_C;    // LCD/EMI share pin driving
   /* EA12-EA15 control by ACIF */
   *ACIF_CON0 = ( *ACIF_CON0 & 0x0FFFFFFF ) | (( EMI_DRIVING_CONTROL_C & 0x00000000F ) << 28);
   *ACIF_CON1 = ( *ACIF_CON1 & 0xFFF0FFFF ) | (( EMI_DRIVING_CONTROL_C & 0x0000000F0 ) << 12);

   *EMI_ADMUX &= ~0x1;

#endif

   *PREFETCH_CON = 0;   /* Async mode, EMI prefetch and cache should be disable in 52 EMI */
   *EMI_GEN2 &= ~(0x2); //Disable ULTRA_EN of EMI_GEN2

   return 0;

}
#endif /* MT6252 || MT6252H */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */
__TEMPLATE
    }
    
    ###
    my $custom_setAdvEMI_6252;
    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') or ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H'))
    {
    	$custom_setAdvEMI_6252 .= <<"__TEMPLATE";
/*************************************************************************
* FUNCTION
*  setAdvEMI_MT6252_series()
*
* DESCRIPTION
*   This routine aims to set additional EMI
*   This is special for device which needs to set device configuration
*   register to turn-on special mode.
*
* PARAMETERS
*
* RETURNS
*  1:
*
* GLOBALS AFFECTED
*
*************************************************************************/

$custom_setAdvEMI_header

#if defined(MT6252) || defined(MT6252H)

kal_int8 setAdvEMI_MT6252_series(void)
{
     kal_int8    status = 0;
     kal_int32   delay = 0xf;
     kal_uint32  i;
     
     volatile unsigned short *ptr16;
     unsigned short data;
     kal_uint32 saved_cache_con, saved_prefetch_con;

     /**
       * Backup L1 cache.
       */
     saved_cache_con = *CACHE_CON;
     /**
       * Disable L1 cache and EMI cache to prevent any commands being cached.
       */
     *CACHE_CON &= ~(0x000d);


#if defined(__EMI_DEVICE_MODE_BURST__)

#if !defined(MT6252)
    /**
      * Switch NOR-Flash RCR into corresponding modes.
      * This part is not part of the auto-gen template and is compile-time generated.
      */
    for (i=0;i<Sel_NOR_CMD_num; i++) 
    {
        if (EMI_NOR_BURST_OP[i] == MEM_CMD_OP_16BIT_RD) {
              data = *(volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS[i]);
        } else if (EMI_NOR_BURST_OP[i] == MEM_CMD_OP_16BIT_WR) {
            *(volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS[i]) = EMI_NOR_BURST_DATA[i];
        }
        for (delay=0; delay <0x0f; delay++) {
            #if defined(__RVCT__) && defined(__MTK_TARGET__)
            __nop()
            #endif
            ;
        }
    }
    for (delay=0; delay <0xff; delay++) {
        #if defined(__RVCT__) && defined(__MTK_TARGET__)
        __nop()
        #endif
        ;
    }
    
#endif /*MT6252*/

    /**
      *  Work-around for MT6252 SIP with APTIC PSRAM
      *  Adjust the driving to 1/8 !
      */
#if defined(MT6252)
    if ((__EMI_CurDIDR & __EMI_DIDR_APTIC_MASK) == (__EMI_DIDR_APTIC_VID & __EMI_DIDR_APTIC_MASK)) {
         /* overwrite the BCR configuration value */
       if ((EMI_PSRAM_BURST_DATA[2]& 0x0000ffff)== 0x01) {
          EMI_PSRAM_BURST_DATA[3] = __EMI_DIDR_APTIC_BCRVAL;
       } else if ((EMI_PSRAM_BURST_DATA[6]& 0x0000ffff)== 0x01) {
          EMI_PSRAM_BURST_DATA[7] = __EMI_DIDR_APTIC_BCRVAL;
       }
    }   
#endif

    /**
      * Switch PSRAM configuration (BCR/RCR) into corresponding modes.
      * This part is not part of the auto-gen template and is compile-time generated.
      */
    for (i=0;i<Sel_PSRAM_CMD_num; i++) 
    {
        if (EMI_PSRAM_BURST_OP[i] == MEM_CMD_OP_16BIT_RD) {
              data = *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS[i]);
        } else if (EMI_PSRAM_BURST_OP[i] == MEM_CMD_OP_16BIT_WR) {
            *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS[i]) = EMI_PSRAM_BURST_DATA[i];
        }
        for (delay=0; delay <0x0f; delay++) {
            #if defined(__RVCT__) && defined(__MTK_TARGET__)
            __nop()
            #endif
            ;
        }
    }
    for (delay=0; delay <0xff; delay++) {
        #if defined(__RVCT__) && defined(__MTK_TARGET__)
        __nop()
        #endif
        ;
    }
     
#endif /* __EMI_DEVICE_MODE_BURST__ */

#if defined(__EMI_DEVICE_MODE_PAGE__)

    for (i=0;i<Sel_PSRAM_CMD_num; i++) 
    {
        if (EMI_PSRAM_PAGE_OP[i] == MEM_CMD_OP_16BIT_RD) {
              data = *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_PAGE_ADDRESS[i]);
        } else if (EMI_PSRAM_PAGE_OP[i] == MEM_CMD_OP_16BIT_WR) {
            *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_PAGE_ADDRESS[i]) = EMI_PSRAM_PAGE_DATA[i];
        }
        for (delay=0; delay <0x0f; delay++) {
            #if defined(__RVCT__) && defined(__MTK_TARGET__)
            __nop()
            #endif
            ;
        }
    }
    for (delay=0; delay <0xff; delay++) {
        #if defined(__RVCT__) && defined(__MTK_TARGET__)
        __nop()
        #endif
        ;
    }

#endif /* __EMI_DEVICE_MODE_PAGE__ */



#if defined(__EMI_DEVICE_MODE_BURST__)

#if defined(MT6252)
     *EMI_CONB = EMI_CONB_BURST; 
     *EMI_EXTCON2 = EMI_EXTCON2_BURST;
         
     *EMI_IOA = EMI_DRIVING_CONTROL_A_BURST;
     *EMI_IOB = EMI_DRIVING_CONTROL_B_BURST;     

     *EMI_CLOCKDEL = 0x0; 
     *EMI_EXTCON = EMI_EXTCON_BURST;
     *EMI_EXTCON3 = 0x00020041;
       /* TX center align compensation */
     *EMI_CONB_EXT = 0x00040000;

     if( ( *EMI_EXTCON2 & 0x00700070 ) == 0x00300000 )
     {
         /* Page size 32 byte and wrap mode enable */
         *EMI_GEN3 |= 1;
     }
     
#endif /* MT6252 */

#if defined(MT6252H)
     *EMI_CONA = EMI_CONA_BURST;
     *EMI_CONB = EMI_CONB_BURST; 
     *EMI_EXTCON2 = EMI_EXTCON2_BURST;
         
     *EMI_IOA = EMI_DRIVING_CONTROL_A_BURST;
     *EMI_IOB = EMI_DRIVING_CONTROL_B_BURST;     

     *EMI_CLOCKDEL = 0x0; 
     *EMI_EXTCON = EMI_EXTCON_BURST;
     *EMI_EXTCON3 = 0x00130000;
       /* TX center align compensation */
       *EMI_CONA_EXT = 0x00040000;
       *EMI_CONB_EXT = 0x00040000;

     if( ( *EMI_EXTCON2 & 0x00770070 ) == 0x00330000 )
     {
         /* Page size 32 byte and wrap mode enable */
         *EMI_GEN3 |= 1;
     }
     
#endif /* MT6252H */

    *EMI_GEN = EMI_GENERAL_CONTROL_BURST;

     /* Prefetch must be turned on for burst mode and Cache must be turned off.due to design bug.
        For async mode, prefetch and cache must be turned off. */
     *PREFETCH_CON = 0x03060306;
     
#endif /*__EMI_DEVICE_MODE_BURST__*/

#if defined(__EMI_DEVICE_MODE_PAGE__)
     *EMI_CONA = EMI_CONA_PAGE;
     *EMI_CONB = EMI_CONB_PAGE; 
     *EMI_EXTCON2 = 0x01330000;
         
     *EMI_IOA = EMI_DRIVING_CONTROL_A;
     *EMI_IOB = EMI_DRIVING_CONTROL_B;     
     *EMI_IOC = EMI_DRIVING_CONTROL_C;  

     *EMI_GEN3 |= 1;   /* enable wrap access */  
#endif /*__EMI_DEVICE_MODE_BURST__*/



#if defined(MT6252)
    /* EMI is in burst mode */
    *EMI_ARBA = 0x0000D853; // MCU: 65%
    *EMI_ARBB = 0x0000D80D; // DMA: 10%
    *EMI_ARBC = 0x0000D820; // GMC: 25%  //change to soft mode support WQVGA from 11B.W11.33 Requested by AB.

#endif /* MT6252 */

#if defined(MT6252H)
     if( (*EMI_CONA & 0x00020000 ) && ( *EMI_CONB & 0x00020000) )
     {
         /* EMI is in burst mode */
         *EMI_ARBA = 0x0000D83F; // MCU: 49%
         *EMI_ARBB = 0x0000D80D; // DMA: 10%
         *EMI_ARBC = 0x00009834; // GMC: 40%
     }

     if( (*EMI_CONA & 0x00010000 ) && ( *EMI_CONB & 0x00010000) )
     {
         /* EMI is in page mode */
         *EMI_ARBA = 0x0000D845; // MCU: 53%
         *EMI_ARBB = 0x0000D814; // DMA: 15%
         *EMI_ARBC = 0x0000D827; // GMC: 30%%
     }
#endif /* MT6252H */
     
     for (delay=0; delay < 0xff; delay++);


    /**
      * Restore original L1 cache and EMI cache/prefetch setting.
      */
    *CACHE_CON = saved_cache_con;

   return status;
}

#endif /* MT6252 || MT6252H */

$custom_setAdvEMI_tail
__TEMPLATE
    }

    ###
    my ($custom_EMI_optional_func_by_device_type);
    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
    {
        $custom_EMI_optional_func_by_device_type .= <<"__TEMPLATE";
/*************************************************************************
* FUNCTION
*  __EMI_GetDIDR()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if defined(__EMI_COMBO_EN) && defined(__EMI_SIP_RAM)

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */

kal_uint32 __EMI_CurDIDR = 0; // will be also used in custom_setAdvEMI();

#if defined(MT6252)
void __EMI_GetDIDR(void)
{
     kal_uint16 didr, data;
     kal_int32 delay;
     
   /** 
     * Suppose the command sequence to be R -> R -> W -> R/W 
     */
   data = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   data = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }

   *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS) = 0x2;
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   didr = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   __EMI_CurDIDR = (kal_uint32)didr;
   
   return;
}
#endif /* MT6252 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
#endif /* __MTK_TARGET__ */

#endif /* __EMI_COMBO_EN && __EMI_SIP_RAM */

/*************************************************************************
* FUNCTION
*  __EMI_SelectSIPbyDIDR()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if defined(__EMI_COMBO_EN) && defined(__EMI_SIP_RAM)

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */

/**
  * DIDR:
  * Bit Field      Field name
  * DIDR[15]       Row length
  * DIDR[14:11]    Device version     
  * DIDR[10:8]     Device density
  * DIDR[7:5]      CellularRAM generation 
  * DIDR[4:0]      Vendor ID
  *
  * Last 2 bits of Device version (12:11) and Vendor ID will not be used to identify SIP configuration set
 */

#if defined(MT6252)
kal_uint32 __EMI_SelectSIPbyDIDR(void)
{
   kal_uint32 i;
   MTK_MEM_Info *mem_info;
   
   for (i=0; i<__EMI_COMBO_ENTRY_COUNT; i++) 
   {
      mem_info = (MTK_MEM_Info *)&CUST_MEM_INFO.mem_info[i];

      if ( (__EMI_CurDIDR&__EMI_DIDR_SELECT_MASK) == (mem_info->didr&__EMI_DIDR_SELECT_MASK) ) 
         return i;
   }

   while (1) {}; // ERROR !! unknow DIDR, trap here !!
}
#endif /* MT6252 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
#endif /* __MTK_TARGET__ */

#endif /* __EMI_COMBO_EN && __EMI_SIP_RAM */
__TEMPLATE
    }
    elsif (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2') and ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6276'))
    {
        $custom_EMI_optional_func_by_device_type .= <<"__TEMPLATE";
/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

void __EMI_SetEmiPllLowSpeed( void )
{
    volatile int delay;
    
    /**
       * Set the EMI PLL's source to be 26MHz crystal.
       */
    *PLL_CON4 &= 0xFF0F;

    /**
       * Set the EMI PLL enable from SW control register.
       */
    //*EPLL_CON1 = 0x0100;
    *EPLL_CON1 |= 0x0100;    // the PLL will be first set in BL for DDS, avoid to overwrite it

    /**
       * Set the EMI frequency to be 331MHz.
       */
    *EPLL_CON0 = 0x0000;

    /**
       * Set the EMI PLL to be 26MHz PLL.
       */    
    *EPLL_CON0 |=0x024C;

    /**
       * Enable EMI PLL.
       */    
    *EPLL_CON0 |=0x0001;

    /**
       * Set EMI PLL enable from HW top state machine control.
       */    
    *EPLL_CON1 &= 0xFEFF;

    /**
       * Set the EMI PLL's source to be 26MHz crystal again.
       */
    *PLL_CON4 &= 0xFF0F;

    /**
       * Set the EMI PLL's source to be EMI PLL divider output.
       */
    *PLL_CON4 |= 0x0010;

    /**
       * Wait for PLL stable.
       */   
    __EMI_DelayLoop(10000);
}

#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

void __EMI_SetEmiPllHighSpeed( void )
{
    volatile int delay;

    // 166 MHz
    *EPLL_CON0 &= 0x00FF;

//#if (__EMI_CLK_200MHZ__) && !defined(__MT6276_CONCURRENCY_TEST__)
#if defined(__EMI_CLK_200MHZ__)
    *EPLL_CON0 |= 0x6F00;
#endif
    
    for(delay=0; delay<10000; delay++);

}

#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_InitializeLPDDR()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)
    
void __EMI_InitializeLPDDR( void )
{
    volatile int i;
    kal_uint32 dram_rank = DRAM_CS;
    
    volatile SW_SECVERSION sw_sec_version;
    
    sw_sec_version = INT_SW_SecVersion();
    //sw_sec_version = *SW_VER & 0x00FF;
    
    /**
       * Disable Dummy Read.
       */
    *EMI_DRCT=0x0;

    /* Apply output delay */
    *EMI_ODLA=EMI_ODL_A_VAL;
    *EMI_ODLB=EMI_ODL_B_VAL;
    *EMI_ODLC=EMI_ODL_C_VAL;
    *EMI_ODLD=EMI_ODL_D_VAL;
    *EMI_ODLE=EMI_ODL_E_VAL;
    *EMI_ODLF=EMI_ODL_F_VAL;    // only for LPDDR2, 2x CMD
    *EMI_ODLG=EMI_ODL_G_VAL;
    
    /* Apply IO duty */
    *EMI_DUTA=EMI_IODUTY_A_VAL;
    *EMI_DUTB=EMI_IODUTY_B_VAL;
    *EMI_DUTC=EMI_IODUTY_C_VAL;

    /* Apply RX duty auto tracking */
    *EMI_DUCA=EMI_RXDUTY_A_VAL;
    *EMI_DUCB=EMI_RXDUTY_B_VAL;
    *EMI_DUCE=EMI_RXDUTY_E_VAL;

    /* Apply IO Misc. Control L */
    *EMI_IOCL=EMI_IOMISC_L_VAL;

    /**
       * Set AC Timing Parameters for according memory device.
       */
    *EMI_CONJ=EMI_CONTROL_J_VAL; 
    *EMI_CONK=EMI_CONTROL_K_VAL;
#if defined(__EMI_DEVICE_LPDDR2__)
    if (sw_sec_version == SW_SEC_0)
    {
        // SW work-aruond on 6276 E2
        *EMI_CONL=EMI_CONTROL_L_VAL & 0xffffffcf | 0x00000020; // RW_LAT = 2 (RL5, WR2)
    } 
    else 
    {
        *EMI_CONL=EMI_CONTROL_L_VAL;
    }
#else /* __EMI_DEVICE_LPDDR2__ */
    *EMI_CONL=EMI_CONTROL_L_VAL;
#endif
    *EMI_CONN=EMI_CONTROL_N_VAL;
    
#if defined(__EMI_DEVICE_LPDDR1__)
    /**
       * Set LPDDR device configuration.
       */
    *EMI_CONI=EMI_CONTROL_I_VAL;
#endif
    
    /**
       * Set DRAM rank.
       * We enable DRAM rank, and enable the rest of the rank to be SRAM to prevent SW bug cause EMI hang.
       */
    if(0 == dram_rank)
    {
        *EMI_GEND = 0x0001000E;
    }
    else if(1 == dram_rank)
    {
        *EMI_GEND = 0x0002000D;
    }
    else
    {
        ASSERT(0);
    }
    

    /**
       * Pad swap function mode (configure as DDRI or DDRII/SRAM pad configuration).
            0x2/0x3 : LPDDR
            0x4/0x5 : LPDDR2
       */
#if defined(__EMI_DEVICE_LPDDR1__)
    *EMI_IOCL |= 0x03000000;
#elif defined(__EMI_DEVICE_LPDDR2__)
    *EMI_IOCL &= ~(0x10000000); /* IOCL = 0 (EMI_IOCL[28]=0, use O1 path) */
    *EMI_IOCL |= 0x05000000;
#else
    #error
#endif

#if defined(__EMI_DEVICE_LPDDR2__)
    /**
      * Enable ZQ Calibration
      */
    *EMI_DDRV = ( 1 << ( DRAM_CS + 4 ) );    
#endif

    /**
       * Delay for a while.
       */    
    __EMI_DelayLoop(0xfff);


    /**
       * Enable external clock (DRAM clk out & HCLKX2_CK).
       */
#if defined(__EMI_DEVICE_LPDDR1__)
    *EMI_GENA |= 0x00000300;
#endif
    /**
       * Remap if necessary.
       */    
    if(0 == dram_rank)
    {
        *EMI_GENA &= (~0xF);
        *EMI_GENA |= 0x0A;
    }
    else if(1 == dram_rank)
    {
        *EMI_GENA &= (~0xF);
        *EMI_GENA |= 0x0B;
    }
    else
    {
        ASSERT(0);
    }

    
    /**
       * EMI Driving, it needs to be set before LPDDR being initialized.
       */    
    *EMI_DRVA = EMI_DRV_A_VAL;
    *EMI_DRVB = EMI_DRV_B_VAL;
    

    /**
       * Delay for a while.
       */    
    __EMI_DelayLoop(0xff);
    
    
    /**
       * LPDDR Initial Flow.
       */
#if defined(__EMI_DEVICE_LPDDR1__)    
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x10000000;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x08000000;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x04000000;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x02000000;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x01000000;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x00000000; 
    __EMI_DelayLoop(0xff);
#elif defined(__EMI_DEVICE_LPDDR2__) /* __EMI_DEVICE_LPDDR1__ */
    /**
       * [Initial Flow 1]:Power Ramp
       */
    
    /**
       * [Initial Flow 2]:CKE and clock
       * Enable Clock ( DRAM clk out / delay-line HCLKX2_CK/ SRAM clk center-align /CKE_EN )
       */
    // *EMI_GENA |= 0x00000B10;  
    *EMI_GENA |= 0x00000310;
    
    /**
       * [Initial Flow 3]:Reset Command
       */    
    *EMI_CONI = 0x003F0000;
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x20000000; //0x20950901;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //0x00950901
    __EMI_DelayLoop(0xfff);
        
    /**
       * [Initial Flow 4]:Mode Registers Reads and Device Auto-Initialization (DAI) polling
       */
    *EMI_CONI = 0x00000000;
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x40000000; //0x40950901;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //0x00950901
    __EMI_DelayLoop(0xfff);

    /**
       * [Initial Flow 5]:ZQ Calibration
       */
    *EMI_CONI = 0xFF0A0000;
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x20000000; //0x20950901;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //0x00950901;
    __EMI_DelayLoop(0xfff);
    
    /**
      * Set Device Feature
      */   
    // Set Device Feature1 - nWR=3, WC=Wrap, BT=sequential, BL=4
    *EMI_CONI = 0x22010000;
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x20000000; //0x20950901;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //0x00950901;
    __EMI_DelayLoop(0xfff);

    // Set Device Feature2 - RL4/WL2
    if (sw_sec_version == SW_SEC_0)
    {
        /**
           * SW work-around; If we use LPDDR2(400) before 6276 E2,
           * the MR2 should be RL4/WL2 and EMI should be RL5/WL2 (RW_LAT=2)
           */
        *EMI_CONI = 0x02020000; // RL4/WL2 for LPDDR2-400
    } 
    else 
    {
        *EMI_CONI = 0x01020000; // RL3/WL1 for LPDDR2-400
    } 
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x20000000; //0x20950901;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //0x00950901;
    __EMI_DelayLoop(0xfff);

    // add for LPDDR2 DRAM driving setting
    *EMI_CONI = EMI_CONTROL_I_VAL; // 0x02030000
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x20000000; //|= MRW_EN;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //&= ~MRW_EN;
    __EMI_DelayLoop(0xfff);
    
    // Clear Initial Bits
    *EMI_CONN &= ~0xFF000000;
#endif  /* __EMI_DEVICE_LPDDR1__ */ 

    /**
       * Enable auto-refresh, fixed-clock (for auto-refresh), and pdn.
       */        
   *EMI_CONN |=  0x00000016;

    __EMI_DelayLoop(0xff);      
}

#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_DataTrackingMbistTestCore()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)


kal_int32 __EMI_DataTrackingMbistTestCore(kal_int32 algo_sel, kal_int32 addr_scramble_sel, kal_int32 data_scramble_sel)
{
    volatile kal_int32 delay;
    
    /**
       * MBIST reset.
       */
    *EMI_MBISTA = 0x0;

    /**
       * MBIST data-pattern setting.
       */
    *EMI_MBISTB = 0xFFFF0000 | ((0x0000A55A) >> (algo_sel + addr_scramble_sel + data_scramble_sel));

    /**
       * MBIST starting address.
       */
    *EMI_MBISTC = 0x410000>>10;

    /**
       * MBIST ending address.
       */
    *EMI_MBISTD = 0x410000>>10;

    /**
       * ClearBIST address/data scramble and algorithm.
       */
    *EMI_MBISTA &= 0xFFFF000F;


    *EMI_MBISTA |= (0x00220000 | algo_sel<<4 | addr_scramble_sel<<12 | data_scramble_sel<<8 | 1);
    __EMI_DelayLoop(0xff);

    /**
       * Start MBIST test.
       */
    *EMI_MBISTA = *EMI_MBISTA | 2;

    /**
       * Polling the MBIST test finish status.
       */
    while(!(*EMI_MBISTE&0x0002));

    /**
       * Check the MBIST result.
       */
    if(*EMI_MBISTE&0x0001)
    {
        /**
           * addr[15:00]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x0 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_addr = ( *EMI_MBISTE & 0xFFFF0000 ) >> 16;
#endif

        /**
           * addr[31:16]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x1 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
         emi_data_training_err_info.err_addr |= ( *EMI_MBISTE & 0xFFFF0000 );
#endif

        /**
           * wdataL[15:00]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x4 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_wdataL= ( *EMI_MBISTE & 0xFFFF0000 ) >> 16;
#endif

        /**
           * wdataL[31:16]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x5 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_wdataL |= ( *EMI_MBISTE & 0xFFFF0000 );
#endif

        /**
           * wdataH[47:32]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x6 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_wdataH = ( *EMI_MBISTE & 0xFFFF0000 ) >> 16;
#endif

        /**
           * wdataH[63:48]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x7 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_wdataH |= ( *EMI_MBISTE & 0xFFFF0000 );
#endif

        /**
           * rdataL[15:00]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x8 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_rdataL = ( *EMI_MBISTE & 0xFFFF0000 ) >> 16;
#endif

        /**
           * rdataL[31:16]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x9 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_rdataL |= ( *EMI_MBISTE & 0xFFFF0000 );
#endif

        /**
           * rdataH[47:32]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0xA << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_rdataH = ( *EMI_MBISTE & 0xFFFF0000 ) >> 16;
#endif

        /**
           * rdataH[63:48]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0xB << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_rdataH |= ( *EMI_MBISTE & 0xFFFF0000 );
#endif

        /**
           * MBIST reset.
           */
        *EMI_MBISTA = 0x0;
        
        return -1;
    }
    else
    {
        /**
           * MBIST reset.
           */
        *EMI_MBISTA = 0x0;

        return 0;
    }
}
    
#endif /* MT6276 */
  
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

kal_int32 __EMI_DataAutoTrackingMbistTest(void)
{
    kal_int32 algo_sel, data_scramble_sel;
    // kal_int32 addr_scramble_sel;
    kal_uint32 EMI_DRCT_bakval;

    /**
       * Backup dummy read control. 
       */
    EMI_DRCT_bakval = *EMI_DRCT;

    /**
       * Disable dummy read before testing MBIST (must). 
       */
    *EMI_DRCT &= ~(0x1);
        
    for(algo_sel=0; algo_sel<3; algo_sel++)
    {
        for(data_scramble_sel=0; data_scramble_sel<7; data_scramble_sel++)
        {
            if( __EMI_DataTrackingMbistTestCore( algo_sel, 0x0, data_scramble_sel ) != 0 )
            {
                /**
                    * Restore dummy read control. 
                    */
                *EMI_DRCT = EMI_DRCT_bakval;
                return -1;
            }
        }
    }

    /**
        * Restore dummy read control. 
        */
   *EMI_DRCT = EMI_DRCT_bakval;
 
    return 0;
}


#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

void __EMI_DataAutoTrackingRegRead( EMI_DATA_TRAIN_REG_t* pREG )
{
    if( pREG != 0 )
    {
        pREG->EMI_DLLV_regval = *EMI_DLLV;
        pREG->EMI_DQSV_regval = *EMI_DQSV;
        pREG->EMI_CONN_regval = *EMI_CONN;        
        pREG->EMI_DQSA_regval = *EMI_DQSA;
        pREG->EMI_DQSE_regval = *EMI_DQSE;        
        pREG->EMI_IDLA_regval = *EMI_IDLA;
        pREG->EMI_IDLB_regval = *EMI_IDLB;
        pREG->EMI_IDLC_regval = *EMI_IDLC;
        pREG->EMI_IDLD_regval = *EMI_IDLD;
        pREG->EMI_IDLE_regval = *EMI_IDLE;
        pREG->EMI_IDLF_regval = *EMI_IDLF;
        pREG->EMI_IDLG_regval = *EMI_IDLG;
        pREG->EMI_IDLH_regval = *EMI_IDLH;
        pREG->EMI_IDLI_regval = *EMI_IDLI;        
        pREG->EMI_CALA_regval = *EMI_CALA;
        pREG->EMI_CALE_regval = *EMI_CALE;
        pREG->EMI_CALI_regval = *EMI_CALI;
        pREG->EMI_CALP_regval = *EMI_CALP;
    }    
    else
    {
        ASSERT(0);
    }
}


#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

/*static*/ void __EmiDataTrainRegWrite( EMI_DATA_TRAIN_REG_t* pREG )
{
    if( pREG != 0 )
    {
        *EMI_CONN = pREG->EMI_CONN_regval;
                 
        *EMI_DQSA = pREG->EMI_DQSA_regval;
        *EMI_DQSE = pREG->EMI_DQSE_regval;
                    
        *EMI_IDLA = pREG->EMI_IDLA_regval;
        *EMI_IDLB = pREG->EMI_IDLB_regval;
        *EMI_IDLC = pREG->EMI_IDLC_regval;
        *EMI_IDLD = pREG->EMI_IDLD_regval;
        *EMI_IDLE = pREG->EMI_IDLE_regval;
        *EMI_IDLF = pREG->EMI_IDLF_regval;
        *EMI_IDLG = pREG->EMI_IDLG_regval;
        *EMI_IDLH = pREG->EMI_IDLH_regval;
        *EMI_IDLI = pREG->EMI_IDLI_regval;
                    
        *EMI_CALA = pREG->EMI_CALA_regval;
        *EMI_CALE = pREG->EMI_CALE_regval;
        *EMI_CALI = pREG->EMI_CALI_regval;
        *EMI_CALP = pREG->EMI_CALP_regval;
    }
    
}
    

#endif /* MT6276 */
    
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

int __EMI_DataAutoTrackingTraining( EMI_DATA_TRAIN_REG_t* pResult )
{    
    kal_int32 value;
    kal_int32 test_result;
    kal_int32 bytex_dly_mod, bytex_setup_mod, dqy_in_del, dqsix_dlysel;
    kal_int32 bytex_dly_mod_start = 0, bytex_setup_mod_start = 0, dqy_in_del_start = 0;
    kal_int32 prev_emi_idl = 0, prev_emi_cala = 0, prev_emi_cale = 0, prev_emi_cali = 0;
    kal_int32 prev_dwnd_size = 0, dwnd_size;
    kal_int32 lbound_finding;
    kal_int32 DATA_TUNING_STEP = 1;       
    int b_wnd_found = 0;
    static EMI_DATA_TRAIN_REG_t REG_BAK = {1, 2, 3}; /*use static to avoid stack overflow*/
    

    /**
       * Backup modified register at entry
       */

    __EMI_DataAutoTrackingRegRead( &REG_BAK );
    
    /**
       * Disable data auto tracking" & "setup/hold max value" before data auto-tracking training.
       */
    *EMI_CALP &= ~0xFFFF0001;

    /**
       * Disable 1/5T DLL before data auto-tracking training.
       */
    *EMI_CONN &= ~(1<<8);

    /**
       * Disable DQSi auto-tracking before data auto-tracking training.
       */
    *EMI_DQSE &= ~0x0000FFFF;
           
    for(dqsix_dlysel=0x0; dqsix_dlysel<=0x7F; dqsix_dlysel+=8)
    {        
        /**
            * Set auto tracking init value.
            */
        *EMI_DQSA = dqsix_dlysel<<24 | dqsix_dlysel<<16 | dqsix_dlysel<<8 | dqsix_dlysel;

        lbound_finding = 1;

        /**
           * byte_delay = 0. 
           * byte_setup = 0. 
           */
        bytex_dly_mod = 0;
        bytex_setup_mod = 0;

        /**
           * DQSi input delay = 0. 
           */
        *EMI_IDLI = 0;

        /**
           * Set data setup time = 0. 
           */
        *EMI_CALE = 0;

        /**
           * Set data delay time = 0. 
           */
        *EMI_CALA = 0;

        /**
           * Set data hold time = 0. 
           */
        *EMI_CALI = 0;

        /**
            * Iterate dq_in delay 0x1F ~ 0. 
            */
        for(dqy_in_del=0x1F; dqy_in_del>=0; dqy_in_del-=DATA_TUNING_STEP)
        {
            *EMI_IDLA = *EMI_IDLB = *EMI_IDLC = *EMI_IDLD = *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = dqy_in_del<<24 | dqy_in_del<<16 | dqy_in_del<<8 | dqy_in_del;

            /**
               * Clear DDRFIFO to prevent any data queued within the FIFO causing our read-comparison result is untrustable.
               */
            *EMI_CALP |= 0x00000100;
            *EMI_CALP &= 0xFFFFFEFF;

            /**
               * Perform DQS calibration. 0 = pass, non-0 = fail.
               */
#if defined( ___EMIDATATRAIN_MBIST_DATATRAIN__ )
            test_result = __EMI_DataAutoTrackingMbistTest();
#else /* ___EMIDATATRAIN_MBIST_DATATRAIN__ */
            /**
               * Perform DQS calibration need to create 2 DQS-pulse, which is 32B on DDR32 case. 
               */
            store_8word(0x0, 0x12345678);
            test_result = load_8word(0x0, 0x12345678);
#endif /* ___EMIDATATRAIN_MBIST_DATATRAIN__ */

            
            if(lbound_finding==1 && test_result == 0)
            {
                /**
                   * R/W ok & during boundary finding ==> 0->1 , record the start boundary. 
                   */
                dqy_in_del_start = dqy_in_del;
                bytex_dly_mod_start = bytex_dly_mod;
                bytex_setup_mod_start = bytex_setup_mod;
                
                lbound_finding = 0;
            }
            else if(lbound_finding==0 && test_result != 0 )
            {
                /**
                   * R/W faill & not during boundary finding ==> 1->0.
                   */
                goto window_found;
            }            
        }

        /**
            * This value should be already be 0. 
            */
        dqy_in_del = 0; 
        *EMI_IDLA = *EMI_IDLB = *EMI_IDLC = *EMI_IDLD = *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = 0;
                
        for(bytex_setup_mod=0; bytex_setup_mod<=0x1F; bytex_setup_mod+=DATA_TUNING_STEP)
        {                       
            *EMI_CALE = bytex_setup_mod<<24 | bytex_setup_mod<<16 | bytex_setup_mod<<8 | bytex_setup_mod;

            /**
                * Clear DDR FIFO.
                */
            *EMI_CALP |= 0x00000100;
            *EMI_CALP &= 0xFFFFFEFF;

            /**
                * DQS calibration. 
                */
            #if defined( ___EMIDATATRAIN_MBIST_DATATRAIN__ )
            test_result = __EMI_DataAutoTrackingMbistTest();
            #else
            store_8word(0x0, 0x12345678);
            test_result = load_8word(0x0, 0x12345678);
            #endif

            if(lbound_finding==1 && test_result == 0 )
            {
                bytex_dly_mod_start = bytex_dly_mod;
                bytex_setup_mod_start = bytex_setup_mod;
                dqy_in_del_start = dqy_in_del;

                lbound_finding = 0;

            }
            else if(lbound_finding==0 && test_result != 0 )
            {
                goto window_found;
            }
        }


        /**
           * This value should be already be 0x1F. 
           */
        bytex_setup_mod=0x1F; 
        *EMI_CALE = bytex_setup_mod<<24 | bytex_setup_mod<<16 | bytex_setup_mod<<8 | bytex_setup_mod;

        for(bytex_dly_mod=0; bytex_dly_mod<=0x1F; bytex_dly_mod+=DATA_TUNING_STEP)
        {
            *EMI_IDLI = bytex_dly_mod<<24 | bytex_dly_mod<<16 | bytex_dly_mod<<8 | bytex_dly_mod;

            /**
                * Clear DDR FIFO.
                */
            *EMI_CALP |= 0x00000100;
            *EMI_CALP &= 0xFFFFFEFF;

            /**
                * DQS calibration. 
                */
            #if defined( ___EMIDATATRAIN_MBIST_DATATRAIN__ )
            test_result = __EMI_DataAutoTrackingMbistTest();
            #else
            store_8word(0x0, 0x12345678);
            test_result = load_8word(0x0, 0x12345678);
            #endif

            if(lbound_finding==1 && test_result == 0 )
            {
                bytex_dly_mod_start = bytex_dly_mod;
                bytex_setup_mod_start = bytex_setup_mod;
                dqy_in_del_start = dqy_in_del;

                lbound_finding = 0;

            }
            else if(lbound_finding==0 && test_result != 0 )
            {
                goto window_found;
            }

    }
    
        /**
            * Find a windows that only have one-end boundary,ex. 000111111.
            */
        if(lbound_finding == 0)
        {
            goto window_found;
        }

        /**
            * Window is not found, use next mask setting. 
            */
        continue;

    window_found:

        b_wnd_found = 1;

        if(bytex_dly_mod>0x1F)
        {
            /**
               * Unexpected case.
               */
            bytex_dly_mod = 0x1F;
        }

        if(bytex_setup_mod>0x1F)
        {
            /**
               * Unexpected case.
               */
            bytex_setup_mod = 0x1F;
        }

        if(dqy_in_del<0)
        {
            /**
               * Unexpected case.
               */
            dqy_in_del = 0;
        }

        if(dqsix_dlysel>0x7F)
        {
            /**
               * Unexpected case.
               */
            dqsix_dlysel = 0x7F;
        }

        dwnd_size = (dqy_in_del_start-dqy_in_del)+(bytex_setup_mod-bytex_setup_mod_start)+(bytex_dly_mod-bytex_dly_mod_start);

        if(prev_dwnd_size && (prev_dwnd_size >= dwnd_size))
        {
            /**
               * Once find a windows less or equal previous one, use:
               * 1. Previous delay setting
               * 2. current mask setting ( in case the previous one is in mask boundary )
               * and finish data training.
               */
            *EMI_IDLA = *EMI_IDLB = *EMI_IDLC = *EMI_IDLD = *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = prev_emi_idl;
            *EMI_CALA = prev_emi_cala;
            *EMI_CALE = prev_emi_cale;
            *EMI_CALI = prev_emi_cali;
            
            break;
        }

        prev_dwnd_size = dwnd_size;

        /**
           * Set DQ input delay to align "DQS riging" & "data out". 
           */
        *EMI_IDLA = *EMI_IDLB = *EMI_IDLC = *EMI_IDLD = *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = prev_emi_idl =
        dqy_in_del_start<<24 | dqy_in_del_start <<16 | dqy_in_del_start <<8 | dqy_in_del_start;

        /**
           * Set auto-tracking byte data delay from DQS. 
           */
        value = (bytex_setup_mod_start+(dwnd_size/2))>31? (bytex_setup_mod_start+(dwnd_size/2))-31:0;
        *EMI_CALA = prev_emi_cala = value<<24 | value<<16 | value<<8 | value;


        /**
           * Set auto-tracking byte data setup from DQS. 
           */
        value = (bytex_setup_mod_start+(dwnd_size/2))<31? (bytex_setup_mod_start+(dwnd_size/2)):31;
        *EMI_CALE = prev_emi_cale = value<<24 | value<<16 | value<<8 | value;

        /*byte Data Hold*/
        value = ( dwnd_size/2 > 31 ) ? 31 : dwnd_size/2;
        *EMI_CALI = prev_emi_cali = value<<24 | value<<16 | value<<8 | value; 
        //dwnd_size/2; 

        /*Go next mask setting*/
        
    }

    /**
       * Set up MAX "Data Setup" & " Data Hold" to constrain the auto-tracking window shift.
       */
     value = ( prev_dwnd_size/2 > 31 ) ? 31 : prev_dwnd_size/2;
    *EMI_CALP &= 0x0000FFFF;
    *EMI_CALP |= ((kal_uint32)1 << 31 ) | ( value << 24) | ( 1 << 23 ) | ( value << 16 );

    /**
       * Return Training Result and Restore Register.
       */
     __EMI_DataAutoTrackingRegRead( pResult ); 
     __EmiDataTrainRegWrite( &REG_BAK );             
     __EMI_DataAutoTrackingRegRead( &REG_BAK );
     
    return  b_wnd_found;
    
}

#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI_MT6276()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if defined(MT6276)

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

kal_int8 __EMI_InitializationFlow(void)
{
    int ret = 1;

    EMI_DATA_TRAIN_REG_t    DATA_TRAIN_RESULT_REG;

    /*********
      *
      * Set EMI low speed before initial LPDDR.
      * This is special for LPDDR2.
      *
      ********/

    __EMI_SetEmiPllLowSpeed();


    /*********
      *
      * Initial LPDDR.
      *
      ********/

    __EMI_InitializeLPDDR();


    /*********
      *
      * Restore EMI Pll to high speed before data tracking tuning.
      *
      ********/

    __EMI_SetEmiPllHighSpeed();


    /*********
      *
      * Data training.
      *
      ********/

    ret = __EMI_EnableDataAutoTracking(&DATA_TRAIN_RESULT_REG);


    /*********
      *
      * Enable performance/power related module.      
      *
      ********/

    __EMI_EnablePerformancePowerControl();


    /*********
      *
      * Enable bandwidth limiter.
      *
      ********/
   
    __EMI_EnableBandwidthLimiter();


#if defined(MT6276_S00)
    /*********
      *
      * Enable EMI work-around for HW DCM.
      *
      ********/

    __EMI_HwDcmInitialization();
#endif


#if defined(__DBG_EVB_CHECK_FAIL)    
    /*********
      *
      * Detect EMI timing shift.
      *
      ********/

    dbg_is_evb_check_fail = __EMI_CheckTxDelayLevel();        

    /*********
      *
      * Record EMI register value after initialization.
      *
      ********/

    __EMI_RecordRegInitStatus();
#endif // __DBG_EVB_CHECK_FAIL

    return ret;    
}

#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_EnableDataAutoTracking()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)
 
int __EMI_EnableDataAutoTracking( EMI_DATA_TRAIN_REG_t* DATA_TRAIN_RESULT_REG)
{
    int ret = 1;

    #if defined(MT6276)
    int adjust_dqi;
    #endif

    // the output delay must be applied before DDR init 
    /*
    *EMI_ODLA=EMI_ODL_A_VAL;
    *EMI_ODLB=EMI_ODL_B_VAL;
    *EMI_ODLC=EMI_ODL_C_VAL;
    *EMI_ODLD=EMI_ODL_D_VAL;
    *EMI_ODLE=EMI_ODL_E_VAL;
    *EMI_ODLG=EMI_ODL_G_VAL;
    */
    
    if( __EMI_DataAutoTrackingTraining(DATA_TRAIN_RESULT_REG ) == 0 )
    {
        /**
           * Data training fail. 
           */
        ret = 0; 
    }

    /**
       * Mask auto tracking initial value. 
       */
    *EMI_DQSA = DATA_TRAIN_RESULT_REG->EMI_DQSA_regval;     

#if defined(__EMI_DATA_AUTO_TRACKING_ENABLE)
   
    /**
        * Data Auto Tracking init value. 
        */
    *EMI_CALA = DATA_TRAIN_RESULT_REG->EMI_CALA_regval;     
    *EMI_CALE = DATA_TRAIN_RESULT_REG->EMI_CALE_regval;
    *EMI_CALI = DATA_TRAIN_RESULT_REG->EMI_CALI_regval;    
    *EMI_CALP = DATA_TRAIN_RESULT_REG->EMI_CALP_regval;    

    /**
        * Enable auto data tracking. 
        */
    *EMI_CALP |= 0x1;                                       
    
#else
    
    #if defined(MT6276)
    /* The variation of timing window on L/R boundary is un-balance under different corner case;
       It will be better to apply some adjusting */
    adjust_dqi = DATA_TRAIN_RESULT_REG->EMI_IDLA_regval & 0x1f;
    adjust_dqi = adjust_dqi + 3;
    if (adjust_dqi > 0x1f) adjust_dqi = 0x1f;
    
    DATA_TRAIN_RESULT_REG->EMI_IDLA_regval = DATA_TRAIN_RESULT_REG->EMI_IDLB_regval = 
    DATA_TRAIN_RESULT_REG->EMI_IDLC_regval = DATA_TRAIN_RESULT_REG->EMI_IDLD_regval = 
    DATA_TRAIN_RESULT_REG->EMI_IDLE_regval = DATA_TRAIN_RESULT_REG->EMI_IDLF_regval = 
    DATA_TRAIN_RESULT_REG->EMI_IDLG_regval = DATA_TRAIN_RESULT_REG->EMI_IDLH_regval
             = (adjust_dqi << 24) | (adjust_dqi << 16) | (adjust_dqi << 8) | adjust_dqi;
    #endif
    
    /**
       * DQ-in delay. 
       */
    *EMI_IDLA = DATA_TRAIN_RESULT_REG->EMI_IDLA_regval;     
    *EMI_IDLB = DATA_TRAIN_RESULT_REG->EMI_IDLB_regval;
    *EMI_IDLC = DATA_TRAIN_RESULT_REG->EMI_IDLC_regval;
    *EMI_IDLD = DATA_TRAIN_RESULT_REG->EMI_IDLD_regval;
    *EMI_IDLE = DATA_TRAIN_RESULT_REG->EMI_IDLE_regval;
    *EMI_IDLF = DATA_TRAIN_RESULT_REG->EMI_IDLF_regval;
    *EMI_IDLG = DATA_TRAIN_RESULT_REG->EMI_IDLG_regval;
    *EMI_IDLH = DATA_TRAIN_RESULT_REG->EMI_IDLH_regval;

    /** 
        * Enable 1/5 PLL. 
        */
    *EMI_CONN |= 0x00000100;    
        
    /**
       * Add new timing delay to meet new EMI timing constrain that after enabling 1/5 DLL.
       */
    __EMI_DelayLoop(0xfff);
        
#endif // __EMI_DATA_AUTO_TRACKING_ENABLE

    /** 
        * Setup HW EMI calibration for sleep mode resume.
        */
    *EMI_DQSE |= 0x1000FFFF;
               
    /**
       * Enable Dummy Read 
       */
   *(volatile kal_uint32*)EMI_DRCT=0x8000F001;

    return ret;    
}


#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */



/*************************************************************************
* FUNCTION
*  __EMI_EnableBandwidthLimiter()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)
 
int __EMI_EnableBandwidthLimiter( void )
{

    if (CHIP_MT6276M == INT_ChipName())
    {
        /* Set ARM BW*/
        *EMI_ARBA = EMI_ARB_A_VAL_MT6276M;

        /* Set FCore BW */
        *EMI_ARBB = EMI_ARB_B_VAL;

        /* Set FCore-DMA BW */
        *EMI_ARBC = EMI_ARB_C_VAL;

        /* Set 2G/3G BW */
        *EMI_ARBD = EMI_ARB_D_VAL;

        /* Set MM BW */
        *EMI_ARBE = EMI_ARB_E_VAL_MT6276M;

        /* Set Peri./Audio/ARM-DMA BW */
        *EMI_ARBF = EMI_ARB_F_VAL;

    } else {
      /* MT6276 || MT6276D */
        
        /* Set ARM BW*/
        *EMI_ARBA = EMI_ARB_A_VAL;

        /* Set FCore BW */
        *EMI_ARBB = EMI_ARB_B_VAL;

        /* Set FCore-DMA BW */
        *EMI_ARBC = EMI_ARB_C_VAL;

        /* Set 2G/3G BW */
        *EMI_ARBD = EMI_ARB_D_VAL;

        /* Set MM BW */
        *EMI_ARBE = EMI_ARB_E_VAL;

        /* Set Peri./Audio/ARM-DMA BW */
        *EMI_ARBF = EMI_ARB_F_VAL;
    }
   
    return 0;
}


#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_EnablePerformancePowerControl()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)
 
int __EMI_EnablePerformancePowerControl( void )
{
    /**
       * Setup Precharge & PDN delay 
       */
    *(volatile kal_uint32*)EMI_PPCT=0xFFFF0000;

    /** 
        * Disable all HI prio and enable R/W command flavor.
        */
    *(volatile kal_uint32*)EMI_SLCT=0x0000003F;

    /**
        * Setup 1/16 freq for HWDCM mode and enable arbitration controls 
        */ 
    *(volatile kal_uint32*)EMI_ABCT=0x00070010;

    __EMI_DelayLoop(100);

    return 0;    
}


#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_OutputTxWindow()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

#if defined(__DBG_EVB_CHECK_FAIL) 
int __EMI_OutputTxWindow( void )
{
    int tx_X_delay_level;
    int tx_Y_delay_level;
    int rx_X_delay_level;
    int rx_Y_delay_level;

    dbg_print("\\n\\r");
    for( tx_Y_delay_level=0 ; tx_Y_delay_level <= 0xF ;  tx_Y_delay_level++ )
    {
        for( tx_X_delay_level=0 ; tx_X_delay_level <= 0xF ;  tx_X_delay_level++ )
        {
            dbg_print("%d ",dbg_tx_wnd[tx_X_delay_level][tx_Y_delay_level]);
        }
        dbg_print("\\n\\r");
    }
    dbg_print("\\n\\r");

    for(rx_X_delay_level = 0 ; rx_X_delay_level < 95 ; rx_X_delay_level++ ){
        dbg_print("%d ",dbg_rx_wnd[rx_X_delay_level]);
    }
    dbg_print("\\n\\r");
    if( dbg_is_evb_check_fail == 1 )
    {
        dbg_print("[ERROR]:EVB EMI Timing Check FAIL!\\n\\n");
    } else
    {
        dbg_print("EVB EMI Timing Check Pass!\\n\\n");
    }

    return 0;    
}
#endif

#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */




/*************************************************************************
* FUNCTION
*  __ARM_TimingWindow()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

#if defined(__DBG_EVB_CHECK_FAIL)
int __ARM_TimingWindow( void )
{
    unsigned int arm_delay_level;
    int i = 0;
    
    /**
      * 0x610d0640 definition.
      * bit 5      4  3  2  1   0
      *     -       --------    -
      * ARM/Fcore      sel    enable
      */
    
    for(i = 0; i < 10; i++)
    {
        // ROSC_CON, select ARM.
        *(volatile unsigned int*)0x610d0640 &= 0xFFFF0000;
        // Choose select from bit[1~4], ARM only has 9 lines available.
        *(volatile unsigned int*)0x610d0640 |= (i << 0x1);
        
        // Enable ring freqyebct meter.
        *(volatile unsigned int*)0x610d0640 &= 0xFFFFFFFE;  
        *(volatile unsigned int*)0x610d0640 |= 0x00000001;  
        
        // ABIST_FQMTR_CON1, select ARM/Fcore ring.
        *(volatile unsigned int*)0x61150F84 &= 0xFFFFFFF0;    
        *(volatile unsigned int*)0x61150F84 |= 0x0000000C;    
        
        // ABIST_FQMTR_CON0, reset counter with window size = 0x4.
        *(volatile unsigned int*)0x61150F80 &= 0xFFFF0000; 
        *(volatile unsigned int*)0x61150F80 |= 0x00004400; 
        
        // ABIST_FQMTR_CON0, encounter counter with window size = 0x4.
        *(volatile unsigned int*)0x61150F80 &= 0xFFFF0000;  
        *(volatile unsigned int*)0x61150F80 |= 0x00008400;
        
        // Wait until windown calculation complete.
        while(((*(volatile unsigned int*)0x61150F84) & 0x8000) != 0);
        
        // Read ABIST_FQMTR_DATA.
        arm_delay_level = *(volatile unsigned int*)0x61150f88;
        
        dbg_print("ABIST_FQMTR_DATA(%d) = %d\\n", i, arm_delay_level);
    }
    
    // recover ROSC_CON (Fixed by Ryan)
    *(volatile unsigned int*)0x610d0640 = 0;
    
    dbg_print("ARM timing window tuning complete\\n\\n");

    return 0;    
}
#endif

#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */



/*************************************************************************
* FUNCTION
*  evb_fail_detection()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

int evb_fail_detection( void )
{
  
#if defined(__DBG_EVB_CHECK_FAIL)
    __ARM_TimingWindow();
  
    __EMI_OutputTxWindow();
#endif

    return 0;
}

#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_CheckTxDelayLevel()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

#if defined(__DBG_EVB_CHECK_FAIL)
int __EMI_CheckTxDelayLevel( void )
{
    /**
        * Default 0 is PASS.
        */
    int result = 0; 
    int tx_X_delay_level;
    int tx_Y_delay_level;
    int rx_X_delay_level;
    int rx_Y_delay_level;
    unsigned long regbak_ODLA, regbak_ODLB, regbak_ODLC, regbak_ODLD; 
    unsigned long regbak_ODLE, regbak_ODLG;

    /**
        * Backup register.
        */
    regbak_ODLA = *EMI_ODLA;
    regbak_ODLB = *EMI_ODLB;
    regbak_ODLC = *EMI_ODLC;
    regbak_ODLD = *EMI_ODLD;
    regbak_ODLE = *EMI_ODLE;
    regbak_ODLG = *EMI_ODLG;
     
    /**
        * Check TX Delay Level.
        */
    for( tx_Y_delay_level=0 ; tx_Y_delay_level <= 0xF ;  tx_Y_delay_level++ )
    {        
        *EMI_ODLA = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);        
        *EMI_ODLB = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);        
        *EMI_ODLC = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);
        *EMI_ODLD = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);

        /**
           * Factor3 - DQM_OUT_DEL.
           * Clear DQM_OUT_DEL first
           */
        *EMI_ODLE &= ~0xFFFF0000; 
        *EMI_ODLE |= ((tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16));
        
        
        for( tx_X_delay_level=0 ; tx_X_delay_level <= 0xF ;  tx_X_delay_level++ )
        {
            /**
               * Factor4 - DQS_OUT_DEL.
               * Clear DQS_OUT_DEL first
               */
            *EMI_ODLE &= ~0x0000FFFF;
            *EMI_ODLE |= ((tx_X_delay_level <<12) | (tx_X_delay_level <<8) |(tx_X_delay_level <<4) |(tx_X_delay_level <<0));

            /**
               * Factor5 - EDCLK_OUT_DEL.
               */
            *EMI_ODLG &= ~0x0000000F;
            *EMI_ODLG |= tx_X_delay_level;

            if( __EMI_DataAutoTrackingMbistTest() != 0 )
            {
                if( tx_X_delay_level == 0x9 ) 
                {
                    /**
                        * Test fail.
                        */
                    result = 1; 
                }
                dbg_tx_wnd[tx_X_delay_level][tx_Y_delay_level] = 0;
            } else
            {
                dbg_tx_wnd[tx_X_delay_level][tx_Y_delay_level] = 1;
            }
        }
    }

    
     /**
        * Check RX Delay Level.
        */
   
    
    for( tx_Y_delay_level=0 ; tx_Y_delay_level <= 0x6 ;  tx_Y_delay_level++ )
    {        
        *EMI_ODLA = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);        
        *EMI_ODLB = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);        
        *EMI_ODLC = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);
        *EMI_ODLD = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);

        /**
           * Factor3 - DQM_OUT_DEL.
           * Clear DQM_OUT_DEL first
           */
        *EMI_ODLE &= ~0xFFFF0000; 
        *EMI_ODLE |= ((tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16));
        
        for( tx_X_delay_level=0x0 ; tx_X_delay_level <= 0x6 ;  tx_X_delay_level++ )
        {
            /**
               * Factor4 - DQS_OUT_DEL.
               * Clear DQS_OUT_DEL first
               */
            *EMI_ODLE &= ~0x0000FFFF;
            *EMI_ODLE |= ((tx_X_delay_level <<12) | (tx_X_delay_level <<8) |(tx_X_delay_level <<4) |(tx_X_delay_level <<0));

            /**
               * Factor5 - EDCLK_OUT_DEL.
               */
            *EMI_ODLG &= ~0x0000000F;
            *EMI_ODLG |= tx_X_delay_level;
            for(rx_X_delay_level = 0 ; rx_X_delay_level < 95 ; rx_X_delay_level++ ){
                 _RX_EMI_Tuning_Factor_Set(rx_X_delay_level);
            if( __EMI_DataAutoTrackingMbistTest() != 0 )
             {
                dbg_rx_wnd[rx_X_delay_level] = 0;
             }
             else
              {
                dbg_rx_wnd[rx_X_delay_level] = 1;
                      count_rw_y[rx_Y_delay_level] += 1; 
              }
                      
                     
                  }
          
          }    
    }
    
       
    /**
        * Restore register.
        */
    *EMI_ODLA = regbak_ODLA;
    *EMI_ODLB = regbak_ODLB;
    *EMI_ODLC = regbak_ODLC;
    *EMI_ODLD = regbak_ODLD;
    *EMI_ODLE = regbak_ODLE;
    *EMI_ODLG = regbak_ODLG;

    return result;        
}
#endif // __DBG_EVB_CHECK_FAIL

#endif /* MT6276 */
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */
/*************************************************************************
* FUNCTION
*  _RX_EMI_Tuning_Factor_Set()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(__DBG_EVB_CHECK_FAIL)
void _RX_EMI_Tuning_Factor_Set( unsigned int l_i4DqDelay_V )
{
    unsigned long regbak_IDLA, regbak_IDLB, regbak_IDLC, regbak_IDLD; 
    unsigned long regbak_IDLE, regbak_IDLF, regbak_IDLG, regbak_IDLH, regbak_IDLI;
    unsigned long regbak_CALE, regbak_CALF, regbak_CALG, regbak_CALH;
    /**
        * Backup register.
        */
    regbak_IDLA = *EMI_IDLA;
    regbak_IDLB = *EMI_IDLB;
    regbak_IDLC = *EMI_IDLC;
    regbak_IDLD = *EMI_IDLD;
    regbak_IDLE = *EMI_IDLE;
    regbak_IDLF = *EMI_IDLF;
    regbak_IDLG = *EMI_IDLG;
    regbak_IDLH = *EMI_IDLH;
    regbak_IDLI = *EMI_IDLI;
    regbak_CALE = *EMI_CALE;
    regbak_CALF = *EMI_CALF;
    regbak_CALG = *EMI_CALG;
    regbak_CALH = *EMI_CALH;
    //Factor4 -DQ_IN_DEL, BYTE_DATA_SETUP and BYTE_DATA_DLYSEL
    if (l_i4DqDelay_V <= __DQIDLY_BOUNDARY)
    {
        //Factor4 -DQ_IN_DEL            
        l_i4DqDelay_V = (__DQIDLY_BOUNDARY - l_i4DqDelay_V); //Tuning sequence = 0x1f ~ 0x0
        *EMI_IDLA = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
        *EMI_IDLB = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
        *EMI_IDLC = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
        *EMI_IDLD = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;        
    
        *EMI_IDLE = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
        *EMI_IDLF = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
        *EMI_IDLG = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
        *EMI_IDLH = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;        

        //Factor4 - BYTE_DATA_SETUP
        *EMI_CALE = 0; 
        *EMI_CALF = 0; 
        *EMI_CALG = 0;
        *EMI_CALH = 0;
    
        //Factor4 - BYTE_DATA_DLY      
        *EMI_IDLI = 0;
    
    }
    else if (l_i4DqDelay_V <= (__DQIDLY_BOUNDARY*2+1))
    {            
        //Factor4 - BYTE_DATA_SETUP
        l_i4DqDelay_V -= (__DQIDLY_BOUNDARY+1); //Tuning sequence = 0x0 ~ 0x1f            
        *EMI_CALE= (l_i4DqDelay_V <<24) | (l_i4DqDelay_V << 16 ) |(l_i4DqDelay_V <<8) | l_i4DqDelay_V; 
        *EMI_CALF= (l_i4DqDelay_V <<24) | (l_i4DqDelay_V << 16 ) |(l_i4DqDelay_V <<8) | l_i4DqDelay_V;        
        *EMI_CALG= (l_i4DqDelay_V <<24) | (l_i4DqDelay_V << 16 ) |(l_i4DqDelay_V <<8) | l_i4DqDelay_V; 
        *EMI_CALH= (l_i4DqDelay_V <<24) | (l_i4DqDelay_V << 16 ) |(l_i4DqDelay_V <<8) | l_i4DqDelay_V;        
    
    }
    else
    {
        //Factor4 - BYTE_DATA_DLY            
        l_i4DqDelay_V -= (__DQIDLY_BOUNDARY+1)*2; //Tuning sequence = 0x0 ~ 0x1f
        /* Mark Lin : please change to set DQSx_INDLY_SEL */
        *EMI_CALA = (l_i4DqDelay_V <<8) | l_i4DqDelay_V; 
        *EMI_CALB = (l_i4DqDelay_V <<8) | l_i4DqDelay_V; 
        *EMI_IDLI = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V << 16 ) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
    }
    
    /**
        * Restore register.
        */
    *EMI_IDLA = regbak_IDLA;
    *EMI_IDLB = regbak_IDLB;
    *EMI_IDLC = regbak_IDLC;
    *EMI_IDLD = regbak_IDLD;
    *EMI_IDLE = regbak_IDLE;
    *EMI_IDLF = regbak_IDLF;
    *EMI_IDLG = regbak_IDLG;
    *EMI_IDLH = regbak_IDLH;
    *EMI_IDLI = regbak_IDLI;
    *EMI_CALE = regbak_CALE;
    *EMI_CALF = regbak_CALF;
    *EMI_CALG = regbak_CALG;
    *EMI_CALH = regbak_CALH;

}
#endif // __DBG_EVB_CHECK_FAIL

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_RecordRegInitStatus()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

#if defined(__DBG_EVB_CHECK_FAIL)
void __EMI_RecordRegInitStatus( void )
{
    __EMI_DataAutoTrackingRegRead( &debug_emi_initial_reg );
}
#endif

#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_RecordRegCrashStatus()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276)

#if defined(__DBG_EVB_CHECK_FAIL)
void __EMI_RecordRegCrashStatus( void )
{
    __EMI_DataAutoTrackingRegRead( &debug_emi_crash_reg );
}
#endif

#endif /* MT6276 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */



/*************************************************************************
* FUNCTION
*  __EMI_HwDcmInitialization()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(MT6276_S00)

void __EMI_HwDcmInitialization(void)
{
    register kal_uint32 delay;

    /**
        * Disable Dummy Read. 
        */
    *EMI_DRCT &= ~0x1;       

    /**
        * Block all emi transaction. 
        */
    *EMI_CONM =     0x003F;    

    /**
       * Disable DQSI_DCM_AUTO_TUNE_EN (DQSI auto tune after SR mode).
       */
    *EMI_DQSE &= ~(1<<28);

    /**
        * Enter SDRAM self refresh mode and polling status. 
        */
    *EMI_CONN |=    (1<<5);     
    while( ( *EMI_CONN & (1<<7) ) == 0 );

    /**
        * Wait for EMI idle bit assert (since we use SR mode to block the access). 
        */
    while( ( *EMI_CONN & (1<<10) ) == 0 );

    /**
        * Disable DQS strobe auto tracking. 
        */
    *EMI_DQSE &= 0x7FFF0000;    
    
    /**
        * Set as BW limiter counting the same as normal frequence. 
        */
    *EMI_ABCT &= ~(1<<6);

    /**
       * Set TRFC_HW_DCM = 1 to make sure TRFC is enough.
       */  
    *EMI_CONJ |= (1<<22);

    /**
       * Change Dummy read setting (5.26us) for software workaround HW DCM fail to auto-refresh issue. 
       */
    *EMI_DRCT &= ~0x8000F000;
    *EMI_DRCT |= 0x1000;

    /**
        * Unmask EMI access for all master. 
        */
    *EMI_CONM = 0x0000;
    
    /**
       * If Set, BUS will hang when access EMI
       */
    //*EMI_DQSE |= (1<<28); 

    /**
       * Exit SDRAM self refresh mode and polling status. 
       */
    *EMI_CONN &= ~(1<<5);     
    while( ( *EMI_CONN & (1<<7) ) == 1 );

    /**
        * Enable DQS strobe auto tracking. 
        */
    *EMI_DQSE |= 0xFFFF;    

    /**
        * Enable dummy Read. 
        */
    *EMI_DRCT |=    0x1;         

    for( delay = 0; delay <= 0xFFFF; delay++ );
}        

#endif /* MT6276_S00 */

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */
__TEMPLATE
    }
    
    ###
    my $emi_setRegValfromMCP_template;
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
    {
        $emi_setRegValfromMCP_template .= <<"__TEMPLATE";
   MTK_EMI_Info *mem_info;

   mem_info = (MTK_EMI_Info *)&EMI_INFO_2.mem_info[CMCP_Index];

#if defined(MT6235) || defined(MT6235B)

   EMI_GENERAL_A_VAL = mem_info->EMI_GENA_value;
   EMI_GENERAL_B_VAL = mem_info->EMI_GENB_value;
   EMI_GENERAL_C_VAL = mem_info->EMI_GENC_value;
   EMI_GENERAL_D_VAL = mem_info->EMI_GEND_value;
   
   EMI_CONTROL_I_VAL = mem_info->EMI_CONI_value;
   EMI_CONTROL_J_VAL = mem_info->EMI_CONJ_value;
   EMI_CONTROL_K_VAL = mem_info->EMI_CONK_value;
   EMI_CONTROL_L_VAL = mem_info->EMI_CONL_value;
   EMI_CONTROL_M_VAL = mem_info->EMI_CONM_value;
   EMI_CONTROL_N_VAL = mem_info->EMI_CONN_value;
   
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) /* MT6235 || MT6235B */

   EMI_GENERAL_A_VAL = mem_info->EMI_GENA_value;
   EMI_GENERAL_B_VAL = mem_info->EMI_GENB_value;
   EMI_GENERAL_C_VAL = mem_info->EMI_GENC_value;
   EMI_GENERAL_D_VAL = mem_info->EMI_GEND_value;
   
   EMI_CONTROL_I_VAL = mem_info->EMI_CONI_value;
   EMI_CONTROL_J_VAL = mem_info->EMI_CONJ_value;
   EMI_CONTROL_K_VAL = mem_info->EMI_CONK_value;
   EMI_CONTROL_L_VAL = mem_info->EMI_CONL_value;
   EMI_CONTROL_M_VAL = mem_info->EMI_CONM_value;
   EMI_CONTROL_N_VAL = mem_info->EMI_CONN_value;

   EMI_DELAY_A_VAL = mem_info->EMI_DELA_value;
   EMI_DELAY_B_VAL = mem_info->EMI_DELB_value;
   EMI_DELAY_C_VAL = mem_info->EMI_DELC_value;
   EMI_DELAY_D_VAL = mem_info->EMI_DELD_value;
   EMI_DELAY_E_VAL = mem_info->EMI_DELE_value;
   EMI_DELAY_F_VAL = mem_info->EMI_DELF_value;
   EMI_DELAY_G_VAL = mem_info->EMI_DELG_value;
   EMI_DELAY_H_VAL = mem_info->EMI_DELH_value;
   EMI_DELAY_I_VAL = mem_info->EMI_DELI_value;
   EMI_DELAY_J_VAL = mem_info->EMI_DELJ_value; 

   EMI_ARB_A_VAL = mem_info->EMI_ARBA_value;
   EMI_ARB_B_VAL = mem_info->EMI_ARBB_value;
   EMI_ARB_C_VAL = mem_info->EMI_ARBC_value;
   EMI_ARB_D_VAL = mem_info->EMI_ARBD_value;
   EMI_ARB_E_VAL = mem_info->EMI_ARBE_value;
   EMI_ARB_F_VAL = mem_info->EMI_ARBF_value;
   EMI_ARB_G_VAL = mem_info->EMI_ARBG_value;
   EMI_ARB_H_VAL = mem_info->EMI_ARBH_value;
   EMI_ARB_I_VAL = mem_info->EMI_ARBI_value;

#elif defined(MT6276) /* MT6235 || MT6235B */

   EMI_DRV_A_VAL = mem_info->EMI_DRVA_value;
   EMI_DRV_B_VAL = mem_info->EMI_DRVB_value;

   EMI_ODL_A_VAL = mem_info->EMI_ODLA_value;
   EMI_ODL_B_VAL = mem_info->EMI_ODLB_value;
   EMI_ODL_C_VAL = mem_info->EMI_ODLC_value;
   EMI_ODL_D_VAL = mem_info->EMI_ODLD_value;
   EMI_ODL_E_VAL = mem_info->EMI_ODLE_value;
   EMI_ODL_F_VAL = mem_info->EMI_ODLF_value;
   EMI_ODL_G_VAL = mem_info->EMI_ODLG_value;

   EMI_CONTROL_I_VAL = mem_info->EMI_CONI_value;
   EMI_CONTROL_J_VAL = mem_info->EMI_CONJ_value;
   EMI_CONTROL_K_VAL = mem_info->EMI_CONK_value;
   EMI_CONTROL_L_VAL = mem_info->EMI_CONL_value;
   EMI_CONTROL_N_VAL = mem_info->EMI_CONN_value;

   EMI_IODUTY_A_VAL = mem_info->EMI_DUTA_value;
   EMI_IODUTY_B_VAL = mem_info->EMI_DUTB_value;
   EMI_IODUTY_C_VAL = mem_info->EMI_DUTC_value;

   EMI_RXDUTY_A_VAL = mem_info->EMI_DUCA_value;
   EMI_RXDUTY_B_VAL = mem_info->EMI_DUCB_value;
   EMI_RXDUTY_E_VAL = mem_info->EMI_DUCE_value;
   
   EMI_IOMISC_L_VAL = mem_info->EMI_IOCL_value;
   
#endif /* MT6235 || MT6235B */

   return;
__TEMPLATE
    }
    else
    {
        $emi_setRegValfromMCP_template .= <<"__TEMPLATE";
   kal_uint32 i;

   MTK_MEM_Info *mem_info;
   mem_info = (MTK_MEM_Info *)&CUST_MEM_INFO.mem_info[CMCP_Index];

#if defined(MT6236) || defined(MT6236B)

   EMI_GENERAL_A_VAL = mem_info->EMI_GENA_value;
   EMI_GENERAL_B_VAL = mem_info->EMI_GENB_value;
   EMI_GENERAL_C_VAL = mem_info->EMI_GENC_value;
   EMI_GENERAL_D_VAL = mem_info->EMI_GEND_value;

   EMI_DELAY_J_VAL = mem_info->EMI_DELAY_J_value;

   EMI_CONA_ASYNC = mem_info->EMI_CONA_ASYNC_value;
   EMI_CONB_ASYNC = mem_info->EMI_CONB_ASYNC_value;

   EMI_CONA_BURST = mem_info->EMI_CONA_BURST_value;
   EMI_CONE_BURST = mem_info->EMI_CONE_BURST_value;
   
   EMI_CONB_BURST = mem_info->EMI_CONB_BURST_value;
   EMI_CONF_BURST = mem_info->EMI_CONF_BURST_value;

   EMI_RDCT_VAL = mem_info->EMI_RDCT_value;

   // Always BURST
   Sel_NOR_CMD_num = mem_info->EMI_NOR_CMD_num;
   
   for (i=0; i<Sel_NOR_CMD_num; i++) {
      EMI_NOR_BURST_OP[i] = mem_info->EMI_NOR_CMD_OP[i];
      EMI_NOR_BURST_ADDRESS[i] = mem_info->EMI_NOR_CMD_ADDR[i];
      EMI_NOR_BURST_DATA[i] = mem_info->EMI_NOR_CMD_DATA[i];
   }
   
   Sel_PSRAM_CMD_num = mem_info->EMI_PSRAM_CMD_num;
   
   for (i=0; i<Sel_PSRAM_CMD_num; i++) {
      EMI_PSRAM_BURST_OP[i] = mem_info->EMI_PSRAM_CMD_OP[i];
      EMI_PSRAM_BURST_ADDRESS[i] = mem_info->EMI_PSRAM_CMD_ADDR[i];
      EMI_PSRAM_BURST_DATA[i] = mem_info->EMI_PSRAM_CMD_DATA[i];
   }

#elif defined(MT6253)
   EMI_CONA_ASYNC = mem_info->EMI_CONA_ASYNC_value;
   EMI_CONB_ASYNC = mem_info->EMI_CONB_ASYNC_value;
   EMI_CONC_ASYNC = mem_info->EMI_CONC_ASYNC_value;
   EMI_COND_ASYNC = mem_info->EMI_COND_ASYNC_value;   
   EMI_GENERAL_CONTROL = mem_info->EMI_GEN_ASYNC_value;

   EMI_CONA_BURST = mem_info->EMI_CONA_SYNC_value;
   EMI_CONB_BURST = mem_info->EMI_CONB_SYNC_value;
   EMI_CONC_BURST = mem_info->EMI_CONC_SYNC_value;
   EMI_COND_BURST = mem_info->EMI_COND_SYNC_value;   
   EMI_GENERAL_CONTROL_BURST = mem_info->EMI_GEN_SYNC_value;   

   // Always BURST
   Sel_NOR_CMD_num = mem_info->EMI_NOR_CMD_num;
   
   for (i=0; i<Sel_NOR_CMD_num; i++) {
      EMI_NOR_BURST_OP[i] = mem_info->EMI_NOR_CMD_OP[i];
      EMI_NOR_BURST_ADDRESS[i] = mem_info->EMI_NOR_CMD_ADDR[i];
      EMI_NOR_BURST_DATA[i] = mem_info->EMI_NOR_CMD_DATA[i];
   }
   
   Sel_PSRAM_CMD_num = mem_info->EMI_PSRAM_CMD_num;
   
   for (i=0; i<Sel_PSRAM_CMD_num; i++) {
      EMI_PSRAM_BURST_OP[i] = mem_info->EMI_PSRAM_CMD_OP[i];
      EMI_PSRAM_BURST_ADDRESS[i] = mem_info->EMI_PSRAM_CMD_ADDR[i];
      EMI_PSRAM_BURST_DATA[i] = mem_info->EMI_PSRAM_CMD_DATA[i];
   }

#elif defined(MT6252) || defined(MT6252H)

   EMI_CONA_ASYNC = mem_info->EMI_CONA_ASYNC_value;
   EMI_CONB_ASYNC = mem_info->EMI_CONB_ASYNC_value;
   EMI_CONC_ASYNC = mem_info->EMI_CONC_ASYNC_value;   
   EMI_GENERAL_CONTROL_ASYNC = mem_info->EMI_GEN_ASYNC_value;

   EMI_EXTCON_ASYNC = mem_info->EMI_EXTCON_ASYNC_value;
   
   EMI_DRIVING_CONTROL_A = mem_info->EMI_IOA_value;
   EMI_DRIVING_CONTROL_B = mem_info->EMI_IOB_value;
   EMI_DRIVING_CONTROL_C = mem_info->EMI_IOC_value;

#if defined(__EMI_DEVICE_MODE_BURST__)
   EMI_CONA_BURST = mem_info->EMI_CONA_SYNC_value;
   EMI_CONB_BURST = mem_info->EMI_CONB_SYNC_value;
   EMI_CONC_BURST = mem_info->EMI_CONC_SYNC_value;   
   EMI_GENERAL_CONTROL_BURST = mem_info->EMI_GEN_SYNC_value;

   EMI_EXTCON_BURST = mem_info->EMI_EXTCON_BURST_value;
   EMI_EXTCON2_BURST = mem_info->EMI_EXTCON2_BURST_value;

   EMI_DRIVING_CONTROL_A_BURST = mem_info->EMI_IOA_BURST_value;
   EMI_DRIVING_CONTROL_B_BURST = mem_info->EMI_IOB_BURST_value;

#if !defined(MT6252)
   Sel_NOR_CMD_num = mem_info->EMI_NOR_CMD_num;

   for (i=0; i<Sel_NOR_CMD_num; i++) {
      EMI_NOR_BURST_OP[i] = mem_info->EMI_NOR_CMD_OP[i];
      EMI_NOR_BURST_ADDRESS[i] = mem_info->EMI_NOR_CMD_ADDR[i];
      EMI_NOR_BURST_DATA[i] = mem_info->EMI_NOR_CMD_DATA[i];
   }
#endif

   Sel_PSRAM_CMD_num = mem_info->EMI_PSRAM_CMD_num;
   
   for (i=0; i<Sel_PSRAM_CMD_num; i++) {
      EMI_PSRAM_BURST_OP[i] = mem_info->EMI_PSRAM_CMD_OP[i];
      EMI_PSRAM_BURST_ADDRESS[i] = mem_info->EMI_PSRAM_CMD_ADDR[i];
      EMI_PSRAM_BURST_DATA[i] = mem_info->EMI_PSRAM_CMD_DATA[i];
   }
#endif /* __EMI_DEVICE_MODE_BURST__ */

#if defined(__EMI_DEVICE_MODE_PAGE__)

   EMI_CONA_PAGE = mem_info->EMI_CONA_PAGE_value;
   EMI_CONB_PAGE = mem_info->EMI_CONB_PAGE_value;
   EMI_CONC_PAGE = mem_info->EMI_CONC_PAGE_value;
   
   Sel_NOR_CMD_num = mem_info->EMI_NOR_CMD_num;

   for (i=0; i<Sel_NOR_CMD_num; i++) {
      EMI_NOR_PAGE_OP[i] = mem_info->EMI_NOR_CMD_OP[i];
      EMI_NOR_PAGE_ADDRESS[i] = mem_info->EMI_NOR_CMD_ADDR[i];
      EMI_NOR_PAGE_DATA[i] = mem_info->EMI_NOR_CMD_DATA[i];
   }
   
   Sel_PSRAM_CMD_num = mem_info->EMI_PSRAM_CMD_num;
   
   for (i=0; i<Sel_PSRAM_CMD_num; i++) {
      EMI_PSRAM_PAGE_OP[i] = mem_info->EMI_PSRAM_CMD_OP[i];
      EMI_PSRAM_PAGE_ADDRESS[i] = mem_info->EMI_PSRAM_CMD_ADDR[i];
      EMI_PSRAM_PAGE_DATA[i] = mem_info->EMI_PSRAM_CMD_DATA[i];
   }
   
#endif /* __EMI_DEVICE_MODE_PAGE__ */

#endif /* MT6236 || MT6236B */

   return;
__TEMPLATE
    }

    ###
    my $remap_addr;
    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
    {
    	$remap_addr = <<"__TEMPLATE";
/**
  * Define NOR/RAM's starting address.
  */
#if !defined(MT6253) && !defined(MT6252H) && !defined(MT6252)
#ifdef REMAPPING
#define FLASH_BASE_ADDR $cs1_base_address
#define RAM_BASE_ADDR   0x00000000
#else
#define FLASH_BASE_ADDR 0x00000000
#define RAM_BASE_ADDR   $cs1_base_address
#endif
#endif /* !MT6253 && !MT6252H && !MT6252 */
__TEMPLATE
    }

    ###
    my $custom_EMI_c_optional_part1;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) != 1)
    {
        $custom_EMI_c_optional_part1 = <<"__TEMPLATE";
/** 
  *     CMEM_EMIINIT_Index() is defined in "combo_flash_init.h"
  *     it should be included at autoGen for Combo Memory !!
  *
  */
#include "combo_flash_init.h"

#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6276)
#include "cp15.h"
#endif /* MT6268 || MT6236 || MT6236B || MT6276 */

#ifdef __SV5_ENABLED__
#include "br_GFH_emi_list.h"
#include "br_GFH.h"
#endif /* __SV5_ENABLED__ */

$remap_addr

/*************************************
  *
  * Imported APIs.
  *
  *************************************/

/**
  * We will use this function to retrieve the current NOR base address with corresponding L2 cache-bypass bit set so that 
  * we could issue switch command to NOR safely.
  */
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);

#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6276)
/**
   * For auto tracking calibration 
   */
extern kal_int32 store_8word(kal_uint32,kal_uint32);
extern kal_int32 load_8word(kal_uint32,kal_uint32);
#endif /* MT6268 || MT6236 || MT6236B || MT6276 */

extern kal_int32 CMEM_EMIINIT_Index(void);
extern kal_int32 CMEM_Index(void);

#if defined(MT6276)
extern SW_SECVERSION INT_SW_SecVersion(void);
#endif /* MT6276 */

/*************************************
  *
  * Global Variables.
  *
  *************************************/

#if defined(MT6253)
/**
  * This pattern is used to perform EMI feedback clock calibration for NOR and PSRAM individually.
  */
static const volatile unsigned int nor_compare_pattern = EMI_COMPARE_PATTERN;
volatile unsigned int psram_compare_pattern = EMI_COMPARE_PATTERN;
#endif /* MT6253 */

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */

#if defined(MT6236) || defined(MT6236B)
ECO_VERSION init_eco_version;
#endif

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
#endif /* __MTK_TARGET__ */

$EMI_Info
$MEM_Info

#if defined(MT6276)

__align(64*1024) unsigned long EMI_DUMMY_READ_AREA[8] =
{
    0x12345678, 0x87654321, 0x5A5A5A5A, 0xFACEBEAF,
    0x0F0F0F0F, 0xDEADBEAF, 0x25487650, 0x26792679
};


#ifdef __MTK_TARGET__
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

#if defined(__DBG_EVB_CHECK_FAIL)
/**
  * For detecting EVB timing shift's pattern..
  */
int dbg_is_evb_check_fail = 1;
int dbg_tx_wnd[0x10][0x10] = { 1 , 2 , 3 };
int dbg_rx_wnd[95] = { 1 , 2 , 3 };
int count_rw_y[15] = { 1 , 2 , 3 };

int __EMI_CheckTxDelayLevel( void );
void __EMI_RecordRegInitStatus( void );
void __EMI_RecordRegCrashStatus( void );
int __EMI_OutputTxWindow( void );
void _RX_EMI_Tuning_Factor_Set( unsigned int l_i4DqDelay_V );

EMI_DATA_TRAIN_REG_t debug_emi_initial_reg = {1, 2, 3};
EMI_DATA_TRAIN_REG_t debug_emi_crash_reg = {1, 2, 3};
#endif

#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
EMI_DATA_TRAIN_ERR_INFO_t emi_data_training_err_info = {1, 2, 3};
#endif 

#ifdef __MTK_TARGET__
#pragma arm section rwdata , rodata , zidata
#endif /* __MTK_TARGET__ */


#if defined(MT6276_S00)
/**
  * For HW DCM EMI fail to auto-refresh's HW workaround.
  */
void __EMI_HwDcmInitialization(void);
#endif

kal_int8 __EMI_InitializationFlow(void);
int __EMI_EnableDataAutoTracking( EMI_DATA_TRAIN_REG_t* DATA_TRAIN_RESULT_REG);
int __EMI_EnablePerformancePowerControl( void );
int __EMI_EnableBandwidthLimiter( void );

#endif /* MT6276 */

$emi_reg_param_decl

/* The following information will be used in custom_DynamicClockSwitch() for Combo Memory */
#if defined(__EMI_COMBO_EN)

kal_uint32 __EMI_DCM_idx = __EMI_DCM_COMBO_INDEX_UND;

/** 
   *  EMI_CONTROL_J_VAL_MCP0 and EMI_CONTROL_L_VAL_MCP0 is defined here AGAIN,
   *  however the following data structure is placed at INTSRAM, but not EMIINIT,
   *  and will be used in Dynamic Clock Switch
   */

#if defined(MT6235) || defined(MT6235B) ||  defined(MT6236) || defined(MT6236B) || defined(MT6268)

MTK_EMI_DCM_Ctrl __EMI_DCM_control[__EMI_COMBO_ENTRY_COUNT] = 
{
#if defined(MT6235) || defined(MT6235B)
#if defined(_NAND_FLASH_BOOTING_)
$combo_mem_dcm_ctrl_struct_35
#else
#endif 
#elif defined(MT6236) || defined(MT6236B)
#if defined(_NAND_FLASH_BOOTING_)
$combo_mem_dcm_ctrl_struct_36
#else
$combo_mem_nor_psram_dcm_ctrl_struct_36
#endif
#elif defined(MT6268)
$combo_mem_dcm_ctrl_struct_68
#endif
};
#endif /* MT6236 || MT6236B || MT6268 */

#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#if defined(MT6235) || defined(MT6235B)
#if defined(_NAND_FLASH_BOOTING_)
kal_uint32 EMI_CONTROL_J_104_VAL;
kal_uint32 EMI_CONTROL_K_104_VAL;
kal_uint32 EMI_CONTROL_L_104_VAL;
kal_uint32 EMI_CONTROL_M_104_VAL;
kal_uint32 EMI_GENERAL_A_104_VAL;
kal_uint32 EMI_GENERAL_B_104_VAL;
kal_uint32 EMI_GENERAL_C_104_VAL;
kal_uint32 EMI_CONTROL_J_13_VAL;
kal_uint32 EMI_CONTROL_K_13_VAL;
kal_uint32 EMI_CONTROL_L_13_VAL;
kal_uint32 EMI_CONTROL_M_13_VAL;
kal_uint32 EMI_GENERAL_A_13_VAL;
kal_uint32 EMI_GENERAL_B_13_VAL;
kal_uint32 EMI_GENERAL_C_13_VAL;
#else
#endif
#elif defined(MT6236) || defined(MT6236B) /* MT6235 || MT6235B */
#if defined(_NAND_FLASH_BOOTING_)
kal_uint32 EMI_CONTROL_J_104_VAL;
kal_uint32 EMI_CONTROL_L_104_VAL;
kal_uint32 EMI_CONTROL_J_13_VAL;
kal_uint32 EMI_CONTROL_L_13_VAL;
#else
kal_uint32 EMI_CONA_BURST_104MHZ;
kal_uint32 EMI_CONB_BURST_104MHZ;
kal_uint32 EMI_CONE_BURST_104MHZ;
kal_uint32 EMI_CONF_BURST_104MHZ;
kal_uint32 EMI_CONA_BURST_13MHZ;
kal_uint32 EMI_CONB_BURST_13MHZ;
kal_uint32 EMI_CONE_BURST_13MHZ;
kal_uint32 EMI_CONF_BURST_13MHZ;
#endif
#elif defined(MT6268) /* MT6235 || MT6235B */
kal_uint32 EMI_CONTROL_J_122_88_VAL;
kal_uint32 EMI_CONTROL_L_122_88_VAL;
kal_uint32 EMI_CONTROL_J_15_36_VAL;
kal_uint32 EMI_CONTROL_L_15_36_VAL;
#endif
#pragma arm section rwdata , rodata , zidata

#endif /* __EMI_COMBO_EN */

$custom_EMI_optional_func_by_device_type

/*************************************************************************
* FUNCTION
*  __EMI_SetRegValfromCMCP()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if defined(__EMI_COMBO_EN)

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

void __EMI_SetRegValfromCMCP(void)
{
$emi_setRegValfromMCP_template
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */

#endif /* __EMI_COMBO_EN */

__TEMPLATE
    }
    
    ###
    my $custom_EMI_c_optional_part2;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) != 1)
    {
        $custom_EMI_c_optional_part2 = <<"__TEMPLATE";
/*************************************************************************
* FUNCTION
*  custom_EMI_QueryFullSpeedClock()
*
* DESCRIPTION
*   This routine query EMI's full-speed clock rate (instead of the clock rate at query time).
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

$emi_necessary_driver_ifdef

emi_clock_enum custom_EMI_QueryFullSpeedClock( void )
{
    /**
       * This function is only available after EMI is fully initialized, and we must not call this function at EMI init time since the code has not been initialized yet.
       */
    emi_clock_enum cur_emi_clk_rate = EMI_CLK_UNKNOWN;

#if defined(MT6253) || defined(MT6252H) || defined(MT6252)

#if defined(__EMI_CLK_52MHZ__)
    cur_emi_clk_rate = EMI_CLK_52MHZ;
#elif defined(__EMI_CLK_104MHZ__) /* __EMI_CLK_52MHZ__ */
    cur_emi_clk_rate = EMI_CLK_104MHZ;
#endif /* __EMI_CLK_52MHZ__ */

#elif defined(MT6268) /* MT6253 || MT6252H || MT6252 */
 
    cur_emi_clk_rate = EMI_CLK_122_88MHZ;

#elif defined(MT6276) /* MT6253 || MT6252H || MT6252 */

#if defined(__EMI_CLK_166MHZ__)
    cur_emi_clk_rate = EMI_CLK_166MHZ;
#elif defined(__EMI_CLK_200MHZ__) /* __EMI_CLK_166MHZ__ */
    cur_emi_clk_rate = EMI_CLK_200MHZ;
#endif /* __EMI_CLK_166MHZ__ */

#endif /* MT6253 || MT6252H || MT6252 */

    return cur_emi_clk_rate;
}

$emi_necessary_driver_endif
__TEMPLATE
    }
    
    ###
    my $custom_EMI_c_optional_part3;
    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') or ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H'))
    {
        $custom_EMI_c_optional_part3 = <<"__TEMPLATE";
/*************************************************************************
* FUNCTION
*  custom_ShareIOControl()
*
* DESCRIPTION
*  Control the share IO with EMI
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: success to configure IO setting
*  KAL_FALSE: Fail to configure IO setting
*
* GLOBALS AFFECTED
*
*************************************************************************/
$emi_necessary_driver_ifdef
#pragma arm section code = "INTSRAM_ROCODE"
kal_bool custom_ShareIOControl(const EMIShareIOSetting* pIOSetting )
{
#if defined(MT6252H) || defined(MT6252)

#if defined(__EMI_DEVICE_MODE_BURST__)

   kal_uint32 val, drv;

   val = *EMI_IOC & 0xFFFFFFC0;
    
   drv = pIOSetting->EMI_Drv;
    
   if(pIOSetting->EMI_PullDnCtrl)
      val |= (1<<5);
   else
      val &= ~(1<<5);
    
   if(pIOSetting->EMI_PullUpCtrl)
      val |= (1<<4);
   else
      val &= ~(1<<4);

   if(pIOSetting->EMI_SlewCtrl)
      val |= (1<<3);
   else
      val &= ~(1<<3);

   if( drv >= EMI_DRV_8MA )
   {
      val |= (1<<2);
      drv = drv - EMI_DRV_8MA;
   }
   if( drv >= EMI_DRV_4MA )
   {
      val |= (1<<1);
      drv = drv - EMI_DRV_4MA;
   }
   if( drv >= EMI_DRV_2MA )
   {
      val |= (1<<0);
   }

   *EMI_IOC = val;

   return KAL_TRUE;

#endif /*__EMI_DEVICE_MODE_BURST__*/

#if defined(__EMI_DEVICE_MODE_PAGE__)
   return KAL_FALSE;
#endif /*__EMI_DEVICE_MODE_PAGE__*/

#else  /* MT6252H | MT6252 */
   return KAL_FALSE;
#endif /* MT6252H | MT6252 */

}
#pragma arm section code
$emi_necessary_driver_endif
__TEMPLATE
    }
    
    ###
    my $dcm_variable_declaration;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) != 1)
    {
        $dcm_variable_declaration = <<"__TEMPLATE";

#if defined(FEATURE_DCM_SSC)
#pragma arm section zidata="INTSRAM_ZI", rwdata="INTSRAM_RW"
#if defined( DCM_ENABLE )
static unsigned int SSC_DCM_Handle = 0xFFFFFFFF;
#endif /* DCM_ENABLE */
#pragma arm section zidata, rwdata
#endif /* FEATURE_DCM_SSC */

#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
static kal_uint32 saved_emi_a = 0, saved_emi_b = 0;
static kal_uint32 emi_dqsa_13mhz = 0, emi_dqsa_312mhz = 0;
static kal_uint32 emi_dqsb_13mhz = 0, emi_dqsb_312mhz = 0;
static kal_uint32 dcm_status = 0;
static ECO_VERSION eco_version;
#if defined(MT6268)
static kal_uint32 emi_dqsa_122_88mhz = 0;
#endif
#pragma arm section rwdata , rodata , zidata
__TEMPLATE
    }

    ###
     my $HSUPA_76;
   if($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6276')
   {
       if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR')
      {
         if($COMM_MDL_INFO_LOCAL->{0}->{'DQ Bus width'} eq '32')
         {
             $HSUPA_76 = <<"__TEMPLATE";
int query_memorydevice_32(void)
{
   return 1;
}
__TEMPLATE
         }
         else
         {
            $HSUPA_76 = <<"__TEMPLATE";
int query_memorydevice_32(void)
{
   return 0;
}
__TEMPLATE
         }
             
        
           	
      } 	
   }
    ###
    my $template = <<"__TEMPLATE";
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "reg_base.h"
#include "emi_hw.h"
#include "init.h"
#include "pll.h"
#include "MemoryDevice_TypeDef.h"
#include "custom_emi.h"
#include "config_hw.h"
#include "cache_hw_int.h"

#include "custom_EMI_release.h"

#if defined(MT6276)
#include "dcm.h"
#endif

$custom_EMI_c_optional_part1

$custom_setEMI_6252

/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

kal_int8 custom_setEMI(void)
{
$custom_setEMI
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_InitDRAM()
*
* DESCRIPTION
*   This routine aims to set EMI and initialize LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

/**
  * On SRAM configuration, the custom_InitDRAM() will not be used.
  */
#if (defined(MT6235) || defined(MT6235B))
#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE"
#endif /* __MTK_TARGET__ */
#endif /* MT6235 || MT6235B */

kal_int8 custom_InitDRAM(void)
{
$custom_initDRAM
}

#if (defined(MT6235) || defined(MT6235B))
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif /* MT6235 || MT6235B */

/*************************************************************************
* FUNCTION
*  custom_ifLPSDRAM()
*
* DESCRIPTION
*  Query if the memory device is LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: The memory device is LPSDRAM
*  KAL_FALSE: The memory device is not LPSDRAM
*
* GLOBALS AFFECTED
*
*************************************************************************/

//#if (( !defined(__UBL__) && !defined(__FUE__) ) || defined(__EMMC_BOOTING__))
  /* __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
   * add this compile option to avoid compiling functions other than custom_setEMI()
   * The Bootloader will perform Sync/Page EMI initialization at the new EMI init flow, so we must be careful about 
   * the wrapping option so that Bootloader could reference this function.
   */

kal_bool
custom_ifLPSDRAM(void)
{
#if defined(DRAM_CS)
   return KAL_TRUE;
#else /* DRAM_CS */
   return KAL_FALSE;
#endif /* DRAM_CS */
}

//#endif //#if (( !defined(__UBL__) && !defined(__FUE__) ) || defined(__EMMC_BOOTING__))

$custom_setAdvEMI_6252

/*************************************************************************
* FUNCTION
*  custom_setAdvEMI()
*
* DESCRIPTION
*   This routine aims to set additional EMI
*   This is special for device which needs to set device configuration
*   register to turn-on special mode.
*
* PARAMETERS
*
* RETURNS
*  1:
*
* GLOBALS AFFECTED
*
*************************************************************************/

$custom_setAdvEMI_header

kal_int8 custom_setAdvEMI(void)
{
   kal_int8    status = 0;

#if defined(__EMI_COMBO_EN)
   kal_int8    i;
#endif

$custom_setAdvEMI
   return status;
}

$custom_setAdvEMI_tail

$custom_EMI_c_optional_part2

$HSUPA_76

$emi_c_head

/*************************************************************************
* FUNCTION
*  custom_get_EXTSRAM_size()
*
* DESCRIPTION
*  Return predefined external SRAM size.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

$emi_necessary_driver_ifdef

void
custom_get_EXTSRAM_size(kal_uint32 *size)
{
   *size = (kal_uint32)EMI_EXTSRAM_SIZE;
}

$emi_necessary_driver_endif

$custom_EMI_c_optional_part3

/*************************************************************************
* FUNCTION
*  custom_DynamicClockSwitch
*
* DESCRIPTION
*  This function dedicates to switch the system clock and adjust the EMI
*  according to the working system clock.
*
* PARAMETERS
*  clock    -    clock to switch
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
/** 
  *     For MT6236, custom_EMIDynamicClockSwitch_Init() function body must always exist no matter whether DCM_ENABLE is defined or not. 
  *     For BT sw workaround solution. (Slow down clock when drv initial)
  *
  */
$emi_necessary_driver_ifdef

#if defined(DCM_ENABLE) || defined(FEATURE_DCM_SSC) || defined(MT6236) || defined(MT6236B)

$dcm_variable_declaration

#pragma arm section code = "INTSRAM_ROCODE"

int custom_DynamicClockSwitch(mcu_clock_enum clock)
{
$custom_DynamicClockSwitch 
}

#pragma arm section code

#endif  /* DCM_ENABLE || FEATURE_DCM_SSC ||MT6236 || MT6236B  */

$emi_necessary_driver_endif

/*************************************************************************
* FUNCTION
*  custom_EMIDynamicClockSwitch_Init
*
* DESCRIPTION
*  This function is used to Init setting for DCM
*
* PARAMETERS
*
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
/** 
  *     For MT6236, custom_EMIDynamicClockSwitch_Init() function body must always exist no matter whether DCM_ENABLE is defined or not. 
  *     For BT sw workaround solution. (Slow down clock when drv initial)
  *
  */
$emi_necessary_driver_ifdef

int custom_EMIDynamicClockSwitch_Init(void)
{
#if !defined(MT6251)

#if defined(DCM_ENABLE) || defined(FEATURE_DCM_SSC) || defined(MT6236) || defined(MT6236B)

#if defined(__EMI_COMBO_EN)
   if (__EMI_DCM_idx == __EMI_DCM_COMBO_INDEX_UND) 
   {  
      // We only query at the first time
      __EMI_DCM_idx = CMEM_Index();
   
#if defined(MT6235) || defined(MT6235B)
#if defined(_NAND_FLASH_BOOTING_)
      EMI_CONTROL_J_104_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_value;
      EMI_CONTROL_K_104_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONK_value;
      EMI_CONTROL_L_104_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_value;
      EMI_CONTROL_M_104_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONM_value;
      EMI_GENERAL_A_104_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_GENA_value;
      EMI_GENERAL_B_104_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_GENB_value;
      EMI_GENERAL_C_104_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_GENC_value;
      EMI_CONTROL_J_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_13_value;
      EMI_CONTROL_K_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONK_13_value;
      EMI_CONTROL_L_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_13_value;
      EMI_CONTROL_M_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONM_13_value;
      EMI_GENERAL_A_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_GENA_13_value;
      EMI_GENERAL_B_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_GENB_13_value;
      EMI_GENERAL_C_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_GENC_13_value;      
#else
#endif
#elif defined(MT6236) || defined(MT6236B) /* MT6235 || MT6235B */
#if defined(_NAND_FLASH_BOOTING_)
      EMI_CONTROL_J_104_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_value;
      EMI_CONTROL_L_104_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_value;
      EMI_CONTROL_J_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_13_value;
      EMI_CONTROL_L_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_13_value;
#else
      EMI_CONA_BURST_13MHZ =  __EMI_DCM_control[__EMI_DCM_idx].EMI_CONA_BURST_13_value;
      EMI_CONB_BURST_13MHZ =  __EMI_DCM_control[__EMI_DCM_idx].EMI_CONB_BURST_13_value;
      EMI_CONE_BURST_13MHZ =  __EMI_DCM_control[__EMI_DCM_idx].EMI_CONE_BURST_13_value;
      EMI_CONF_BURST_13MHZ =  __EMI_DCM_control[__EMI_DCM_idx].EMI_CONF_BURST_13_value;
      EMI_CONA_BURST_104MHZ = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONA_BURST_104_value;
      EMI_CONB_BURST_104MHZ = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONB_BURST_104_value;
      EMI_CONE_BURST_104MHZ = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONE_BURST_104_value;
      EMI_CONF_BURST_104MHZ = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONF_BURST_104_value;
#endif
#elif defined(MT6268) /* MT6235 || MT6235B */
      EMI_CONTROL_J_122_88_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_value;
      EMI_CONTROL_L_122_88_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_value;
      EMI_CONTROL_J_15_36_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_15_36_value;
      EMI_CONTROL_L_15_36_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_15_36_value;
#endif  /* MT6235 || MT6235B */

   } 
   else
   { 
      return -1; //return error code instead ASSERT(0); // This init function should only be called once
   }
#endif /* __EMI_COMBO_EN */

#endif /* DCM_ENABLE || FEATURE_DCM_SSC */

#endif /* !MT6251 */

    return 0;
}

$emi_necessary_driver_endif

$emi_c_tail

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  FuncBody_custom_setEMI_for_lpsdram
# return:      template of "FUNCTION custom_setEMI()" for LPSDRAM
#****************************************************************************
sub FuncBody_custom_setEMI_for_lpsdram
{
   my $initialize_dram = &FuncBody_Common_initialize_DRAM();
   my $initialize_dram_3538 = &FuncBody_Common_initialize_DRAM_3538();
   my $template = <<"__TEMPLATE";
   kal_uint32   DRAM_Enable = DRAM_CS;
   volatile kal_uint32   delay;
   kal_uint32   DCache_Status=0;
   kal_int16    count = 0;
   volatile kal_uint32 *EMI_DQSx = NULL;

/**
  *   Call CMEM_EMIINIT_Index to get the index
  */
#if defined(__EMI_COMBO_EN)
   CMCP_Index = CMEM_EMIINIT_Index();
   __EMI_SetRegValfromCMCP();
#endif

/* PMU central control by pmu driver. */
#if (defined(MT6235) || defined(MT6235B)) 
   pmic_adpt_boot_init();
#endif /* MT6235 || MT6235B */

#if (defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6276))
   /* Add a delay loop for MT6235 to prevent modify EMI reg while EMI serving a request (pre-fetch). */
   for(delay=0; delay<255; delay++);
#endif

   if ( (DRAM_Enable != 0xFF) && (DRAM_Enable < 4) )
   {
#if (defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B))
      *EMI_GEND  = EMI_GENERAL_D_VAL;
#if (defined(MT6235) || defined(MT6235B))
      *EMI_GENA &= 0x3;
      *EMI_GENA |= (EMI_GENERAL_A_VAL & 0xFFFFFFFC);
#elif (defined(MT6268) || defined(MT6236) || defined(MT6236B))
      *EMI_GENA = EMI_GENERAL_A_VAL;
#endif
#endif

      /* remapping if DRAM at CS1 */
      if ( DRAM_Enable == 1 )
      {
#if (defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6276))
         *EMI_GENA   &= 0xFFFFFFFC;
         *EMI_GENA   |= 0x3;

         /**
            * we assume customers only use one CS as their DRAM.
            */
         *EMI_GEND   &= 0xFFF0FFF0;
         *EMI_GEND   |= 0x0002000D;
#else
         *EMI_REMAP = 3;
#endif
      }
      else if ( DRAM_Enable == 0 )
      {
#if (defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6276))
         /**
            * we assume DRAM at CS0.
            */
         *EMI_GENA   &= 0xFFFFFFFC;
         *EMI_GENA   |= 0x2;   

         /**
            * we assume customers only use one CS as their DRAM.
            */
         *EMI_GEND   &= 0xFFF0FFF0;
         *EMI_GEND   |= 0x0001000E;
#else
         *EMI_REMAP = 2;
#endif
      }
      else
      {
         /**
            * we do not support customers use those CS other than CS0 and CS1 as their booting regions.
            */
         ASSERT(0);
      }

#if (defined(MT6235) || defined(MT6235B))
      *EMI_GENB    = EMI_GENERAL_B_VAL;   
      *EMI_GENC    = EMI_GENERAL_C_VAL;   
      
      *EMI_CONL    = EMI_CONTROL_L_VAL;
      
      for(delay=0;delay<8;delay++);
      *EMI_CONM    = EMI_CONTROL_M_VAL;
      for(delay=0;delay<8;delay++);
      *EMI_CONI    = EMI_CONTROL_I_VAL;
      for(delay=0;delay<8;delay++);
      *EMI_CONJ    = EMI_CONTROL_J_VAL;
      for(delay=0;delay<8;delay++);
      *EMI_CONK    = EMI_CONTROL_K_VAL;
      for(delay=0;delay<20000;delay++);
      
$initialize_dram_3538

#elif (defined(MT6268) || defined(MT6236) || defined(MT6236B))

#if defined(MT6268)
    // DRAM AC timing setting 
     *EMI_CONI = EMI_CONTROL_I_VAL;
     *EMI_CONJ = EMI_CONTROL_J_VAL;
     *EMI_CONK = EMI_CONTROL_K_VAL;
     *EMI_CONL = EMI_CONTROL_L_VAL;
   
     // DRAM driving 
     *EMI_GENB = EMI_GENERAL_B_VAL;
     *EMI_GENC = EMI_GENERAL_C_VAL;
   
     // I/O Delay 
     *EMI_DELA = EMI_DELAY_A_VAL;
     *EMI_DELB = EMI_DELAY_B_VAL;
     *EMI_DELC = EMI_DELAY_C_VAL;
     *EMI_DELD = EMI_DELAY_D_VAL;
     *EMI_DELE = EMI_DELAY_E_VAL;
     *EMI_DELF = EMI_DELAY_F_VAL;
     *EMI_DELG = EMI_DELAY_G_VAL;
     *EMI_DELH = EMI_DELAY_H_VAL;
     *EMI_DELI = EMI_DELAY_I_VAL;
   
     // DLL offset
     *EMI_CONM = EMI_CONTROL_M_VAL;
   
     *EMI_CONN = (EMI_CONTROL_N_VAL & (~0x00000016) )|0x10000000;      /* SHK: Issue the Pre-charge All command. Now, EMI will start the precharge process. */
     *EMI_CONN = (EMI_CONTROL_N_VAL & (~0x00000016));    /* Clear the Pre-charge All command, and this will force EMI to stop the 
                                                     precharge process. Note that before our stopping Precharge All Command, 
                                                     it does no harm to DRAM if multiple Precharge All command is issued. */
     for(delay=0;delay<10;delay++);
   
     *EMI_CONN = (EMI_CONTROL_N_VAL & (~0x00000016) )|0x08000000;    /* SHK: Issue Auto-refresh-1 command. */
     *EMI_CONN = (EMI_CONTROL_N_VAL & (~0x00000016));                /* SHK: Clear the Auto-refresh-1 command. */
     for(delay=0;delay<10;delay++);
   
     *EMI_CONN = (EMI_CONTROL_N_VAL & (~0x00000016) )|0x04000000;    /* SHK: Issue Auto-refresh-2 command. */
     *EMI_CONN = (EMI_CONTROL_N_VAL & (~0x00000016));                /* SHK: Clear the Auto-refresh-1 command. */
     for(delay=0;delay<10;delay++);
   
     *EMI_CONN = (EMI_CONTROL_N_VAL & (~0x00000016) )|0x02000000;    /* SHK: Issue the Load Mode Register command. */
     *EMI_CONN = (EMI_CONTROL_N_VAL & (~0x00000016));                /* SHK: Clear the Load Mode Register command. */
     for(delay=0;delay<10;delay++);
   
     *EMI_CONN = (EMI_CONTROL_N_VAL & (~0x00000016) )|0x01000000;    /* SHK: Issue the Load Extended Mode Register command. */
     *EMI_CONN = (EMI_CONTROL_N_VAL & (~0x00000016));                /* SHK: Clear the Load Extended Mode Register command. */
   
     for(delay=0;delay<200;delay++);

#elif (defined(MT6236) || defined(MT6236B))
      *EMI_DELA = EMI_DELAY_A_VAL;
      *EMI_DELB = EMI_DELAY_B_VAL;
      *EMI_DELC = EMI_DELAY_C_VAL;
      *EMI_DELD = EMI_DELAY_D_VAL;
      *EMI_DELE = EMI_DELAY_E_VAL;
      *EMI_DELF = EMI_DELAY_F_VAL;
      *EMI_DELG = EMI_DELAY_G_VAL;
      *EMI_DELH = EMI_DELAY_H_VAL;
      *EMI_DELI = EMI_DELAY_I_VAL;
      *EMI_DELJ = EMI_DELAY_J_VAL;

      /**
         * set DRAM driving.
         */
      *EMI_GENB = EMI_GENERAL_B_VAL;
      *EMI_GENC = EMI_GENERAL_C_VAL;

      /**
         * set DRAM cycle-based timing.
         */
      *EMI_CONI = EMI_CONTROL_I_VAL;
      *EMI_CONJ = EMI_CONTROL_J_VAL;
      *EMI_CONK = EMI_CONTROL_K_VAL;
      *EMI_CONL = EMI_CONTROL_L_VAL;
   
      /**
         * DRAM initialization command. we mask out the power down mode, DLL calibration, and auto refresh to prevent possibly wrongly-set value on EMI database.
         */   
      *EMI_CONN = (EMI_CONTROL_N_VAL & 0x00FFFEE9) | 0x00000002;
      for (delay = 0; delay < 5000; delay++);
      *EMI_CONN = (EMI_CONTROL_N_VAL & 0x00FFFEE9) | 0x10000000;
      for (delay = 0; delay < 100; delay++);
       *EMI_CONN = (EMI_CONTROL_N_VAL & 0x00FFFEE9) | 0x08000000;	
      for (delay = 0; delay < 100; delay++);
      *EMI_CONN = (EMI_CONTROL_N_VAL & 0x00FFFEE9) | 0x04000000;	
      for (delay = 0; delay < 100; delay++);
      *EMI_CONN = (EMI_CONTROL_N_VAL & 0x00FFFEE9) | 0x02000000;
      for (delay = 0; delay < 100; delay++);
      *EMI_CONN = (EMI_CONTROL_N_VAL & 0x00FFFEE9) | 0x01000000;		
      for (delay = 0; delay < 100; delay++);
      *EMI_CONN = (EMI_CONTROL_N_VAL & 0x00FFFEE9) | 0x00001002;	
      for (delay = 0; delay < 100; delay++);

      *EMI_DQSA = 0x20202020;

#endif  /* MT6268 */
   
      /**
         * Enable power down mode, DLL calibration, and auto refresh.
         */
#if defined(MT6268)
     *EMI_CONN |= 0x00000016;
#elif defined(MT6236) || defined(MT6236B)
      *EMI_CONN |= 0x00000116;
#endif  /* MT6268 */
   
#if (defined(MT6268) || defined(MT6236) || defined(MT6236B))
      /* After enabling CAL_EN, wait for an auto refresh interval around 7.8 us is required. 
         The calibration value from DLL circuit can be applied on delay line. Then EMI can work normally. 
       */
      for(delay=0;delay<0xfff;delay++);
#else      
      for(delay=0;delay<200;delay++);
#endif
   
      /**
         * Set corresponding Rank for DQS auto-tracking calibration.
         */   
      if (0x1 == DRAM_Enable)
      {
         EMI_DQSx = EMI_DQSB;
      }
      else if(0x0 == DRAM_Enable)
      {
         EMI_DQSx = EMI_DQSA;
      }
      else
      {
         ASSERT(0);
      }

#if defined(__ARM9_MMU__)
      /**
         * Disable D Cache if D cache is enabled 
         */
     DCache_Status = cp15_is_dcache_enabled();
     if ( DCache_Status )
     {
         cp15_clean_dcache();
         cp15_drain_write_buffer();
         cp15_disable_dcache();
     }
#endif   

      /**
         * flush read FIFO  
         */
     store_8word(0, 0x5555aaaa);
     for(delay=0; delay<=0x78; delay+=0x8) {

         *EMI_DQSx    = (delay<<24) | (delay<<16) | (delay<<8) | (delay<<0);
    
         if( 0 == load_8word(0, 0x5555aaaa) ) {
             break;
         }
     }
   
      /**
         * do DQS calibration
         */
     store_8word(0x0, 0x12345678);
      for(delay=0x0;delay<=0x78;delay += 0x8)
      {
         *EMI_DQSx    = (delay<<24) | (delay<<16) | (delay<<8) | (delay<<0);
         
         if(load_8word(0x0, 0x12345678) == 0 ) 
         {
             count++;
         }

         if(count > 1) 
         {
            break;
         }

         *EMI_DQSx   = 0x00000000;
      }

      if(count <= 1)
      {
         /**
            * DQA auto calibration fails. trap it directly.
            */
         ASSERT(0);
      }

     *EMI_DQSx   |= 0x80808080;     
     for(delay=0;delay<10;delay++);     
   
#if defined(__ARM9_MMU__)   
      /**
         * Enable D Cache
         */
     if( DCache_Status )
     {
         cp15_invalidate_dcache();
         cp15_enable_dcache();         
     }
#endif   

      /**
         * enable EMI dummy read (Wrap 4x4)
         */
     *EMI_DRCT = 0x00000221; 
    
#if defined(MT6268)
     /* enable bandwidth limiter */
     *EMI_ARBA = EMI_ARB_A_VAL;
   
     /* Set D-bus BW */
     *EMI_ARBB = EMI_ARB_B_VAL;
   
     /* Set DMA BW */
     *EMI_ARBC = EMI_ARB_C_VAL;
   
     /* Set None */
     *EMI_ARBD = EMI_ARB_D_VAL;
   
     /* Set I-bus BW */
     *EMI_ARBE = EMI_ARB_E_VAL; 
   
     /* Set 3G BW */
     *EMI_ARBF = EMI_ARB_F_VAL;
   
     /* Set 2G BW */
     *EMI_ARBG = EMI_ARB_G_VAL;
   
     /* Set GMC0 BW */
     *EMI_ARBH = EMI_ARB_H_VAL;
   
     /* Set GMC1 BW */
     *EMI_ARBI = EMI_ARB_I_VAL;

#elif defined(MT6236) || defined(MT6236B)
      /**
         * set EMI arbitrator:
         * 1. MCU EMI BW: 11%, soft mode.
         * 2. layer2 BUS EMI BW: 23%, soft mode.
         * 3. MCU EMI BW: 11%, soft mode.
         * 4. GMC1 EMI BW: 22.66%, soft mode.
         * 5. GMC2 EMI BW: 19.53%, soft mode.
         */
      *EMI_ARBA = 0x0000580F;
      *EMI_ARBB = 0x0000501E;
      *EMI_ARBC = 0x0000500F;
      *EMI_ARBH = 0x0000501E;
      *EMI_ARBI = 0x00005019;

#endif  /* MT6268 */

#elif defined(MT6276) /* MT6235 || MT6235B */

    __EMI_InitializationFlow();

#else
$initialize_dram
#endif
      return 1;
   }
   else
   {
      /**
         * trap directly.
         */
      ASSERT(0);
   }

   return -1;
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  FuncBody_Common_initialize_DRAM
# return:      template of "FUNCTION custom_setEMI()" for LPSDRAM
#****************************************************************************
sub FuncBody_Common_initialize_DRAM
{
    my $template = <<"__TEMPLATE";
      /* Setting driving */
      *EMI_GENB = EMI_GENERAL_CONTROL2_VAL;

      /* Turn on clock and driving tuning */
      *EMI_GENA = EMI_GENERAL_CONTROL1_VAL;

      for (delay = 0; delay < 200; delay++) ;

      /* Turn-on SDRAM */
      *EMI_CONK = EMI_DRAM_CONTROL;
      *EMI_CONL = EMI_DRAM_RERESH_CONTROL;

      /*  Ping-pong operation, SDRAM enable, CAS = 2T, Burst Read/Single Write ; \CS1, 8words burst length, sequential burs, */
      if ( DRAM_SIZE == 64 )
        *EMI_CONI = EMI_DRAM_MODE | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 128 )
        *EMI_CONI = EMI_DRAM_MODE | (1 << 20) | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 256 )
         *EMI_CONI = EMI_DRAM_MODE | (2 << 20) | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 512 )
         *EMI_CONI = EMI_DRAM_MODE | (3 << 20) | (DRAM_CS << 16);

      for (delay = 0; delay < 200; delay++);

      /* Precharge all */
      *EMI_CONJ = 0x01;

      for (delay = 0; delay < 200; delay++);

      /* Ping-pong operation, SDRAM enable, CAS = 2T, Burst Read/Single Write ; \CS1, 8words burst length, sequential burs, */
      if ( DRAM_SIZE == 64 )
        *EMI_CONI = EMI_DRAM_EXT_MODE | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 128 )
         *EMI_CONI = EMI_DRAM_EXT_MODE | (1 << 20) | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 256 )
         *EMI_CONI = EMI_DRAM_EXT_MODE | (2 << 20) | (DRAM_CS << 16);
      else if (DRAM_SIZE == 512)
         *EMI_CONI = EMI_DRAM_EXT_MODE | (3 << 20) | (DRAM_CS << 16);

      /* Set mode register */
      *EMI_CONJ = 0x04;

      for (delay = 0; delay < 200; delay++);

       /* Ping-pong operation, SDRAM enable, CAS = 2T, Burst Read/Single Write; \CS1, 8words burst length, sequential burs, */
      if ( DRAM_SIZE == 64 )
        *EMI_CONI = EMI_DRAM_MODE | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 128 )
         *EMI_CONI = EMI_DRAM_MODE | (1 << 20) | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 256 )
         *EMI_CONI = EMI_DRAM_MODE | (2 << 20) | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 512 )
         *EMI_CONI = EMI_DRAM_MODE | (3 << 20) | (DRAM_CS << 16);

      /* Set mode register */
      *EMI_CONJ = 0x04;

      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 104MHz */
      *EMI_CONL = EMI_DRAM_RERESH_CONTROL | 0x80000000;

      /* enable CKE */
      *EMI_GENA |= 0x80000000;

      for (delay = 0; delay < 200; delay++);
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  FuncBody_Common_initialize_DRAM_3538
# return:      template of "FUNCTION custom_setEMI()" for LPSDRAM
#****************************************************************************
sub FuncBody_Common_initialize_DRAM_3538
{
   my $template = <<"__TEMPLATE";
      *EMI_CONN  = ( EMI_CONTROL_N_VAL & (~0x00000012)) | 0x10000000;
      for(delay=0;delay<4;delay++);
      *EMI_CONN  = ( EMI_CONTROL_N_VAL & (~0x00000012));
      
      *EMI_CONN  = ( EMI_CONTROL_N_VAL & (~0x00000012)) | 0x08000000;
      for(delay=0;delay<4;delay++);
      *EMI_CONN  = ( EMI_CONTROL_N_VAL & (~0x00000012));
      
      *EMI_CONN  = ( EMI_CONTROL_N_VAL & (~0x00000012)) | 0x04000000;
      for(delay=0;delay<4;delay++);
      *EMI_CONN  = ( EMI_CONTROL_N_VAL & (~0x00000012));
      
      *EMI_CONN  = ( EMI_CONTROL_N_VAL & (~0x00000012)) | 0x02000000;
      for(delay=0;delay<4;delay++);
      *EMI_CONN  = ( EMI_CONTROL_N_VAL & (~0x00000012));
      
      *EMI_CONN  = ( EMI_CONTROL_N_VAL & (~0x00000012)) | 0x01000000;
      for(delay=0;delay<4;delay++);
      *EMI_CONN  = ( EMI_CONTROL_N_VAL & (~0x00000012));
      
      for(delay=0;delay<256;delay++);

      /* Enable power down mode and auto refresh */
      *EMI_CONN |= (0x00000002 | (EMI_CONTROL_N_VAL & 0x00000010));
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  FuncBody_custom_setEMI_for_nor_ram_mcp
# return:      template of "FUNCTION custom_setEMI()" for NOR_RAM_MCP
#****************************************************************************
sub FuncBody_custom_setEMI_for_nor_ram_mcp
{
    my $template = <<"__TEMPLATE";
   unsigned short delay;

/**
  *   Call CMEM_EMIINIT_Index to get the index
  */
#if defined(__EMI_COMBO_EN)

#if defined(__EMI_SIP_RAM)
   /* query DIDR and find the "correct" config set */
   __EMI_GetDIDR();
   CMCP_Index = __EMI_SelectSIPbyDIDR();
#else
   CMCP_Index = CMEM_EMIINIT_Index();
#endif

   __EMI_SetRegValfromCMCP();

#endif /* __EMI_COMBO_EN */

#if defined(MT6252)||defined(MT6252H)

   return setEMI_MT6252_series();

#else /* MT6252 || MT6252H */

/* PMU central control by pmu driver. */
#if (defined(MT6235) || defined(MT6235B) || defined(MT6238) || defined(MT6239)) 
   pmic_adpt_boot_init();
#endif /* MT6235 || MT6235B || MT6238 || MT6239 */

#if (defined(MT6235) || defined(MT6235B)) 
   /* Add a delay loop for MT6235 to prevent modify EMI reg while EMI serving a request (pre-fetch). */
   for(delay=0; delay<255; delay++);
#endif

#if defined(MT6253)

#if defined(__EMI_CLK_52MHZ__)

    if((GP_MT6253 == INT_ChipGroup()) || (GP_MT6253DV == INT_ChipGroup()))
    {
        ASSERT(0);
    }

    if(GP_MT6253D == INT_ChipGroup())
    {
        /**
           * Set EMI clock to 52MHz.
           */
        *EMICLK_CON = 0x0010;
    }

#elif defined(__EMI_CLK_104MHZ__) /* __EMI_CLK_52MHZ__ */

    if((GP_MT6253D == INT_ChipGroup())  || (GP_MT6253DV == INT_ChipGroup()))
    {
        /**
          * Set EMI clock to 104MHz.
          */
        *EMICLK_CON = 0x0000;
    }

#endif /* __EMI_CLK_52MHZ__ */

#endif /* MT6253 */


   /** 
     * enable the ADMUX bit, this is actually a redundant operation and we plan to remove it in the future.
     */
#if (defined(MT6225) || defined(MT6227D) || defined(MT6226D) || defined(MT6223) || defined(MT6223P) || defined(MT6223D)) && !defined(ADMUX_MCP)
   *(volatile kal_uint32 *)(0x80010078) = 0;
#elif defined(MT6253)
     *EMI_ADMUX = 0x3;
#endif

   /**
     * Initialize EMI SRARM controller timing if the rank is used.
     */
   if ( EMI_CSConfiguration[0] != UNUSED )
   {
      *(EMI_CONA) = EMI_CONA_ASYNC;

#if (defined(MT6236) || defined(MT6236B))
      /**
        * RD_DEL_SEL must be h01 under asyn mode
        * We should keep this value maintenance in the database, here we just set it to prevent any potential MVG setting error.
        */
      *EMI_CONE |= 0x00000400;
#endif /* MT6236 || MT6236B */
   }

   if ( EMI_CSConfiguration[1] != UNUSED )
   {
      *(EMI_CONB) = EMI_CONB_ASYNC;

#if (defined(MT6236) || defined(MT6236B))
      /**
        * RD_DEL_SEL must be h01 under asyn mode
        * We should keep this value maintenance in the database, here we just set it to prevent any potential MVG setting error.
        */
      *EMI_CONF |= 0x00000400;
#endif /* MT6236 || MT6236B */
   }

   if ( EMI_CSConfiguration[2] != UNUSED )
   {
      *(EMI_CONC) = EMI_CONC_ASYNC;

#if (defined(MT6236) || defined(MT6236B))
      /**
        * RD_DEL_SEL must be h01 under asyn mode
        * We should keep this value maintenance in the database, here we just set it to prevent any potential MVG setting error.
        */
      *EMI_CONG |= 0x00000400;
#endif /* MT6236 || MT6236B */
   }

   if ( EMI_CSConfiguration[3] != UNUSED )
   {
      *(EMI_COND) = EMI_COND_ASYNC;

#if (defined(MT6236) || defined(MT6236B))
      /**
        * RD_DEL_SEL must be h01 under asyn mode
        * We should keep this value maintenance in the database, here we just set it to prevent any potential MVG setting error.
        */
      *EMI_CONH |= 0x00000400;   
#endif /* MT6236 || MT6236B */
   }

   /**
       * Setting EMI general control register and cache/prefetch size if necessary. 
       */

#if (defined(MT6235) || defined(MT6235B))
   *EMI_GENA &= 0x3;
   *EMI_GENA |= ((EMI_GENERAL_A_VAL & ~(0x600)) & 0xFFFFFFFC);

   *EMI_GENB = EMI_GENERAL_B_VAL;
   *EMI_GENC = EMI_GENERAL_C_VAL;     
   *EMI_GEND = EMI_GENERAL_D_VAL;

#elif defined(MT6253) /* MT6235 || MT6235B */

   *EMI_GEN = EMI_GENERAL_CONTROL;
   *PREFETCH_CON = EMI_CACHE_PREFETCH;
   *EMI_GEN2 &= ~(0x2); //Disable ULTRA_EN of EMI_GEN2

#elif (defined(MT6236) || defined(MT6236B)) /* MT6235 || MT6235B */

   *EMI_GEND  = EMI_GENERAL_D_VAL;
   *EMI_GENA = EMI_GENERAL_A_VAL;

#else /* MT6235 || MT6235B */

   *EMI_GEN = EMI_GENERAL_CONTROL;
   *PREFETCH_CON = EMI_CACHE_PREFETCH;

#endif /* MT6235 || MT6235B */

   return 0;

#endif /* MT6252 || MT6252H */
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  FuncBody_custom_setEMI_empty
# return:      template of "FUNCTION custom_setEMI()" for chips without EMI
#****************************************************************************
sub FuncBody_custom_setEMI_empty
{
    my $template = <<"__TEMPLATE";
    return 0;
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  FuncBody_custom_setAdvEMI_for_nor_ram_mcp
# return:      template of "FUNCTION custom_setEMI()" for NOR_RAM_MCP
#****************************************************************************
sub FuncBody_custom_setAdvEMI_for_nor_ram_mcp
{
    my ($MAKEFILE_OPTIONS_LOCAL, $emi_clk_config_LOCAL) = @_;
    my $template;

    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6253') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236B') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6921') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H'))
    {
        $template .= &custom_setadvemi_for_53_after($MAKEFILE_OPTIONS_LOCAL, $emi_clk_config_LOCAL);
    }

        return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_53_after
# return:      template of "FUNCTION custom_setAdvEMI()" for NOR_RAM_MCP for
#              MT6253
#****************************************************************************
sub custom_setadvemi_for_53_after
{
    my ($MAKEFILE_OPTIONS_LOCAL, $emi_clk_config_LOCAL) = @_;
    my (@addr_list_nor, @addr_list_psram, @rw_addr_list_psram);

    ### No COMBO Memory case
    my @addr_list_nor = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB(1, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
    my @addr_list_psram = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB(1, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
    my @rw_addr_list_psram = &split_addr_ret_rw(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB(1, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));

    my $nor_config;
    for (0..$#addr_list_nor)
    {
        my $idx    = $_ + 1;
        $nor_config  .= "    ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS_$idx);\n";
        $nor_config  .= "    *ptr16 = EMI_NOR_BURST_DATA_$idx;\n";
        if ($_ == $#addr_list_nor)
        {
            $nor_config .=  "    for (delay=0; delay <0xff; delay++);\n";
        }
        else
        {
            $nor_config .=  "    for (delay=0; delay <0x0f; delay++);\n";
        }
    }

    my $psram_config;
    for (0..$#addr_list_psram)
    {
        my $idx    = $_ + 1;
        if ($rw_addr_list_psram[$_] =~ /R:/)
        {
            $psram_config .= "    data = *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_$idx);\n";
        }
        elsif ($rw_addr_list_psram[$_] =~ /W:/)
        {
            $psram_config .= "    *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_$idx) = EMI_PSRAM_BURST_DATA_$idx;\n";
        }
        else
        {
            $psram_config .= "    *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_$idx) = data;\n";
        }
        if ($_ == $#addr_list_psram)
        {
            $psram_config .=  "    for (delay=0; delay <0xff; delay++);\n";
        }
        else
        {
            $psram_config .=  "    for (delay=0; delay <0x0f; delay++);\n";
        }
    }

    my $template = <<"__TEMPLATE";
#if defined(MT6252) || defined(MT6252H)
    return setAdvEMI_MT6252_series();
#else /* MT6252 || MT6252H */

     kal_int32   delay = 0xf;
     volatile unsigned short *ptr16;
     unsigned short data;
     kal_uint32 saved_cache_con, saved_prefetch_con;

#if defined(MT6253)
     /**
       * Backup L1 cache and EMI cache/prefetch value.
       */
     saved_cache_con = *CACHE_CON;
     saved_prefetch_con = *PREFETCH_CON;

     /**
       * Disable L1 cache and EMI cache to prevent any commands being cached.
       */
     *CACHE_CON &= ~(0x000d);
     *PREFETCH_CON &= ~(0x10001);

#endif /* MT6253 */

#if defined(MT6236) || defined(MT6236B)
    /**
      * On ARM9 system, the core will perform pre-fetch in the background, we add a delay loop to prevent modify EMI reg 
      * while EMI serving a request (pre-fetch). 
      */
    for (delay=0; delay <0xff; delay++);

    init_eco_version = INT_ecoVersion();

     /**
        * Setting EMI general control register and cache/prefetch size if necessary.
        */
     *EMI_GEND  = EMI_GENERAL_D_VAL;
    if(init_eco_version == ECO_E2) // 1T path
    {
        *EMI_GENA = 0x00D90002;
    }
    else // 4T path
    {
        *EMI_GENA = EMI_GENERAL_A_VAL;
    }
#endif /* MT6236 || MT6236B */

#if defined(MT6236) || defined(MT6236B)
    if(init_eco_version == ECO_E2) // 1T path (PF38F5060M0Y3DG)
    {
       /**
          * Switch NOR-Flash RCR into corresponding modes.
          * This part is not part of the auto-gen template and is compile-time generated.
          */
        ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0xA206);
        *ptr16 = 0x60;
        for (delay=0; delay <0x0f; delay++);
        ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0xA206);
        *ptr16 = 0x03;
        for (delay=0; delay <0x0f; delay++);
        ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x00000008);
        *ptr16 = 0x60;
        for (delay=0; delay <0x0f; delay++);
        ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x00000008);
        *ptr16 = 0x04;
        for (delay=0; delay <0x0f; delay++);        
        ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x00);
        *ptr16 = 0xFF;
        for (delay=0; delay <0xff; delay++);


        /**
          * Switch PSRAM configuration (BCR/RCR) into corresponding modes.
          * This part is not part of the auto-gen template and is compile-time generated.
          */
        data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x07FFFFFE);
        for (delay=0; delay <0x0f; delay++);
        data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x07FFFFFE);
        for (delay=0; delay <0x0f; delay++);
        *(volatile unsigned short *)(RAM_BASE_ADDR | 0x07FFFFFE) = 0x01;
        for (delay=0; delay <0x0f; delay++);
        *(volatile unsigned short *)(RAM_BASE_ADDR | 0x07FFFFFE) = 0x1913;
        for (delay=0; delay <0xff; delay++);
        data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x07FFFFFE);
        for (delay=0; delay <0x0f; delay++);
        data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x07FFFFFE);
        for (delay=0; delay <0x0f; delay++);
        *(volatile unsigned short *)(RAM_BASE_ADDR | 0x07FFFFFE) = 0x00;
        for (delay=0; delay <0x0f; delay++);
        *(volatile unsigned short *)(RAM_BASE_ADDR | 0x07FFFFFE) = 0x0010;
        for (delay=0; delay <0xff; delay++);
    }
    else // 4T path
    {
#endif /* MT6236 || MT6236B */
    /**
      * Switch NOR-Flash RCR into corresponding modes.
      * This part is not part of the auto-gen template and is compile-time generated.
      */
#if defined(__EMI_COMBO_EN)
    for (i=0;i<Sel_NOR_CMD_num; i++) 
    {
        if (EMI_NOR_BURST_OP[i] == MEM_CMD_OP_16BIT_RD) {
        	  data = *(volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS[i]);
        } else if (EMI_NOR_BURST_OP[i] == MEM_CMD_OP_16BIT_WR) {
            *(volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS[i]) = EMI_NOR_BURST_DATA[i];
        }
        for (delay=0; delay <0x0f; delay++) {
            #if defined(__RVCT__) && defined(__MTK_TARGET__)
            __nop()
            #endif
            ;
        }
    }
    for (delay=0; delay <0xff; delay++) {
        #if defined(__RVCT__) && defined(__MTK_TARGET__)
        __nop()
        #endif
        ;
    }
#else /* __EMI_COMBO_EN */
$nor_config
#endif /* __EMI_COMBO_EN */

    /**
      * Switch PSRAM configuration (BCR/RCR) into corresponding modes.
      * This part is not part of the auto-gen template and is compile-time generated.
      */
#if defined(__EMI_COMBO_EN)
    for (i=0;i<Sel_PSRAM_CMD_num; i++) 
    {
        if (EMI_PSRAM_BURST_OP[i] == MEM_CMD_OP_16BIT_RD) {
        	  data = *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS[i]);
        } else if (EMI_PSRAM_BURST_OP[i] == MEM_CMD_OP_16BIT_WR) {
            *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS[i]) = EMI_PSRAM_BURST_DATA[i];
        }
        for (delay=0; delay <0x0f; delay++) {
            #if defined(__RVCT__) && defined(__MTK_TARGET__)
            __nop()
            #endif
            ;
        }
    }
    for (delay=0; delay <0xff; delay++) {
        #if defined(__RVCT__) && defined(__MTK_TARGET__)
        __nop()
        #endif
        ;
    }
#else /* __EMI_COMBO_EN */
$psram_config
#endif /* __EMI_COMBO_EN */
#if defined(MT6236) || defined(MT6236B)
    }
#endif

#if defined(MT6236) || defined(MT6236B)
    if(init_eco_version == ECO_E2) // 1T path
    {
        /**
          * Switch the EMI register into corresponding modes.
          */
        *EMI_CONA = 0xA8A00021; 
        *EMI_CONE = 0x29C05000; 
        for (delay=0; delay <0xff; delay++);   
        *EMI_CONB = 0xA0000000; 
        *EMI_CONF = 0xB4405088;
        for (delay=0; delay <0xff; delay++);
     
        /**
          * set SCLK_EN, SCLK_SEL(center-aligned for write) & HCLKX2_CK_ON.
          */
        *EMI_GENA |= 0x00000D00;
        for (delay=0; delay <0xff; delay++);      

        /**
          * set driving & delay 
          */
        *EMI_GENB = 0x0000000E;
        *EMI_GENC = 0x00EEEEE0;
        *EMI_DELJ = 0x00000000;
    }
    else
    {
        /**
          * Switch the EMI register into corresponding modes.
          */     
        *EMI_CONA = EMI_CONA_BURST; 
        *EMI_CONE = EMI_CONE_BURST; 
        for (delay=0; delay <0xff; delay++);   
        *EMI_CONB = EMI_CONB_BURST; 
        *EMI_CONF = EMI_CONF_BURST;
        for (delay=0; delay <0xff; delay++);     
     
        /**
          * set SCLK_EN, SCLK_SEL(center-aligned for write)
          */
        *EMI_GENA |= 0x00000C00;
        for (delay=0; delay <0xff; delay++);

        /**
          * enable feedback clock
          */        
        *EMI_RDCT = EMI_RDCT_VAL;
        for (delay=0; delay <0xff; delay++);           

        /**
          * set driving & delay 
          */
        *EMI_GENB = EMI_GENERAL_B_VAL;
        *EMI_GENC = EMI_GENERAL_C_VAL;
        *EMI_DELJ = EMI_DELAY_J_VAL;    
    }
   
    /**
      * set EMI arbitrator:
      * 1. MCU EMI BW: 34%, soft mode.
      * 2. layer2 BUS EMI BW: 28.49%, soft mode.
      * 3. MCU EMI BW: 34%, soft mode.
      * 4. GMC1 EMI BW: 16.98%, soft mode.
      * 5. GMC2 EMI BW: 16.01%, soft mode.
      */
    *EMI_ARBA = 0x0000582C;
    *EMI_ARBB = 0x00005022;
    *EMI_ARBC = 0x0000502C;
    *EMI_ARBH = 0x00005015;
    *EMI_ARBI = 0x00005014;

#elif defined(MT6253) /* MT6236 || MT6236B */
     *EMI_CONA = EMI_CONA_BURST; 
     *EMI_CONB = EMI_CONB_BURST; 
     *EMI_EXTCON2 |= 0x0300; 
     *EMI_GEN = EMI_GENERAL_CONTROL_BURST; 
     *EMI_CLOCKDEL = 0x0; 
     *EMI_EXTCON = 0x0; 
     for (delay=0; delay <0xff; delay++);

     /************************
      *
      * NEGSEL calibration, and we will remove it in the future.
      *
      ************************/

     /* Find the correct NEGSEL of BANK0*/
     if (nor_compare_pattern != EMI_COMPARE_PATTERN)
     {
        /**
          * toggle NEGSEL in EMI Clock Delay Register.
          */
          if(*EMI_CLOCKDEL & (0x1 << BANK0_NEGSEL_p)) 
          {
            /**
              * If the bit associate with specified bank is 1, then switch to 0.
              */
              *EMI_CLOCKDEL &= ~(0x1 << BANK0_NEGSEL_p);
          }
          else 
          {
            /** 
              * If the bit associate with specified bank is 0, then switch to 1.
              */
              *EMI_CLOCKDEL |= (0x1 << BANK0_NEGSEL_p);
          }
     }    
         
     /**
       * Find the correct NEGSEL of BANK1.
       */
     if (psram_compare_pattern != EMI_COMPARE_PATTERN)
     {
          /**
            * toggle NEGSEL in EMI Clock Delay Register
            */
          if(*EMI_CLOCKDEL & (0x1 << BANK1_NEGSEL_p)) 
          {
              /**
                * If the bit associate with specified bank is 1, then switch to 0.
                */
              *EMI_CLOCKDEL &= ~(0x1 << BANK1_NEGSEL_p);
          }
          else 
          {
              /** 
                * If the bit associate with specified bank is 0, then switch to 1.
                */
              *EMI_CLOCKDEL |= (0x1 << BANK1_NEGSEL_p);
          }
     }

#endif  /* MT6236 || MT6236B */

#if defined(MT6253)
    /**
      * Restore original L1 cache and EMI cache/prefetch setting.
      */
    *PREFETCH_CON = saved_prefetch_con;
    *CACHE_CON = saved_cache_con;
#endif /* MT6253 */

#endif /* MT6252 || MT6252H */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_2829_sync_access_104_sibley_part
# return:      template of "FUNCTION custom_setAdvEMI()" for 28/29 SYNC_ACCESS
#              part for 104MHz INTEL SIBLEY
#****************************************************************************
sub custom_setadvemi_for_2829_sync_access_104_sibley_part
{
    my $template = <<"__TEMPLATE";
   /* Turn on advanced mode on NOR-flash */
   {
      kal_uint32 NORBaseAddr, RAMBaseAddr;
      kal_uint32 delay;
      kal_uint16 data;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();
      RAMBaseAddr = NORBaseAddr ^ 0x08000000;

      *EMI_GENB = EMI_DRV0_BURST_MODE;
#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
      *EMI_GENC = EMI_DRV1_BURST_MODE;
#endif
      *EMI_GENA = EMI_DRV2_BURST_MODE;

      /* Configure NOR-flash to synchronous access */
      for (delay = 0; delay < 0xff; delay++);

      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_1)) = DEV_CONFIG_FLASH_BMODE_DATA_1;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_2)) = DEV_CONFIG_FLASH_BMODE_DATA_2;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_3)) = DEV_CONFIG_FLASH_BMODE_DATA_3;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_4)) = DEV_CONFIG_FLASH_BMODE_DATA_4;

      for (delay = 0; delay < 0xff; delay++);

      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_5)) = DEV_CONFIG_FLASH_BMODE_DATA_5;

      *(EMI_CONA) = EMI_FLASH_BURST_MODE;

      /* Configure PSRAM to synchronous access */
      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_1));
      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_2));

      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_3)) = DEV_CONFIG_RAM_BMODE_DATA_3;
      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_4)) = DEV_CONFIG_RAM_BMODE_DATA_4;

      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_5));
      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_6));

      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_7)) = DEV_CONFIG_RAM_BMODE_DATA_7;
      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_8)) = DEV_CONFIG_RAM_BMODE_DATA_8;

      for (delay = 0; delay < 0xff; delay++);

      *(EMI_CONB) = EMI_RAM_BURST_MODE;

      status |= 0x10;
   }
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_2829_sync_access_104_ty_part
# return:      template of "FUNCTION custom_setAdvEMI()" for 28/29 SYNC_ACCESS
#              part for 104MHz TOSHIBA TYAX
#****************************************************************************
sub custom_setadvemi_for_2829_sync_access_104_ty_part
{
    my $template = <<"__TEMPLATE";
   /* Turn on 104Mhz synchronous mode on NOR-flash and PSRAM */
   {
      kal_uint32 NORBaseAddr, RAMBaseAddr;
      kal_uint32 delay;
      kal_uint16 data;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();
      RAMBaseAddr = NORBaseAddr ^ 0x08000000;

      *EMI_GENB = EMI_DRV0_BURST_MODE;
#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
      *EMI_GENC = EMI_DRV1_BURST_MODE;
#endif
      *EMI_GENA = EMI_DRV2_BURST_MODE;

      /* Configure NOR-flash to synchronous access */
      for (delay = 0; delay < 0xff; delay++);

      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_1)) = DEV_CONFIG_FLASH_BMODE_DATA_1;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_2)) = DEV_CONFIG_FLASH_BMODE_DATA_2;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_3)) = DEV_CONFIG_FLASH_BMODE_DATA_3;

      for (delay = 0; delay < 0xff; delay++);

      *(EMI_CONA) = EMI_FLASH_BURST_MODE;

      /* Configure PSRAM to synchronous access */
      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_1));

      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_2)) = data;
      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_3)) = data;
      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_4)) = data;
      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_5)) = data;

      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_6));

      for (delay = 0; delay < 0xff; delay++);

      *(EMI_CONB) = EMI_RAM_BURST_MODE;

      for (delay = 0; delay < 0xff; delay++);

      status |= 0x10;
   }
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_2829_sync_access_104_sibley_nor_lpsdram_part
# return:      template of "FUNCTION custom_setAdvEMI()" for 28/29 SYNC_ACCESS
#              part for 104MHz INTEL SIBLEY
#****************************************************************************
sub custom_setadvemi_for_2829_sync_access_104_sibley_nor_lpsdram_part
{
    my $template = <<"__TEMPLATE";
   /* Turn on advanced mode on NOR-flash */
   {
      kal_uint32 NORBaseAddr;
      kal_uint32 delay;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();

      *EMI_GENB = EMI_DRV0_BURST_MODE;
#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
      *EMI_GENC = EMI_DRV1_BURST_MODE;
#endif
      *EMI_GENA = EMI_DRV2_BURST_MODE;

      /* Configure NOR-flash to synchronous access */
      for (delay = 0; delay < 0xff; delay++);

      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_1)) = DEV_CONFIG_FLASH_BMODE_DATA_1;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_2)) = DEV_CONFIG_FLASH_BMODE_DATA_2;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_3)) = DEV_CONFIG_FLASH_BMODE_DATA_3;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_4)) = DEV_CONFIG_FLASH_BMODE_DATA_4;

      for (delay = 0; delay < 0xff; delay++);

      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_5)) = DEV_CONFIG_FLASH_BMODE_DATA_5;

      *(EMI_CONA) = EMI_FLASH_BURST_MODE;

      for (delay = 0; delay < 0xff; delay++);

      status |= 0x10;
   }
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $BBtbl_LPSDRAM_LOCAL) = @_;
    if ( (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2')) && ($LPSDRAM_CHIP_SELECT_LOCAL !~ /0xFF/i)
        && $BBtbl_LPSDRAM_LOCAL->{$MAKEFILE_OPTIONS_LOCAL->{'platform'}} )
    {
        return &FuncBody_custom_dynamicclockswitch_LPSDRAM($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL);
    } # if ( (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2')) && ($LPSDRAM_CHIP_SELECT_LOCAL !~ /0xFF/i)
    elsif ( (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{RAM_ACCESS_TYPE} eq 'SYNC_ACCESS')) || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
    {
        return &FuncBody_custom_dynamicclockswitch_SYNC($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL);
    } # elsif ( ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') && ... )
    else
    {
        return &FuncBody_custom_dynamicclockswitch_default($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL);
    }
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body specific for LPSDRAM
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_LPSDRAM
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL) = @_;
    my $ctrl_val;

    ###
    my $dcm_FuncBody;
    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235B') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6238') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6239'))
    {
        $dcm_FuncBody = &FuncBody_custom_dynamicclockswitch_LPSDRAM_3538($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL);
    }
    elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6268') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6276'))
    {
        $dcm_FuncBody = &FuncBody_custom_dynamicclockswitch_6876();
    }
    elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236B'))
    {
        $dcm_FuncBody = &FuncBody_custom_dynamicclockswitch_36();
    }

    ###
    my $template = <<"__TEMPLATE";

   register kal_uint32 delay;
   register kal_bool   dcm_sw_workaround = KAL_FALSE;

$dcm_FuncBody

   /* unsupported MCU clock */
   return -1;

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body specific for MT6268 and MT6276
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_6876
{
    my $template = <<"__TEMPLATE__";
#if defined(FEATURE_DCM_SSC)
   unsigned int interruptMask;

#if defined( DCM_ENABLE )
   if(SSC_DCM_Handle==0xFFFFFFFF)
   {
       SSC_DCM_Handle = (unsigned int)DCM_GetHandle();
   }
#endif /* DCM_ENABLE */

#endif /* FEATURE_DCM_SSC */


#if ( !defined(MT6235) && !defined(MT6235B) && !defined(MT6268) && !defined(MT6276) )
   if (clock == MCU_13MHZ)
   {
      /* enter self-refresh mode */
      *EMI_CONJ |= 0x00000100;

      /* wait until the status is changed */
      while (!(*EMI_CONJ & 0x01000000))
      {
         /* NOP */
      }

      /* switch clock to 13MHz */
      *MCUCLK_CON = 0x0000;

      /* delay for 8 cycles */
      for (delay = 0; delay < 8; delay++) {

         /* NOP */
      }

      /* specify EMI setting */

      /* set driving */
      *EMI_GENB = ;

      /* turn on clock, set clock driving and delay */
      *EMI_GENA =  | 0x80000000;


      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* exist self-refresh mode */
      *EMI_CONJ &= ~(0x00000100);

      /* wait until the status is changed */
      while (*EMI_CONJ & 0x01000000)
      {
         /* NOP */
      }

      /* enable auto refresh */
      *EMI_CONL = *EMI_CONL | 0x80000000;

      return 0;
   }
#endif  /* !MT6235 && !MT6235B && !MT6268 && !MT6276*/

#if defined(MT6268)
   
    dcm_status = 1;
    
    if (clock == MCU_15_36MHZ) 
    {
        /* save DQSA */
        emi_dqsa_122_88mhz = *EMI_DQSA & (~0x80808080);

        /* block emi access */
        *EMI_CONM |= 0x1FF0;

        /* enter SDRAM self-refresh mode */
        *EMI_CONN |= 0x00000020;
        do {
            if ((*EMI_CONN) & 0x00000080) {
                break;
            }
        } while (1);

        /* poll the emi idle status */
        do {
            if ((*CLK_INFO) & 0x00008000) {
                break;
            }
        } while (1);

            
        /* disable digital DLL calibration */
        *EMI_CONN &= ~0x00000100;


        /* disable and set the predefined tracking value for 15.36MHz */
        *EMI_DQSA = 0x10101010;

        /* change EMI timing for 15.36MHz */
        *EMI_CONJ = EMI_CONTROL_J_15_36_VAL;
        *EMI_CONL = EMI_CONTROL_L_15_36_VAL;  

        /* switch clock */
        *MCUCLK_CON = 0x0421;
        
        /* wait for clock switched due to sinc with 3.84MHz*/
        while( (*CLK_INFO & 0x7FFF) != 0x0421 );

        /* exist SDRAM self-refresh mode */
        *EMI_CONN &= ~0x00000020;     
        
        /* un-block emi access */
        *EMI_CONM &= ~0x1FF0;     
            
        
    }
    #if 0
    else if (clock == MCU_30_72MHZ)
    {
        /* save DQSA */
        emi_dqsa_122_88mhz = *EMI_DQSA & (~0x80808080);

        /* block emi access */
        *EMI_CONM |= 0x1FF0;

        /* enter SDRAM self-refresh mode */
        *EMI_CONN |= 0x00000020;
        do {
            if ((*EMI_CONN) & 0x00000080) {
                break;
            }
        } while (1);

        /* poll the emi idle status */
        do {
            if ((*CLK_INFO) & 0x00008000) {
                break;
            }
        } while (1);

            
        /* disable digital DLL calibration */
        *EMI_CONN &= ~0x00000100;


        /* disable and set the predefined tracking value for 30.72MHz */
        *EMI_DQSA = 0x10101010;

        /* change EMI timing for 30.72MHz */
        *EMI_CONJ = EMI_CONTROL_J_30_72_VAL;
        *EMI_CONL = EMI_CONTROL_L_30_72_VAL;  


        *MCUCLK_CON = 0x0C63;
        
        /* wait for clock switched due to sinc with 3.84MHz*/
        while( (*CLK_INFO & 0x7FFF) != 0x0C63 );

        /* exist SDRAM self-refresh mode */
        *EMI_CONN &= ~0x00000020;   
        
        /* un-block emi access */
        *EMI_CONM &= ~0x1FF0;                         
    }    
    #endif
    else if (clock == MCU_245_76MHZ)
    {
        /* block emi access */
        *EMI_CONM |= 0x1FF0;

        /* enter SDRAM self-refresh mode */
        *EMI_CONN |= 0x00000020;
        do {
            if ((*EMI_CONN) & 0x00000080) {
                break;
            }
        } while (1);

        /* poll the emi idle status */
        do {
            if ((*CLK_INFO) & 0x00008000) {
                break;
            }
        } while (1);

        /* switch to 122.88MHz */
        *MCUCLK_CON = 0x7DE7;

        /* wait for clock switched due to sinc with 3.84MHz*/
        while( (*CLK_INFO & 0x7FFF) != 0x7DE7 );

        /* change EMI timing for 122.88MHz */
        *EMI_CONJ = EMI_CONTROL_J_122_88_VAL;
        *EMI_CONL = EMI_CONTROL_L_122_88_VAL;

        /* clear digital DLL offset */
        *EMI_CONM = 0x00000000;
            
        /* enable digital DLL calibration */
        *EMI_CONN |= 0x00000100;
        do {
            if (*EMI_CONN & 0x00000200) {
                break;
            }
        } while (1);

        /* set previous tracking value for 122.88MHz */
        /* can not set tracking value and enable tracking at the same time */
        *EMI_DQSA = emi_dqsa_122_88mhz;
            
        /* enable auto-tracking */
        *EMI_DQSA |= 0x80808080;

        /* exist SDRAM self-refresh mode */
        *EMI_CONN &= ~0x00000020;   
        
        /* un-block emi access */
        *EMI_CONM &= ~0x1FF0;           
        
    }

    dcm_status = 0;
 
#endif

#if defined(MT6276)
    if(clock==MCU_650MHZ) // use to restore the normal clock ratio
    {
        *ARM_FSEL = 0x00; // divided by 1
        *DSP_FSEL = 0x00; // divided by 1
        *EMI_FSEL = 0x00; // divided by 1
        *FBUS_FSEL = 0x0F; // 3.84MHz * 32
        *SBUS_FSEL = 0x07; // 3.84MHz * 16

        *DSP_IDLE_FSEL = 0x1F; // divided by 32
        *EMI_IDLE_FSEL = 0x07; // divided by 16
        *FBUS_IDLE_FSEL = 0x01; // 3.84MHz * 4
        *SBUS_IDLE_FSEL = 0x01; // 3.84MHz * 4

        *DCM_RG_CK_DCM_EN1 &= ~0x03; // disable HWDCM
    }
    else if(clock==MCU_20_3125MHZ)
    {
        *ARM_FSEL = 0x00; // divided by 1
        *DSP_FSEL = 0x00; // divided by 1
        *EMI_FSEL = 0x00; // divided by 1
        *FBUS_FSEL = 0x0F; // 3.84MHz * 32
        *SBUS_FSEL = 0x07; // 3.84MHz * 16

        *DSP_IDLE_FSEL = 0x1F; // divided by 32
        *EMI_IDLE_FSEL = 0x07; // divided by 16
        *FBUS_IDLE_FSEL = 0x01; // 3.84MHz * 4
        *SBUS_IDLE_FSEL = 0x01; // 3.84MHz * 4

        *DCM_RG_CK_DCM_EN1 |= 0x03; // enable HWDCM
    }
#if defined(FEATURE_DCM_SSC)
    else if(clock==SSC_NORMAL)
    {
        #if defined( DCM_ENABLE )
        DCM_Disable(SSC_DCM_Handle);
        #endif /* DCM_ENABLE */
        
        *DCM_RG_CK_DCM_EN1 &= ~0x03; // disable HWDCM
        
        *ARM_FSEL = 0x00; // divided by 1
        *DSP_FSEL = 0x00; // divided by 1

        interruptMask = SaveAndSetIRQMask();
        cp15_disable_mmu();
        *EMI_DRCT &= 0xFFFFFFFE;
        *EMI_DQSE &= 0x7FFF0000;
        *EMI_CONM = 0x003F; // block all emi transaction
        *EMI_FSEL = 0x00;   // divided by 1
        
        *EMI_DQSA = 0x20202020;
        *EMI_IDLA = 0x05050505;
        *EMI_IDLB = 0x05050505;
        *EMI_IDLC = 0x05050505;
        *EMI_IDLD = 0x05050505;
        *EMI_IDLE = 0x05050505;
        *EMI_IDLF = 0x05050505;
        *EMI_IDLG = 0x05050505;
        *EMI_IDLH = 0x05050505;
        *EMI_IDLI = 0x03030303;
        
        *EMI_CALA = 0x13131313;
        *EMI_CALE = 0;
        *EMI_CALI = 0x13131313;
        *EMI_CALP = 0x93930000;
        
        *EMI_CONM = 0x0000;
        *EMI_DQSE |= 0x8000FFFF;
        *EMI_DRCT |= 0x00000001;
        cp15_enable_mmu();
        RestoreIRQMask(interruptMask); 
        
        // adjust emi clock frequency for bandwidth calibration under slow idle mode
        *EMI_ABCT = (*EMI_ABCT&0xFFFFFF80); 

        *FBUS_FSEL = 0x0F; // 3.84MHz * 32
        *SBUS_FSEL = 0x07; // 3.84MHz * 16
    }
    else if(clock==SSC_IDLE)
    {
        #if defined( DCM_ENABLE )
        DCM_Disable(SSC_DCM_Handle);
        #endif /* DCM_ENABLE */
        
        *DCM_RG_CK_DCM_EN1 &= ~0x03; // disable HWDCM
        
        *ARM_FSEL = 0x1F; // divided by 32
        *DSP_FSEL = 0x1F; // divided by 32

        interruptMask = SaveAndSetIRQMask();
        cp15_disable_mmu();
        *EMI_DRCT &= 0xFFFFFFFE;
        *EMI_DQSE &= 0x7FFF0000;
        *EMI_CONM = 0x003F; // block all emi transaction
        *EMI_FSEL = 0x0F;   // divided by 1
        
        *EMI_DQSA = 0x08080808;
        *EMI_IDLA = 0x07070707;
        *EMI_IDLB = 0x07070707;
        *EMI_IDLC = 0x07070707;
        *EMI_IDLD = 0x07070707;
        *EMI_IDLE = 0x07070707;
        *EMI_IDLF = 0x07070707;
        *EMI_IDLG = 0x07070707;
        *EMI_IDLH = 0x07070707;
        *EMI_IDLI = 0x1F1F1F1F;
        
        *EMI_CALA = 0x1F1F1F1F;
        *EMI_CALE = 0x03030303;
        *EMI_CALI = 0x1F1F1F1F;
        *EMI_CALP = 0x9F9F0000;
        
        *EMI_CONM = 0x0000;
        *EMI_DQSE |= 0x8000FFFF;
        *EMI_DRCT |= 0x00000001;
        cp15_enable_mmu();
        RestoreIRQMask(interruptMask); 
        
        // adjust emi clock frequency for bandwidth calibration under slow idle mode
        *EMI_ABCT = (*EMI_ABCT&0xFFFFFF80)|0x50; 

        *FBUS_FSEL = 0x01; // 3.84MHz * 4
        *SBUS_FSEL = 0x01; // 3.84MHz * 4
    }
    else if(clock==SSC_MCU_LOW_SPEED1)
    {
        #if defined( DCM_ENABLE )
        DCM_Disable(SSC_DCM_Handle);
        #endif /* DCM_ENABLE */
        
        *DCM_RG_CK_DCM_EN1 &= ~0x03; // disable HWDCM
        
        *ARM_FSEL = 0x03; // divided by 4
        *DSP_FSEL = 0x00; // divided by 1
        
        interruptMask = SaveAndSetIRQMask();
        cp15_disable_mmu();
        *EMI_DRCT &= 0xFFFFFFFE;
        *EMI_DQSE &= 0x7FFF0000;
        *EMI_CONM = 0x003F; // block all emi transaction
        *EMI_FSEL = 0x00;   // divided by 1
        
        *EMI_DQSA = 0x20202020;
        *EMI_IDLA = 0x05050505;
        *EMI_IDLB = 0x05050505;
        *EMI_IDLC = 0x05050505;
        *EMI_IDLD = 0x05050505;
        *EMI_IDLE = 0x05050505;
        *EMI_IDLF = 0x05050505;
        *EMI_IDLG = 0x05050505;
        *EMI_IDLH = 0x05050505;
        *EMI_IDLI = 0x03030303;
        
        *EMI_CALA = 0x13131313;
        *EMI_CALE = 0;
        *EMI_CALI = 0x13131313;
        *EMI_CALP = 0x93930000;
        
        *EMI_CONM = 0x0000;
        *EMI_DQSE |= 0x8000FFFF;
        *EMI_DRCT |= 0x00000001;
        cp15_enable_mmu();
        RestoreIRQMask(interruptMask); 
        
        *FBUS_FSEL = 0x0F; // 3.84MHz * 32
        *SBUS_FSEL = 0x07; // 3.84MHz * 16
    }
    else if(clock==SSC_DSP_LOW_SPEED1)
    {
        #if defined( DCM_ENABLE )
        DCM_Disable(SSC_DCM_Handle);
        #endif /* DCM_ENABLE */
        
        *DCM_RG_CK_DCM_EN1 &= ~0x03; // disable HWDCM
        
        *ARM_FSEL = 0x00; // divided by 1
        *DSP_FSEL = 0x03; // divided by 1
        
        interruptMask = SaveAndSetIRQMask();
        cp15_disable_mmu();
        *EMI_DRCT &= 0xFFFFFFFE;
        *EMI_DQSE &= 0x7FFF0000;
        *EMI_CONM = 0x003F; // block all emi transaction
        *EMI_FSEL = 0x00;   // divided by 1
        
        *EMI_DQSA = 0x20202020;
        *EMI_IDLA = 0x05050505;
        *EMI_IDLB = 0x05050505;
        *EMI_IDLC = 0x05050505;
        *EMI_IDLD = 0x05050505;
        *EMI_IDLE = 0x05050505;
        *EMI_IDLF = 0x05050505;
        *EMI_IDLG = 0x05050505;
        *EMI_IDLH = 0x05050505;
        *EMI_IDLI = 0x03030303;
        
        *EMI_CALA = 0x13131313;
        *EMI_CALE = 0;
        *EMI_CALI = 0x13131313;
        *EMI_CALP = 0x93930000;
        
        *EMI_CONM = 0x0000;
        *EMI_DQSE |= 0x8000FFFF;
        *EMI_DRCT |= 0x00000001;
        cp15_enable_mmu();
        RestoreIRQMask(interruptMask); 

        *FBUS_FSEL = 0x0F; // 3.84MHz * 32
        *SBUS_FSEL = 0x07; // 3.84MHz * 16
    }
    else if(clock==SSC_BUS_LOW_SPEED1)
    {
        #if defined( DCM_ENABLE )
        DCM_Disable(SSC_DCM_Handle);
        #endif /* DCM_ENABLE */
        
        *DCM_RG_CK_DCM_EN1 &= ~0x03; // disable HWDCM
        
        *ARM_FSEL = 0x00; // divided by 1
        *DSP_FSEL = 0x00; // divided by 1

        interruptMask = SaveAndSetIRQMask();
        cp15_disable_mmu();
        *EMI_DRCT &= 0xFFFFFFFE;
        *EMI_DQSE &= 0x7FFF0000;
        *EMI_CONM = 0x003F; // block all emi transaction
        *EMI_FSEL = 0x00;   // divided by 1
        
        *EMI_DQSA = 0x20202020;
        *EMI_IDLA = 0x05050505;
        *EMI_IDLB = 0x05050505;
        *EMI_IDLC = 0x05050505;
        *EMI_IDLD = 0x05050505;
        *EMI_IDLE = 0x05050505;
        *EMI_IDLF = 0x05050505;
        *EMI_IDLG = 0x05050505;
        *EMI_IDLH = 0x05050505;
        *EMI_IDLI = 0x03030303;
        
        *EMI_CALA = 0x13131313;
        *EMI_CALE = 0;
        *EMI_CALI = 0x13131313;
        *EMI_CALP = 0x93930000;
        
        *EMI_CONM = 0x0000;
        *EMI_DQSE |= 0x8000FFFF;
        *EMI_DRCT |= 0x00000001;
        cp15_enable_mmu();
        RestoreIRQMask(interruptMask); 

        *FBUS_FSEL = 0x07; // 3.84MHz * 16
        *SBUS_FSEL = 0x03; // 3.84MHz * 8
    }
    else if(clock==SSC_EMI_LOW_SPEED1)
    {
        #if defined( DCM_ENABLE )
        DCM_Disable(SSC_DCM_Handle);
        #endif /* DCM_ENABLE */
        
        *DCM_RG_CK_DCM_EN1 &= ~0x03; // disable HWDCM
        
        *ARM_FSEL = 0x00; // divided by 1
        *DSP_FSEL = 0x00; // divided by 1

        interruptMask = SaveAndSetIRQMask();
        cp15_disable_mmu();
        *EMI_DRCT &= 0xFFFFFFFE;
        *EMI_DQSE &= 0x7FFF0000;
        *EMI_CONM = 0x003F; // block all emi transaction
        *EMI_FSEL = 0x03;   // divided by 4
        
        *EMI_DQSA = 0x08080808;
        *EMI_IDLA = 0x00000000;
        *EMI_IDLB = 0x00000000;
        *EMI_IDLC = 0x00000000;
        *EMI_IDLD = 0x00000000;
        *EMI_IDLE = 0x00000000;
        *EMI_IDLF = 0x00000000;
        *EMI_IDLG = 0x00000000;
        *EMI_IDLH = 0x00000000;
        *EMI_IDLI = 0x1F1F1F1F;
        
        *EMI_CALA = 0x1F1F1F1F;
        *EMI_CALE = 0x06060606;
        *EMI_CALI = 0x19191919;
        *EMI_CALP = 0x99990000;
        
        *EMI_CONM = 0x0000;
        *EMI_DQSE |= 0x8000FFFF;
        *EMI_DRCT |= 0x00000001;
        cp15_enable_mmu();
        RestoreIRQMask(interruptMask); 
        
        // adjust emi clock frequency for bandwidth calibration under slow idle mode
        *EMI_ABCT = (*EMI_ABCT&0xFFFFFF80)|0x84; 

        *FBUS_FSEL = 0x0F; // 3.84MHz * 32
        *SBUS_FSEL = 0x07; // 3.84MHz * 16
    }
    else if(clock==SSC_COMBINATION)
    {
        #if defined( DCM_ENABLE )
        DCM_Disable(SSC_DCM_Handle);
        #endif /* DCM_ENABLE */
        
        *DCM_RG_CK_DCM_EN1 &= ~0x03; // disable HWDCM
        
        *ARM_FSEL = 0x03; // divided by 1
        *DSP_FSEL = 0x03; // divided by 1

        interruptMask = SaveAndSetIRQMask();
        cp15_disable_mmu();
        *EMI_DRCT &= 0xFFFFFFFE;
        *EMI_DQSE &= 0x7FFF0000;
        *EMI_CONM = 0x003F; // block all emi transaction
        *EMI_FSEL = 0x03;   // divided by 1
        
        *EMI_DQSA = 0x08080808;
        *EMI_IDLA = 0x00000000;
        *EMI_IDLB = 0x00000000;
        *EMI_IDLC = 0x00000000;
        *EMI_IDLD = 0x00000000;
        *EMI_IDLE = 0x00000000;
        *EMI_IDLF = 0x00000000;
        *EMI_IDLG = 0x00000000;
        *EMI_IDLH = 0x00000000;
        *EMI_IDLI = 0x1F1F1F1F;
        
        *EMI_CALA = 0x1F1F1F1F;
        *EMI_CALE = 0x06060606;
        *EMI_CALI = 0x19191919;
        *EMI_CALP = 0x99990000;
        
        *EMI_CONM = 0x0000;
        *EMI_DQSE |= 0x8000FFFF;
        *EMI_DRCT |= 0x00000001;
        cp15_enable_mmu();
        RestoreIRQMask(interruptMask); 
        
        // adjust emi clock frequency for bandwidth calibration under slow idle mode
        *EMI_ABCT = (*EMI_ABCT&0xFFFFFF80)|0x84; 

        *FBUS_FSEL = 0x07; // 3.84MHz * 32
        *SBUS_FSEL = 0x03; // 3.84MHz * 16
    }
    else if(clock==SSC_MCU_LOW_SPEED2)
    {
        #if defined( DCM_ENABLE )
        DCM_Disable(SSC_DCM_Handle);
        #endif /* DCM_ENABLE */
        
        *DCM_RG_CK_DCM_EN1 &= ~0x03; // disable HWDCM
        
        *ARM_FSEL = 0x07; // divided by 1
        *DSP_FSEL = 0x00; // divided by 1

        interruptMask = SaveAndSetIRQMask();
        cp15_disable_mmu();
        *EMI_DRCT &= 0xFFFFFFFE;
        *EMI_DQSE &= 0x7FFF0000;
        *EMI_CONM = 0x003F; // block all emi transaction
        *EMI_FSEL = 0x00;   // divided by 1
        
        *EMI_DQSA = 0x20202020;
        *EMI_DQSE = 0x0;
        *EMI_IDLA = 0x05050505;
        *EMI_IDLB = 0x05050505;
        *EMI_IDLC = 0x05050505;
        *EMI_IDLD = 0x05050505;
        *EMI_IDLE = 0x05050505;
        *EMI_IDLF = 0x05050505;
        *EMI_IDLG = 0x05050505;
        *EMI_IDLH = 0x05050505;
        *EMI_IDLI = 0x03030303;
        
        *EMI_CALA = 0x13131313;
        *EMI_CALE = 0;
        *EMI_CALI = 0x13131313;
        *EMI_CALP = 0x93930000;
        
        *EMI_CONM = 0x0000;
        *EMI_DQSE |= 0x8000FFFF;
        *EMI_DRCT |= 0x00000001;
        cp15_enable_mmu();
        RestoreIRQMask(interruptMask); 

        *FBUS_FSEL = 0x0F; // 3.84MHz * 32
        *SBUS_FSEL = 0x07; // 3.84MHz * 16
    }
    for(delay=0; delay<10000; delay++);

#endif /* FEATURE_DCM_SSC */

#endif /* MT6276 */
__TEMPLATE__
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body specific for MT6236
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_36
{
    my $template = <<"__TEMPLATE__";
#if defined(MT6236) || defined(MT6236B)

    dcm_status = 1;
    eco_version = INT_ecoVersion();

    if (clock == MCU_13MHZ) 
    {
#if defined(_NAND_FLASH_BOOTING_)
        /**
           * save the enabled DQSA. we assume only one RANK of DRAM will be enabled at a time.
           */
        if (0x0 != *EMI_DQSA)
        {
           emi_dqsa_312mhz = *EMI_DQSA & (~0x80808080);
        }
        else if(0x0 != *EMI_DQSB)
        {
           emi_dqsb_312mhz = *EMI_DQSB & (~0x80808080);
        }
        else
        {
           ASSERT(0);
        }
#endif /* _NAND_FLASH_BOOTING_ */

        /**
          * Block emi access during our clock switch.
          */
        *EMI_CONM |= 0x1FF0;

#if defined(_NAND_FLASH_BOOTING_)
        /** 
           * enter SDRAM self-refresh mode to prevent any commands being issued during our EMI settings change.
           */
        *EMI_CONN |= 0x00000020;
        do 
        {
            if ((*EMI_CONN) & 0x00000080) 
            {
                break;
            }
        } while (1);
#endif /* _NAND_FLASH_BOOTING_ */

        /** 
          * Poll the emi idle status to make sure all previous commands have been flushed and EMI goes to idle.
          */
        do {
            if ((*CLK_INFO) & 0x0100) 
            {
                break;
            }
        } while (1);

#if defined(_NAND_FLASH_BOOTING_)            
        /**
           * disable digital DLL calibration 
           */
        *EMI_CONN &= ~0x00000100;

        /**
           * set digital DLL offset, no need anymore.
           */
        //*EMI_CONM = 0xEEEE0000;

        /**
           * disable and set the predefined tracking value for 13MHz 
           */
        if(emi_dqsa_312mhz != 0x0)
        {
            *EMI_DQSA = 0x10101010;
        }
        else if(emi_dqsb_312mhz != 0x0)
        {
            *EMI_DQSB = 0x10101010;
        }
        else
        {
            ASSERT(0);
        }

        /** 
           * change EMI timing for slow clock speed.
           */
        *EMI_CONJ = EMI_CONTROL_J_13_VAL;
        *EMI_CONL = EMI_CONTROL_L_13_VAL;
#endif /* _NAND_FLASH_BOOTING_ */

        /**
          * enter enh SW DCM
          */
        //*GCLOCK_CON |= 0xC0; /* skip enhanced SW DCM */

        /**
          * Switch to 13MHz clock.
          */
        *MCUCLK_CON = 0x0000;
        
        /**
          * Wait for clock switched for synchronization. 
          */
        while((*CLK_INFO & 0x1F) != 0x00);

#if !defined(_NAND_FLASH_BOOTING_)
        
        /**
          * Change EMI setting for 13MHz
          */
        if(eco_version == ECO_E2) // 1T path (PF38F5060M0Y3DG)
        {
            /*NOR*/
            *EMI_CONA = 0xA8A00021; 
            *EMI_CONE = 0x29405000;          
        
            /*PSRAM*/  
            *EMI_CONB = 0xA0000000; 
            *EMI_CONF = 0xB2405010;
        }
        else
        {
            /*NOR*/
            *EMI_CONA = EMI_CONA_BURST_13MHZ; 
            *EMI_CONE = EMI_CONE_BURST_13MHZ;          
        
            /*PSRAM*/  
            *EMI_CONB = EMI_CONB_BURST_13MHZ; 
            *EMI_CONF = EMI_CONF_BURST_13MHZ;         
        }

#endif /* !_NAND_FLASH_BOOTING_ */

#if defined(_NAND_FLASH_BOOTING_)
        /**
           * exist SDRAM self-refresh mode 
           */
        *EMI_CONN &= ~0x00000020;
#endif /* _NAND_FLASH_BOOTING_ */
        
        /**
          * Un-block emi access so that EMI could accept access again. 
          */
        *EMI_CONM &= ~0x1FF0;                
    }
    else if (clock == MCU_312MHZ)
    {
        /**
          * Block emi access during our clock switch.
          */
        *EMI_CONM |= 0x1FF0;

#if defined(_NAND_FLASH_BOOTING_)
        /** 
           * enter SDRAM self-refresh mode to prevent any commands being issued during our EMI settings change.
           */
        *EMI_CONN |= 0x00000020;
        do 
        {
            if ((*EMI_CONN) & 0x00000080) 
            {
                break;
            }
        } while (1);
#endif /* _NAND_FLASH_BOOTING_ */

        /** 
          * Poll the emi idle status to make sure all previous commands have been flushed and EMI goes to idle.
          */
        do {
            if ((*CLK_INFO) & 0x0100) 
            {
                break;
            }
        } while (1);

#if !defined(_NAND_FLASH_BOOTING_)

        /**
          * Change EMI setting for 104MHz
          */
        if(eco_version == ECO_E2) // 1T path (PF38F5060M0Y3DG)
        {
            /*NOR*/
            *EMI_CONA = 0xA8A00021; 
            *EMI_CONE = 0x29C05000;          
        
            /*PSRAM*/  
            *EMI_CONB = 0xA0000000; 
            *EMI_CONF = 0xB4405088;
        }
        else
        {
            /*NOR*/
            *EMI_CONA = EMI_CONA_BURST_104MHZ; 
            *EMI_CONE = EMI_CONE_BURST_104MHZ;          
        
            /*PSRAM*/  
            *EMI_CONB = EMI_CONB_BURST_104MHZ; 
            *EMI_CONF = EMI_CONF_BURST_104MHZ;         
        }

#endif /* !_NAND_FLASH_BOOTING_ */

        /**
          * leave enh SW DCM
          */
        //*GCLOCK_CON &= ~0xC0; /* skip enhanced SW DCM */

        /**
          * Switch to 312MHz clock.
          */
        *MCUCLK_CON = 0x2000;

        /**
          * Wait for clock switched for synchronization. 
          */
        while((*CLK_INFO & 0x1F) != 0x08);

#if defined(_NAND_FLASH_BOOTING_)
        /** 
           * change EMI timing for fast clock speed.
           */
        *EMI_CONJ = EMI_CONTROL_J_104_VAL;
        *EMI_CONL = EMI_CONTROL_L_104_VAL;

        /**
           * clear digital DLL offset.
           */
        *EMI_CONM = 0x00000000;

        /**
           * enable digital DLL calibration.
           */
        *EMI_CONN |= 0x00000100;
        do 
        {
            if (*EMI_CONN & 0x00000200) 
            {
                break;
            }
        } while (1);

        /**
           * set previous tracking value for 312MHz, note that we can not set tracking value and enable tracking at the same time.
           */
        if(emi_dqsa_312mhz != 0x0)
        {
            *EMI_DQSA = emi_dqsa_312mhz;
            *EMI_DQSA |= 0x80808080;
            emi_dqsa_312mhz = 0;
        }
        else if(emi_dqsb_312mhz != 0x0)
        {
            *EMI_DQSB = emi_dqsb_312mhz;
            *EMI_DQSB |= 0x80808080;
            emi_dqsb_312mhz = 0;
        }
        else
        {
            ASSERT(0);
        }
           
        /**
           * exist SDRAM self-refresh mode 
           */
        *EMI_CONN &= ~0x00000020;   
#endif /* _NAND_FLASH_BOOTING_ */

        /**
          * Un-block emi access so that EMI could accept access again. 
          */
        *EMI_CONM &= ~0x1FF0;                   
    }
    else
    {
        /**
          * Unsupported MCU clock 
          */
        return -1;
    }

    dcm_status = 0;

    return 0;

#endif  /* MT6236 || MT6236B */
__TEMPLATE__
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body specific for MT6251
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_51
{
    my $template = <<"__TEMPLATE__";
  // custom_SFIDynamicClockSwitch(clock);

//#if 0  
#if defined(MT6251)

   /* See if HW is still processing the previous clock change*/
   while ((*LYR2_EMPTY & 0x8000) == 0x8000);

  /* Force AHB-L2 enters idle status and pends its request. */
   *LYR2_EMPTY_EN = *LYR2_EMPTY_EN | 0x0001;

   // see if DCM controller is still busy for previous DCM setting.
   //while ((*LYR2_EMPTY & 0x8000) == 0x8000); // revised by conan @ 20080625: In SW control, MSB and LSB are equivalent
   while ((*LYR2_EMPTY & 0x0001) == 0x0); // Revised by Chris on 20080711:

   while ((*SF_MISC_CTL & 0x0010) == 0x0);//wait until SF idle is true

   switch (clock)
   {
      case MCU_78MHZ:
         /* switch MODEM clock to78MHz (default), ARM clock to 78MHz, MCU clock to 78MHz*/
     *PLL_CON6 = 0xC000; //enable dcm, div set
         break;

      case MCU_13MHZ:
         /* switch MODEM clock to 13MHz (default), ARM clock to 13MHz, MCU clock to 13MHz*/
         *PLL_CON6 = 0xF000; //enable dcm, div set
         break;

      default:
         return -1;
   }


      /* SHK: Clear the AHB-L2 pending. */
     *LYR2_EMPTY_EN = *LYR2_EMPTY_EN & 0xfffe;

#endif
__TEMPLATE__
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body specific for MT6235/MT6238
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_LPSDRAM_3538
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL) = @_;
    my $template;
    if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235' || $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235B')
    {
       $template = <<"__TEMPLATE";
#if (defined(MT6235) || defined(MT6235B))

   if(ECO_E5 >= INT_ecoVersion())
   {
       /* apply UART data error with DCM enable SW workaround */
       dcm_sw_workaround = KAL_TRUE;
   }

   /* From this point, all access to EMI (L1/2/3/4) will be blocked/pending by EMI. */
   switch (clock)
   {
      case MCU_208MHZ:
            /* enable SDRAM self-refresh mode */
            *EMI_CONN |= 0x00000020;

            /*
             * NoteXXX: MT6235 EMI doesn't support status polling for self-refresh mode.
             *          We need to wait for 100T via the busy loop.
            */
            for (delay = 0; delay < 100; delay++) {}

            if(dcm_sw_workaround)
            {
                /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
                /* switch EMI to 104MHz and ARM to 208MHz first */
                *MCUCLK_CON = 0x7f00;
                /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
                     The loop length must be altered once the switching period is larger than 208M<->13M. 
                     The loop is unnecessary here because since MT6235/38 platforms are switch aligned to 13M boundary. */
                //for (delay = 0; delay < 8; delay++) {}
                /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
            }
    
            /* change EMI timing for 104MHz */
            *EMI_CONJ = EMI_CONTROL_J_104_VAL;
            *EMI_CONK = EMI_CONTROL_K_104_VAL;
            *EMI_CONL = EMI_CONTROL_L_104_VAL;
            *EMI_CONM = EMI_CONTROL_M_104_VAL;

            *EMI_GENA &= 0x3;
            *EMI_GENA |= (EMI_GENERAL_A_104_VAL & 0xFFFFFFFC);
            *EMI_GENB = EMI_GENERAL_B_104_VAL;
            *EMI_GENC = EMI_GENERAL_C_104_VAL;

            /* switch BUS to 104MHz */
            *MCUCLK_CON = 0x7f37;
         
            /* disable SDRAM self-refresh mode */
            *EMI_CONN &= ~0x00000020;
            /* The wait for exit of DRAM self-refresh mode can be bypassed on MT6235/38 platform. For 
               rest platform, consult with designers. */
//#if (defined(MT6235) || defined(MT6235B))
            //for (delay = 0; delay < 100; delay++) {}
//#elif  (defined(MT6238) || defined(MT6239))   
            //while ((*(volatile kal_uint32 *)0x81000068 & 0x00000080)){}
//#endif
         break;

      case MCU_13MHZ:

            if(dcm_sw_workaround)
            {
                /* switc BUS to 13MHz first */
                *MCUCLK_CON = 0x7f00;
         
                /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
                     The loop length must be altered once the switching period is larger than 208M<->13M. */
                for (delay = 0; delay < 8; delay++) {}
                /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
            }
            
            /* enable SDRAM self-refresh mode */
            *EMI_CONN |= 0x00000020;

            /*
             * NoteXXX: MT6235 EMI doesn't support status polling for self-refresh mode.
             *          We need to wait for 100T via the busy loop.
            */
            for (delay = 0; delay < 100; delay++) {}
    
            /* switch EMI and ARM to 13MHz */
            *MCUCLK_CON = 0x0000;

            /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
                 The loop length must be altered once the switching period is larger than 208M<->13M. */
            for (delay = 0; delay < 8; delay++) {}
            /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
            
            /* change EMI timing for 13MHz */
            *EMI_CONJ = EMI_CONTROL_J_13_VAL;
            *EMI_CONK = EMI_CONTROL_K_13_VAL;
            *EMI_CONL = EMI_CONTROL_L_13_VAL;
            *EMI_CONM = EMI_CONTROL_M_13_VAL;

            *EMI_GENA &= 0x3;
            *EMI_GENA |= (EMI_GENERAL_A_13_VAL & 0xFFFFFFFC);
            *EMI_GENB = EMI_GENERAL_B_13_VAL;
            *EMI_GENC = EMI_GENERAL_C_13_VAL;

            /* disable SDRAM self-refresh mode */
            *EMI_CONN &= ~0x00000020;
            /* The wait for exit of DRAM self-refresh mode can be bypassed on MT6235/38 platform. For 
               rest platform, consult with designers. */
//#if (defined(MT6235) || defined(MT6235B))
            //for (delay = 0; delay < 100; delay++) {}
//#elif  (defined(MT6238) || defined(MT6239))   
            //while ((*(volatile kal_uint32 *)0x81000068 & 0x00000080)){}
//#endif
         break;

      default:
         return -1;
   }

   return 0;
#endif   /* MT6235 || || MT6235B */    
__TEMPLATE
    }
    else
    {
        $template = <<"__TEMPLATE";
__TEMPLATE
    }

    return $template;
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body specific for MT6235/MT6238
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_NORRAMMCP_SYNC_3538
{
    ###
    my $template = <<"__TEMPLATE";
#if (defined(MT6235) || defined(MT6235B))
   switch (clock) 
   {
      case MCU_208MHZ:
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         *MCUCLK_CON = 0x7F37;
         /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
              The loop length must be altered once the switching period is larger than 208M<->13M. 
              The loop is unnecessary here because since MT6235/38 platforms are switch aligned to 13M boundary. */
         //for (delay = 0; delay < 8; delay++) {}
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         
         break;
    
      case MCU_104MHZ:
         *MCUCLK_CON = 0x7737;
         /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
              The loop length must be altered once the switching period is larger than 208M<->13M. */
         for (delay = 0; delay < 8; delay++) {}
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         
         break;
    
      case MCU_52MHZ:
         *MCUCLK_CON = 0x3333;
         /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
              The loop length must be altered once the switching period is larger than 208M<->13M. */
         for (delay = 0; delay < 8; delay++) {}
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         
         break;

      case MCU_26MHZ:
         *MCUCLK_CON = 0x1111;
         /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
              The loop length must be altered once the switching period is larger than 208M<->13M. */
         for (delay = 0; delay < 8; delay++) {}
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         
         break;
    
      case MCU_13MHZ:     
         *MCUCLK_CON = 0x0000;
         /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
              The loop length must be altered once the switching period is larger than 208M<->13M. */
         for (delay = 0; delay < 8; delay++) {}
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         
         break;
    
      default:
         return -1;
   }   

   return 0;
#endif   /* MT6235 || MT6235B */
__TEMPLATE
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body specific for MT6235/MT6238
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_NORRAMMCP_SYNC_53_after
{
    ###
    my $template = <<"__TEMPLATE";
#if defined(MT6253)
   volatile static unsigned int tmp;
   kal_uint32 saved_cache_con, saved_prefetch_con;
   
   /**
     * See if HW is still processing the previous clock change.
     */
   while ((*LYR2_EMPTY & 0x8000) == 0x8000);

   /** 
     * Force AHB-L2 enters idle status and pends its request. 
     */
   *LYR2_EMPTY_EN = *LYR2_EMPTY_EN | 0x0001;

   /** 
     * See if DCM controller is still busy for previous DCM setting. 
     */
   while ((*LYR2_EMPTY & 0x0001) == 0x0); 

    /**
      * Backup L1 and EMI cache/prefetch setting.
      */
    saved_cache_con = *CACHE_CON;
    saved_prefetch_con = *PREFETCH_CON;

    /**
      * Disable L1 and EMI cache/prefetch setting.
      */
    *CACHE_CON &= ~(0x000d); 
    *PREFETCH_CON &= ~(0x10001); 

   /** 
     * Dummy read to make sure all previous command queued in the EMI controller itself has been flushed.
     */
   tmp = *(volatile unsigned int*)0x0;

   switch (clock) 
   {
      case MCU_104MHZ:
         /**
           * Switch MODEM clock to 52MHz (default), ARM/EMI clock to 104MHz, MCU/BUS clock to 52MHz.
           */
         *MCUCLK_CON = 0x3783;

         /**
           * Polling to see if MCU/BUS ratio becomes 2:1 && EMI clock has already switched to 104M.
           */
         while(((*ARB_1T_EN & 0x8000) == 0x8000) || ((*ARB_1T_EN & 0x4000) == 0x0));

         break;

      case MCU_52MHZ:
         /**
           * Switch MODEM clock to 52MHz (default), ARM/EMI clock to 52MHz, MCU/BUS clock to 52MHz.
           */
         *MCUCLK_CON = 0x3383;

         /**
           * Polling to see if MCU/BUS ratio becomes 1:1 && EMI clock has already switched to 52M.
           */
         while(((*ARB_1T_EN & 0x8000) == 0x0) || ((*ARB_1T_EN & 0x2000) == 0x0));

         break;


      case MCU_13MHZ:     
         /**
           * Switch MODEM clock to 13MHz (default), ARM/EMI clock to 13MHz, MCU/BUS clock to 13MHz.
           */
         *MCUCLK_CON = 0x3080;

         /**
           * Polling to see if MCU/BUS ratio becomes 1:1 && EMI clock has already switched to 13M.
           */
         while((*ARB_1T_EN & 0x8000) == 0 || (*ARB_1T_EN & 0x1000) == 0);

         break;

      default:
         return -1;
   }   

    /**
      * delay for a while.
      */
    for (delay = 0; delay < 8; delay++)
    {
           /* NOP */
    }

      /**
        * Find the correct NEGSEL of BANK0.
        */
     if (nor_compare_pattern != EMI_COMPARE_PATTERN)
     {
        /** 
           * Toggle NEGSEL in EMI Clock Delay Register.
           */
          if(*EMI_CLOCKDEL & (0x1 << BANK0_NEGSEL_p)) 
          {
            /**
               * If the bit associate with specified bank is 1, then switch to 0.
               */
              *EMI_CLOCKDEL &= ~(0x1 << BANK0_NEGSEL_p);
          }
          else 
          {
            /**
               * If the bit associate with specified bank is 0, then switch to 1.
               */
              *EMI_CLOCKDEL |= (0x1 << BANK0_NEGSEL_p);
          }
     }    
         
    /**
       * Find the correct NEGSEL of BANK1.
       */
     if (psram_compare_pattern != EMI_COMPARE_PATTERN)
     {
        /**
           * Toggle NEGSEL in EMI Clock Delay Register.
           */
          if(*EMI_CLOCKDEL & (0x1 << BANK1_NEGSEL_p)) 
          {
            /** 
               * If the bit associate with specified bank is 1, then switch to 0.
               */
              *EMI_CLOCKDEL &= ~(0x1 << BANK1_NEGSEL_p);
          }
          else 
          {
            /** 
               * If the bit associate with specified bank is 0, then switch to 1.
               */
              *EMI_CLOCKDEL |= (0x1 << BANK1_NEGSEL_p);
          }
     }

     /** 
       * Restore L1 and EMI cache/prefetch setting.
       */
    *PREFETCH_CON = saved_prefetch_con;
    *CACHE_CON = saved_cache_con;
   
    /**
      * Clear the AHB-L2 pending. 
      */
    *LYR2_EMPTY_EN = *LYR2_EMPTY_EN & 0xfffe;

   return 0;
      
#endif   /* MT6253 */

#if (defined(MT6252H) || defined(MT6252))
   volatile static unsigned int tmp;

   /**
     * See if HW is still processing the previous clock change.
     */
   while ((*LYR2_EMPTY & 0x8000) == 0x8000);

   /** 
     * Force AHB-L2 enters idle status and pends its request. 
     */
   *LYR2_EMPTY_EN = *LYR2_EMPTY_EN | 0x0001;

   /** 
     * See if DCM controller is still busy for previous DCM setting. 
     */
   while ((*LYR2_EMPTY & 0x0001) == 0x0); 

   /** 
     * Dummy read to make sure all previous command queued in the EMI controller itself has been flushed.
     */
   tmp = *(volatile unsigned int*)0x20000000;

   switch (clock) 
   {
      case MCU_104MHZ:

         #if defined(MT6252)
         custom_SFIDynamicClockSwitch(clock);
         #endif 
         
         /**
           * Switch MODEM clock to 52MHz (default), ARM/EMI clock to 104MHz, MCU/BUS clock to 52MHz.
           */
         *MCUCLK_CON = 0x3181;  /* hw bug: prevent from glitch */
         *MCUCLK_CON = 0x3783;

         /**
           * Polling to see if MCU/BUS ratio becomes 2:1 && EMI clock has already switched to 104M.
           */
         while(((*ARB_1T_EN & 0x8000) == 0x8000) || ((*ARB_1T_EN & 0x4000) == 0x0));

         break;

      case MCU_52MHZ:
        
         #if defined(MT6252)
         custom_SFIDynamicClockSwitch(clock);
         #endif 
         
         /**
           * Switch MODEM clock to 52MHz (default), ARM/EMI clock to 52MHz, MCU/BUS clock to 52MHz.
           */
         *MCUCLK_CON = 0x3181; /* hw bug: prevent from glitch */
         *MCUCLK_CON = 0x3383;

         /**
           * Polling to see if MCU/BUS ratio becomes 1:1 && EMI clock has already switched to 52M.
           */
         while(((*ARB_1T_EN & 0x8000) == 0x0) || ((*ARB_1T_EN & 0x2000) == 0x0));

         break;


      case MCU_13MHZ:   

         #if defined(MT6252)
         custom_SFIDynamicClockSwitch(clock);
         #endif 
        
         /**
           * Switch MODEM clock to 13MHz (default), ARM/EMI clock to 13MHz, MCU/BUS clock to 13MHz.
           */
         *MCUCLK_CON = 0x3181; /* hw bug: prevent from glitch */
         *MCUCLK_CON = 0x3080;

         /**
           * Polling to see if MCU/BUS ratio becomes 1:1 && EMI clock has already switched to 13M.
           */
         while((*ARB_1T_EN & 0x8000) == 0 || (*ARB_1T_EN & 0x1000) == 0);

         break;

      default:
         return -1;
   }   
   
    /**
      * Clear the AHB-L2 pending. 
      */
    *LYR2_EMPTY_EN = *LYR2_EMPTY_EN & 0xfffe;

   return 0;
            
#endif   /* MT6252H || MT6252 */

__TEMPLATE
}

#****************************************************************************
# subroutine:  FuncBody_custom_dynamicclockswitch_SYNC
# return:      template for "FUNCTION custom_DynamicClockSwitch()"
#              for non-LPSDRAM and non Burst Mode NOR_RAM_MCP
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_SYNC
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL) = @_;
    ###
    my $dcm_FuncBody;
    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235B') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6238') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6239'))
    {
        $dcm_FuncBody = &FuncBody_custom_dynamicclockswitch_NORRAMMCP_SYNC_3538();
    }
    elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6253') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252'))
    {
        $dcm_FuncBody = &FuncBody_custom_dynamicclockswitch_NORRAMMCP_SYNC_53_after();
    }
    elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236B') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6921'))
    {
        $dcm_FuncBody = &FuncBody_custom_dynamicclockswitch_36();
    }
    elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6251')
    {
        $dcm_FuncBody = &FuncBody_custom_dynamicclockswitch_51();
    }

    my $template = <<"__TEMPLATE";
   register kal_uint32 delay;

/**
  * The DCM switch process is a highly-DCM-design-dependent flow, so we will wrap the whole flow with the whole chip options.
  */

$dcm_FuncBody

   /* unsupported MCU clock */
   return -1;

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  FuncBody_custom_dynamicclockswitch_default
# return:      template for "FUNCTION custom_DynamicClockSwitch()"
#              for non-LPSDRAM and non Burst Mode NOR_RAM_MCP
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_default
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL) = @_;
    ###
    my $dcm_others = <<"__TEMPLATE";
   if (clock == MCU_104MHZ) {

      /* restore EMI A */
      *(volatile kal_uint32 *)EMI_CONA = saved_emi_a;

      /* restore EMI B */
      *(volatile kal_uint32 *)EMI_CONB = saved_emi_b;

      /* switch clock to 104MHz */
      *MCUCLK_CON = 0x0703;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

      return 0;

   } else if (clock == MCU_52MHZ) {

      /* restore EMI A */
      *(volatile kal_uint32 *)EMI_CONA = saved_emi_a;

      /* restore EMI B */
      *(volatile kal_uint32 *)EMI_CONB = saved_emi_b;

      /* switch clock to 52MHz */
      *MCUCLK_CON = 0x0303;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

      return 0;

   } else if (clock == MCU_26MHZ) {

      /* save EMI A */
      saved_emi_a = *EMI_CONA;

      /* save EMI B */
      saved_emi_b = *EMI_CONB;

      /* switch clock to 26MHz */
      *MCUCLK_CON = 0x0101;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

#if ( defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) || defined(MT6223D) || defined(MT6226) || defined(MT6226M) || defined(MT6227) )
      /* set EMI A */
      *EMI_CONA = 0x44004405;
      /* set EMI B */
      *EMI_CONB = 0x44004405;
#else /* MT6223 || MT6223P || MT6227D || MT6226D || MT6223D || MT6226 || MT6226M || MT6227 */
      /* set EMI A */
      *EMI_CONA = 0x20404405;
      /* set EMI B */
      *EMI_CONB = 0x20404405;    
#endif /* MT6223 || MT6223P || MT6227D || MT6226D || MT6223D || MT6226 || MT6226M || MT6227 */

      return 0;

   } else if (clock == MCU_13MHZ) {

      /* save EMI A */
      saved_emi_a = *EMI_CONA;

      /* save EMI B */
      saved_emi_b = *EMI_CONB;

      /* switch clock to 13MHz */
      *MCUCLK_CON = 0x0000;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

#if ( defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) || defined(MT6223D) || defined(MT6226) || defined(MT6226M) || defined(MT6227) )
      /* set EMI A */
      *EMI_CONA = 0x44004203;
      /* set EMI B */
      *EMI_CONB = 0x44004203;      
#else /* MT6223 || MT6223P || MT6227D || MT6226D || MT6223D || MT6226 || MT6226M || MT6227 */
      /* set EMI A */
      *EMI_CONA = 0x20404203;
      /* set EMI B */
      *EMI_CONB = 0x20404203;   
#endif /* MT6223 || MT6223P || MT6227D || MT6226D || MT6223D || MT6226 || MT6226M || MT6227 */

      return 0;

   } else {

      /* unsupported MCU clock */

      return -1;
   }
__TEMPLATE

    ###
    my $dcm_FuncBody;
    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235B') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6238') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6239'))
    {
        if ( ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
           && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'ASYNC_ACCESS') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{RAM_ACCESS_TYPE} eq 'ASYNC_ACCESS') )
        {
            $dcm_FuncBody = &FuncBody_custom_dynamicclockswitch_NORRAMMCP_ASYNC_3538();
        }
    }
    else
    {
        $dcm_FuncBody = $dcm_others;
    }
    
    my $template = <<"__TEMPLATE";

   register kal_uint32 delay;

$dcm_FuncBody

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body specific for MT6235/MT6238
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_NORRAMMCP_ASYNC_3538
{
    my $template = <<"__TEMPLATE";
#if (defined(MT6235) || defined(MT6235B))
   switch (clock) 
   {
      case MCU_208MHZ:
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         *MCUCLK_CON = 0x7F37;
         /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
              The loop length must be altered once the switching period is larger than 208M<->13M. 
              The loop is unnecessary here because since MT6235/38 platforms are switch aligned to 13M boundary. */
         //for (delay = 0; delay < 8; delay++) {}
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         
         break;
    
      case MCU_104MHZ:
         *MCUCLK_CON = 0x7737;
         /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
              The loop length must be altered once the switching period is larger than 208M<->13M. */
         for (delay = 0; delay < 8; delay++) {}
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         
         break;
    
      case MCU_52MHZ:
         *MCUCLK_CON = 0x3333;
         /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
              The loop length must be altered once the switching period is larger than 208M<->13M. */
         for (delay = 0; delay < 8; delay++) {}
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         
         break;

      case MCU_26MHZ:
         *MCUCLK_CON = 0x1111;
         /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
              The loop length must be altered once the switching period is larger than 208M<->13M. */
         for (delay = 0; delay < 8; delay++) {}
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         
         break;
    
      case MCU_13MHZ:     
         *MCUCLK_CON = 0x0000;
         /* Switch the clock. Note that the sattle down of the clock between 208M<->13M should wait as least 208/13=8T. 
              The loop length must be altered once the switching period is larger than 208M<->13M. */
         for (delay = 0; delay < 8; delay++) {}
         /* This op might cause ARM MMU fecth corresponding page table from EMI, to prevent this, we have to lock this reg_base on TLB. */
         
         break;
    
      default:
         return -1;
   }   

   return 0;
#endif   /* MT6235 || MT6235B */
__TEMPLATE
}

#****************************************************************************
# subroutine:  custom_EMI_release_h_file_body
# return:      
#****************************************************************************
sub custom_EMI_release_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL) = @_;
    ###
    my %EMI_DEV_MODE_NAND_DRAM = 
    (       
        '0'  => '__EMI_DEVICE_MODE_SDR16__',  #0b00
        '1'  => '__EMI_DEVICE_MODE_SDR32__',  #0b01
        '2'  => '__EMI_DEVICE_MODE_DDRI16__', #0b10
        '3'  => '__EMI_DEVICE_MODE_DDRI32__', #0b11
    );

    ###
    my %EMI_DEV_MODE_NOR_PSRAM = 
    (       
        #'0'  => '__EMI_DEVICE_MODE_BURST__', #0b0
        '1'  => '__EMI_DEVICE_MODE_BURST__',  #0b1
    );
    
    ###
    my %EMI_DEV_MODE_NOR_PSRAM_LV2 = 
    (       
        '0'  => '__EMI_DEVICE_MODE_ASYNC__', #0b0
        '1'  => '__EMI_DEVICE_MODE_PAGE__',  #0b1
    );
    
    ###
    my $emi_clk_str;
    if (((($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'SYNC_ACCESS') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{RAM_ACCESS_TYPE} eq 'SYNC_ACCESS')) or ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') or ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')or ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6280')) and (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'})!=1))
    {
        $emi_clk_str = sprintf("#define __EMI_CLK_%sMHZ__", $emi_clk_config_LOCAL);
        if ($emi_clk_str =~ /\./)
        {
            $emi_clk_str =~ s/\./_/;
        }
    }
    
    ###
    my $emi_device_mode;
    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236B') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6921'))
    {
        if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
        {
            my $dram_conn = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG(1, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
            my $emi_device_mode_bits = (hex($dram_conn) << (31-17)) >> (32-2);
            $emi_device_mode = "#define " . $EMI_DEV_MODE_NAND_DRAM{$emi_device_mode_bits};
        }
        elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
        {
            my @psram_setting_list_6236 = &split_emi(&Lookup_SYNC_EMI_setting_by_IDX_CS_CLK_BB(1, 1, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my $emi_device_mode_bits = (hex($psram_setting_list_6236[1]) << (31-29)) >> (32-1);
            if (defined $EMI_DEV_MODE_NOR_PSRAM{$emi_device_mode_bits})
            {
                $emi_device_mode = "#define " . $EMI_DEV_MODE_NOR_PSRAM{$emi_device_mode_bits};
            }
            else
            {
                my $emi_conb_async_36;
                if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236B'))
                {
                    $emi_conb_async_36 = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6236 MT6236B'};
                }
                elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6921')
                {
                    $emi_conb_async_36 = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6921'};
                }
                $emi_device_mode_bits = (hex($emi_conb_async_36) << (31-26)) >> (32-1);
                $emi_device_mode = "#define " . $EMI_DEV_MODE_NOR_PSRAM_LV2{$emi_device_mode_bits};
            }
        }
    }
    elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
    {
        $emi_device_mode = "#define __EMI_DEVICE_MODE_BURST__";
    }
     elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
    {
        if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
    	{
    		$emi_device_mode = "#define __EMI_DEVICE_LPDDR1__";
    	}
    	elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
    	{
    		 if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'SYNC_ACCESS') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{RAM_ACCESS_TYPE} eq 'SYNC_ACCESS'))
        {
            $emi_device_mode = "#define __EMI_DEVICE_MODE_BURST__";
        }
        elsif (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'ASYNC_ACCESS') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{RAM_ACCESS_TYPE} eq 'ASYNC_ACCESS'))
        {
            $emi_device_mode = "#define __EMI_DEVICE_MODE_ASYNC__";
        }
    	}
    }
    elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6276') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6256'))
    {
    	if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
    	{
    		$emi_device_mode = "#define __EMI_DEVICE_LPDDR1__";
    	}
    	elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2')
    	{
    		$emi_device_mode = "#define __EMI_DEVICE_LPDDR2__";
    	}
    }
     elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6280'))
    {
    	if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
    	{
    		$emi_device_mode = "#define __EMI_DEVICE_LPDDR1__";
    	}
    	elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2')
    	{
    		$emi_device_mode = "#define __EMI_DEVICE_LPDDR2__";
    	}
    }
    elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
    {
        if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'SYNC_ACCESS') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{RAM_ACCESS_TYPE} eq 'SYNC_ACCESS'))
        {
            $emi_device_mode = "#define __EMI_DEVICE_MODE_BURST__";
        }
        elsif (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'ASYNC_ACCESS') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{RAM_ACCESS_TYPE} eq 'ASYNC_ACCESS'))
        {
            $emi_device_mode = "#define __EMI_DEVICE_MODE_ASYNC__";
        }
    }

    ###
    my $HSUPA_76;
   if($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6276')
   {
       if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR')
      {
             $HSUPA_76 = <<"__TEMPLATE";
extern int query_memorydevice_32(void);
__TEMPLATE
        
           	
      } 	
   }
    ###
    my $cs1_base_address = sprintf("0x%08X", &config_query_cs1_addr($MAKEFILE_OPTIONS_LOCAL->{'platform'}));
    my $remap_addr;
    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP' or $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
    {
    	if(($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255') and ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
    	{
    		
    	}
    	else
    	{
    	$remap_addr = <<"__TEMPLATE";
/**
  * Define NOR/RAM's starting address.
  */
#if defined(MT6253) || defined(MT6252H) || defined(MT6252)
#ifdef REMAPPING
#define FLASH_BASE_ADDR $cs1_base_address
#define RAM_BASE_ADDR   0x00000000
#else /* REMAPPING */
#define FLASH_BASE_ADDR 0x00000000
#define RAM_BASE_ADDR   $cs1_base_address
#endif /* REMAPPING */
#endif /* MT6253 || MT6252H || MT6252 */
__TEMPLATE
    }
    }
    print "MDL info:$COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}\n";
    ###
    my ($emi_shareio_struct, $emi_shareio_extern);
    if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') or ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H'))
    {
    	$emi_shareio_struct = <<"__TEMPLATE";
typedef struct
{
    kal_bool EMI_PullUpCtrl;
    kal_bool EMI_PullDnCtrl;
    kal_bool EMI_SlewCtrl;
    kal_uint32 EMI_Drv;
}EMIShareIOSetting;
__TEMPLATE

        $emi_shareio_extern = "extern kal_bool custom_ShareIOControl(const EMIShareIOSetting* pIOSetting );";
    }
    my $custom_EMI_release_h_optional_part1;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) != 1)
    {
        $custom_EMI_release_h_optional_part1 = <<"__TEMPLATE";
/**
    * EMI driving current for query.
    */
typedef enum emi_drv_enum_t 
{
   EMI_DRV_UNKNOWN = 0,
   EMI_DRV_2MA = 2,
   EMI_DRV_4MA = 4,
   EMI_DRV_6MA = 6,
   EMI_DRV_8MA = 8,
   EMI_DRV_10MA = 10,
   EMI_DRV_12MA = 12,
   EMI_DRV_14MA = 14,
   EMI_DRV_16MA = 16,
   EMI_DRV_18MA = 18,
   EMI_DRV_20MA = 20
} emi_drv_enum;

$emi_shareio_struct

/***********************************
    *
    * Exposed APIs.
    * 
    *********************************/

extern emi_clock_enum custom_EMI_QueryFullSpeedClock( void );
extern void custom_get_EXTSRAM_size(kal_uint32 *size);
$emi_shareio_extern
__TEMPLATE
    }
    
    ###
    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_EMI_RELEASE__
#define __CUSTOM_EMI_RELEASE__

#include "kal_general_types.h"

/***********************************
    *
    * Definition
    * 
    *********************************/

/**
  * Define EMI's clock rate.
  * comes from EMI_CLK definition in custom_MemoryDevice.h, or highest freq in MDL 
  */
$emi_clk_str

/**
  * Define memory's mode.
  */
$emi_device_mode

/**
  * Define RAM size in Bytes.
  */
#define EMI_EXTSRAM_SIZE ((($COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'})<<20)>> 3)
$physical_ram_density

$remap_addr

/***********************************
    *
    * Enum
    * 
    *********************************/

/**
    * EMI clock rate for query.
    */
typedef enum emi_clock_enum_t 
{
    EMI_CLK_UNKNOWN = 0,
   EMI_CLK_13MHZ = 26,
   EMI_CLK_15_36MHZ = 30,
   EMI_CLK_26MHZ = 52,
   EMI_CLK_30_72MHZ = 60,
   EMI_CLK_39MHZ = 78,
   EMI_CLK_52MHZ = 104,
   EMI_CLK_61_44MHZ = 122,
   EMI_CLK_65MHZ = 130,
   EMI_CLK_78MHZ = 156,
   EMI_CLK_91MHZ = 182,
   EMI_CLK_104MHZ = 208,
   EMI_CLK_122_88MHZ = 244,
   EMI_CLK_125MHZ = 250,
   EMI_CLK_156MHZ = 312,
   EMI_CLK_166MHZ = 332,
   EMI_CLK_200MHZ = 400,
   EMI_CLK_208MHZ = 416,
   EMI_CLK_245_76MHZ = 490,
   EMI_CLK_333MHZ = 666,
   EMI_CLK_400MH = 800
} emi_clock_enum;

$custom_EMI_release_h_optional_part1

$HSUPA_76

#endif /* __CUSTOM_EMI_RELEASE__ */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  custom_EMI_h_file_body
# return:      
#****************************************************************************
sub custom_EMI_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL) = @_;
    my $HeaderBody;

    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
    {
        $HeaderBody = &HeaderBody_for_nor_ram_mcp($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL);
    } # if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
    elsif (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
    {
        $HeaderBody = &HeaderBody_for_lpsdram($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL);
    } # elsif (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
    else
    {
        # Incorrect memory device type or part number not supported!
        ;
    }

    ###
    my ($EMI_Info, $EMI_List);
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
    {
        $EMI_Info .= <<"__TEMPLATE__";
typedef struct
{
   kal_char m_identifier[8];
  
#if defined(MT6235) || defined(MT6235B)

   kal_uint32 EMI_GENA_value;
   kal_uint32 EMI_GENB_value;
   kal_uint32 EMI_GENC_value;
   kal_uint32 EMI_GEND_value;

   kal_uint32 EMI_CONI_value;
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONK_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONM_value;
   kal_uint32 EMI_CONN_value;

#elif defined(MT6268) || defined(MT6236) || defined(MT6236B)

   kal_uint32 EMI_GENA_value;
   kal_uint32 EMI_GENB_value;
   kal_uint32 EMI_GENC_value;
   kal_uint32 EMI_GEND_value;

   kal_uint32 EMI_CONI_value;
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONK_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONM_value;
   kal_uint32 EMI_CONN_value;
   
   kal_uint32 EMI_DELA_value;
   kal_uint32 EMI_DELB_value;
   kal_uint32 EMI_DELC_value;
   kal_uint32 EMI_DELD_value;
   kal_uint32 EMI_DELE_value;
   kal_uint32 EMI_DELF_value;
   kal_uint32 EMI_DELG_value;
   kal_uint32 EMI_DELH_value;
   kal_uint32 EMI_DELI_value;
   kal_uint32 EMI_DELJ_value;

   kal_uint32 EMI_ARBA_value;
   kal_uint32 EMI_ARBB_value;
   kal_uint32 EMI_ARBC_value;
   kal_uint32 EMI_ARBD_value;
   kal_uint32 EMI_ARBE_value;
   kal_uint32 EMI_ARBF_value;
   kal_uint32 EMI_ARBG_value;
   kal_uint32 EMI_ARBH_value;
   kal_uint32 EMI_ARBI_value;

#elif defined(MT6276)

   kal_uint32 EMI_DRVA_value;
   kal_uint32 EMI_DRVB_value;

   kal_uint32 EMI_ODLA_value;
   kal_uint32 EMI_ODLB_value;
   kal_uint32 EMI_ODLC_value;
   kal_uint32 EMI_ODLD_value;
   kal_uint32 EMI_ODLE_value;
   kal_uint32 EMI_ODLF_value;
   kal_uint32 EMI_ODLG_value;
   
   kal_uint32 EMI_CONI_value;
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONK_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONN_value;

   kal_uint32 EMI_DUTA_value;
   kal_uint32 EMI_DUTB_value;
   kal_uint32 EMI_DUTC_value;

   kal_uint32 EMI_DUCA_value;
   kal_uint32 EMI_DUCB_value;
   kal_uint32 EMI_DUCE_value;

   kal_uint32 EMI_IOCL_value;

#endif

} MTK_EMI_Info;
__TEMPLATE__
        chomp $EMI_Info;

        $EMI_List .= <<"__TEMPLATE__";
typedef struct 
{
   kal_char m_identifier[16];

   /**
      * m_ver = 3 for MT6235
      */
   kal_uint32 m_ver;

   /**
      * for MT6276, 0:166 MHz; 1:200 MHz 
      */
   kal_uint8 op_ver;

   /**
      * reserved for future used 
      */
   kal_uint8 reserved_1;
   kal_uint8 reserved_2;

   /**
      * Numbers of MCPs
      */
   kal_uint8 mcps_num; 

   /** List of all MCP
     *
     */
   MTK_EMI_Info mem_info[__EMI_COMBO_ENTRY_COUNT];

} MTK_EMI_List;
__TEMPLATE__
        chomp $EMI_List;
    }
    
    ###
    my ($MEM_Info, $MEM_List);
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
    {
    	if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) != 1)
    {
        $MEM_Info .= <<"__TEMPLATE__";
/**
   * memory mode-switch command operation.
   */
typedef enum
{
   MEM_CMD_OP_16BIT_RD = 0x00000000,
   MEM_CMD_OP_16BIT_WR,
   MEM_CMD_OP_32BIT_RD,
   MEM_CMD_OP_32BIT_WR,
   MEM_CMD_OP_NOP
} MEM_CMD_OP;


/**
   * memory device mode switch information.
   */

/* 
      1. EMI_NOR_CMD_num_max, EMI_PSRAM_CMD_num_max will be the largest one of all valid MCP 
         for all OPs which are not used by certain MCP, the OP must be MEM_CMD_OP_NOP 
      2. Some fields are moved to MTK_Combo_List
 */
typedef struct 
{

   kal_char m_identifier[8];   

   /* DIDR, not in MDL now but keep for furthur using */
   kal_uint32 didr;

#if defined(MT6236) || defined(MT6236B)
   /**
      * EMI control register value.
      */
   kal_uint32 EMI_GENA_value;
   kal_uint32 EMI_GENB_value;
   kal_uint32 EMI_GENC_value;
   kal_uint32 EMI_GEND_value;
   kal_uint32 EMI_DELAY_J_value;
   
   kal_uint32 EMI_CONA_ASYNC_value;
   kal_uint32 EMI_CONB_ASYNC_value;

   kal_uint32 EMI_CONA_BURST_value;
   kal_uint32 EMI_CONE_BURST_value;
   kal_uint32 EMI_CONB_BURST_value;
   kal_uint32 EMI_CONF_BURST_value;
   
   kal_uint32 EMI_RDCT_value;
   
   /** 
     * Only Burst Mode
     */
     
   /**
      * NOR switch command sets.
      */
   kal_uint32 EMI_NOR_CMD_num;
   
   kal_uint32 EMI_NOR_CMD_OP[__EMI_NOR_CMD_NUM];
   kal_uint32 EMI_NOR_CMD_ADDR[__EMI_NOR_CMD_NUM];
   kal_uint32 EMI_NOR_CMD_DATA[__EMI_NOR_CMD_NUM];

   /**
      * PSRAM switch command sets.
      */
   kal_uint32 EMI_PSRAM_CMD_num;
   
   kal_uint32 EMI_PSRAM_CMD_OP[__EMI_PSRAM_CMD_NUM];
   kal_uint32 EMI_PSRAM_CMD_ADDR[__EMI_PSRAM_CMD_NUM];
   kal_uint32 EMI_PSRAM_CMD_DATA[__EMI_PSRAM_CMD_NUM];

#elif defined(MT6253)

   /**
      * EMI control register value.
      */
   kal_uint32 EMI_CONA_ASYNC_value;
   kal_uint32 EMI_CONB_ASYNC_value;
   kal_uint32 EMI_CONC_ASYNC_value;
   kal_uint32 EMI_COND_ASYNC_value;
   kal_uint32 EMI_GEN_ASYNC_value;
   kal_uint32 EMI_CONA_SYNC_value;
   kal_uint32 EMI_CONB_SYNC_value;
   kal_uint32 EMI_CONC_SYNC_value;
   kal_uint32 EMI_COND_SYNC_value;
   kal_uint32 EMI_GEN_SYNC_value;   
   kal_uint32 EMI_PREFETCH_CON_value;

   /** 
     * Only Burst Mode
     */
     
   /**
      * NOR switch command sets.
      */
   kal_uint32 EMI_NOR_CMD_num;
   
   kal_uint32 EMI_NOR_CMD_OP[__EMI_NOR_CMD_NUM];
   kal_uint32 EMI_NOR_CMD_ADDR[__EMI_NOR_CMD_NUM];
   kal_uint32 EMI_NOR_CMD_DATA[__EMI_NOR_CMD_NUM];

   /**
      * PSRAM switch command sets.
      */
   kal_uint32 EMI_PSRAM_CMD_num;
   
   kal_uint32 EMI_PSRAM_CMD_OP[__EMI_PSRAM_CMD_NUM];
   kal_uint32 EMI_PSRAM_CMD_ADDR[__EMI_PSRAM_CMD_NUM];
   kal_uint32 EMI_PSRAM_CMD_DATA[__EMI_PSRAM_CMD_NUM];

#elif defined(MT6252) || defined(MT6252H)

   kal_uint32 EMI_CONA_ASYNC_value;
   kal_uint32 EMI_CONB_ASYNC_value;
   kal_uint32 EMI_CONC_ASYNC_value;
   
   kal_uint32 EMI_GEN_ASYNC_value;
   kal_uint32 EMI_EXTCON_ASYNC_value;

   kal_uint32 EMI_IOA_value;
   kal_uint32 EMI_IOB_value;
   kal_uint32 EMI_IOC_value;

#if defined(__EMI_DEVICE_MODE_BURST__)
   
   kal_uint32 EMI_CONA_SYNC_value;
   kal_uint32 EMI_CONB_SYNC_value;
   kal_uint32 EMI_CONC_SYNC_value;

   kal_uint32 EMI_GEN_SYNC_value;
   kal_uint32 EMI_EXTCON_BURST_value;
   kal_uint32 EMI_EXTCON2_BURST_value;

   kal_uint32 EMI_IOA_BURST_value;
   kal_uint32 EMI_IOB_BURST_value;

#endif
 
#if defined(__EMI_DEVICE_MODE_PAGE__)     

   kal_uint32 EMI_CONA_PAGE_value;
   kal_uint32 EMI_CONB_PAGE_value;
   kal_uint32 EMI_CONC_PAGE_value;

#endif

/**
  *    For Page Mode, if there is no command for NOR, let the num = 0
  *    since there will be the compile option "__EMI_DEVICE_MODE_BURST__"
  *    Array with size = 0 will not be compiled
  */
#if defined(__EMI_DEVICE_MODE_BURST__) && !defined(MT6252)
   /**
      * NOR switch command sets.
      */
   kal_uint32 EMI_NOR_CMD_num;
   
   kal_uint32 EMI_NOR_CMD_OP[__EMI_NOR_CMD_NUM];
   kal_uint32 EMI_NOR_CMD_ADDR[__EMI_NOR_CMD_NUM];
   kal_uint32 EMI_NOR_CMD_DATA[__EMI_NOR_CMD_NUM];

#endif /* __EMI_DEVICE_MODE_BURST__ && ! MT6252 */


#if defined(__EMI_DEVICE_MODE_BURST__) || defined(__EMI_DEVICE_MODE_PAGE__)
   /**
      * PSRAM switch command sets.
      */
   kal_uint32 EMI_PSRAM_CMD_num;
   
   kal_uint32 EMI_PSRAM_CMD_OP[__EMI_PSRAM_CMD_NUM];
   kal_uint32 EMI_PSRAM_CMD_ADDR[__EMI_PSRAM_CMD_NUM];
   kal_uint32 EMI_PSRAM_CMD_DATA[__EMI_PSRAM_CMD_NUM];

#endif /* __EMI_DEVICE_MODE_BURST__ || __EMI_DEVICE_MODE_PAGE__ */

#endif /* MT6236 */

#if defined(__EMI_DEVICE_MODE_PAGE__) && defined(__EMI_DEVICE_MODE_BURST__)
   #error "Device could not be both Burst and Page at the same time !!\\n"
#endif

} MTK_MEM_Info;
__TEMPLATE__

        $MEM_List = <<"__TEMPLATE";
/**
   * List of All valid MCPs
   */ 
 
typedef struct 
{
   /**
      * header pattern information.
      */
   kal_char cb_identifier[16];
   /**
      * chip version information.
      * m_ver = 1 for MT6253
      */
   kal_uint32 m_chip_ver;
   /**
      * switch op version information.
      * m_ver = 1 for initial version.
      */
   kal_uint8 m_op_ver;

   /**
      * Max number of NOR switch command of all MCPs
      */   
   kal_uint8 emi_nor_cmd_num_max;  // =0 if there is no NOR command

   /**
      * Max number of PSRAM switch command of all MCPs
      */   
   kal_uint8 emi_psram_cmd_num_max;   // =0 if there is no PSRAM command

   /**
      * Numbers of MCPs
      */
   kal_uint8 mcps_num; 

   /** List of all MCP
     *
     */
   MTK_MEM_Info mem_info[__EMI_COMBO_ENTRY_COUNT];
   
} MTK_MEM_List;
__TEMPLATE
    	}
    	else
    	{
            $MEM_Info .= <<"__TEMPLATE__";
typedef struct 
{
   /**
      * header pattern information.
      */
   kal_char m_identifier[16];
   /**
      * chip version information.
      * m_ver = 1 for MT6253
      */
   kal_uint32 m_chip_ver;
   /**
      * switch op version information.
      * m_ver = 1 for initial version.
      */
   kal_uint32 m_op_ver;

#if defined(MT6251)
   // Nothing Necessary
#endif

} MTK_MEM_Info;
__TEMPLATE__

        $MEM_List = <<"__TEMPLATE";
/**
   * List of All valid MCPs
   */ 
 
typedef struct 
{
   /**
      * header pattern information.
      */
   kal_char cb_identifier[16];
   /**
      * chip version information.
      * m_ver = 1 for MT6253
      */
   kal_uint32 m_chip_ver;
   /**
      * switch op version information.
      * m_ver = 1 for initial version.
      */
   kal_uint8 m_op_ver;

   /**
      * Max number of NOR switch command of all MCPs
      */   
   kal_uint8 emi_nor_cmd_num_max;  // =0 if there is no NOR command

   /**
      * Max number of PSRAM switch command of all MCPs
      */   
   kal_uint8 emi_psram_cmd_num_max;   // =0 if there is no PSRAM command

   /**
      * Numbers of MCPs
      */
   kal_uint8 mcps_num; 

   /** List of all MCP
     *
     */
   MTK_MEM_Info mem_info[__EMI_COMBO_ENTRY_COUNT];
   
} MTK_MEM_List;
__TEMPLATE
    	}
        chomp $MEM_Info;
        chomp $MEM_List;
    }
        
    ###
    my ($cs0_info, $cs1_info);
    if (defined $PART_NUMBER_LOCAL->{0})
    {
        $cs0_info .= <<"__TEMPLATE__";
 * CS0_PART_NUMBER: $PART_NUMBER_LOCAL->{0}
__TEMPLATE__
        chomp $cs0_info;
    }
    if (defined $PART_NUMBER_LOCAL->{1})
    {
        $cs1_info .= <<"__TEMPLATE__";
 * CS1_PART_NUMBER: $PART_NUMBER_LOCAL->{1}
__TEMPLATE__
        chomp $cs1_info;
    }

    ###
    my $custom_EMI_h_optional_part1;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) != 1)
    {
        $custom_EMI_h_optional_part1 = <<"__TEMPLATE";
/****************************************************************************
   *
   * Specify high-level feature option for EMI driver (internal usage).
   *
   ****************************************************************************/

/**
  *     New patched code, used to select SIP by DIDR
  *     And also work around for aptic
  *
  */ 

/**
  * Only some fields will be used to compare DIDR
  * 0x0000E7E0 = 2'b 1110_0111_1110_0000
  */
// Address to be read DIDR
#define __EMI_DIDR_ADDRESS        0x01FFFFFF
// Mask to be used to select SIP
#define __EMI_DIDR_SELECT_MASK    0x0000E7E0

// ONLY used for APTIC driving work-around
#if defined(MT6252)
#define __EMI_DIDR_APTIC_MASK     0x0000601F
#define __EMI_DIDR_APTIC_VID      0x0000994D
#define __EMI_DIDR_APTIC_BCRVAL   0x00002133
#endif

/**
  * On SRAM configuration, the old EMI init flow will perform Sync/Page EMI initialization at INTSRAM_ROCODE section, while 
  * the new EMI init flow will perform this flow at EMIINITCODE section.
  * Note that the __EMI_INIT_FLOW_Vx__ has different version maintenance on NOR case and NAND case, that is, 
  * NOR case has its V1->V2->V3, and NAND case has its own V1->V2->V3.
  */
#if defined(_NAND_FLASH_BOOTING_)

/**
   * EMI init flow is INT_SetPLL() -> custom_setEMI() -> Init execution regions.
   */
#define __EMI_INIT_FLOW_V1__

#else /* _NAND_FLASH_BOOTING_ */

#if (defined(MT6236) || defined(MT6236B) || defined(MT6253) || defined(MT6252H) || defined(MT6252))
/**
   * EMI init flow is [custom_setEMI() -> INT_SetPLL() -> custom_setAdvEMI()]\@int.ram -> Init execution regions.
   */
#define __EMI_INIT_FLOW_V2__
#else /* MT6236 || MT6236B || MT6253 || MT6252H || MT6252 */
/**
   * EMI init flow is custom_setEMI() -> INT_SetPLL() -> Init execution regions -> [custom_setAdvEMI()]\@int.ram.
   */
#define __EMI_INIT_FLOW_V1__
#endif /* MT6236 || MT6236B || MT6253 || MT6252H || MT6252 */

#endif /* _NAND_FLASH_BOOTING_ */

/**
  * __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
  * We add this compile option to avoid compiling functions other than custom_setEMI() so to reduce the lib size.
  * The Bootloader will perform Sync/Page EMI initialization at the new EMI init flow, so we must be careful about 
  * the wrapping option so that Bootloader could reference the custom_setAdvEMI() function on __EMI_INIT_FLOW_V2__.
  */
#if defined(__EMI_INIT_FLOW_V1__)

#if defined(__FUE__)
/**
   * Do nothing.
   */
#endif  /* __FUE__ */

#if defined(__UBL__)
/**
   * Do nothing.
   */
#endif /* __UBL__ */

#if !defined(__FUE__) && !defined(__UBL__)
#define __EMI_OPTION_DRIVER__
#define __EMI_NECESSARY_DRIVER__
#endif /* !__FUE__ && __UBL__!*/

#elif defined(__EMI_INIT_FLOW_V2__) /* __EMI_INIT_FLOW_V1__ */

#if defined(__FUE__)
/**
   * Do nothing.
   */
#endif  /* __FUE__ */

#if defined(__UBL__)
#define __EMI_OPTION_DRIVER__
#endif /* __UBL__ */

#if !defined(__FUE__) && !defined(__UBL__)
#define __EMI_OPTION_DRIVER__
#define __EMI_NECESSARY_DRIVER__
#endif /* !__FUE__ && __UBL__!*/

#endif /* __EMI_INIT_FLOW_V1__ */

#if defined(MT6276)

/**
  * Define EMI enable data auto-tracking or not (if we do not use data auto-tracking, we will enable 1/5T PLL).
  * It is for DVT usage only.
  */
//#define __EMI_DATA_AUTO_TRACKING_ENABLE

/**
  * Use to filtering EVB 
  */
//#define __DBG_EVB_CHECK_FAIL
//#define __DQIDLY_BOUNDARY 0x1f //Use to seperate the factor4 of RX timing tuning

//#define __LOG_DATA_TRAIN_ERROR_INFO

/**
   * Define EMI that supporting MBIST functionality.
   */
#define ___EMIDATATRAIN_MBIST_DATATRAIN__

#endif /* MT6276 */
__TEMPLATE
    }

    ###
    my $custom_EMI_h_optional_part2;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) != 1)
    {
        ### No Combo Memory case
    	my $mt6253_sync_setting;
    	if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6253')
    	{
            my @addr_list_nor = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB(1, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my @data_list_nor = &split_emi(&Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB(1, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my @addr_list_psram = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB(1, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my @data_list_psram = &split_emi(&Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB(1, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
	        
	    for (0..$#addr_list_nor)
	    {
	        my $idx = $_ + 1;
	        $mt6253_sync_setting .= "#define EMI_NOR_BURST_ADDRESS_$idx      EMI_NOR_BURST_ADDRESS_$idx\_MCP0\n";
	    }
	    for (0..$#data_list_nor)
	    {
	        my $idx = $_ + 1;
	        $mt6253_sync_setting .= "#define EMI_NOR_BURST_DATA_$idx         EMI_NOR_BURST_DATA_$idx\_MCP0\n";
	    }
	    for (0..$#addr_list_psram)
	    {
	        my $idx = $_ + 1;
	        $mt6253_sync_setting .= "#define EMI_PSRAM_BURST_ADDRESS_$idx    EMI_PSRAM_BURST_ADDRESS_$idx\_MCP0\n";
	    }
	    for (0..$#data_list_psram)
	    {
	        my $idx = $_ + 1;
	        $mt6253_sync_setting .= "#define EMI_PSRAM_BURST_DATA_$idx      EMI_PSRAM_BURST_DATA_$idx\_MCP0\n";
	    }
	    chomp $mt6253_sync_setting;
	}

    	$custom_EMI_h_optional_part2 = <<"__TEMPLATE";
/* for SW-DCM */
#if defined(MT6235) || defined(MT6235B) || defined(MT6236) || defined(MT6236B) || defined(MT6268)
typedef struct
{
#if defined(MT6235) || defined(MT6235B)
#if defined(_NAND_FLASH_BOOTING_)
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONK_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONM_value;
   kal_uint32 EMI_GENA_value;
   kal_uint32 EMI_GENB_value;
   kal_uint32 EMI_GENC_value;

   kal_uint32 EMI_CONJ_13_value;
   kal_uint32 EMI_CONK_13_value;
   kal_uint32 EMI_CONL_13_value;
   kal_uint32 EMI_CONM_13_value;
   kal_uint32 EMI_GENA_13_value;
   kal_uint32 EMI_GENB_13_value;
   kal_uint32 EMI_GENC_13_value;
#else
#endif 
#elif defined(MT6236) || defined(MT6236B) /* MT6235 || MT6235B */
#if defined(_NAND_FLASH_BOOTING_)
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONJ_13_value;
   kal_uint32 EMI_CONL_13_value;
#else
   kal_uint32 EMI_CONA_BURST_104_value;
   kal_uint32 EMI_CONB_BURST_104_value;
   kal_uint32 EMI_CONE_BURST_104_value;
   kal_uint32 EMI_CONF_BURST_104_value;

   kal_uint32 EMI_CONA_BURST_13_value;
   kal_uint32 EMI_CONB_BURST_13_value;
   kal_uint32 EMI_CONE_BURST_13_value;
   kal_uint32 EMI_CONF_BURST_13_value;
#endif
#elif defined(MT6268) /* MT6235 || MT6235B */
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONJ_15_36_value;
   kal_uint32 EMI_CONL_15_36_value;
#endif  /* MT6236 || MT6236B */
} MTK_EMI_DCM_Ctrl;
#endif /* MT6236 || MT6236B || MT6268 */

/* Turn-off Combo Memory */
#if defined(__EMI_COMBO_DIS)

#if defined(MT6235) || defined(MT6235B)

#define EMI_GENERAL_A_VAL   EMI_GENERAL_A_VAL_MCP0
#define EMI_GENERAL_B_VAL   EMI_GENERAL_B_VAL_MCP0
#define EMI_GENERAL_C_VAL   EMI_GENERAL_C_VAL_MCP0
#define EMI_GENERAL_D_VAL   EMI_GENERAL_D_VAL_MCP0

#define EMI_CONTROL_I_VAL   EMI_CONTROL_I_VAL_MCP0
#define EMI_CONTROL_J_VAL   EMI_CONTROL_J_VAL_MCP0
#define EMI_CONTROL_K_VAL   EMI_CONTROL_K_VAL_MCP0
#define EMI_CONTROL_L_VAL   EMI_CONTROL_L_VAL_MCP0
#define EMI_CONTROL_M_VAL   EMI_CONTROL_M_VAL_MCP0
#define EMI_CONTROL_N_VAL   EMI_CONTROL_N_VAL_MCP0

#define EMI_GENERAL_A_104_VAL   EMI_GENERAL_A_VAL_MCP0
#define EMI_GENERAL_B_104_VAL   EMI_GENERAL_B_VAL_MCP0
#define EMI_GENERAL_C_104_VAL   EMI_GENERAL_C_VAL_MCP0

#define EMI_CONTROL_J_104_VAL   EMI_CONTROL_J_VAL_MCP0
#define EMI_CONTROL_K_104_VAL   EMI_CONTROL_K_VAL_MCP0
#define EMI_CONTROL_L_104_VAL   EMI_CONTROL_L_VAL_MCP0
#define EMI_CONTROL_M_104_VAL   EMI_CONTROL_M_VAL_MCP0

#define EMI_GENERAL_A_13_VAL   EMI_GENERAL_A_13_VAL_MCP0
#define EMI_GENERAL_B_13_VAL   EMI_GENERAL_B_13_VAL_MCP0
#define EMI_GENERAL_C_13_VAL   EMI_GENERAL_C_13_VAL_MCP0

#define EMI_CONTROL_J_13_VAL   EMI_CONTROL_J_13_VAL_MCP0
#define EMI_CONTROL_K_13_VAL   EMI_CONTROL_K_13_VAL_MCP0
#define EMI_CONTROL_L_13_VAL   EMI_CONTROL_L_13_VAL_MCP0
#define EMI_CONTROL_M_13_VAL   EMI_CONTROL_M_13_VAL_MCP0

#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) /* MT6235 || MT6235B */
#if defined(_NAND_FLASH_BOOTING_)

#define EMI_GENERAL_A_VAL   EMI_GENERAL_A_VAL_MCP0
#define EMI_GENERAL_B_VAL   EMI_GENERAL_B_VAL_MCP0
#define EMI_GENERAL_C_VAL   EMI_GENERAL_C_VAL_MCP0
#define EMI_GENERAL_D_VAL   EMI_GENERAL_D_VAL_MCP0

#define EMI_CONTROL_I_VAL   EMI_CONTROL_I_VAL_MCP0
#define EMI_CONTROL_J_VAL   EMI_CONTROL_J_VAL_MCP0
#define EMI_CONTROL_K_VAL   EMI_CONTROL_K_VAL_MCP0
#define EMI_CONTROL_L_VAL   EMI_CONTROL_L_VAL_MCP0
#define EMI_CONTROL_M_VAL   EMI_CONTROL_M_VAL_MCP0
#define EMI_CONTROL_N_VAL   EMI_CONTROL_N_VAL_MCP0

#define EMI_DELAY_A_VAL     EMI_DELAY_A_VAL_MCP0
#define EMI_DELAY_B_VAL     EMI_DELAY_B_VAL_MCP0
#define EMI_DELAY_C_VAL     EMI_DELAY_C_VAL_MCP0
#define EMI_DELAY_D_VAL     EMI_DELAY_D_VAL_MCP0
#define EMI_DELAY_E_VAL     EMI_DELAY_E_VAL_MCP0
#define EMI_DELAY_F_VAL     EMI_DELAY_F_VAL_MCP0
#define EMI_DELAY_G_VAL     EMI_DELAY_G_VAL_MCP0
#define EMI_DELAY_H_VAL     EMI_DELAY_H_VAL_MCP0
#define EMI_DELAY_I_VAL     EMI_DELAY_I_VAL_MCP0
#define EMI_DELAY_J_VAL     EMI_DELAY_J_VAL_MCP0

#define EMI_ARB_A_VAL       EMI_ARB_A_VAL_MCP0
#define EMI_ARB_B_VAL       EMI_ARB_B_VAL_MCP0
#define EMI_ARB_C_VAL       EMI_ARB_C_VAL_MCP0
#define EMI_ARB_D_VAL       EMI_ARB_D_VAL_MCP0
#define EMI_ARB_E_VAL       EMI_ARB_E_VAL_MCP0
#define EMI_ARB_F_VAL       EMI_ARB_F_VAL_MCP0
#define EMI_ARB_G_VAL       EMI_ARB_G_VAL_MCP0
#define EMI_ARB_H_VAL       EMI_ARB_H_VAL_MCP0
#define EMI_ARB_I_VAL       EMI_ARB_I_VAL_MCP0

#if defined(MT6236) || defined(MT6236B)
#define EMI_CONTROL_J_104_VAL    EMI_CONTROL_J_VAL_MCP0
#define EMI_CONTROL_L_104_VAL    EMI_CONTROL_L_VAL_MCP0
#define EMI_CONTROL_J_13_VAL     EMI_CONTROL_J_13_VAL_MCP0  
#define EMI_CONTROL_L_13_VAL     EMI_CONTROL_L_13_VAL_MCP0  
#else
#define EMI_CONTROL_J_122_88_VAL EMI_CONTROL_J_VAL_MCP0
#define EMI_CONTROL_L_122_88_VAL EMI_CONTROL_L_VAL_MCP0
#define EMI_CONTROL_J_15_36_VAL  EMI_CONTROL_J_15_36_VAL_MCP0
#define EMI_CONTROL_L_15_36_VAL  EMI_CONTROL_L_15_36_VAL_MCP0
#define EMI_CONTROL_J_30_72_VAL  EMI_CONTROL_J_30_72_VAL_MCP0
#define EMI_CONTROL_L_30_72_VAL  EMI_CONTROL_L_30_72_VAL_MCP0
#endif


#else
#if defined(MT6236) || defined(MT6236B)
#define EMI_GENERAL_A_VAL   EMI_GENERAL_A_VAL_MCP0
#define EMI_GENERAL_B_VAL   EMI_GENERAL_B_VAL_MCP0
#define EMI_GENERAL_C_VAL   EMI_GENERAL_C_VAL_MCP0
#define EMI_GENERAL_D_VAL   EMI_GENERAL_D_VAL_MCP0

#define EMI_DELAY_J_VAL    EMI_DELAY_J_VAL_MCP0

#define EMI_CONA_ASYNC   EMI_CONA_ASYNC_MCP0
#define EMI_CONB_ASYNC    EMI_CONB_ASYNC_MCP0
#define EMI_CONC_ASYNC    0
#define EMI_COND_ASYNC    0

#define EMI_CONA_BURST    EMI_CONA_BURST_MCP0
#define EMI_CONE_BURST    EMI_CONE_BURST_MCP0

#define EMI_CONB_BURST   EMI_CONB_BURST_MCP0
#define EMI_CONF_BURST    EMI_CONF_BURST_MCP0

#define EMI_CONA_BURST_13MHZ    EMI_CONA_BURST_13MHZ_MCP0
#define EMI_CONE_BURST_13MHZ    EMI_CONE_BURST_13MHZ_MCP0

#define EMI_CONB_BURST_13MHZ    EMI_CONB_BURST_13MHZ_MCP0
#define EMI_CONF_BURST_13MHZ    EMI_CONF_BURST_13MHZ_MCP0

#define EMI_CONA_BURST_104MHZ    EMI_CONA_BURST_MCP0
#define EMI_CONE_BURST_104MHZ    EMI_CONE_BURST_MCP0

#define EMI_CONB_BURST_104MHZ    EMI_CONB_BURST_MCP0
#define EMI_CONF_BURST_104MHZ    EMI_CONF_BURST_MCP0

#define EMI_RDCT_VAL    EMI_RDCT_VAL_MCP0
#define EMI_NOR_BURST_ADDRESS_1    EMI_NOR_BURST_ADDRESS_1_MCP0
#define EMI_NOR_BURST_ADDRESS_2    EMI_NOR_BURST_ADDRESS_2_MCP0
#define EMI_NOR_BURST_ADDRESS_3    EMI_NOR_BURST_ADDRESS_3_MCP0
#define EMI_NOR_BURST_ADDRESS_4    EMI_NOR_BURST_ADDRESS_4_MCP0
#define EMI_NOR_BURST_ADDRESS_5    EMI_NOR_BURST_ADDRESS_5_MCP0
#define EMI_NOR_BURST_DATA_1    EMI_NOR_BURST_DATA_1_MCP0
#define EMI_NOR_BURST_DATA_2    EMI_NOR_BURST_DATA_2_MCP0
#define EMI_NOR_BURST_DATA_3    EMI_NOR_BURST_DATA_3_MCP0
#define EMI_NOR_BURST_DATA_4    EMI_NOR_BURST_DATA_4_MCP0
#define EMI_NOR_BURST_DATA_5    EMI_NOR_BURST_DATA_5_MCP0

#define EMI_PSRAM_BURST_ADDRESS_1    EMI_PSRAM_BURST_ADDRESS_1_MCP0
#define EMI_PSRAM_BURST_ADDRESS_2    EMI_PSRAM_BURST_ADDRESS_2_MCP0
#define EMI_PSRAM_BURST_ADDRESS_3    EMI_PSRAM_BURST_ADDRESS_3_MCP0
#define EMI_PSRAM_BURST_ADDRESS_4    EMI_PSRAM_BURST_ADDRESS_4_MCP0
#define EMI_PSRAM_BURST_DATA_3    EMI_PSRAM_BURST_DATA_3_MCP0
#define EMI_PSRAM_BURST_DATA_4    EMI_PSRAM_BURST_DATA_4_MCP0
#define EMI_PSRAM_BURST_ADDRESS_5    EMI_PSRAM_BURST_ADDRESS_5_MCP0
#define EMI_PSRAM_BURST_ADDRESS_6    EMI_PSRAM_BURST_ADDRESS_6_MCP0
#define EMI_PSRAM_BURST_ADDRESS_7    EMI_PSRAM_BURST_ADDRESS_7_MCP0
#define EMI_PSRAM_BURST_ADDRESS_8    EMI_PSRAM_BURST_ADDRESS_8_MCP0
#define EMI_PSRAM_BURST_DATA_7    EMI_PSRAM_BURST_DATA_7_MCP0
#define EMI_PSRAM_BURST_DATA_8    EMI_PSRAM_BURST_DATA_8_MCP0
#endif
#endif

#elif defined(MT6276) /* MT6235 || MT6235B */

#define EMI_DRV_A_VAL       EMI_DRV_A_VAL_MCP0
#define EMI_DRV_B_VAL       EMI_DRV_B_VAL_MCP0

#define EMI_ODL_A_VAL       EMI_ODL_A_VAL_MCP0
#define EMI_ODL_B_VAL       EMI_ODL_B_VAL_MCP0
#define EMI_ODL_C_VAL       EMI_ODL_C_VAL_MCP0
#define EMI_ODL_D_VAL       EMI_ODL_D_VAL_MCP0
#define EMI_ODL_E_VAL       EMI_ODL_E_VAL_MCP0
#define EMI_ODL_F_VAL       EMI_ODL_F_VAL_MCP0
#define EMI_ODL_G_VAL       EMI_ODL_G_VAL_MCP0

#define EMI_CONTROL_I_VAL   EMI_CONTROL_I_VAL_MCP0
#define EMI_CONTROL_J_VAL   EMI_CONTROL_J_VAL_MCP0
#define EMI_CONTROL_K_VAL   EMI_CONTROL_K_VAL_MCP0
#define EMI_CONTROL_L_VAL   EMI_CONTROL_L_VAL_MCP0
#define EMI_CONTROL_N_VAL   EMI_CONTROL_N_VAL_MCP0

#define EMI_IODUTY_A_VAL    EMI_IODUTY_A_VAL_MCP0
#define EMI_IODUTY_B_VAL    EMI_IODUTY_B_VAL_MCP0
#define EMI_IODUTY_C_VAL    EMI_IODUTY_C_VAL_MCP0

#define EMI_RXDUTY_A_VAL    EMI_RXDUTY_A_VAL_MCP0
#define EMI_RXDUTY_B_VAL    EMI_RXDUTY_B_VAL_MCP0
#define EMI_RXDUTY_E_VAL    EMI_RXDUTY_E_VAL_MCP0

#define EMI_IOMISC_L_VAL    EMI_IOMISC_L_VAL_MCP0  

#elif defined(MT6253)

#define EMI_CONA_ASYNC               EMI_CONA_ASYNC_MCP0
#define EMI_CONB_ASYNC               EMI_CONB_ASYNC_MCP0
#define EMI_CONC_ASYNC               0
#define EMI_COND_ASYNC               0

#define EMI_CONA_BURST               EMI_CONA_BURST_MCP0
#define EMI_CONB_BURST               EMI_CONB_BURST_MCP0
#define EMI_CONC_BURST               0
#define EMI_COND_BURST               0

$mt6253_sync_setting

#define EMI_GENERAL_CONTROL_BURST    EMI_GENERAL_CONTROL_BURST_MCP0
#define EMI_GENERAL_CONTROL          EMI_GENERAL_CONTROL_MCP0

#elif defined(MT6252) || defined(MT6252H)
// MT6252 always enable combo memory

#endif

#endif /* __EMI_COMBO_DIS */
__TEMPLATE
    }

    ###
    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__

#include "kal_general_types.h"
#include "MemoryDevice_TypeDef.h"

/**
  *    for definition of COMBO_MEM_ENTRY_COUNT and __EMI_DEVICE_MODE_BURST__
  */
#include "custom_MemoryDevice.h"
#include "custom_EMI_release.h"
/**
  *    for SIP, the Combo CNT is defined by the number of MTKSIPxx in MDL
  *    Note: MT6252 will use only MTKSIP01 ~ MTKSIP04 !
  */
#if defined(MT6252)
#define __EMI_SIP_RAM
#endif

/* Enable Combo Memory Supporting */
#if defined(__EMI_SIP_RAM)
#define __EMI_COMBO_EN
#define __EMI_COMBO_ENTRY_COUNT     $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT}   // by the number of entry fetched from MDL
#elif defined(__COMBO_MEMORY_SUPPORT__)
#define __EMI_COMBO_EN
#define __EMI_COMBO_ENTRY_COUNT     COMBO_MEM_ENTRY_COUNT
#else /* __EMI_SIP_RAM */
#define __EMI_COMBO_DIS
#define __EMI_COMBO_ENTRY_COUNT     1  // always 1 set for flash tool
#endif /* __EMI_SIP_RAM */

#define __EMI_DCM_COMBO_INDEX_UND   0xffffffff

$custom_EMI_h_optional_part1

$HeaderBody

$EMI_Info

$EMI_List

$MEM_Info

$MEM_List

$custom_EMI_h_optional_part2

/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *
$cs0_info
$cs1_info
 ****************************************************/

#endif /* __CUSTOM_EMI__ */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  HeaderBody_for_nor_ram_mcp
# return:      content for custom_EMI.h 
#****************************************************************************
sub HeaderBody_for_nor_ram_mcp
{
    ###
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL) = @_;
    my ($sub_content_block1, $sub_content_block2, $sub_content_block3, $sub_content_block4);
    my $sub_content_didr;
    my $sub_content_command_num;
    my $optional_block_admux;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) != 1)
    {
        ###
        $sub_content_block1 = &emi_csconfiguration($COMM_MDL_INFO_LOCAL);
        $sub_content_block2 = &driving_and_cache_prefetch_setting($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL);
        $sub_content_block3 = &emi_setting_on_chip_select();
        #$sub_content_block4 = &additional_information($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);

        ###
        my $combo_ram_count = ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') ? ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT}) : ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT});
        foreach (1..$combo_ram_count)
        {
            my $combo_idx = $_ - 1;
            my $didr = ((defined $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'DIDR'}) and ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'DIDR'} ne 'x') and ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'DIDR'} ne ' ')) ? $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'DIDR'} : "0";
            
            $sub_content_didr .= <<"__TEMPLATE";
#define EMI_RAM_DIDR_MCP$combo_idx    $didr
__TEMPLATE
        }

        ###
        $sub_content_command_num = <<"__TEMPLATE";
#define __EMI_NOR_CMD_NUM      $emi_nor_cmd_num_max_LOCAL
#define __EMI_PSRAM_CMD_NUM    $emi_psram_cmd_num_max_LOCAL

#if defined(__EMI_NOR_CMD_NUM) && (__EMI_NOR_CMD_NUM<1)
#if defined(MT6252) || defined(__EMI_DEVICE_MODE_PAGE__)
/* MT6252 support only Rank1 and there is no NOR command in Page mode */
#else
#error "ERROR ! There must be commands to switch NOR to burst mode!\\n"
#endif
#endif

#if defined(__EMI_PSRAM_CMD_NUM) && (__EMI_PSRAM_CMD_NUM<1)
#error "ERROR ! There must be commands to switch RAM to page or burst mode!\\n"
#endif
__TEMPLATE

        ###
        if ($COMM_MDL_INFO_LOCAL->{0}->{'ADMUX'} eq 'YES' or $COMM_MDL_INFO_LOCAL->{1}->{'ADMUX'} eq 'YES')
        {
            $optional_block_admux = &mcp_admux();
        }
    }

    ###
    my $template = <<"__TEMPLATE";

/*
 ****************************************************************************
 Specify the chip select configuration
 Possible choices, NOR_FLASH, RAM, LPSDRAM, UNUSED
 ****************************************************************************
*/
$sub_content_block1

/*
 ****************************************************************************
 Specify SRAM DIDR
 ****************************************************************************
*/
$sub_content_didr

/*
 ****************************************************************************
 Specify NOR/PSRAM Command Num
 ****************************************************************************
*/
$sub_content_command_num

$optional_block_admux

/*
 ****************************************************************************
 Define the driving and cache/prefetch setting (optional)
 ****************************************************************************
*/
$sub_content_block2
/*
 ****************************************************************************
 Specify the related EMI Setting
 ****************************************************************************
*/
$sub_content_block3
/*
 ****************************************************************************
 Specify additional information
 ****************************************************************************
*/
$sub_content_block4
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  emi_csconfiguration
# return:      template of part EMI_CSConfiguration
#****************************************************************************
sub emi_csconfiguration
{
	  my ($COMM_MDL_INFO_LOCAL) = @_;
    my $content;
    for (0..3)
    {
        if (!defined $COMM_MDL_INFO_LOCAL->{$_}->{'Comm. Series'})
        {
            $content .=  (($_==3) ? "   UNUSED\n" : "   UNUSED,\n");
        }
        elsif ($COMM_MDL_INFO_LOCAL->{$_}->{'Comm. Series'} ne '*')
        {
            $content .=  "   NOR_FLASH,\n";
        }
        elsif ($COMM_MDL_INFO_LOCAL->{$_}->{'Comm. Series'} eq '*')
        {
            $content .=  "   RAM,\n";
        }
    }
    ###
    my $template = <<"__TEMPLATE";
const ExtMemoryType_T   EMI_CSConfiguration[4] =
{
$content
};

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  driving_and_cache_prefetch_setting
# return:      driving and cache section
#****************************************************************************
sub driving_and_cache_prefetch_setting
{
	  my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL) = @_;
    my $sync_setting;
    
    ### MT6253
    ### To support Combo Memory
    my $sub_content_emi_setting_53;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        
        my ($emi_cona_async_53, $emi_conb_async_53, $emi_cona_burst_53, $emi_conb_burst_53, $emi_gen_con_burst_53, $emi_gen_con_async_53);
        
        $emi_cona_burst_53    = &Lookup_SYNC_EMI_setting_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'});
        $emi_conb_burst_53    = &Lookup_SYNC_EMI_setting_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'});

        if ($emi_clk_config_LOCAL == 104)
        {
            $emi_cona_async_53    = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6253'};
            $emi_conb_async_53    = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6253'};
            $emi_gen_con_burst_53 = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous Driving Setting'}->{'MT6253'};
            $emi_gen_con_async_53 = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous Driving Setting'}->{'MT6253'};
        }
        elsif ($emi_clk_config_LOCAL == 52)
        {
            $emi_cona_async_53    = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6253D'};
            $emi_conb_async_53    = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6253D'};
            $emi_gen_con_burst_53 = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'52MHz Synchronous Driving Setting'}->{'MT6253 MT6253D'};
            $emi_gen_con_async_53 = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous Driving Setting'}->{'MT6253D'};
        }

        ###
        my $sync_setting;
        my @op_list_nor = &split_addr_ret_rw(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @addr_list_nor = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @data_list_nor = &split_emi(&Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @op_list_psram = &split_addr_ret_rw(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @addr_list_psram = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @data_list_psram = &split_emi(&Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        
        for (0..($emi_nor_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#op_list_nor)
            {
                $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_NOP\n";
            }
            elsif ($op_list_nor[$_] eq 'R:')
            {
                $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_RD\n";
            }
            else
            {
                $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_WR\n";
            }
        }
        for (0..($emi_nor_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#addr_list_nor)
            {
                $sync_setting .= "#define EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx      0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx      $addr_list_nor[$_]\n";
            }
        }
        for (0..($emi_nor_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#data_list_nor)
            {
                $sync_setting .= "#define EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx         0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx         $data_list_nor[$_]\n";
            }
        }
        for (0..($emi_psram_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#op_list_psram)
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_NOP\n";
            }
            elsif ($op_list_psram[$_] eq 'R:')
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_RD\n";
            }
            else
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_WR\n";
            }
        }
        for (0..($emi_psram_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#addr_list_psram)
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx    0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx    $addr_list_psram[$_]\n";
            }
        }
        for (0..($emi_psram_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#data_list_psram)
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx      0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx      $data_list_psram[$_]\n";
            }
        }
        chomp $sync_setting;

        $sub_content_emi_setting_53 .= <<"__TEMPLATE";
/* start of MCP$combo_idx */

#define EMI_CONA_ASYNC_MCP$combo_idx               $emi_cona_async_53
#define EMI_CONB_ASYNC_MCP$combo_idx               $emi_conb_async_53
#define EMI_CONC_ASYNC_MCP$combo_idx               0
#define EMI_COND_ASYNC_MCP$combo_idx               0

#define EMI_CONA_BURST_MCP$combo_idx               $emi_cona_burst_53
#define EMI_CONB_BURST_MCP$combo_idx               $emi_conb_burst_53
#define EMI_CONC_BURST_MCP$combo_idx               0
#define EMI_COND_BURST_MCP$combo_idx               0

$sync_setting

/**
  * For support RF desense analysis, some of the current setting will be hard-coded based
  * on SA's suggestion.
  */
#if defined(MT6253)

#if defined(__RF_DESENSE_EMI_MIN_CURRENT__)
    /**
      * [FIXED VALUE]ECLK - 4mA, DQs - 4mA.
      */
    #define EMI_GENERAL_CONTROL_BURST_MCP$combo_idx    0xCCCCFB80
#elif defined(__RF_DESENSE_EMI_2MA_CTRL_CURRENT__) /* __RF_DESENSE_EMI_MIN_CURRENT__ */
    /**
      * [FIXED VALUE]ECLK - 2mA, DQs - 6mA
      */
    #define EMI_GENERAL_CONTROL_BURST_MCP$combo_idx    0x8AAAFB80
#else /* __RF_DESENSE_EMI_MIN_CURRENT__ */
    /**
      * Set current from EMI database.
      */
    #define EMI_GENERAL_CONTROL_BURST_MCP$combo_idx    $emi_gen_con_burst_53
#endif /* __RF_DESENSE_EMI_MIN_CURRENT__ */

#endif /* MT6253 */

#define EMI_GENERAL_CONTROL_MCP$combo_idx          $emi_gen_con_async_53
__TEMPLATE
    }

    ### MT6252/MT6252H
    ### To support Combo Memory
    my $sub_content_emi_setting_52;
    if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252H')
    {
        my $combo_ram_count = ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252') ? ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT}) : ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT});
        foreach (1..$combo_ram_count)
        {
            my $combo_idx = $_ - 1;
            
            my ($emi_cona_async, $emi_conb_async, $emi_conc_async, $emi_extcon_async, $emi_general_control_async, $emi_driving_control_a, $emi_driving_control_b, $emi_driving_control_c);
            my ($emi_cona_page, $emi_conb_page);
            my ($emi_cona_burst, $emi_conb_burst, $emi_extcon_burst, $emi_general_control_burst, $emi_extcon2_burst, $emi_driving_control_a_burst, $emi_driving_control_b_burst);

            my @emi_con_async_cs0 = &split_emi(&Lookup_ASYNC_EMI_setting_by_IDX_CS_BB($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my @emi_con_async_cs1 = &split_emi(&Lookup_ASYNC_EMI_setting_by_IDX_CS_BB($_, 1, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            $emi_cona_async = ((defined $emi_con_async_cs0[0]) and ($emi_con_async_cs0[0] ne 'x')) ? ($emi_con_async_cs0[0]) : (0);
            $emi_conb_async = ((defined $emi_con_async_cs1[0]) and ($emi_con_async_cs1[0] ne 'x')) ? ($emi_con_async_cs1[0]) : (0);
            $emi_extcon_async = ((defined $emi_con_async_cs1[2]) and ($emi_con_async_cs1[2] ne 'x')) ? ($emi_con_async_cs1[2]) : (0);
            $emi_general_control_async = ((defined $emi_con_async_cs1[1]) and ($emi_con_async_cs1[1] ne 'x')) ? ($emi_con_async_cs1[1]) : (0);
            my @emi_driving_control = &split_emi(&Lookup_ASYNC_EMI_driving_by_IDX_CS_BB($_, 1, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            $emi_driving_control_a = ((defined $emi_driving_control[0]) and ($emi_driving_control[0] ne 'x')) ? ($emi_driving_control[0]) : (0);
            $emi_driving_control_b = ((defined $emi_driving_control[1]) and ($emi_driving_control[1] ne 'x')) ? ($emi_driving_control[1]) : (0);
            $emi_driving_control_c = ((defined $emi_driving_control[2]) and ($emi_driving_control[2] ne 'x')) ? ($emi_driving_control[2]) : (0);

            $emi_cona_page = ((defined $emi_con_async_cs0[1]) and ($emi_con_async_cs0[1] ne 'x')) ? ($emi_con_async_cs0[1]) : (0);
            $emi_conb_page = ((defined $emi_con_async_cs1[3]) and ($emi_con_async_cs1[3] ne 'x')) ? ($emi_con_async_cs1[3]) : (0);

            my @emi_con_burst_cs0 = &split_emi(&Lookup_SYNC_EMI_setting_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my @emi_con_burst_cs1 = &split_emi(&Lookup_SYNC_EMI_setting_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            $emi_cona_burst = ((defined $emi_con_burst_cs0[0]) and ($emi_con_burst_cs0[0] ne 'x')) ? ($emi_con_burst_cs0[0]) : (0);
            $emi_conb_burst = ((defined $emi_con_burst_cs1[0]) and ($emi_con_burst_cs1[0] ne 'x')) ? ($emi_con_burst_cs1[0]) : (0);
            $emi_extcon_burst = ((defined $emi_con_burst_cs1[2]) and ($emi_con_burst_cs1[2] ne 'x')) ? ($emi_con_burst_cs1[2]) : (0);
            $emi_general_control_burst = ((defined $emi_con_burst_cs1[1]) and ($emi_con_burst_cs1[1] ne 'x')) ? ($emi_con_burst_cs1[1]) : (0);
            $emi_extcon2_burst = ((defined $emi_con_burst_cs1[3]) and ($emi_con_burst_cs1[3] ne 'x')) ? ($emi_con_burst_cs1[3]) : (0);
        
            my @emi_driving_control_burst = &split_emi(&Lookup_SYNC_EMI_driving_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            $emi_driving_control_a_burst = ((defined $emi_driving_control_burst[0]) and $emi_driving_control_burst[0] ne 'x') ? ($emi_driving_control_burst[0]) : (0);
            $emi_driving_control_b_burst = ((defined $emi_driving_control_burst[1]) and $emi_driving_control_burst[1] ne 'x') ? ($emi_driving_control_burst[1]) : (0);
        
            ###
            my $sync_setting;
            my @op_list_nor = &split_addr_ret_rw(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my @addr_list_nor = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my @data_list_nor = &split_emi(&Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my @op_list_psram = &split_addr_ret_rw(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my @addr_list_psram = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            my @data_list_psram = &split_emi(&Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
            
            for (0..($emi_nor_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                if ($_ > $#op_list_nor)
                {
                    $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_NOP\n";
                }
                elsif ($op_list_nor[$_] eq 'R:')
                {
                    $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_RD\n";
                }
                else
                {
                    $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_WR\n";
                }
            }
            for (0..($emi_nor_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                if ($_ > $#addr_list_nor)
                {
                    $sync_setting .= "#define EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx      0\n";
                }
                else
                {
                    $sync_setting .= "#define EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx      $addr_list_nor[$_]\n";
                }
            }
            for (0..($emi_nor_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                if ($_ > $#data_list_nor)
                {
                    $sync_setting .= "#define EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx         0\n";
                }
                else
                {
                    $sync_setting .= "#define EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx         $data_list_nor[$_]\n";
                }
            }
            for (0..($emi_psram_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                if ($_ > $#op_list_psram)
                {
                    $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_NOP\n";
                }
                elsif ($op_list_psram[$_] eq 'R:')
                {
                    $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_RD\n";
                }
                else
                {
                    $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_WR\n";
                }
            }
            for (0..($emi_psram_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                if ($_ > $#addr_list_psram)
                {
                    $sync_setting .= "#define EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx    0\n";
                }
                else
                {
                    $sync_setting .= "#define EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx    $addr_list_psram[$_]\n";
                }
            }
            for (0..($emi_psram_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                if ($_ > $#data_list_psram)
                {
                    $sync_setting .= "#define EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx      0\n";
                }
                else
                {
                    $sync_setting .= "#define EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx      $data_list_psram[$_]\n";
                }
            }
            chomp $sync_setting;
            
        $sub_content_emi_setting_52 .= <<"__TEMPLATE";
/**
  * MT6253E/L and MT6252(H) has different register field definition to MT6253.
  */
#define EMI_CONA_ASYNC_MCP$combo_idx               $emi_cona_async
#define EMI_CONB_ASYNC_MCP$combo_idx               $emi_conb_async
#define EMI_CONC_ASYNC_MCP$combo_idx               0

#define EMI_EXTCON_ASYNC_MCP$combo_idx             $emi_extcon_async

#define EMI_GENERAL_CONTROL_ASYNC_MCP$combo_idx    $emi_general_control_async

#define EMI_DRIVING_CONTROL_A_MCP$combo_idx        $emi_driving_control_a
#define EMI_DRIVING_CONTROL_B_MCP$combo_idx        $emi_driving_control_b
#define EMI_DRIVING_CONTROL_C_MCP$combo_idx        $emi_driving_control_c

#define EMI_CONA_PAGE_MCP$combo_idx                $emi_cona_page
#define EMI_CONB_PAGE_MCP$combo_idx                $emi_conb_page

/**
  * MT6253E/L and MT6252(H) has different register field definition to MT6253.
  */
#define EMI_CONA_BURST_MCP$combo_idx               $emi_cona_burst
#define EMI_CONB_BURST_MCP$combo_idx               $emi_conb_burst   //Variable latency

#define EMI_EXTCON_BURST_MCP$combo_idx             $emi_extcon_burst

#define EMI_GENERAL_CONTROL_BURST_MCP$combo_idx    $emi_general_control_burst

#define EMI_EXTCON2_BURST_MCP$combo_idx            $emi_extcon2_burst

/**
  * Setup NOR burst control register to LC=5(data \@6T), WRAP32.
  */
/**
  * Setup PSRAM mode register to BRBW mode, wrap-64-bytes, LC=3(data @4T)
  */
$sync_setting

#define EMI_DRIVING_CONTROL_A_BURST_MCP$combo_idx  $emi_driving_control_a_burst
#define EMI_DRIVING_CONTROL_B_BURST_MCP$combo_idx  $emi_driving_control_b_burst
__TEMPLATE
        }
    }

    ### MT6236
    ### To support Combo Memory
    my $sub_content_emi_setting_36;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        
        my ($emi_cona_async_36, $emi_conb_async_36, $emi_gena_val_36, $emi_genb_val_36, $emi_genc_val_36, $emi_gend_val_36, $emi_delj_val_36, $emi_rdct_val_36);
        my ($emi_cona_burst_36, $emi_cone_burst_36, $emi_conb_burst_36, $emi_conf_burst_36, $emi_cona_burst_36_13m, $emi_cone_burst_36_13m, $emi_conb_burst_36_13m, $emi_conf_burst_36_13m);
        my (@driving_list_6236, @nor_setting_list_6236, @psram_setting_list_6236, @nor_setting_list_6236_13m, @psram_setting_list_6236_13m);
    
        if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236B')
        {
            $emi_cona_async_36    = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6236 MT6236B'};
            $emi_conb_async_36    = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6236 MT6236B'};
        }
        elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6921')
        {
            $emi_cona_async_36    = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6921'};
            $emi_conb_async_36    = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6921'};
        }

        if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'ASYNC_ACCESS')
        {
            if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236B')
            {
                @driving_list_6236 = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous Driving Setting'}->{'MT6236 MT6236B'});
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6921')
            {
                @driving_list_6236 = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous Driving Setting'}->{'MT6921'});
            }
        }
        else
        {
            if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236' or $MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236B')
            {
                @nor_setting_list_6236   = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous EMI Setting'}->{'MT6236 MT6236B'});
                @psram_setting_list_6236 = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'104MHz Synchronous EMI Setting'}->{'MT6236 MT6236B'});
                @driving_list_6236       = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous Driving Setting'}->{'MT6236 MT6236B'});
                @nor_setting_list_6236_13m   = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'13MHz Synchronous EMI Setting'}->{'MT6236 MT6236B'});
                @psram_setting_list_6236_13m = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'13MHz Synchronous EMI Setting'}->{'MT6236 MT6236B'});
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6921')
            {
                @nor_setting_list_6236   = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous EMI Setting'}->{'MT6921'});
                @psram_setting_list_6236 = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'104MHz Synchronous EMI Setting'}->{'MT6921'});
                @driving_list_6236       = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous Driving Setting'}->{'MT6921'});
                @nor_setting_list_6236_13m   = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'13MHz Synchronous EMI Setting'}->{'MT6921'});
                @psram_setting_list_6236_13m = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'13MHz Synchronous EMI Setting'}->{'MT6921'});
            }
        }
	    $emi_gena_val_36   = $driving_list_6236[0];
	    $emi_genb_val_36   = $driving_list_6236[1];
	    $emi_genc_val_36   = $driving_list_6236[2];
	    $emi_gend_val_36   = $driving_list_6236[3];
	    $emi_delj_val_36   = $driving_list_6236[4];
	    $emi_rdct_val_36   = $driving_list_6236[5];
	    $emi_cona_burst_36 = $nor_setting_list_6236[0];
	    $emi_cone_burst_36 = $nor_setting_list_6236[1];
	    $emi_conb_burst_36 = $psram_setting_list_6236[0];
	    $emi_conf_burst_36 = $psram_setting_list_6236[1];
	    $emi_cona_burst_36_13m = $nor_setting_list_6236_13m[0];
	    $emi_cone_burst_36_13m = $nor_setting_list_6236_13m[1];
	    $emi_conb_burst_36_13m = $psram_setting_list_6236_13m[0];
	    $emi_conf_burst_36_13m = $psram_setting_list_6236_13m[1];

        ###
        my $sync_setting;
        my @op_list_nor = &split_addr_ret_rw(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @addr_list_nor = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @data_list_nor = &split_emi(&Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @op_list_psram = &split_addr_ret_rw(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @addr_list_psram = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @data_list_psram = &split_emi(&Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        
        for (0..($emi_nor_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#op_list_nor)
            {
                $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_NOP\n";
            }
            elsif ($op_list_nor[$_] eq 'R:')
            {
                $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_RD\n";
            }
            else
            {
                $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_WR\n";
            }
        }
        for (0..($emi_nor_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#addr_list_nor)
            {
                $sync_setting .= "#define EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx      0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx      $addr_list_nor[$_]\n";
            }
        }
        for (0..($emi_nor_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#data_list_nor)
            {
                $sync_setting .= "#define EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx         0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx         $data_list_nor[$_]\n";
            }
        }
        for (0..($emi_psram_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#op_list_psram)
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_NOP\n";
            }
            elsif ($op_list_psram[$_] eq 'R:')
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_RD\n";
            }
            else
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_WR\n";
            }
        }
        for (0..($emi_psram_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#addr_list_psram)
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx    0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx    $addr_list_psram[$_]\n";
            }
        }
        for (0..($emi_psram_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#data_list_psram)
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx      0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx      $data_list_psram[$_]\n";
            }
        }
        chomp $sync_setting;

        $sub_content_emi_setting_36 .= <<"__TEMPLATE";
/* start of MCP$combo_idx */

/* EMI_GENA value */
#define EMI_GENERAL_A_VAL_MCP$combo_idx            $emi_gena_val_36
/* EMI_GENA value */
#define EMI_GENERAL_B_VAL_MCP$combo_idx            $emi_genb_val_36
/* EMI_GENA value */
#define EMI_GENERAL_C_VAL_MCP$combo_idx            $emi_genc_val_36
/* EMI_GEND value */
#define EMI_GENERAL_D_VAL_MCP$combo_idx            $emi_gend_val_36

/* EMI_DELJ value */
#define EMI_DELAY_J_VAL_MCP$combo_idx              $emi_delj_val_36

/* NOR async */
#define EMI_CONA_ASYNC_MCP$combo_idx               $emi_cona_async_36

/* PSRAM async */
#define EMI_CONB_ASYNC_MCP$combo_idx               $emi_conb_async_36

/* NOR burst */
#define EMI_CONA_BURST_MCP$combo_idx               $emi_cona_burst_36
#define EMI_CONE_BURST_MCP$combo_idx               $emi_cone_burst_36

/* PSRAM burst */
#define EMI_CONB_BURST_MCP$combo_idx               $emi_conb_burst_36
#define EMI_CONF_BURST_MCP$combo_idx               $emi_conf_burst_36

/* NOR burst */
#define EMI_CONA_BURST_13MHZ_MCP$combo_idx         $emi_cona_burst_36_13m
#define EMI_CONE_BURST_13MHZ_MCP$combo_idx         $emi_cone_burst_36_13m

/* PSRAM burst */
#define EMI_CONB_BURST_13MHZ_MCP$combo_idx         $emi_conb_burst_36_13m
#define EMI_CONF_BURST_13MHZ_MCP$combo_idx         $emi_conf_burst_36_13m

#define EMI_RDCT_VAL_MCP$combo_idx                 $emi_rdct_val_36

$sync_setting
__TEMPLATE
    }

    ###
    my $default_value  = 0x03030103;
    my ($i_psize, $d_psize, @temp_cs0_emi, @temp_cs1_emi);
    @temp_cs0_emi = &Lookup_ASYNC_EMI_setting_by_IDX_CS_BB(1, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'});
    @temp_cs1_emi = &Lookup_ASYNC_EMI_setting_by_IDX_CS_BB(1, 1, $MAKEFILE_OPTIONS_LOCAL->{'platform'});
    if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6253')
    {
          $i_psize = hex($temp_cs0_emi[0]) & 0x20;
          $d_psize = hex($temp_cs1_emi[0]) & 0x20;
    }
    if ($i_psize == 0)  # set IWRP8 to 0
    {
          $default_value = $default_value & 0xFFFFFFFB;
    }
    else  # set IWRP8 to 1
    {
          $default_value = $default_value | 0x4;  # set IWRP8 to 16
    }
    if ($d_psize == 0)  # set DWRP8 to 0
    {
          $default_value = $default_value & 0xFFFBFFFF;
    }
    else
    {
          if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6253')
          {
                $default_value = $default_value | 0x40000;  # set DWRP8 to 16
          }
          else
          {
              $default_value = $default_value & 0xFFFBFFFF;  # set DWRP8 to 8
          }
    }
#    if ($part_info->{CS}->{0}->{PAGE_SIZE} == 16)
#    {
#        $default_value = $default_value | 0x4;
#    }
#    elsif ($part_info->{CS}->{1}->{PAGE_SIZE} == 16)
#    {
#        $default_value = $default_value | 0x40000;
#    }
    my $cache_prefetch = sprintf("0x%08X", $default_value);

    ###
    
    my $template = <<"__TEMPLATE";
#if defined(MT6253)

$sub_content_emi_setting_53

#define EMI_CACHE_PREFETCH           $cache_prefetch

#define BANK0_NEGSEL_p               16
#define BANK1_NEGSEL_p               17
#define EMI_COMPARE_PATTERN          0x5AA5FF00

#elif ( defined(MT6252H) || defined(MT6252) )

$sub_content_emi_setting_52

#elif ( defined(MT6236) || defined(MT6236B) )

$sub_content_emi_setting_36

#else

#error "Undefined BB chips !"

#endif
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  emi_setting_on_chip_select
# return:      EMI setting section
#****************************************************************************
sub emi_setting_on_chip_select
{
    ### ? 
#    my $setting_func = sub { 
#       my ($platform) = @_;
#       my $content;
#       for (0..3)
#       {
#           my $emi_setting_value = '0';
#           if (defined &Lookup_ASYNC_EMI_setting_by_IDX_CS_BB($_, $platform))
#           {
#               $emi_setting_value = &Lookup_ASYNC_EMI_setting_by_CS_BB($_, $platform);
#               $emi_setting_value =~ s/(0x\w+)\W.*/$1/;
#           }
#           if ($MEM_DEV_LIST_INFO{$_}->{'DRAM'} eq 'YES')
#           {
#              $emi_setting_value = '0';
#           }
#           $content .=  (($_<=2) ? "   $emi_setting_value,\n" : "   $emi_setting_value\n");
#       }
#       return $content;
#    };
    ###

#    my $emi_setting_6223  = &$setting_func('MT6223');
#    my $emi_setting_6235  = &$setting_func('MT6235');

#    chomp $emi_setting_6223 ;
#    chomp $emi_setting_6235 ;
    ###
    my $template = <<"__TEMPLATE";
#if ( defined(MT6235) || defined(MT6235B) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   1,
   1,
   0,
   0
};

#elif ( defined(MT6236) || defined(MT6236B) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   1,
   1,
   0,
   0
};

#elif ( defined(MT6253) || defined(MT6252H) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   1,
   1,
   0,
   0
};

#elif ( defined(MT6252) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   0,
   1,
   0,
   0
};

#elif ( defined(MT6255) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   EMI_CONA_ASYNC,
   EMI_CONB_ASYNC,
   0,
   0
};

#endif

__TEMPLATE

    return $template;
}



#****************************************************************************
# subroutine:  HeaderBody_for_lpsdram
# return:      content for custom_EMI.h 
#****************************************************************************
sub HeaderBody_for_lpsdram
{
    ### EMI register value for each MCP
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL) = @_;
    my $combo_mem_emi_reg;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
	my ($ref_con, $dram_mode, $dram_ext_mode, $dram_ctrl, $gen_ctrla, $gen_ctrlb, $gen_ctrlc);  # ARM7 series
        my ($dram_gena, $dram_genb, $dram_genc, $dram_gend, $dram_coni, $dram_conj, $dram_conk, $dram_conl, $dram_conm, $dram_conn, $dram_gena_13, $dram_genb_13, $dram_genc_13, $dram_conj_13, $dram_conk_13, $dram_conl_13, $dram_conm_13);  # 35/38 series
	my ($dram_dela, $dram_delb, $dram_delc, $dram_deld, $dram_dele, $dram_delf, $dram_delg, $dram_delh, $dram_deli, $dram_delj, $dram_arba, $dram_arbb, $dram_arbc, $dram_arbd, $dram_arbe, $dram_arbf, $dram_arbg, $dram_arbh, $dram_arbi, $dram_conj_15_36, $dram_conl_15_36, $dram_conj_30_72, $dram_conl_30_72);
	my ($dram_conj_13, $dram_conl_13);
	my ($dram_drva_166, $dram_drvb_166, $dram_odla_166, $dram_odlb_166, $dram_odlc_166, $dram_odld_166, $dram_odle_166, $dram_odlf_166, $dram_odlg_166, $dram_coni_166, $dram_conj_166, $dram_conk_166, $dram_conl_166, $dram_conn_166, $dram_iodutya_166, $dram_iodutyb_166, $dram_iodutyc_166, $dram_rxdutya_166, $dram_rxdutyb_166, $dram_rxdutye_166, $dram_iomiscl_166);
	my ($dram_drva_200, $dram_drvb_200, $dram_odla_200, $dram_odlb_200, $dram_odlc_200, $dram_odld_200, $dram_odle_200, $dram_odlf_200, $dram_odlg_200, $dram_coni_200, $dram_conj_200, $dram_conk_200, $dram_conl_200, $dram_conn_200, $dram_iodutya_200, $dram_iodutyb_200, $dram_iodutyc_200, $dram_rxdutya_200, $dram_rxdutyb_200, $dram_rxdutye_200, $dram_iomiscl_200);

	if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6235B') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6238') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6239'))
	{
	    ### 35/38 series
	    $dram_gena     = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_genb     = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_genc     = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_gend     = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GEND_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_coni     = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conj     = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conk     = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conl     = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conm     = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONM_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conn     = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
      $dram_gena_13  = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
      $dram_genb_13  = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
      $dram_genc_13  = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
      $dram_conj_13  = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
      $dram_conk_13  = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
      $dram_conl_13  = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
      $dram_conm_13  = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONM_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	}
	elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6268')
	{
	    ### 6268 series
	    $dram_gena       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_genb       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_genc       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_gend       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GEND_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_coni       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conj       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 122.88, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conk       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conl       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 122.88, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conn       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_dela       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delb       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delc       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_deld       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELD_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_dele       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delf       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELF_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delg       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELG_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delh       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELH_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_deli       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delj       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_arba       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ARBA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_arbb       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ARBB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_arbc       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ARBC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_arbd       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ARBD_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_arbe       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ARBE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_arbf       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ARBF_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_arbg       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ARBG_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_arbh       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ARBH_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_arbi       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ARBI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conj_15_36 = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 15.36, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conl_15_36 = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 15.36, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conj_30_72 = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 30.72, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conl_30_72 = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 30.72, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	}
	elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6236B'))
	{
	    ### 6236 series
	    $dram_gena       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_genb       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_genc       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GENC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_gend       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_GEND_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_coni       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conj       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conk       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conl       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conn       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_dela       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delb       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delc       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_deld       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELD_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_dele       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delf       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELF_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delg       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELG_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delh       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELH_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_deli       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_delj       = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 0, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DELJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conj_13    = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	    $dram_conl_13    = &Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL);
	}
	elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6276')
	{
	    ### 6276 series
	    $dram_drva_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drvb_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odla_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlb_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlc_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_C_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odld_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_D_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odle_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_E_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlf_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_F_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlg_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_G_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_coni_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conj_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conk_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conl_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conn_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutya_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyb_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyc_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutya_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutyb_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutye_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iomiscl_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_IOCL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drva_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drvb_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odla_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlb_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlc_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_C_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odld_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_D_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odle_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_E_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlf_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_F_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlg_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_G_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_coni_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conj_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conk_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conl_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conn_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutya_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyb_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyc_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutya_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutyb_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutye_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iomiscl_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_IOCL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	}

        $combo_mem_emi_reg .= <<"__TEMPLATE";
   /**
      * EMI/MEM configuration information of MCP$combo_idx
      */
      
#if (defined(MT6235) || defined(MT6235B))
/* EMI_GENA value */
#define EMI_GENERAL_A_VAL_MCP$combo_idx         $dram_gena
/* EMI_GENB value */
#define EMI_GENERAL_B_VAL_MCP$combo_idx         $dram_genb
/* EMI_GENC value */
#define EMI_GENERAL_C_VAL_MCP$combo_idx         $dram_genc
/* EMI_GEND value */
#define EMI_GENERAL_D_VAL_MCP$combo_idx         $dram_gend
/* EMI_CONI value */
#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni
/* EMI_CONJ value */
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj
/* EMI_CONK value */
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk
/* EMI_CONL value */
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl
/* EMI_CONM value */
#define EMI_CONTROL_M_VAL_MCP$combo_idx         $dram_conm
/* EMI_CONN value */
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn

/* EMI_GENA value */
#define EMI_GENERAL_A_13_VAL_MCP$combo_idx      $dram_gena_13
/* EMI_GENB value */
#define EMI_GENERAL_B_13_VAL_MCP$combo_idx      $dram_genb_13
/* EMI_GENC value */
#define EMI_GENERAL_C_13_VAL_MCP$combo_idx      $dram_genc_13

/* EMI_CONJ value */
#define EMI_CONTROL_J_13_VAL_MCP$combo_idx      $dram_conj_13
/* EMI_CONK value */
#define EMI_CONTROL_K_13_VAL_MCP$combo_idx      $dram_conk_13
/* EMI_CONL value */
#define EMI_CONTROL_L_13_VAL_MCP$combo_idx      $dram_conl_13
/* EMI_CONM value */
#define EMI_CONTROL_M_13_VAL_MCP$combo_idx      $dram_conm_13

#elif defined(MT6268) /* MT6235 || MT6235B */
/* EMI_GENA value */
#define EMI_GENERAL_A_VAL_MCP$combo_idx         $dram_gena
/* EMI_GENB value */
#define EMI_GENERAL_B_VAL_MCP$combo_idx         $dram_genb
/* EMI_GENC value */
#define EMI_GENERAL_C_VAL_MCP$combo_idx         $dram_genc
/* EMI_GEND value */
#define EMI_GENERAL_D_VAL_MCP$combo_idx         $dram_gend

/* EMI_CONI value */
#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni
/* EMI_CONJ value */
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj
/* EMI_CONK value */
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk
/* EMI_CONL value */
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl
/* EMI_CONM value */
#define EMI_CONTROL_M_VAL_MCP$combo_idx         0x00000000
/* EMI_CONN value */
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn

/* EMI_DELA value */
#define EMI_DELAY_A_VAL_MCP$combo_idx           $dram_dela
/* EMI_DELB value */
#define EMI_DELAY_B_VAL_MCP$combo_idx           $dram_delb
/* EMI_DELC value */
#define EMI_DELAY_C_VAL_MCP$combo_idx           $dram_delc
/* EMI_DELD value */
#define EMI_DELAY_D_VAL_MCP$combo_idx           $dram_deld
/* EMI_DELE value */
#define EMI_DELAY_E_VAL_MCP$combo_idx           $dram_dele
/* EMI_DELF value */
#define EMI_DELAY_F_VAL_MCP$combo_idx           $dram_delf
/* EMI_DELG value */
#define EMI_DELAY_G_VAL_MCP$combo_idx           $dram_delg
/* EMI_DELH value */
#define EMI_DELAY_H_VAL_MCP$combo_idx           $dram_delh
/* EMI_DELI value */
#define EMI_DELAY_I_VAL_MCP$combo_idx           $dram_deli
/* EMI_DELJ value */
#define EMI_DELAY_J_VAL_MCP$combo_idx           $dram_delj

/* EMI_ARB_A value */
#define EMI_ARB_A_VAL_MCP$combo_idx             $dram_arba
/* EMI_ARB_B value */
#define EMI_ARB_B_VAL_MCP$combo_idx             $dram_arbb
/* EMI_ARB_C value */
#define EMI_ARB_C_VAL_MCP$combo_idx             $dram_arbc
/* EMI_ARB_D value */
#define EMI_ARB_D_VAL_MCP$combo_idx             $dram_arbd
/* EMI_ARB_E value */
#define EMI_ARB_E_VAL_MCP$combo_idx             $dram_arbe
/* EMI_ARB_F value */
#define EMI_ARB_F_VAL_MCP$combo_idx             $dram_arbf
/* EMI_ARB_G value */
#define EMI_ARB_G_VAL_MCP$combo_idx             $dram_arbg
/* EMI_ARB_H value */
#define EMI_ARB_H_VAL_MCP$combo_idx             $dram_arbh
/* EMI_ARB_I value */
#define EMI_ARB_I_VAL_MCP$combo_idx             $dram_arbi

/* EMI_CONJ 15.36MHz value */
#define EMI_CONTROL_J_15_36_VAL_MCP$combo_idx   $dram_conj_15_36
/* EMI_CONL 15.36MHz value */
#define EMI_CONTROL_L_15_36_VAL_MCP$combo_idx   $dram_conl_15_36

/* EMI_CONJ 30.72MHz value */
#define EMI_CONTROL_J_30_72_VAL_MCP$combo_idx   $dram_conj_30_72
/* EMI_CONL 30.72MHz value */
#define EMI_CONTROL_L_30_72_VAL_MCP$combo_idx   $dram_conl_30_72

#elif (defined(MT6236) || defined(MT6236B)) /* MT6235 || MT6235B */
/* EMI_GENA value */
#define EMI_GENERAL_A_VAL_MCP$combo_idx         $dram_gena
/* EMI_GENB value */
#if defined(__RF_DESENSE_EMI_MIN_CURRENT__)
#define EMI_GENERAL_B_VAL_MCP$combo_idx         0x00CCCCC0 // 4mA (slow)
#elif defined(__RF_DESENSE_EMI_2MA_CTRL_CURRENT__)
#define EMI_GENERAL_B_VAL_MCP$combo_idx         0x00888880 // 2mA (slow)
#else
#define EMI_GENERAL_B_VAL_MCP$combo_idx         $dram_genb
#endif
/* EMI_GENC value */
#if defined(__RF_DESENSE_EMI_MIN_CURRENT__)
#define EMI_GENERAL_C_VAL_MCP$combo_idx         0x00CCCC0C // 4mA (slow)
#elif defined(__RF_DESENSE_EMI_2MA_CTRL_CURRENT__)
#define EMI_GENERAL_C_VAL_MCP$combo_idx         0x00888808 // 2mA (slow)
#else
#define EMI_GENERAL_C_VAL_MCP$combo_idx         $dram_genc
#endif
/* EMI_GEND value */
#define EMI_GENERAL_D_VAL_MCP$combo_idx         $dram_gend

/* EMI_CONI value */
#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni
/* EMI_CONJ value */
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj
/* EMI_CONK value */
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk
/* EMI_CONL value */
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl
/* EMI_CONM value */
#define EMI_CONTROL_M_VAL_MCP$combo_idx         0x00000000
/* EMI_CONN value */
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn

/* EMI_DELA value */
#define EMI_DELAY_A_VAL_MCP$combo_idx           $dram_dela
/* EMI_DELB value */
#define EMI_DELAY_B_VAL_MCP$combo_idx           $dram_delb
/* EMI_DELC value */
#define EMI_DELAY_C_VAL_MCP$combo_idx           $dram_delc
/* EMI_DELD value */
#define EMI_DELAY_D_VAL_MCP$combo_idx           $dram_deld
/* EMI_DELE value */
#define EMI_DELAY_E_VAL_MCP$combo_idx           $dram_dele
/* EMI_DELF value */
#define EMI_DELAY_F_VAL_MCP$combo_idx           $dram_delf
/* EMI_DELG value */
#define EMI_DELAY_G_VAL_MCP$combo_idx           $dram_delg
/* EMI_DELH value */
#define EMI_DELAY_H_VAL_MCP$combo_idx           $dram_delh
/* EMI_DELI value */
#define EMI_DELAY_I_VAL_MCP$combo_idx           $dram_deli
/* EMI_DELJ value */
#define EMI_DELAY_J_VAL_MCP$combo_idx           $dram_delj

/* EMI_CONJ 13MHz value */
#define EMI_CONTROL_J_13_VAL_MCP$combo_idx      $dram_conj_13
/* EMI_CONL 13MHz value */
#define EMI_CONTROL_L_13_VAL_MCP$combo_idx      $dram_conl_13

#elif defined(MT6276) /* MT6235 || MT6235B */

#if defined(__EMI_CLK_166MHZ__)

#define EMI_DRV_A_VAL_MCP$combo_idx             $dram_drva_166
#define EMI_DRV_B_VAL_MCP$combo_idx             $dram_drvb_166

#define EMI_ODL_A_VAL_MCP$combo_idx             $dram_odla_166
#define EMI_ODL_B_VAL_MCP$combo_idx             $dram_odlb_166
#define EMI_ODL_C_VAL_MCP$combo_idx             $dram_odlc_166
#define EMI_ODL_D_VAL_MCP$combo_idx             $dram_odld_166
#define EMI_ODL_E_VAL_MCP$combo_idx             $dram_odle_166
#define EMI_ODL_F_VAL_MCP$combo_idx             $dram_odlf_166    // only used on LPDDR2
#define EMI_ODL_G_VAL_MCP$combo_idx             $dram_odlg_166

#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni_166
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj_166
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk_166
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl_166
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn_166

#define EMI_IODUTY_A_VAL_MCP$combo_idx          $dram_iodutya_166
#define EMI_IODUTY_B_VAL_MCP$combo_idx          $dram_iodutyb_166
#define EMI_IODUTY_C_VAL_MCP$combo_idx          $dram_iodutyc_166

#define EMI_RXDUTY_A_VAL_MCP$combo_idx          $dram_rxdutya_166
#define EMI_RXDUTY_B_VAL_MCP$combo_idx          $dram_rxdutyb_166
#define EMI_RXDUTY_E_VAL_MCP$combo_idx          $dram_rxdutye_166

#define EMI_IOMISC_L_VAL_MCP$combo_idx          $dram_iomiscl_166

//#define EMI_DQS_A_VAL     0x28282828

#elif defined(__EMI_CLK_200MHZ__)/* __EMI_CLK_166MHZ__ */

#define EMI_DRV_A_VAL_MCP$combo_idx             $dram_drva_200
#define EMI_DRV_B_VAL_MCP$combo_idx             $dram_drvb_200

#define EMI_ODL_A_VAL_MCP$combo_idx             $dram_odla_200
#define EMI_ODL_B_VAL_MCP$combo_idx             $dram_odlb_200
#define EMI_ODL_C_VAL_MCP$combo_idx             $dram_odlc_200
#define EMI_ODL_D_VAL_MCP$combo_idx             $dram_odld_200
#define EMI_ODL_E_VAL_MCP$combo_idx             $dram_odle_200
#define EMI_ODL_F_VAL_MCP$combo_idx             $dram_odlf_200    // only used on LPDDR2
#define EMI_ODL_G_VAL_MCP$combo_idx             $dram_odlg_200

#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni_200
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj_200
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk_200
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl_200
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn_200

#define EMI_IODUTY_A_VAL_MCP$combo_idx          $dram_iodutya_200
#define EMI_IODUTY_B_VAL_MCP$combo_idx          $dram_iodutyb_200
#define EMI_IODUTY_C_VAL_MCP$combo_idx          $dram_iodutyc_200

#define EMI_RXDUTY_A_VAL_MCP$combo_idx          $dram_rxdutya_200
#define EMI_RXDUTY_B_VAL_MCP$combo_idx          $dram_rxdutyb_200
#define EMI_RXDUTY_E_VAL_MCP$combo_idx          $dram_rxdutye_200

#define EMI_IOMISC_L_VAL_MCP$combo_idx          $dram_iomiscl_200

//#define EMI_DQS_A_VAL     0x28282828

#endif /* __EMI_CLK_166MHZ__ */

#else /* MT6235 || MT6235B */

  #error "undefined BB chip !!"

#endif /* MT6235 || MT6235B */

   /**
      * End of EMI/MEM configuration information of MCP$combo_idx
      */
__TEMPLATE
    }

    ###
    my $template = <<"__TEMPLATE";
/****************************************************************************
   *
   * Definition.
   *
   ****************************************************************************/

#define DRAM_CS                   $LPSDRAM_CHIP_SELECT_LOCAL

/**
    * On new format, it has been replaced with EMI_EXTSRAM_SIZE defined at custom_emi_release.h, 
    * but we still keep it and will remove this definition when phasing in auto-gen.
    */
#define DRAM_SIZE                 $COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}  /* Density of LPSDRAM,in terms of Mbits */
$physical_ram_density

/****************************************************************************
   *
   * Macro.
   *
   ****************************************************************************/

#define __EMI_DelayLoop(dly_val) \\
    do { \\
        kal_int32 dly; \\
        for(dly = dly_val; dly != 0; dly--); \\
    } while(0)


/****************************************************************************
   *
   * Struct
   *
   ****************************************************************************/

typedef struct 
{
    unsigned long EMI_DLLV_regval;
    unsigned long EMI_DQSV_regval;    
    unsigned long EMI_CONN_regval;        
    unsigned long EMI_DQSA_regval;
    unsigned long EMI_DQSE_regval;   
    unsigned long EMI_IDLA_regval;
    unsigned long EMI_IDLB_regval;
    unsigned long EMI_IDLC_regval;
    unsigned long EMI_IDLD_regval;
    unsigned long EMI_IDLE_regval;
    unsigned long EMI_IDLF_regval;
    unsigned long EMI_IDLG_regval;
    unsigned long EMI_IDLH_regval;
    unsigned long EMI_IDLI_regval;    
    unsigned long EMI_CALA_regval;
    unsigned long EMI_CALE_regval;
    unsigned long EMI_CALI_regval;
    unsigned long EMI_CALP_regval;    
} EMI_DATA_TRAIN_REG_t;


typedef struct 
{
    kal_int32 algo_sel;
    kal_int32 addr_scramble_sel;
    kal_int32 data_scramble_sel;
    kal_uint32 err_addr;
    kal_uint32  err_wdataL;
    kal_uint32 err_wdataH;
    kal_uint32 err_rdataL;
    kal_uint32 err_rdataH;
} EMI_DATA_TRAIN_ERR_INFO_t;


/****************************************************************************
   *
   * EMI register value definition.
   *
   ****************************************************************************/

$combo_mem_emi_reg

#if defined(MT6276)
/**
  * EMI bandwidth limiter setting.
  * At DVT stage, we always set as hard mode to ensure each subsystem's requested EMI bandwidth is absolutly correct.
  * 1. ARM: 30.5% (request 30%), hard-mode.
  * 2. FCORE: 12.5% (request 12%), hard-mode.
  * 3. Fcore DMA: 0% (request 0%), soft-mode, whihc means it is not guaranteed ANY bandwidth, but can still use soft mode BW for testing.
  * 4. 2G+3G: 5.5% (request 5.17%), hard-mode.
  * 5. MM: 28.9% (request 28.29%), hard-mode.
  * 6. PERI: 11.7% (request 11.44%), hard-mode.
  *
  * E2: 
  *  M0 ARM
  *  M1 Fcore
  *  M2 2G/3G/Audio
  *  M3 Peripheral
  *  M4 MM
  *
  */
#define SOFT_MODE_FOR_MP

#if defined(MT6276_S00)

#if defined(SOFT_MODE_FOR_MP)
#define EMI_ARB_A_VAL                           0x00001827   // ARM
#else
#define EMI_ARB_A_VAL                           0x00005827   // ARM
#endif
#define EMI_ARB_B_VAL                           0x00001010   // FCore
#define EMI_ARB_C_VAL                           0x00005000   // FCore-DMA
#define EMI_ARB_D_VAL                           0x00001007   // 2G/3G
#define EMI_ARB_E_VAL                           0x00001025   // MM
#define EMI_ARB_F_VAL                           0x0000100F   // Peri./Audio/ARM-DMA

#else /* MT6276_S00 */

#if defined(SOFT_MODE_FOR_MP)
  #define EMI_ARB_A_VAL                         0x00005826   // ARM
  #define EMI_ARB_B_VAL                         0x00005011   // FCore
  #define EMI_ARB_D_VAL                         0x0000500A   // PERI/ADUIO/ARM-DMA
#else
  #define EMI_ARB_A_VAL                         0x00001826   // ARM
  #define EMI_ARB_B_VAL                         0x00001011   // FCore
  #define EMI_ARB_D_VAL                         0x0000100A   // PERI/ADUIO/ARM-DMA
#endif

#define EMI_ARB_C_VAL                           0x00001007   // 2G/3G
#define EMI_ARB_E_VAL                           0x00001035   // MM
#define EMI_ARB_F_VAL                           0x00000000   // RESERVED

/* for MT6276M */
#define EMI_ARB_A_VAL_MT6276M                   0x00005835  // ARM: 41.4% (request 41%), soft-mode
#define EMI_ARB_E_VAL_MT6276M                   0x00005000  // MM: 0%, soft-mode

#endif /* MT6276_S00 */

/**
  * Bit position of EMI limiter.
  * It is for DVT usage only and is used to switch EMI limiter between soft mode and hard mode.
  */
#define EMI_ARB_SOFT_MODE_EN_SHIFT              14

#endif /* MT6276 */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  mcp_admux
# return:      template of part "RAM size in Bytes"
#****************************************************************************
sub mcp_admux
{
    my $template = <<"__TEMPLATE";
/*
 ****************************************************************************
 Specify if ADMUX device is applied
 If it is supported, define ADMUX_MCP
 ****************************************************************************
*/
#define ADMUX_MCP
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  split_addr
# return:      List of EMI Setting Address/Driving
# input:       $addr: Excel value to be split
#****************************************************************************
sub split_addr
{
    my ($addr) = @_;
    my @addr_list;
    my $tmp_addr;
    my @ret_addr;

    @addr_list = split /\s/, $addr;
    
    foreach (@addr_list)
    {
        if ($_ eq 'x')
        {
            push @ret_addr, $_;
            return @ret_addr;
        }
        
        $tmp_addr = $_;
        while ($tmp_addr =~ /([RW]:)*(0x\w+)/)
        {
             push @ret_addr, $2;
             $tmp_addr = $';
        }
        if ($tmp_addr =~ /([RW]:)*(\d+)/)
        {
             push @ret_addr, $2;
        }
    }
    return @ret_addr;
}

#****************************************************************************
# subroutine:  split_addr_ret_rw
# return:      Read/Write sequence of the input address pairs
# input:       $addr: Excel value to be split
#****************************************************************************
sub split_addr_ret_rw
{
    my ($addr) = @_;
    my @addr_list;
    my $tmp_addr;
    my @ret_addr;

    @addr_list = split /\s/, $addr;
    
    foreach (@addr_list)
    {
        if ($_ eq 'x')
        {
            return @ret_addr;
        }
        
        $tmp_addr = $_;

        while ($tmp_addr =~ /([RW]:)*(0x\w+)/)
        {
             push @ret_addr, $1;
             $tmp_addr = $';
        }
        if ($tmp_addr =~ /([RW]:)*(\d+)/)
        {
             push @ret_addr, $1;
        }
    }
    return @ret_addr;
}

#****************************************************************************
# subroutine:  split_emi
# return:      List of EMI Setting/Driving
# input:       $emi: Excel value to be split
#****************************************************************************
sub split_emi
{
    my ($emi) = @_;
    my @emi_list;
    my $tmp_emi;
    my @ret_emi;

    @emi_list = split /\s/, $emi;
    
    foreach (@emi_list)
    {
        if ($_ eq 'x')
        {
            push @ret_emi, $_;
            return @ret_emi;
        }
        
        $tmp_emi = $_;
        while ($tmp_emi =~ /(0x\w+)/)
        {
             push @ret_emi, $1;
             $tmp_emi = $';
        }
        if ($tmp_emi =~ /(\d+)/)
        {
             push @ret_emi, $1;
        }
    }
    return @ret_emi;
}

#****************************************************************************
# subroutine:  custom_EMI_info_h_file_body
# return:      
# input:       
#****************************************************************************
sub custom_EMI_info_h_56_file_body
{
	 my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL) = @_;
	 my $combo_mem_emi_info_struct;
	 my $combo_mei_emi_count;
	 if($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT} ne '0')
	 {
	     $combo_mei_emi_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT};	
	 }
	 else
	 {
	 	   $combo_mei_emi_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT};
	 }
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        
        $combo_mem_emi_info_struct .= <<"__TEMPLATE";
   /**
      * EMI/MEM configuration information of MCP$combo_idx
      */
   "EMI_INF",
   
   EMI_DRV_A_VAL_MCP$combo_idx,
   EMI_DRV_B_VAL_MCP$combo_idx,

   EMI_ODL_A_VAL_MCP$combo_idx,
   EMI_ODL_B_VAL_MCP$combo_idx,
   EMI_ODL_C_VAL_MCP$combo_idx,
   EMI_ODL_D_VAL_MCP$combo_idx,
   EMI_ODL_E_VAL_MCP$combo_idx,
   EMI_ODL_F_VAL_MCP$combo_idx,
   EMI_ODL_G_VAL_MCP$combo_idx,

   EMI_CONTROL_I_VAL_MCP$combo_idx,
   EMI_CONTROL_J_VAL_MCP$combo_idx,
   EMI_CONTROL_K_VAL_MCP$combo_idx,
   EMI_CONTROL_L_VAL_MCP$combo_idx,
   EMI_CONTROL_N_VAL_MCP$combo_idx,

   EMI_IODUTY_A_VAL_MCP$combo_idx,
   EMI_IODUTY_B_VAL_MCP$combo_idx,  
   EMI_IODUTY_C_VAL_MCP$combo_idx,
   
   EMI_RXDUTY_A_VAL_MCP$combo_idx,
   EMI_RXDUTY_B_VAL_MCP$combo_idx,  
   EMI_RXDUTY_E_VAL_MCP$combo_idx,
   
   EMI_IOMISC_L_VAL_MCP$combo_idx,
   
   /**
      * End of EMI/MEM configuration information of MCP$combo_idx
      */
__TEMPLATE
    }
	 
	 ###for combo memory 13mhz
    my $combo_mem_dcm_ctrl_struct_56;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";

        $combo_mem_dcm_ctrl_struct_56 .= <<"__TEMPLATE";
   {
      EMI_CONTROL_J_VAL_MCP$combo_idx,
      EMI_CONTROL_K_VAL_MCP$combo_idx,
      EMI_CONTROL_L_VAL_MCP$combo_idx,
      EMI_CONTROL_J_13_VAL_MCP$combo_idx,
      EMI_CONTROL_K_13_VAL_MCP$combo_idx,
      EMI_CONTROL_L_13_VAL_MCP$combo_idx,
      EMI_CONTROL_J_156_VAL_MCP$combo_idx,
      EMI_CONTROL_K_156_VAL_MCP$combo_idx,
      EMI_CONTROL_L_156_VAL_MCP$combo_idx
   }$comma
__TEMPLATE
    }
    
	 my $template = <<"__TEMPLATE";
	 
#if defined(MT6256)

#ifndef __CUSTOM_EMI_LIST__
#define __CUSTOM_EMI_LIST__

#include "kal_general_types.h"
#include "MemoryDevice_TypeDef.h"

/**
  *    for definition of COMBO_MEM_ENTRY_COUNT and __EMI_DEVICE_MODE_BURST__
  */
#include "custom_MemoryDevice.h"
#include "custom_EMI_release.h"
#include "custom_EMI.h"

#ifdef __SV5_ENABLED__
#include "br_GFH_emi_list.h"
#include "br_GFH.h"
#endif /* __SV5_ENABLED__ */

#ifdef __SV5_ENABLED__ // SV5 will always with __UBL__
#pragma arm section rodata = "BOOTLOADER_GFH_EXT"
#else
#pragma arm section rodata = "SECOND_PART"
#endif // __SV5_ENABLED__

#ifdef __SV5_ENABLED__ 
    const GFH_EMI_LIST_v5 EMI_INFO_2 =
#else /* __SV5_ENABLED__ */
  const MTK_EMI_List EMI_INFO_2 =
#endif /* __SV5_ENABLED__ */
{
#ifdef __SV5_ENABLED__
    GFH_HEADER(GFH_EMI_LIST, 5),  
#else
   "MTK_CMB_EMI_LST",
#endif

   // chip_ver
   5,
   // op_ver
   #if defined(__EMI_DEVICE_LPDDR1__) && defined(__EMI_CLK_166MHZ__)
   0x01,
   #elif defined(__EMI_DEVICE_LPDDR1__) && defined(__EMI_CLK_200MHZ__)
   0x02,
   #elif defined(__EMI_DEVICE_LPDDR2__) && defined(__EMI_CLK_166MHZ__) 
   0x11,
   #elif defined(__EMI_DEVICE_LPDDR2__) && defined(__EMI_CLK_200MHZ__) 
   0x12,
   #else
   0,
   #endif
   
   0, // reserved_1
   0, // reserved_2

   $combo_mei_emi_count, // mcp_num
$combo_mem_emi_info_struct
}; /* End of EMI_INFO_2 */

#pragma arm section rodata
//#if defined(DCM_ENABLE)

#if defined(__EMI_COMBO_EN)
MTK_EMI_DCM_Ctrl __EMI_DCM_control[__EMI_COMBO_ENTRY_COUNT] = 
{
$combo_mem_dcm_ctrl_struct_56
};
#endif  //#if defined(__EMI_COMBO_EN)

//#endif  //#if defined(DCM_ENABLE)
 
#endif /* __CUSTOM_EMI_LIST__ */

#endif //#if defined(MT6256)

__TEMPLATE

return $template;
}

sub custom_EMI_h_56_file_body
{
   	my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL, $MCP_LIST_LOCAL) = @_;
    my $HeaderBody;
        $HeaderBody = &HeaderBody_for_lpsdram_56($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL);
   
    my ($EMI_Info, $EMI_List);
    $EMI_Info .= <<"__TEMPLATE__";
    typedef struct
   {
   	  kal_char m_identifier[8];
   	  
   	  kal_uint32 EMI_DRVA_value;
      kal_uint32 EMI_DRVB_value;
      
      kal_uint32 EMI_ODLA_value;
      kal_uint32 EMI_ODLB_value;
      kal_uint32 EMI_ODLC_value;
      kal_uint32 EMI_ODLD_value;
      kal_uint32 EMI_ODLE_value;
      kal_uint32 EMI_ODLF_value;
      kal_uint32 EMI_ODLG_value;
   
      kal_uint32 EMI_CONI_value;
      kal_uint32 EMI_CONJ_value;
      kal_uint32 EMI_CONK_value;
      kal_uint32 EMI_CONL_value;
      kal_uint32 EMI_CONN_value;

      kal_uint32 EMI_DUTA_value;
      kal_uint32 EMI_DUTB_value;
      kal_uint32 EMI_DUTC_value;

      kal_uint32 EMI_DUCA_value;
      kal_uint32 EMI_DUCB_value;
      kal_uint32 EMI_DUCE_value;

      kal_uint32 EMI_IOCL_value;
   }MTK_EMI_Info;
__TEMPLATE__
        chomp $EMI_Info;
    $EMI_List .= <<"__TEMPLATE__";
typedef struct 
{
   kal_char m_identifier[16];

   /**
      * m_ver = 3 for MT6235
      */
   kal_uint32 m_ver;

   /**
      * for MT6256, 0:166 MHz; 1:200 MHz 
      */
   kal_uint8 op_ver;

   /**
      * reserved for future used 
      */
   kal_uint8 reserved_1;
   kal_uint8 reserved_2;

   /**
      * Numbers of MCPs
      */
   kal_uint8 mcps_num; 

   /** List of all MCP
     *
     */
   MTK_EMI_Info mem_info[__EMI_COMBO_ENTRY_COUNT];

} MTK_EMI_List;
__TEMPLATE__
        chomp $EMI_List;
        
   ###
    my ($cs0_info, $cs1_info);
    if($MAKEFILE_OPTIONS_LOCAL->{'combo_memory_support'} eq 'TRUE')
   {
    	   if (defined $MCP_LIST_LOCAL->[01]->{0})
    {
        $cs0_info .= <<"__TEMPLATE__";
 * CS0_PART_NUMBER: $MCP_LIST_LOCAL->[01]->{0}
__TEMPLATE__
        chomp $cs0_info;
    }
    if (defined $MCP_LIST_LOCAL->[02]->{0})
    {
        $cs1_info .= <<"__TEMPLATE__";
 * CS1_PART_NUMBER: $MCP_LIST_LOCAL->[02]->{0}
__TEMPLATE__
        chomp $cs1_info;
    } 
   }
    else
   {
    if (defined $PART_NUMBER_LOCAL->{0})
    {
        $cs0_info .= <<"__TEMPLATE__";
 * CS0_PART_NUMBER: $PART_NUMBER_LOCAL->{0}
__TEMPLATE__
        chomp $cs0_info;
    }
    if (defined $PART_NUMBER_LOCAL->{1})
    {
        $cs1_info .= <<"__TEMPLATE__";
 * CS1_PART_NUMBER: $PART_NUMBER_LOCAL->{1}
__TEMPLATE__
        chomp $cs1_info;
    } 
   }
   

 
###
    my $custom_EMI_h_optional_part2;
    $custom_EMI_h_optional_part2 = <<"__TEMPLATE";
/* for SW-DCM */
typedef struct
{
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONK_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONJ_13_value;
   kal_uint32 EMI_CONK_13_value;
   kal_uint32 EMI_CONL_13_value;
   kal_uint32 EMI_CONJ_156_value;
   kal_uint32 EMI_CONK_156_value;
   kal_uint32 EMI_CONL_156_value;
} MTK_EMI_DCM_Ctrl;


__TEMPLATE

 
    ###
    my $template = <<"__TEMPLATE";
#if defined(MT6256)
    
#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__

#include "kal_general_types.h"
#include "MemoryDevice_TypeDef.h"

/**
  *    for definition of COMBO_MEM_ENTRY_COUNT and __EMI_DEVICE_MODE_BURST__
  */
#include "custom_MemoryDevice.h"
#include "custom_EMI_release.h"

/* Enable Combo Memory Supporting */
#if defined(__EMI_SIP_RAM)
#define __EMI_COMBO_EN
#define __EMI_COMBO_ENTRY_COUNT     $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT}   // by the number of entry fetched from MDL
#elif defined(__COMBO_MEMORY_SUPPORT__)
#define __EMI_COMBO_EN
#define __EMI_COMBO_ENTRY_COUNT     COMBO_MEM_ENTRY_COUNT
#else /* __EMI_SIP_RAM */
#define __EMI_COMBO_DIS
#define __EMI_COMBO_ENTRY_COUNT     1  // always 1 set for flash tool
#endif /* __EMI_SIP_RAM */

#define __EMI_DCM_COMBO_INDEX_UND   0xffffffff

$custom_EMI_h_optional_part1

$HeaderBody

$EMI_Info

$EMI_List

$custom_EMI_h_optional_part2
/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *
$cs0_info
$cs1_info
 ****************************************************/

#endif /* __CUSTOM_EMI__ */

#endif //#if defined(MT6256)

__TEMPLATE

    return $template;          
}

sub HeaderBody_for_lpsdram_56
{
    ### EMI register value for each MCP
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL) = @_;
    my $combo_mem_emi_reg;
    
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        my ($dram_drva_166, $dram_drvb_166, $dram_odla_166, $dram_odlb_166, $dram_odlc_166, $dram_odld_166, $dram_odle_166, $dram_odlf_166, $dram_odlg_166, $dram_coni_166, $dram_conj_166, $dram_conk_166, $dram_conl_166, $dram_conn_166, $dram_iodutya_166, $dram_iodutyb_166, $dram_iodutyc_166, $dram_rxdutya_166, $dram_rxdutyb_166, $dram_rxdutye_166, $dram_iomiscl_166);
	      my ($dram_drva_200, $dram_drvb_200, $dram_odla_200, $dram_odlb_200, $dram_odlc_200, $dram_odld_200, $dram_odle_200, $dram_odlf_200, $dram_odlg_200, $dram_coni_200, $dram_conj_200, $dram_conk_200, $dram_conl_200, $dram_conn_200, $dram_iodutya_200, $dram_iodutyb_200, $dram_iodutyc_200, $dram_rxdutya_200, $dram_rxdutyb_200, $dram_rxdutye_200, $dram_iomiscl_200);  
        my ($dram_conj_13, $dram_conk_13, $dram_conj_13); 
         ### 6256 series
	    $dram_drva_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drvb_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odla_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlb_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlc_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_C_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odld_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_D_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odle_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_E_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlf_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_F_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlg_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_G_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_coni_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conj_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conk_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conl_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conn_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutya_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyb_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyc_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutya_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutyb_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutye_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iomiscl_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_IOCL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drva_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drvb_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odla_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlb_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlc_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_C_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odld_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_D_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odle_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_E_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlf_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_F_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlg_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_G_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_coni_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conj_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conk_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conl_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conn_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutya_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyb_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyc_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutya_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutyb_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutye_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iomiscl_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_IOCL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
      $dram_conj_13 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
      $dram_conk_13 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
      $dram_conl_13 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL); 
        $combo_mem_emi_reg .= <<"__TEMPLATE";
   /**
      * EMI register value definition
      * EMI/MEM configuration information of MCP$combo_idx
      */
      #if defined(__EMI_CLK_166MHZ__)

#define EMI_DRV_A_VAL_MCP$combo_idx             $dram_drva_166
#define EMI_DRV_B_VAL_MCP$combo_idx             $dram_drvb_166

#define EMI_ODL_A_VAL_MCP$combo_idx             $dram_odla_166
#define EMI_ODL_B_VAL_MCP$combo_idx             $dram_odlb_166
#define EMI_ODL_C_VAL_MCP$combo_idx             $dram_odlc_166
#define EMI_ODL_D_VAL_MCP$combo_idx             $dram_odld_166
#define EMI_ODL_E_VAL_MCP$combo_idx             $dram_odle_166
#define EMI_ODL_F_VAL_MCP$combo_idx             $dram_odlf_166    
#define EMI_ODL_G_VAL_MCP$combo_idx             $dram_odlg_166

#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni_166
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj_166
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk_166
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl_166
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn_166

#define EMI_IODUTY_A_VAL_MCP$combo_idx          $dram_iodutya_166
#define EMI_IODUTY_B_VAL_MCP$combo_idx          $dram_iodutyb_166
#define EMI_IODUTY_C_VAL_MCP$combo_idx          $dram_iodutyc_166

#define EMI_RXDUTY_A_VAL_MCP$combo_idx          $dram_rxdutya_166
#define EMI_RXDUTY_B_VAL_MCP$combo_idx          $dram_rxdutyb_166
#define EMI_RXDUTY_E_VAL_MCP$combo_idx          $dram_rxdutye_166

#define EMI_IOMISC_L_VAL_MCP$combo_idx          $dram_iomiscl_166

#define EMI_CONTROL_J_13_VAL_MCP$combo_idx      $dram_conj_13
#define EMI_CONTROL_K_13_VAL_MCP$combo_idx      $dram_conk_13
#define EMI_CONTROL_L_13_VAL_MCP$combo_idx      $dram_conl_13

#define EMI_CONTROL_J_156_VAL_MCP$combo_idx     $dram_conj_166
#define EMI_CONTROL_K_156_VAL_MCP$combo_idx     $dram_conk_166
#define EMI_CONTROL_L_156_VAL_MCP$combo_idx     $dram_conl_166

#elif defined(__EMI_CLK_200MHZ__)/* __EMI_CLK_166MHZ__ */

#define EMI_DRV_A_VAL_MCP$combo_idx             $dram_drva_200
#define EMI_DRV_B_VAL_MCP$combo_idx             $dram_drvb_200

#define EMI_ODL_A_VAL_MCP$combo_idx             $dram_odla_200
#define EMI_ODL_B_VAL_MCP$combo_idx             $dram_odlb_200
#define EMI_ODL_C_VAL_MCP$combo_idx             $dram_odlc_200
#define EMI_ODL_D_VAL_MCP$combo_idx             $dram_odld_200
#define EMI_ODL_E_VAL_MCP$combo_idx             $dram_odle_200
#define EMI_ODL_F_VAL_MCP$combo_idx             $dram_odlf_200    
#define EMI_ODL_G_VAL_MCP$combo_idx             $dram_odlg_200

#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni_200
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj_200
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk_200
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl_200
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn_200

#define EMI_IODUTY_A_VAL_MCP$combo_idx          $dram_iodutya_200
#define EMI_IODUTY_B_VAL_MCP$combo_idx          $dram_iodutyb_200
#define EMI_IODUTY_C_VAL_MCP$combo_idx          $dram_iodutyc_200

#define EMI_RXDUTY_A_VAL_MCP$combo_idx          $dram_rxdutya_200
#define EMI_RXDUTY_B_VAL_MCP$combo_idx          $dram_rxdutyb_200
#define EMI_RXDUTY_E_VAL_MCP$combo_idx          $dram_rxdutye_200

#define EMI_IOMISC_L_VAL_MCP$combo_idx          $dram_iomiscl_200

#define EMI_CONTROL_J_13_VAL_MCP$combo_idx      $dram_conj_13
#define EMI_CONTROL_K_13_VAL_MCP$combo_idx      $dram_conk_13
#define EMI_CONTROL_L_13_VAL_MCP$combo_idx      $dram_conl_13

#define EMI_CONTROL_J_156_VAL_MCP$combo_idx     $dram_conj_166
#define EMI_CONTROL_K_156_VAL_MCP$combo_idx     $dram_conk_166
#define EMI_CONTROL_L_156_VAL_MCP$combo_idx     $dram_conl_166

#endif /* __EMI_CLK_166MHZ__ */
/**
      * End of EMI/MEM configuration information of MCP$combo_idx
      */
__TEMPLATE
    }	
    
    ###
    my $template = <<"__TEMPLATE";
/****************************************************************************
   *
   * Definition.
   *
   ****************************************************************************/

#define DRAM_CS                   $LPSDRAM_CHIP_SELECT_LOCAL

/**
    * On new format, it has been replaced with EMI_EXTSRAM_SIZE defined at custom_emi_release.h, 
    * but we still keep it and will remove this definition when phasing in auto-gen.
    */
#define DRAM_SIZE                 $COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}  /* Density of LPSDRAM,in terms of Mbits */


$combo_mem_emi_reg;

__TEMPLATE

   return $template;
}
sub custom_EMI_h_55_file_body
{
   	my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL, $MCP_LIST_LOCAL) = @_;
    my $HeaderBody;
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP'))
    {
       $HeaderBody = &HeaderBody_for_nor_ram_mcp_55($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL);
    }
    else
    {
       $HeaderBody = &HeaderBody_for_lpsdram_55($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL);
    }
        
   
     ###
    my ($EMI_Info, $EMI_List);
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND')  || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
    {
        $EMI_Info .= <<"__TEMPLATE__";
typedef struct
{
   kal_char m_identifier[8];

   kal_uint32 EMI_DRVA_value;
   kal_uint32 EMI_DRVB_value;

   kal_uint32 EMI_ODLA_value;
   kal_uint32 EMI_ODLB_value;
   kal_uint32 EMI_ODLC_value;
   kal_uint32 EMI_ODLD_value;
   kal_uint32 EMI_ODLE_value;
   kal_uint32 EMI_ODLF_value;
   kal_uint32 EMI_ODLG_value;
   
   kal_uint32 EMI_CONI_value;
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONK_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONN_value;

   kal_uint32 EMI_DUTA_value;
   kal_uint32 EMI_DUTB_value;
   kal_uint32 EMI_DUTC_value;

   kal_uint32 EMI_DUCA_value;
   kal_uint32 EMI_DUCB_value;
   kal_uint32 EMI_DUCE_value;

   kal_uint32 EMI_IOCL_value;

} MTK_EMI_Info;
__TEMPLATE__
        chomp $EMI_Info;

        $EMI_List .= <<"__TEMPLATE__";
typedef struct 
{
   kal_char m_identifier[16];

   /**
      * m_ver = 3 for MT6235
      */
   kal_uint32 m_ver;

   /**
      * for MT6276, 0:166 MHz; 1:200 MHz 
      */
   kal_uint8 op_ver;

   /**
      * reserved for future used 
      */
   kal_uint8 reserved_1;
   kal_uint8 reserved_2;

   /**
      * Numbers of MCPs
      */
   kal_uint8 mcps_num; 

   /** List of all MCP
     *
     */
   MTK_EMI_Info mem_info[__EMI_COMBO_ENTRY_COUNT];

} MTK_EMI_List;
__TEMPLATE__
        chomp $EMI_List;
    }
    
    ###
    my ($MEM_Info, $MEM_List);
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP'))
    {
    
        $MEM_Info .= <<"__TEMPLATE__";
/**
   * memory mode-switch command operation.
   */
typedef enum
{
   MEM_CMD_OP_16BIT_RD = 0x00000000,
   MEM_CMD_OP_16BIT_WR,
   MEM_CMD_OP_32BIT_RD,
   MEM_CMD_OP_32BIT_WR,
   MEM_CMD_OP_NOP
} MEM_CMD_OP;


/**
   * memory device mode switch information.
   */

/* 
      1. EMI_NOR_CMD_num_max, EMI_PSRAM_CMD_num_max will be the largest one of all valid MCP 
         for all OPs which are not used by certain MCP, the OP must be MEM_CMD_OP_NOP 
      2. Some fields are moved to MTK_Combo_List
 */
typedef struct 
{

   kal_char m_identifier[8];   

   /* DIDR, not in MDL now but keep for furthur using */
   kal_uint32 didr;

   /**
      * EMI control register value.
      */
   kal_uint32 EMI_GENA_value;
   kal_uint32 EMI_GEND_value;
   
   kal_uint32 EMI_CONA_ASYNC_value;
   kal_uint32 EMI_CONB_ASYNC_value;

   kal_uint32 EMI_CONA_BURST_value;
   kal_uint32 EMI_CONE_BURST_value;
   kal_uint32 EMI_CONB_BURST_value;
   kal_uint32 EMI_CONF_BURST_value;
   
   /** 
     * Only Burst Mode
     */
     
   /**
      * NOR switch command sets.
      */
   kal_uint32 EMI_NOR_CMD_num;
   
   kal_uint32 EMI_NOR_CMD_OP[__EMI_NOR_CMD_NUM];
   kal_uint32 EMI_NOR_CMD_ADDR[__EMI_NOR_CMD_NUM];
   kal_uint32 EMI_NOR_CMD_DATA[__EMI_NOR_CMD_NUM];

   /**
      * PSRAM switch command sets.
      */
   kal_uint32 EMI_PSRAM_CMD_num;
   
   kal_uint32 EMI_PSRAM_CMD_OP[__EMI_PSRAM_CMD_NUM];
   kal_uint32 EMI_PSRAM_CMD_ADDR[__EMI_PSRAM_CMD_NUM];
   kal_uint32 EMI_PSRAM_CMD_DATA[__EMI_PSRAM_CMD_NUM];

} MTK_EMI_Info;
__TEMPLATE__

        $MEM_List = <<"__TEMPLATE";
/**
   * List of All valid MCPs
   */ 
 
typedef struct 
{
   /**
      * header pattern information.
      */
   kal_char cb_identifier[16];
   /**
      * chip version information.
      * m_ver = 1 for MT6253
      */
   kal_uint32 m_chip_ver;
   /**
      * switch op version information.
      * m_ver = 1 for initial version.
      */
   kal_uint8 m_op_ver;

   /**
      * Max number of NOR switch command of all MCPs
      */   
   kal_uint8 emi_nor_cmd_num_max;  // =0 if there is no NOR command

   /**
      * Max number of PSRAM switch command of all MCPs
      */   
   kal_uint8 emi_psram_cmd_num_max;   // =0 if there is no PSRAM command

   /**
      * Numbers of MCPs
      */
   kal_uint8 mcps_num; 

   /** List of all MCP
     *
     */
   MTK_EMI_Info mem_info[__EMI_COMBO_ENTRY_COUNT];
   
} MTK_EMI_List;
__TEMPLATE
    	
        chomp $MEM_Info;
        chomp $MEM_List;
    }

###
    my ($cs0_info, $cs1_info);
    if($MAKEFILE_OPTIONS_LOCAL->{'combo_memory_support'} eq 'TRUE')
   {
    	   if (defined $MCP_LIST_LOCAL->[01]->{0})
    {
        $cs0_info .= <<"__TEMPLATE__";
 * CS0_PART_NUMBER: $MCP_LIST_LOCAL->[01]->{0}
__TEMPLATE__
        chomp $cs0_info;
    }
    if (defined $MCP_LIST_LOCAL->[02]->{0})
    {
        $cs1_info .= <<"__TEMPLATE__";
 * CS1_PART_NUMBER: $MCP_LIST_LOCAL->[02]->{0}
__TEMPLATE__
        chomp $cs1_info;
    } 
   }
    else
   {
    if (defined $PART_NUMBER_LOCAL->{0})
    {
        $cs0_info .= <<"__TEMPLATE__";
 * CS0_PART_NUMBER: $PART_NUMBER_LOCAL->{0}
__TEMPLATE__
        chomp $cs0_info;
    }
    if (defined $PART_NUMBER_LOCAL->{1})
    {
        $cs1_info .= <<"__TEMPLATE__";
 * CS1_PART_NUMBER: $PART_NUMBER_LOCAL->{1}
__TEMPLATE__
        chomp $cs1_info;
    } 
   }
 
###
    my $custom_EMI_h_optional_part2;
    $custom_EMI_h_optional_part2 = <<"__TEMPLATE";
/* for SW-DCM */
typedef struct
{
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONK_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONJ_13_value;
   kal_uint32 EMI_CONK_13_value;
   kal_uint32 EMI_CONL_13_value;
} MTK_EMI_DCM_Ctrl;


__TEMPLATE
   
    ###
    my $template = <<"__TEMPLATE";
#if defined(MT6255)
    
#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__

#include "kal_general_types.h"
#include "MemoryDevice_TypeDef.h"

/**
  *    for definition of COMBO_MEM_ENTRY_COUNT and __EMI_DEVICE_MODE_BURST__
  */
#include "custom_MemoryDevice.h"
#include "custom_EMI_release.h"

/* Enable Combo Memory Supporting */
#if defined(__SIP_RAM_SIZE__)
#define __EMI_COMBO_DIS
#define __EMI_COMBO_ENTRY_COUNT     1   // by the number of entry fetched from MDL
#elif defined(__COMBO_MEMORY_SUPPORT__)
#define __EMI_COMBO_EN
#define __EMI_COMBO_ENTRY_COUNT     COMBO_MEM_ENTRY_COUNT
#else /* __EMI_SIP_RAM */
#define __EMI_COMBO_DIS
#define __EMI_COMBO_ENTRY_COUNT     1  // always 1 set for flash tool
#endif /* __EMI_SIP_RAM */

#define __EMI_DCM_COMBO_INDEX_UND   0xffffffff

$HeaderBody

$EMI_Info

$EMI_List

$MEM_Info

$MEM_List

$custom_EMI_h_optional_part2
/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *
$cs0_info
$cs1_info
 ****************************************************/

#endif /* __CUSTOM_EMI__ */

#endif //#if defined(MT6255)

__TEMPLATE

    return $template;          
}

sub HeaderBody_for_lpsdram_55
{
    ### EMI register value for each MCP
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL) = @_;
    my $combo_mem_emi_reg;
    
    
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        my ($dram_drva_166, $dram_drvb_166, $dram_odla_166, $dram_odlb_166, $dram_odlc_166, $dram_odld_166, $dram_odle_166, $dram_odlf_166, $dram_odlg_166, $dram_coni_166, $dram_conj_166, $dram_conk_166, $dram_conl_166, $dram_conn_166, $dram_iodutya_166, $dram_iodutyb_166, $dram_iodutyc_166, $dram_rxdutya_166, $dram_rxdutyb_166, $dram_rxdutye_166, $dram_iomiscl_166);
	      my ($dram_drva_200, $dram_drvb_200, $dram_odla_200, $dram_odlb_200, $dram_odlc_200, $dram_odld_200, $dram_odle_200, $dram_odlf_200, $dram_odlg_200, $dram_coni_200, $dram_conj_200, $dram_conk_200, $dram_conl_200, $dram_conn_200, $dram_iodutya_200, $dram_iodutyb_200, $dram_iodutyc_200, $dram_rxdutya_200, $dram_rxdutyb_200, $dram_rxdutye_200, $dram_iomiscl_200);  
        my ($dram_conj_13, $dram_conk_13, $dram_conj_13); 
         ### 6256 series
	    $dram_drva_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drvb_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odla_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlb_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlc_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_C_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odld_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_D_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odle_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_E_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlf_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_F_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlg_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_G_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_coni_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conj_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conk_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conl_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conn_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutya_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyb_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyc_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutya_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutyb_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutye_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iomiscl_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_IOCL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drva_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drvb_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odla_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlb_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlc_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_C_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odld_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_D_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odle_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_E_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlf_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_F_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlg_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_G_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_coni_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conj_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conk_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conl_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conn_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutya_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyb_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyc_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutya_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutyb_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutye_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iomiscl_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_IOCL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conj_13 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
      $dram_conk_13 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
      $dram_conl_13 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL); 
        $combo_mem_emi_reg .= <<"__TEMPLATE";
   /**
      * EMI register value definition
      * EMI/MEM configuration information of MCP$combo_idx
      */
      #if defined(__EMI_CLK_166MHZ__)

#define EMI_DRV_A_VAL_MCP$combo_idx             $dram_drva_166
#define EMI_DRV_B_VAL_MCP$combo_idx             $dram_drvb_166

#define EMI_ODL_A_VAL_MCP$combo_idx             $dram_odla_166
#define EMI_ODL_B_VAL_MCP$combo_idx             $dram_odlb_166
#define EMI_ODL_C_VAL_MCP$combo_idx             $dram_odlc_166
#define EMI_ODL_D_VAL_MCP$combo_idx             $dram_odld_166
#define EMI_ODL_E_VAL_MCP$combo_idx             $dram_odle_166
#define EMI_ODL_F_VAL_MCP$combo_idx             $dram_odlf_166    
#define EMI_ODL_G_VAL_MCP$combo_idx             $dram_odlg_166

#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni_166
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj_166
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk_166
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl_166
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn_166

#define EMI_IODUTY_A_VAL_MCP$combo_idx          $dram_iodutya_166
#define EMI_IODUTY_B_VAL_MCP$combo_idx          $dram_iodutyb_166
#define EMI_IODUTY_C_VAL_MCP$combo_idx          $dram_iodutyc_166

#define EMI_RXDUTY_A_VAL_MCP$combo_idx          $dram_rxdutya_166
#define EMI_RXDUTY_B_VAL_MCP$combo_idx          $dram_rxdutyb_166
#define EMI_RXDUTY_E_VAL_MCP$combo_idx          $dram_rxdutye_166

#define EMI_IOMISC_L_VAL_MCP$combo_idx          $dram_iomiscl_166

#define EMI_CONTROL_J_13_VAL_MCP$combo_idx      $dram_conj_13
#define EMI_CONTROL_K_13_VAL_MCP$combo_idx      $dram_conk_13
#define EMI_CONTROL_L_13_VAL_MCP$combo_idx      $dram_conl_13

#elif defined(__EMI_CLK_200MHZ__)/* __EMI_CLK_166MHZ__ */

#define EMI_DRV_A_VAL_MCP$combo_idx             $dram_drva_200
#define EMI_DRV_B_VAL_MCP$combo_idx             $dram_drvb_200

#define EMI_ODL_A_VAL_MCP$combo_idx             $dram_odla_200
#define EMI_ODL_B_VAL_MCP$combo_idx             $dram_odlb_200
#define EMI_ODL_C_VAL_MCP$combo_idx             $dram_odlc_200
#define EMI_ODL_D_VAL_MCP$combo_idx             $dram_odld_200
#define EMI_ODL_E_VAL_MCP$combo_idx             $dram_odle_200
#define EMI_ODL_F_VAL_MCP$combo_idx             $dram_odlf_200    
#define EMI_ODL_G_VAL_MCP$combo_idx             $dram_odlg_200

#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni_200
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj_200
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk_200
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl_200
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn_200

#define EMI_IODUTY_A_VAL_MCP$combo_idx          $dram_iodutya_200
#define EMI_IODUTY_B_VAL_MCP$combo_idx          $dram_iodutyb_200
#define EMI_IODUTY_C_VAL_MCP$combo_idx          $dram_iodutyc_200

#define EMI_RXDUTY_A_VAL_MCP$combo_idx          $dram_rxdutya_200
#define EMI_RXDUTY_B_VAL_MCP$combo_idx          $dram_rxdutyb_200
#define EMI_RXDUTY_E_VAL_MCP$combo_idx          $dram_rxdutye_200

#define EMI_IOMISC_L_VAL_MCP$combo_idx          $dram_iomiscl_200

#define EMI_CONTROL_J_13_VAL_MCP$combo_idx      $dram_conj_13
#define EMI_CONTROL_K_13_VAL_MCP$combo_idx      $dram_conk_13
#define EMI_CONTROL_L_13_VAL_MCP$combo_idx      $dram_conl_13

#endif /* __EMI_CLK_166MHZ__ */
/**
      * End of EMI/MEM configuration information of MCP$combo_idx
      */
__TEMPLATE
    }	
    
    ###
    if($MAKEFILE_OPTIONS_LOCAL->{'SIP_RAM_SIZE'} eq '256M_BITS')
    {
    	 print "test head 55\n";
    	 my $template = <<"__TEMPLATE";
/****************************************************************************
   *
   * Definition.
   *
   ****************************************************************************/

#define DRAM_CS                   1

/**
    * On new format, it has been replaced with EMI_EXTSRAM_SIZE defined at custom_emi_release.h, 
    * but we still keep it and will remove this definition when phasing in auto-gen.
    */
#define DRAM_SIZE                 $COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}  /* Density of LPSDRAM,in terms of Mbits */


$combo_mem_emi_reg;

__TEMPLATE

       return $template;
    }
    else
    {
    	
    	   my $template = <<"__TEMPLATE";
/****************************************************************************
   *
   * Definition.
   *
   ****************************************************************************/

#define DRAM_CS                   1

/**
    * On new format, it has been replaced with EMI_EXTSRAM_SIZE defined at custom_emi_release.h, 
    * but we still keep it and will remove this definition when phasing in auto-gen.
    */
#define DRAM_SIZE                 $COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}  /* Density of LPSDRAM,in terms of Mbits */


$combo_mem_emi_reg;

__TEMPLATE

      return $template;
    }
 
   
}

sub HeaderBody_for_nor_ram_mcp_55
{
    ###
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL) = @_;
    my ($sub_content_block1, $sub_content_block2, $sub_content_block3, $sub_content_block4);
    my $sub_content_didr;
    my $sub_content_command_num;
    my $optional_block_admux;
    if (&config_query_no_EMI($MAKEFILE_OPTIONS_LOCAL->{'platform'}) != 1)
    {
        ###
        #$sub_content_block1 = &emi_csconfiguration($COMM_MDL_INFO_LOCAL);
        $sub_content_block2 = &driving_and_cache_prefetch_setting_55($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL);
        $sub_content_block3 = &emi_setting_on_chip_select();

       
        ###
        $sub_content_command_num = <<"__TEMPLATE";
#define __EMI_NOR_CMD_NUM      $emi_nor_cmd_num_max_LOCAL
#define __EMI_PSRAM_CMD_NUM    $emi_psram_cmd_num_max_LOCAL

__TEMPLATE

        ###
        if ($COMM_MDL_INFO_LOCAL->{0}->{'ADMUX'} eq 'YES' or $COMM_MDL_INFO_LOCAL->{1}->{'ADMUX'} eq 'YES')
        {
            $optional_block_admux = &mcp_admux();
        }
    }

    ###
    my $template = <<"__TEMPLATE";


/*
 ****************************************************************************
 Specify NOR/PSRAM Command Num
 ****************************************************************************
*/
$sub_content_command_num

$optional_block_admux

/*
 ****************************************************************************
 Define the driving and cache/prefetch setting (optional)
 ****************************************************************************
*/
$sub_content_block2

$sub_content_block3
__TEMPLATE

    return $template;
}

sub driving_and_cache_prefetch_setting_55
{
	  my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL) = @_;
    my $sync_setting;


    ### MT6255
    ### To support Combo Memory
    my $sub_content_emi_setting_55;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        
        my ($emi_cona_async_55, $emi_conb_async_55, $emi_gena_val_55, $emi_drva_val_55, $emi_drvb_val_55, $emi_iocm_val_55);
        my ($emi_cona_burst_55, $emi_cone_burst_55, $emi_conb_burst_55, $emi_conf_burst_55, $emi_cona_burst_55_13m, $emi_cone_burst_55_13m, $emi_conb_burst_55_13m, $emi_conf_burst_55_13m);
        my (@driving_list_6255, @nor_setting_list_6255, @psram_setting_list_6255, @nor_setting_list_6255_13m, @psram_setting_list_6255_13m);
    
        if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
        {
            $emi_cona_async_55    = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6255'};
            $emi_conb_async_55    = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6255'};
            $emi_drva_val_55      = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous Driving Setting'}->{'EMI_DRV_A_VAL'};
            $emi_drvb_val_55      = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous Driving Setting'}->{'EMI_DRV_B_VAL'};
        }
        elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6922')
        {
            $emi_cona_async_55    = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6922'};
            $emi_conb_async_55    = $MDL_INFO_LIST_LOCAL->[$_]->{1}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6922'};
        }

        if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'ASYNC_ACCESS')
        {
            if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                #@driving_list_6255 = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous Driving Setting'}->{'MT6255'});
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6922')
            {
                #@driving_list_6255 = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Asynchrnous Driving Setting'}->{'MT6922'});
            }
        }
        else
        {
            if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
            {
                @nor_setting_list_6255   = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous EMI Setting'}->{'MT6255'});
                @psram_setting_list_6255 = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'104MHz Synchronous EMI Setting'}->{'MT6255'});
                #@driving_list_6255       = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous Driving Setting'}->{'MT6255'});
                @nor_setting_list_6255_13m   = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'13MHz Synchronous EMI Setting'}->{'MT6255'});
                @psram_setting_list_6255_13m = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'13MHz Synchronous EMI Setting'}->{'MT6255'});
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6922')
            {
                @nor_setting_list_6255   = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous EMI Setting'}->{'MT6922'});
                @psram_setting_list_6255 = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'104MHz Synchronous EMI Setting'}->{'MT6922'});
                @driving_list_6255       = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'104MHz Synchronous Driving Setting'}->{'MT6922'});
                @nor_setting_list_6255_13m   = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{0}->{'13MHz Synchronous EMI Setting'}->{'MT6922'});
                @psram_setting_list_6255_13m = &split_emi($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'13MHz Synchronous EMI Setting'}->{'MT6922'});
            }
        }
	    $emi_gena_val_55   = $driving_list_6255[0];
	    $emi_cona_burst_55 = $nor_setting_list_6255[0];
	    $emi_cone_burst_55 = $nor_setting_list_6255[1];
	    $emi_conb_burst_55 = $psram_setting_list_6255[0];
	    $emi_conf_burst_55 = $psram_setting_list_6255[1];
	    $emi_cona_burst_55_13m = $nor_setting_list_6255_13m[0];
	    $emi_cone_burst_55_13m = $nor_setting_list_6255_13m[1];
	    $emi_conb_burst_55_13m = $psram_setting_list_6255_13m[0];
	    $emi_conf_burst_55_13m = $psram_setting_list_6255_13m[1];

        ###
        my $sync_setting;
        my @op_list_nor = &split_addr_ret_rw(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @addr_list_nor = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @data_list_nor = &split_emi(&Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @op_list_psram = &split_addr_ret_rw(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @addr_list_psram = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        my @data_list_psram = &split_emi(&Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config_LOCAL, $MAKEFILE_OPTIONS_LOCAL->{'platform'}));
        
        for (0..($emi_nor_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#op_list_nor)
            {
                $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_NOP\n";
            }
            elsif ($op_list_nor[$_] eq 'R:')
            {
                $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_RD\n";
            }
            else
            {
                $sync_setting .= "#define EMI_NOR_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_WR\n";
            }
        }
        for (0..($emi_nor_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#addr_list_nor)
            {
                $sync_setting .= "#define EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx      0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx      $addr_list_nor[$_]\n";
            }
        }
        for (0..($emi_nor_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#data_list_nor)
            {
                $sync_setting .= "#define EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx         0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx         $data_list_nor[$_]\n";
            }
        }
        for (0..($emi_psram_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#op_list_psram)
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_NOP\n";
            }
            elsif ($op_list_psram[$_] eq 'R:')
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_RD\n";
            }
            else
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx           MEM_CMD_OP_16BIT_WR\n";
            }
        }
        for (0..($emi_psram_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#addr_list_psram)
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx    0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx    $addr_list_psram[$_]\n";
            }
        }
        for (0..($emi_psram_cmd_num_max_LOCAL-1))
        {
            my $idx = $_ + 1;
            if ($_ > $#data_list_psram)
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx      0\n";
            }
            else
            {
                $sync_setting .= "#define EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx      $data_list_psram[$_]\n";
            }
        }
        chomp $sync_setting;

        $sub_content_emi_setting_55 .= <<"__TEMPLATE";
/* start of MCP$combo_idx */


/* EMI_DRVA value */
#define EMI_DRV_A_VAL_MCP$combo_idx                $emi_drva_val_55
#define EMI_DRV_B_VAL_MCP$combo_idx                $emi_drvb_val_55

/* NOR async */
#define EMI_CONA_ASYNC_MCP$combo_idx               $emi_cona_async_55

/* PSRAM async */
#define EMI_CONB_ASYNC_MCP$combo_idx               $emi_conb_async_55

/* NOR burst */
#define EMI_CONA_BURST_MCP$combo_idx               $emi_cona_burst_55
#define EMI_CONE_BURST_MCP$combo_idx               $emi_cone_burst_55

/* PSRAM burst */
#define EMI_CONB_BURST_MCP$combo_idx               $emi_conb_burst_55
#define EMI_CONF_BURST_MCP$combo_idx               $emi_conf_burst_55

/* NOR burst */
#define EMI_CONA_BURST_13MHZ_MCP$combo_idx         $emi_cona_burst_55_13m
#define EMI_CONE_BURST_13MHZ_MCP$combo_idx         $emi_cone_burst_55_13m

/* PSRAM burst */
#define EMI_CONB_BURST_13MHZ_MCP$combo_idx         $emi_conb_burst_55_13m
#define EMI_CONF_BURST_13MHZ_MCP$combo_idx         $emi_conf_burst_55_13m


$sync_setting

/* NOR async */
#define EMI_CONA_ASYNC               EMI_CONA_ASYNC_MCP$combo_idx

/* PSRAM async */
#define EMI_CONB_ASYNC               EMI_CONB_ASYNC_MCP$combo_idx

/* NOR burst */
#define EMI_CONA_BURST               EMI_CONA_BURST_MCP$combo_idx
#define EMI_CONE_BURST               EMI_CONE_BURST_MCP$combo_idx

/* PSRAM burst */
#define EMI_CONB_BURST               EMI_CONB_BURST_MCP$combo_idx
#define EMI_CONF_BURST               EMI_CONF_BURST_MCP$combo_idx

/* NOR burst */
#define EMI_CONA_BURST_13MHZ         EMI_CONA_BURST_13MHZ_MCP$combo_idx
#define EMI_CONE_BURST_13MHZ         EMI_CONE_BURST_13MHZ_MCP$combo_idx

/* PSRAM burst */
#define EMI_CONB_BURST_13MHZ         EMI_CONB_BURST_13MHZ_MCP$combo_idx
#define EMI_CONF_BURST_13MHZ         EMI_CONF_BURST_13MHZ_MCP$combo_idx

#define EMI_NOR_BURST_ADDRESS_1      EMI_NOR_BURST_ADDRESS_1_MCP$combo_idx
#define EMI_NOR_BURST_ADDRESS_2      EMI_NOR_BURST_ADDRESS_2_MCP$combo_idx
#define EMI_NOR_BURST_ADDRESS_3      EMI_NOR_BURST_ADDRESS_3_MCP$combo_idx
#define EMI_NOR_BURST_ADDRESS_4      EMI_NOR_BURST_ADDRESS_4_MCP$combo_idx
#define EMI_NOR_BURST_ADDRESS_5      EMI_NOR_BURST_ADDRESS_5_MCP$combo_idx
#define EMI_NOR_BURST_DATA_1         EMI_NOR_BURST_DATA_1_MCP$combo_idx
#define EMI_NOR_BURST_DATA_2         EMI_NOR_BURST_DATA_2_MCP$combo_idx
#define EMI_NOR_BURST_DATA_3         EMI_NOR_BURST_DATA_3_MCP$combo_idx
#define EMI_NOR_BURST_DATA_4         EMI_NOR_BURST_DATA_4_MCP$combo_idx
#define EMI_NOR_BURST_DATA_5         EMI_NOR_BURST_DATA_5_MCP$combo_idx
#define EMI_PSRAM_BURST_ADDRESS_1    EMI_PSRAM_BURST_ADDRESS_1_MCP$combo_idx
#define EMI_PSRAM_BURST_ADDRESS_2    EMI_PSRAM_BURST_ADDRESS_2_MCP$combo_idx
#define EMI_PSRAM_BURST_ADDRESS_3    EMI_PSRAM_BURST_ADDRESS_3_MCP$combo_idx
#define EMI_PSRAM_BURST_ADDRESS_4    EMI_PSRAM_BURST_ADDRESS_4_MCP$combo_idx
#define EMI_PSRAM_BURST_ADDRESS_5    EMI_PSRAM_BURST_ADDRESS_5_MCP$combo_idx
#define EMI_PSRAM_BURST_ADDRESS_6    EMI_PSRAM_BURST_ADDRESS_6_MCP$combo_idx
#define EMI_PSRAM_BURST_ADDRESS_7    EMI_PSRAM_BURST_ADDRESS_7_MCP$combo_idx
#define EMI_PSRAM_BURST_ADDRESS_8    EMI_PSRAM_BURST_ADDRESS_8_MCP$combo_idx
#define EMI_PSRAM_BURST_DATA_1      EMI_PSRAM_BURST_DATA_1_MCP$combo_idx
#define EMI_PSRAM_BURST_DATA_2      EMI_PSRAM_BURST_DATA_2_MCP$combo_idx
#define EMI_PSRAM_BURST_DATA_3      EMI_PSRAM_BURST_DATA_3_MCP$combo_idx
#define EMI_PSRAM_BURST_DATA_4      EMI_PSRAM_BURST_DATA_4_MCP$combo_idx
#define EMI_PSRAM_BURST_DATA_5      EMI_PSRAM_BURST_DATA_5_MCP$combo_idx
#define EMI_PSRAM_BURST_DATA_6      EMI_PSRAM_BURST_DATA_6_MCP$combo_idx
#define EMI_PSRAM_BURST_DATA_7      EMI_PSRAM_BURST_DATA_7_MCP$combo_idx
#define EMI_PSRAM_BURST_DATA_8      EMI_PSRAM_BURST_DATA_8_MCP$combo_idx
__TEMPLATE
    }

    ###
    
    my $template = <<"__TEMPLATE";

$sub_content_emi_setting_55

__TEMPLATE

    return $template;
}

sub custom_EMI_info_h_55_file_body
{
	 my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL) = @_;
	 my $combo_mem_emi_info_struct;
	 my $combo_mei_emi_count;
	 if($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT} ne '0')
	 {
	     $combo_mei_emi_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT};	
	 }
	 else
	 {
	 	   $combo_mei_emi_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT};
	 }
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        if(($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {
        $combo_mem_emi_info_struct .= <<"__TEMPLATE";
   /**
      * EMI/MEM configuration information of MCP$combo_idx
      */
   "EMI_INF",
   
   EMI_DRV_A_VAL_MCP$combo_idx,
   EMI_DRV_B_VAL_MCP$combo_idx,

   EMI_ODL_A_VAL_MCP$combo_idx,
   EMI_ODL_B_VAL_MCP$combo_idx,
   EMI_ODL_C_VAL_MCP$combo_idx,
   EMI_ODL_D_VAL_MCP$combo_idx,
   EMI_ODL_E_VAL_MCP$combo_idx,
   EMI_ODL_F_VAL_MCP$combo_idx,
   EMI_ODL_G_VAL_MCP$combo_idx,

   EMI_CONTROL_I_VAL_MCP$combo_idx,
   EMI_CONTROL_J_VAL_MCP$combo_idx,
   EMI_CONTROL_K_VAL_MCP$combo_idx,
   EMI_CONTROL_L_VAL_MCP$combo_idx,
   EMI_CONTROL_N_VAL_MCP$combo_idx,

   EMI_IODUTY_A_VAL_MCP$combo_idx,
   EMI_IODUTY_B_VAL_MCP$combo_idx,  
   EMI_IODUTY_C_VAL_MCP$combo_idx,
   
   EMI_RXDUTY_A_VAL_MCP$combo_idx,
   EMI_RXDUTY_B_VAL_MCP$combo_idx,  
   EMI_RXDUTY_E_VAL_MCP$combo_idx,
   
   EMI_IOMISC_L_VAL_MCP$combo_idx,
   
   /**
      * End of EMI/MEM configuration information of MCP$combo_idx
      */
__TEMPLATE
    }
    else
    {
            my $combo_idx = $_ - 1;
            my ($emi_nor_op_str, $emi_nor_address_str, $emi_nor_data_str, $emi_psram_op_str, $emi_psram_address_str, $emi_psram_data_str);

            for (0..($emi_nor_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                $emi_nor_op_str .= "   EMI_NOR_BURST_OP_$idx\_MCP$combo_idx,\n";
                $emi_nor_address_str .= "   EMI_NOR_BURST_ADDRESS_$idx\_MCP$combo_idx,\n";
                $emi_nor_data_str .= "   EMI_NOR_BURST_DATA_$idx\_MCP$combo_idx,\n";
            }
            for (0..($emi_psram_cmd_num_max_LOCAL-1))
            {
                my $idx = $_ + 1;
                $emi_psram_op_str .= "   EMI_PSRAM_BURST_OP_$idx\_MCP$combo_idx,\n";
                $emi_psram_address_str .= "   EMI_PSRAM_BURST_ADDRESS_$idx\_MCP$combo_idx,\n";
                $emi_psram_data_str .= "   EMI_PSRAM_BURST_DATA_$idx\_MCP$combo_idx,\n";
            }
    	    $combo_mem_emi_info_struct .= <<"__TEMPLATE";
   /**
      * EMI/MEM configuration information of MCP$combo_idx
      */
   "EMI_INF",
   
   /**
      * EMI control register value.
      */
   EMI_DRV_A_VAL_MCP$combo_idx,
   EMI_DRV_B_VAL_MCP$combo_idx,

   EMI_GENERAL_A_VAL_MCP$combo_idx,

   EMI_CONA_ASYNC_MCP$combo_idx,
   EMI_CONB_ASYNC_MCP$combo_idx,

   EMI_CONA_BURST_MCP$combo_idx,
   EMI_CONE_BURST_MCP$combo_idx,

   EMI_CONB_BURST_MCP$combo_idx,
   EMI_CONF_BURST_MCP$combo_idx,
 
   
   /**
      * End of EMI/MEM configuration information of MCP$combo_idx
      */
__TEMPLATE
    }
  }
	 
	 ###for combo memory 13mhz
    my $combo_mem_dcm_ctrl_struct_55;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";

        $combo_mem_dcm_ctrl_struct_55 .= <<"__TEMPLATE";
   {
      EMI_CONTROL_J_VAL_MCP$combo_idx,
      EMI_CONTROL_K_VAL_MCP$combo_idx,
      EMI_CONTROL_L_VAL_MCP$combo_idx,
      EMI_CONTROL_J_13_VAL_MCP$combo_idx,
      EMI_CONTROL_K_13_VAL_MCP$combo_idx,
      EMI_CONTROL_L_13_VAL_MCP$combo_idx
   }$comma
__TEMPLATE
    }
  
  ###for combo memory EMI Controller value
  my $combo_mem_emi;
  for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
  {
  	  my $combo_idx = $_ - 1;
  	 $combo_mem_emi .= <<"__TEMPLATE";
 #define EMI_GENERAL_A_VAL_MCP$combo_idx            0x00000002
 #define EMI_IOCM_VAL_MCP$combo_idx                 0x00010003
 #define EMI_GENERAL_A_VAL     EMI_GENERAL_A_VAL_MCP$combo_idx
 #define EMI_IOCM_VAL          EMI_IOCM_VAL_MCP$combo_idx
__TEMPLATE
  }
  ###
  my $emi_driving_gena_and_iocm;
  if($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
  {
  $emi_driving_gena_and_iocm .= <<"__TEMPLATE";
$combo_mem_emi
__TEMPLATE
  }
	 my $template = <<"__TEMPLATE";
	 
#if defined(MT6255)

#ifndef __CUSTOM_EMI_LIST__
#define __CUSTOM_EMI_LIST__

#include "kal_general_types.h"
#include "MemoryDevice_TypeDef.h"
$emi_driving_gena_and_iocm
/**
  *    for definition of COMBO_MEM_ENTRY_COUNT and __EMI_DEVICE_MODE_BURST__
  */
#include "custom_MemoryDevice.h"
#include "custom_EMI_release.h"
#include "custom_EMI.h"

#ifdef __SV5_ENABLED__
#include "br_GFH_emi_list.h"
#include "br_GFH.h"
#endif /* __SV5_ENABLED__ */

#ifdef __SV5_ENABLED__ // SV5 will always with __UBL__
#pragma arm section rodata = "BOOTLOADER_GFH_EXT"
#else
#pragma arm section rodata = "SECOND_PART"
#endif // __SV5_ENABLED__

#ifdef __SV5_ENABLED__ 
    const GFH_EMI_LIST_v5 EMI_INFO_2 =
#else /* __SV5_ENABLED__ */
  const MTK_EMI_List EMI_INFO_2 =
#endif /* __SV5_ENABLED__ */
{
#ifdef __SV5_ENABLED__
    GFH_HEADER(GFH_EMI_LIST, 5),  
#else
   "MTK_CMB_EMI_LST",
#endif

   // chip_ver
   5,
   // op_ver
   #if defined(__EMI_DEVICE_LPDDR1__) && defined(__EMI_CLK_166MHZ__)
   0x01,
   #elif defined(__EMI_DEVICE_LPDDR1__) && defined(__EMI_CLK_200MHZ__)
   0x02,
   #elif defined(__EMI_DEVICE_LPDDR2__) && defined(__EMI_CLK_166MHZ__) 
   0x11,
   #elif defined(__EMI_DEVICE_LPDDR2__) && defined(__EMI_CLK_200MHZ__) 
   0x12,
   #else
   0,
   #endif
   
   0, // reserved_1
   0, // reserved_2

   $combo_mei_emi_count, // mcp_num
$combo_mem_emi_info_struct
}; /* End of EMI_INFO_2 */

#pragma arm section rodata

#if defined(__EMI_COMBO_EN)
MTK_EMI_DCM_Ctrl __EMI_DCM_control[__EMI_COMBO_ENTRY_COUNT] = 
{
$combo_mem_dcm_ctrl_struct_55
};
#endif  //#if defined(__EMI_COMBO_EN)

#endif /* __CUSTOM_EMI_LIST__ */

#endif //#if defined(MT6255)

__TEMPLATE

return $template;
}
sub custom_EMI_h_80_file_body
{
   	my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL, $MCP_LIST_LOCAL) = @_;
    my $HeaderBody;
   
    $HeaderBody = &HeaderBody_for_lpsdram_80($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL);

     ###
    my ($EMI_Info, $EMI_List);
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND')  || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
    {
        $EMI_Info .= <<"__TEMPLATE__";
typedef struct
{
  kal_char m_identifier[8];

   kal_uint32 EMI_DRVA_value;
   kal_uint32 EMI_DRVB_value;

   kal_uint32 EMI_ODLE_value;
   kal_uint32 EMI_ODLF_value;
   kal_uint32 EMI_ODLG_value;
   kal_uint32 EMI_ODLH_value;
   kal_uint32 EMI_ODLI_value;
   kal_uint32 EMI_ODLJ_value;
   kal_uint32 EMI_ODLK_value;
   kal_uint32 EMI_ODLL_value;
   kal_uint32 EMI_ODLM_value;
   kal_uint32 EMI_ODLN_value;

   kal_uint32 EMI_CONI_value;
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONK_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONN_value;

   kal_uint32 EMI_DUTA_value;
   kal_uint32 EMI_DUTB_value;
   kal_uint32 EMI_DUTC_value;

   kal_uint32 EMI_DUCA_value;
   kal_uint32 EMI_DUCB_value;
   kal_uint32 EMI_DUCE_value;

   kal_uint32 EMI_IOCL_value;
} MTK_EMI_Info;
__TEMPLATE__
        chomp $EMI_Info;

        $EMI_List .= <<"__TEMPLATE__";
typedef struct 
{
   kal_char m_identifier[16];

   /**
      * m_ver = 3 for MT6235
      */
   kal_uint32 m_ver;

   /**
      * for MT6276, 0:166 MHz; 1:200 MHz 
      */
   kal_uint8 op_ver;

   /**
      * reserved for future used 
      */
   kal_uint8 reserved_1;
   kal_uint8 reserved_2;

   /**
      * Numbers of MCPs
      */
   kal_uint8 mcps_num; 

   /** List of all MCP
     *
     */
   MTK_EMI_Info mem_info[__EMI_COMBO_ENTRY_COUNT];

} MTK_EMI_List;
__TEMPLATE__
        chomp $EMI_List;
    }
 
###
    my ($cs0_info, $cs1_info);
    if($MAKEFILE_OPTIONS_LOCAL->{'combo_memory_support'} eq 'TRUE')
   {
    	   if (defined $MCP_LIST_LOCAL->[01]->{0})
    {
        $cs0_info .= <<"__TEMPLATE__";
 * CS0_PART_NUMBER: $MCP_LIST_LOCAL->[01]->{0}
__TEMPLATE__
        chomp $cs0_info;
    }
    if (defined $MCP_LIST_LOCAL->[02]->{0})
    {
        $cs1_info .= <<"__TEMPLATE__";
 * CS1_PART_NUMBER: $MCP_LIST_LOCAL->[02]->{0}
__TEMPLATE__
        chomp $cs1_info;
    } 
   }
    else
   {
    if (defined $PART_NUMBER_LOCAL->{0})
    {
        $cs0_info .= <<"__TEMPLATE__";
 * CS0_PART_NUMBER: $PART_NUMBER_LOCAL->{0}
__TEMPLATE__
        chomp $cs0_info;
    }
    if (defined $PART_NUMBER_LOCAL->{1})
    {
        $cs1_info .= <<"__TEMPLATE__";
 * CS1_PART_NUMBER: $PART_NUMBER_LOCAL->{1}
__TEMPLATE__
        chomp $cs1_info;
    } 
   }
 
###
    my $custom_EMI_h_optional_part2;
    $custom_EMI_h_optional_part2 = <<"__TEMPLATE";
/* for SW-DCM */
typedef struct
{
   kal_uint32 EMI_CONJ_value;
   kal_uint32 EMI_CONK_value;
   kal_uint32 EMI_CONL_value;
   kal_uint32 EMI_CONJ_13_value;
   kal_uint32 EMI_CONK_13_value;
   kal_uint32 EMI_CONL_13_value;
} MTK_EMI_DCM_Ctrl;


__TEMPLATE
   
    ###
    my $template = <<"__TEMPLATE";
#if defined(MT6280)
    
#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__

#include "kal_general_types.h"
#include "MemoryDevice_TypeDef.h"

/**
  *    for definition of COMBO_MEM_ENTRY_COUNT and __EMI_DEVICE_MODE_BURST__
  */
#include "custom_MemoryDevice.h"
#include "custom_EMI_release.h"

/* Enable Combo Memory Supporting */
#if defined(__SIP_RAM_SIZE__)
#define __EMI_COMBO_DIS
#define __EMI_COMBO_ENTRY_COUNT     1   // by the number of entry fetched from MDL
#elif defined(__COMBO_MEMORY_SUPPORT__)
#define __EMI_COMBO_EN
#define __EMI_COMBO_ENTRY_COUNT     COMBO_MEM_ENTRY_COUNT
#else /* __EMI_SIP_RAM */
#define __EMI_COMBO_DIS
#define __EMI_COMBO_ENTRY_COUNT     1  // always 1 set for flash tool
#endif /* __EMI_SIP_RAM */

#define __EMI_DCM_COMBO_INDEX_UND   0xffffffff

$HeaderBody

$EMI_Info

$EMI_List

$MEM_Info

$MEM_List

$custom_EMI_h_optional_part2
/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *
$cs0_info
$cs1_info
 ****************************************************/

#endif /* __CUSTOM_EMI__ */

#endif //#if defined(MT6280)

__TEMPLATE

    return $template;  #'        
}

sub HeaderBody_for_lpsdram_80
{
    ### EMI register value for each MCP
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL) = @_;
    my $combo_mem_emi_reg;
    
    
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        my ($dram_drva_166, $dram_drvb_166, $dram_odle_166, $dram_odlf_166, $dram_odlg_166, $dram_odlh_166, $dram_odli_166, $dram_odlj_166, $dram_odlk_166, $dram_odll_166,$dram_odlm_166,$dram_odln_166, $dram_coni_166, $dram_conj_166, $dram_conk_166, $dram_conl_166, $dram_conn_166, $dram_iodutya_166, $dram_iodutyb_166, $dram_iodutyc_166, $dram_rxdutya_166, $dram_rxdutyb_166, $dram_rxdutye_166, $dram_iomiscl_166);
	      my ($dram_drva_200, $dram_drvb_200, $dram_odle_200, $dram_odlf_200, $dram_odlg_200, $dram_odlh_200, $dram_odli_200, $dram_odlj_200, $dram_odlk_200, $dram_odll_200,$dram_odlm_200,$dram_odln_200, $dram_coni_200, $dram_conj_200, $dram_conk_200, $dram_conl_200, $dram_conn_200, $dram_iodutya_200, $dram_iodutyb_200, $dram_iodutyc_200, $dram_rxdutya_200, $dram_rxdutyb_200, $dram_rxdutye_200, $dram_iomiscl_200);  
        my ($dram_conj_13, $dram_conk_13, $dram_conj_13); 
         ### 6280 series
	    $dram_drva_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drvb_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odle_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_E_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlf_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_F_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlg_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_G_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlh_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_H_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odli_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_I_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlj_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_J_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlk_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_K_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odll_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_L_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlm_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_M_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odln_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_N_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_coni_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conj_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conk_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conl_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conn_166   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutya_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyb_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyc_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutya_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutyb_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutye_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iomiscl_166 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_IOCL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drva_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_drvb_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_B_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odle_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_E_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlf_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_F_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlg_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_G_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlh_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_H_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odli_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_I_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlj_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_J_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlk_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_K_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odll_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_L_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odlm_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_M_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_odln_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_ODL_N_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_coni_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONI_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conj_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conk_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conl_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conn_200   = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONN_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutya_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyb_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iodutyc_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUTC_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutya_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCA_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutyb_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCB_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_rxdutye_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DUCE_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_iomiscl_200 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_IOCL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
	    $dram_conj_13 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONJ_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
      $dram_conk_13 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONK_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL);
      $dram_conl_13 = &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 13, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_CONL_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL); 
        $combo_mem_emi_reg .= <<"__TEMPLATE";
   /**
      * EMI register value definition
      * EMI/MEM configuration information of MCP$combo_idx
      */
      #if defined(__EMI_CLK_166MHZ__)

#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni_166
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj_166
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk_166
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl_166
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn_166

#define EMI_ODL_E_VAL_MCP$combo_idx             $dram_odle_166
#define EMI_ODL_F_VAL_MCP$combo_idx             $dram_odlf_166
#define EMI_ODL_G_VAL_MCP$combo_idx             $dram_odlg_166
#define EMI_ODL_H_VAL_MCP$combo_idx             $dram_odlh_166
#define EMI_ODL_I_VAL_MCP$combo_idx             $dram_odli_166
#define EMI_ODL_J_VAL_MCP$combo_idx             $dram_odlj_166    
#define EMI_ODL_K_VAL_MCP$combo_idx             $dram_odlk_166
#define EMI_ODL_L_VAL_MCP$combo_idx             $dram_odll_166
#define EMI_ODL_M_VAL_MCP$combo_idx             $dram_odlm_166
#define EMI_ODL_N_VAL_MCP$combo_idx             $dram_odln_166

#define EMI_IODUTY_A_VAL_MCP$combo_idx          $dram_iodutya_166
#define EMI_IODUTY_B_VAL_MCP$combo_idx          $dram_iodutyb_166
#define EMI_IODUTY_C_VAL_MCP$combo_idx          $dram_iodutyc_166


#define EMI_DRV_A_VAL_MCP$combo_idx             $dram_drva_166
#define EMI_DRV_B_VAL_MCP$combo_idx             $dram_drvb_166

#define EMI_RXDUTY_A_VAL_MCP$combo_idx          $dram_rxdutya_166
#define EMI_RXDUTY_B_VAL_MCP$combo_idx          $dram_rxdutyb_166
#define EMI_RXDUTY_E_VAL_MCP$combo_idx          $dram_rxdutye_166

#define EMI_IOMISC_L_VAL_MCP$combo_idx          $dram_iomiscl_166     //for LPDDR2/DDR3 should be set 0

#define EMI_CONTROL_J_13_VAL_MCP$combo_idx      $dram_conj_13
#define EMI_CONTROL_K_13_VAL_MCP$combo_idx      $dram_conk_13
#define EMI_CONTROL_L_13_VAL_MCP$combo_idx      $dram_conl_13

#elif defined(__EMI_CLK_200MHZ__)/* __EMI_CLK_166MHZ__ */

#define EMI_CONTROL_I_VAL_MCP$combo_idx         $dram_coni_200
#define EMI_CONTROL_J_VAL_MCP$combo_idx         $dram_conj_200
#define EMI_CONTROL_K_VAL_MCP$combo_idx         $dram_conk_200
#define EMI_CONTROL_L_VAL_MCP$combo_idx         $dram_conl_200
#define EMI_CONTROL_N_VAL_MCP$combo_idx         $dram_conn_200

#define EMI_ODL_E_VAL_MCP$combo_idx             $dram_odle_200
#define EMI_ODL_F_VAL_MCP$combo_idx             $dram_odlf_200
#define EMI_ODL_G_VAL_MCP$combo_idx             $dram_odlg_200
#define EMI_ODL_H_VAL_MCP$combo_idx             $dram_odlh_200
#define EMI_ODL_I_VAL_MCP$combo_idx             $dram_odli_200
#define EMI_ODL_J_VAL_MCP$combo_idx             $dram_odlj_200    
#define EMI_ODL_K_VAL_MCP$combo_idx             $dram_odlk_200
#define EMI_ODL_L_VAL_MCP$combo_idx             $dram_odll_200
#define EMI_ODL_M_VAL_MCP$combo_idx             $dram_odlm_200
#define EMI_ODL_N_VAL_MCP$combo_idx             $dram_odln_200


#define EMI_IODUTY_A_VAL_MCP$combo_idx          $dram_iodutya_200
#define EMI_IODUTY_B_VAL_MCP$combo_idx          $dram_iodutyb_200
#define EMI_IODUTY_C_VAL_MCP$combo_idx          $dram_iodutyc_200

#define EMI_DRV_A_VAL_MCP$combo_idx             $dram_drva_200
#define EMI_DRV_B_VAL_MCP$combo_idx             $dram_drvb_200

#define EMI_RXDUTY_A_VAL_MCP$combo_idx          $dram_rxdutya_200
#define EMI_RXDUTY_B_VAL_MCP$combo_idx          $dram_rxdutyb_200
#define EMI_RXDUTY_E_VAL_MCP$combo_idx          $dram_rxdutye_200

#define EMI_IOMISC_L_VAL_MCP$combo_idx          $dram_iomiscl_200    //for LPDDR2/DDR3 should be set 0

#define EMI_CONTROL_J_13_VAL_MCP$combo_idx      $dram_conj_13
#define EMI_CONTROL_K_13_VAL_MCP$combo_idx      $dram_conk_13
#define EMI_CONTROL_L_13_VAL_MCP$combo_idx      $dram_conl_13

#endif /* __EMI_CLK_166MHZ__ */
/**
      * End of EMI/MEM configuration information of MCP$combo_idx
      */
__TEMPLATE
    }	
    
    ###
   
    	
    	   my $template = <<"__TEMPLATE";
/****************************************************************************
   *
   * Definition.
   *
   ****************************************************************************/

#define DRAM_CS                   1


$combo_mem_emi_reg

__TEMPLATE

      return $template;
   
}

sub custom_EMI_info_h_80_file_body
{
	 my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL) = @_;
	 my $combo_mem_emi_info_struct;
	 my $combo_mei_emi_count;
	 if($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT} ne '0')
	 {
	     $combo_mei_emi_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT};	
	 }
	 else
	 {
	 	   $combo_mei_emi_count = $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT};
	 }
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
    if(($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
    {
        $combo_mem_emi_info_struct .= <<"__TEMPLATE";
   /**
      * EMI/MEM configuration information of MCP$combo_idx
      */
      
   {
   "EMI_INF",
   
   EMI_DRV_A_VAL_MCP$combo_idx,
   EMI_DRV_B_VAL_MCP$combo_idx,

   EMI_ODL_E_VAL_MCP$combo_idx,
   EMI_ODL_F_VAL_MCP$combo_idx,
   EMI_ODL_G_VAL_MCP$combo_idx,
   EMI_ODL_H_VAL_MCP$combo_idx,
   EMI_ODL_I_VAL_MCP$combo_idx,
   EMI_ODL_J_VAL_MCP$combo_idx,
   EMI_ODL_K_VAL_MCP$combo_idx,
   EMI_ODL_L_VAL_MCP$combo_idx,
   EMI_ODL_M_VAL_MCP$combo_idx,
   EMI_ODL_N_VAL_MCP$combo_idx,

   EMI_CONTROL_I_VAL_MCP$combo_idx,
   EMI_CONTROL_J_VAL_MCP$combo_idx,
   EMI_CONTROL_K_VAL_MCP$combo_idx,
   EMI_CONTROL_L_VAL_MCP$combo_idx,
   EMI_CONTROL_N_VAL_MCP$combo_idx,

   EMI_IODUTY_A_VAL_MCP$combo_idx,
   EMI_IODUTY_B_VAL_MCP$combo_idx,  
   EMI_IODUTY_C_VAL_MCP$combo_idx,
   
   EMI_RXDUTY_A_VAL_MCP$combo_idx,
   EMI_RXDUTY_B_VAL_MCP$combo_idx,  
   EMI_RXDUTY_E_VAL_MCP$combo_idx,
   
   EMI_IOMISC_L_VAL_MCP$combo_idx
  },
   
   /**
      * End of EMI/MEM configuration information of MCP$combo_idx
      */
__TEMPLATE
    }
   
  }
	 
	 ###for combo memory 13mhz
    my $combo_mem_dcm_ctrl_struct_80;
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        my $comma = ($_ < $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}) ? "," : "";

        $combo_mem_dcm_ctrl_struct_80 .= <<"__TEMPLATE";
   {
      EMI_CONTROL_J_VAL_MCP$combo_idx,
      EMI_CONTROL_K_VAL_MCP$combo_idx,
      EMI_CONTROL_L_VAL_MCP$combo_idx,
      EMI_CONTROL_J_13_VAL_MCP$combo_idx,
      EMI_CONTROL_K_13_VAL_MCP$combo_idx,
      EMI_CONTROL_L_13_VAL_MCP$combo_idx
   }$comma
__TEMPLATE
    }
  
  ###for combo memory EMI Controller value
  my $combo_mem_emi;
  for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
  {
  	  my $combo_idx = $_ - 1;
  	 $combo_mem_emi .= <<"__TEMPLATE";
 #define EMI_GENERAL_A_VAL_MCP$combo_idx            0x00000002
 #define EMI_IOCM_VAL_MCP$combo_idx                 0x00010003
 #define EMI_GENERAL_A_VAL     EMI_GENERAL_A_VAL_MCP$combo_idx
 #define EMI_IOCM_VAL          EMI_IOCM_VAL_MCP$combo_idx
__TEMPLATE
  }
  ###
 
	 my $template = <<"__TEMPLATE";
	 
#if defined(MT6280)

#ifndef __CUSTOM_EMI_LIST__
#define __CUSTOM_EMI_LIST__

#include "kal_general_types.h"
#include "MemoryDevice_TypeDef.h"

/**
  *    for definition of COMBO_MEM_ENTRY_COUNT and __EMI_DEVICE_MODE_BURST__
  */
#include "custom_MemoryDevice.h"
#include "custom_EMI_release.h"
#include "custom_EMI.h"

#include "br_GFH_emi_list.h"
#include "br_GFH.h"

__attribute__ ((section ("BOOTLOADER_GFH_EXT"))) 
    const GFH_EMI_LIST_v5 EMI_INFO_2 =
{
    GFH_HEADER(GFH_EMI_LIST, 5),  
   // chip_ver
   6,
   // op_ver
   #if defined(__EMI_DEVICE_LPDDR1__) && defined(__EMI_CLK_166MHZ__)
   0x01,
   #elif defined(__EMI_DEVICE_LPDDR1__) && defined(__EMI_CLK_200MHZ__)
   0x02,
   #elif defined(__EMI_DEVICE_LPDDR2__) && defined(__EMI_CLK_166MHZ__) 
   0x11,
   #elif defined(__EMI_DEVICE_LPDDR2__) && defined(__EMI_CLK_200MHZ__) 
   0x12,
   #elif defined(__EMI_DEVICE_DDR3__) && defined(__EMI_CLK_125MHZ__) 
   0x21, 
   #else
   0,
   #endif
   
   0, // reserved_1
   0, // reserved_2

   $combo_mei_emi_count, // mcp_num
   {
$combo_mem_emi_info_struct
   }
}; /* End of EMI_INFO_2 */


MTK_EMI_DCM_Ctrl __EMI_DCM_control[__EMI_COMBO_ENTRY_COUNT] = 
{
$combo_mem_dcm_ctrl_struct_80
};

#endif /* __CUSTOM_EMI_LIST__ */

#endif //#if defined(MT6280)

__TEMPLATE

return $template;
}