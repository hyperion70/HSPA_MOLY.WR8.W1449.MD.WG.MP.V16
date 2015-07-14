#ifndef PDN_FIXUP_MT6589_SERIES_H
#define PDN_FIXUP_MT6589_SERIES_H


/*
 * PDN_STATUS(kal_uint32 dev, type s, type): get device power down status
 * @dev: device ID (EX: PDN_UART1)
 * @s: returned power down status
 * @t: type of s
 */
#define _PDN_STATUS(dev, s, t)											\
	do {																\
		if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {						\
			(s) = (t)(*(volatile kal_uint32 *)(dev##_CON_REG) & dev##_REG_BIT);	\
		} else {														\
			(s) = (t)(*(volatile kal_uint16 *)(dev##_CON_REG) & dev##_REG_BIT);	\
		}																\
	} while (0)


#undef PDN_STATUS


/**
 * Because there 2 PDN status registers, belongs to AP side,
 * not obey the design rule of MD PDN policy.
 * Their staus register bit is not the same with set/clear register bit.
 *
 * Here to exclude them from general macro definition, and introduce a fixup method for their specifics.
 * It takes use of compiler optimization to remove overhead of exception method.
 **/

#define PDN_STATUS(dev, s, t)											\
	do {																\
		if (_##dev == _PDN_TOPCKG_MD2_PMICSPI)							\
			(s) = (t)(*(volatile kal_uint32 *)(dev##_CON_REG) & AP_TOPCKG_MD2_CG_CON_PMICSPI); \
		else if (_##dev == _PDN_TOPCKG_MD1_PMICSPI)						\
			(s) = (t)(*(volatile kal_uint32 *)(dev##_CON_REG) & AP_TOPCKG_MD1_CG_CON_PMICSPI); \
		else															\
			_PDN_STATUS(dev, s, t);										\
	} while(0)
					




#endif
