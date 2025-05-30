/*
** svn $Id: inlet_test.h 585 2012-01-03 18:44:28Z arango $
*******************************************************************************
** Copyright (c) 2002-2012 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options for Inlet Test Case, waves-ocean (SWAN/ROMS) two-way coupling.
**
** Application flag:   YAEYAMA1
** Input script:       ocean_inlet_test.in
**                     coupling_inlet_test.in
**                     sediment_inlet_test.in
*/
#define ROMS_MODEL
#define SWAN_MODEL
#define MCT_LIB

#define NO_LBC_ATT
/*#define PARALLEL_IO*/
/*#define HDF5*/
/*#define PNETCDF*/

/*#define NESTING*/
/*#define NESTING_DEBUG*/
/*#define ONE_WAY*/
/*#define QUADRATIC_WEIGHTS*/

#define SOLVE3D

#define UV_ADV
#define UV_COR

/*#define UV_U3ADV_SPLIT*/
/*#define UV_C2ADVECTION*/
/*#define UV_C4ADVECTION*/
/*#define UV_SADVECTION*/

#define UV_VIS2
/*#define UV_VIS4*/
#define UV_SMAGORINSKY

#define MIX_S_UV
/*#define MIX_GEO_UV*/

/*#define TS_U3ADV_SPLIT*/
/*#define TS_C4HADVECTION*/
#define TS_U3HADVECTION
/*#define TS_C2HADVECTION*/
/*#define TS_C2VADVECTION*/
#define TS_C4VADVECTION
/*#define TS_SVADVECTION*/
/*#define TS_MPDATA*/

#define TS_DIF2
/*#define TS_DIF4*/
#define TS_SMAGORINSKY
#define MIX_S_TS
/*#define MIX_GEO_TS*/
/*#define MIX_ISO_TS*/

#define MASKING

#define NONLIN_EOS
#define SALINITY
#define ATM_PRESS

/*#define PJ_GRADPQ4 */
#define DJ_GRADPS

/*#define SPLINES*/
/*#define RI_HORAVG*/
/*#define RI_VERAVG*/

#define WET_DRY


/*** Option for Boundary condition ***/
#define RADIATION_2D

/*** Option for tidal forcing ***/
/*#define SSH_TIDES*/  /* deactivate when the case of JCOPE-T boundary */
/*#define UV_TIDES*/   /* deactivate when the case of JCOPE-T boundary */
/*#define ADD_FSOBC*/  /* deactivate when the case of JCOPE-T boundary */
/*#define ADD_M2OBC*/  /* deactivate when the case of JCOPE-T boundary */
/*#define RAMP_TIDES*/ /*Not use*/

/*#define ANA_INITIAL*/
/*#define ANA_FSOBC*/
/*#define ANA_M2OBC*/
/*#define ANA_TOBC*/

#define BULK_FLUXES
#ifdef BULK_FLUXES
/*# define ANA_SRFLUX*/  /* activate 200603-201805 */
# define CLOUDS        /* activate 201806- */
# define ALBEDO_CLOUD  /* activate 200603- */
/*# define LONGWAVE*/
# define LONGWAVE_OUT
# define ANA_LRFLUX  /* activate 200603- */
# define ANA_LONGWAVE_DOWN  /* activate 200603-; Original CPP flag */ 
# define JMAMSM_FLUXES  /* activate 200603-; Original CPP flag for JMAMSM data */ 
/*# define JMAOBS_FLUXES*/  /* Original CPP flag for JMA weather station data */ 
# define EMINUSP
/*# define ANA_CLOUD*/
/*# define ANA_HUMID*/
/*# define ANA_PAIR*/
/*# define ANA_TAIR*/
/*# define ANA_RAIN*/
/*# define ANA_WINDS*/
/*# define LOCAL_TIME +9.0*/
/*# define DIURNAL_SRFLUX*/
#else
# define ANA_SMFLUX
# define ANA_STFLUX
#endif


/*** waves-ocean (SWAN/ROMS) two-way coupling. ***/
#ifdef SWAN_MODEL
/*# define WEC_MELLOR*/
# define WEC_VF
# define BOTTOM_STREAMING
# define WDISS_WAVEMOD
# define UV_KIRBY
#endif

/* define only one of the following 5 */
/*#define UV_LOGDRAG*/
/*#define UV_QDRAG*/
/*#define MB_BBL*/
/*#define SG_BBL*/
#define SSW_BBL

#ifdef MB_BBL
/*# define MB_CALC_ZNOT*/
#endif

#ifdef SSW_BBL
/*# define SSW_CALC_ZNOT*/
/*# define SSW_LOGINT*/
#endif
#define LIMIT_BSTRESS


#ifdef SOLVE3D

# define GLS_MIXING
/*# define MY25_MIXING*/
/*# define LMD_MIXING*/

# if defined GLS_MIXING
/*#  define CRAIG_BANNER*/
#  define KANTHA_CLAYSON
/*#  define  CANUTO_A*/
/*#  define  CANUTO_B*/
/*#  define K_C4ADVECTION*/
/*#  define K_C2ADVECTION*/
/*#  define N2S2_HORAVG*/
#  define ZOS_HSIG
#  define TKE_WAVEDISS
# endif

# if defined MY25_MIXING
#  define KANTHA_CLAYSON
#  undef  CANUTO_A
/*#  define K_C4ADVECTION*/
#  define N2S2_HORAVG
# endif

# ifdef LMD_MIXING
#  define LMD_RIMIX
#  define LMD_CONVEC
#  define LMD_SKPP
#  define LMD_BKPP
#  define LMD_NONLOCAL
#  define LMD_SHAPIRO
#  define LMD_DDMIX
# endif


# define SEDIMENT
# ifdef SEDIMENT
#  define SUSPLOAD
#  undef  BEDLOAD_SOULSBY
#  undef  BEDLOAD_MPM
/*#  define SED_MORPH*/
# endif
# if defined SEDIMENT || defined SG_BBL || defined MB_BBL || defined SSW_BBL
#  define ANA_SEDIMENT
#  define ANA_SED_UNIFORM    /*Original CPP flag */
# endif
# define ANA_BPFLUX
# define ANA_BTFLUX
# define ANA_BSFLUX
# define ANA_SPFLUX

#endif


/*#define FLOATS*/
#if defined FLOATS
# define FLOAT_BIOLOGY
# if defined FLOAT_BIOLOGY
#  define FLOAT_REEF_ECOSYS    /*Original CPP flag */
# endif
#endif

/*** submarine groundwater discharge ***/

/*#define SGD_ON*/    /*Original CPP flag */

/*** Vegetation form drag ***/
#define VEGETATION

#if defined VEGETATION
# define ANA_VEGETATION 
# define VEG_DRAG
# ifdef VEG_DRAG
/*#  define VEG_FLEX*/
#  define VEG_TURB
# endif
# define VEG_SWAN_COUPLING
# ifdef VEG_SWAN_COUPLING
#  define VEG_STREAMING  /* dependence to WEC_VF/BOTTOM_STREAMING */
# endif
/*** Aquaculture form drag ***/
# define AQUACULTURE    /* Original CPP flag */
#endif

/***  Biological model options. (Original CPP flags) ***/

#define REEF_ECOSYS

#if defined REEF_ECOSYS || defined SEDIMENT
# define ANA_TOBC_BIO  /*Original CPP flag */
# define ANA_TOBC_SED   /*Original CPP flag */
# define BIO_VPROFILE_YAEYAMA   /*Original CPP flag */
#endif

#if defined REEF_ECOSYS
# define BIOLOGY
# define DIAGNOSTICS_BIO
# define ANA_BIOLOGY

/* compartments */
# define ORGANIC_MATTER
/*# define CARBON_ISOTOPE*/
# define NUTRIENTS

/*# define CORAL_POLYP*/  /* USE coral module */
/*# define SEAGRASS*/     /* USE seagrass module */
/*# define MACROALGAE*/        /* USE algae module  */
# define SEDIMENT_ECOSYS        /* USE sedecosys module  */

# if defined ORGANIC_MATTER
#  define FOODWEB      /* USE foodweb module */
# endif
# define AIR_SEA_GAS_EXCHANGE

/*# define DYNAMIC_COVERAGE*/ /* yt_edit not yet implemented in coawst */


/*** Coral Polyp model options. ***/
# if defined CORAL_POLYP
#  define CORAL_ZOOXANTHELLAE
#  define CORAL_MUCUS           /*Mucus release from coral */
#  if defined ORGANIC_MATTER
#   define CORAL_INGESTION
#  endif
/*#  define CORAL_SIZE_DYNAMICS*/
#  if defined CARBON_ISOTOPE
#   define CORAL_CARBON_ISOTOPE
/*#   define CORAL_NONE_CO2_EQ*/
#  endif
#  if defined NUTRIENTS
/*#   define CORAL_NUTRIENTS*/
#  endif
/*#  define CORAL_BORON_ISOTOPE*/
# endif


/*** Seagrass model options. ***/
# if defined SEAGRASS
#  if defined NUTRIENTS
/*#   define SEAGRASS_LEAF_NUTRIENT_UPTAKE*/
#  endif
#  if defined SEDIMENT_ECOSYS
/*#   define SEAGRASS_ROOT_CARBON_OXYGEN_EXCHANGE*/
#  endif
#  if defined NUTRIENTS && defined SEDIMENT_ECOSYS
#   define SEAGRASS_ROOT_NUTRIENT_UPTAKE
#  endif
#  if defined ORGANIC_MATTER
#   define SEAGRASS_LEAF_POM
#   if defined SEDIMENT_ECOSYS
#    define SEAGRASS_ROOT_POM
#   endif
#  endif
# endif


/*** Sediment model options. ***/
# if defined SEDIMENT_ECOSYS  /* Masa_edits */
/*#  define SEDIMENT_EMPIRICAL*/     /* USE empirical sediment module  */
#  define SEDIMENT_ECOSYS_INITIAL_MODE /* For starting new run */
#  define SEDECO_CLOSED_BOTTOM_DIFFUSION_BOUNDARY /* closed boundary condition at the bottom sediment layer */
#  define SULFATE      /* For sulfate reduction in sediment */
/*#  define SEDECO_BURIAL*/    /* For Burial term in sediment transport (massbalance) */
/*#  define SEDECO_ADVECTION*/
#  define ORGANIC_MATTER
#  define NUTRIENTS
# endif


#endif
