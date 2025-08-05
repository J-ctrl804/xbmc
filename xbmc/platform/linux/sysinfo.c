#include "sysinfo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>

void get_sysinfo(struct sysinfo *info)
{
    struct utsname uts;
    if (uname(&uts) == -1)
    {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    info->sysname = strdup(uts.sysname);
    info->nodename = strdup(uts.nodename);
    info->release = strdup(uts.release);
    info->version = strdup(uts.version);
    info->machine = strdup(uts.machine);
}
