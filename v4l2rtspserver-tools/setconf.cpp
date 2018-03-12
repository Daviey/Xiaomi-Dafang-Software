#include<stdio.h>
#include <getopt.h>
#include <cstdlib>
#include "sharedmem.h"


int main(int argc, char *argv[]) {

    char key = 0;
    char *value;

    // Parse Arguments:
    int c;
    while ((c = getopt(argc, argv, "k:v:")) != -1) {
        switch (c) {
            case 'k':
                key = optarg[0];
                break;
            case 'v':
                value = optarg;
                break;
            default:
                printf("Invalid Argument %c\n", c);
                exit(EXIT_FAILURE);
        }
    }

    SharedMem &mem = SharedMem::instance();
    shared_conf *conf = mem.getConfig();
    //printf("%d,%d\n", conf->nightmode, conf->flip);
    mem.readConfig();
    //printf("%d,%d\n", conf->nightmode, conf->flip);
    switch (key) {
        case 'f':
            conf->flip = atoi(value);
            break;
        case 'n':
            conf->nightmode = atoi(value);
            break;
        case 'b':
            conf->bitrate =  atoi(value);
            break;
        case 'o':
            strcpy(conf->osdTimeDisplay,value);
            break;
	case 'c':
	    conf->osdColor = atoi(value);
	    break;
	case 's':
	    conf->osdSize = atoi(value);
	    break;
	case 'x':
	    conf->osdPosY = atoi(value);
	    break;
	case 'p':
	    conf->osdSpace = atoi(value);
	    break;
	case 'w':
	    conf->osdFixedWidth = atoi(value)==0?false:true;
	    break;
        default:
            printf("Invalid Argument %c\n", key);
            exit(EXIT_FAILURE);
    }
    mem.setConfig();
    //mem.readConfig();
    //printf("%d,%d\n", conf->nightmode, conf->flip);

    return 0;


}

