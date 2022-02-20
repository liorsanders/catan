#ifndef BUILD_H
#define BUILD_H

#include "Resource.h"
#include <stdlib.h>

Resource* roadResources() {
    Resource* resources = (Resource*)malloc(sizeof(Resource) * 2);
    resources[0] = wood;
    resources[1] = brick;
    return resources;
}

Resource* settlementResources() {
    Resource* resources = (Resource*)malloc(sizeof(Resource)*4);
    resources[0] = sheep;
    resources[1] = wood;
    resources[2] = ore;
    resources[3] = wheat;
    return resources;
}

Resource* cityResources() {
    Resource* resources = (Resource*)malloc(sizeof(Resource)*5);
    resources[0] = wheat;
    resources[1] = wheat;
    resources[2] = ore;
    resources[3] = ore;
    resources[4] = ore;
    return resources;
}

Resource* developmentCardResources() {
    Resource* resources = (Resource*)malloc(sizeof(Resource)*3);
    resources[0] = wheat;
    resources[1] = sheep;
    resources[2] = ore;
    return resources;
}

#endif