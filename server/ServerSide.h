/*
 * main function of the program header file
 * @param argc number of arguments
 * @param argv array of arguments
 * @return 0 if the program ends successfully
 * @return 1 if the program ends with an error
 */

#ifndef ADVANCEDPROGRAMMINGR_O_SERVERSIDE_H
#define ADVANCEDPROGRAMMINGR_O_SERVERSIDE_H

#include <iostream>
#include "server/header/distance/Distance.h"
#include "server/header/distance/MinkowskiDistance.h"
#include "server/header/distance/CanberraDistance.h"
#include "server/header/distance/EuclideanDistance.h"
#include "server/header/distance/ManhattanDistance.h"
#include "server/header/distance/ChebyshevDistance.h"
#include "server/header/util/Util.h"
#include "server/header/factory/DistanceFactory.h"
#include "server/header/database/Classification.h"
#include "server/header/TCP/TCP_Server.h"

using namespace std;

/**
 * main function of the program
 * @param argc number of arguments
 * @param argv array of arguments
 * @return 0 if the program ends successfully
 * @return 1 if the program ends with an error
 */
int main(int argc, char *argv[]);
#endif
