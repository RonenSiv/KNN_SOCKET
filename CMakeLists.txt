cmake_minimum_required(VERSION 2.8.12.2)
project(AdvancedProgrammingR_O)

add_compile_options(-std=c++11) # CMake 2.8.12 or newer

include_directories(.)

add_executable(a.out
        server/ServerSide.cpp
        server/ServerSide.h
        server/src/distance/Distance.cpp
        server/header/distance/Distance.h
        server/src/distance/CanberraDistance.cpp
        server/header/distance/CanberraDistance.h
        server/src/distance/MinkowskiDistance.cpp
        server/header/distance/MinkowskiDistance.h
        server/src/util/Util.cpp
        server/header/util/Util.h
        server/header/distance/EuclideanDistance.h
        server/src/distance/EuclideanDistance.cpp
        server/header/distance/ChebyshevDistance.h
        server/src/distance/ChebyshevDistance.cpp
        server/header/distance/ManhattanDistance.h
        server/src/distance/ManhattanDistance.cpp
        server/src/database/Classification.cpp
        server/header/database/Classification.h
        server/header/factory/DistanceFactory.h
        server/src/factory/DistanceFactory.cpp
        server/src/database/DataBase.cpp
        server/header/database/DataBase.h
        server/src/TCP/TCP_Server.cpp
        server/header/TCP/TCP_Server.h
        app/header/DefaultIO.h
        app/header/Command.h
        app/src/DefaultIO.cpp
        app/src/CLI.cpp
        app/src/Command.cpp
        server/src/commands/AlgoSetCommand.cpp
        server/src/commands/ClassifyDataCommand.cpp
        server/src/commands/ServerCommand.cpp
        server/src/commands/ExitCommand.cpp
        server/src/commands/SendFileCommand.cpp
        server/src/commands/UploadCommand.cpp
        server/src/DIO/SocketIO.cpp
        app/src/StandardIO.cpp
        server/src/util/DataProvider.cpp
        server/header/commands/AlgoSetCommand.h
        server/header/commands/ClassifyDataCommand.h
        app/header/CLI.h
        server/header/commands/ExitCommand.h
        server/header/commands/SendFileCommand.h
        server/header/commands/UploadCommand.h
        server/header/commands/ServerCommand.h
        server/src/factory/ServerCommandFactory.cpp
        server/header/factory/ServerCommandFactory.h)