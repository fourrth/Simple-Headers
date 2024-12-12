#ifndef DebugingStuff_H
#define DebugingStuff_H

/* NOTE THAT YOU CANNOT DEFINE VARIABLES IN THIS MACRO 
   AS THE IF STATEMENTS HAVE THEIR OWN SCOPES
   is good for prints and reassignments tho.. */
#define ___PREPROCESSOR_IF__(DEF1, ifDEF1, DEF2, ifDEF2) \
    if(DEF1) \
	{ \
	    ifDEF1 \
    } else if(DEF2) \
	{ \
	    ifDEF2 \
    }
#define IFDEBUG(ifDEBUG, ifNDEBUG) \
    ___PREPROCESSOR_IF__(___DEBUG, ifDEBUG, ___NDEBUG, ifNDEBUG)

#endif
