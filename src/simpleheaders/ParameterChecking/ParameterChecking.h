#ifndef ParameterChecking_H
#define ParameterChecking_H
#include "../BitfieldStuff/BitfieldMacros.h"
#include "../CommonMacros.h"
#include "../Logging/Logging.h"

#include <inttypes.h>
#ifdef __cplusplus
extern "C" {
#endif
// #define PARAMETERCHECKING_PRINT_FUNC(...) fputs(__VA_ARGS__, stderr)
#define PARAMETERCHECKING_PRINT_FUNC PRINTF_ERROR_INFO

#if 0
#define checkparmesan(bitfield_name_, parameter_, valid_value_comparison) \
    do \
	{ \
	    uint8_t bitfield_name_ = 0; \
	    if((!(parameter_ valid_value_comparison))) \
		{ \
		    SET_BITS(bitfield_name_, 1, 0); \
	    } \
	    /* Now all the bits are correctly set */ \
	    if(bitfield_name_ != 0) \
		{ \
		    PRINTF_ERROR_INFO(error_message); \
		    for(uint8_t _i_ = 0; _i_ < 8; _i_++) \
			{ \
			    if(GET_VAL(bitfield_name_, 1, _i_)) \
				printf(STR(parameter_) \
				           STR(valid_value_comparison)); \
			} \
		    putchar('\n'); \
	    } \
    } while(0)
#endif

#define ___CHECK_BLANK_PARAMETER__CHECKER___( \
    PARAMETER_NAME, VALUE_COMPARISON, PARAMETER_NUMBER, bitfield_name_ \
) \
    if((!(VALUE_COMPARISON))) \
	{ \
	    SET_BITS(bitfield_name_, 1, PARAMETER_NUMBER - 1); \
    }

#define ___CHECK_BLANK_PARAMETER__PRINTER___( \
    PARAMETER_NAME, VALUE_COMPARISON, PARAMETER_NUMBER, bitfield_name_ \
) \
    if(GET_VAL(bitfield_name_, 1, PARAMETER_NUMBER - 1)) \
	fputs(stdout,"(" STR(VALUE_COMPARISON) ") ");

#define ___CHECK_BLANK_PARAMETER__MAIN___( \
    CHECKER, PRINTER, bitfield_name_, error_message \
) \
    uint8_t bitfield_name_ = 0; \
    do \
	{ \
	    CHECKER \
	    if(bitfield_name_ != 0 && error_message != NULL) \
		{ /* if error_message is NULL, it means that I do not want a print */ \
		    PARAMETERCHECKING_PRINT_FUNC(error_message); \
\
		    PRINTER \
\
		    putchar('\n'); \
	    } \
    } while(0)
#pragma region /* if its hidden, I can pretend that this isn't here */

// clang-format off
#define Check_1_Parameter( \
    bitfield_name_, error_message, parameter_1, value_comparison_1 \
) \
    ___CHECK_BLANK_PARAMETER__MAIN___( \
	___CHECK_BLANK_PARAMETER__CHECKER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	), \
	___CHECK_BLANK_PARAMETER__PRINTER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	), \
	bitfield_name_, \
	error_message \
    )

#define Check_2_Parameter( \
    bitfield_name_, \
    error_message, \
    parameter_1, \
    value_comparison_1, \
    parameter_2, \
    value_comparison_2 \
) \
    ___CHECK_BLANK_PARAMETER__MAIN___( \
\
	___CHECK_BLANK_PARAMETER__CHECKER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__CHECKER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ), \
\
	___CHECK_BLANK_PARAMETER__PRINTER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__PRINTER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ), \
\
	bitfield_name_, \
	error_message \
    )

#define Check_3_Parameter( \
    bitfield_name_, \
    error_message, \
    parameter_1, \
    value_comparison_1, \
    parameter_2, \
    value_comparison_2, \
    parameter_3, \
    value_comparison_3 \
) \
    ___CHECK_BLANK_PARAMETER__MAIN___( \
\
	___CHECK_BLANK_PARAMETER__CHECKER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__CHECKER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		), \
\
	___CHECK_BLANK_PARAMETER__PRINTER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__PRINTER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		), \
\
	bitfield_name_, \
	error_message \
    )

#define Check_4_Parameter( \
    bitfield_name_, \
    error_message, \
    parameter_1, \
    value_comparison_1, \
    parameter_2, \
    value_comparison_2, \
    parameter_3, \
    value_comparison_3, \
    parameter_4, \
    value_comparison_4 \
) \
    ___CHECK_BLANK_PARAMETER__MAIN___( \
\
	___CHECK_BLANK_PARAMETER__CHECKER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__CHECKER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		) \
		    ___CHECK_BLANK_PARAMETER__CHECKER___( \
			parameter_4, value_comparison_4, 4, bitfield_name_ \
		    ), \
\
	___CHECK_BLANK_PARAMETER__PRINTER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__PRINTER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		) \
		    ___CHECK_BLANK_PARAMETER__PRINTER___( \
			parameter_4, value_comparison_4, 4, bitfield_name_ \
		    ), \
\
	bitfield_name_, \
	error_message \
    )


#define Check_5_Parameter( \
    bitfield_name_, \
    error_message, \
    parameter_1, \
    value_comparison_1, \
    parameter_2, \
    value_comparison_2, \
    parameter_3, \
    value_comparison_3, \
    parameter_4, \
    value_comparison_4, \
    parameter_5, \
    value_comparison_5 \
) \
    ___CHECK_BLANK_PARAMETER__MAIN___( \
\
	___CHECK_BLANK_PARAMETER__CHECKER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__CHECKER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_4, value_comparison_4, 4, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_5, value_comparison_5, 5, bitfield_name_ \
		), \
\
	___CHECK_BLANK_PARAMETER__PRINTER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__PRINTER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_4, value_comparison_4, 4, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_5, value_comparison_5, 5, bitfield_name_ \
		), \
\
	bitfield_name_, \
	error_message \
    )


#define Check_6_Parameter( \
    bitfield_name_, \
    error_message, \
    parameter_1, \
    value_comparison_1, \
    parameter_2, \
    value_comparison_2, \
    parameter_3, \
    value_comparison_3, \
    parameter_4, \
    value_comparison_4, \
    parameter_5, \
    value_comparison_5, \
    parameter_6, \
    value_comparison_6 \
) \
    ___CHECK_BLANK_PARAMETER__MAIN___( \
\
	___CHECK_BLANK_PARAMETER__CHECKER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__CHECKER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_4, value_comparison_4, 4, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_5, value_comparison_5, 5, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_6, value_comparison_6, 6, bitfield_name_ \
		), \
\
	___CHECK_BLANK_PARAMETER__PRINTER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__PRINTER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_4, value_comparison_4, 4, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_5, value_comparison_5, 5, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_6, value_comparison_6, 6, bitfield_name_ \
		), \
\
	bitfield_name_, \
	error_message \
    )

#define Check_7_Parameter( \
    bitfield_name_, \
    error_message, \
    parameter_1, \
    value_comparison_1, \
    parameter_2, \
    value_comparison_2, \
    parameter_3, \
    value_comparison_3, \
    parameter_4, \
    value_comparison_4, \
    parameter_5, \
    value_comparison_5, \
    parameter_6, \
    value_comparison_6, \
    parameter_7, \
    value_comparison_7 \
) \
    ___CHECK_BLANK_PARAMETER__MAIN___( \
\
	___CHECK_BLANK_PARAMETER__CHECKER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__CHECKER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_4, value_comparison_4, 4, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_5, value_comparison_5, 5, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_6, value_comparison_6, 6, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_7, value_comparison_7, 7, bitfield_name_ \
		), \
\
	___CHECK_BLANK_PARAMETER__PRINTER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__PRINTER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_4, value_comparison_4, 4, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_5, value_comparison_5, 5, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_6, value_comparison_6, 6, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_7, value_comparison_7, 7, bitfield_name_ \
		), \
\
	bitfield_name_, \
	error_message \
    )

#define Check_8_Parameter( \
    bitfield_name_, \
    error_message, \
    parameter_1, \
    value_comparison_1, \
    parameter_2, \
    value_comparison_2, \
    parameter_3, \
    value_comparison_3, \
    parameter_4, \
    value_comparison_4, \
    parameter_5, \
    value_comparison_5, \
    parameter_6, \
    value_comparison_6, \
    parameter_7, \
    value_comparison_7, \
    parameter_8, \
    value_comparison_8 \
) \
    ___CHECK_BLANK_PARAMETER__MAIN___( \
\
	___CHECK_BLANK_PARAMETER__CHECKER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__CHECKER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_4, value_comparison_4, 4, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_5, value_comparison_5, 5, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_6, value_comparison_6, 6, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_7, value_comparison_7, 7, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__CHECKER___( \
		    parameter_8, value_comparison_8, 8, bitfield_name_ \
		), \
\
	___CHECK_BLANK_PARAMETER__PRINTER___( \
	    parameter_1, value_comparison_1, 1, bitfield_name_ \
	) \
	    ___CHECK_BLANK_PARAMETER__PRINTER___( \
		parameter_2, value_comparison_2, 2, bitfield_name_ \
	    ) \
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_3, value_comparison_3, 3, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_4, value_comparison_4, 4, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_5, value_comparison_5, 5, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_6, value_comparison_6, 6, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_7, value_comparison_7, 7, bitfield_name_ \
		)\
		___CHECK_BLANK_PARAMETER__PRINTER___( \
		    parameter_8, value_comparison_8, 8, bitfield_name_ \
		), \
\
	bitfield_name_, \
	error_message \
    )
// clang-format on
#pragma endregion /* oh god, c macros are so bulky */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
