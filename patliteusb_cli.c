#include "patliteusb.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
 
#define LIGHT_RED_OPT 0
#define LIGHT_YEL_OPT 1
#define LIGHT_GRN_OPT 2
#define LIGHT_BLU_OPT 3
#define LIGHT_CLR_OPT 4

#define BUZZR_TYP_OPT 5
#define BUZZR_TOA_OPT 6
#define BUZZR_TOB_OPT 7
 
int main(int argc, char **argv)
{
    int c;

    int light_red_opt = 8;
    int light_yel_opt = 8;
    int light_grn_opt = 8;
    int light_blu_opt = 8;
    int light_clr_opt = 8;

    int buzzr_typ_opt = 8;
    int buzzr_toa_opt = 8;
    int buzzr_tob_opt = 8;

    while (1)
    {
        static struct option long_options[] =
            {
                {"red", required_argument, 0, LIGHT_RED_OPT},
                {"yel", required_argument, 0, LIGHT_YEL_OPT},
                {"grn", required_argument, 0, LIGHT_GRN_OPT},
                {"blu", required_argument, 0, LIGHT_BLU_OPT},
                {"clr", required_argument, 0, LIGHT_CLR_OPT},

                {"bzt", required_argument, 0, BUZZR_TYP_OPT},
                {"toa", required_argument, 0, BUZZR_TOA_OPT},
                {"tob", required_argument, 0, BUZZR_TOB_OPT},
                {0, 0, 0, 0}
            };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long(argc, argv, "",
                        long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c)
        {
            case LIGHT_RED_OPT:
                printf("option LIGHT_RED_OPT with value '%s'\n", optarg);
                light_red_opt = atoi(optarg);
                break;

            case LIGHT_YEL_OPT:
                printf("option LIGHT_YEL_OPT with value '%s'\n", optarg);
                light_yel_opt = atoi(optarg);
                break;

            case LIGHT_GRN_OPT:
                printf("option LIGHT_GRN_OPT with value '%s'\n", optarg);
                light_grn_opt = atoi(optarg);
                break;

            case LIGHT_BLU_OPT:
                printf("option LIGHT_BLU_OPT with value '%s'\n", optarg);
                light_blu_opt = atoi(optarg);
                break;

            case LIGHT_CLR_OPT:
                printf("option LIGHT_CLR_OPT with value '%s'\n", optarg);
                light_clr_opt = atoi(optarg);
                break;

            case BUZZR_TYP_OPT:
                printf("option BUZZR_TYP_OPT with value '%s'\n", optarg);
                buzzr_typ_opt = atoi(optarg);
                break;

            case BUZZR_TOA_OPT:
                printf("option BUZZR_TOA_OPT with value '%s'\n", optarg);
                buzzr_toa_opt = atoi(optarg);
                break;

            case BUZZR_TOB_OPT:
                printf("option BUZZR_TOB_OPT with value '%s'\n", optarg);
                buzzr_tob_opt = atoi(optarg);
                break;

            case '?':
                /* getopt_long already printed an error message. */
                break;

            default:
                abort();
        }
    }

    printf("%d, %d, %d, %d, %d, %d, %d, %d\n",
           light_red_opt, 
           light_yel_opt, 
           light_grn_opt, 
           light_blu_opt, 
           light_clr_opt,
           buzzr_typ_opt,
           buzzr_toa_opt,
           buzzr_tob_opt);

    patlite_lights(light_red_opt,
                   light_yel_opt,
                   light_grn_opt,
                   light_blu_opt,
                   light_clr_opt);
    patlite_buzzer(buzzr_typ_opt,
                   buzzr_toa_opt,
                   buzzr_tob_opt);
    return 0;
}
